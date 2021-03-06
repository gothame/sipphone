#include "model.h"
#include "cdlgbusyforward.h"
#include "uicommon.h"
#include "qtcommon/qmisc.h"
#include "setting/include/common.h"
#include "setting/src/callforwardcontroller.h"
#include "uikernel/languagehelper.h"
#include "inputmethod/inputmethod.h"
#include "baseui/fontcolor.h"
#include "uikernel/languagehelper.h"
#include "messagebox/modmessagebox.h"
#include "account/include/modaccount.h"

#include "uikernel/qcomboboxutility.h"
#include "uikernel/qlineeditutility.h"
#include "uikernel/qcheckbox.h"
#include "baseui/t4xpicpath.h"
#include <configiddefine.h>
#include "configparser/modconfigparser.h"
#include "directoryui/include/moddirectoryui.h"

void DlgBusyForward_DirectoryCallBack(yl::string strContactName, yl::string strContactNumber)
{

    CDlgBusyForward * pBusyForward = qobject_cast<CDlgBusyForward *>(UIManager_GetPrivateDlg(
                                         DLG_CDlgBusyForward));
    if (NULL == pBusyForward)
    {
        return;
    }
    QString name = toQString(strContactName);
    QString number = toQString(strContactNumber);

    pBusyForward->writeData(name, number);
}

CDlgBusyForward::CDlgBusyForward(QWidget * parent)
    : CDlgBaseFwdPageUI(FWD_TYPE_BUSY, parent)
    , m_pEditTarget(NULL)
    , m_pEditOnCode(NULL)
    , m_pEditOffCode(NULL)
    , m_qCheckBox(NULL)
{
    InitData();
}

void CDlgBusyForward::InitData()
{
    //初始化
    m_qCheckBox = new qCheckBox(this);
    m_pEditTarget = new QLineEdit(this);
    m_pEditOnCode = new QLineEdit(this);
    m_pEditOffCode = new QLineEdit(this);

    //指针判空
    if (m_qCheckBox == NULL || m_pEditOffCode == NULL
            || m_pEditOnCode == NULL || m_pEditTarget == NULL)
    {
        return;
    }

    qLineEditUtility::SetLineEditStyle(m_pEditTarget, Qt::black);
    qLineEditUtility::SetLineEditStyle(m_pEditOnCode, Qt::black);
    qLineEditUtility::SetLineEditStyle(m_pEditOffCode, Qt::black);

    //设置输入框输入的最大长度
    qLineEditUtility::SetMaxLength(m_pEditTarget, EDIT_TYPE_PHONE_NUMBER);
    qLineEditUtility::SetMaxLength(m_pEditOnCode, EDIT_TYPE_CODE);
    qLineEditUtility::SetMaxLength(m_pEditOffCode, EDIT_TYPE_CODE);

    //为输入框安装输入法
    qInstallIME(m_pEditTarget, IME_DIAL);
    qInstallIME(m_pEditOnCode, IME_DIAL);
    qInstallIME(m_pEditOffCode, IME_DIAL);

    //设置Activation标签
    QWidgetPair qPair;
    QString strLab;

    strLab = LANG_TRANSLATE(TRID_BUSY_FORWARD);
    qPair.first = strLab;
    qPair.second = m_qCheckBox;
    m_vecWidgetPair.push_back(qPair);

    strLab = LANG_TRANSLATE(TRID_FORWARD_TO);
    qPair.first = strLab;
    qPair.second = m_pEditTarget;
    qPair.iExtraButten = DIRECTORY_EXTRA;
    m_vecWidgetPair.push_back(qPair);
    qPair.iExtraButten = NONE_EXTRA;

    //broadsoft开启之后不显示code，http://10.2.1.199/Bug.php?BugID=44441
    if (configParser_GetConfigInt(kszBroadsoftActive) == 0)
    {
        strLab = LANG_TRANSLATE(TRID_ON_CODE);
        qPair.first = strLab;
        qPair.second = m_pEditOnCode;
        m_vecWidgetPair.push_back(qPair);

        strLab = LANG_TRANSLATE(TRID_OFF_CODE);
        qPair.first = strLab;
        qPair.second = m_pEditOffCode;
        m_vecWidgetPair.push_back(qPair);
    }
    else
    {
        m_pEditOnCode->hide();
        m_pEditOffCode->hide();
    }


    AddWidget(m_vecWidgetPair);

    //安装事件过滤器
    m_qCheckBox->installEventFilter(this);
    m_pEditTarget->installEventFilter(this);
    m_pEditOnCode->installEventFilter(this);
    m_pEditOffCode->installEventFilter(this);

    //为界面自己安装事件过滤器
    this->installEventFilter(this);
}

/*
调用此函数前要先进行点击type的判断，当为BUSY时，才能进行调用，再按照type取对应页面值
*/
bool CDlgBusyForward::GetPageData(ForwardData * pData, FWD_TYPE eFwdType)
{
    if (NULL == pData)
    {
        return false;
    }

    if (m_qCheckBox != NULL)
    {
        //从页面滑块获取开关值
        pData->m_isOn = m_qCheckBox->GetData();

    }
    else
    {
        return false;
    }

    //指针判空
    if (m_pEditOffCode == NULL
            || m_pEditOnCode == NULL || m_pEditTarget == NULL)
    {
        return false;
    }

    //获取页面editLine中输入的文字
    pData->m_strTarget = m_pEditTarget->text().toUtf8().data();
    pData->m_strOnCode = m_pEditOnCode->text().toUtf8().data();
    pData->m_strOffCode = m_pEditOffCode->text().toUtf8().data();

    return true;
}

bool CDlgBusyForward::IsInputDataValid(InputDataErrorInfo & objErrorContent)
{
    //指针判空
    if (m_qCheckBox == NULL || m_pEditOffCode == NULL
            || m_pEditOnCode == NULL || m_pEditTarget == NULL)
    {
        return false;
    }
    else
    {
        //只有开关打开且转接置空时为无效输入
        if (m_qCheckBox->GetData())
        {
            if (m_pEditTarget->text().trimmed().isEmpty())
            {
                objErrorContent.strErrorContent = LANG_TRANSLATE(TRID_TARGET_CANNOT_BE_EMPTY);
                objErrorContent.pLineEdit = m_pEditTarget;
                return false;
            }
        }
        else
        {
            //开关关闭时，转接号码或者为空或者为有效号码
            if (!m_pEditTarget->text().trimmed().isEmpty()
                    && !qLineEditUtility::IsFormatValid(m_pEditTarget->text().trimmed(), EDIT_TYPE_PHONE_NUMBER))
            {
                objErrorContent.strErrorContent = LANG_TRANSLATE(TRID_TARGET_CANNOT_BE_EMPTY);
                objErrorContent.pLineEdit = m_pEditTarget;
                return false;
            }
        }
        //broadsoft开启之后不显示code，http://10.2.1.199/Bug.php?BugID=44441
        if (configParser_GetConfigInt(kszBroadsoftActive) == 0)
        {
            //on code与off code需要同时可用或同时不可用
            if (m_pEditOnCode->text().isEmpty()
                    && !m_pEditOffCode->text().isEmpty())
            {
                if (!qLineEditUtility::IsFormatValid(m_pEditOffCode->text(), EDIT_TYPE_CODE))
                {
                    objErrorContent.strErrorContent = LANG_TRANSLATE(TRID_OFF_CODE_IS_INVALID);
                    objErrorContent.pLineEdit = m_pEditOffCode;
                    return false;
                }
            }
            if (m_pEditOffCode->text().isEmpty()
                    && !m_pEditOnCode->text().isEmpty())
            {
                objErrorContent.strErrorContent = LANG_TRANSLATE(TRID_OFF_CODE_CANNOT_BE_EMPTY);
                objErrorContent.pLineEdit = m_pEditOffCode;
                return false;
            }
            if (!m_pEditOnCode->text().isEmpty()
                    && !m_pEditOffCode->text().isEmpty())
            {
                if (!qLineEditUtility::IsFormatValid(m_pEditOnCode->text(), EDIT_TYPE_CODE))
                {
                    objErrorContent.strErrorContent = LANG_TRANSLATE(TRID_ON_CODE_IS_INVALID);
                    objErrorContent.pLineEdit = m_pEditOnCode;
                    return false;
                }
                if (!qLineEditUtility::IsFormatValid(m_pEditOffCode->text(), EDIT_TYPE_CODE))
                {
                    objErrorContent.strErrorContent = LANG_TRANSLATE(TRID_OFF_CODE_IS_INVALID);
                    objErrorContent.pLineEdit = m_pEditOffCode;
                    return false;
                }
            }
        }
    }
    return true;
}

/*
调用此函数前要先进行点击type的判断，当为BUSY时，才进行对比
*/
bool CDlgBusyForward::IsStatusChanged()
{
    if (CDlgBaseFwdPageUI::IsStatusChanged())
    {
        return true;
    }

    const ForwardData & objConfigData = GetFwdData();
    ForwardData objPageData;

    if (GetPageData(&objPageData, GetUIType()))
    {
        //判断对应项数据是否存在改变，只要有一处改变，就返回true
        return !(objPageData == objConfigData);
    }

    return false;
}

//通过C层获取所有可用帐号的配置数据，与GetPageData值比较，有改动时返回true
bool CDlgBusyForward::IsAnyLineStatusChanged()
{
    //获取可用账号数据
    ListAccounts listValidAccount = acc_GetAvailableAccountList();

    ForwardData objPageData;
    ForwardData objConfigData;

    bool bResult = GetPageData(&objPageData, GetUIType());
    bool bIsAnyLineStautsChanged = false;

    ListAccounts::iterator iterAccount = listValidAccount.begin();

    //判断对所有可用帐号配置信息和当前页面是否相同，只要有一出不同，就返回true
    for (; iterAccount != listValidAccount.end(); ++iterAccount)
    {
        bResult = g_pCallForwardController->GetForwardDataByType(&objConfigData, FWD_TYPE_BUSY,
                  *iterAccount);

        if (bResult)
        {
            //判断对应项数据是否存在改变，只要有一处改变，就返回true
            bIsAnyLineStautsChanged = !(objPageData == objConfigData) || bIsAnyLineStautsChanged;
        }
    }

    return bIsAnyLineStautsChanged;
}

/*
调用此函数前要先进行点击type的判断，当为ALWAYS时，用此函数载入页面
*/
bool CDlgBusyForward::LoadPageData()
{
    //指针判空
    if (m_qCheckBox == NULL || m_pEditOffCode == NULL
            || m_pEditOnCode == NULL || m_pEditTarget == NULL)
    {
        return false;
    }

    //设置首选输入法
    qLineEditUtility::SetCurrentInputMethod(m_pEditTarget, EDIT_TYPE_PHONE_NUMBER);
    qLineEditUtility::SetCurrentInputMethod(m_pEditOnCode, EDIT_TYPE_PHONE_NUMBER);
    qLineEditUtility::SetCurrentInputMethod(m_pEditOffCode, EDIT_TYPE_PHONE_NUMBER);

    if (LoadData())
    {
        if (NULL == m_qCheckBox)
        {
            return false;
        }

        const ForwardData & objData = GetFwdData();

        //将objData中的值在界面上对应的区域显示出来
        m_qCheckBox->SetData(objData.m_isOn);
        m_pEditTarget->setText(toQString(objData.m_strTarget.c_str()));
        m_pEditOnCode->setText(toQString(objData.m_strOnCode.c_str()));
        m_pEditOffCode->setText(toQString(objData.m_strOffCode.c_str()));

        return true;
    }
    else
    {
        return false;
    }
}

//将所有可用帐号的的Always的属性全部设置成当前页面的属性
bool CDlgBusyForward::SavePageDataToAllLine()
{
    if (IsAnyLineStatusChanged())
    {
        bool bSaveResult = false;

        //取当前页面的数据
        ForwardData objData;
        GetPageData(&objData, GetUIType());

        //获取可用账号数据
        ListAccounts listValidAccount = acc_GetAvailableAccountList();

        ListAccounts::iterator iterAccount = listValidAccount.begin();
        for (; iterAccount != listValidAccount.end(); ++iterAccount)
        {
            bSaveResult = g_pCallForwardController->SetForwardDataByType(FWD_TYPE_BUSY, objData,
                          *iterAccount) || bSaveResult;
        }

        return bSaveResult;
    }

    return true;
}

void CDlgBusyForward::ProcessMsgBoxCallBack(CMessageBoxBase * pMessageBox)
{
    CDlgBaseFwdPageUI::ProcessMsgBoxCallBack(pMessageBox);

    if (NULL == pMessageBox
            || MessageBox_OK != pMessageBox->GetResult())
    {
        return;
    }

    InputDataErrorInfo objErrorInfo;
    if (IsInputDataValid(objErrorInfo))
    {
        if (SavePageDataToAllLine())
        {
            //弹出保存成功的提示框
            MessageBox_ShowCommonMsgBox(this,
                                        LANG_TRANSLATE(TRID_SAVING_CONFIG_FILE),
                                        MESSAGEBOX_NOTE, SHORT_TIME, "", "",
                                        MSG_ID_SHOW_NOTE_BEFORE_BACK);
        }
        else
        {
            //保存失败
            MessageBox_ShowCommonMsgBox(NULL, LANG_TRANSLATE(TRID_SAVE_FAILED), MESSAGEBOX_NOTE, SHORT_TIME);
        }
    }
    else
    {
        //先设置焦点，再弹出提示框
        if (NULL != objErrorInfo.pLineEdit)
        {
            CDlgBaseSubPage::SetErrorFocus(objErrorInfo.pLineEdit);
        }

        //弹出错误提示
        MessageBox_ShowCommonMsgBox(NULL, LANG_TRANSLATE(objErrorInfo.strErrorContent), MESSAGEBOX_Cancel);
    }
}

bool CDlgBusyForward::OnAction(const QString & strAction)
{
    if (strAction == "alllines")
    {
        MessageBox_ShowCommonMsgBox(this,
                                    LANG_TRANSLATE(TRID_IF_COPY_CONFIGURATION_TO_ALL_LINES),
                                    MESSAGEBOX_OkCancel);
        return true;
    }

    return CDlgBaseFwdPageUI::OnAction(strAction);
}

CDlgBusyForward::~CDlgBusyForward()
{
}

void CDlgBusyForward::OnExtraAction(int eActionType)
{
    if (eActionType == DIRECTORY_EXTRA)
    {
        DM_EnterSelectDirectoryUI(DlgBusyForward_DirectoryCallBack);
    }
}

void CDlgBusyForward::writeData(QString name, QString number)
{
    m_pEditTarget->setText(number);
}

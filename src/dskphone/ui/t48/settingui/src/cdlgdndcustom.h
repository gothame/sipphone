#ifndef CDLGDNDCUSTOM_H
#define CDLGDNDCUSTOM_H

#include "setting/include/common.h"
#include "cdlgbasesubpage.h"
#include "account/include/modaccount.h"
#include <QDialog>
#include <vector>

typedef std::pair<int, QLabel *>  PairAccountID;
typedef std::vector<PairAccountID>  VecAccountID;

class CDlgDNDCustom : public CDlgBaseSubPage
{
    Q_OBJECT

public:
    explicit CDlgDNDCustom(QWidget * parent = 0);
    ~CDlgDNDCustom();

    static CBaseDialog * CreateInstance()
    {
        return new CDlgDNDCustom();
    }
    //从V层读取当前界面的值
    bool GetPageData(int & nIndex);

    //通过C层获取已有配置数据，通过V层在界面上显示出来
    virtual bool LoadPageData();

    //通过C层获取配置数据，与GetPageData值比较，有改动时返回true
    virtual bool IsStatusChanged();

    //从V层读取当前界面的配置，通过C层保存
    virtual bool SavePageData();

    // 对输入框的数据进行验证
    virtual bool IsInputDataValid(InputDataErrorInfo & objErrorContent);

    //用于初始化数据。在构造函数中调用。设置控件的属性、样式、数据等都在其中进行
    virtual void InitData();

    // 设置子页面的SoftKey
    bool GetSoftkeyData(CArraySoftKeyBarData & objSoftData);

    virtual bool OnAction(const QString & strAction);

    virtual void OnReShow();

protected:
    void SetAllStatus(bool bStatus);

private:
    // 账号和m_pCmbBoxLineID的映射
    VecAccountID    m_VecAccountID;

    //可用帐号
    ListAccounts m_listAccount;

    //Softkey2按键状态（All Off/All On）
    bool            m_bFN2IsAllOn;

    bool            m_bEnableAccount;
};

#endif // CDLGDNDCUSTOM_H

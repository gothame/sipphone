#ifndef MODTALKUI_H
#define MODTALKUI_H
#include <ylstring.h>

/************************************************************************/
/* 接口  ： talkui_RegisterDlgClass()                                    */
/* 功能  ： 实现窗体类注册                                                    */
/* 参数说明 ：无                                                          */
/* 返回值 ： 无                                                            */
/************************************************************************/
void talkui_RegisterDlgClass();

/************************************************************************/
/* 接口  ： talkui_Init()                                                */
/* 功能  ： talkUI模块初始化                                                */
/* 参数说明 ：无                                                          */
/* 返回值 ： 无                                                            */
/************************************************************************/
void talkui_Init();

/************************************************************************/
/* 接口  ： talkui_Uninit()                                              */
/* 功能  ： talkUI模块注销                                               */
/* 参数说明 ：无                                                          */
/* 返回值 ： 无                                                            */
/************************************************************************/
void talkui_Uninit();

/************************************************************************/
//当前顶层界面是否是通话界面
bool talkui_IsInTalk();
/************************************************************************/

void talkui_SetCallManagerInfo();
/************************************************************************/
/* 接口  ： talkui_UpdateWnd(void* pData)                                */
/* 功能  ： 根据Logic层所提供的数据进行界面更新                               */
/* 参数说明 ：[in] void* pData:Logic层所提供的数据，需为DataLogic2UI     */
/* 返回值 ： 无                                                            */
/************************************************************************/
void talkui_UpdateWnd(void * pData);

/*******************************************************************
** 函数描述:    session退出
** 参数:        [in] iSessionID: session id
** 返回:        无
********************************************************************/
void talkui_SessionExit(int iSessionID);

/*******************************************************************
** 函数描述:    根据通话Id清空UI对应的数据指针
** 参数:        [in] iSessionID: session id
** 返回:        无
********************************************************************/
void talkui_ClearSessionData(int iSessionID);

/************************************************************************/
/* 接口  ： talkui_UpdateErrorInfo(void* pData)                          */
/* 功能  ： 根据Logic层所提供的数据进行错误信息更新，若有错误信息，         */
/*         则直接显示，无论处于何通话界面，若处于错误界面，                 */
/*         传过来的参数为空，则关闭错误提示界面                               */
/* 参数说明 ：[in] void* pData:Logic层所提供的数据，需为Error_Info           */
/* 返回值 ： 无                                                            */
/************************************************************************/
void talkui_UpdateErrorInfo(void * pData);

/************************************************************************/
/* 接口  ： talkui_UpdateChannelIcon()                                   */
/* 功能  ： 更新通道图标                                                   */
/* 参数说明 ：无                                                          */
/* 返回值 ： 无                                                            */
/************************************************************************/
//v80该接口取消
//void talkui_UpdateChannelIcon();

/************************************************************************/
/* 接口  ： talkui_GetTalkTimeBySessionId()                              */
/* 功能  ： 根据通话Id获得通话时间数据                                   */
/* 参数说明 ：[in] int nSessionId:所需获取的Session对应的Id                */
/* 返回值 ： 对应的Session通话时间的秒数                              */
/************************************************************************/
int talkui_GetTalkTimeBySessionId(int nSessionId);

/************************************************************************/
/* 接口  ： talkui_SetVolumeBarVisible()                             */
/* 功能  ： 关闭开启音量条                                                */
/* 参数说明 ：[in] bool bVisible:是否开启关闭音量条                       */
/* 返回值 ： 无                                                            */
/************************************************************************/
void talkui_SetVolumeBarVisible(bool bVisible);

/************************************************************************/
/* 接口  ： talkui_GetInputChar()                                        */
/* 功能  ： 获取输入法按键的第一个字符                              */
/* 参数说明 ：[in] string strIMEName:输入法的名称                        */
/* 参数说明 ：[in] int iKeyCode:按键的keyCode                           */
/* 返回值 ： 输入法获取到的字符                                                            */
/************************************************************************/
yl::string talkui_GetInputChar(const yl::string & strIMEName, int iKeyCode);

/************************************************************************/
/* 接口  ： talkui_GetInputContent()                                     */
/* 功能  ：  将当前所有UI(Qt)事件执行完毕，将所有输入完成 */
/* 参数说明 ：无                                                          */
/* 返回值 ： 输入框内容，yl::string类型                                 */
/************************************************************************/
yl::string talkui_GetInputContent();
bool talkui_GetInputContent(yl::string & strNum, yl::string & strDisplayname);

/************************************************************************/
/* 接口  ： talkui_EnterPickupMenu()                                     */
/* 功能  ： 进入Pickup操作界面     */
/* 参数说明 ：无                                                          */
/* 返回值 ： 无                                    */
/************************************************************************/
void talkui_EnterPickupMenu();

/************************************************************************/
/* 接口  ： talkui_UpdatePickupMenu()                                        */
/* 功能  ： 更新Pickup操作界面数据       */
/* 参数说明 ：无                                                          */
/* 返回值 ： 无                                */
/************************************************************************/
void talkui_UpdatePickupMenu();

/************************************************************************/
/* 接口  ： talkui_ExitPickupMenu()                                      */
/* 功能  ：  退出Pickup操作界面    */
/* 参数说明 ：无                                                          */
/* 返回值 ： 无                                    */
/************************************************************************/
void talkui_ExitPickupMenu();

/************************************************************************/
/* 接口  ： talkui_OpenPool()                                        */
/* 功能  ：  进入选择界面  */
/* 参数说明 ：
/*[in]bIsEnterFromIdle: 是否从Idle界面进入  默认false                         */
/* 返回值 ： 无                                    */
/************************************************************************/
bool talkui_OpenPool(bool bIsEnterFromIdle = false);

/************************************************************************/
/* 接口  ： talkui_ExitPool()                                        */
/* 功能  ：  退出选择界面  */
/* 参数说明 ：无                                                          */
/* 返回值 ： 无                                    */
/************************************************************************/
void talkui_ExitPool();

/************************************************************************/
/* 接口  ： talkui_EnterSCAMenu()                                        */
/* 功能  ： 进入SCA操作界面        */
/* 参数说明 ：*/
/*              [in]pData: ScaMenuData* 传给界面的数据
/* 返回值 ： 无                                    */
/************************************************************************/
bool talkui_EnterSCAMenu(void * pData);

/************************************************************************/
/* 接口  ： talkui_IsExistSCAMenu()                                      */
/* 功能  ： 是否存在SCA操作界面  */
/* 参数说明 ：无                                                          */
/* 返回值 ： 无                                    */
/************************************************************************/
bool talkui_IsExistSCAMenu();

/************************************************************************/
/* 接口  ： talkui_ExitSCAMenu()                                     */
/* 功能  ：  退出SCA操作界面   */
/* 参数说明 ：无                                                          */
/* 返回值 ： 无                                    */
/************************************************************************/
void talkui_ExitSCAMenu();

#if IF_FEATURE_SHOW_BLF_CALLID
bool talkui_EnterBLFMenu(void* pData);

bool talkui_IsExistBLFMenu(const yl::string& strKey);

void talkui_ExitBLFMenu();
#endif

/************************************************************************/
/* 接口  ： talkui_GetInputCallID()                                      */
/* 功能  ：  获取输入内容的Call id    */
/* 参数说明 ：无                                                          */
/* 返回值 ： 输入框内容的callid，int类型                                   */
/************************************************************************/
int talkui_GetInputCallID();

#endif // MODTALKUI_H

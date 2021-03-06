#ifndef _DSSKEY_ENUM_TYPE_HEADER_
#define _DSSKEY_ENUM_TYPE_HEADER_
// 通话录音状态
#include "commondefine/dsskeytypedefine.h"

enum Record_Status
{
    RECORD_IDLE, // 未录音
    RECORD_USING // 正在录音
};

enum DssKeyEventType
{
    DSS_KEY_EVENT_TYPE_BEGIN    = -1,
    DSS_KEY_EVENT_TYPE_CONFERENCE,
    DSS_KEY_EVENT_TYPE_FORWARD,
    DSS_KEY_EVENT_TYPE_TRANSFER,
    DSS_KEY_EVENT_TYPE_HOLD,
    DSS_KEY_EVENT_TYPE_DND,
    DSS_KEY_EVENT_TYPE_REDIAL,
    DSS_KEY_EVENT_TYPE_CALL_RETURN,
    DSS_KEY_EVENT_TYPE_SMS,
    DSS_KEY_EVENT_TYPE_PICK_UP,
    DSS_KEY_EVENT_TYPE_CALL_PARK,
    DSS_KEY_EVENT_TYPE_DTMF,
    DSS_KEY_EVENT_TYPE_VOICE_MAIL,
    DSS_KEY_EVENT_TYPE_GROUP_LISTENING,
    DSS_KEY_EVENT_TYPE_ZERO_SP_TOUCH,
    DSS_KEY_EVENT_TYPE_PREFIX,
    DSS_KEY_EVENT_TYPE_PUBLIC_HOLD,
    DSS_KEY_EVENT_TYPE_PRIVITE_HOLD,
    DSS_KEY_EVENT_TYPE_XML_GROUP,
    DSS_KEY_EVENT_TYPE_GROUP_PICKUP,
    DSS_KEY_EVENT_TYPE_PAGING,
    DSS_KEY_EVENT_TYPE_RECORD,
    DSS_KEY_EVENT_TYPE_LDAP,
    DSS_KEY_EVENT_TYPE_LOCAL_GROUP,
    DSS_KEY_EVENT_TYPE_BROADSOFT_GROUP,
    DSS_KEY_EVENT_TYPE_FAVORITE,
    DSS_KEY_EVENT_TYPE_XML_BROWSER,
    DSS_KEY_EVENT_TYPE_KEYGUARD,
    DSS_KEY_EVENT_TYPE_HOTDESKING,
    DSS_KEY_EVENT_TYPE_NETWORK_FAVORITE,
    DSS_KEY_EVENT_TYPE_BUDDIES,
    DSS_KEY_EVENT_TYPE_MYSTATUS,
    DSS_KEY_EVENT_TYPE_PAGING_LSIT,
    DSS_KEY_EVENT_TYPE_VOICE_RECORD,
    DSS_KEY_EVENT_TYPE_GET_BALANCE,
    DSS_KEY_EVENT_TYPE_PLCM,
    DSS_KEY_EVENT_TYPE_MEDIA_STATS,
    DSS_KEY_EVENT_TYPE_MTSW_CONTACT,
    DSS_KEY_EVENT_TYPE_MTSW_CALL_PARK,
    DSS_KEY_EVENT_TYPE_MESSAGE_LIST,
    DSS_KEY_EVENT_TYPE_MTSW_LOGOUT,
    DSS_KEY_EVENT_TYPE_CALLLIST,
    DSS_KEY_EVENT_TYPE_END,
};

// Line状态
enum Dsskey_Status
{
    DS_NON = -1,

    DS_LINE_FIRST,
    DS_LINE_NONE,
    DS_LINE_UNREGISTERED,           // 未注册、注册失败
    DS_LINE_REGISTERING,            // 正在注册
    DS_LINE_REGISTERED,         // 注册成功
    DS_LINE_USING,                  // 使用中
    DS_LINE_DISABLE,                // 禁用状态
    DS_LINE_FWD,
    DS_LINE_DND,
    DS_LINE_END,

    DS_BLF_FIRST, // 到DS_BLFLAST之间为blf状态
    // blf状态
    DS_BLF_STATUS_IDLE,
    DS_BLF_STATUS_RINGING,
    DS_BLF_STATUS_TALKING,
    DS_BLF_STATUS_UNKOWN,

    DS_BLF_STATUS_HOLD,
    DS_BLF_STATUS_TALKING_ME,
    DS_BLF_STATUS_RINGING_ME,
    DS_BLF_STATUS_PARKED,
    DS_BLF_STATUS_HELD_ME,
    DS_BLF_STATUS_CALLING_ME,
    DS_BLF_STATUS_CALLOUT,        //呼出
    DS_BLF_STATUS_PARK,
    DS_BLF_STATUS_DND,

    //Broadsoft SCA Status
    DS_BLA_STATUS_IDLE,             // BLA IDLE
    DS_BLA_STATUS_SEIZED,           // BLA SEIZE
    DS_BLA_STATUS_PROGRESSING,      // BLA PROGRESSING
    DS_BLA_STATUS_ALERTING,         // BLA ALERTING
    DS_BLA_STATUS_ACTIVE,           // BLA ACTIVE
    DS_BLA_STATUS_HELD,             // BLA HELD
    DS_BLA_STATUS_HELD_PRIVATE,     // BLA HELD_PRIVATE
    DS_BLA_STATUS_BRIDGE_ACITVE,    // BLA BRIDGE_ACITVE
    DS_BLA_STATUS_BRIDGE_HELD,      // BLA BRIDGE_HELD
    DS_BLA_STATUS_UNKOWN,           // BLA UNKOWN

    DS_BLF_LAST,

    DS_BLF_LED_MODE1, // Wildix特制,sip根据notify中的<mode>0</mode>对blf状态进行 (| 0x40)
    DS_BLF_LED_MODE2, // Wildix特制,sip根据notify中的<mode>0</mode>对blf状态进行 (| 0x20)

    DS_SCA_CALLPARK_FIRST,
    DS_SCA_CALLPARK_NON,
    DS_SCA_STATUS_IDLE,             // BLA IDLE
    DS_SCA_STATUS_SEIZED,           // BLA SEIZE
    DS_SCA_STATUS_PROGRESSING,      // BLA PROGRESSING
    DS_SCA_STATUS_ALERTING,         // BLA ALERTING
    DS_SCA_STATUS_ACTIVE,           // BLA ACTIVE
    DS_SCA_STATUS_HELD,             // BLA HELD
    DS_SCA_STATUS_HELD_PRIVATE,     // BLA HELD_PRIVATE
    DS_SCA_STATUS_BRIDGE_ACITVE,    // BLA BRIDGE_ACITVE
    DS_SCA_STATUS_BRIDGE_HELD,      // BLA BRIDGE_HELD
    DS_SCA_STATUS_UNKOWN,           // BLA UNKOWN
    DS_SCA_CALLPARK,
    DS_SCA_CALLPARK_END,

    DS_AUTO_PICKUP_FIRST,
    DS_AUTO_PICKUP_ON,
    DS_AUTO_PICKUP_OFF,
    DS_AUTO_PICKUP_END,

    DS_ACD_FIRST, // 到DS_ACDLAST之间为ACD状态
    DS_ACD_IDLE,
    DS_ACD_AVAILABLE,
    DS_ACD_UNAVAILABLE,
    DS_ACD_WRAPUP,
    DS_ACD_LAST,

    DS_SESSION_FIRST,
    DS_SESSION_NORMAL_USING, // 普通的使用linekey:LT_GREEN_ON
    DS_SESSION_HIDE, // 绑定的session隐藏起来了:LT_OFF
    DS_SESSION_HOLD, // hold:LT_GREEN_FLASH_3
    DS_SESSION_CALL_IN, // 来电:LT_GREEN_FLASH_2
    DS_SESSION_CALL_Out, // 来电:LT_GREEN_FLASH_2
    DS_SESSION_TALK,
    DS_SESSION_DIAL,
    DS_NO_SESSION,
    DS_SESSION_END,

    DS_FWD_FIRST,
    DS_FWD_USING,
    DS_FWD_DISABLE,
    DS_FWD_END,

    DS_DND_FIRST,
    DS_DND_USING,
    DS_DND_END,

    DS_AUTOANSWER_FIRST,
    DS_AUTOANSWER_USING,
    DS_AUTOANSWER_DISABLE,
    DS_AUTOANSWER_END,

    DS_URL_FIRST,
    DS_URL_OK,
    DS_URL_NETWORK_UNKNOW,
    DS_URL_NETWORK_UNAVAILABLE,
    DS_URL_END,

    DS_HOTELING_FIRST,
    DS_HOTELING_ON,
    DS_HOTELING_OFF,
    DS_HOTELING_END,

    DS_RECORD_FIRST,
    DS_RECORD_USING,
    DS_RECORD_IDLE,
    DS_RECORD_END,

    DS_UC_FIRST,
    DS_UC_ONLINE,  // 用户在线而且准备好沟通
    DS_UC_CHATTY,  // 用户在线而且希望和人聊天
    DS_UC_AWAY,    // 用户在线,但是已经离开电脑10分钟
    DS_UC_EXTENDED_AWAY,  // Extended Away
    DS_UC_BUSY,    // 用户处于忙碌状态
    DS_UC_OFFLINE, // 用户处于脱机状态
    DS_UC_UNKNOWN, // 未知状态
    DS_UC_END,
    DS_NOTIFY_FIRST,
    DS_NOTIFY_CONNECT,    // 已连接
    DS_NOTIFY_USING,      // 使用中
    DS_NOTIFY_DISCONNECT, // 断开连接
    DS_NOTIFY_DISABLE,    // 禁用
    DS_NOTIFY_END,

    DS_BTLINE_FIRST,
    DS_BTLINE_OFFLINE,     //未连接
    DS_BTLINE_ONLINE,      //已连接
    DS_BTLINE_USING,       //使用中
    DS_BTLINE_CONNECTTING,  //连接中
    DS_BTLINE_END,
    DS_XMLBROSER_FIRST,
    DS_XMLBROSER_IDLE,
    DS_XMLBROSER_LOADING,
    DS_XMLBROSER_LOAD_FINISH,
    DS_XMLBROSER_LOAD_ERROE,
    DS_XMLBROSER_END,

    DS_SRTP_FIRST,
    DS_SRTP_COMPLUSORY,
    DS_SRTP_END,
};

enum DssKeyLockType
{
    DSS_KEY_LOCK_TYPE_BEGIN = -1,
    DSS_KEY_LOCK_TYPE_DEFAULT,
    DSS_KEY_LOCK_TYPE_FLOAT,
    DSS_KEY_LOCK_TYPE_LOCK,
    DSS_KEY_LOCK_TYPE_END,
};

enum DsskeyExpRefresh
{
    DSS_KEY_REFRESH_ALL,
    DSS_KEY_REFRESH_ICON,
    DSS_KEY_REFRESH_LED,
};

enum DsskeyTempFileType
{
    DSS_FILE_TYPE_AUTO,
    DSS_FILE_TYPE_INI,
    DSS_FILE_TYPE_XML,
    DSS_FILE_TYPE_M7,
};

enum DSS_ATTR_TYPE
{
    DSS_ATTR_NONE,
    DSS_ATTR_NATIVE,
    DSS_ATTR_FACTORY,
};

enum DsskeySetFlags
{
    //只设置值
    DSSKEY_SET_NONE         = 0x00,
    //仅保存至内存且不通知（原先值可能会被缓存）
    DSSKEY_SET_ONLY         = 0x01 << 0,
    //进行通知
    DSSKEY_SET_NOTIFY       = 0x01 << 1,
    //写入文件
    DSSKEY_SET_WRITE        = 0x01 << 2,
    //通知ConfigServer
    DSSKEY_SET_NOTIFY_CFG   = 0x01 << 3,
    //刷新
    DSSKEY_SET_REFRESH      = 0x01 << 4,
    //特殊处理auto label
    DSSKEY_SET_AUTO_LABEL   = 0x01 << 5,
    //默认即时通知，即时写入读写
    DSSKEY_SET_NORMAL       = DSSKEY_SET_NOTIFY | DSSKEY_SET_WRITE | DSSKEY_SET_NOTIFY_CFG | DSSKEY_SET_REFRESH,
    // 默认写入基础上去除autolabel
    DSSKEY_SET_RELOAD       = DSSKEY_SET_NORMAL | DSSKEY_SET_AUTO_LABEL,
};

enum DSS_HIDE_MODE
{
    HIDE_MODE_NONE = 0x00, //不隐藏
    HIDE_MODE_COMMON = 1 << 0,
    HIDE_MODE_USERMODE_ADMIN = 1 << 1,
    HIDE_MODE_USERMODE_USER = 1 << 2,
    HIDE_MODE_USERMODE_VAR = 1 << 3,
    HIDE_MODE_PSTN_ACCOUNT = 1 << 4,
    HIDE_MODE_ALL = 0xFF,
};

#if IF_FEATURE_SRTP
enum SRTP_TYPE
{
    SRTP_DISABLE = 0,
    SRTP_OPTIONAL = 1,
    SRTP_COMPLUSORY = 2,
};
#endif //IF_FEATURE_SRTP

#define EXP_KEY_NUM     40

#endif


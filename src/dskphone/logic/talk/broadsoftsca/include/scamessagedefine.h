#ifndef _BLA_MSG_DEFINE_H_
#define _BLA_MSG_DEFINE_H_

#include "innermsgdefine.h"

// 联系人消息定义.
enum BLAMessage
{
    BLA_MESSAGE_BEGIN = INNER_MSG_BLA_MESSAGE_BEGIN,

    BLA_MESSAGE_DSSKEY_CHANGED = BLA_MESSAGE_BEGIN + 1,

    BLA_MESSAGE_UPDATE_SCA_INFO,

    BLA_MESSAGE_END = INNER_MSG_BLA_MESSAGE_END
};

#endif  // _BLA_MSG_DEFINE_H_
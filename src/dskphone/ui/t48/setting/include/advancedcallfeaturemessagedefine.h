#ifndef DEFINE_ADVANCEDCALLFEATUREMESSAGEDEFINE_H_
#define DEFINE_ADVANCEDCALLFEATUREMESSAGEDEFINE_H_

#include "innermsgdefine.h"

#if 0
// Advanced call feature message definition.
enum AdvanceCallFeatureMessage
{
    ADVANCED_CALL_FEATURE_MESSAGE_BEGIN = INNER_MSG_ADVANCED_CALL_FEATURE_BEGIN,

    // Key as send changed. Extra-changed key as send.
    ADVANCED_CALL_FEATURE_KEY_AS_SEND_CHANGED = ADVANCED_CALL_FEATURE_MESSAGE_BEGIN + 1,

    // History-save switch changed, LPARAM: 0-no to save, 1-to save.
    ADVANCED_CALL_FEATURE_HISTORY_SAVE_SWITCH_CHANGED = ADVANCED_CALL_FEATURE_MESSAGE_BEGIN + 2,
    // Hotline number changed. Extra-the changed hotline number.
    ADVANCED_CALL_FEATURE_HOTLINE_NUMBER_CHANGED = ADVANCED_CALL_FEATURE_MESSAGE_BEGIN + 3,
    // Hotline delay changed, LPARAM: The hotline delay after change.
    ADVANCED_CALL_FEATURE_HOTLINE_DELAY_CHANGED = ADVANCED_CALL_FEATURE_MESSAGE_BEGIN + 4,

    // Auto redial switch changed. LPRAM: 0-off, 1-on.
    ADVANCED_CALL_FEATURE_AUTO_REDIAL_SWITCH_CHANGED = ADVANCED_CALL_FEATURE_MESSAGE_BEGIN + 5,
    // Auto redial Interval changed. LPARAM: the new redial interval after change.
    ADVANCED_CALL_FEATURE_AUTO_REDIAL_INTERVAL_CHANGED = ADVANCED_CALL_FEATURE_MESSAGE_BEGIN + 6,
    // Auto redial times changed. LPARAM: the new auto redial times after change.
    ADVANCED_CALL_FEATURE_AUTO_REDIAL_TIMES_CHANGED = ADVANCED_CALL_FEATURE_MESSAGE_BEGIN + 7,

    // Call completion switch changed. LPRAM: 0-off, 1-on.
    ADVANCED_CALL_FEATURE_CALL_COMPLETION_SWITCH_CHANGED = ADVANCED_CALL_FEATURE_MESSAGE_BEGIN + 8,

    ADVANCED_CALL_FEATURE_TVOUTPUT_SWITCH_CHANGED = ADVANCED_CALL_FEATURE_MESSAGE_BEGIN + 9,

    ADVANCED_CALL_FEATURE_MESSAGE_END = INNER_MSG_ADVANCED_CALL_FEATURE_END
};
#endif
#endif  // DEFINE_ADVANCEDCALLFEATUREMESSAGEDEFINE_H_

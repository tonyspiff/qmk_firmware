#ifndef CONFIG_X_H
#define CONFIG_X_H

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#ifndef NO_DEBUG
#define NO_DEBUG
#endif

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 750

#define LEADER_TIMEOUT 750
#define LEADER_PER_KEY_TIMING

#undef TAPPING_TERM
#define TAPPING_TERM 250

#endif


#ifndef CONFIG_X_H
#define CONFIG_X_H

#include "../../config.h"

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

/* #define ONESHOT_TAP_TOGGLE 1 */
#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 750

#undef LEADER_TIMEOUT
#define LEADER_TIMEOUT 1500

#undef TAPPING_TERM
#define TAPPING_TERM 250

#endif

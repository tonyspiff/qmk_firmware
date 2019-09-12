/* *
 * X - A dvorak based, vim inspired keymap for ergodox keyboards
 * http://www.keyboard-layout-editor.com/#/gists/67569b26aa9c30d3e6fde64dd48e9696
 *
 * Modifiers Helpers
 */
#ifndef MODS_H
#define MODS_H

#define KC_CMD KC_LCMD
#define CMD(kc) LCMD(kc)
#define KC_OPT KC_LALT
#define OPT(kc) LALT(kc)
#define KC_CTRL KC_LCTRL
#define CTRL(kc) LCTL(kc)
#define KC_SUPR (QK_LCTL | QK_LALT | QK_LGUI)
#define SUPR(kc) (QK_LCTL | QK_LALT | QK_LGUI | (kc))

#define isShiftOn (keyboard_report->mods & MOD_BIT(KC_LSFT) \
			|| ((get_oneshot_mods() & MOD_BIT(KC_LSFT)) && !has_oneshot_mods_timed_out()) \
			|| keyboard_report->mods & MOD_BIT(KC_RSFT) \
			|| ((get_oneshot_mods() & MOD_BIT(KC_RSFT)) && !has_oneshot_mods_timed_out()))

#define isCmdOn (keyboard_report->mods & MOD_BIT(KC_LCMD) \
			|| ((get_oneshot_mods() & MOD_BIT(KC_LCMD)) && !has_oneshot_mods_timed_out()) \
			|| keyboard_report->mods & MOD_BIT(KC_RCMD) \
			|| ((get_oneshot_mods() & MOD_BIT(KC_RCMD)) && !has_oneshot_mods_timed_out()))

#define isCtrlOn (keyboard_report->mods & MOD_BIT(KC_LCTL) \
			|| ((get_oneshot_mods() & MOD_BIT(KC_LCTL)) && !has_oneshot_mods_timed_out()) \
			|| keyboard_report->mods & MOD_BIT(KC_RCTL) \
			|| ((get_oneshot_mods() & MOD_BIT(KC_RCTL)) && !has_oneshot_mods_timed_out()))

#define isOptionOn (keyboard_report->mods & MOD_BIT(KC_LALT) \
			|| ((get_oneshot_mods() & MOD_BIT(KC_LALT)) && !has_oneshot_mods_timed_out()) \
			|| keyboard_report->mods & MOD_BIT(KC_RALT) \
			|| ((get_oneshot_mods() & MOD_BIT(KC_RALT)) && !has_oneshot_mods_timed_out()))

#endif


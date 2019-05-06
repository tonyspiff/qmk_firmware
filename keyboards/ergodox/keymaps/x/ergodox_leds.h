/* *
 * X - A dvorak based, vim inspired keymap for ergodox keyboards
 * http://www.keyboard-layout-editor.com/#/gists/67569b26aa9c30d3e6fde64dd48e9696
 *
 * Ergodox LEDs
 */
#ifndef ERGODOX_LEDS_X_H
#define ERGODOX_LEDS_X_H

enum LedColor
{
	LedColorRed = 0,
	LedColorGreen,
	LedColorBlue,
	LedColorAll
};

// One Shot Modifiers
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

void toggleLed(bool isOn, uint8_t color)
{
	switch(color)
	{
		case LedColorRed:
			isOn ? ergodox_right_led_1_on() : ergodox_right_led_1_off();
			break;

		case LedColorGreen:
			isOn ? ergodox_right_led_2_on() : ergodox_right_led_2_off();
			break;

		case LedColorBlue:
			isOn ? ergodox_right_led_3_on() : ergodox_right_led_3_off();
			break;

		case LedColorAll:
			isOn ? ergodox_right_led_1_on() : ergodox_right_led_1_off();
			isOn ? ergodox_right_led_2_on() : ergodox_right_led_2_off();
			isOn ? ergodox_right_led_3_on() : ergodox_right_led_3_off();
			break;
	}
}

#endif

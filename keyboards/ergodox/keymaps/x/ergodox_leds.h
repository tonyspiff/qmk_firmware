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

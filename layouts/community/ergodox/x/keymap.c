/* *
 * X - A dvorak based, vim inspired keymap for ergodox keyboards
 * http://www.keyboard-layout-editor.com/#/gists/67569b26aa9c30d3e6fde64dd48e9696
 */
#include QMK_KEYBOARD_H
#include "layers.h"
#include "mods.h"
#include "macros.h"
#include "vim.h"
#include "leading.h"
#include "ergodox_leds.h"

#define X_____X KC_NO

enum TapDance
{
	Colon = 0,
	Quote,
	Bracket,
	Paren,
	Brace,
	Tilde
};

enum Keycode
{
	KC_UNUSED = SAFE_RANGE
};

#define SHUTDOWN LCAG(KC_EJCT)
#define LOCKSCR CTRL(RSFT(KC_PWR))
#define SYM_TAB LT(Arrows, KC_TAB)
#define NUM_F13 LT(Numpad, KC_F13)

qk_tap_dance_action_t tap_dance_actions[] =
{
	[Colon] = ACTION_TAP_DANCE_DOUBLE(KC_COLON, KC_SCOLON),
	[Quote] = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_DOUBLE_QUOTE),
	[Bracket] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_RBRACKET),
	[Paren] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_PAREN, KC_RIGHT_PAREN),
	[Brace] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE),
	[Tilde] = ACTION_TAP_DANCE_DOUBLE(KC_TILDE, KC_GRAVE)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = 
{
#if defined(KEYBOARD_ergodox_ez) || defined(KEYBOARD_ergodox_infinity)
[Base] = LAYOUT_ergodox
(
	// left hand
	LOCKSCR,		KC_F1,      KC_F2,   	KC_F3,		KC_F4,   	KC_F5,	KC_F11,
	KC_GRV,			KC_QUOTE,	KC_COMM,	KC_LEAD,	KC_P,   	KC_Y,   LCAG(KC_F13),
	KC_ESC,			KC_A,       KC_O,		KC_E,		KC_U,   	KC_I,
	OSM(MOD_LSFT),	TD(Colon),	KC_Q,   	KC_J,		KC_K,   	KC_X,   HYPR(KC_F13),
	KC_OPT,			KC_CMD,	    KC_CTRL,	KC_LEAD,	SYM_TAB,

				KC_LEFT,	KC_RGHT,
							KC_F16,
	KC_SPC,		KC_F13,		MEH(KC_SPC),

	// right hand
	KC_F12,			KC_F6, 		KC_F7, 		KC_F8,   	KC_F9,   	KC_F10,   	KC_CAPS,
	G(KC_Y),		KC_F,	 	KC_G, 		KC_C,		KC_R,   	KC_L,		KC_SLSH,
					KC_D,   	KC_H, 		KC_T,  		KC_N,   	KC_S,		KC_MINS,
	G(KC_TAB),		KC_B,   	KC_M, 		KC_W,   	KC_V,   	KC_Z,		OSM(MOD_RSFT),
								KC_ENT,		KC_LEAD,	KC_CTRL,  	KC_CMD,		KC_OPT,

	KC_MPLY,		KC_MNXT,
	KC_F16,
	CTRL(KC_F2),	_______,	KC_BSPC
),

[Numpad] = LAYOUT_ergodox
(
	// Left Hand
	RESET,		_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	TO(Base),	KC_3,		KC_2,		KC_1,		KC_0,		_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,

				_______,	_______,
							_______,
	_______,	_______,	_______,

	// Right Hand
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	KC_EQL,		KC_7,		KC_8,		KC_9,		KC_MINS,	KC_SLSH,
				KC_DOT,  	KC_4,   	KC_5,   	KC_6,   	KC_PLUS,   	KC_ASTR,
	_______,	KC_COMM,	KC_1,		KC_2,		KC_3,		KC_ENT,		_______,
							_______,	KC_0,		KC_CIRC,	KC_EXLM,	KC_X,

	_______,	_______,
	_______,
	_______,	_______,	_______
),

[Function] = LAYOUT_ergodox
(
	// Left Hand
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	TO(Base),	KC_F3,		KC_F2,		KC_F1,		KC_F10,		_______,
	_______,	KC_F13,		KC_F12, 	KC_F11,		_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,

				_______,	_______,
							_______,
	_______,	_______,	_______,

	// Right Hand
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	KC_F7,		KC_F8,		KC_F9,		_______,	_______,
				_______, 	KC_F4,   	KC_F5,   	KC_F6,   	_______,	_______,
	_______,	_______,	KC_F1,		KC_F2,		KC_F3,		_______,	_______,
							_______,	KC_F10,		_______,	_______,	_______,

	_______,	_______,
	_______,
	_______,	_______,	_______
),

[Arrows] = LAYOUT_ergodox
(
	// Left Hand
	RESET,		_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	TO(Base),	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	KC_DOWN,   	KC_UP,		_______,	_______,
	_______,	_______,	_______,	_______,	_______,

				_______,	_______,
							_______,
	_______,	_______,	_______,

	// Right Hand
	_______,	_______,	_______,	_______,	_______,	_______,	RESET,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
				_______,  	KC_LEFT,   	KC_DOWN,   	KC_UP,   	KC_RGHT,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
							_______,	_______,	_______,	_______,	_______,

	_______,	_______,
	_______,
	_______,	_______,	_______
)
#endif
};

#if defined(UNICODE_ENABLE)
void eeconfig_init_user(void) { set_unicode_input_mode(UC_OSX); }
#endif

// Called by QMK during key processing before the actual key event is handled
bool process_record_user(uint16_t keycode, keyrecord_t *record) 
{
	if (!vim_process_record_user(keycode, record))
		return false;

	if (!macros_process_record_user(keycode, record))
		return false;

	if (!record->event.pressed)
		return true;

	switch (keycode)
	{
		case KC_ESC:
			if (get_oneshot_mods() && !has_oneshot_mods_timed_out())
			{
				clear_oneshot_mods();
				return false;
			}
			break;

		case KC_ENT:
			if (curLayer != Base)
				layer_clear();
			break;
	}

	return true;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) 
{
	bool isRedLedOn = leading;

	bool isGreenLedOn = isVimodeOn;

	bool isBlueLedOn = isShiftOn || isCmdOn || isCtrlOn || isOptionOn
		|| curLayer != Base;

	toggleLed(isRedLedOn, LedColorRed);
	toggleLed(isGreenLedOn, LedColorGreen);
	toggleLed(isBlueLedOn, LedColorBlue);

	if (!leading)
		return;

	// TODO: see if it can be moved to process_record_user
	process_leading_sequence();

	if (timer_elapsed(leader_time) > LEADER_TIMEOUT)
		endLeading();
};


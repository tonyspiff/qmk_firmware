/* *
 * X - A dvorak based, vim inspired keymap for ergodox keyboards
 * http://www.keyboard-layout-editor.com/#/gists/67569b26aa9c30d3e6fde64dd48e9696
 */
#include QMK_KEYBOARD_H
#include "vim.h"

enum Layer
{
	Base = 0,
	SymbolsL,
	SymbolsR,
	Numpad,
	Arrows,
	Hotkeys
};

enum TapDance
{
	colon = 0,
	tilde
};

#define KC_SUPR (QK_LCTL | QK_LALT | QK_LGUI)
#define SHUTDOWN LCAG(KC_EJCT)
#define LOCKSCR RCTL(RSFT(KC_PWR))
#define SYM_TAB LT(SymbolsR, KC_TAB)
#define SYM_ENT LT(SymbolsL, KC_ENT)
#define NUM_F13 LT(Numpad, KC_F13)

qk_tap_dance_action_t tap_dance_actions[] =
{
	[colon] = ACTION_TAP_DANCE_DOUBLE(KC_COLON, KC_SCOLON),
	[tilde] = ACTION_TAP_DANCE_DOUBLE(KC_TILDE, KC_GRAVE)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = 
{
[Base] = LAYOUT_ergodox
(
	// left hand
	LOCKSCR,		KC_1,       KC_2,   	KC_3,		KC_4,   	KC_5,   KC_F11,
	TD(tilde),		KC_QUOT,    KC_COMM,	KC_DOT,		KC_P,   	KC_Y,   LCAG(KC_F13),
	LGUI_T(KC_ESC),	KC_A,       KC_O,		KC_E,		KC_U,   	KC_I,
	KC_LSFT,        TD(colon),	KC_Q,   	KC_J,		KC_K,   	KC_X,   HYPR(KC_F13),
	KC_LALT,		KC_HYPR,    KC_SUPR,	TT(Arrows),	SYM_TAB,

				KC_LEFT,	KC_RGHT,
							KC_F16,
	KC_SPC,		NUM_F13,	MEH(KC_SPC),

	// right hand
	KC_F12,			KC_6,  		KC_7, 		KC_8,   	KC_9,   	KC_0,   	KC_CAPS,
	RGUI(KC_GRV),	KC_F,	 	KC_G, 		KC_C,   	KC_R,   	KC_L,		RCTL_T(KC_SLSH),
					KC_D,   	KC_H, 		KC_T,  		KC_N,   	KC_S,		RGUI_T(KC_MINS),
	RGUI(KC_TAB),	KC_B,   	KC_M, 		KC_W,   	KC_V,   	KC_Z,		KC_RSFT,
								SYM_ENT,	KC_LEAD,	KC_SUPR,  	KC_HYPR,	KC_RALT,

	KC_MPLY,		KC_MNXT,
	KC_F16,
	RCTL(KC_F2),	OSL(Hotkeys),	KC_BSPC
),

[SymbolsL] = LAYOUT_ergodox
(
	// left hand
	SHUTDOWN,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		LGUI(KC_F11),
	LCTL_T(KC_GRV),	KC_EXLM,	KC_AT,		KC_HASH,	KC_DLR,		KC_PERC,	_______,
	_______,		KC_EQL,		KC_LBRC,	KC_LPRN,	KC_LCBR,	KC_PLUS,
	_______,		KC_SCLN,	KC_RBRC,	KC_RPRN,	KC_RCBR,	KC_BSLS,	_______,
	_______,		_______,	_______,	_______,	_______,

						_______,		_______,
										HYPR(KC_F17),
	LGUI(LALT(KC_SPC)), LGUI(KC_F13),	_______,

	// right hand
	_______,	_______,	_______,	_______,	_______,	_______,	RESET,
	_______,	KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		_______,
				KC_6,  		KC_7,   	KC_8,   	KC_9,   	KC_0,   	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
							_______,	_______,	_______,	_______,	_______,

	KC_VOLD,	KC_VOLU,
	_______,
	_______,	_______,	_______
),

[SymbolsR] = LAYOUT_ergodox
(
   	// left hand
	RESET,		_______,	_______,	_______,	_______,	_______,	_______,
	_______,	KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		_______,
	_______,	KC_1,		KC_2,		KC_3,		KC_4,		KC_5,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,

				KC_F14,		KC_F15,
							_______,
	_______,	_______,	_______,

	// right hand
	LGUI(KC_F12),	KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_PWR,
	HYPR(KC_F18),	KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,	_______,
					KC_QUES,	KC_LEFT,	KC_DOWN,	KC_UP,		KC_RGHT,	_______,
	_______,		KC_PIPE,	KC_HOME,	KC_PGDN,	KC_PGUP,	KC_END,		_______,
								_______,	_______,	_______,	_______,	_______,

	KC_MUTE,		KC_MPRV,
	HYPR(KC_F16),
	_______,		LGUI(KC_F),	KC_DEL
),

[Numpad] = LAYOUT_ergodox
(
   	// left hand
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,

				_______,	_______,
							_______,
	_______,	_______,	_______,

	// right hand
	_______,	_______,	_______,	_______,	KC_LPRN,	KC_RPRN,	_______,
	_______,	KC_EQL,		KC_7,		KC_8,		KC_9,		KC_MINS,	KC_SLSH,
				KC_DOT,  	KC_4,   	KC_5,   	KC_6,   	KC_PLUS,   	KC_ASTR,
	_______,	KC_COMM,	KC_1,		KC_2,		KC_3,		KC_ENT,		_______,
							KC_0,		KC_0,		KC_CIRC,	KC_EXLM,	KC_X,

	_______,	_______,
	_______,
	_______,	MEH(KC_SPC),	_______
),

[Arrows] = LAYOUT_ergodox
(
   	// left hand
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,

				_______,	_______,
							_______,
	_______,	_______,	_______,

	// right hand
	_______,	_______,	_______,		_______,		_______,		_______,		_______,
	_______,	_______,	RCTL(KC_LEFT),	RCTL(KC_DOWN),	RCTL(KC_UP),	RCTL(KC_RGHT),	_______,
				_______,	RGUI(KC_LEFT),	RGUI(KC_DOWN),	RGUI(KC_UP),	RGUI(KC_RGHT),	_______,
	_______,	_______,	RSFT(KC_LEFT),	RSFT(KC_DOWN),	RSFT(KC_UP),	RSFT(KC_RGHT),	_______,
							_______,		_______,		_______,		_______,		_______,

	_______,	_______,
	_______,
	_______,	_______,	_______
),

[Hotkeys] = LAYOUT_ergodox
(
   	// left hand
	_______,	_______,		_______,		_______,		_______,		_______,		_______,
	_______,	LCAG(KC_F1),	LCAG(KC_F2),	LCAG(KC_F3),	LCAG(KC_F4),	LCAG(KC_F5),	_______,
	_______,	MEH(KC_F1),		MEH(KC_F2),		MEH(KC_F3),		MEH(KC_F4),		MEH(KC_F5),
	_______,	HYPR(KC_F1),	HYPR(KC_F2),	HYPR(KC_F3),	HYPR(KC_F4),	HYPR(KC_F5),	_______,
	_______,	_______,		_______,		_______,		LCAG(KC_F11),

					_______,		_______,
									_______,
	MEH(KC_F11),	HYPR(KC_F11),	_______,

	// right hand
	_______,	_______,		_______,		_______,		_______,		_______,		_______,
	_______,	LCAG(KC_F6),	LCAG(KC_F7),	LCAG(KC_F8),	LCAG(KC_F9),	LCAG(KC_F10),	_______,
				MEH(KC_F6),		MEH(KC_F7),		MEH(KC_F8),		MEH(KC_F9),		RGUI(KC_SPC),	_______,
	_______,	HYPR(KC_F6),	HYPR(KC_F7),	HYPR(KC_F8),	HYPR(KC_F9),	HYPR(KC_F10),	_______,
								LCAG(KC_F12),	_______,		_______,		_______,		_______,

	_______,	_______,
	_______,
	_______,	_______,	HYPR(KC_F12)
)
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {};

void leader_start(void) 
{
	ergodox_right_led_3_on();
}

void leader_end(void)
{ 
	ergodox_right_led_3_off();
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) 
{
	ergodox_board_led_off();

	if (!leading)
	{
		ergodox_right_led_1_off();
		ergodox_right_led_2_off();
		ergodox_right_led_3_off();
	}

	uint8_t layer = biton32(layer_state);

	switch (layer)
	{
		case SymbolsL:
			ergodox_right_led_2_on();
			break;

		case SymbolsR:
			ergodox_right_led_2_on();
			break;

		case Numpad:
			ergodox_right_led_3_on();
			break;

		case Arrows:
			ergodox_right_led_1_on();
			break;

		case Hotkeys:
			ergodox_right_led_1_on();
			break;

		default:
			break;
	}

	// https://github.com/qmk/qmk_firmware/issues/370
	// Custom leading trying to mimic some Vim and Vimperator commands.
	// It activates before the timeout if sequence is complete but it has to be unambiguous.
	if (!leading)
		return;

	// w : ⌥ →
	if (leader_sequence[0] == (KC_W))
	{
		option(KC_RGHT);
	}

	// b : ⌥ ←
	else if (leader_sequence[0] == (KC_B))
	{
		option(KC_LEFT);
	}

	// a : ⌘ →
	else if (leader_sequence[0] == (KC_A))
	{
		cmd(KC_RGHT);
	}

	// 0 : ⌘ ←
	else if (leader_sequence[0] == (KC_0))
	{
		cmd(KC_LEFT);
	}

	/* Visual/Select/Shifted */
	// vw : ⌥ ⇧ →
	else if (leader_sequence[0] == (KC_V))
	{
		if (leader_sequence[1] == (KC_W))
		{
			optionShift(KC_RGHT);
		}

		// vb : ⌥ ⇧ ←
		else if (leader_sequence[1] == (KC_B))
		{
			optionShift(KC_LEFT);
		}
	}

	// TODO: Copy content before deleting
	/* Deletion */
	// dw : ⌥ ⌦
	else if (leader_sequence[0] == (KC_D))
	{
		if (leader_sequence[1] == (KC_W))
		{
			option(KC_DEL);
		}

		// db : ⌥ ⌫
		else if (leader_sequence[1] == (KC_B))
		{
			option(KC_BSPC);
		}

		// dd : ⌘ → then ⌘ ⌫
		else if (leader_sequence[1] == (KC_D))
		{
			cmd(KC_RGHT);
			cmd(KC_BSPC);
		}
	}

	/* CamelCase navigation */
	// ,w : ⌃ →
	else if (leader_sequence[0] == (KC_COMM))
	{
		if (leader_sequence[1] == (KC_W))
		{
			ctrl(KC_RGHT);
		}

		// ,b : ⌃ ←
		else if (leader_sequence[1] == (KC_B))
		{
			ctrl(KC_LEFT);
		}

		// ,vw : ⌃ ⇧ →
		else if (leader_sequence[1] == (KC_V) && leader_sequence[2] == (KC_W))
		{
			ctrlShift(KC_RGHT);
		}

		// ,vb : ⌃ ⇧ ←
		else if (leader_sequence[1] == (KC_V) && leader_sequence[2] == (KC_B))
		{
			ctrlShift(KC_LEFT);
		}

		// ,db : ⌃ ⌫
		else if (leader_sequence[1] == (KC_D) && leader_sequence[2] == (KC_B))
		{
			ctrl(KC_BSPC);
		}

		// ,dw : ⌃ ⌦
		else if (leader_sequence[1] == (KC_D) && leader_sequence[2] == (KC_W))
		{
			ctrl(KC_DEL);
		}
	}

	// Tabs / Extra
	else if (leader_sequence[0] == (KC_G))
	{
		// gt : ⌘ ⇧ →
		if (leader_sequence[1] == (KC_T))
		{
			cmdShift(KC_RGHT);
		}

		// ge : ⌘ ⇧ ←
		else if (leader_sequence[1] == (KC_E))
		{
			cmdShift(KC_LEFT);
		}
	}

	// Window / Split / Panel
	else if (leader_sequence[0] == (KC_ENT))
	{
		// ⏎ w : ⌘ ]
		if (leader_sequence[1] == (KC_W))
		{
			cmd(KC_RBRC);
		}
	}

	// s : ⌘ ⌃ →
	else if (leader_sequence[0] == (KC_S))
	{
		cmdCtrl(KC_RGHT);
	}

	// h : ⌘ ⌃ ←
	else if (leader_sequence[0] == (KC_H))
	{
		cmdCtrl(KC_LEFT);
	}

	if (timer_elapsed(leader_time) > LEADER_TIMEOUT)
	{
		leading = false;
	}

	if (leading == false)
	{
		leader_end();
	}
};


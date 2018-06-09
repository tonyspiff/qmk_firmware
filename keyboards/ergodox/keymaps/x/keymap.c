/* *
 * X - A dvorak based, vim inspired keymap for ergodox keyboards
 * http://www.keyboard-layout-editor.com/#/gists/67569b26aa9c30d3e6fde64dd48e9696
 */
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum Layer
{
	Base = 0,
	SymbolsL,
	SymbolsR,
	Numpad
};

enum Macro
{
	CtrlTilde = 0
};

#define KC_SUPR (QK_LCTL | QK_LALT | QK_LGUI)
#define SHUTDOWN LCAG(KC_EJCT)
#define LOCKSCR RCTL(RSFT(KC_PWR))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = 
{
[Base] = LAYOUT_ergodox
(
	// left hand
	LOCKSCR,			KC_1,           KC_2,   		KC_3,   	KC_4,   			KC_5,  		MEH(KC_F11),
	M(CtrlTilde),		KC_QUOT,        KC_COMM,		KC_DOT, 	KC_P,   			KC_Y,   	KC_F17,
	LGUI_T(KC_ESC),		KC_A,           KC_O,			KC_E,   	KC_U,   			KC_I,
	KC_LSFT,        	KC_COLN,        KC_Q,    		KC_J,   	KC_K,   			KC_X,   	LGUI(KC_GRV),
	KC_LALT,			KC_HYPR,		KC_SUPR,		TT(Numpad),	LT(SymbolsR, KC_TAB),

				KC_LEFT,		KC_RGHT,
								KC_F13,
	KC_SPC,		RGUI(KC_SPC),	KC_LEAD,

	// right hand
	MEH(KC_F12),	KC_6,  		KC_7,   				KC_8,   	KC_9,   	KC_0,   	KC_CAPS,
	KC_F18,			KC_F,	 	KC_G,   				KC_C,   	KC_R,   	KC_L,		RCTL_T(KC_SLSH),
					KC_D,   	KC_H,   				KC_T,  		KC_N,   	KC_S,		RGUI_T(KC_MINS),
	RGUI(KC_TAB),	KC_B,   	KC_M,   				KC_W,   	KC_V,   	KC_Z,		KC_RSFT,
								LT(SymbolsL, KC_ENT),	KC_LEAD,	KC_SUPR,  	KC_HYPR,	KC_RALT,

	KC_MPLY,	KC_MNXT,
	KC_F16,
	KC_LEAD,	RALT(KC_SPC),	KC_BSPC
),

[SymbolsL] = LAYOUT_ergodox
(
	// left hand
	SHUTDOWN,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F11,
	LCTL_T(KC_GRV),	KC_EXLM,	KC_AT,		KC_HASH,	KC_DLR,		KC_PERC,	HYPR(KC_F17),
	KC_TRNS,		KC_EQL,		KC_LBRC,	KC_LPRN,	KC_LCBR,	KC_PLUS,
	KC_TRNS,		KC_SCLN,	KC_RBRC,	KC_RPRN,	KC_RCBR,	KC_BSLS,	KC_TRNS,
	KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,

								KC_TRNS,	KC_TRNS,
											HYPR(KC_F13),
	LGUI(LALT(KC_SPC)),	LGUI(LCTL(KC_SPC)),	KC_TRNS,

	// right hand
	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	RESET,
	KC_TRNS,	KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_TRNS,
				KC_6,  		KC_7,   	KC_8,   	KC_9,   	KC_0,   	KC_TRNS,
	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
							KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,

	KC_VOLD,	KC_VOLU,
	KC_TRNS,
	KC_TRNS,	KC_TRNS,	KC_TRNS
),

[SymbolsR] = LAYOUT_ergodox
(
   	// left hand
	RESET,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
	KC_TRNS,	KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_TRNS,
	KC_TRNS,	KC_1,		KC_2,		KC_3,		KC_4,		KC_5,
	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,

				KC_F14,		KC_F15,
							KC_TRNS,
	KC_TRNS,	KC_TRNS,	KC_TRNS,

	// right hand
	KC_F12,			KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_PWR,
	HYPR(KC_F18),	KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,	KC_TRNS,
					KC_QUES,	KC_LEFT,	KC_DOWN,	KC_UP,		KC_RGHT,	KC_TRNS,
	KC_TRNS,		KC_PIPE,	KC_HOME,	KC_PGDN,	KC_PGUP,	KC_END,		KC_TRNS,
								KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,

	KC_MUTE,		KC_MPRV,
	HYPR(KC_F16),
	KC_TRNS,		LCAG(KC_SPC),	KC_DEL
),

[Numpad] = LAYOUT_ergodox
(
   	// left hand
	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,

				KC_TRNS,	KC_TRNS,
							KC_TRNS,
	KC_TRNS,	KC_TRNS,	KC_TRNS,

	// right hand
	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
	KC_TRNS,	KC_EQL,		KC_7,		KC_8,		KC_9,		KC_MINS,	KC_SLSH,
				KC_DOT,  	KC_4,   	KC_5,   	KC_6,   	KC_PLUS,   	KC_ASTR,
	KC_TRNS,	KC_COMM,	KC_1,		KC_2,		KC_3,		KC_ENT,		KC_TRNS,
							KC_0,		KC_0,		KC_TRNS,	KC_TRNS,	KC_TRNS,

	KC_TRNS,	KC_TRNS,
	KC_TRNS,
	KC_TRNS,	KC_TRNS,	KC_TRNS
)

};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void)
{
};

static uint16_t start;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	switch (id)
	{
		// https://github.com/qmk/qmk_firmware/issues/50
		case CtrlTilde:
			if (record->event.pressed)
			{
				start = timer_read();

				return MACRO(D(LCTL), END);
			}
			else
			{
				if (timer_elapsed(start) > TAPPING_TERM) 
				{
					return MACRO(U(LCTL), END);
				}
				else
				{
					return MACRO(U(LCTL), D(LSFT), T(GRV), U(LSFT), END);
				}
			}
			break;
	}

	return MACRO_NONE;
}

LEADER_EXTERNS();

void leader_start(void) 
{
	ergodox_right_led_1_on();
	ergodox_right_led_2_on();
	ergodox_right_led_3_on();
}

void leader_end(void)
{ 
	ergodox_right_led_1_off();
	ergodox_right_led_2_off();
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
			ergodox_right_led_1_on();
			break;

		case SymbolsR:
			ergodox_right_led_2_on();
			break;

		case Numpad:
			ergodox_right_led_3_on();
			break;

		default:
			break;
	}

	// https://github.com/qmk/qmk_firmware/issues/370
	// Custom leading trying to mimic some Vim and Vimperator commands.
	// It activates before the timeout if sequence is complete but it has to be unambiguous.
	if (leading)
	{
		uint8_t count = 1;
		uint8_t offset = 0;
		
		// Count / Repetition (up to 9)
		// FIXME: it doesn't work if the number is on a different layer
		if (leader_sequence[0] >= (KC_1) && leader_sequence[0] <= (KC_9))
		{
			count = leader_sequence[0] - (KC_Z);
			offset++;
		}

		// ⎋ : Abort leading sequence
		// FIXME: not working, maybe because Esc is a dual role key
		if (leader_sequence[offset + 0] == (KC_ESC))
		{
			leading = false;
		}

		// w : ⌥ →
		else if (leader_sequence[offset + 0] == (KC_W))
		{
			for (uint8_t i = 0; i < count; i++)
			{
				register_code(KC_LALT);
				register_code(KC_RGHT);
				unregister_code(KC_RGHT);
				unregister_code(KC_LALT);
			}

			leading = false;
		}

		// b : ⌥ ←
		else if (leader_sequence[offset + 0] == (KC_B))
		{
			for (uint8_t i = 0; i < count; i++)
			{
				register_code(KC_LALT);
				register_code(KC_LEFT);
				unregister_code(KC_LEFT);
				unregister_code(KC_LALT);
			}

			leading = false;
		}

		// a : ⌘ →
		else if (leader_sequence[offset + 0] == (KC_A))
		{
			for (uint8_t i = 0; i < count; i++)
			{
				register_code(KC_LGUI);
				register_code(KC_RGHT);
				unregister_code(KC_RGHT);
				unregister_code(KC_LGUI);
			}

			leading = false;
		}

		// 0 : ⌘ ←
		else if (leader_sequence[offset + 0] == (KC_0))
		{
			for (uint8_t i = 0; i < count; i++)
			{
				register_code(KC_LGUI);
				register_code(KC_LEFT);
				unregister_code(KC_LEFT);
				unregister_code(KC_LGUI);
			}

			leading = false;
		}

		/* Visual/Select/Shifted */
		// vw : ⌥ ⇧ →
		else if (leader_sequence[offset + 0] == (KC_V))
		{
			if (leader_sequence[offset + 1] == (KC_W))
			{
				for (uint8_t i = 0; i < count; i++)
				{
					register_code(KC_LALT);
					register_code(KC_LSFT);
					register_code(KC_RGHT);
					unregister_code(KC_RGHT);
					unregister_code(KC_LSFT);
					unregister_code(KC_LALT);
				}

				leading = false;
			}

			// vb : ⌥ ⇧ ←
			else if (leader_sequence[offset + 1] == (KC_B))
			{
				for (uint8_t i = 0; i < count; i++)
				{
					register_code(KC_LALT);
					register_code(KC_LSFT);
					register_code(KC_LEFT);
					unregister_code(KC_LEFT);
					unregister_code(KC_LSFT);
					unregister_code(KC_LALT);
				}

				leading = false;
			}
		}

		// TODO: Copy content before deleting
		/* Deletion */
		// dw : ⌥ ⌦
		else if (leader_sequence[offset + 0] == (KC_D))
		{
			if (leader_sequence[offset + 1] == (KC_W))
			{
				for (uint8_t i = 0; i < count; i++)
				{
					register_code(KC_LALT);
					register_code(KC_DEL);
					unregister_code(KC_DEL);
					unregister_code(KC_LALT);
				}

				leading = false;
			}

			// db : ⌥ ⌫
			else if (leader_sequence[offset + 1] == (KC_B))
			{
				for (uint8_t i = 0; i < count; i++)
				{
					register_code(KC_LALT);
					register_code(KC_BSPC);
					unregister_code(KC_BSPC);
					unregister_code(KC_LALT);
				}

				leading = false;
			}

			// dd : ⌘ → then ⌘ ⌫
			else if (leader_sequence[offset + 1] == (KC_D))
			{
				for (uint8_t i = 0; i < count; i++)
				{
					register_code(KC_LGUI);
					register_code(KC_RGHT);
					unregister_code(KC_RGHT);
					register_code(KC_BSPC);
					unregister_code(KC_BSPC);
					unregister_code(KC_LGUI);
				}

				leading = false;
			}
		}

		/* CamelCase navigation */
		// ,w : ⌃ →
		else if (leader_sequence[offset + 0] == (KC_COMM))
		{
			if (leader_sequence[offset + 1] == (KC_W))
			{
				for (uint8_t i = 0; i < count; i++)
				{
					register_code(KC_LCTL);
					register_code(KC_RGHT);
					unregister_code(KC_RGHT);
					unregister_code(KC_LCTL);
				}

				leading = false;
			}

			// ,b : ⌃ ←
			else if (leader_sequence[offset + 1] == (KC_B))
			{
				for (uint8_t i = 0; i < count; i++)
				{
					register_code(KC_LCTL);
					register_code(KC_LEFT);
					unregister_code(KC_LEFT);
					unregister_code(KC_LCTL);
				}

				leading = false;
			}

			// ,vw : ⌃ ⇧ →
			else if (leader_sequence[offset + 1] == (KC_V) && leader_sequence[offset + 2] == (KC_W))
			{
				for (uint8_t i = 0; i < count; i++)
				{
					register_code(KC_LCTL);
					register_code(KC_LSFT);
					register_code(KC_RGHT);
					unregister_code(KC_RGHT);
					unregister_code(KC_LSFT);
					unregister_code(KC_LCTL);
				}

				leading = false;
			}

			// ,vb : ⌃ ⇧ ←
			else if (leader_sequence[offset + 1] == (KC_V) && leader_sequence[offset + 2] == (KC_B))
			{
				for (uint8_t i = 0; i < count; i++)
				{
					register_code(KC_LCTL);
					register_code(KC_LSFT);
					register_code(KC_LEFT);
					unregister_code(KC_LEFT);
					unregister_code(KC_LSFT);
					unregister_code(KC_LCTL);
				}

				leading = false;
			}

			// ,db : ⌃ ⌫
			else if (leader_sequence[offset + 1] == (KC_D) && leader_sequence[offset + 2] == (KC_B))
			{
				for (uint8_t i = 0; i < count; i++)
				{
					register_code(KC_LCTL);
					register_code(KC_BSPC);
					unregister_code(KC_BSPC);
					unregister_code(KC_LCTL);
				}

				leading = false;
			}

			// ,dw : ⌃ ⌦
			else if (leader_sequence[offset + 1] == (KC_D) && leader_sequence[offset + 2] == (KC_W))
			{
				for (uint8_t i = 0; i < count; i++)
				{
					register_code(KC_LCTL);
					register_code(KC_DEL);
					unregister_code(KC_DEL);
					unregister_code(KC_LCTL);
				}

				leading = false;
			}
		}

		// Terminal
		else if (leader_sequence[offset + 0] == (KC_T))
		{
			// tw : ⌃ →
			if (leader_sequence[offset + 1] == (KC_W))
			{
				for (uint8_t i = 0; i < count; i++)
				{
					register_code(KC_LCTL);
					register_code(KC_RGHT);
					unregister_code(KC_RGHT);
					unregister_code(KC_LCTL);
				}

				leading = false;
			}

			// tb : ⌃ ←
			else if (leader_sequence[offset + 1] == (KC_B))
			{
				for (uint8_t i = 0; i < count; i++)
				{
					register_code(KC_LCTL);
					register_code(KC_LEFT);
					unregister_code(KC_LEFT);
					unregister_code(KC_LCTL);
				}

				leading = false;
			}

			// ta : ⌃ e ␣
			else if (leader_sequence[offset + 1] == (KC_A))
			{
				for (uint8_t i = 0; i < count; i++)
				{
					register_code(KC_LCTL);
					register_code(KC_E);
					unregister_code(KC_E);
					unregister_code(KC_LCTL);
					register_code(KC_SPC);
					unregister_code(KC_SPC);
				}

				leading = false;
			}

			// t0 : ⌃ a
			else if (leader_sequence[offset + 1] == (KC_0))
			{
				for (uint8_t i = 0; i < count; i++)
				{
					register_code(KC_LCTL);
					register_code(KC_A);
					unregister_code(KC_A);
					unregister_code(KC_LCTL);
				}

				leading = false;
			}

		}

		// Tabs / Extra
		else if (leader_sequence[offset + 0] == (KC_G))
		{
			// gt : ⌘ ⇧ →
			if (leader_sequence[offset + 1] == (KC_T))
			{
				for (uint8_t i = 0; i < count; i++)
				{
					register_code(KC_LGUI);
					register_code(KC_LSFT);
					register_code(KC_RGHT);
					unregister_code(KC_RGHT);
					unregister_code(KC_LSFT);
					unregister_code(KC_LGUI);
				}

				leading = false;
			}

			// ge : ⌘ ⇧ ←
			else if (leader_sequence[offset + 1] == (KC_E))
			{
				for (uint8_t i = 0; i < count; i++)
				{
					register_code(KC_LGUI);
					register_code(KC_LSFT);
					register_code(KC_LEFT);
					unregister_code(KC_LEFT);
					unregister_code(KC_LSFT);
					unregister_code(KC_LGUI);
				}

				leading = false;
			}
		}

		// Window / Split / Panel
		else if (leader_sequence[offset + 0] == (KC_ENT))
		{
			// ⏎ w : ⌘ ]
			if (leader_sequence[offset + 1] == (KC_W))
			{
				for (uint8_t i = 0; i < count; i++)
				{
					register_code(KC_LGUI);
					register_code(KC_RBRC);
					unregister_code(KC_RBRC);
					unregister_code(KC_LGUI);
				}

				leading = false;
			}
		}

		// s : ⌘ ⌃ →
		else if (leader_sequence[offset + 0] == (KC_S))
		{
			for (uint8_t i = 0; i < count; i++)
			{
				register_code(KC_LGUI);
				register_code(KC_LCTL);
				register_code(KC_RGHT);
				unregister_code(KC_RGHT);
				unregister_code(KC_LCTL);
				unregister_code(KC_LGUI);
			}

			leading = false;
		}

		// h : ⌘ ⌃ ←
		else if (leader_sequence[offset + 0] == (KC_H))
		{
			for (uint8_t i = 0; i < count; i++)
			{
				register_code(KC_LGUI);
				register_code(KC_LCTL);
				register_code(KC_LEFT);
				unregister_code(KC_LEFT);
				unregister_code(KC_LCTL);
				unregister_code(KC_LGUI);
			}

			leading = false;
		}

		if (timer_elapsed(leader_time) > LEADER_TIMEOUT)
		{
			leading = false;
		}

		if (leading == false)
		{
			leader_end();
		}
	}
};


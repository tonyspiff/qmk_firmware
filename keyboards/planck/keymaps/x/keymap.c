/* *
 * Planck X - A dvorak based, vim inspired keymap for Planck keyboards
 * http://www.keyboard-layout-editor.com/#/gists/6b62cc3de20991eb879aabb32cf75b8f
 */
#include QMK_KEYBOARD_H
#include "action_layer.h"

enum Layer
{
	Base = 0,
	SymbolsL,
	SymbolsR,
	Numpad,
	Macros
};

enum Macro
{
	CtrlTilde = 0
};

#define KC_SUPR (QK_LCTL | QK_LALT | QK_LGUI)
#define NUM_SPC LT(Numpad, KC_SPC)
#define SYM_TAB LT(SymbolsR, KC_TAB)
#define SYM_ENT LT(SymbolsL, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = 
{
[Base] = LAYOUT_planck_grid
(
M(CtrlTilde),	KC_QUOT,     KC_COMM,	KC_DOT, 	KC_P,		KC_Y, 	 	KC_F,		KC_G,   	KC_C,   	KC_R,   	KC_L,		RCTL_T(KC_SLSH),
LGUI_T(KC_ESC),	KC_A,       KC_O,		KC_E,   	KC_U,  		KC_I, 	 	KC_D,   	KC_H,  	 	KC_T,  		KC_N,   	KC_S,		RGUI_T(KC_MINS),
KC_LSFT,       	KC_COLN,    KC_Q,   	KC_J,   	KC_K,  		KC_X, 	 	KC_B,   	KC_M,  	 	KC_W,   	KC_V,   	KC_Z,		KC_RSFT,
KC_LALT,		KC_HYPR,	KC_SUPR,	KC_LEAD, 	SYM_TAB,	NUM_SPC,	KC_BSPC,	SYM_ENT,	KC_LEAD,	KC_SUPR,  	KC_HYPR,	KC_RALT
),

[SymbolsL] = LAYOUT_planck_grid
(
LCTL_T(KC_GRV),	KC_EXLM,	KC_AT,		KC_HASH,	KC_DLR,				KC_PERC,       	KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		RESET,
_______,		KC_EQL,		KC_LBRC,	KC_LPRN,	KC_LCBR,			KC_PLUS,       	KC_6,  		KC_7,   	KC_8,   	KC_9,   	KC_0,   	_______,
_______,		KC_SCLN,	KC_RBRC,	KC_RPRN,	KC_RCBR,			KC_BSLS,       	_______,	_______,	_______,	_______,	_______,	_______,
_______,		_______,	_______,	_______,	RGUI(RCTL(KC_SPC)),	RGUI(KC_SPC),	_______,	_______,	_______,	_______,    _______,	_______
),

[SymbolsR] = LAYOUT_planck_grid
(
RESET,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,	 	KC_CIRC,		KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,	_______,
_______,	KC_1,		KC_2,		KC_3,		KC_4,		KC_5,    	KC_QUES,		KC_LEFT,	KC_DOWN,	KC_UP,		KC_RGHT,	_______,
_______,	_______,	_______,	_______,	_______,	_______, 	KC_PIPE,		KC_HOME,	KC_PGDN,	KC_PGUP,	KC_END,		_______,
_______,	_______,	_______,	_______,	_______, 	_______, 	KC_DEL,			_______,	_______,	_______,	_______,	_______
),

[Numpad] = LAYOUT_planck_grid
(
_______,	_______,	_______,	_______,	_______,	_______, 	KC_EQL,		KC_7,	KC_8,	KC_9,		KC_MINS,	KC_SLSH,
_______,	_______,	_______,	_______,	_______,	_______,	KC_DOT,  	KC_4,  	KC_5,  	KC_6,   	KC_PLUS,   	KC_ASTR,
_______,	_______,	_______,	_______,	_______,	_______, 	KC_COMM,	KC_1,	KC_2,	KC_3,		KC_ENT,		_______,
_______,	_______,	_______,	_______,	_______, 	_______, 	KC_F13,		KC_0,	KC_0,	KC_CIRC,	KC_EXLM,	KC_X
),

[Macros] = LAYOUT_planck_grid
(
_______,	_______,	_______,	_______,	_______,	_______, 	KC_EQL,		KC_7,	KC_8,	KC_9,		KC_MINS,	KC_SLSH,
_______,	_______,	_______,	_______,	_______,	_______,	KC_DOT,  	KC_4,  	KC_5,  	KC_6,   	KC_PLUS,   	KC_ASTR,
_______,	_______,	_______,	_______,	_______,	_______, 	KC_COMM,	KC_1,	KC_2,	KC_3,		KC_ENT,		_______,
_______,	_______,	_______,	_______,	_______, 	_______, 	KC_DEL,		KC_0,	KC_0,	KC_CIRC,	KC_EXLM,	KC_X
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
	/* ergodox_right_led_3_on(); */
}

void leader_end(void)
{ 
    /* ergodox_right_led_3_off(); */
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) 
{
    /* uint8_t layer = biton32(layer_state); */

    /* ergodox_board_led_off(); */
    /* ergodox_right_led_1_off(); */
    /* ergodox_right_led_2_off(); */
	/*  */
    /* switch (layer) */
   	/* { */
    /*     case SymbolsL: */
    /*         ergodox_right_led_1_on(); */
    /*         break; */
    /*     case SymbolsR: */
    /*         ergodox_right_led_2_on(); */
    /*         break; */
    /*     default: */
    /*         break; */
    /* } */

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


/* *
 * X - A dvorak based, vim inspired keymap for ergodox keyboards
 * http://www.keyboard-layout-editor.com/#/gists/67569b26aa9c30d3e6fde64dd48e9696
 */
#include QMK_KEYBOARD_H
#include "vim.h"
#include "ergodox_leds.h"

#define curLayer (biton32(layer_state))
#define X_____X KC_NO

enum Layer
{
	Base = 0,
	Media,
	Numpad,
	Arrows
};

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
#define LOCKSCR RCTL(RSFT(KC_PWR))
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
[Base] = LAYOUT_ergodox
(
	// left hand
	LOCKSCR,		KC_F1,      KC_F2,   	KC_F3,		KC_F4,   	KC_F5,	KC_F11,
	LCTL_T(KC_GRV),	KC_QUOTE,	KC_COMM,	KC_LEAD,	KC_P,   	KC_Y,   LCAG(KC_F13),
	LGUI_T(KC_ESC),	KC_A,       KC_O,		KC_E,		KC_U,   	KC_I,
	OSM(MOD_LSFT),	TD(Colon),	KC_Q,   	KC_J,		KC_K,   	KC_X,   HYPR(KC_F13),
	KC_LALT,		KC_HYPR,    KC_SUPR,	KC_LEAD,	SYM_TAB,

				KC_LEFT,	KC_RGHT,
							KC_F16,
	LT(Numpad, KC_SPC),	NUM_F13,	MEH(KC_SPC),

	// right hand
	KC_F12,			KC_F6, 		KC_F7, 		KC_F8,   	KC_F9,   	KC_F10,   	KC_CAPS,
	G(KC_Y),		KC_F,	 	KC_G, 		KC_C,		KC_R,   	KC_L,		RCTL_T(KC_SLSH),
					KC_D,   	KC_H, 		KC_T,  		KC_N,   	KC_S,		RGUI_T(KC_MINS),
	G(KC_TAB),		KC_B,   	KC_M, 		KC_W,   	KC_V,   	KC_Z,		OSM(MOD_RSFT),
								KC_ENT,		KC_LEAD,	KC_SUPR,  	KC_HYPR,	KC_RALT,

	KC_MPLY,		KC_MNXT,
	KC_F16,
	RCTL(KC_F2),	_______,	KC_BSPC
),

[Numpad] = LAYOUT_ergodox
(
	// Left Hand
	RESET,		_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,

				_______,	_______,
							_______,
	_______,	_______,	_______,

	// Right Hand
	_______,	_______,	_______,	_______,	KC_LPRN,	KC_RPRN,	_______,
	_______,	KC_EQL,		KC_7,		KC_8,		KC_9,		KC_MINS,	KC_SLSH,
				KC_DOT,  	KC_4,   	KC_5,   	KC_6,   	KC_PLUS,   	KC_ASTR,
	_______,	KC_COMM,	KC_1,		KC_2,		KC_3,		KC_ENT,		_______,
							KC_0,		KC_0,		KC_CIRC,	KC_EXLM,	KC_X,

	_______,	_______,
	_______,
	_______,	_______,	_______
),

[Arrows] = LAYOUT_ergodox
(
	// Left Hand
	RESET,		_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,

				_______,	_______,
							_______,
	_______,	_______,	_______,

	// Right Hand
	_______,	_______,	_______,	_______,	_______,	_______,	RESET,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
				_______,  	KC_LEFT,   	KC_DOWN,   	KC_UP,   	KC_RGHT,   	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
							_______,	_______,	_______,	_______,	_______,

	_______,	_______,
	_______,
	_______,	_______,	_______
),

/* [Template] = LAYOUT_ergodox */
/* ( */
/*	// Left Hand */
/* 	_______,	_______,	_______,	_______,	_______,	_______,	_______, */
/* 	_______,	_______,	_______,	_______,	_______,	_______,	_______, */
/* 	_______,	_______,	_______,	_______,	_______,	_______, */
/* 	_______,	_______,	_______,	_______,	_______,	_______,	_______, */
/* 	_______,	_______,	_______,	_______,	_______, */

/* 				_______,	_______, */
/* 							_______, */
/* 	_______,	_______,	_______, */

/* 	// Right Hand */
/* 	_______,	_______,	_______,	_______,	_______,	_______,	_______, */
/* 	_______,	_______,	_______,	_______,	_______,	_______,	_______, */
/* 				_______,	_______,	_______,	_______,	_______,	_______, */
/* 	_______,	_______,	_______,	_______,	_______,	_______,	_______, */
/* 							_______,	_______,	_______,	_______,	_______, */

/* 	_______,	_______, */
/* 	_______, */
/* 	_______,	_______,	_______ */
/* ) */
};

#if defined(UNICODE_ENABLE)
void eeconfig_init_user(void)
{
	set_unicode_input_mode(UC_OSX);
}
#endif

// Called by QMK during key processing before the actual key event is handled.
bool process_record_user (uint16_t keycode, keyrecord_t *record) 
{
	if (!record->event.pressed) { return true; }

	switch (keycode)
	{
		case KC_ESC:
		{
			if (get_oneshot_mods()
				&& !has_oneshot_mods_timed_out())
			{
				clear_oneshot_mods();
				return false;
			}
		}
	}

	return true;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) 
{
	bool isRedLedOn = leading;

	bool isGreenLedOn = curLayer == Numpad
		|| curLayer == Arrows;

	bool isBlueLedOn = isShiftOn || isCmdOn || isCtrlOn || isOptionOn;

	toggleLed(isRedLedOn, LedColorRed);
	toggleLed(isGreenLedOn, LedColorGreen);
	toggleLed(isBlueLedOn, LedColorBlue);

	if (!leading)
		return;

	bindFirstSequence(KC_ESC, cancelLeading())

	bindSequenceTwo(KC_H, KC_LEAD, repeatLastCommand())
	bindSequence(KC_LEAD, tap(KC_DOT))
	bindSequence(KC_P, tap(MEH(KC_F3)))
	bindSequence(KC_U, tap(KC_F13))
	bindSequence(KC_O, tap(G(A(KC_SPC))))
	bindSequenceOneTwo(KC_SPC, tap(KC_DOT), tap(KC_SPC))
	bindSequenceOneTwo(KC_ENT, tap(KC_DOT), tap(KC_ENT))
	bindSequenceOneTwo(KC_SLSH, SEND_STRING("... "), cancelLeading())

	// Shortcuts
	bindSequenceTwo(KC_T, KC_COMM, tap(HYPR(KC_F2)))
	bindSequenceTwo(KC_T, KC_P, tap(MEH(KC_F12)))
	bindSequenceTwo(KC_T, KC_O, tap(HYPR(KC_F4)))
	bindSequenceTwo(KC_T, KC_I, tap(HYPR(KC_F3)))
	bindSequenceTwo(KC_T, KC_X, tap(LCAG(KC_F2)))
	bindSequenceTwo(KC_T, KC_F, tap(HYPR(KC_F1)))
	bindSequenceTwo(KC_T, KC_L, tap(MEH(KC_F4)))
	bindSequenceTwo(KC_T, KC_D, tap(LCAG(KC_F11)))
	bindSequenceTwo(KC_T, KC_H, tap(MEH(KC_F1)))
	bindSequenceTwo(KC_T, KC_T, tap(G(KC_TAB)))
	bindSequenceTwo(KC_T, KC_S, tap(G(KC_SPC)))
	bindSequenceTwo(KC_T, KC_M, tap(LCAG(KC_F1)))
	bindSequenceTwo(KC_T, KC_V, tap(MEH(KC_F2)))

	// Symbols
	bindSequenceTwo(KC_H, KC_QUOTE, tap(KC_DOUBLE_QUOTE))
	bindSequenceTwo(KC_H, KC_COMM, tap(KC_LT))
	bindSequenceTwo(KC_H, KC_P, tap(KC_LPRN))
	bindSequenceTwo(KC_H, KC_Y, tap(KC_RPRN))
	bindSequenceTwo(KC_H, KC_A, tap(KC_ASTR))
	bindSequenceTwo(KC_H, KC_O, tap(KC_0))
	bindSequenceTwo(KC_H, KC_E, tap(KC_EQL))
	bindSequenceTwo(KC_H, KC_U, tap(KC_PLUS))
	bindSequenceTwo(KC_H, KC_I, tap(KC_1))
	bindSequenceTwo(KC_H, KC_COLON, tap(KC_SCOLON))
	bindSequenceTwo(KC_H, KC_Q, tap(KC_QUES))
	bindSequenceTwo(KC_H, KC_J, tap(KC_DOWN))
	bindSequenceTwo(KC_H, KC_K, tap(KC_UP))
	bindSequenceTwo(KC_H, KC_F, tap(KC_CIRC))
	bindSequenceTwo(KC_H, KC_G, tap(KC_AT))
	bindSequenceTwo(KC_H, KC_C, tap(KC_LEFT_CURLY_BRACE))
	bindSequenceTwo(KC_H, KC_R, tap(KC_PERC))
	bindSequenceTwo(KC_H, KC_L, tap(KC_RIGHT_CURLY_BRACE))
	bindSequenceTwo(KC_H, KC_D, tap(KC_DLR))
	bindSequenceTwo(KC_H, KC_H, tap(KC_HASH))
	bindSequenceTwo(KC_H, KC_T, tap(KC_TILDE))
	bindSequenceTwo(KC_H, KC_S, tap(KC_BSLS))
	bindSequenceTwo(KC_H, KC_B, tap(KC_LBRACKET))
	bindSequenceTwo(KC_H, KC_M, tap(KC_AMPR))
	bindSequenceTwo(KC_H, KC_V, tap(KC_PIPE))
	bindSequenceTwo(KC_H, KC_Z, tap(KC_RBRACKET))

	// Cmd
#define cmdBind(key) bindSequenceTwo(KC_C, key, tap(G(key)))
	cmdBind(KC_C)
	cmdBind(KC_V)
	cmdBind(KC_Q)
	cmdBind(KC_W)
	cmdBind(KC_Z)
	cmdBind(KC_F)
	bindSequenceTwo(KC_C, KC_T, tap(G(KC_GRAVE)))
	bindSequenceTwoTwo(KC_C, KC_P, tap(G(KC_A)), tap(G(KC_V)))
	bindSequenceTwoTwo(KC_C, KC_Y, tap(G(KC_A)), tap(G(KC_C)))
	bindSequenceTwo(KC_C, KC_J, tap(G(KC_DOWN)))
	bindSequenceTwo(KC_C, KC_K, tap(G(KC_UP)))
	bindSequenceTwo(KC_C, KC_H, tap(G(KC_LEFT)))
	bindSequenceTwo(KC_C, KC_S, tap(G(KC_RGHT)))
	bindSequenceTwo(KC_G, KC_Z, tap(G(KC_LEFT)))
	bindSequenceTwo(KC_G, KC_A, tap(G(KC_RGHT)))

	// Cmd + Shift
#define cmdShiftBind(key) bindSequenceThree(KC_C, KC_S, key, tap(G(S(key))))
	cmdShiftBind(KC_F)
	bindSequenceThree(KC_C, KC_S, KC_J, tap(C(KC_DOWN)))
	bindSequenceThree(KC_C, KC_S, KC_K, tap(C(KC_UP)))
	bindSequenceThree(KC_C, KC_S, KC_H, tap(C(KC_LEFT)))
	bindSequenceThree(KC_C, KC_S, KC_S, tap(C(KC_RGHT)))

	// ctRl - combos: rt-tab rj/rk/rh/rs-arrows
#define ctrlBind(key) bindSequenceTwo(KC_R, key, tap(C(key)))
	ctrlBind(KC_A)
	ctrlBind(KC_X)
	ctrlBind(KC_I)
	ctrlBind(KC_V)
	ctrlBind(KC_R)
	bindSequenceTwo(KC_R, KC_T, tap(C(KC_TAB)))
	bindSequenceTwo(KC_R, KC_J, tap(C(KC_DOWN)))
	bindSequenceTwo(KC_R, KC_K, tap(C(KC_UP)))
	bindSequenceTwo(KC_R, KC_H, tap(C(KC_LEFT)))
	bindSequenceTwo(KC_R, KC_S, tap(C(KC_RGHT)))

	// Media: mp-play mn-next mr-previous mj-volDown mk-volUp mm-mute
	bindSequenceTwo(KC_M, KC_P, tap(KC_MPLY))
	bindSequenceTwo(KC_M, KC_N, tap(KC_MNXT))
	bindSequenceTwo(KC_M, KC_R, tap(KC_MPRV))
	bindSequenceTwo(KC_M, KC_J, tap(KC_VOLD))
	bindSequenceTwo(KC_M, KC_K, tap(KC_VOLU))
	bindSequenceTwo(KC_M, KC_M, tap(KC_MUTE))

	// w: ⌥ →	 b: ⌥ ←	 ga: ⌘ →	 gz: ⌘ ←
	bindSequence(KC_W, tap(A(KC_RGHT)))
	bindSequence(KC_B, tap(A(KC_LEFT)))

	// TODO: Copy content before deleting
	/* Deletion */
	// dw : ⌥ ⌦		 db : ⌥ ⌫ 		dd : ⌘ → then ⌘ ⌫
	bindSequenceTwo(KC_D, KC_W, tap(A(KC_DEL)))
	bindSequenceTwo(KC_D, KC_B, tap(A(KC_BSPC)))
	bindSequenceTwoTwo(KC_D, KC_D, tap(G(KC_RGHT)), tap(G(KC_BSPC)))

	/* CamelCase navigation */
	// ,w: ⌃ →		,b: ⌃ ←	,vw: ⌃ ⇧ →		,vb: ⌃ ⇧ ←		,db: ⌃ ⌫ 	,dw: ⌃ ⌦
	/* bindSequenceTwo(KC_COMM, KC_W, ctrl(KC_RGHT); } */
	/* bindSequenceTwo(KC_COMM, KC_B, ctrl(KC_LEFT); } */ 
	/* bindSequenceTwo(KC_COMM, KC_V) && leader_sequence[2] == (KC_W)) { ctrlShift(KC_RGHT); } */
	/* bindSequenceTwo(KC_COMM, KC_V) && leader_sequence[2] == (KC_B)) { ctrlShift(KC_LEFT); } */
	/* bindSequenceTwo(KC_COMM, KC_D) && leader_sequence[2] == (KC_B)) { ctrl(KC_BSPC); } */
	/* bindSequenceTwo(KC_COMM, KC_D) && leader_sequence[2] == (KC_W)) { ctrl(KC_DEL); } } */

	// Tabs / Extra
	// gt: ⌘ ⇧ →	 ge: ⌘ ⇧ ←	 gs: ⌘ ⌃ →	 gh: ⌘ ⌃ ←
	/* bindSequenceTwo(KC_G, KC_T, tap(SGUI(KC_RGHT))) */
	/* bindSequenceTwo(KC_G, KC_E, tap(SGUI(KC_LEFT))) */
	/* bindSequenceTwo(KC_G, KC_S, tap(G(C(KC_RGHT)))) */
	/* bindSequenceTwo(KC_G, KC_H, tap(G(C(KC_LEFT)))) */

	// Window / Split / Panel
	// ⏎ w : ⌘ ]
	/* bindSequenceTwo(KC_ENT, KC_W, tap(G(KC_RBRC))) */

	// Arrows
	/* bindSequence(KC_J, tap(KC_DOWN)) */
	/* bindSequence(KC_K, tap(KC_UP)) */
	/* bindSequence(KC_H, tap(KC_LEFT)) */
	/* bindSequence(KC_S, tap(KC_RGHT)) */

#if defined(UNICODE_ENABLE)
	// Unicode, Accented characters
	bindSequenceTwo(KC_QUOTE, KC_C, tapUnicode(0x00E7))
	bindSequenceTwo(KC_QUOTE, KC_A, tapUnicode(0x00E1))
	bindSequenceTwo(KC_QUOTE, KC_E, tapUnicode(0x00E9))
	bindSequenceTwo(KC_QUOTE, KC_I, tapUnicode(0x00ED))
	bindSequenceTwo(KC_QUOTE, KC_O, tapUnicode(0x00F3))
	bindSequenceTwo(KC_QUOTE, KC_U, tapUnicode(0x00FA))
	bindSequenceTwo(KC_GRAVE, KC_A, tapUnicode(0x00E0))
	bindSequenceTwo(KC_TILDE, KC_A, tapUnicode(0x00E3))
	bindSequenceTwo(KC_TILDE, KC_O, tapUnicode(0x00F5))
	bindSequenceTwo(KC_TILDE, KC_N, tapUnicode(0x00F1))
	bindSequenceTwo(KC_F, KC_A, tapUnicode(0x00E2))
	bindSequenceTwo(KC_F, KC_E, tapUnicode(0x00EA))
	bindSequenceTwo(KC_F, KC_O, tapUnicode(0x00F4))
	bindSequenceTwo(KC_F, KC_U, tapUnicode(0x00FC))
#endif

	if (timer_elapsed(leader_time) > LEADER_TIMEOUT)
		leading = false;

	if (leading == false)
		leader_end();
};


/* *
 * X - A dvorak based, vim inspired keymap for ergodox keyboards
 * http://www.keyboard-layout-editor.com/#/gists/67569b26aa9c30d3e6fde64dd48e9696
 */
#include QMK_KEYBOARD_H
#include "vim.h"
#include "ergodox_leds.h"

#define curLayer (biton32(layer_state))

enum Layer
{
	Base = 0,
	SymbolsL,
	SymbolsR,
	Numpad,
	Arrows
};

enum TapDance
{
	Colon = 0,
	Bracket,
	Paren,
	Brace,
	Tilde
};

#define SHUTDOWN LCAG(KC_EJCT)
#define LOCKSCR RCTL(RSFT(KC_PWR))
#define SYM_TAB LT(SymbolsR, KC_TAB)
#define SYM_ENT LT(SymbolsL, KC_ENT)
#define NUM_F13 LT(Numpad, KC_F13)

qk_tap_dance_action_t tap_dance_actions[] =
{
	[Colon] = ACTION_TAP_DANCE_DOUBLE(KC_COLON, KC_SCOLON),
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
	LCTL_T(KC_GRV),	KC_QUOT,    KC_COMM,	KC_DOT,		KC_P,   	KC_Y,   LCAG(KC_F13),
	LGUI_T(KC_ESC),	KC_A,       KC_O,		KC_E,		KC_U,   	KC_I,
	OSM(MOD_LSFT),	TD(Colon),	KC_Q,   	KC_J,		KC_K,   	KC_X,   HYPR(KC_F13),
	KC_LALT,		KC_HYPR,    KC_SUPR,	TT(Arrows),	SYM_TAB,

				KC_LEFT,	KC_RGHT,
							KC_F16,
	KC_SPC,		NUM_F13,	MEH(KC_SPC),

	// right hand
	KC_F12,			KC_F6, 		KC_F7, 		KC_F8,   	KC_F9,   	KC_F10,   	KC_CAPS,
	_______,		KC_F,	 	KC_G, 		KC_C,   	KC_R,   	KC_L,		RCTL_T(KC_SLSH),
					KC_D,   	KC_H, 		KC_T,  		KC_N,   	KC_S,		RGUI_T(KC_MINS),
	_______,		KC_B,   	KC_M, 		KC_W,   	KC_V,   	KC_Z,		OSM(MOD_RSFT),
								SYM_ENT,	_______,	KC_SUPR,  	KC_HYPR,	KC_RALT,

	KC_MPLY,		KC_MNXT,
	KC_F16,
	RCTL(KC_F2),	KC_LEAD,	KC_BSPC
),

[SymbolsL] = LAYOUT_ergodox
(
	// left hand
	SHUTDOWN,		KC_F1,		KC_F2,			KC_F3,		KC_F4,		KC_F5,		LGUI(KC_F11),
	KC_TILD,		KC_EXLM,	KC_AT,			KC_HASH,	KC_DLR,		KC_PERC,	_______,
	_______,		KC_EQL,		TD(Bracket),	TD(Paren),	TD(Brace),	KC_PLUS,
	_______,		KC_SCLN,	_______,		_______,	_______,	KC_BSLS,	_______,
	_______,		_______,	_______,		_______,	_______,

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
)
};

// Called by QMK during key processing before the actual key event is handled.
bool process_record_user (uint16_t keycode, keyrecord_t *record) 
{
	if (!record->event.pressed) { return true; }

	if (keycode == KC_ESC
		&& get_oneshot_mods()
		&& !has_oneshot_mods_timed_out())
	{
		clear_oneshot_mods();
		return false;
	}

	return true;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) 
{
	// One Shot Modifiers LEDs
	bool isShiftOn = keyboard_report->mods & MOD_BIT(KC_LSFT)
			|| ((get_oneshot_mods() & MOD_BIT(KC_LSFT)) && !has_oneshot_mods_timed_out()) 
			|| keyboard_report->mods & MOD_BIT(KC_RSFT)
			|| ((get_oneshot_mods() & MOD_BIT(KC_RSFT)) && !has_oneshot_mods_timed_out());

	bool isRedLedOn = curLayer == Arrows;

	bool isGreenLedOn = curLayer == SymbolsL
		|| curLayer == SymbolsR;

	bool isBlueLedOn = leading
		|| isShiftOn
		|| curLayer == Numpad;

	toggleLed(isRedLedOn, LedColorRed);
	toggleLed(isGreenLedOn, LedColorGreen);
	toggleLed(isBlueLedOn, LedColorBlue);

	// https://github.com/qmk/qmk_firmware/issues/370
	// Custom leading trying to mimic some Vim and Vimperator commands.
	// It activates before the timeout if sequence is complete but it has to be unambiguous.
	if (!leading)
		return;

	bindFirstSequence(KC_DOT, repeat())

	// w: ⌥ →	 b: ⌥ ←	 ga: ⌘ →	 gz: ⌘ ←
	bindSequence(KC_W, tap(A(KC_RGHT)))
	bindSequence(KC_B, tap(A(KC_LEFT)))
	bindSequenceTwo(KC_G, KC_A, tap(G(KC_RGHT)))
	bindSequenceTwo(KC_G, KC_Z, tap(G(KC_LEFT)))

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
	bindSequenceTwo(KC_G, KC_T, tap(SGUI(KC_RGHT)))
	bindSequenceTwo(KC_G, KC_E, tap(SGUI(KC_LEFT)))
	bindSequenceTwo(KC_G, KC_S, tap(G(C(KC_RGHT))))
	bindSequenceTwo(KC_G, KC_H, tap(G(C(KC_LEFT))))

	// Window / Split / Panel
	// ⏎ w : ⌘ ]
	bindSequenceTwo(KC_ENT, KC_W, tap(G(KC_RBRC)))

	// Universal shortcuts: p-1password ub-menubar ut-add_todoist up-start_pomodoro */
	bindSequence(KC_P, tap(MEH(KC_F12)))
	bindSequenceTwo(KC_U, KC_B, tap(C(KC_F2)))
	bindSequenceTwo(KC_U, KC_T, tap(LCAG(KC_F11)))
	bindSequenceTwo(KC_U, KC_P, tap(LCAG(KC_F10)))

	// Apps: f-firefox v-vimr <spc>-iterm um-messages ux-xcode ui-itunes ud-todoist uo-moom us-spotlight ur-transmission uc-chrome uw-whatsapp
	bindSequence(KC_F, tap(MEH(KC_F1)))
	bindSequence(KC_V, tap(MEH(KC_F2)))
	bindSequence(KC_SPC, tap(MEH(KC_F3)))
	bindSequenceTwo(KC_U, KC_S, tap(G(KC_SPC)))
	bindSequenceTwo(KC_U, KC_O, tap(G(A(KC_SPC))))
	bindSequenceTwo(KC_U, KC_M, tap(LCAG(KC_F1)))
	bindSequenceTwo(KC_U, KC_X, tap(LCAG(KC_F2)))
	bindSequenceTwo(KC_U, KC_I, tap(LCAG(KC_F3)))
	bindSequenceTwo(KC_U, KC_D, tap(LCAG(KC_F4)))
	bindSequenceTwo(KC_U, KC_R, tap(LCAG(KC_F5)))
	bindSequenceTwo(KC_U, KC_C, tap(LCAG(KC_F6)))
	bindSequenceTwo(KC_U, KC_W, tap(LCAG(KC_F7)))

	// Arrows
	bindSequence(KC_J, tap(KC_DOWN))
	bindSequence(KC_K, tap(KC_UP))
	bindSequence(KC_H, tap(KC_LEFT))
	bindSequence(KC_S, tap(KC_RGHT))

	// Emblems (symbols and punctuation)
	// . : " ( / , { * = + $ < ! ? # ~ & > [ - ' ` % ; ) } ] _ @ \ ^ 
	//       p s   c a e u d   x q h t m   b       r           g k f
	bindSequenceTwo(KC_E, KC_P, tap(KC_LEFT_PAREN))
	bindSequenceTwo(KC_E, KC_S, tap(KC_SLSH))
	bindSequenceTwo(KC_E, KC_C, tap(KC_LEFT_CURLY_BRACE))
	bindSequenceTwo(KC_E, KC_A, tap(KC_ASTR))
	bindSequenceTwo(KC_E, KC_E, tap(KC_EQL))
	bindSequenceTwo(KC_E, KC_U, tap(KC_PLUS))
	bindSequenceTwo(KC_E, KC_D, tap(KC_DLR))
	bindSequenceTwo(KC_E, KC_X, tap(KC_EXLM))
	bindSequenceTwo(KC_E, KC_Q, tap(KC_QUES))
	bindSequenceTwo(KC_E, KC_H, tap(KC_HASH))
	bindSequenceTwo(KC_E, KC_T, tap(KC_TILDE))
	bindSequenceTwo(KC_E, KC_M, tap(KC_AMPR))
	bindSequenceTwo(KC_E, KC_B, tap(KC_LBRACKET))
	bindSequenceTwo(KC_E, KC_R, tap(KC_PERC))
	bindSequenceTwo(KC_E, KC_G, tap(KC_AT))
	bindSequenceTwo(KC_E, KC_K, tap(KC_BSLS))
	bindSequenceTwo(KC_E, KC_F, tap(KC_CIRC))

	// Alfred: af-alfred-files am-alfred-menu ai-alfred-itunes
	bindSequenceTwo(KC_A, KC_F, tap(HYPR(KC_F1)))
	bindSequenceTwo(KC_A, KC_M, tap(HYPR(KC_F2)))
	bindSequenceTwo(KC_A, KC_I, tap(HYPR(KC_F3)))

	// Cmd combos: t-tab ct-` cc-c cv-v cq-q ca-a cz-z cx-x cf-f cj/ck/ch/cs-arrows cy-ca+cc cp-ca+cv
	bindSequence(KC_T, tap(G(KC_TAB)))
	bindSequenceTwo(KC_C, KC_T, tap(G(KC_GRAVE)))
	bindSequenceTwo(KC_C, KC_C, tap(G(KC_C)))
	bindSequenceTwo(KC_C, KC_V, tap(G(KC_V)))
	bindSequenceTwo(KC_C, KC_Q, tap(G(KC_Q)))
	bindSequenceTwo(KC_C, KC_A, tap(G(KC_A)))
	bindSequenceTwo(KC_C, KC_Z, tap(G(KC_Z)))
	bindSequenceTwo(KC_C, KC_X, tap(G(KC_X)))
	bindSequenceTwo(KC_C, KC_F, tap(G(KC_F)))
	bindSequenceTwo(KC_C, KC_J, tap(G(KC_DOWN)))
	bindSequenceTwo(KC_C, KC_K, tap(G(KC_UP)))
	bindSequenceTwo(KC_C, KC_H, tap(G(KC_LEFT)))
	bindSequenceTwo(KC_C, KC_S, tap(G(KC_RGHT)))
	bindSequenceTwoTwo(KC_C, KC_Y, tap(G(KC_A)), tap(G(KC_C)))
	bindSequenceTwoTwo(KC_C, KC_P, tap(G(KC_A)), tap(G(KC_V)))

	// cTrl combos: r-tab tj/tk/th/ts-arrows
	bindSequence(KC_R, tap(C(KC_TAB)))
	bindSequenceTwo(KC_T, KC_J, tap(C(KC_DOWN)))
	bindSequenceTwo(KC_T, KC_K, tap(C(KC_UP)))
	bindSequenceTwo(KC_T, KC_H, tap(C(KC_LEFT)))
	bindSequenceTwo(KC_T, KC_S, tap(C(KC_RGHT)))

	// Media: mp-play mn-next mr-previous mj-volDown mk-volUp mm-mute
	bindSequenceTwo(KC_M, KC_P, tap(KC_MPLY))
	bindSequenceTwo(KC_M, KC_N, tap(KC_MNXT))
	bindSequenceTwo(KC_M, KC_R, tap(KC_MPRV))
	bindSequenceTwo(KC_M, KC_J, tap(KC_VOLD))
	bindSequenceTwo(KC_M, KC_K, tap(KC_VOLU))
	bindSequenceTwo(KC_M, KC_M, tap(KC_MUTE))

	if (timer_elapsed(leader_time) > LEADER_TIMEOUT)
		leading = false;

	if (leading == false)
		leader_end();
};


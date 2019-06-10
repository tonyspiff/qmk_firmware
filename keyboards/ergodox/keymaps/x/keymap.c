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
	Inter,
	Symbols,
	Shortcuts,
	Media,
	Cmd,
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
	KC_DOTSPC = SAFE_RANGE,
	KC_ELIP,
	KC_DOTENT,
	KC_COPYALL,
	KC_PASTEALL
};

#define SHUTDOWN LCAG(KC_EJCT)
#define LOCKSCR RCTL(RSFT(KC_PWR))
#define SYM_TAB LT(Arrows, KC_TAB)
#define SYM_ENT LT(Symbols, KC_ENT)
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
	LOCKSCR,		KC_F1,      KC_F2,   	NUM_F13,	KC_F4,   	KC_F5,	KC_F11,
	LCTL_T(KC_GRV),	TD(Quote),  KC_COMM,	OSL(Inter),	KC_P,   	KC_Y,   LCAG(KC_F13),
	LGUI_T(KC_ESC),	KC_A,       KC_O,		KC_E,		KC_U,   	KC_I,
	OSM(MOD_LSFT),	TD(Colon),	KC_Q,   	KC_J,		KC_K,   	KC_X,   HYPR(KC_F13),
	KC_LALT,		KC_HYPR,    KC_SUPR,	KC_LEAD,	SYM_TAB,

				KC_LEFT,	KC_RGHT,
							KC_F16,
	LT(Numpad, KC_SPC),	NUM_F13,	MEH(KC_SPC),

	// right hand
	KC_F12,			KC_F6, 		KC_F7, 		KC_LEAD,   	KC_F9,   	KC_F10,   	KC_CAPS,
	G(KC_Y),		KC_F,	 	KC_G, 		KC_C,		KC_R,   	KC_L,		RCTL_T(KC_SLSH),
					KC_D,   	KC_H, 		KC_T,  		KC_N,   	KC_S,		RGUI_T(KC_MINS),
	G(KC_TAB),		KC_B,   	KC_M, 		KC_W,   	KC_V,   	KC_Z,		OSM(MOD_RSFT),
								SYM_ENT,	KC_LEAD,	KC_SUPR,  	KC_HYPR,	KC_RALT,

	KC_MPLY,		KC_MNXT,
	KC_F16,
	RCTL(KC_F2),	_______,	KC_BSPC
),

[Inter] = LAYOUT_ergodox
(
	// Left Hand
	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,
	X_____X,	X_____X,	X_____X,	KC_DOT, 	MEH(KC_F3),	X_____X,	X_____X,
	TO(Base),	X_____X,	X_____X,	X_____X,	KC_F13,		X_____X,
	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,
	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,

				X_____X,	X_____X,
							X_____X,
	KC_DOTSPC,	X_____X,	X_____X,

	// Right Hand
	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,	SHUTDOWN,
	X_____X,	X_____X,	X_____X,	OSL(Cmd),	X_____X,	X_____X,	X_____X,
				X_____X,OSL(Symbols),OSL(Shortcuts),X_____X,	X_____X,	X_____X,
	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,
							X_____X,	X_____X,	X_____X,	X_____X,	X_____X,

	X_____X,	X_____X,
	X_____X,
	X_____X,	MEH(KC_SPC),	KC_LEAD
),

[Symbols] = LAYOUT_ergodox
(
	// Left Hand
	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,
	X_____X,	KC_DQUO,	KC_LT,		KC_ELIP,	KC_LPRN,	KC_RPRN,	X_____X,
	_______,	KC_ASTR,	KC_0,		KC_EQL,		KC_PLUS,	KC_1,
	X_____X,	KC_SCLN,	KC_QUES,	KC_DOWN,	KC_UP,		KC_EXLM,	X_____X,
	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,

				X_____X,	X_____X,
							X_____X,
	KC_DOTSPC,	X_____X,	X_____X,

	// Right Hand
	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,	RESET,
	X_____X,	KC_CIRC,	KC_AT,		KC_LCBR,	KC_PERC,	KC_RCBR,	X_____X,
				KC_DLR,		KC_HASH,	KC_TILD,	X_____X,	KC_BSLS,	X_____X,
	X_____X,	KC_LBRC,	KC_AMPR,	X_____X,	KC_PIPE,	KC_RBRC,	X_____X,
							KC_DOTENT,	X_____X,	X_____X,	X_____X,	X_____X,

	X_____X,	X_____X,
	X_____X,
	X_____X,	X_____X,	X_____X
),

[Shortcuts] = LAYOUT_ergodox
(
	// Left Hand
	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,
	X_____X,	X_____X,	HYPR(KC_F2),MEH(KC_F3),	MEH(KC_F12),X_____X,	X_____X,
	_______,	KC_F13,		HYPR(KC_F4),KC_F13,		X_____X,	HYPR(KC_F3),
	X_____X,	HYPR(KC_F2),X_____X,	X_____X,	X_____X,	LCAG(KC_F2),X_____X,
	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,

				X_____X,	X_____X,
							X_____X,
	KC_DOTSPC,	X_____X,	X_____X,

	// Right Hand
	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,	X_____X,	MEH(KC_F11),
	X_____X,	HYPR(KC_F1),X_____X,	X_____X,	X_____X,	MEH(KC_F4),	X_____X,
				LCAG(KC_F11),MEH(KC_F1),G(KC_TAB), 	X_____X,  	G(KC_SPC), 	X_____X,
	X_____X,	X_____X,	LCAG(KC_F1),X_____X,	MEH(KC_F2),	X_____X,	X_____X,
							X_____X,	X_____X,	X_____X,	X_____X,	X_____X,

	X_____X,	X_____X,
	X_____X,
	X_____X,	MEH(KC_SPC),	X_____X
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
	_______,	MEH(KC_SPC),	_______
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

[Cmd] = LAYOUT_ergodox
(
	// Left Hand
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	KC_PASTEALL,KC_COPYALL,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,

				_______,	_______,
							_______,
	_______,	_______,	_______,

	// Right Hand
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	G(KC_GRV),	_______,	_______,	_______,
				_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,
							_______,	_______,	_______,	_______,	_______,

	_______,	_______,
	_______,
	_______,	_______,	_______
)

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

		case KC_DOTSPC:
			tap(KC_DOT);
			tap(KC_SPC);
			break;

		case KC_DOTENT:
			tap(KC_DOT);
			tap(KC_ENT);
			break;

		case KC_ELIP:
			SEND_STRING("... ");
			break;

		case KC_COPYALL:
			tap(G(KC_A));
			tap(G(KC_C));
			break;

		case KC_PASTEALL:
			tap(G(KC_A));
			tap(G(KC_V));
			break;
	}

	return true;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) 
{
	bool isRedLedOn = curLayer == Numpad
		|| curLayer == Arrows;

	bool isGreenLedOn = curLayer == Inter
		|| curLayer == Shortcuts
		|| curLayer == Symbols;

	bool isBlueLedOn = leading
		|| curLayer == Cmd
		|| isShiftOn;

	toggleLed(isRedLedOn, LedColorRed);
	toggleLed(isGreenLedOn, LedColorGreen);
	toggleLed(isBlueLedOn, LedColorBlue);

	// https://github.com/qmk/qmk_firmware/issues/370
	// Custom leading trying to mimic some Vim and Vimperator commands.
	// It activates before the timeout if sequence is complete but it has to be unambiguous.
	if (!leading)
		return;

	bindFirstSequence(KC_ESC, cancelLeading())

	// Used: . <ent> <spc> a b c d e f g h 	 j k   m   p   r s t u v w x   
	bindSequence(KC_DOT, repeatLastCommand())

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

	// Apps: f-firefox v-vimr <spc>-iterm um-messages x-xcode ui-itunes ud-todoist uo-moom us-spotlight ur-transmission uc-chrome uw-whatsapp
	bindSequence(KC_F, tap(MEH(KC_F1)))
	bindSequence(KC_V, tap(MEH(KC_F2)))
	bindSequence(KC_SPC, tap(MEH(KC_F3)))
	bindSequenceTwo(KC_U, KC_S, tap(G(KC_SPC)))
	bindSequenceTwo(KC_U, KC_O, tap(G(A(KC_SPC))))
	bindSequenceTwo(KC_U, KC_M, tap(LCAG(KC_F1)))
	bindSequence(KC_X, tap(LCAG(KC_F2)))
	bindSequenceTwo(KC_U, KC_I, tap(LCAG(KC_F3)))
	bindSequenceTwo(KC_U, KC_D, tap(LCAG(KC_F4)))
	bindSequenceTwo(KC_U, KC_R, tap(LCAG(KC_F5)))
	bindSequenceTwo(KC_U, KC_C, tap(LCAG(KC_F6)))
	bindSequenceTwo(KC_U, KC_W, tap(LCAG(KC_F7)))

	// Arrows
	/* bindSequence(KC_J, tap(KC_DOWN)) */
	/* bindSequence(KC_K, tap(KC_UP)) */
	/* bindSequence(KC_H, tap(KC_LEFT)) */
	/* bindSequence(KC_S, tap(KC_RGHT)) */

	// Emblems (symbols and punctuation)
	// . : " ( / , { * = + $ < ! ? # ~ & > [ - ' ` % ; ) } ] _ @ \ ^ 
	//       p s   c a e u d   x q h t m   b       r           g k f
	/* bindSequenceTwo(KC_E, KC_P, tap(KC_LEFT_PAREN)) */
	/* bindSequenceTwo(KC_E, KC_S, tap(KC_SLSH)) */
	/* bindSequenceTwo(KC_E, KC_C, tap(KC_LEFT_CURLY_BRACE)) */
	/* bindSequenceTwo(KC_E, KC_A, tap(KC_ASTR)) */
	/* bindSequenceTwo(KC_E, KC_E, tap(KC_EQL)) */
	/* bindSequenceTwo(KC_E, KC_U, tap(KC_PLUS)) */
	/* bindSequenceTwo(KC_E, KC_D, tap(KC_DLR)) */
	/* bindSequenceTwo(KC_E, KC_X, tap(KC_EXLM)) */
	/* bindSequenceTwo(KC_E, KC_Q, tap(KC_QUES)) */
	/* bindSequenceTwo(KC_E, KC_H, tap(KC_HASH)) */
	/* bindSequenceTwo(KC_E, KC_T, tap(KC_TILDE)) */
	/* bindSequenceTwo(KC_E, KC_M, tap(KC_AMPR)) */
	/* bindSequenceTwo(KC_E, KC_B, tap(KC_LBRACKET)) */
	/* bindSequenceTwo(KC_E, KC_R, tap(KC_PERC)) */
	/* bindSequenceTwo(KC_E, KC_G, tap(KC_AT)) */
	/* bindSequenceTwo(KC_E, KC_K, tap(KC_BSLS)) */
	/* bindSequenceTwo(KC_E, KC_F, tap(KC_CIRC)) */

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

	// ctRl combos: r-tab tj/tk/th/ts-arrows
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

	if (timer_elapsed(leader_time) > LEADER_TIMEOUT)
		leading = false;

	if (leading == false)
		leader_end();
};


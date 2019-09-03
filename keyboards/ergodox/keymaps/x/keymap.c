/* *
 * X - A dvorak based, vim inspired keymap for ergodox keyboards
 * http://www.keyboard-layout-editor.com/#/gists/67569b26aa9c30d3e6fde64dd48e9696
 */
#include QMK_KEYBOARD_H
#include "vim.h"
#include "ergodox_leds.h"

#define curLayer (biton32(layer_state))
#define X_____X KC_NO
#define KC_CMD KC_LCMD
#define CMD(kc) LCMD(kc)
#define KC_OPT KC_LALT
#define OPT(kc) LALT(kc)
#define KC_CTRL KC_LCTRL
#define CTRL(kc) LCTL(kc)

enum Layer
{
	Base = 0,
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

/* enum Keycode */
/* { */
/* 	KC_UNUSED = SAFE_RANGE */
/* }; */

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
	LT(Numpad, KC_SPC),	NUM_F13,	MEH(KC_SPC),

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
	TO(Base),	_______,	_______,	_______,	_______,	_______,
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

static bool isCmdTabOn = false;

// Called by QMK during key processing before the actual key event is handled.
bool process_record_user (uint16_t keycode, keyrecord_t *record) 
{
	if (!record->event.pressed) { return true; }

	switch (keycode)
	{
		case KC_ESC:
			if (isCmdTabOn)
			{
				release(KC_CMD);
			}

			if (get_oneshot_mods()
				&& !has_oneshot_mods_timed_out())
			{
				clear_oneshot_mods();
				return false;
			}
			break;

		case KC_ENT:
			if (isCmdTabOn)
			{
				release(KC_CMD);
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

	if (leader_sequence[0] == KC_ESC) { leading = false; }

	else if (leader_sequence[0] == KC_LEAD) { tap(KC_DOT); }
	else if (leader_sequence[0] == KC_P) { tap(MEH(KC_F3)); }
	else if (leader_sequence[0] == KC_N) { layer_on(Numpad); leading = false; }
	else if (leader_sequence[0] == KC_W) { layer_on(Arrows); leading = false; }
	else if (leader_sequence[0] == KC_U) { tap(KC_F13); }
	else if (leader_sequence[0] == KC_SPC) { tap(KC_DOT); tap(KC_SPC); }
	else if (leader_sequence[0] == KC_ENT) { tap(KC_DOT); tap(KC_ENT); }

	// App switching
	else if (leader_sequence[0] == KC_T) {
		if (leader_sequence[1] == KC_T) { tap(CMD(KC_TAB)); } // ⌘ ↹
		else if (leader_sequence[1] == KC_H) { tap(MEH(KC_F1)); } // Firefox
		else if (leader_sequence[1] == KC_V) { tap(MEH(KC_F2)); } // VimR
		else if (leader_sequence[1] == KC_X) { tap(LCAG(KC_F2)); } // Xcode
		else if (leader_sequence[1] == KC_P) { tap(MEH(KC_F12)); } // 1Password
		else if (leader_sequence[1] == KC_M) { tap(LCAG(KC_F1)); } // Messaging App
		else if (leader_sequence[1] == KC_G) { tap(CMD(KC_GRAVE)); } // ⌘ `
		else if (leader_sequence[1] == KC_C) { press(KC_CMD); tap(KC_TAB); isCmdTabOn = true; } // Sticky ⌘ ↹
		else if (leader_sequence[1] == KC_R) { tap(LCAG(KC_F5)); } // tRansmission
		else if (leader_sequence[1] == KC_D) { tap(LCAG(KC_F4)); } // toDoist
		else if (leader_sequence[1] == KC_I) { tap(HYPR(KC_F3)); } // iTunes Mini Player - Alfred
		else if (leader_sequence[1] == KC_S) { tap(CMD(KC_SPC)); } // Spotlight
		else if (leader_sequence[1] == KC_O) { tap(CMD(OPT(KC_SPC))); } // mOom
		/* else if (leader_sequence[1] == KC_F) { tap(HYPR(KC_F1)); } */
		/* else if (leader_sequence[1] == KC_L) { tap(MEH(KC_F4)); } */
	}

	// Symbols
	else if (leader_sequence[0] == KC_H) {
		if (leader_sequence[1] == KC_LEAD) { repeatTap(); }
		else if (leader_sequence[1] == KC_QUOTE) { tap(KC_DOUBLE_QUOTE); }
		else if (leader_sequence[1] == KC_COMM) { tap(KC_LT); }
		else if (leader_sequence[1] == KC_P) { tap(KC_LPRN); tap(KC_RPRN); tap(KC_LEFT); } // pair of Parentheses
		else if (leader_sequence[1] == KC_Y) { tap(KC_RPRN); }
		else if (leader_sequence[1] == KC_A) { tap(KC_ASTR); } // Asterisk
		else if (leader_sequence[1] == KC_O) { tap(KC_0); }
		else if (leader_sequence[1] == KC_E) { tap(KC_EQL); } // Equal
		else if (leader_sequence[1] == KC_U) { tap(KC_PLUS); } // plUs
		else if (leader_sequence[1] == KC_I) { tap(KC_1); }
		else if (leader_sequence[1] == KC_COLON) { tap(KC_SCOLON); }
		else if (leader_sequence[1] == KC_Q) { tap(KC_QUES); } // Question mark
		else if (leader_sequence[1] == KC_J) { tap(KC_DOWN); }
		else if (leader_sequence[1] == KC_K) { tap(KC_UP); }
		else if (leader_sequence[1] == KC_X) { tap(KC_EXLM); } // eXclamation mark
		else if (leader_sequence[1] == KC_F) { tap(KC_CIRC); } // circumFlex
		else if (leader_sequence[1] == KC_G) { tap(KC_AT); } // at sigGn
		else if (leader_sequence[1] == KC_C) { tap(KC_LEFT_CURLY_BRACE); tap(KC_RIGHT_CURLY_BRACE); tap(KC_LEFT); } // pair of Curly braces
		else if (leader_sequence[1] == KC_R) { tap(KC_PERC); } // peRcent
		else if (leader_sequence[1] == KC_L) { tap(KC_RIGHT_CURLY_BRACE); }
		else if (leader_sequence[1] == KC_D) { tap(KC_DLR); } // Dollar
		else if (leader_sequence[1] == KC_H) { tap(KC_HASH); } // Hash
		else if (leader_sequence[1] == KC_T) { tap(KC_TILDE); } // Tilde
		else if (leader_sequence[1] == KC_S) { tap(KC_BSLS); } // backSlash
		else if (leader_sequence[1] == KC_B) { tap(KC_LBRACKET); tap(KC_RBRACKET); tap(KC_LEFT); } // pair of Brackets
		else if (leader_sequence[1] == KC_M) { tap(KC_AMPR); } // aMpersand
		else if (leader_sequence[1] == KC_V) { tap(KC_PIPE); } // Vertical bar
		else if (leader_sequence[1] == KC_Z) { tap(KC_RBRACKET); }
	}

	// ⌘ - Command
	else if (leader_sequence[0] == KC_C) {
		if (leader_sequence[1]) { tap(CMD(leader_sequence[1])); }
		/* else if (leader_sequence[1] == KC_J) { tap(CMD(KC_DOWN)); } */
		/* else if (leader_sequence[1] == KC_K) { tap(CMD(KC_UP)); } */
		/* else if (leader_sequence[1] == KC_H) { tap(CMD(KC_LEFT)); } */
		/* else if (leader_sequence[1] == KC_S) { tap(CMD(KC_RIGHT)); } */
	}

	// Macros & Misc
	else if (leader_sequence[0] == KC_G) {
		if (leader_sequence[1] == KC_N) { tap(HYPR(KC_F2)); } // meNu
		else if (leader_sequence[1] == KC_B) { tap(CTRL(KC_F2)); } // Bar
		else if (leader_sequence[1] == KC_Z) { tap(CMD(KC_LEFT)); } // ⌘ ←
		else if (leader_sequence[1] == KC_A) { tap(CMD(KC_RIGHT)); } // ⌘ →
		else if (leader_sequence[1] == KC_P) { tap(CMD(KC_A)); tap(CMD(KC_V)); } // Paste all
		else if (leader_sequence[1] == KC_Y) { tap(CMD(KC_A)); tap(CMD(KC_C)); } // Yank all
		else if (leader_sequence[1] == KC_E) { tap(CMD(S(KC_LEFT))); } // ⌘ ⇧ ←
		else if (leader_sequence[1] == KC_T) { tap(CMD(S(KC_RIGHT))); } // ⌘ ⇧ →
		else if (leader_sequence[1] == KC_H) { tap(CMD(CTRL(KC_LEFT))); } // ⌘ ⌃ ←
		else if (leader_sequence[1] == KC_S) { tap(CMD(CTRL(KC_RIGHT))); } // ⌘ ⌃ →
		else if (leader_sequence[1] == KC_D) { tap(LCAG(KC_F11)); } // toDoist quick add
		else if (leader_sequence[1] == KC_M) { tap(HYPR(KC_F4)); } // eMojis
		else if (leader_sequence[1] == KC_LEAD) { SEND_STRING("... "); leading = false; }
	}

	// ⌘ ⇧
	else if (leader_sequence[0] == (KC_L)) {
		if (leader_sequence[1]) { tap(CMD(S(leader_sequence[1]))); }
		/* else if (leader_sequence[1] == KC_J) { tap(CMD(S(KC_DOWN))); } */
		/* else if (leader_sequence[1] == KC_K) { tap(CMD(S(KC_UP))); } */
		/* else if (leader_sequence[1] == KC_H) { tap(CMD(S(KC_LEFT))); } */
		/* else if (leader_sequence[1] == KC_S) { tap(CMD(S(KC_RIGHT))); } */
	}

	// ⌃ - contRol
	else if (leader_sequence[0] == (KC_R)) {
		if (leader_sequence[1]) { tap(C(leader_sequence[1])); }
		/* else if (leader_sequence[1] == KC_J) { tap(C(KC_DOWN)); } */
		/* else if (leader_sequence[1] == KC_K) { tap(C(KC_UP)); } */
		/* else if (leader_sequence[1] == KC_H) { tap(C(KC_LEFT)); } */
		/* else if (leader_sequence[1] == KC_S) { tap(C(KC_RIGHT)); } */
	}

	// ⌥  - Option
	else if (leader_sequence[0] == KC_O) {
		if (leader_sequence[1]) { tap(OPT(leader_sequence[1])); }
	}

	// Media: mp-play mn-next mr-previous mj-volDown mk-volUp mm-mute
	else if (leader_sequence[0] == KC_M) {
		if (leader_sequence[1] == KC_P) { tap(KC_MEDIA_PLAY_PAUSE); }
		else if (leader_sequence[1] == KC_N) { tap(KC_MEDIA_NEXT_TRACK); }
		else if (leader_sequence[1] == KC_R) { tap(KC_MEDIA_PREV_TRACK); }
		else if (leader_sequence[1] == KC_J) { tap(KC_AUDIO_VOL_DOWN); }
		else if (leader_sequence[1] == KC_K) { tap(KC_AUDIO_VOL_UP); }
		else if (leader_sequence[1] == KC_M) { tap(KC_AUDIO_MUTE); }
	}

	// w: ⌥ →	 b: ⌥ ←	 ga: ⌘ →	 gz: ⌘ ←
	/* else if (leader_sequence[1] == KC_W) { tap(OPT(KC_RIGHT))) */
	/* else if (leader_sequence[1] == KC_B) { tap(OPT(KC_LEFT))) */

	// TODO: Copy content before deleting
	/* Deletion */
	// dw : ⌥ ⌦		 db : ⌥ ⌫ 		dd : ⌘ → then ⌘ ⌫
	/* else if (leader_sequence[1] == KC_D, KC_W) { tap(OPT(KC_DEL)); } */
	/* else if (leader_sequence[1] == KC_D, KC_B) { tap(OPT(KC_BSPC)); } */
	/* else if (leader_sequence[1] == KC_D; KC_D) { tap(CMD(KC_RIGHT)), tap(CMD(KC_BSPC)); } */

	/* CamelCase navigation */
	// ,w: ⌃ →		,b: ⌃ ←	,vw: ⌃ ⇧ →		,vb: ⌃ ⇧ ←		,db: ⌃ ⌫ 	,dw: ⌃ ⌦
	/* bindSequenceTwo(KC_COMM, KC_W, ctrl(KC_RIGHT); } */
	/* bindSequenceTwo(KC_COMM, KC_B, ctrl(KC_LEFT); } */ 
	/* bindSequenceTwo(KC_COMM, KC_V) && leader_sequence[2] == (KC_W)) { ctrlShift(KC_RIGHT); } */
	/* bindSequenceTwo(KC_COMM, KC_V) && leader_sequence[2] == (KC_B)) { ctrlShift(KC_LEFT); } */
	/* bindSequenceTwo(KC_COMM, KC_D) && leader_sequence[2] == (KC_B)) { ctrl(KC_BSPC); } */
	/* bindSequenceTwo(KC_COMM, KC_D) && leader_sequence[2] == (KC_W)) { ctrl(KC_DEL); } } */

	// Tabs / Extra
	// gt: ⌘ ⇧ →	 ge: ⌘ ⇧ ←	 gs: ⌘ ⌃ →	 gh: ⌘ ⌃ ←
	/* bindSequenceTwo(KC_G, KC_T) { tap(SGUI(KC_RIGHT))) */
	/* bindSequenceTwo(KC_G, KC_E) { tap(SGUI(KC_LEFT))) */
	/* bindSequenceTwo(KC_G, KC_S) { tap(CMD(C(KC_RIGHT)))) */
	/* bindSequenceTwo(KC_G, KC_H) { tap(CMD(C(KC_LEFT)))) */

	// Window / Split / Panel
	// ⏎ w : ⌘ ]
	/* bindSequenceTwo(KC_ENT, KC_W) { tap(CMD(KC_RBRC))) */

	// Arrows
	/* else if (leader_sequence[1] == KC_J) { tap(KC_DOWN)) */
	/* else if (leader_sequence[1] == KC_K) { tap(KC_UP)) */
	/* else if (leader_sequence[1] == KC_H) { tap(KC_LEFT)) */
	/* else if (leader_sequence[1] == KC_S) { tap(KC_RIGHT)) */

#if defined(UNICODE_ENABLE)
	// Unicode, Accented characters
	else if (leader_sequence[0] == KC_QUOTE) { // ¸ or ´
		if (leader_sequence[1] == KC_C) { tapUnicode(0x00E7); }
		else if (leader_sequence[1] == KC_A) { tapUnicode(0x00E1); }
		else if (leader_sequence[1] == KC_E) { tapUnicode(0x00E9); }
		else if (leader_sequence[1] == KC_I) { tapUnicode(0x00ED); }
		else if (leader_sequence[1] == KC_O) { tapUnicode(0x00F3); }
		else if (leader_sequence[1] == KC_U) { tapUnicode(0x00FA); }
	}
	else if (leader_sequence[0] == KC_GRAVE) { // `
		if (leader_sequence[1] == KC_A) { tapUnicode(0x00E0); }
	}
	else if (leader_sequence[0] == KC_MINS) { // ~
		if (leader_sequence[1] == KC_A) { tapUnicode(0x00E3); }
		else if (leader_sequence[1] == KC_O) { tapUnicode(0x00F5); }
		else if (leader_sequence[1] == KC_N) { tapUnicode(0x00F1); }
	}
	else if (leader_sequence[0] == KC_F) { // ^
		if (leader_sequence[1] == KC_A) { tapUnicode(0x00E2); }
		else if (leader_sequence[1] == KC_E) { tapUnicode(0x00EA); }
		else if (leader_sequence[1] == KC_O) { tapUnicode(0x00F4); }
		else if (leader_sequence[1] == KC_U) { tapUnicode(0x00FC); }
	}
#endif

	if (timer_elapsed(leader_time) > LEADER_TIMEOUT)
		leading = false;

	if (leading == false)
		leader_end();
};


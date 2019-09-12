#include "leading.h"
#include "mods.h"
#include "vim.h"

void endLeading()
{
	leading = false;
	leader_end();
}

uint16_t previousKeycode = 0;

void tapL(uint16_t code)
{
	previousKeycode = code;
	tap(code);
	endLeading();
}

void repeatTapL()
{
	if (previousKeycode == 0)
		return;
	
	tapL(previousKeycode);
}

#if defined(UNICODE_ENABLE)
void tapUnicodeL(uint16_t code)
{
	unicode_input_start();
	register_hex(code);
	unicode_input_finish();
	endLeading();
}
#endif

void process_leading_sequence(void)
{
	if (!leading)
		return;
	
	switch (leader_sequence[0])
	{
		case 0: return;
		case KC_ESC: endLeading(); break;
		case KC_LEAD: tapL(KC_DOT); break;
		case KC_P: tapL(MEH(KC_F3)); break;
		case KC_BSPACE: layer_on(Arrows); endLeading(); break;
		case KC_U: tapL(KC_F13); break;
		case KC_SPC: tapL(KC_DOT); tapL(KC_SPC); break;
		case KC_ENT: tapL(KC_DOT); tapL(KC_ENT); break;
		case KC_V: isVimodeOn = true; endLeading(); break;
			
		// App switching
		case KC_T:
			switch (leader_sequence[1])
			{
				case KC_T: tapL(CMD(KC_TAB)); break; // ⌘ ↹
				case KC_H: tapL(MEH(KC_F1)); break; // Firefox
				case KC_V: tapL(MEH(KC_F2)); break; // VimR
				case KC_X: tapL(LCAG(KC_F2)); break; // Xcode
				case KC_P: tapL(MEH(KC_F12)); break; // 1Password
				case KC_M: tapL(LCAG(KC_F1)); break; // Messaging App
				case KC_G: tapL(CMD(KC_GRAVE)); break; // ⌘ `
				case KC_C: press(KC_CMD); tapL(KC_TAB); isCmdTabOn = true; break; // Sticky ⌘ ↹
				case KC_R: tapL(LCAG(KC_F5)); break; // tRansmission
				case KC_D: tapL(LCAG(KC_F4)); break; // toDoist
				case KC_I: tapL(HYPR(KC_F3)); break; // iTunes Mini Player - Alfred
				case KC_S: tapL(CMD(KC_SPC)); break; // Spotlight
				case KC_O: tapL(CMD(OPT(KC_SPC))); break; // mOom
				/* case KC_F: tapL(HYPR(KC_F1)); break; */
				/* case KC_L: tapL(MEH(KC_F4)); break; */
			}
			break;
			
		// Symbols
		case KC_H:
			switch (leader_sequence[1])
			{
				case KC_LEAD: repeatTapL(); break;
				case KC_QUOTE: tapL(KC_DOUBLE_QUOTE); tapL(KC_DOUBLE_QUOTE); tapL(KC_LEFT); break; // pair of double quotes
				case KC_COMM: tapL(KC_LT); break;
				case KC_P: tapL(KC_LPRN); tapL(KC_RPRN); tapL(KC_LEFT); break; // pair of Parentheses
				case KC_Y: tapL(KC_RPRN); break;
				case KC_A: tapL(KC_ASTR); break; // Asterisk
				case KC_O: tapL(KC_0); break;
				case KC_E: tapL(KC_EQL); break; // Equal
				case KC_U: tapL(KC_PLUS); break; // plUs
				case KC_I: tapL(KC_1); break;
				case KC_COLON: tapL(KC_SCOLON); break;
				case KC_Q: tapL(KC_QUES); break; // Question mark
				case KC_J: tapL(KC_DOWN); break;
				case KC_K: tapL(KC_UP); break;
				case KC_X: tapL(KC_EXLM); break; // eXclamation mark
				case KC_F: tapL(KC_CIRC); break; // circumFlex
				case KC_G: tapL(KC_AT); break; // at sigGn
				case KC_C: tapL(KC_LEFT_CURLY_BRACE); tapL(KC_RIGHT_CURLY_BRACE); tapL(KC_LEFT); break; // pair of Curly braces
				case KC_R: tapL(KC_PERC); break; // peRcent
				case KC_L: tapL(KC_RIGHT_CURLY_BRACE); break;
				case KC_D: tapL(KC_DLR); break; // Dollar
				case KC_H: tapL(KC_HASH); break; // Hash
				case KC_T: tapL(KC_TILDE); break; // Tilde
				case KC_S: tapL(KC_BSLS); break; // backSlash
				case KC_B: tapL(KC_LBRACKET); tapL(KC_RBRACKET); tapL(KC_LEFT); break; // pair of Brackets
				case KC_M: tapL(KC_AMPR); break; // aMpersand
				case KC_V: tapL(KC_PIPE); break; // Vertical bar
				case KC_Z: tapL(KC_RBRACKET); break;
			}
			break;
			
		// ⌘ - Command
		case KC_C:
			if (leader_sequence[1])
				tapL(CMD(leader_sequence[1]));
			/* case KC_J: tapL(CMD(KC_DOWN)); break; */
			/* case KC_K: tapL(CMD(KC_UP)); break; */
			/* case KC_H: tapL(CMD(KC_LEFT)); break; */
			/* case KC_S: tapL(CMD(KC_RIGHT)); break; */
			break;
			
		// Macros & Misc
		case KC_G:
			switch (leader_sequence[1])
			{
				case KC_N: tapL(HYPR(KC_F2)); break; // meNu
				case KC_B: tapL(CTRL(KC_F2)); break; // Bar
				case KC_Z: tapL(CMD(KC_LEFT)); break; // ⌘ ←
				case KC_A: tapL(CMD(KC_RIGHT)); break; // ⌘ →
				case KC_P: tapL(CMD(KC_A)); tapL(CMD(KC_V)); break; // Paste all
				case KC_Y: tapL(CMD(KC_A)); tapL(CMD(KC_C)); break; // Yank all
				case KC_E: tapL(CMD(S(KC_LEFT))); break; // ⌘ ⇧ ←
				case KC_T: tapL(CMD(S(KC_RIGHT))); break; // ⌘ ⇧ →
				case KC_H: tapL(CMD(CTRL(KC_LEFT))); break; // ⌘ ⌃ ←
				case KC_S: tapL(CMD(CTRL(KC_RIGHT))); break; // ⌘ ⌃ →
				case KC_D: tapL(LCAG(KC_F11)); break; // toDoist quick add
				case KC_M: tapL(HYPR(KC_F4)); break; // eMojis
				case KC_LEAD: SEND_STRING("... "); endLeading(); break;
			}
			break;
			
		/* case KC_N: layer_on(Numpad); endLeading(); break; */
		case KC_N:
			switch (leader_sequence[1])
			{
				case KC_U: tapL(KC_0); break;
				case KC_E: tapL(KC_1); break;
				case KC_O: tapL(KC_2); break;
				case KC_A: tapL(KC_3); break;
				case KC_I: tapL(KC_4); break;
				case KC_LEAD: tapL(KC_5); break;
				/* case KC_E: tapL(KC_1); break; */
				/* case KC_O: tapL(KC_2); break; */
				/* case KC_A: tapL(KC_3); break; */
				/* case KC_I: tapL(KC_4); break; */
				/* case KC_LEAD: tapL(KC_5); break; */
			}
			break;
			
		// ⌘ ⇧
		case (KC_L):
			if (leader_sequence[1])
				tapL(CMD(S(leader_sequence[1])));
			/* case KC_J: tapL(CMD(S(KC_DOWN))); break; */
			/* case KC_K: tapL(CMD(S(KC_UP))); break; */
			/* case KC_H: tapL(CMD(S(KC_LEFT))); break; */
			/* case KC_S: tapL(CMD(S(KC_RIGHT))); break; */
			break;
			
		// ⌃ - contRol
		case (KC_R):
			if (leader_sequence[1])
				tapL(C(leader_sequence[1]));
			/* case KC_J: tapL(C(KC_DOWN)); break; */
			/* case KC_K: tapL(C(KC_UP)); break; */
			/* case KC_H: tapL(C(KC_LEFT)); break; */
			/* case KC_S: tapL(C(KC_RIGHT)); break; */
			break;
			
		// ⌥  - Option
		case KC_O:
			if (leader_sequence[1])
				tapL(OPT(leader_sequence[1]));
			break;
			
		// Media: mp-play mn-next mr-previous mj-volDown mk-volUp mm-mute
		case KC_M:
			switch (leader_sequence[1])
			{
				case KC_P: tapL(KC_MEDIA_PLAY_PAUSE); break;
				case KC_N: tapL(KC_MEDIA_NEXT_TRACK); break;
				case KC_R: tapL(KC_MEDIA_PREV_TRACK); break;
				case KC_J: tapL(KC_AUDIO_VOL_DOWN); break;
				case KC_K: tapL(KC_AUDIO_VOL_UP); break;
				case KC_M: tapL(KC_AUDIO_MUTE); break;
			}
			break;
			
		/* CamelCase navigation */
		// ,w: ⌃ →		,b: ⌃ ←	,vw: ⌃ ⇧ →		,vb: ⌃ ⇧ ←		,db: ⌃ ⌫ 	,dw: ⌃ ⌦
		/* bindSequenceTwo(KC_COMM, KC_W, ctrl(KC_RIGHT); break; */
		/* bindSequenceTwo(KC_COMM, KC_B, ctrl(KC_LEFT); break; */
		/* bindSequenceTwo(KC_COMM, KC_V) && leader_sequence[2] == (KC_W): ctrlShift(KC_RIGHT); break; */
		/* bindSequenceTwo(KC_COMM, KC_V) && leader_sequence[2] == (KC_B): ctrlShift(KC_LEFT); break; */
		/* bindSequenceTwo(KC_COMM, KC_D) && leader_sequence[2] == (KC_B): ctrl(KC_BSPC); break; */
		/* bindSequenceTwo(KC_COMM, KC_D) && leader_sequence[2] == (KC_W): ctrl(KC_DEL); break; } */
		
		// Tabs / Extra
		// gt: ⌘ ⇧ →	 ge: ⌘ ⇧ ←	 gs: ⌘ ⌃ →	 gh: ⌘ ⌃ ←
		/* bindSequenceTwo(KC_G, KC_T: tapL(SGUI(KC_RIGHT))) */ /* bindSequenceTwo(KC_G, KC_E: tapL(SGUI(KC_LEFT))) */
		/* bindSequenceTwo(KC_G, KC_S: tapL(CMD(C(KC_RIGHT)))) */ /* bindSequenceTwo(KC_G, KC_H: tapL(CMD(C(KC_LEFT)))) */
		
		// Window / Split / Panel
		// ⏎ w : ⌘ ]
		/* bindSequenceTwo(KC_ENT, KC_W: tapL(CMD(KC_RBRC))) */
		
		// Arrows
		/* case KC_J: tapL(KC_DOWN)) */
		/* case KC_K: tapL(KC_UP)) */
		/* case KC_H: tapL(KC_LEFT)) */
		/* case KC_S: tapL(KC_RIGHT)) */
			
#if defined(UNICODE_ENABLE)
		// Unicode, Accented characters
		case KC_QUOTE: // ¸ or ´
			switch (leader_sequence[1])
			{
				case KC_C: tapUnicodeL(0x00E7); break;
				case KC_A: tapUnicodeL(0x00E1); break;
				case KC_E: tapUnicodeL(0x00E9); break;
				case KC_I: tapUnicodeL(0x00ED); break;
				case KC_O: tapUnicodeL(0x00F3); break;
				case KC_U: tapUnicodeL(0x00FA); break;
			}
			break;
			
		case KC_GRAVE: // `
			switch (leader_sequence[1])
			{
				case KC_A: tapUnicodeL(0x00E0); break;
			}
			break;

		case KC_MINS: // ~
			switch (leader_sequence[1])
			{
				case KC_A: tapUnicodeL(0x00E3); break;
				case KC_O: tapUnicodeL(0x00F5); break;
				case KC_N: tapUnicodeL(0x00F1); break;
			}
			break;
			
		case KC_F: // ^
			switch (leader_sequence[1])
			{
				case KC_A: tapUnicodeL(0x00E2); break;
				case KC_E: tapUnicodeL(0x00EA); break;
				case KC_O: tapUnicodeL(0x00F4); break;
				case KC_U: tapUnicodeL(0x00FC); break;
			}
			break;
#endif
	}
}


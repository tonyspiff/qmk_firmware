#include "leading.h"
#include "mods.h"
#include "vim.h"

bool isSymbolLeading = false;

void startSymbolLeading()
{
	isSymbolLeading = true;
	qk_leader_start();
}

void endLeading()
{
	isSymbolLeading = false;
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

void tapModComboL(uint16_t keycode, uint16_t mods[], uint8_t size)
{
	stick(mods, size);
	
	if (keycode != KC_BSPC)
	{
		keycode == KC_SYMB
			? tap(KC_COMM)
			: tap(keycode);
		unstickAll();
	}

	endLeading();
}

void process_leading_sequence(void)
{
	if (!leading)
		return;

	if (isSymbolLeading) 
	{
		switch (leader_sequence[0])
		{
			case 0: return;
			case KC_ESC: endLeading(); break;
			case KC_LEAD: tapL(KC_RIGHT_ANGLE_BRACKET); break;
			case KC_SYMB: tapL(KC_COMM); break;
			case KC_QUOTE: tapL(KC_DOUBLE_QUOTE); break; // double quote
			case KC_P: tapL(KC_LPRN); break; // Parenthesis
			case KC_Y: tapL(KC_RPRN); break;
			case KC_A: tapL(KC_ASTR); break; // Asterisk
			case KC_O: tapL(KC_0); break;
			case KC_E: tapL(KC_EQL); break; // Equal
			case KC_U: tapL(KC_PLUS); break; // plUs
			case KC_I: tapL(KC_1); break;
			case KC_COLON: tapL(KC_SCOLON); break;
			case KC_N: tapL(KC_SCOLON); break; // semicoloN
			case KC_Q: tapL(KC_QUES); break; // Question mark
			case KC_J: tapL(KC_DOWN); break;
			case KC_K: tapL(KC_UP); break;
			case KC_X: tapL(KC_EXLM); break; // eXclamation mark
			case KC_F: tapL(KC_CIRC); break; // circumFlex
			case KC_G: tapL(KC_AT); break; // at sigGn
			case KC_C: tapL(KC_LEFT_CURLY_BRACE); break; // Curly brace
			case KC_R: tapL(KC_PERC); break; // peRcent
			case KC_L: tapL(KC_RIGHT_CURLY_BRACE); break;
			case KC_D: tapL(KC_DLR); break; // Dollar
			case KC_H: tapL(KC_HASH); break; // Hash
			case KC_T: tapL(KC_TILDE); break; // Tilde
			case KC_S: tapL(KC_BSLS); break; // backSlash
			case KC_B: tapL(KC_LBRACKET); break; // Bracket
			case KC_M: tapL(KC_AMPR); break; // aMpersand
			case KC_V: tapL(KC_PIPE); break; // Vertical bar
			case KC_Z: tapL(KC_RBRACKET); break;
			case KC_SPC: tap(KC_COMM); tapL(KC_SPC); break;
			case KC_ENT: tap(KC_COMM); tapL(KC_ENT); break;
		}

		return;
	}

	switch (leader_sequence[0])
	{
		case 0: return;
		case KC_ESC: endLeading(); break;
		case KC_LEAD: tapL(KC_DOT); break;
		case KC_P: tapL(MEH(KC_F3)); break;
		case KC_U: tapL(KC_F13); break;
		case KC_N: layer_on(Numpad); endLeading(); break;
		case KC_SPC: tap(KC_DOT); tapL(KC_SPC); break;
		case KC_ENT: tap(KC_DOT); tapL(KC_ENT); break;
		case KC_V: isVimodeOn = true; endLeading(); break;
		case KC_J: tapL(KC_DOWN); break;
		case KC_K: tapL(KC_UP); break;

		// One Shot Function Layer
		case KC_F:
			layer_on(Function);
            set_oneshot_layer(Function, ONESHOT_START);
            clear_oneshot_layer_state(ONESHOT_PRESSED);
			endLeading();
			break;
			
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
				case KC_C: { uint16_t mods[] = { KC_CMD }; stick(mods, 1); tapL(KC_TAB); } break; // Sticky ⌘ ↹
				case KC_R: tapL(LCAG(KC_F5)); break; // tRansmission
				case KC_D: tapL(LCAG(KC_F4)); break; // toDoist
				case KC_I: tapL(HYPR(KC_F3)); break; // iTunes Mini Player - Alfred
				case KC_S: tapL(CMD(KC_SPC)); break; // Spotlight
				case KC_O: tapL(CMD(OPT(KC_SPC))); break; // mOom
				/* case KC_F: tapL(HYPR(KC_F1)); break; */
				/* case KC_L: tapL(MEH(KC_F4)); break; */
			}
			break;
			
		// FIXME: Deprecate this in favour of KC_SYMB
		// Symbols
		case KC_H:
			switch (leader_sequence[1])
			{
				case KC_LEAD: repeatTapL(); break;
				case KC_QUOTE: tapL(KC_DOUBLE_QUOTE); break; // double quote
				case KC_P: tapL(KC_LPRN); break; // Parenthesis
				case KC_Y: tapL(KC_RPRN); break;
				case KC_A: tapL(KC_ASTR); break; // Asterisk
				case KC_O: tapL(KC_0); break;
				case KC_E: tapL(KC_EQL); break; // Equal
				case KC_U: tapL(KC_PLUS); break; // plUs
				case KC_I: tapL(KC_1); break;
				case KC_COLON: tapL(KC_SCOLON); break;
				case KC_N: tapL(KC_SCOLON); break; // semicoloN
				case KC_Q: tapL(KC_QUES); break; // Question mark
				case KC_J: tapL(KC_DOWN); break;
				case KC_K: tapL(KC_UP); break;
				case KC_X: tapL(KC_EXLM); break; // eXclamation mark
				case KC_F: tapL(KC_CIRC); break; // circumFlex
				case KC_G: tapL(KC_AT); break; // at sigGn
				case KC_C: tapL(KC_LEFT_CURLY_BRACE); break; // Curly brace
				case KC_R: tapL(KC_PERC); break; // peRcent
				case KC_L: tapL(KC_RIGHT_CURLY_BRACE); break;
				case KC_D: tapL(KC_DLR); break; // Dollar
				case KC_H: tapL(KC_HASH); break; // Hash
				case KC_T: tapL(KC_TILDE); break; // Tilde
				case KC_S: tapL(KC_BSLS); break; // backSlash
				case KC_B: tapL(KC_LBRACKET); break; // Bracket
				case KC_M: tapL(KC_AMPR); break; // aMpersand
				case KC_V: tapL(KC_PIPE); break; // Vertical bar
				case KC_Z: tapL(KC_RBRACKET); break;
			}
			break;

		// Special Symbols
		case KC_W:
			switch (leader_sequence[1])
			{
				case KC_B: tapL(KC_RBRACKET); break; // Bracket
				case KC_P: tapL(KC_RPRN); break; // Parenthesis
				case KC_C: tapL(KC_RIGHT_CURLY_BRACE); break; // Curly brace
				case KC_E: tapL(KC_LPRN); tapL(KC_RPRN); tapL(KC_LEFT); break; // pair of parenthesEs
				case KC_U: tapL(KC_LEFT_CURLY_BRACE); tapL(KC_RIGHT_CURLY_BRACE); tapL(KC_LEFT); break; // pair of cUrly braces
				case KC_O: tapL(KC_LBRACKET); tapL(KC_RBRACKET); tapL(KC_LEFT); break; // pair of crOtchets
				case KC_A: tapL(KC_DOUBLE_QUOTE); tapL(KC_DOUBLE_QUOTE); tapL(KC_LEFT); break; // pair of double quotes
				case KC_LEAD: tapL(KC_DOT); tapL(KC_DOT); break; // pair of dots
				case KC_SYMB: tapL(KC_LEFT_ANGLE_BRACKET); tapL(KC_RIGHT_ANGLE_BRACKET); tapL(KC_LEFT); break; // pair of angle brackets
				case KC_QUOTE: tapL(KC_QUOTE); tapL(KC_QUOTE); tapL(KC_LEFT); break; // pair of quotes
				case KC_GRAVE: tapL(KC_GRAVE); tapL(KC_GRAVE); tapL(KC_LEFT); break; // pair of grave accents
				case KC_D: tapL(KC_DLR); tapL(KC_0); tapL(KC_DOT); break; // $0.
			}
			break;

			
		// ⌘ - Command
		case KC_C:
			if (leader_sequence[1])
			{
				uint16_t mods[] = { KC_CMD };
				tapModComboL(leader_sequence[1], mods, 1);
			}
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
				case KC_H: tapL(CMD(CTRL(KC_LEFT))); break; // ⌘ ⎈ ←
				case KC_S: tapL(CMD(CTRL(KC_RIGHT))); break; // ⌘ ⎈ →
				case KC_D: tapL(LCAG(KC_F11)); break; // toDoist quick add
				case KC_M: tapL(HYPR(KC_F4)); break; // eMojis
				case KC_C: tapL(HYPR(KC_F5)); break; // Close notifications
				case KC_X: tapL(HYPR(KC_F6)); break; // Close system specific dialogs
				case KC_I: tapL(S(KC_ESC)); break; // ⇧ ⎋
				case KC_LEAD: SEND_STRING("... "); endLeading(); break;
			}
			break;

		// Macros & Misc
		case KC_Z:
			switch (leader_sequence[1])
			{
				case KC_I: tapL(CMD(KC_PLUS)); break; // zoom in: ⌘ +
				case KC_O: tapL(CMD(KC_MINUS)); break; // zoom out: ⌘ -
				case KC_LEAD: tapL(CMD(KC_DOT)); break; // ⌘ .
				case KC_J: tapL(CMD(OPT(KC_DOWN))); break; // ⌘ ⌥ ↓
				case KC_K: tapL(CMD(OPT(KC_UP))); break; // ⌘ ⌥ ↑
			}
			break;
			
		// ⌘ ⇧
		case (KC_L):
			if (leader_sequence[1])
			{
				uint16_t mods[] = { KC_CMD, KC_SHIFT };
				tapModComboL(leader_sequence[1], mods, 2);
			}
			/* case KC_J: tapL(CMD(S(KC_DOWN))); break; */
			/* case KC_K: tapL(CMD(S(KC_UP))); break; */
			/* case KC_H: tapL(CMD(S(KC_LEFT))); break; */
			/* case KC_S: tapL(CMD(S(KC_RIGHT))); break; */
			break;
			
		// ⎈ - contRol
		case (KC_R):
			if (leader_sequence[1])
			{
				uint16_t mods[] = { KC_CTRL };
				tapModComboL(leader_sequence[1], mods, 1);
			}
			/* case KC_J: tapL(C(KC_DOWN)); break; */
			/* case KC_K: tapL(C(KC_UP)); break; */
			/* case KC_H: tapL(C(KC_LEFT)); break; */
			/* case KC_S: tapL(C(KC_RIGHT)); break; */
			break;
			
		// ⌥ - Option
		case KC_O:
			if (leader_sequence[1])
			{
				uint16_t mods[] = { KC_OPT };
				tapModComboL(leader_sequence[1], mods, 1);
			}
			break;

		// ⌘ ⌥ - Command Option
		case KC_Q:
			if (leader_sequence[1])
			{
				uint16_t mods[] = { KC_CMD, KC_OPT };
				tapModComboL(leader_sequence[1], mods, 2);
			}
			break;

		// ⌘ ⎈ - Command Control
		case KC_A:
			if (leader_sequence[1])
			{
				uint16_t mods[] = { KC_CMD, KC_CTRL };
				tapModComboL(leader_sequence[1], mods, 2);
			}
			break;
			
		// ⌘ ⎈ ⌥ - Command Control Option
		case KC_B:
			if (leader_sequence[1])
			{
				uint16_t mods[] = { KC_CMD, KC_OPT, KC_CTRL };
				tapModComboL(leader_sequence[1], mods, 3);
			}
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
			
#if !defined(UNICODE_ENABLE)
		// Accented characters - macos - no unicode
		case KC_QUOTE: tapL(OPT(KC_E)); break; // ´
		case KC_GRAVE: tapL(OPT(KC_GRAVE)); break; // `
		case KC_MINUS: tapL(OPT(KC_N)); break; // ˜
		case KC_X: tapL(OPT(KC_I)); break; // ˆ
		case KC_SYMB: tapL(OPT(KC_C)); break; // ç
		case KC_COLON: tapL(OPT(KC_U)); break; // ¨
#else	
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

		case KC_MINUS: // ~
			switch (leader_sequence[1])
			{
				case KC_A: tapUnicodeL(0x00E3); break;
				case KC_O: tapUnicodeL(0x00F5); break;
				case KC_N: tapUnicodeL(0x00F1); break;
			}
			break;
			
		case KC_X: // ^
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


#include "vim.h"
#include "tap.h"
#include "mods.h"
#include <string.h>

bool isVimodeOn = false;
uint16_t vimQueue[2] = { 0, 0 };
uint16_t previousVimQueue[2] = { 0, 0 };

bool vim_process_record_user(uint16_t keycode, keyrecord_t *record)
{
	if (!isVimodeOn || !record->event.pressed)
		return true;

	switch (keycode)
	{
        case KC_LCTRL ... KC_RGUI:
			// FALL THRU
        case QK_ONE_SHOT_MOD ... QK_ONE_SHOT_MOD_MAX:
			return true;
	}

	addToVimQueue(keycode);
	return processQueue();
}

void addToVimQueue(uint16_t keycode)
{
	for (uint8_t i = 0; i < sizeof(vimQueue); i++) 
	{
		if (vimQueue[i] == 0) 
		{
			vimQueue[i] = keycode;
			break;
		}
	}
}

void clearVimQueue(void)
{
	memset(vimQueue, 0, sizeof(vimQueue));
}

void clearModsAndTap(uint16_t keycode)
{
	clear_mods();
	clear_oneshot_mods();
	tap(keycode);
}

bool processQueue(void)
{
	bool shouldPassKeyThru = false;
	bool shouldClearQueue = true;

	// Mac Keyboard Shortcuts: https://support.apple.com/en-ca/HT201236
	switch (vimQueue[0])
	{
		case KC_ESC: break;
		case KC_TAB:
			 // FALL THRU
		case KC_ENT: isVimodeOn = false; shouldPassKeyThru = true; break;

		case KC_SPACE: tap(KC_PGDOWN); break;
		case KC_MINUS: tap(KC_PGUP); break;

		case KC_A:
			if (isShiftOn)
				clearModsAndTap(CMD(KC_RIGHT));
			else
				tap(KC_RIGHT);

			isVimodeOn = false;
			break;

		case KC_B: tap(OPT(KC_LEFT)); break;

		case KC_C:
			switch (vimQueue[1])
			{
				case KC_B: tap(OPT(KC_BSPC)); isVimodeOn = false; break;
				case KC_W: tap(OPT(KC_DEL)); isVimodeOn = false; break;
				case 0: shouldClearQueue = false; break;
			}
			break;

		// TODO: Copy content before deleting
		case KC_D:
			if (isShiftOn) { clearModsAndTap(CTRL(KC_K)); break; }

			switch (vimQueue[1])
			{
				case KC_B: tap(OPT(KC_BSPC)); break;
				case KC_D: tap(CMD(KC_RIGHT)); tap(CMD(KC_BSPC)); break;
				case KC_W: tap(OPT(KC_DEL)); break;
				case 0: shouldClearQueue = false; break;
			}
			break;

		case KC_G:
			if (isShiftOn) { clearModsAndTap(KC_END); break; }

			switch (vimQueue[1])
			{
				case KC_A: tap(CMD(KC_RIGHT)); break;
				case KC_Z: tap(CMD(KC_LEFT)); break;
				case KC_G: tap(KC_HOME); break;
				case 0: shouldClearQueue = false; break;
			}
			break;

		case KC_H: tap(KC_LEFT); break;

		case KC_I:
			if (isShiftOn) { clearModsAndTap(CMD(KC_LEFT)); }

			isVimodeOn = false;
			break;

		case KC_J: tap(KC_DOWN); break;
		case KC_K: tap(KC_UP); break;
		case KC_P: tap(CMD(KC_V)); break;
		case KC_S: tap(KC_RIGHT); break;
		case KC_U: tap(CMD(KC_Z)); break;
		case KC_W: tap(OPT(KC_RIGHT)); break;

		case KC_X:
			if (isShiftOn) { clearModsAndTap(KC_BSPACE); break; }

			tap(KC_DEL);
			break;

		case KC_Y:
			if (isShiftOn) { tap(CMD(KC_RIGHT)); tap(CMD(KC_C)); break; }

			switch (vimQueue[1])
			{
				case KC_Y: tap(CMD(KC_A)); tap(CMD(KC_C)); break;
				case 0: shouldClearQueue = false; break;
			}
			break;

		case KC_LEAD:
			memcpy(vimQueue, previousVimQueue, sizeof(previousVimQueue));
			return processQueue();

		/* CamelCase navigation */
		// ,w: ⌃ →		,b: ⌃ ←	,vw: ⌃ ⇧ →		,vb: ⌃ ⇧ ←		,db: ⌃ ⌫ 	,dw: ⌃ ⌦
		/* bindSequenceTwo(KC_COMM, KC_W, ctrl(KC_RIGHT); break; */
		/* bindSequenceTwo(KC_COMM, KC_B, ctrl(KC_LEFT); break; */
		/* bindSequenceTwo(KC_COMM, KC_V) && leader_sequence[2] == (KC_W): ctrlShift(KC_RIGHT); break; */
		/* bindSequenceTwo(KC_COMM, KC_V) && leader_sequence[2] == (KC_B): ctrlShift(KC_LEFT); break; */
		/* bindSequenceTwo(KC_COMM, KC_D) && leader_sequence[2] == (KC_B): ctrl(KC_BSPC); break; */
		/* bindSequenceTwo(KC_COMM, KC_D) && leader_sequence[2] == (KC_W): ctrl(KC_DEL); break; } */
		
		// Window / Split / Panel
		// ⏎ w : ⌘ ]
		/* bindSequenceTwo(KC_ENT, KC_W: tapL(CMD(KC_RBRC))) */
	}

	if (shouldClearQueue)
	{
		memcpy(previousVimQueue, vimQueue, sizeof(vimQueue));
		clearVimQueue();
	}

	return shouldPassKeyThru;
}


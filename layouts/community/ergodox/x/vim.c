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

	addToVimQueue(keycode);
	return processQueue();
}

void addToVimQueue(uint16_t keycode)
{
	if (vimQueue[0] == 0) 
		vimQueue[0] = keycode;
	else
		vimQueue[1] = keycode;
}

void clearVimQueue(void)
{
	vimQueue[0] = 0;
	vimQueue[1] = 0;
}

bool processQueue(void)
{
	bool shouldPassKeyThru = false;
	bool shouldClearQueue = true;

	switch (vimQueue[0])
	{
		case KC_ESC: break;
		case KC_TAB:
			 // FALL THRU
		case KC_ENT: isVimodeOn = false; shouldPassKeyThru = true; break;

		case KC_SPACE: tap(KC_PGDOWN); break;
		case KC_MINUS: tap(KC_PGUP); break;
		case KC_A: tap(KC_RIGHT); isVimodeOn = false; break;
		case KC_B: tap(OPT(KC_LEFT)); break;
		case KC_H: tap(KC_LEFT); break;
		case KC_I: isVimodeOn = false; break;
		case KC_J: tap(KC_DOWN); break;
		case KC_K: tap(KC_UP); break;
		case KC_P: tap(CMD(KC_V)); break;
		case KC_S: tap(KC_RIGHT); break;
		case KC_U: tap(CMD(KC_Z)); break;
		case KC_W: tap(OPT(KC_RIGHT)); break;
		case KC_X: tap(KC_BSPACE); break;

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
			// FIXME: Shift not working
			if (isShiftOn)
			{
				tap(CMD(KC_DEL));
				break;
			}

			switch (vimQueue[1])
			{
				case KC_B: tap(OPT(KC_BSPC)); break;
				case KC_D: tap(CMD(KC_RIGHT)); tap(CMD(KC_BSPC)); break;
				case KC_W: tap(OPT(KC_DEL)); break;
				case 0: shouldClearQueue = false; break;
			}
			break;

		case KC_G:
			switch (vimQueue[1])
			{
				case KC_A: tap(CMD(KC_RIGHT)); break;
				case KC_Z: tap(CMD(KC_LEFT)); break;
				case KC_G: tap(KC_HOME); break;
				case 0: shouldClearQueue = false; break;
			}
			break;

		case KC_Y:
			switch (vimQueue[1])
			{
				case KC_Y: tap(CMD(KC_A)); tap(CMD(KC_C)); break;
				case 0: shouldClearQueue = false; break;
			}
			break;

		case KC_LEAD:
			memcpy(vimQueue, previousVimQueue, sizeof(previousVimQueue));
			return processQueue();
	}

	if (shouldClearQueue)
	{
		memcpy(previousVimQueue, vimQueue, sizeof(vimQueue));
		clearVimQueue();
	}

	return shouldPassKeyThru;
}


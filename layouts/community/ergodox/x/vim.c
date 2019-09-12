#include "vim.h"
#include "tap.h"
#include "mods.h"

bool isVimodeOn = false;
uint16_t vimQueue[2] = { 0, 0 };

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
	switch (vimQueue[0])
	{
		case KC_ESC: break;

		case KC_B: tap(OPT(KC_LEFT)); break;
		case KC_I: isVimodeOn = false; break;
		case KC_P: tap(CMD(KC_V)); break;
		case KC_U: tap(CMD(KC_Z)); break;
		case KC_W: tap(OPT(KC_RIGHT)); break;

		case KC_C:
			switch (vimQueue[1])
			{
				case KC_B: tap(OPT(KC_BSPC)); isVimodeOn = false; break;
				case KC_W: tap(OPT(KC_DEL)); isVimodeOn = false; break;
				case 0: return false;
			}
			break;

		// TODO: Copy content before deleting
		case KC_D:
			if (isShiftOn)
			{
				tap(CMD(KC_DEL));
				clearVimQueue();
				return false;
			}

			switch (vimQueue[1])
			{
				case KC_B: tap(OPT(KC_BSPC)); break;
				case KC_D: tap(CMD(KC_RIGHT)); tap(CMD(KC_BSPC)); break;
				case KC_W: tap(OPT(KC_DEL)); break;
				case 0: return false;
			}
			break;

		case KC_G:
			switch (vimQueue[1])
			{
				case KC_A: tap(CMD(KC_RIGHT)); break;
				case KC_Z: tap(CMD(KC_LEFT)); break;
				case 0: return false;
			}
			break;

		case KC_Y:
			switch (vimQueue[1])
			{
				case KC_Y: tap(CMD(KC_A)); tap(CMD(KC_C)); break;
				case 0: return false;
			}
			break;
	}

	clearVimQueue();

	return false;
}

/* void vim_D(void) */
/* { */
/* 	tap(CMD(KC_DEL)); */
/* } */

/* void vim_W(void) */
/* { */
/* 	tap(OPT(KC_RIGHT)); */
/* } */

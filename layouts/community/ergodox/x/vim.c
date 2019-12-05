#include "vim.h"
#include "tap.h"
#include "mods.h"
#include <string.h>

bool isVimodeOn = false;
uint16_t vimQueue[2] = { 0, 0 };
uint16_t previousVimQueue[2] = { 0, 0 };

bool vim_process_record_user(uint16_t keycode, keyrecord_t *record)
{
	if (!isVimodeOn)
		return true;

	switch (keycode)
	{
        case KC_LCTRL ... KC_RGUI:
			// FALL THRU
        case QK_ONE_SHOT_MOD ... QK_ONE_SHOT_MOD_MAX:
			return true;
	}

	addToVimQueue(keycode);

	return processQueue(record->event.pressed);
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

void handleKeycode(uint16_t keycode, bool isPressed, bool shouldClearMods, bool canRepeat)
{
	if (isPressed)
	{
		canRepeat ? press(keycode) : tap(keycode);
	}
	else if (canRepeat)
	{
		release(keycode);
	}

	if (shouldClearMods && !isPressed)
	{
		clear_mods();
		clear_oneshot_mods();
	}
}

bool processQueue(bool isPressed)
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

		case KC_SPACE: handleKeycode(KC_PGDOWN, isPressed, false, true); break;
		case KC_MINUS: handleKeycode(KC_PGUP, isPressed, false, true); break;

		case KC_A:
			if (isShiftOn)
				handleKeycode(CMD(KC_RIGHT), isPressed, true, false);
			else
				handleKeycode(KC_RIGHT, isPressed, false, true);

			isVimodeOn = false;
			break;

		case KC_B: handleKeycode(OPT(KC_LEFT), isPressed, false, true); break;

		case KC_C:
			switch (vimQueue[1])
			{
				case KC_B: handleKeycode(OPT(KC_BSPC), isPressed, false, false); isVimodeOn = false; break;
				case KC_C: handleKeycode(CMD(KC_RIGHT), isPressed, false, false); handleKeycode(CMD(KC_BSPC), isPressed, false, false); isVimodeOn = false; break;
				case KC_W: handleKeycode(OPT(KC_DEL), isPressed, false, false); isVimodeOn = false; break;
				case 0: shouldClearQueue = false; break;
			}
			break;

		// TODO: Copy content before deleting
		case KC_D:
			if (isShiftOn) { handleKeycode(CTRL(KC_K), isPressed, true, false); break; }

			switch (vimQueue[1])
			{
				case KC_B: handleKeycode(OPT(KC_BSPC), isPressed, false, false); break;
				case KC_D: handleKeycode(CMD(KC_RIGHT), isPressed, false, false); handleKeycode(CMD(KC_BSPC), isPressed, false, false); break;
				case KC_W: handleKeycode(OPT(KC_DEL), isPressed, false, false); break;
				case 0: shouldClearQueue = false; break;
			}
			break;

		case KC_G:
			if (isShiftOn) { handleKeycode(KC_END, isPressed, true, false); break; }

			switch (vimQueue[1])
			{
				case KC_A: handleKeycode(CMD(KC_RIGHT), isPressed, false, false); break;
				case KC_Z: handleKeycode(CMD(KC_LEFT), isPressed, false, false); break;
				case KC_G: handleKeycode(KC_HOME, isPressed, false, false); break;
				case 0: shouldClearQueue = false; break;
			}
			break;

		case KC_H: handleKeycode(KC_LEFT, isPressed, false, true); break;

		case KC_I:
			if (isShiftOn) { handleKeycode(CMD(KC_LEFT), isPressed, true, false); }

			isVimodeOn = false;
			break;

		case KC_J: handleKeycode(KC_DOWN, isPressed, false, true); break;
		case KC_K: handleKeycode(KC_UP, isPressed, false, true); break;
		case KC_P: handleKeycode(CMD(KC_V), isPressed, false, false); break;
		case KC_R: handleKeycode(KC_DEL, isPressed, false, false); isVimodeOn = false; break;
		case KC_S: handleKeycode(KC_RIGHT, isPressed, false, true); break;
		case KC_U: handleKeycode(CMD(KC_Z), isPressed, false, true); break;
		case KC_W: handleKeycode(OPT(KC_RIGHT), isPressed, false, true); break;

		case KC_X:
			if (isShiftOn) { handleKeycode(KC_BSPACE, isPressed, true, true); break; }

			handleKeycode(KC_DEL, isPressed, false, true);
			break;

		case KC_Y:
			if (isShiftOn) { handleKeycode(CMD(KC_RIGHT), isPressed, false, false); handleKeycode(CMD(KC_C), isPressed, false, false); break; }

			switch (vimQueue[1])
			{
				case KC_Y: handleKeycode(CMD(KC_A), isPressed, false, false); handleKeycode(CMD(KC_C), isPressed, false, false); break;
				case 0: shouldClearQueue = false; break;
			}
			break;

		case KC_LEAD:
			memcpy(vimQueue, previousVimQueue, sizeof(previousVimQueue));
			return processQueue(isPressed);

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


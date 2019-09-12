#include "macros.h"
#include "tap.h"
#include "mods.h"

bool isCmdTabOn = false;

bool macros_process_record_user(uint16_t keycode, keyrecord_t *record)
{
	if (!isCmdTabOn || !record->event.pressed)
		return true;

	switch (keycode)
	{
		case KC_ESC:
			// FALL THRU
		case KC_ENT:
			if (isCmdTabOn)
			{
				release(KC_CMD);
				isCmdTabOn = false;
				return false;
			}
			break;
	}

	return true;
}


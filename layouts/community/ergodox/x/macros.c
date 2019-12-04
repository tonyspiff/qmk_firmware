#include "macros.h"
#include "tap.h"
#include "mods.h"

uint16_t stickyKey = 0;

bool macros_process_record_user(uint16_t keycode, keyrecord_t *record)
{
	if (!stickyKey || !record->event.pressed)
		return true;

	switch (keycode)
	{
		case KC_ESC:
			// FALL THRU
		case KC_ENT:
			if (stickyKey)
			{
				release(stickyKey);
				stickyKey = 0;
				return false;
			}
			break;
	}

	return true;
}


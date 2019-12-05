#include "macros.h"
#include "tap.h"
#include "mods.h"
#include <string.h>

#define MODS_MAX 4
uint16_t stickyMods[MODS_MAX] = { 0 };

bool isSticky(void)
{
	uint16_t *p = stickyMods;

	while (*p++)
		return true;

	return false;
}

bool macros_process_record_user(uint16_t keycode, keyrecord_t *record)
{
	if (!isSticky() || !record->event.pressed)
		return true;

	switch (keycode)
	{
		case KC_ESC:
			// FALL THRU
		case KC_ENT:
			if (isSticky())
			{
				unstickAll();
				return false;
			}
			break;
	}

	return true;
}

void stick(uint16_t mods[], uint8_t size)
{
	unstickAll();

	for (int i = 0; i < size; i++)
		press(mods[i]);

	memcpy(stickyMods, mods, size * sizeof(uint16_t));
}

void unstickAll(void)
{
	for (int i = 0; i < MODS_MAX && stickyMods[i] > 0; i++)
		release(stickyMods[i]);

	memset(stickyMods, 0, sizeof(stickyMods));
}


#include "vim.h"
#include "mods.h"

uint16_t vimQueue = KC_NO;

bool vim_process_record_user(uint16_t keycode, keyrecord_t *record)
{
	if (!record->event.pressed)
		return true;

	switch (keycode)
	{
		case VIM_I:
			vim_i();
			return false;

		case VIM_ESC:
			clearVimQueue();
			return false;

		case VIM_B:
			switch(vimQueue)
			{
				case KC_NO:
					isShiftOn
						? vim_B()
						: vim_b();
					break;

				case VIM_D:
					vim_db();
					break;
			}
			return false;

		case VIM_D:
			switch(vimQueue)
			{
				case KC_NO:
					isShiftOn
						? vim_D()
						: addToVimQueue(VIM_D);
					break;

				case VIM_D:
					vim_dd();
					break;
			}
			return false;

		case VIM_W:
			switch(vimQueue)
			{
				case KC_NO:
					isShiftOn
						? vim_W()
						: vim_w();
					break;

				case VIM_D:
					vim_dw();
					break;
			}
			return false;

	}

	return true;
}

void addToVimQueue(uint16_t keycode)
{
	vimQueue = keycode;
}

void clearVimQueue(void)
{
	vimQueue = KC_NO;
}

void vim_b(void)
{
	tap(OPT(KC_LEFT));
}

void vim_B(void)
{
	tap(OPT(KC_LEFT));
}

void vim_db(void)
{
	tap(OPT(KC_BSPC));
	clearVimQueue();
}

void vim_dd(void)
{
	tap(CMD(KC_RIGHT));
	tap(CMD(KC_BSPC));
	clearVimQueue();
}

void vim_dw(void)
{
	tap(OPT(KC_DEL));
	clearVimQueue();
}

void vim_D(void)
{
	tap(CMD(KC_DEL));
}

void vim_i(void)
{
	layer_off(Vimode);
}

void vim_w(void)
{
	tap(OPT(KC_RIGHT));
}

void vim_W(void)
{
	tap(OPT(KC_RIGHT));
}

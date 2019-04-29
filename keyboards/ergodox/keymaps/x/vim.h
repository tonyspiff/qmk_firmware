/* *
 * X - A dvorak based, vim inspired keymap for ergodox keyboards
 * http://www.keyboard-layout-editor.com/#/gists/67569b26aa9c30d3e6fde64dd48e9696
 *
 * vim.h - inspired by: https://github.com/qmk/qmk_firmware/blob/master/keyboards/ergodox_ez/keymaps/vim/vim.h
 */
#ifndef VIM_X_H
#define VIM_X_H

#define press(keycode) register_code16(keycode)
#define release(keycode) unregister_code16(keycode)

LEADER_EXTERNS();

void tap(uint16_t keycode)
{
	tap_code16(keycode);

	leading = false;
}

void cmd(uint16_t keycode) 
{
	press(KC_LGUI);
	tap(keycode);
	release(KC_LGUI);
}

void ctrl(uint16_t keycode) 
{
	press(KC_LCTRL);
	tap(keycode);
	release(KC_LCTRL);
}

void shift(uint16_t keycode) 
{
	press(KC_LSHIFT);
	tap(keycode);
	release(KC_LSHIFT);
}

void option(uint16_t keycode) 
{
	press(KC_LALT);
	tap(keycode);
	release(KC_LALT);
}

void cmdShift(uint16_t keycode) 
{
	press(KC_LGUI);
	press(KC_LSHIFT);
	tap(keycode);
	release(KC_LSHIFT);
	release(KC_LGUI);
}

void optionShift(uint16_t keycode) 
{
	press(KC_LALT);
	press(KC_LSHIFT);
	tap(keycode);
	release(KC_LSHIFT);
	release(KC_LALT);
}

void ctrlShift(uint16_t keycode) 
{
	press(KC_LCTRL);
	press(KC_LSHIFT);
	tap(keycode);
	release(KC_LSHIFT);
	release(KC_LCTRL);
}

void cmdCtrl(uint16_t keycode) 
{
	press(KC_LGUI);
	press(KC_LCTRL);
	tap(keycode);
	release(KC_LCTRL);
	release(KC_LGUI);
}

#endif

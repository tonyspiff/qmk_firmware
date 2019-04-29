#include "config.h"
#include "keycode.h"

#define press(keycode) register_code(keycode)
#define release(keycode) unregister_code(keycode)

void tap(uint16_t keycode)
{
    press(keycode);
    release(keycode);
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


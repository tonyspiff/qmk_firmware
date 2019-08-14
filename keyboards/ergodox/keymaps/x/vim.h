/* *
 * X - A dvorak based, vim inspired keymap for ergodox keyboards
 * http://www.keyboard-layout-editor.com/#/gists/67569b26aa9c30d3e6fde64dd48e9696
 *
 * vim.h - inspired by: https://github.com/qmk/qmk_firmware/blob/master/keyboards/ergodox_ez/keymaps/vim/vim.h
 */
#ifndef VIM_X_H
#define VIM_X_H

LEADER_EXTERNS();

#define KC_SUPR (QK_LCTL | QK_LALT | QK_LGUI)
#define SUPR(kc) (QK_LCTL | QK_LALT | QK_LGUI | (kc))

#define press(keycode) register_code16(keycode)
#define release(keycode) unregister_code16(keycode)

static uint16_t previousKeycode = 0;

inline void tap(uint16_t code);
void tap(uint16_t code)
{
	previousKeycode = code;
	tap_code16(code);
	leading = false;
}

#if defined(UNICODE_ENABLE)
inline void tapUnicode(uint16_t code);
void tapUnicode(uint16_t code)
{
	unicode_input_start();
	register_hex(code);
	unicode_input_finish();
	leading = false;
}
#endif

inline void repeatTap(void);
void repeatTap()
{
	if (previousKeycode == 0)
		return;

	tap(previousKeycode);
}

#endif


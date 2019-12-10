/* *
 * X - A dvorak based, vim inspired keymap for ergodox keyboards
 * http://www.keyboard-layout-editor.com/#/gists/67569b26aa9c30d3e6fde64dd48e9696
 *
 * vim.h - inspired by: https://github.com/qmk/qmk_firmware/blob/master/keyboards/ergodox_ez/keymaps/vim/vim.h
 */
#ifndef VIM_X_H
#define VIM_X_H

#include QMK_KEYBOARD_H

bool vim_process_record_user(uint16_t keycode, keyrecord_t *record);
void addToVimQueue(uint16_t keycode);
void clearVimQueue(void);
bool processQueue(bool isPressed);

extern bool isVimodeOn;

#endif


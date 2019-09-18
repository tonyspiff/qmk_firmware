/* *
 * X - A dvorak based, vim inspired keymap for ergodox keyboards
 * http://www.keyboard-layout-editor.com/#/gists/67569b26aa9c30d3e6fde64dd48e9696
 *
 * Tap Helpers
 */
#ifndef TAP_X_H
#define TAP_X_H

#define press(keycode) register_code16(keycode)
#define release(keycode) unregister_code16(keycode)
#define tap(keycode) tap_code16(keycode)

#endif


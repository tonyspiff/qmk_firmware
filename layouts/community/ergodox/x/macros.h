#ifndef MACROS_X_H
#define MACROS_X_H

#include QMK_KEYBOARD_H

extern bool isCmdTabOn;
bool macros_process_record_user(uint16_t keycode, keyrecord_t *record);

#endif


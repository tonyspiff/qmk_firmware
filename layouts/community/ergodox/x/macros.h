#ifndef MACROS_H
#define MACROS_H

#include QMK_KEYBOARD_H

bool isCmdTabOn;
bool macros_process_record_user(uint16_t keycode, keyrecord_t *record);

#endif


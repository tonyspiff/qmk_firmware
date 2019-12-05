#ifndef MACROS_X_H
#define MACROS_X_H

#include QMK_KEYBOARD_H

bool macros_process_record_user(uint16_t keycode, keyrecord_t *record);

void stick(uint16_t mods[], uint8_t size);
void unstickAll(void);

#endif


#ifndef LEADING_X_H
#define LEADING_X_H

#include "tap.h"
#include "macros.h"
#include "layers.h"

LEADER_EXTERNS();

extern void startSymbolLeading(void);
extern void endLeading(void);
extern void process_leading_sequence(void);

void tapL(uint16_t code);
void repeatTapL(void);

#if defined(UNICODE_ENABLE)
void tapUnicodeL(uint16_t code);
#endif

#endif


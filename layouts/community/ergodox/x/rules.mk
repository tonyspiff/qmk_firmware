# This enables Link Time Optimization
EXTRAFLAGS += -flto

LEADER_ENABLE = yes
MOUSEKEY_ENABLE = no
COMMAND_ENABLE = no
TAP_DANCE_ENABLE = yes

SRC += $(KEYMAP_PATH)/macros.c
SRC += $(KEYMAP_PATH)/leading.c
SRC += $(KEYMAP_PATH)/vim.c


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

#define bindFirstSequence(key, cmd) if (leader_sequence[0] == (key)) { cmd; }
#define bindFirstSequenceTwo(key1, key2, cmd) if (leader_sequence[0] == (key1) && leader_sequence[1] == (key2)) { cmd; }
#define bindFirstSequenceThree(key1, key2, key3, cmd) if (leader_sequence[0] == (key1) && leader_sequence[1] == (key2) && leader_sequence[2] == (key3)) { cmd; }
#define bindFirstSequenceFour(key1, key2, key3, key4, cmd) if (leader_sequence[0] == (key1) && leader_sequence[1] == (key2) && leader_sequence[2] == (key3) && leader_sequence[3] == (key4)) { cmd; }
#define bindFirstSequenceFive(key1, key2, key3, key4, key5, cmd) if (leader_sequence[0] == (key1) && leader_sequence[1] == (key2) && leader_sequence[2] == (key3) && leader_sequence[3] == (key4) && leader_sequence[4] == (key5)) { cmd; }
#define bindFirstSequenceTwoTwo(key1, key2, cmd1, cmd2) if (leader_sequence[0] == (key1) && leader_sequence[1] == (key2)) { cmd1; cmd2; }

#define bindSequence(key, cmd) else bindFirstSequence(key, cmd)
#define bindSequenceTwo(key1, key2, cmd) else bindFirstSequenceTwo(key1, key2, cmd)
#define bindSequenceThree(key1, key2, key3, cmd) else bindFirstSequenceThree(key1, key2, key3, cmd)
#define bindSequenceFour(key1, key2, key3, key4, cmd) else bindFirstSequenceFour(key1, key2, key3, key4, cmd)
#define bindSequenceFive(key1, key2, key3, key4, key5, cmd) else bindFirstSequenceFive(key1, key2, key3, key4, key5, cmd)
#define bindSequenceTwoTwo(key1, key2, cmd1, cmd2) else bindFirstSequenceTwoTwo(key1, key2, cmd1, cmd2)

void tap(uint16_t code);
void repeatLastCommand(void);
void cancelLeading(void);

static uint16_t previousKeycode = 0;

void tap(uint16_t code)
{
	previousKeycode = code;
	tap_code16(code);
	leading = false;
}

void repeatLastCommand()
{
	if (previousKeycode == 0)
		return;

	tap(previousKeycode);
}

void cancelLeading()
{
	leading = false;
}

#endif


#pragma once

#define VIAL_KEYBOARD_UID {0x61, 0x81, 0x85, 0xD0, 0x4F, 0x0A, 0xB7, 0x01}

// Top row, outer key + inner key on the USB half's own side, so unlocking works with one half alone
#ifdef INIT_EE_HANDS_RIGHT
#    define VIAL_UNLOCK_COMBO_ROWS {5, 5}
#else
#    define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#endif
#define VIAL_UNLOCK_COMBO_COLS {0, 5}

// Copyright 2018-2020
// ENDO Katsuhiro <ka2hiro@curlybracket.co.jp>
// David Philip Barr <@davidphilipbarr>
// Pierre Chevalier <pierrechevalier83@gmail.com>
// SPDX-License-Identifier: GPL-2.0+

#include "quantum.h"

#ifdef SWAP_HANDS_ENABLE
__attribute__ ((weak))
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    // Left
    {{4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
    {{4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5}},
    {{4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}},
    {{1, 7}, {0, 7}, {2, 7}, {3, 7}, {4, 7}},
    // Right
    {{4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
    {{4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
    {{4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
    {{1, 3}, {0, 3}, {2, 3}, {3, 3}, {4, 3}}
};
#endif

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

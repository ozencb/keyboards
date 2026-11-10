#include QMK_KEYBOARD_H

enum layers { _QWERTY, _LOWER, _RAISE, _ADJUST };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_LCTL, KC_LALT, KC_LGUI, TL_LOWR, KC_ENT,  KC_SPC,  TL_UPPR, KC_RGUI, KC_RALT, KC_RCTL
    ),
    [_LOWER] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR,          KC_LBRC, KC_RBRC, KC_UNDS, KC_COLN, KC_BSLS, _______,
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX, KC_DEL,
        _______, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_CAPS,          KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_BSPC,
        _______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        QK_RBT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, QK_RBT,
        EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, EE_CLR,
        NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_BRID, XXXXXXX, KC_BRIU, XXXXXXX, NK_TOGG,
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

// Bootmagic key (outer top key of each half, held while plugging in) only enters the bootloader; keep the Vial keymap
void bootmagic_reset_eeprom(void) {}

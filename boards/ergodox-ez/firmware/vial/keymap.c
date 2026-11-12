// keymaps[] generated from ../vial.vil by shared/tools/vil-to-keymap.py. Vial edits live in EEPROM; this is the reset default.
#include QMK_KEYBOARD_H
#include "i18n.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = {
        {KC_ESCAPE, KC_TAB, KC_CAPS_LOCK, KC_LEFT_SHIFT, KC_NO, KC_NO},
        {KC_1, KC_Q, KC_A, KC_Z, KC_NO, KC_NO},
        {KC_2, KC_W, LT(3, KC_S), KC_X, KC_LEFT_CTRL, KC_BACKSPACE},
        {KC_3, KC_E, LT(2, KC_D), KC_C, KC_LALT, KC_SPACE},
        {KC_4, KC_R, LT(1, KC_F), KC_V, KC_LGUI, KC_NO},
        {KC_5, KC_T, KC_G, KC_B, KC_NO, KC_NO},
        {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
        {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
        {KC_6, KC_Y, KC_H, KC_N, KC_NO, KC_NO},
        {KC_7, KC_U, LT(1, KC_J), KC_M, KC_RGUI, KC_NO},
        {KC_8, KC_I, LT(2, KC_K), KC_COMMA, KC_RALT, KC_ENTER},
        {KC_9, KC_O, LT(3, KC_L), KC_DOT, KC_RIGHT_CTRL, KC_DELETE},
        {KC_0, KC_P, KC_SEMICOLON, KC_SLASH, KC_NO, KC_NO},
        {KC_MINUS, KC_KP_PLUS, KC_QUOTE, KC_RIGHT_SHIFT, KC_NO, KC_NO},
    },
    [1] = {
        {KC_F1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
        {KC_F2, KC_TRNS, KC_TRNS, KC_NONUS_BACKSLASH, KC_TRNS, KC_TRNS},
        {KC_F3, KC_TRNS, KC_SEMICOLON, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_F4, KC_TRNS, KC_TRNS, KC_DOT, KC_TRNS, KC_TRNS},
        {KC_F5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_F6, KC_TRNS, KC_LEFT_BRACKET, KC_TRNS, KC_NO, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_TRNS},
        {KC_F7, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS},
        {KC_F8, KC_RIGHT_BRACKET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_F9, KC_I, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_F10, KC_COMMA, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_F11, KC_TRNS, KC_TRNS, KC_NONUS_HASH, KC_TRNS, KC_TRNS},
        {KC_F12, KC_DELETE, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
    },
    [2] = {
        {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
        {KC_TRNS, KC_GRAVE, LSFT(KC_GRAVE), KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_TRNS, LSFT(KC_LEFT_BRACKET), KC_SEMICOLON, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_LEFT_BRACKET, KC_BACKSLASH, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_RIGHT_BRACKET, KC_EQUAL, LSFT(KC_BACKSLASH), KC_TRNS, KC_TRNS},
        {KC_TRNS, LSFT(KC_RIGHT_BRACKET), KC_LEFT_BRACKET, KC_TRNS, KC_NO, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_TRNS},
        {KC_TRNS, LALT(KC_LEFT), KC_LEFT, KC_HOME, KC_NO, KC_TRNS},
        {KC_TRNS, KC_RIGHT_BRACKET, KC_DOWN, KC_PAGE_DOWN, KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_I, KC_UP, KC_PGUP, KC_TRNS, KC_TRNS},
        {KC_TRNS, LALT(KC_RIGHT), KC_RIGHT, KC_END, KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
    },
    [3] = {
        {QK_BOOT, QK_REBOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
        {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_WH_U, KC_MS_L, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_MS_U, KC_MS_D, KC_TRNS, KC_TRNS, KC_BTN1},
        {KC_TRNS, KC_WH_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS},
        {KC_TRNS, KC_MPRV, KC_VOLD, KC_BRID, KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_MPLY, KC_MUTE, KC_TRNS, KC_TRNS, KC_BTN2},
        {KC_TRNS, KC_MNXT, KC_VOLU, KC_BRIU, KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
        {QK_BOOT, QK_REBOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO},
    },
};

layer_state_t layer_state_set_user(layer_state_t state) {
    static const uint8_t leds[8] = {0, 1, 2, 4, 3, 5, 6, 7}; // bit0 = LED 1, bit1 = LED 2, bit2 = LED 3, as in Oryx
    uint8_t m = leds[get_highest_layer(state) & 7];
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    if (m & 1) ergodox_right_led_1_on();
    if (m & 2) ergodox_right_led_2_on();
    if (m & 4) ergodox_right_led_3_on();
    return state;
}

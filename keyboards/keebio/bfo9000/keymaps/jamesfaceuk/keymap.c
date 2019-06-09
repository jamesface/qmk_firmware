#include QMK_KEYBOARD_H

// #define _BASE 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_NO, KC_NO, KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, SCMD(LALT(KC_L)), KC_DEL, KC_MPLY, KC_P7, KC_P8, KC_P9, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC__VOLUP, KC_P4, KC_P5, KC_P6, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC__VOLDOWN, KC_P1, KC_P2, KC_P3, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_ENT, KC_MFFD, KC_NO, KC_UP, KC_P0, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_NO, KC_UP, KC_MRWD, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_RGUI, KC_RALT, KC_RCTL, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT),
	[1] = LAYOUT(KC_ESC, KC_E, KC_S, KC_C, KC_V, KC_X, KC_NO, LSFT(KC_SLSH), KC_MINS, KC_1, KC_7, LSFT(KC_E), LSFT(KC_S), LSFT(KC_C), LSFT(KC_V), LSFT(KC_X), KC_NO, KC_NO, KC_SPC, KC_T, KC_H, KC_M, KC_B, KC_Z, KC_NO, KC_NO, KC_NO, KC_2, KC_8, LSFT(KC_T), LSFT(KC_H), LSFT(KC_M), LSFT(KC_B), LSFT(KC_Z), KC_NO, KC_NO, KC_SPC, KC_A, KC_R, KC_F, KC_G, KC_NO, KC_COMM, LSFT(KC_9), LSFT(KC_0), KC_3, KC_9, LSFT(KC_A), LSFT(KC_R), LSFT(KC_F), LSFT(KC_G), LSFT(KC_2), KC_ENT, KC_ENT, KC_SPC, KC_O, KC_D, KC_W, KC_K, KC_NO, KC_DOT, LSFT(KC_BSLS), KC_TAB, KC_4, KC_0, LSFT(KC_O), LSFT(KC_D), LSFT(KC_W), LSFT(KC_K), KC_NO, KC_NO, KC_NO, TO(0), KC_I, KC_L, KC_Y, KC_Q, KC_NO, LSFT(KC_SCLN), KC_GRV, KC_QUOT, KC_5, LSFT(KC_4), LSFT(KC_I), LSFT(KC_L), LSFT(KC_Y), LSFT(KC_Q), LSFT(KC_7), KC_NO, KC_NO, KC_NO, KC_N, KC_U, KC_P, KC_J, KC_NO, KC_SCLN, LSFT(KC_1), LSFT(KC_8), LSFT(KC_6), KC_NO, LSFT(KC_N), LSFT(KC_U), LSFT(KC_P), LSFT(KC_J), LALT(KC_MINS), KC_NO, KC_NO)
};

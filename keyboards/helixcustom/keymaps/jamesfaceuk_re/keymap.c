#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif
#ifdef CONSOLE_ENABLE
  #include <print.h>
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _FUNCTION,
    _ILLUSTRATOR,
    _ADJUST,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  FUNCTION,
  ILLUSTRATOR,
  ADJUST,
};

#if HELIX_ROWS == 5
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |  BS  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  | Ctrl |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   `  |   '  |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Lower | Lower| Caps |  Alt |  GUI | Space|  BS  | Enter| Space| GUI  | Alt  | Menu |Lower |Lower |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_GRV, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_SPC, KC_SPC, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_RSPC, MO(1), TT(2), MO(3), KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_SPC, KC_RGUI, KC_RALT, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT),

  /* Function
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   F  |   P  |   G  |             |   J  |   L  |   U  |   Y  |   ;  | \    |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   R  |   S  |   T  |   D  |             |   H  |   N  |   E  |   I  |   O  | Ctrl |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   `  |   '  |   K  |   M  |   ,  |   .  |   /  | Shift|
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Lower | Lower| Caps |  Alt |  GUI | Space|  BS  | Enter| Space| GUI  | Alt  | Menu |Lower |Lower |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_FUNCTION] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_MPLY, KC_TRNS, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_PSLS, KC__VOLDOWN, KC__MUTE, KC__VOLUP, KC_MINS, KC_EQL, SCMD(LALT(KC_L)), KC_TRNS, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PAST, KC_MRWD, KC_MPLY, KC_MFFD, KC_TRNS, KC_QUOT, KC_TRNS, KC_TRNS, KC_P1, KC_P2, KC_P3, KC_PENT, KC_PEQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_PDOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /* Illustrator
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   '  |   ,  |   .  |   P  |   Y  |             |   F  |   G  |   C  |   R  |   L  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   O  |   E  |   U  |   I  |             |   D  |   H  |   T  |   N  |   S  | Ctrl |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   ;  |   Q  |   J  |   K  |   X  |   `  |   /  |   B  |   M  |   W  |   V  |   Z  | Shift|
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Lower | Lower| Caps |  Alt |  GUI | Space|  BS  | Enter| Space| GUI  | Alt  | Menu |Lower |Lower |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ILLUSTRATOR] = LAYOUT(KC_TRNS, LGUI(KC_7), LGUI(LALT(KC_7)), KC_MINS, KC_EQL, KC_BSPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, LGUI(KC_C), LGUI(KC_F), KC_I, KC_UP, KC_T, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ENT, KC_A, LGUI(KC_S), KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, LGUI(KC_Z), KC_X, KC_M, KC_V, KC_BSLS, TG(2), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

  /* Eucalyn (http://eucalyn.hatenadiary.jp/entry/about-eucalyn-layout)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   ,  |   .  |   ;  |             |   M  |   R  |   D  |   Y  |   P  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   O  |   E  |   I  |   U  |             |   G  |   T  |   K  |   S  |   N  | Ctrl |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   F  |   `  |   '  |   B  |   H  |   J  |   L  |   /  | Shift|
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Lower | Lower| Caps |  Alt |  GUI | Space|  BS  | Enter| Space| GUI  | Alt  | Menu |Lower |Lower |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT(KC_NO, BL_STEP, KC_NO, BL_DEC, BL_INC, BL_BRTG, RGB_M_B, RGB_RMOD, RGB_MOD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_HUD, RGB_HUI, RGB_M_B, RGB_M_P, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_SAD, RGB_SAI, RGB_M_K, RGB_M_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_VAD, RGB_VAI, RGB_M_SW, RGB_M_SN, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, BL_TOGG, RGB_TOG, KC_NO, RGB_SPD, RGB_SPI, RGB_M_G, RGB_M_X, KC_NO)
};

#else
#error "undefined keymaps"
#endif


void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}


#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
}

void shutdown_user()
{
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif


#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
      // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (biton32(layer_state)) {
      case _FUNCTION:
        oled_write_P(PSTR("Function\n"), false);
        break;
      case _ILLUSTRATOR:
        oled_write_P(PSTR("Ai\n"), false);
        break;
      case _ADJUST:
        oled_write_P(PSTR("Adjust\n"), false);
        break;
      default:
        // Or use the write_ln shortcut over adding '\n' to the end of your string
        oled_write_ln_P(PSTR("Ya Basic\n"), false);
    }
    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
  } else {
      render_logo();       // Renders a static logo
     // oled_scroll_left();  // Turns on scrolling
  }
}
#endif

static bool tabbing = false;
static uint16_t tabtimer;
#define TABBING_TIMER 500

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    switch (biton32(layer_state)) {
      case _FUNCTION:
         if (clockwise) {
              tap_code(KC__VOLUP);
            } else {
              tap_code(KC__VOLDOWN);
            }
      break;
      case _ILLUSTRATOR:
         if (clockwise) {
              tap_code16(LGUI(KC_EQL));
            } else {
              tap_code16(LGUI(KC_MINS));
            }
      break;
      case _ADJUST:
         if (clockwise) {
            rgblight_step();
            } else {
            rgblight_step_reverse();
            }
      break;
      default:
        if (clockwise) {
            tabtimer = timer_read();
            if(!tabbing) {
                register_code(KC_LGUI);
                tabbing = true;
            }
            tap_code(KC_TAB);
        } else {
            tabtimer = timer_read();
            if(!tabbing) {
                register_code(KC_LGUI);
                tabbing = true;
            }
            register_code(KC_LSFT);
            tap_code(KC_TAB);
            unregister_code(KC_LSFT);
        }
    }
  } else if (index == 1) { /* Second encoder, clockwise is backwards */
    switch (biton32(layer_state)) {
      case _FUNCTION:
         if (clockwise) {
              tap_code(KC_MRWD);
            } else {
              tap_code(KC_MFFD);
            }
      break;
      case _ILLUSTRATOR:
         if (clockwise) {
              tap_code16(LGUI(KC_MINS));
            } else {
              tap_code16(LGUI(KC_EQL));
            }
      break;
      case _ADJUST:
         if (clockwise) {
            rgblight_decrease_sat();
            } else {
            rgblight_increase_sat();
            }
      break;
      default:
    if (clockwise) {
      tap_code(KC_BSPC);
    } else {
      tap_code(KC_DEL);
    }
    }
  }
}

void matrix_scan_user(void) {
  if(tabbing) {
    if (timer_elapsed(tabtimer) > TABBING_TIMER) {
      unregister_code(KC_LGUI);
      tabbing = false;
    }
  }
}

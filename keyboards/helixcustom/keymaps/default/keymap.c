/* Copyright 2019 Michael Shultz
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user

extern uint8_t is_master;

bool mouse_off = true;
bool os_undo(void);
bool os_redo(void);

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.


enum layer_number {
    _COLEMAK = 0,
    _COLEMAC,
    _QWERTY,
    _TEX,
    _NAV,
    _MNAV,
    _SYM,
    _NUM,
    _ADJUST,
    _AUDIO,
    _MOUSE,
    _MWIN,
    _MEDIA
};

enum custom_keycodes {
  ALIGN = SAFE_RANGE,
  ARRAY,
  CLK_TOG,
  COLEMAC,
  COLEMAK,
  DISPMTH,
  ENUM,
  EPRM,
  ITEM,
  ITEMZ,
  LEFTRGHT,
  LEMMA,
  LINEMTH,
  MEDIA,
  MS_A0,
  MS_A1,
  MS_A2,
  OS_UNDO,
  RGBRST,
  SECTN,
  THEOREM,
  VRSN,
  QWERTY,
};


// Keys that involve layer switching
#define ADJUST MO(_ADJUST)
#define MNAVESC LT(_MNAV,KC_ESC)
#define MACWIN MO(_MWIN)
#define MNAVSPC LT(_MNAV, KC_SPACE)
#define MOUSE TT(_MOUSE)
#define NAVESC LT(_NAV,KC_ESC)
#define NAVSPC LT(_NAV,KC_SPC)
#define SYMENT LT(_SYM,KC_ENT)
#define SYMSPC LT(_SYM,KC_SPC)
#define TEXSPC LT(_TEX,KC_SPC)

// Dual Function Keys
#define CTLSCLN CTL_T(KC_SCLN)
#define CTLSLSH CTL_T(KC_SLSH)
#define GUISCLN GUI_T(KC_SCLN)
#define GUISLSH GUI_T(KC_SLSH)

// Mod combos
#define ALTCTL LCTL(KC_LALT)
#define ALTSHFT S(KC_LALT)

// Navigation
#define ALTLEFT LALT(KC_LEFT)
#define ALTRGHT LALT(KC_RGHT)
#define ALTBSPC LALT(KC_BSPC)
#define ALTDEL LALT(KC_DEL)
#define CTLBSPC LCTL(KC_BSPC)
#define CTLDEL LCTL(KC_DEL)
#define CTLLEFT LCTL(KC_LEFT)
#define CTLRGHT LCTL(KC_RGHT)
#define MACEND LGUI(KC_RIGHT)
#define MACHOME LGUI(KC_LEFT)
#define TABLEFT LCTL(LSFT(KC_TAB))
#define TABRGHT LCTL(KC_TAB)

// Windows specific
#define GUITAB LGUI(KC_TAB)
#define WINMIN LGUI(KC_M)
#define WINQUIT LALT(KC_F4)

// Mac Window Adjustment with magnet
#define MW_CENT LCTL(LALT(KC_F))
#define MW_CSQR LCTL(LALT(KC_C)) 
#define MW_FULL LCTL(LALT(KC_ENT))
#define MW_LEFT LCTL(LALT(KC_LEFT))
#define MW_LLFT LCTL(LALT(KC_J))
#define MW_LOWR LCTL(LALT(KC_DOWN))
#define MW_LRIT LCTL(LALT(KC_K))
#define MW_L13 LCTL(LALT(KC_D))
#define MW_L23 LCTL(LALT(KC_E))
#define MW_RGHT LCTL(LALT(KC_RIGHT))
#define MW_R13 LCTL(LALT(KC_G))
#define MW_R23 LCTL(LALT(KC_T))
#define MW_ULFT LCTL(LALT(KC_U))
#define MW_UPPR LCTL(LALT(KC_UP))
#define MW_URIT LCTL(LALT(KC_I))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*  AUX modifier key layer
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |  BS  | Enter|      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_COLEMAK] = LAYOUT( \
      KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, \
      KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                   KC_J   , KC_L   , KC_U   , KC_Y   , GUISCLN, KC_BSLS, \
      NAVESC , KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,                   KC_K   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT, \
      KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , _______, _______, KC_M   , KC_H   , KC_COMM, KC_DOT , CTLSLSH, KC_RSFT, \
      ADJUST , KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, NAVSPC , KC_SPC , SYMENT , TEXSPC , WINMIN , _______, ALTSHFT, ALTCTL , ADJUST \
      ),

  [_COLEMAC] = LAYOUT( \
      KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, \
      KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                   KC_J   , KC_L   , KC_U   , KC_Y   , CTLSCLN, KC_BSLS, \
      MNAVESC, KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,                   KC_K   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT, \
      KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , _______, _______, KC_M   , KC_H   , KC_COMM, KC_DOT , GUISLSH, KC_RSFT, \
      ADJUST , KC_LCTL, KC_LALT, KC_LGUI, KC_LGUI, MNAVSPC, KC_SPC , SYMENT , TEXSPC , WINMIN , _______, _______, _______, ADJUST \
      ),

  [_NAV] = LAYOUT( \
      _______, _______, _______, _______, WINQUIT, _______,                      _______, _______, _______, _______, _______, _______, \
      _______, _______, LCTL(KC_PGUP), KC_PGUP, LCTL(KC_PGDN), _______,          _______, TABLEFT, KC_UP  , TABRGHT, _______, _______, \
      _______, _______, KC_HOME,    KC_PGDN, KC_END , _______,                   CTLLEFT, KC_LEFT, KC_DOWN, KC_RGHT, CTLRGHT, _______, \
      _______, _______, KC_F2  ,    KC_CAPS, KC_INS , _______, _______, _______, CTLBSPC, KC_BSPC, KC_DEL , CTLDEL , LCTL(KC_0), _______, \
      _______, _______, _______, _______, _______, _______, _______, _______,    KC_ENT , _______, _______, _______, _______, KC_F12 \
      ),

  [_MNAV] = LAYOUT( \
      _______, _______, _______, _______, LGUI(KC_Q), _______,                _______, _______, _______, _______, _______, _______, \
      _______, LGUI(KC_Q), _______, KC_PGUP, _______, _______,                   _______, TABLEFT, KC_UP  , TABRGHT, _______, _______, \
      _______, _______, MACHOME, KC_PGDN, MACEND , _______,                   ALTLEFT, KC_LEFT, KC_DOWN, KC_RGHT, ALTRGHT, _______, \
      MACWIN , _______, _______, KC_CAPS, KC_INS , _______, _______, _______, ALTBSPC, KC_BSPC, KC_DEL , ALTDEL , LCTL(KC_0), _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT , _______, _______, _______, _______, KC_F12 \
      ),

  [_TEX] = LAYOUT( \
      _______, KC_F1  ,  KC_F2  , KC_F3,   KC_F4  , KC_F5  ,                   KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10, KC_F11 , \
      _______, SECTN  , ENUM   , ITEMZ  ,LEFTRGHT, _______,                   _______, KC_LBRC, KC_RBRC, LINEMTH, DISPMTH, KC_F12 , \
      _______, ALIGN  , ARRAY  , _______, ITEM   , _______,                   _______, KC_LCBR, KC_RCBR, S(KC_9), S(KC_0), _______, \
      _______, LEMMA  , THEOREM, _______, _______, _______, _______, _______, KC_MINS, KC_UNDS, S(KC_EQL),KC_EQL, KC_BSLS, _______, \
      _______, _______, _______, _______, _______, SYMSPC , _______, _______, _______, _______, _______, _______, _______, _______ \
      ),

  [_SYM] = LAYOUT( \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
      _______, KC_F1  ,  KC_F2  , KC_F3,   KC_F4  , KC_F5  ,                   KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11, \
      KC_TILD, KC_EXLM,  KC_AT  , KC_HASH, KC_DLR , KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12, \
      KC_GRV , KC_1   ,  KC_2   , KC_3   , KC_4   , KC_5   , _______, _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
      ),

  [_ADJUST] =  LAYOUT( \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, RGBRST, _______, \
      _______, RGB_TOG, RGB_VAD, RGB_HUI, RGB_VAI, RGB_SAI,                   RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, _______, RESET  , \
      _______, _______,RGB_RMOD, RGB_HUD, RGB_MOD, RGB_SAD,                   RGB_HUD, RGB_SAD, RGB_VAD,RGB_RMOD, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, COLEMAK, _______, _______, COLEMAC, _______, _______, _______, _______, _______ \
   ),

/*
  [16] = LAYOUT_kc( \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
      ),
*/

};


#ifdef AUDIO_ENABLE

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif

bool TOG_STATUS = false;

int os_status = 0;

bool os_undo(void) {
  if (os_status == 1) {
    register_code(KC_LGUI);
    tap_code(KC_Z);
    unregister_code(KC_LGUI);
  } else {
    register_code(KC_LCTL);
    tap_code(KC_Z);
    unregister_code(KC_LCTL);
  }
  return false;  
}

bool os_redo(void) {
  if (os_status == 1) {
    register_code(KC_LSFT);
    register_code(KC_LGUI);
    tap_code(KC_Z);
    unregister_code(KC_LGUI);
    unregister_code(KC_LSFT);
  } else {
    register_code(KC_LSFT);
    register_code(KC_LCTL);
    tap_code(KC_Z);
    unregister_code(KC_LCTL);
    unregister_code(KC_LSFT);
  }
  return false;  
}

int _os(void) {
  return os_status;
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      //rgblight_mode(RGB_current_mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_puzzle);
        #endif
        os_status = _COLEMAK;
      }
      break;
    case COLEMAC:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAC);
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_treasure);
        #endif
        os_status = _COLEMAC;
      }
      break;
    case MS_A0:
      if (record->event.pressed) {
        #ifdef MOUSEKEY_ENABLE
          unregister_code(KC_ACL1);
          unregister_code(KC_ACL2);
          register_code(KC_ACL0);
        #endif
      }
      break;
    case MS_A1:
      if (record->event.pressed) {
        #ifdef MOUSEKEY_ENABLE
          unregister_code(KC_ACL0);
          unregister_code(KC_ACL2);
          register_code(KC_ACL1);
        #endif
      }
    case MS_A2:
      if (record->event.pressed) {
        #ifdef MOUSEKEY_ENABLE
          unregister_code(KC_ACL0);
          unregister_code(KC_ACL1);
          register_code(KC_ACL2);
        #endif
      }
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      break;

    // Toggles left click on mouse. I use this with
    // rotary encoders to do an etch-a-sketch type thing
    case CLK_TOG:
      if (record->event.pressed) {
        if (mouse_off) {
          register_code(KC_BTN1);
        } else {
          unregister_code(KC_BTN1);
          }
      } else {
        mouse_off = !mouse_off;
        }
      break;
  /*
    case EPRM:  
      if (record->event.pressed) {
        eeconfig_init();
      }
      break;
  */
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
    
    // Various macros for use when writing in LaTeX
    case ALIGN:
      if (record->event.pressed)
      {
        SEND_STRING("\\begin{align*}" SS_TAP(X_ENTER) SS_TAP(X_ENTER) "\\end{align*}" SS_TAP(X_UP) SS_TAP(X_TAB));
      }
      break;
    case ARRAY:
      if (record->event.pressed)
      {
        SEND_STRING("\\begin{array}{c c}"SS_TAP(X_ENTER) SS_TAP(X_ENTER) "\\end{array}" SS_TAP(X_UP) SS_TAP(X_TAB));
      }
      break;
    case DISPMTH:
      if (record->event.pressed)
      {  
        SEND_STRING("\\[" SS_TAP(X_ENTER) SS_TAP(X_ENTER)"\\]" SS_TAP(X_UP) SS_TAP(X_TAB));
      }
      break;
    case ENUM:
      if (record->event.pressed)
      {
        SEND_STRING("\\begin{enumerate}" SS_TAP(X_ENTER) SS_TAP(X_ENTER) "\\end{enumerate}" SS_TAP(X_UP) SS_TAP(X_TAB) "\\item ");
      }
      break;
    case ITEM:
      if (record->event.pressed)
      {
        SEND_STRING("\\item");
      }
      break;
    case ITEMZ:
      if (record->event.pressed)
      {
        SEND_STRING("\\begin{itemize}"SS_TAP(X_ENTER) SS_TAP(X_ENTER) "\\end{itemize}" SS_TAP(X_UP) SS_TAP(X_TAB) "\\item ");
      }
      break;
    case LEFTRGHT:
      if (record->event.pressed)
      {
        SEND_STRING("\\left(  \\right)" SS_LCTRL(SS_TAP(X_LEFT) SS_TAP(X_LEFT)) SS_TAP(X_LEFT));   
      }
      break;
    case LEMMA:
      if (record->event.pressed) {
        SEND_STRING("\\begin{lemma}[]"SS_TAP(X_ENTER)SS_TAP(X_ENTER)"\\end{lemma}"SS_TAP(X_UP)SS_TAP(X_TAB));
      }
      break;
    case LINEMTH:
      if (record->event.pressed)
      {
        SEND_STRING("\\(\\)" SS_TAP(X_LEFT) SS_TAP(X_LEFT) "   " SS_TAP(X_LEFT));
      }
      break; 
    case SECTN:
      if (record->event.pressed)
      {
        SEND_STRING("\\section{}"SS_TAP(X_LEFT));
      }
      break;
    case THEOREM:
      if (record->event.pressed) {
        SEND_STRING("\\begin{theorem}[]"SS_TAP(X_ENTER)SS_TAP(X_ENTER)"\\end{theorem}"SS_TAP(X_UP)SS_TAP(X_TAB));
      }
      break;
    }
  return true;
}



#ifdef ENCODER_ENABLE
  void encoder_update_user(uint8_t index, bool clockwise) {
    // LEFT KNOB
    if (index == 0) {
    // NAV LAYER
      if (IS_LAYER_ON(_NAV) | IS_LAYER_ON(_MNAV)) {
        if (clockwise) {
          tap_code(KC_TAB);
        } else {
            register_code(KC_LSFT);
            tap_code(KC_TAB);
            unregister_code(KC_LSFT);
          }
      }
  //  MOUSE LAYER
      else if (IS_LAYER_ON(_MOUSE)) {
        if (clockwise) {
          tap_code(KC_MS_D);
        } else {
          tap_code(KC_MS_U);
          }
      }
    // TEX Layer
      else if (IS_LAYER_ON(_TEX)) {
        if (clockwise) {
          os_redo();
        }
        else {
          os_undo();
        }
      }
    // ADJUST layer
      else if (IS_LAYER_ON(_ADJUST)) {
        if (clockwise) {
          tap_code(KC_VOLU);
        }
        else {
          tap_code(KC_VOLD);
        }
      }
      // DEFAULT
      else {
        if (clockwise) {
          tap_code(KC_DOWN);
        } else {
          tap_code(KC_UP);
          }
      }
    }
  // RIGHT KNOB    
    else if (index == 1) {
  //  NAV LAYER
      if (IS_LAYER_ON(_NAV) | IS_LAYER_ON(_MNAV)) {
        if (clockwise) {
          tap_code(KC_PGDN);
        } else {
          tap_code(KC_PGUP);
          }
      }
  //  MOUSE LAYER
      else if (IS_LAYER_ON(_MOUSE)) {
        if (clockwise) {
          tap_code(KC_MS_R);
        } else {
          tap_code(KC_MS_L);
          }
      }
      // Symbol layer
      else if (IS_LAYER_ON(_SYM)) {
        if (clockwise) {
          tap_code(KC_SPC);
        } else {
          tap_code(KC_BSPC);
          }
      }
      // Adjust layer
      else if (IS_LAYER_ON(_ADJUST)) {
        if (clockwise) {
          tap_code(KC_MPRV);
        }
        else
          tap_code(KC_MNXT);
      }
      // Media layer
      else if (IS_LAYER_ON(_MEDIA)) {
        if (clockwise) {
          tap_code(KC_MNXT);
        }
        else {
          tap_code(KC_MPRV);
        }
      }
  // DEFAULT
      else {      
        if (clockwise) {
          tap_code(KC_RGHT);
        } else {
          tap_code(KC_LEFT);
      }
      }
    }
  }
#endif


void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
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
      case _COLEMAK:
        oled_write_P(PSTR("Colemak\n"), false);
        break;
      case _COLEMAC:
        oled_write_P(PSTR("Colemak OSX\n"), false);
        break;
      case _NAV:
        oled_write_P(PSTR("Nav\n"), false);
        break;
      case _MNAV:
        oled_write_P(PSTR("Nav OSX\n"), false);
        break;
      case _TEX:
        oled_write_P(PSTR("LaTeX\n"), false);
        break;
      case _SYM:
        oled_write_P(PSTR("Symbol\n"), false);
        break;
      case _ADJUST:
        oled_write_P(PSTR("Adjust\n"), false);
        break;
      default:
        // Or use the write_ln shortcut over adding '\n' to the end of your string
        oled_write_ln_P(PSTR("Undefined"), false);
    }
    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
  } else {
      render_logo();       // Renders a statuc logo
      oled_scroll_left();  // Turns on scrolling
  }
}
#endif
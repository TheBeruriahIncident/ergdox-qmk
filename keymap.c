#include QMK_KEYBOARD_H
#include "version.h"

#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)

enum layers {
    COLEMAK_DHM,  // default layer
    HEBREW_ARKAN,
    QWERTY_GAMING,
    SYMBOLS,
    MEDIA,
};

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  HSV_86_255_128,
  HSV_172_255_255,
  HSV_27_255_255,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK_DHM] = LAYOUT_ergodox_pretty(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_LEFT,                                        KC_RIGHT,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_DELETE,      KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           TG(HEBREW_ARKAN),                               TG(SYMBOLS),    KC_J,           KC_L,           KC_U,           KC_Y,           LT(MEDIA,KC_SCOLON),KC_BSLASH,
    KC_BSPACE,      KC_A,           KC_R,           KC_S,           KC_T,           KC_G,                                                                           KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           MT(MOD_LGUI, KC_QUOTE),
    KC_LSHIFT,      MT(MOD_LCTL, KC_Z),KC_X,        KC_C,           KC_D,           KC_V,           KC_HYPR,                                        KC_MEH,         KC_K,           KC_H,           KC_COMMA,       KC_DOT,         MT(MOD_RCTL, KC_SLASH),KC_RSHIFT,
    LT(SYMBOLS,KC_GRAVE), KC_QUOTE, CAPS_WORD,      KC_LEFT,        KC_BSPACE,                                                                                                      KC_SPACE,       KC_DOWN,        KC_LBRACKET,    KC_RBRACKET,    MO(SYMBOLS),
                                                                                                    MT(MOD_LALT, KC_APPLICATION),KC_LGUI,KC_LALT,   MT(MOD_LCTL, KC_ESCAPE),
                                                                                                                    KC_HOME,        KC_PGUP,
                                                                                    KC_SPACE,       KC_BSPACE,      KC_END,         KC_PGDOWN,      KC_TAB,         KC_ENTER
  ),
  [HEBREW_ARKAN] = LAYOUT_ergodox_pretty(
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,           KC_TRNS,
    KC_TRNS,        KC_TZADI_SOFIT, KC_NUN_SOFIT,   KC_QOF,         KC_RESH,        KC_ALEF,        KC_TRNS,                                        KC_TRNS,        KC_TET,         KC_VAV,         KC_TAV,         KC_MEM_SOFIT,   KC_PEH,            KC_TRNS,
    KC_TRNS,        KC_SHIN,        KC_DALET,       KC_GIMEL,       KC_KAF,         KC_AYIN,                                                                        KC_YOD,         KC_CHET,        KC_LAMED,       KC_KAF_SOFIT,   KC_PEH_SOFIT,      KC_TRNS,
    KC_TRNS,        KC_ZAYIN,       KC_SAMEKH,      KC_BET,         KC_HEH,         KC_NUN,         KC_TRNS,                                        KC_TRNS,        KC_NUN,         KC_MEM,         KC_TZADI,       KC_TRNS,        KC_TRNS,           KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,           KC_TRNS,
                                                                                                    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                    KC_TRNS,        KC_TRNS,
                                                                                    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
  ),
  [QWERTY_GAMING] = LAYOUT_ergodox_pretty(
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,           KC_TRNS,
    KC_TRNS,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRNS,                                        KC_TRNS,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,              KC_TRNS,
    KC_TRNS,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_TRNS,           KC_TRNS,
    KC_TRNS,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_TRNS,                                        KC_TRNS,        KC_N,           KC_M,           KC_TRNS,        KC_TRNS,        KC_TRNS,           KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,           KC_TRNS,
                                                                                                    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                    KC_TRNS,        KC_TRNS,
                                                                                    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
  ),
  [SYMBOLS] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,                                                                       KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_BSLASH,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EQUAL,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_DOT,         KC_0,           KC_EQUAL,       KC_TRANSPARENT,
                                                                                                    RGB_MOD,        RGB_VAI,        RGB_TOG,        RGB_SLD,
                                                                                                                    HSV_86_255_128, TOGGLE_LAYER_COLOR,
                                                                                    RGB_VAD,        HSV_172_255_255,HSV_27_255_255, KC_TRANSPARENT, RGB_HUD,        RGB_HUI
  ),
  [MEDIA] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,                                                                                                     KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_WWW_BACK
  ),
};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
    case HSV_27_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(27,255,255);
      }
      return false;
  }
  return true;
}

uint8_t layer_state_set_user(uint8_t state) {
    uint8_t layer = biton(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};


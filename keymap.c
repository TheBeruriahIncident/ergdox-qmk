#include QMK_KEYBOARD_H
#include "version.h"

#define LAYER_RETURN KC_TRNS // Just as a marker

enum layers {
    COLEMAK_DHM,  // default layer
    HEBREW_ARKAN,
    QWERTY_GAMING,
    SPECIAL,
    HEBREW_CTRL,
    HEBREW_SHIFT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // KC_TAB and KC_ENTER are intended to be used by the right hand generally, but they're duplicated for the left hand for when using the mouse
  [COLEMAK_DHM] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_EQUAL,                                       KC_GRAVE,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_TAB,         KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_TRNS,                                        KC_TRNS,        KC_J,           KC_L,           KC_U,           KC_Y,           KC_SEMICOLON,   KC_BACKSLASH,
    QK_CAPS_WORD_TOGGLE,KC_A,       KC_R,           KC_S,           KC_T,           KC_G,                                                                           KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_MEDIA_PLAY_PAUSE,
    SC_LSPO,        KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,           KC_ENTER,                                       KC_TRNS,        KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_UP,          SC_RSPC,
    KC_LCTL,        KC_LGUI,        KC_LALT,        KC_DELETE,      KC_BACKSPACE,                                                                                                   KC_SPACE,       KC_TAB,         KC_LEFT,        KC_DOWN,        KC_RIGHT,
                                                                                                    KC_LEFT_BRACKET,KC_RIGHT_BRACKET,KC_SLASH,      KC_QUOTE,
                                                                                                                    KC_HOME,        KC_PAGE_UP,
                                                                                    TG(HEBREW_ARKAN),TG(QWERTY_GAMING),KC_END,      KC_PAGE_DOWN,   TT(SPECIAL),    KC_ENTER
  ),
  // Note that (per the Hebrew keyboard standard), shift-9 is always an open parenthesis and shift-0 is always a close, even though the symbols are swapped
  // Shift lets you type Colemak while held. This is similar to a traditional keyboard, except that it's lowercase rather than upper case.
  // Note that the space cadet behavior of parenthesis when tapping shift is lost, because there's no specific code for parenthesis, and mod keys don't work with layer shift. Probably process_record_user could fix this, but every version of SEND_STRING or tap_code16 I've tried somehow sends F7?!
  // Left control still sends control, but it also momentarily switches to Colemak so that shortcuts will work.
  [HEBREW_ARKAN] = LAYOUT_ergodox_pretty(
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_TZADI_SOFIT, KC_NUN_SOFIT,   KC_QOF,         KC_RESH,        KC_ALEF,        KC_TRNS,                                        KC_TRNS,        KC_TET,         KC_VAV,         KC_TAV,         KC_MEM_SOFIT,   KC_PEH,         KC_TRNS,
    KC_TRNS,        KC_SHIN,        KC_DALET,       KC_GIMEL,       KC_KAF,         KC_AYIN,                                                                        KC_YOD,         KC_CHET,        KC_LAMED,       KC_KAF_SOFIT,   KC_PEH_SOFIT,   KC_TRNS,
    LM(HEBREW_SHIFT, MOD_LSFT),KC_ZAYIN,KC_SAMEKH,  KC_BET,         KC_HEH,         KC_NUN,         KC_TRNS,                                        KC_TRNS,        KC_MEM,         KC_TZADI,       KC_TRNS,        KC_TRNS,        KC_TRNS,        LM(HEBREW_SHIFT, MOD_RSFT),
    LM(HEBREW_CTRL, MOD_LCTL),KC_TRNS,KC_TRNS,      KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                    KC_TRNS,        KC_TRNS,
                                                                                    LAYER_RETURN,   KC_NO,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
  ),
  // KC_SPACE is duplicated into an empty space here so that it's available to the left hand while gaming. If KC_SPACE is moved, replace it with KC_NO so that the Hebrew toggle doesn't come through.
  [QWERTY_GAMING] = LAYOUT_ergodox_pretty(
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRNS,                                        KC_TRNS,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRNS,
    KC_TRNS,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SEMICOLON,   KC_TRNS,
    KC_TRNS,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_TRNS,                                        KC_TRNS,        KC_N,           KC_M,           KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                    KC_TRNS,        KC_TRNS,
                                                                                    KC_SPACE,       LAYER_RETURN,   KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
  ),
  [SPECIAL] = LAYOUT_ergodox_pretty(
    KC_SYSTEM_SLEEP,KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRNS,                                        KC_TRNS,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_F12,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                    KC_TRNS,        KC_TRNS,        KC_AUDIO_MUTE,  KC_PRINT_SCREEN,
                                                                                                             KC_MEDIA_NEXT_TRACK,   KC_AUDIO_VOL_UP,
                                                                                    KC_TRNS,        KC_TRNS, KC_MEDIA_PREV_TRACK,   KC_AUDIO_VOL_DOWN,LAYER_RETURN, KC_MEDIA_PLAY_PAUSE
  ),
  // When you press ctrl on the Hebrew layer, you get this layer. This layer exists because you can't momentarily toggle the base layer. So, we duplicate the relevant parts so that we can toggle it in and make ctrl shortcuts work.
  [HEBREW_CTRL] = LAYOUT_ergodox_pretty(
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_TRNS,                                        KC_TRNS,        KC_J,           KC_L,           KC_U,           KC_Y,           KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_A,           KC_R,           KC_S,           KC_T,           KC_G,                                                                           KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_TRNS,
    KC_NO,          KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,           KC_TRNS,                                        KC_TRNS,        KC_K,           KC_H,           KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_NO,
    KC_NO,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                    KC_TRNS,        KC_TRNS,
                                                                                    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
  ),
  // This layer lets shift on the keyboard type English, but unlike on a traditional Hebrew keyboard, it's not all caps. We have to put in the shifted version of other keys so that shift isn't broken for e.g. numbers or quotes in Hebrew.
  [HEBREW_SHIFT] = LAYOUT_ergodox_pretty(
    KC_TRNS,        KC_EXCLAIM,     KC_AT,          KC_HASH,        KC_DOLLAR,      KC_PERCENT,     KC_PLUS,                                        KC_TILDE,       KC_PERCENT,     KC_AMPERSAND,   KC_ASTERISK,    KC_LEFT_PAREN,  KC_RIGHT_PAREN, KC_UNDERSCORE,
    KC_TRNS,        KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_TRNS,                                        KC_TRNS,        KC_J,           KC_L,           KC_U,           KC_Y,           KC_COLON,       KC_PIPE,
    KC_TRNS,        KC_A,           KC_R,           KC_S,           KC_T,           KC_G,                                                                           KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_TRNS,
    KC_NO,          KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,           KC_TRNS,                                        KC_TRNS,        KC_K,           KC_H,           KC_LEFT_ANGLE_BRACKET,KC_RIGHT_ANGLE_BRACKET,KC_TRNS,KC_NO,
    KC_NO,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                           KC_LEFT_CURLY_BRACE,KC_RIGHT_CURLY_BRACE,KC_QUESTION,KC_DOUBLE_QUOTE,
                                                                                                                    KC_TRNS,        KC_TRNS,
                                                                                    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
  ),
  // [BLANK_TEMPLATE] = LAYOUT_ergodox_pretty(
  //   KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
  //   KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
  //   KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
  //   KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
  //   KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
  //                                                                                                   KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
  //                                                                                                                   KC_TRNS,        KC_TRNS,
  //                                                                                   KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
  // ),
};

void keyboard_pre_init_user(void) {
  rgb_matrix_set_speed(50); // Animation speed
}


uint8_t layer_state_set_user(uint8_t state) {
  uint8_t layer = biton(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case COLEMAK_DHM:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_LEFT_RIGHT);
      rgblight_sethsv_noeeprom(50,255,255); // Full saturation and brightness; hue has no effect with this animation
      break;
    case HEBREW_ARKAN:
    case HEBREW_CTRL:
    case HEBREW_SHIFT:
      ergodox_right_led_2_on();
      rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
      rgblight_sethsv_noeeprom(HSV_GREEN);
      break;
    case QWERTY_GAMING:
      ergodox_right_led_1_on();
      rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
      rgblight_sethsv_noeeprom(HSV_RED);
      break;
    case SPECIAL:
      ergodox_right_led_3_on();
      rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
      rgblight_sethsv_noeeprom(HSV_CYAN);
      break;
    default:
      break;
  }
  return state;
};

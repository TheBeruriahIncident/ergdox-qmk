/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"vrpJO/yR7Dz" // This must match the url of the layout on Oryx for Live Training and Keymapp to work
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT

#define RGB_MATRIX_STARTUP_SPD 60

#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE
#define KC_ALEF UC(0x05D0)
#define KC_BET UC(0x05D1)
#define KC_GIMEL UC(0x05D2)
#define KC_DALET UC(0x05D3)
#define KC_HEH UC(0x05D4)
#define KC_VAV UC(0x05D5)
#define KC_ZAYIN UC(0x05D6)
#define KC_CHET UC(0x05D7)
#define KC_TET UC(0x05D8)
#define KC_YOD UC(0x05D9)
#define KC_KAF_SOFIT UC(0x05DA)
#define KC_KAF UC(0x05DB)
#define KC_LAMED UC(0x05DC)
#define KC_MEM_SOFIT UC(0x05DD)
#define KC_MEM UC(0x05DE)
#define KC_NUN_SOFIT UC(0x05DF)
#define KC_NUN UC(0x05E0)
#define KC_SAMEKH UC(0x05E1)
#define KC_AYIN UC(0x05E2)
#define KC_PEH_SOFIT UC(0x05E3)
#define KC_PEH UC(0x05E4)
#define KC_TZADI_SOFIT UC(0x05E5)
#define KC_TZADI UC(0x05E6)
#define KC_QOF UC(0x05E7)
#define KC_RESH UC(0x05E8)
#define KC_SHIN UC(0x05E9)
#define KC_TAV UC(0x05EA)
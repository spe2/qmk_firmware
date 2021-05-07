#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    Southpaw Design
#define PRODUCT         SpacePad
#define DESCRIPTION     An 18 key macropad with multiple switch type support, per key RGB LEDs, OLED,Speaker, and ENC support
/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

/* key matrix pins */
#define MATRIX_ROW_PINS { D3, D2, D4, B6, B2 }
#define MATRIX_COL_PINS { D7, E6, B4, B5 }
#define UNUSED_PINS

#define ENCODERS_PAD_A { F6 }
#define ENCODERS_PAD_B { F5 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Speader Pin */
//#define C6_AUDIO

/* number of backlight levels */
#define BACKLIGHT_LEVELS 0

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN B1
#define RGBLED_NUM 12    // Number of LEDs

#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 6
#define RGBLIGHT_SAT_STEP 4
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LIMIT_VAL 255

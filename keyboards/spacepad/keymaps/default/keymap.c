/* Copyright 2018 Jack Humbert
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

#define BASE 0
#define FN 1

enum encoder_names {
  _BOTTOM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[BASE] = LAYOUT(
		  KC_7,     KC_8,    KC_9, KC_HOME,
		  KC_4,     KC_5,    KC_6, KC_END,
		  KC_1,    KC_2,    KC_3, KC_DEL,
		KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
		  KC_NO,   KC_NO,   MO(1), KC_NO
	),
  
	[FN] = LAYOUT(
		RGB_TOG, KC_HOME,  KC_PGUP, KC_TRNS,
		RGB_MOD,  KC_END,  KC_PGDN, KC_TRNS,
		KC_TRNS, KC_TRNS,  KC_TRNS, RESET,
		KC_NO,     KC_NO,   KC_ENT, KC_NO,
		KC_NO,     KC_NO,  KC_TRNS, KC_NO
	)
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _BOTTOM) {
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_INS);
        }
    }
}


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}

void oled_task_user(void) {
  // Host Keyboard Layer Status
  oled_write_P(PSTR("OLEDs are neat!"), false);
  switch (get_highest_layer(layer_state)) {
    case BASE:
      oled_write_ln_P(PSTR(""), false);
      break;
    case FN:
      oled_write_ln_P(PSTR("FN"), false);
      break;
    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_ln_P(PSTR("Undef"), false);
  }

  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NLCK ") : PSTR("     "), false);
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPS ") : PSTR("       "), false);
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLK") : PSTR("       "), false);
}
#endif

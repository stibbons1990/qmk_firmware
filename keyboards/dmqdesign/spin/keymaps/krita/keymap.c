/* Copyright 2019-2020 DMQ Design
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(/* Base */
                KC_F13, KC_F14, KC_F15, KC_X, // (Krita: switch background and foreground colors).
                KC_F16, KC_F17, KC_F18, KC_5, // (Krita: reset rotation to 0).
                KC_F19, KC_F20, KC_F21, KC_1, // (Krita: reset zoom to 100%).
                KC_F22, KC_F23, KC_F24
                ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code16(LALT(KC_KP_PLUS)); // Alt++ to decrease brush size.
    } else {
      tap_code16(LALT(KC_KP_MINUS)); // Alt+- to decrease brush size.
    }
  } else if (index == 1) { /* Second encoder */
    if (clockwise) {
      tap_code(KC_6); // (Krita: rotate right).
    } else {
      tap_code(KC_4); // (Krita: rotate left).
    }
  } else if (index == 2) { /* Third encoder */
    if (clockwise) {
      tap_code(KC_MS_WH_UP); // Mouse wheel scroll up (Krita: zoom in).
    } else {
      tap_code(KC_MS_WH_DOWN); // Mouse wheel scroll down (Krita: zoom in).
    }
  }
  return true;
}

void keyboard_post_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    // Set all LEDs to BLUE
    rgblight_setrgb_range(RGB_BLUE, 0, RGBLED_NUM);
    rgblight_mode_noeeprom(RGBLIGHT_EFFECT_BREATHING + 2);
  #endif
}

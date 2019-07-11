/* Copyright 2015-2017 Jack Humbert
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
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

enum custom_layers {
  _COLEMAK,
  _QWERTY,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  DVORAK,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV
};

#define CTL_ESC CTL_T(KC_ESC)  // Tap for Escape, hold for Control
#define HPR_TAB ALL_T(KC_TAB)  // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)
#define MEH_GRV MEH_T(KC_GRV)  // Tap for Backtick, hold for Meh (Ctrl+Alt+Shift)
#define SFT_BSP SFT_T(KC_BSPC) // Tap for Backspace, hold for Shift
#define SFT_ENT SFT_T(KC_ENT)  // Tap for Enter, hold for Shift
#define SFT_SPC SFT_T(KC_SPC)  // Tap for Space, hold for Shift
#define UMLAUT  RALT(KC_U)     // Combine Alt and U

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,--------------------------------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   -  |      |   =  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |   \  |   ]  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   {  |      |   }  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   (  |  Up  |   )  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Meh  | Alt  | GUI  |Lower |Space | Left | Down | Rght | Tab  |Raise | GUI  |AltGr | Umlt | Ctrl |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, _______, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
  { HPR_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL  },
  { CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LCBR, _______, KC_RCBR, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT },
  { SFT_BSP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LPRN, KC_UP,   KC_RPRN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT },
  { KC_LCTL, MEH_GRV, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, HPR_TAB, RAISE,   KC_RGUI, KC_RALT, UMLAUT,  KC_RCTL }
},

/* Colemak
 * ,--------------------------------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   -  |      |   =  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   [  |   \  |   ]  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   {  |      |   }  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   (  |  Up  |   )  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Meh  | Alt  | GUI  |Lower |Space | Left | Down | Rght | Tab  |Raise | GUI  |AltGr | Umlt | Ctrl |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, _______, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
  { HPR_TAB, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_LBRC, KC_BSLS, KC_RBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL  },
  { CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_LCBR, _______, KC_RCBR, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT },
  { SFT_BSP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LPRN, KC_UP,   KC_RPRN, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT },
  { KC_LCTL, MEH_GRV, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, HPR_TAB, RAISE,   KC_RGUI, KC_RALT, UMLAUT,  KC_RCTL }
},

/* Dvorak
 * ,--------------------------------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   -  |      |   =  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   [  |   \  |   ]  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   {  |      |   }  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   (  |  Up  |   )  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Meh  | Alt  | GUI  |Lower |Space | Left | Down | Rght | Tab  |Raise | GUI  |AltGr | Umlt | Ctrl |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, _______, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
  { HPR_TAB, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_LBRC, KC_BSLS, KC_RBRC, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_DEL  },
  { CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_LCBR, _______, KC_RCBR, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH },
  { SFT_BSP, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_LPRN, KC_UP,   KC_RPRN, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    SFT_ENT },
  { KC_LCTL, MEH_GRV, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, HPR_TAB, RAISE,   KC_RGUI, KC_RALT, UMLAUT,  KC_RCTL }
},

/* Lower
 * ,--------------------------------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Bksp |  Up  |  Del |      |      |      |      |      |      |   /  |   7  |   8  |   9  |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * |      |      | Left | Down | Rght |      |      |      |      |      |      |   *  |   4  |   5  |   6  |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |   -  |   1  |   2  |   3  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |   +  |Enter |   0  |   .  |
 * `--------------------------------------------------------------------------------------------------------'
  */
[_LOWER] = {
  { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12  },
  { _______, _______, KC_BSPC, KC_UP,   KC_DEL,  _______, _______, _______, _______, _______, _______, KC_PSLS, KC_P7,   KC_P8,   KC_P9   },
  { _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_PAST, KC_P4,   KC_P5,   KC_P6   },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PMNS, KC_P1,   KC_P2,   KC_P3   },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PPLS, KC_PENT, KC_P0,   KC_PDOT }
},

/* Raise	
 * ,--------------------------------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Bksp | PgUp |  Del |      |      |      |      |      | Bksp |  Up  |  Del |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * |      |      | Home | PgDn |  End |      |      |      |      |      | Left | Down | Rght |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * |      |      | Pause| Ins  | PrScr|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_RAISE] = {
  { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12  },
  { _______, _______, KC_BSPC, KC_PGUP, KC_DEL,  _______, _______, _______, _______, _______, KC_BSPC, KC_UP,   KC_DEL,  _______, _______ },
  { _______, _______, KC_HOME, KC_PGDN, KC_END,  _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______ },
  { _______, _______, KC_PAUS, KC_INS,  KC_PSCR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
},

/* Plover layer (http://opensteno.org)
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |   #  |   #  |   #  |   #  |   #  |   #  |      |      |      |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |      |      |      |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |      |      |      |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |      |      |      |      |      |   E  |   U  |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */

[_PLOVER] = {
  { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
  { KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1    },
  { XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, XXXXXXX, XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC },
  { XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, XXXXXXX, XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT },
  { EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX }
},

/* Adjust (Lower + Raise)
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |      | Reset|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|      |      |      |AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|      |      |      |MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */

[_ADJUST] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   KC_DEL  },
  { _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, _______, _______, _______, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  PLOVER,  _______ },
  { _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   _______, _______, _______, MI_OFF,  _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
}
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}

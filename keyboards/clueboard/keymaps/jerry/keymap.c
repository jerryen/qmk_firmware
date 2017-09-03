#include "clueboard.h"

// Helpful defines
#define GRAVE_MODS (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT) | MOD_BIT(KC_LCTRL))
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _WL 0
#define _GL 1
#define _ML 2
#define _WF 3
#define _MF 4
#define _CL 5
#define _GC 6

#define CAPS_FN LT(_CL, KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _WL: Windows Layer (Default)
   */
[_WL] = KEYMAP(
  F(0),    KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSLS, KC_GRV,           KC_INS,  \
  KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,                   KC_DEL,  \
  KC_LCTL, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN,  KC_QUOT,  XXXXXXX,  KC_ENT,                             \
  KC_LSFT, XXXXXXX, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,   KC_SLSH,  XXXXXXX,  KC_RSFT,          KC_UP,            \
  CAPS_FN, KC_LGUI, KC_LALT,XXXXXXX,                XXXXXXX,KC_SPC,                  XXXXXXX,  KC_RALT,  KC_RCTL,  F(4),    KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap _GL + _WL: MMO Layer
   */
[_GL] = KEYMAP(
  _______, F(9),    F(9),   F(9),   F(9),   F(9),   _______,_______,_______,_______, _______,  _______,  _______,  _______, _______,          _______, \
  _______, F(9),    _______,F(9),   F(9),   _______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                   _______, \
  _______, _______, _______,_______,F(9),   _______,_______,_______,_______,_______, _______,  _______,  XXXXXXX,  _______,                            \
  _______, XXXXXXX, F(9),   F(9),   F(9),   F(9),   _______,_______,_______,_______, _______,  _______,  XXXXXXX,  _______,          _______,          \
  _______, _______, _______,XXXXXXX,                XXXXXXX,_______,                 XXXXXXX,  _______,  _______,  _______, _______, _______, _______),

  /* Keymap _GC: MMO Ctrl Layer (Only accessed through action_function)
   */
[_GC] = KEYMAP(
  _______, KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  _______,_______,_______,_______, _______,  _______,  _______,  _______, _______,          _______, \
  _______, KC_F6,   _______,KC_F7,  KC_F8,  _______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                   _______, \
  _______, _______, _______,_______,KC_F9,  _______,_______,_______,_______,_______, _______,  _______,  XXXXXXX,  _______,                            \
  _______, XXXXXXX, KC_F10, KC_F11, KC_F12, KC_F13, _______,_______,_______,_______, _______,  _______,  XXXXXXX,  _______,          _______,          \
  _______, _______, _______,XXXXXXX,                XXXXXXX,_______,                 XXXXXXX,  _______,  _______,  _______, _______, _______, _______),

  /* Keymap _ML + _WL: Mac Layer
   */
[_ML] = KEYMAP(
  _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______, _______,          _______, \
  _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                   _______, \
  _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  XXXXXXX,  _______,                            \
  _______, XXXXXXX, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  XXXXXXX,  _______,          _______,          \
  _______, KC_LALT, KC_LGUI,XXXXXXX,                XXXXXXX,_______,                 XXXXXXX,  KC_RGUI,  KC_RALT,  _______, _______, _______, _______),

  /* Keymap _WF: Windows Function Layer
   */
[_WF] = KEYMAP(
  KC_GRV,  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,   KC_F11,   F(1),     KC_F13,  KC_F14,           KC_F15,  \
  _______, _______, _______,_______,_______,_______,_______,_______,KC_PSCR,KC_SLCK, KC_PAUS,  KC_VOLD,  KC_VOLU,  KC_MUTE,                   F(5),    \
  _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  F(7),     XXXXXXX,  KC_MPLY,                            \
  _______, XXXXXXX, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  XXXXXXX,  _______,          KC_PGUP,          \
  _______, _______, _______,XXXXXXX,                XXXXXXX,_______,                 XXXXXXX,  _______,  KC_APP,   _______, KC_HOME, KC_PGDN, KC_END),

  /* Keymap _MF + _WF: Mac Function Layer
   */
[_MF] = KEYMAP(
  _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  KC_F12,   _______, _______,          _______, \
  _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                   F(6),    \
  _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  F(8),     XXXXXXX,  _______,                            \
  _______, XXXXXXX, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  XXXXXXX,  _______,          _______,          \
  _______, _______, _______,XXXXXXX,                XXXXXXX,_______,                 XXXXXXX,  _______,  KC_RALT,  _______, _______, _______, _______),

  /* Keymap _CL: Config layer
   */
[_CL] = KEYMAP(
  _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______, RGB_TOG,          RGB_VAI, \
  _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                   RGB_VAD, \
  TG(_GL), _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  XXXXXXX,  _______,                            \
  _______, XXXXXXX, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  XXXXXXX,  _______,          RGB_SAI,          \
  _______, F(2),    F(3),   XXXXXXX,                XXXXXXX,RGB_MOD,                 XXXXXXX,  _______,  _______,  _______, RGB_HUD, RGB_SAD, RGB_HUI),
};

/* This is a list of user defined functions. F(N) corresponds to item N
   of this list.
 */
const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(0), // Grave/Esc
  [1] = ACTION_FUNCTION(1), // F12 during boot
  [2] = ACTION_FUNCTION(2), // Swap to Windows mode
  [3] = ACTION_FUNCTION(3), // Swap to Mac mode
  [4] = ACTION_FUNCTION(4), // FN Layers
  [5] = ACTION_MODS_KEY(MOD_LCTL | MOD_LSFT, KC_ESC), // Task Manager
  [6] = ACTION_MODS_KEY(MOD_LALT | MOD_LGUI, KC_ESC), // Force Quit
  [7] = ACTION_MODS_KEY(MOD_LGUI | MOD_LSFT, KC_S), // Windows screen grab to clipboard
  [8] = ACTION_MODS_KEY(MOD_LCTL | MOD_LGUI | MOD_LSFT, KC_4), // Mac screen grab to clipboard
  [9] = ACTION_FUNCTION(9), // MMO Function Keys

};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t mods_pressed;
  static bool mod_flag;
  switch (id) {
    case 0:
      /* Handle the combined Grave/Esc key
       */
      mods_pressed = get_mods() & GRAVE_MODS; // Check to see what mods are pressed

      if (record->event.pressed) {
        /* The key is being pressed.
         */
        if (mods_pressed) {
          mod_flag = true;
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        /* The key is being released.
         */
        if (mod_flag) {
          mod_flag = false;
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
    case 1:
      /* Set to Mac layer if F12 was used within 15 seconds of powering on
       */
      if (timer_read32() < 15000) {
        default_layer_set(1 << _ML);
        if (layer_state & (1 << _WF)) {
          layer_on(_MF);
        }
      }
      if (record->event.pressed) {
        add_key(KC_F12);
        send_keyboard_report();
      } else {
        del_key(KC_F12);
        send_keyboard_report();
      }
      break;
    case 2:
      default_layer_set(1 << _WL);
      break;
    case 3:
      default_layer_set(1 << _ML);
      break;
    case 4:
      layer_invert(_WF);
      if (default_layer_state == (1 << _ML)) {
        layer_invert(_MF);
      }
      break;
    case 9: {
      uint16_t mmo_key = keymap_key_to_keycode(_GC, (keypos_t){.row = record->event.key.row, .col = record->event.key.col});
      uint16_t base_key = keymap_key_to_keycode(_WL, (keypos_t){.row = record->event.key.row, .col = record->event.key.col});
      if (get_mods() & MOD_BIT(KC_LCTRL)) {
        del_mods(MOD_LCTL);
        if (record->event.pressed) {
          add_key(mmo_key);
          send_keyboard_report();
        } else {
          del_key(mmo_key);
          del_key(base_key);
          send_keyboard_report();
        }
        add_mods(MOD_LCTL);
      } else {
        if (record->event.pressed) {
          add_key(base_key);
          send_keyboard_report();
        } else {
          del_key(mmo_key);
          del_key(base_key);
          send_keyboard_report();
        }
      }
      break;
    }
  }
}

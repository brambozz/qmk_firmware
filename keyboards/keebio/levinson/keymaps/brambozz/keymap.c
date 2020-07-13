#include QMK_KEYBOARD_H

//TODO: make all momentary toggles a key when pressed, i.e. maximize the
//layout.
#define COLEMAK 0
#define LOWER 1
#define RAISE 2
#define ADJUST 3
#define OVERCOOKED 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,---------------------------------------------------------------------------------------.
 * | Tab    |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | RESET  |
 * |--------+------+------+------+------+-------------+------+------+------+------+--------|
 * |GUI/Bksp|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "     |
 * |--------+------+------+------+------+------|------+------+------+------+------+--------|
 * |Shft/Esc|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Sft/Ent |
 * |--------+------+------+------+------+------+------+------+------+------+------+--------|
 * |Adjust  | Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right   |
 * `-------------------------------------------------------------------------------------'
 */
[COLEMAK] = LAYOUT_ortho_4x12( \
  KC_TAB,          KC_Q,    KC_W,    KC_F,    KC_P,      KC_G,             KC_J,    KC_L,      KC_U,    KC_Y,    KC_SCLN, RESET, \
  RGUI_T(KC_BSPC), KC_A,    KC_R,    KC_S,    KC_T,      KC_D,             KC_H,    KC_N,      KC_E,    KC_I,    KC_O,    KC_QUOT, \
  LSFT_T(KC_ESC),  KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,             KC_K,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT), \
  MO(ADJUST),      KC_LCTL, KC_LALT, KC_LGUI, MO(LOWER), LT(RAISE,KC_SPC), KC_SPC,  MO(RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower/raise
 * ,------------------------------------------------------------------------------------.
 * | F1/F7 | F2/F8| F3/F9|F4/F10|F5/F11|F6/F12|      |  5/% |  6/^ |  7/& |  8/ *|      |
 * |-------+------+------+------+------+-------------+------+------+------+------+------|
 * |Del/Del|  `\~ |  \/| |  =/+ |  -/_ |      |      |  9/( |  0/) |  [/{ |  ]/} |      |
 * |-------+------+------+------+------+------|------+------+------+------+------+------|
 * |BLSTEP |      |      |      |      |      |      |  1/! |  2/@ |  3/# |  4/$ |      |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |       |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[LOWER] = LAYOUT_ortho_4x12( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_5,    KC_6,     KC_7,    KC_8,    _______, \
  KC_DEL,  KC_GRV,  KC_BSLS, KC_EQL,  KC_MINS, _______, _______, KC_9,    KC_0,     KC_LBRC, KC_RBRC, _______, \
  BL_STEP, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,     KC_3,    KC_4,    _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______ \
),

[RAISE] = LAYOUT_ortho_4x12( \
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_PERC,  KC_CIRC, KC_AMPR, KC_ASTR, _______, \
  KC_DEL,  KC_TILD, KC_PIPE, KC_PLUS, KC_UNDS, _______, _______, KC_LPRN,  KC_RPRN, KC_LCBR, KC_RCBR, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______ \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|      |      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[ADJUST] =  LAYOUT_ortho_4x12( \
  RESET,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______,        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  TG(OVERCOOKED), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______,        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Overcooked
 * ,-----------------------------------------------------------------------------------.
 * | LCTL | LSHFT| LALT |      |      |      |      |      | Up   |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | LSHFT| LCTL | Space| LALT |      |      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |  W   |      |      |      |      | RSHFT| Up   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  A   |  S   |  D   |      | RALT | RCTL | Left | Down | Right|
 * `-----------------------------------------------------------------------------------'
 */
[OVERCOOKED] =  LAYOUT_ortho_4x12( \
  KC_LCTL, KC_LSFT, KC_LALT, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______, \
  _______, KC_LSFT, KC_LCTL, KC_SPC,  KC_LALT, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, _______, _______, _______, KC_W,    _______, _______, _______, _______, KC_RSFT, KC_UP,   _______, \
  _______, _______, _______, KC_A,    KC_S,    KC_D,    _______, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT \
)

};

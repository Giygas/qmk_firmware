#include QMK_KEYBOARD_H



enum layer_number {
  _QWERTY = 0,
  _COLEMAK = 1,
  _LOWER,
  _NUM,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift(|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift)|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |BackSP | TG(NUM)|  DEL |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,       KC_8,    KC_9,     KC_0,  KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,     KC_U,       KC_I,    KC_O,     KC_P, KC_MINS,
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,     KC_J,       KC_K,    KC_L,  KC_SCLN, KC_QUOT,
  KC_LSPO,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,    KC_N,     KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_RSPC,
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,   KC_ENT, KC_BSPC, TG(_NUM),     KC_DEL
),
/* COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   R  |   S  |   I  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift(|   Z  |   X  |   C  |   V  |   B  |-------|    |------|   K  |   M  |   ,  |   .  |   /  |RShift)|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |BackSP | TG(NUM)|  DEL |
 *                   |      |      |      |/       /         \      \ |      |        |      |
 *                   `----------------------------'           '------''---------------------'
 */

 [_COLEMAK] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,    KC_8,      KC_9,    KC_0,  KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                       KC_J,     KC_L,    KC_U,      KC_Y, KC_SCLN, KC_MINS,
  KC_LCTRL, KC_A,   KC_R,    KC_S,    KC_I,    KC_D,                       KC_H,     KC_N,    KC_E,      KC_I,    KC_O, KC_QUOT,
  KC_LSPO,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,    KC_K,     KC_M, KC_COMM,    KC_DOT, KC_SLSH, KC_RSPC,
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,   KC_ENT, KC_BSPC, TG(_NUM),  KC_DEL
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |   *  |      |      |      |      | SCR+ |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |SHIFT |  6   |  7   |  8   |  9   |   0  |                    |   =  | HOME |  UP  | END  |      | SCR- |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |-------.    ,-------|   +  | LEFT | DOWN | RIGHT| CTRL |      |
 * |------+------+------+------+------+------| VOL + |    | VOL - |------+------+------+------+------+------|
 * |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |-------|    |-------|   |  |  -   | CAPS |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  | DEL |      |      |
 *                   |      |      |      |/       /         \      \ |     |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                                      KC_PAST, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  KC_BRIGHTNESS_UP,
  KC_LSFT,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                                     KC_EQUAL, KC_HOME,   KC_UP,  KC_END,  XXXXXXX,KC_BRIGHTNESS_DOWN,
   KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                      KC_PPLS, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_RCTL,           XXXXXXX,
   KC_F12,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN,  KC_NUBS, KC_PMNS, KC_CAPS, XXXXXXX,  XXXXXXX,           XXXXXXX,
                             _______, _______, _______,         _______, _______,             KC_DEL, XXXXXXX, XXXXXXX
),
/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |   *  |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  DEL |  UP  |      |      |                    |   -  |   7  |  8   |  9   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | LEFT | DOWN | RIGHT|      |-------.    ,-------|   +  |   4  |  5   |  6   | N.ENT|      |
 * |------+------+------+------+------+------|       |    | BKSP  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   /  |   1  |  2   |  3   |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | COPY | PASTE |CUT | /Space  /       \Enter \  |   0   | TG(2) |  =   |
 *                   |      |      |      |/       /         \      \ |      |       |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_NUM] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                     KC_PAST,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,  KC_DEL,   KC_UP,  XXXXXXX, XXXXXXX,                     KC_PMNS,    KC_P7,   KC_P8,   KC_P9, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX,                     KC_PLUS,    KC_P4,   KC_P5,   KC_P6, KC_PENT, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,   _______, _______, KC_PSLS,    KC_P1,   KC_P2,   KC_P3, KC_RBRC, KC_BSLS,
                             KC_COPY, KC_PASTE,  KC_CUT,   _______, _______,   KC_P0, TG(_NUM),  KC_EQL
),
/* ADJUST
 * ,-----------------------------------------.                    ,------------------------------------------.
 * |QWERTY|      |      |      |      |      |                    |COLEMAK|      |      |      |      |      |
 * |------+------+------+------+------+------|                    |-------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |       |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |-------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|       |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |-------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|       |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \------------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  DF(_QWERTY), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   DF(_COLEMAK), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 _______, _______, _______,   _______, _______,   _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _NUM, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;

  switch (keycode) {
    case LT(0,KC_N): //sends n on tap and ñ on hold
    if (record->tap.count && record->event.pressed) {
        return true; // Return true for normal processing of tap keycode
        break;
    } else if (record->event.pressed) {
        tap_code16(RALT(KC_N)); // Intercept hold function Right Alt + N that will be a Ñ
        return false;
    }
    return true; // this allows for normal processing of key release!
  }
}




#include QMK_KEYBOARD_H

#define KX_COPY LCTL(KC_C)
#define KX_CUT  LCTL(KC_X)
#define KX_PASTE LCTL(KC_V)

int deflayout = 0;
bool combstatus=true;


enum layer_number {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _NUM,
  _ADJUST,
};

enum keycode {
  QWE = SAFE_RANGE,
  COL,
  ENI = ALGR(KC_N),
};


// Combos Definitions
enum combos {
FTAB,
// DESKR,
// DESKL,
FCOPY,
FPASTE,
FCUT,
CTRLZ,
};

const uint16_t PROGMEM ftab_combo[]   = {KC_F, KC_TAB, COMBO_END};
// const uint16_t PROGMEM deskr_combo[]  = {KC_LGUI, KC_RBRC, COMBO_END};
// const uint16_t PROGMEM deskl_combo[]  = {KC_LGUI, KC_LBRC, COMBO_END};
const uint16_t PROGMEM fcopy_combo[]  = {KC_F, KC_C, COMBO_END};
const uint16_t PROGMEM fpaste_combo[] = {KC_F, KC_V, COMBO_END};
const uint16_t PROGMEM fcut_combo[] = {KC_F, KC_X, COMBO_END};
const uint16_t PROGMEM ctrlz_combo[] = {KC_F, KC_Z, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [FTAB]   = COMBO(ftab_combo,   A(KC_TAB)),
  // [DESKR]  = COMBO(deskr_combo,  C(G(KC_RIGHT))),
  // [DESKL]  = COMBO(deskl_combo,  C(G(KC_LEFT))),
  [FCOPY]  = COMBO(fcopy_combo,  C(KC_C)),
  [FPASTE] = COMBO(fpaste_combo, C(KC_V)),
  [FCUT]   = COMBO(fcut_combo, C(KC_X)),
  [CTRLZ]  = COMBO(ctrlz_combo,  C(KC_Z))
};
//END of Combos Definitions


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
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,     KC_7,       KC_8,    KC_9,     KC_0,  KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,     KC_U,       KC_I,    KC_O,     KC_P, KC_MINS,
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,     KC_J,       KC_K,    KC_L,  KC_SCLN, KC_QUOT,
  KC_LSPO,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,    LT(0, KC_N),     KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_RSPC,
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,   KC_ENT,        KC_BSPC, TG(_NUM),     KC_DEL
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
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,            KC_7,    KC_8,      KC_9,    KC_0,  KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                       KC_J,            KC_L,    KC_U,      KC_Y, KC_SCLN, KC_MINS,
  KC_LCTRL, KC_A,   KC_R,    KC_S,    KC_I,    KC_D,                       KC_H,     LT(0, KC_N),    KC_E,      KC_I,    KC_O, KC_QUOT,
  KC_LSPO,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,    KC_K,            KC_M, KC_COMM,    KC_DOT, KC_SLSH, KC_RSPC,
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,   KC_ENT, KC_BSPC,        TG(_NUM),  KC_DEL
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
 * |      |      |      |      |      |      |                    |   *  |      |      |      |      |ADJUST|
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
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                     KC_PAST,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,TG(_ADJUST),
  XXXXXXX, XXXXXXX,  KC_DEL,   KC_UP,  XXXXXXX, XXXXXXX,                     KC_PMNS,    KC_P7,   KC_P8,   KC_P9, XXXXXXX,    XXXXXXX,
  XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX,                     KC_PLUS,    KC_P4,   KC_P5,   KC_P6, KC_PENT,    XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,   _______, _______, KC_PSLS,    KC_P1,   KC_P2,   KC_P3, KC_RBRC,    KC_BSLS,
                             KX_COPY, KX_PASTE,  KX_CUT,   _______, _______,   KC_P0, TG(_NUM),  KC_EQL
),
/* ADJUST
 * ,-----------------------------------------.                    ,------------------------------------------.
 * |QWERTY|      |      |      |      |      |                    |COLEMAK |      |      |      |      |ADJUST|
 * |------+------+------+------+------+------|                    |--------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |        |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |--------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|CMB OFF |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |--------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------| CMB ON |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \------------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
          QWE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            COL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        CMB_OFF, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,     CMB_ON, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 _______, _______, _______,   _______, _______,    _______, _______, _______
  )
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DISPLAY RELATED

#ifdef OLED_ENABLE
  char wpm_str[4];
  #include <stdio.h>
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//   if (!is_keyboard_master())
//     return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
//   return rotation;
// }

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
     return OLED_ROTATION_270;
 }


//Left Display Function
static void print_status_narrow(void) {

  //Print base mode, qwerty or colemak
  oled_write_ln_P(PSTR("MODE"), false);
  oled_write_ln_P(PSTR(""), false);
  if (deflayout == 0) {
        oled_write_P(PSTR("QWTY\n"), false);
      } else {
        oled_write_P(PSTR("CMAK\n"), false);
      }
  oled_write_P(PSTR("\n\n"), false);

  //Print current layer
  oled_write_ln_P(PSTR("LAYER"), false);
  switch (get_highest_layer(layer_state)) {
    case _COLEMAK:
    case _QWERTY:
      oled_write_P(PSTR("Base\n"), false);
      break;
    case _LOWER:
      oled_write_P(PSTR("Low\n"),false);
      break;
    case _NUM:
      oled_write_P(PSTR("Num\n"),false);
      break;
    case _ADJUST:
      oled_write_P(PSTR("Adj\n"),false);
      break;
    default:
      oled_write_ln_P(PSTR("Undef"), false); 
  }
  //Print CAPSLOCK status
  oled_write_P(PSTR("\n\n"), false);
  led_t led_usb_state = host_keyboard_led_state();
  oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
  //Print COMBO status
  oled_write_ln_P(PSTR(""), false);
  oled_write_ln_P(PSTR("COMBO"), combstatus);
}

//Animation Function

/* Animation bit by j-inc https://github.com/qmk/qmk_firmware/tree/master/keyboards/kyria/keymaps/j-inc */
// WPM-responsive animation stuff here
#define IDLE_FRAMES 5
#define IDLE_SPEED 40 // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#define TAP_FRAMES 2
#define TAP_SPEED 60 // above this wpm value typing animation to triggere

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
#define ANIM_SIZE 350 // number of bytes in array, minimize for adequate firmware size, max is 1024

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
uint8_t current_tap_frame = 0;

// Implementation credit j-inc(/James Incandenza), pixelbenny, and obosob.
// Bongo cat images changed and adapted for sofle keyboard oled size.
// Original gif can be found here: https://www.pixilart.com/art/bongo-cat-bd2a8e9323aa705
static void render_anim(void) {
    static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {
        {
        0x00, 0xc0, 0x3e, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0x03, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00,
        0xe1, 0x1e, 0x00, 0xc0, 0xbc, 0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3c, 0x03, 0x00, 0x00, 0x00, 0x80, 0x78, 0x87, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xe0, 0x1f,
        0x01, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x31, 0x05, 0x41, 0x12, 0x04,
        0x00, 0x00, 0x00, 0x00, 0xf8, 0x87, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0xc0, 0x3f, 0x03, 0x80,
        0x78, 0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x03, 0x05,
        0x00, 0x00, 0xf0, 0xcf, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x80, 0x79, 0x07, 0x80, 0x78, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xe0, 0x1e, 0x01, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xf9, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x2c, 0x32, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x07, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0x00, 0xf0, 0x0f, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x18, 0x60, 0x80, 0x00, 0x00, 0xe1, 0x1e, 0x01, 0xf0, 0x8f, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
        0x0e, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x08, 0x08, 0x09, 0x0e, 0x0e, 0x01, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x19,
        0x19, 0x41, 0x0a, 0x22, 0x84, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x70, 0x80,
        0x00, 0x00, 0xf0, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x02, 0x01,
        }
    };
    static const char PROGMEM tap[TAP_FRAMES][ANIM_SIZE] = {
        {
        0x00, 0xc0, 0x3e, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0xff, 0xff, 0xff, 0x7c, 0x70, 0x40, 0x40,
        0x61, 0x5e, 0x80, 0xc0, 0xbc, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3c, 0x03, 0x00, 0x00, 0x00, 0x80, 0x78, 0x87, 0x00, 0x03, 0x0f, 0x3f, 0xf8, 0xf0, 0xf0, 0x20,
        0x40, 0x80, 0x80, 0x00, 0x00, 0x01, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xf8, 0x87, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0xc0, 0x3f, 0x03, 0x80,
        0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04,
        0x00, 0x00, 0xf0, 0xcf, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x80, 0x79, 0x07, 0x80, 0x78, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xe0, 0x1e, 0x01, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xf9, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x2c, 0x32, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x07, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0x00, 0xf0, 0x0f, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x18, 0x60, 0x80, 0x00, 0x00, 0xe1, 0x1e, 0x01, 0xf0, 0x8f, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
        0x0e, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x08, 0x08, 0x09, 0x0e, 0x0e, 0x01, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x19,
        0x19, 0x41, 0x0a, 0x22, 0x84, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x70, 0x80,
        0x00, 0x00, 0xf0, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x02, 0x01,
        },
        {
        0x00, 0xc0, 0x3e, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0x03, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00,
        0xe1, 0x1e, 0x00, 0xc0, 0xbc, 0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3c, 0x03, 0x00, 0x00, 0x00, 0x80, 0x78, 0x87, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xe0, 0x1f,
        0x01, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x31, 0x05, 0x41, 0x12, 0x04,
        0x00, 0x00, 0x00, 0x00, 0xf8, 0x87, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0xc0, 0x3f, 0x03, 0x80,
        0x78, 0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x03, 0x05,
        0x00, 0x00, 0xf0, 0xcf, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x80, 0x79, 0x07, 0x80, 0x78, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xe0, 0xfe, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0xc0, 0x00, 0xf9, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x2c, 0x32, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x07, 0x03, 0x0f, 0x3f, 0xff, 0x03, 0x01, 0x03, 0x07, 0x18, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x18, 0x60, 0x80, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3c, 0x00, 0x00, 0x00, 0x00,
        0x0e, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x08, 0x08, 0x09, 0x0e, 0x0e, 0x01, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x70, 0x80,
        0x00, 0x00, 0xf0, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x02, 0x01
        },
    };

    //assumes 1 frame prep stage
    void animation_phase(void) {
        if(get_current_wpm() <=IDLE_SPEED){
            /*
            current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
            oled_write_raw_P(idle[abs((IDLE_FRAMES-1)-current_idle_frame)], ANIM_SIZE);
            */
            oled_write_raw_P(idle[0], ANIM_SIZE);
         }
         /*
         if(get_current_wpm() >IDLE_SPEED && get_current_wpm() <TAP_SPEED){
             // oled_write_raw_P(prep[abs((PREP_FRAMES-1)-current_prep_frame)], ANIM_SIZE); // uncomment if IDLE_FRAMES >1
             oled_write_raw_P(prep[0], ANIM_SIZE);  // remove if IDLE_FRAMES >1
         }*/
         if(get_current_wpm() >=TAP_SPEED){
             current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
             oled_write_raw_P(tap[abs((TAP_FRAMES-1)-current_tap_frame)], ANIM_SIZE);
         }
    }
    if(get_current_wpm() != 000) {
        oled_on(); // not essential but turns on animation OLED with any alpha keypress
        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
        if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}

/////////////////////////////////////////////////////////////////

bool oled_task_user(void) { 
  if (is_keyboard_master()) {
        print_status_narrow();
  } else {
    //oled_write(read_logo(), false);
    render_anim();
    oled_set_cursor(0,12);
    sprintf(wpm_str, "WPM\n%03d", get_current_wpm());
    oled_write(wpm_str, false);
  }
  return false; 
}
#endif // OLED_ENABLE

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  
  switch (keycode) {
    case LT(0,KC_N): //sends n on tap and ñ on hold
      if (!record->tap.count && record->event.pressed) {  //Intercept hold function Right Alt + N that will be a Ñ
          tap_code16(RALT(KC_N));
          return false;
      }
      return true;
      break;
    case QWE:
      if (record->event.pressed) {
        default_layer_set(_QWERTY);
        deflayout = 0;                    //Used for LEFT OLED default layout
        layer_move(_QWERTY);
        return false;
      }
      break;
    case COL:de
      if (record->event.pressed) {
        default_layer_set(_COLEMAK);
        deflayout = 1;
        layer_move(_COLEMAK);
        return false;
      }
      break;
    case CMB_OFF:
      if (record->event.pressed) {
        combstatus=false;                 //Used for LEFT OLED COMBO status
        if (IS_LAYER_ON(_QWERTY)) {       //Detects base layer and goes there
          layer_move(_QWERTY);
        } else {
          layer_move(_COLEMAK);
        }
        return false;
       }
       break;
    case CMB_ON:
      if (record->event.pressed) {
        combstatus=true;
        if (IS_LAYER_ON(_QWERTY)) {
          layer_move(_QWERTY);
        } else {
          layer_move(_COLEMAK);
        }
        return false;
       }
  }
  return true;
}
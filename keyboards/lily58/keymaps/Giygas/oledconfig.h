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
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
      case _QWERTY:
          oled_write_P(PSTR("QWERTY\n"), false);
          break;
      case _COLEMAK:
          oled_write_P(PSTR("COLEMAK\n"), false);
          break;
      case _NUM:
          oled_write_P(PSTR("NUM\n"), false);
          break;
      case _LOWER:
          oled_write_P(PSTR("LOWER\n"), false);
          break;
      case _ADJUST:
          oled_write_P(PSTR("ADJUST\n"), false);
          break;
      default:
          // Or use the write_ln shortcut over adding '\n' to the end of your string
          oled_write_ln_P(PSTR("Undefined"), false);
    }
    
    //oled_write_ln(read_layer_state(), false);
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
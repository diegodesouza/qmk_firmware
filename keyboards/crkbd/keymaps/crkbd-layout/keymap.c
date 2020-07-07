#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NUMBER 3
#define _MOUSE 4
#define _ADJUST 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  NUMBER,
  MOUSE,
  ADJUST,
BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \

//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_BSLS, \
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,\
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LSFT, LT(1,KC_Z), LT(3,KC_X), KC_C, LT(2,KC_V), LT(4,KC_B),              LT(5,KC_N),  KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,\
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                         KC_LCTL, KC_LGUI, KC_BSPC,     KC_ENT, KC_SPC, KC_RALT),\
//                                      `--------------------------'  `--------------------------'

[_LOWER] = LAYOUT( \

//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TAB,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,   KC_9,    KC_0,    KC_DEL, \
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_ESC,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, KC_NO,   KC_NO,  \
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LSFT,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,  \
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_ENT, KC_SPC, KC_RALT),\
//                                      `--------------------------'  `--------------------------'


[_RAISE] = LAYOUT( \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
   KC_TRNS,  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   KC_TRNS,  KC_NO,    KC_NO,   KC_NO,   KC_NO,  KC_NO,                         KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_PIPE, KC_GRV, \
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   KC_TRNS,  KC_NO,    KC_NO,   KC_NO,   KC_NO,  KC_NO,                         KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,\
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                         KC_TRNS, KC_TRNS, KC_TRNS,    KC_ENT, KC_TRNS, KC_RALT),\
//                                      `--------------------------'  `--------------------------'

[_NUMBER] = LAYOUT( \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
   KC_TRNS,  KC_NO,    KC_NO,   KC_NO,   KC_NO,  KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   KC_TRNS,  KC_NO,    KC_NO,   KC_BTN2, KC_BTN1, KC_NO,                        KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,   KC_NO, \
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                         KC_TRNS, KC_TRNS, KC_TRNS,    KC_ENT, KC_TRNS, KC_RALT), \
//                                      `--------------------------'  `--------------------------'

[_MOUSE] = LAYOUT( \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
   RESET,    EEP_RST,  DEBUG,   KC_NO,   KC_NO,  KC_NO,                         KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_PAST, \
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   KC_TRNS,  KC_NO,    KC_NO,   KC_NO,   KC_NO,  KC_NO,                         KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PMNS, KC_PPLS, \
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_NO,   \
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,       KC_NO, KC_P0, KC_NO), \
//                                      `--------------------------'  `--------------------------'

[_ADJUST] = LAYOUT( \
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    RESET,   EEP_RST, DEBUG,   BL_ON,   BL_INC, RGB_MOD,                       RGB_HUI, RGB_VAI,  RGB_SPI, RGB_SAI, RGB_M_P, RGB_M_B,\
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    RGB_TOG, BL_TOGG, BL_STEP, BL_OFF,  BL_DEC, RGB_RMOD,                      RGB_HUD, RGB_VAD,  RGB_SPD, RGB_SAD, RGB_M_R, RGB_M_SW,\
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_NO,   KC_NO,    RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G,\
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,       KC_NO, KC_NO, KC_NO)
//                                      `--------------------------'  `--------------------------'
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_LOWER);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_RAISE);
      }
      return false;
    case NUMBER:
        if (record->event.pressed) {
        set_single_persistent_default_layer(_NUMBER);
      }
      return false;
    case MOUSE:
        if (record->event.pressed) {
        set_single_persistent_default_layer(_MOUSE);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
        set_single_persistent_default_layer(_ADJUST);
      }
      return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}

uint8_t prev = _QWERTY;
uint32_t desired = 1;
uint16_t hue = 120;
uint16_t sat = 255;
uint16_t val = 255;

void get_hsv(void) {
	hue = rgblight_get_hue();
	sat = rgblight_get_sat();
	val = rgblight_get_val();
}

void reset_hsv(void) {
	rgblight_sethsv(hue, sat, val);
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif

	rgblight_mode(desired);
	rgblight_enable();
	reset_hsv();
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  if (prev!=_ADJUST) {
	  switch (layer) {
		case _QWERTY:
		  rgblight_mode(desired);
		  if(desired < 6 || (desired > 14 && desired < 25)) { // Skip in rainbow modes.
			reset_hsv();
		  }
		  break;

		case _LOWER:
		  rgblight_mode(5);
//		  rgblight_sethsv(0, 255, 255);
		  break;

		case _RAISE:
		  rgblight_mode(19);
//		  rgblight_sethsv(240, 255, 255);
		  break;

		case _NUMBER:
		  rgblight_mode(4);
//		  rgblight_sethsv(230, 250, 255);
		  break;

		case _MOUSE:
		  rgblight_mode(3);
//		  rgblight_sethsv(220, 220, 255);
		  break;
		case _ADJUST:
		  break;
	  }
  } else {
	  desired = rgblight_get_mode();
	  get_hsv();
  }
  prev = layer;
  return state;
}

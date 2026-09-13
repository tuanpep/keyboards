#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define DF_QWE DF(_QWERTY)
#define DF_CMK DF(_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_split_3x6_3(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                        KC_LGUI, LOWER,   KC_SPC,     KC_ENT,  RAISE,   KC_RALT
),
[_COLEMAK] = LAYOUT_split_3x6_3(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                        KC_LGUI, LOWER,   KC_SPC,     KC_ENT,  RAISE,   KC_RALT
),
[_LOWER] = LAYOUT_split_3x6_3(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12,
                                        _______, _______, _______,   _______, _______, _______
),
[_RAISE] = LAYOUT_split_3x6_3(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PIPE, KC_TILD,
    _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, XXXXXXX,                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_MUTE, KC_MPLY,
                                        _______, _______, _______,   _______, _______, _______
),
[_ADJUST] = LAYOUT_split_3x6_3(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
    XXXXXXX, DF_QWE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, DF_CMK,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, _______, _______,   _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

bool oled_task_user(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _QWERTY:  oled_write_ln_P(PSTR("QWERTY"), false); break;
        case _COLEMAK: oled_write_ln_P(PSTR("ColemakDH"), false); break;
        case _LOWER:   oled_write_ln_P(PSTR("Lower"), false); break;
        case _RAISE:   oled_write_ln_P(PSTR("Raise"), false); break;
        case _ADJUST:  oled_write_ln_P(PSTR("Adjust"), false); break;
        default:       oled_write_ln_P(PSTR("?"), false); break;
    }
    return false;
}
#endif

#include QMK_KEYBOARD_H

enum layers {
    _BASE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = {
        { KC_Q, KC_W, KC_E }, 
        { KC_A, KC_S, KC_D },
        { KC_Z, KC_X, KC_C }  
    }
};


void matrix_scan_user(void) {
    static bool prev_gp7 = false;
    static bool prev_gp6 = false;
    static bool prev_gp10 = false;

    bool gp7 = !readPin(GP7);
    bool gp6 = !readPin(GP6);
    bool gp10 = !readPin(GP10);

    if (gp7 && !prev_gp7) {
        tap_code(KC_ENTER);
    }

    if (gp6 && !prev_gp6) {
        tap_code(KC_ESC);
    }

    if (gp10 && !prev_gp10) {
        tap_code(KC_MUTE);
    }

    prev_gp7 = gp7;
    prev_gp6 = gp6;
    prev_gp10 = gp10;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);   // Volume up
        } else {
            tap_code(KC_VOLD);   // Volume down
        }
    }
    return true;
}
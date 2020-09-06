/*
Author: Oliver Reams
Date:   2020-09-03
Name:   hmmm.keymap.c
Board:  keebio/bdn9/rev1
*/
#include QMK_KEYBOARD_H

//Encoder declarations
enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

// Tap Dance declarations
enum {
    TD_TAB_ENTR
};


// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_TAB_ENTR] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ENTER),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
        | Knob 1: Vol Dn/Up |      | Knob 2: Page Dn/Up |
        | Press: Play       | Home | Press: TO 1        |
        | Previous          | Up   | Next               |
        | Left              | Down | Right              |
     */
	[0] = LAYOUT(KC_MPLY, KC_HOME, TO(1), KC_MPRV, KC_UP, KC_MNXT, KC_LEFT, KC_DOWN, KC_RGHT),
    // /*
    //     | Knob 1: Vol Dn/Up |           | Knob 2: Page Dn/Up |
    //     | Press: Play       |  Page Up  | Press: TO 2        |
    //     | Browser Search    | Page Down | Browser Refresh    |
    //     | Browser Back      |   Home    | Browser Forward    |
    //  */	
    // [1] = LAYOUT(KC_MPLY, KC_PGUP, TO(2), KC_WSCH, KC_PGDN, KC_WREF, KC_WBAK, KC_HOME, KC_WFWD),
   
   /*
        | Knob 1: Vol Dn/Up |           | Knob 2: Page Dn/Up |
        | Press: Play       |  Escape   | Press: TO 2        |
        | Tab/Enter         |    Up     | Browser Refresh    |
        | Browser Back      |   Down    | Browser Forward    |
     */	
    [1] = LAYOUT(KC_MPLY, KC_ESC, TO(2), TD(TD_TAB_ENTR), KC_UP, KC_WREF, KC_WBAK, KC_DOWN, KC_WFWD),


    /*
        | Knob 1: Vol Dn/Up |           | Knob 2: Page Dn/Up |
        | Press: BL Breathe |    BL+    | Press: TO 0        |
        | Brightness Up     |    BL-    | BL Toggle          |
        | Brightness Down   | RGB Mode- | RGB Mode +         |
     */	
    [2] = LAYOUT(BL_BRTG, BL_INC, TO(0), KC_BRIU, BL_DEC, BL_TOGG, KC_BRID, RGB_RMOD, RGB_MOD)
};



void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == _MIDDLE) {
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    else if (index == _RIGHT) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}


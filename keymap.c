#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_dvp.h" // DP_ for dvorak key
#include "personal.h"

// Layer definitions
enum {
    BASE = 0,   // default layer
    SYMB,       // the bunch of symbols I can never remember
    FKEY,       // Function keys, media
    NUMB,       // number keys
    SUBL,       // Sublime Text
    SKCH,       // Bohemian Sketch
    WIN,        // Windows
    WIN_SYMB,        // Windows Symbols
    NMS_GND,    // No Man's Sky - Ground
    NMS_FLT,    // No Man's Sky - Flight
    OC,         // Overcooked
    PLVR,       // Plover
    _DYN,       // Dynamic Macro Recording (I think it should be last)
};

// OS-specific keys
#define SUPER KC_LGUI
#define SUPER_WIN KC_LCTL
#define MOD(x) (LGUI(x)) // CMD in OSX
#define SMOD(x) (SCMD(x)) // SHIFT CMD in OSX

#define SCRN_SHOT LCTL(LSFT(MOD(KC_4)))
#define SCRN_SAVE LSFT(MOD(KC_4))

// Sketch Layer
#define ICON_ADD HYPR(KC_I)
#define ICON_OUTLINE HYPR(KC_O)
#define DISTR LCTL(LALT(KC_D))
#define SWAP LCTL(LSFT(MOD(KC_L)))
#define ARTB_PREV LSFT(MOD(KC_LBRC))
#define ARTB_NEXT LSFT(MOD(KC_RBRC))
#define RUNR_GO_TO HYPR(KC_G)
#define RUNR_APPLY HYPR(KC_A)
#define RUNR_CREATE HYPR(KC_C)
#define RUNR_INSERT HYPR(KC_N)
#define RUNR_RUN MOD(KC_QUOT)

#define ALGN_LEFT HYPR(KC_LEFT)
#define ALGN_RIGHT HYPR(KC_RIGHT)
#define ALGN_BOTT HYPR(KC_DOWN)
#define ALGN_TOP HYPR(KC_UP)

#define STYLE_CREATE MEH(KC_S)
#define STYLE_COPY LALT(MOD(KC_C))
#define STYLE_PASTE LALT(MOD(KC_V))

#define POS_COPY LCTL(LSFT(KC_C))
#define POS_PASTE LCTL(LSFT(KC_P))

#define TOG_HIDE LSFT(MOD(KC_H))
#define TOG_LOCK LSFT(MOD(KC_L))
#define LAYER_FRONT LCTL(LALT(MOD(KC_UP)))
#define LAYER_BACK LCTL(LALT(MOD(KC_DOWN)))
#define LAYER_FORWARD LALT(MOD(KC_UP))
#define LAYER_BACKWARD LALT(MOD(KC_DOWN))
#define LAYER_COLLAPSE HYPR(KC_S)
#define LAYER_REVEAL LSFT(MOD(KC_J))

// resize artboard to fit
// align to
// user flows add connection
// user flows create diagram
// Zoom Artboard to Fit ( cmd+4 )
// fluid

// SUBL Layer
#define COM_PAL SMOD(KC_P)

#define JMP_WORD MEH(KC_SCLN)
#define JMP_CHAR MEH(KC_QUOT)
#define JMP_LINE MEH(KC_DOT)
#define JMP_IN_LINE HYPR(KC_COMM)
#define JMP_SELECT HYPR(KC_SCLN)
#define JMP_ADD_CURSOR HYPR(KC_QUOT)

#define BKMK_TOG MOD(KC_F2)
#define BKMK_NEXT KC_F2
#define BKMK_PREV LSFT(KC_F2)
#define BKMK_CLEAR SMOD(KC_F2)

#define STEP_IN KC_F11
#define STEP_OVER KC_F10
#define STEP_OUT LSFT(KC_F11)

#define FILE_DUP HYPR(KC_D)
#define FILE_REN HYPR(KC_R)

#define SETTING_WDWP MEH(KC_W)

#define DEL_LINE LSFT(LCTL(KC_K))
#define DEL_TO_EOL HYPR(KC_RBRC)
#define DEL_TO_SOL HYPR(KC_LBRC)

#define VIEW_PREV SMOD(KC_LBRC)

#define VIEW_NEXT SMOD(KC_RBRC)

#define SEL_WORD MOD(KC_D)
#define SEL_LINE MOD(KC_L)
#define SEL_QUOT MOD(KC_QUOT)
#define SEL_IND LSFT(MOD(KC_J))
#define SEL_TAG LSFT(MOD(KC_A))
#define SEL_BRC LSFT(LCTL(KC_M))

#define SEL_SPLIT SMOD(KC_L)
#define SEL_SPLIT_CHAR LALT(MOD(KC_COMM))
#define FILE_OPEN_REC LALT(SMOD(KC_T))
#define MATCH_BRACE MOD(KC_M)
#define MATCH_BRACE_SEL SMOD(KC_M)
#define PRESERVE_CASE HYPR(KC_P)
#define CRSR_BACK LCTL(KC_MINS)
#define CRSR_FWD LSFT(LCTL(KC_MINS))
// origami: cmd+k, shift arrow to jump to, cmd to create to, shift+cmd to destroy "to"


/*======================================
=            FN Definitions            =
======================================*/

enum {
    JL_NUMB = 0,   // Tap toggle Number layer
    JL_SKCH,       // Tap toggle Sketch layer
};

const uint16_t PROGMEM fn_actions[] = {
    [JL_NUMB] = ACTION_LAYER_TAP_TOGGLE(NUMB),
    [JL_SKCH] = ACTION_LAYER_TAP_TOGGLE(SKCH),
};

/*=====  End of FN Definitions  ======*/



/*=========================================
=            Macro Definitions            =
=========================================*/

// Macro Definitions
enum {
  PLVR_TOG = 0,     // Plover toggle
  PLVR_DICT,        // Plover add to dictionary
  PLVR_LOOK,        // Plover lookup dictionary
  PLVR_RESET,       // Plover reset output
  PLVR_UP_LAST,     // Plover upper case last word
  PLVR_LO_LAST,     // Plover lower case last word
  PLVR_TOG_AST,     // Plover toggle asterisk
  PLVR_ADD_SP,      // Plover retroactively add space
  PLVR_REM_SP,      // Plover retroactively remove space
  DBL_P0,           // 00
  CLEAR_MODS,       // Sends up key on all mods

  WORK_ID,
  WORK_USER,
  WORK_EMAIL,
  WORK_PH,
  PER_ID,
  PER_USER,
  PER_PH,
  PER_EMAIL,

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {

    case PLVR_TOG: {
        if (record->event.pressed) {
            // this will be interpreted by my Plover dictionary to toggle steno mode
            return MACRO( D(A), D(W), D(H), D(I), D(K), D(N), W(10), U(A), U(W), U(H), U(I), U(K), U(N), END);
        }
        break;
    }
    case PLVR_DICT: {
        if (record->event.pressed) {
            // This will be interpreted by my Plover dictionary to open up the dictionary
            return MACRO( D(W), D(S), D(N), D(M), D(K), D(L), D(P), D(H), W(10), U(W), U(S), U(N), U(M), U(K), U(L), U(P), U(H), END);
        }
    }
    case PLVR_LOOK: {
        if (record->event.pressed) {
            return MACRO( D(W), D(S), D(N), D(M), D(K), D(L), D(P), W(10), U(W), U(S), U(N), U(M), U(K), U(L), U(P), END);
        }
    }
    case PLVR_RESET: {
        if (record->event.pressed) {
            return MACRO( D(F), D(N), D(H), D(U), D(P), W(10), U(F), U(N), U(H), U(U), U(P), END);
        }
    }
    case PLVR_UP_LAST: {
        if (record->event.pressed) {
            return MACRO( D(H), D(M), D(I), D(LBRC), W(10), U(H), U(M), U(I), U(LBRC), END);
        }
    }
    case PLVR_LO_LAST: {
        if (record->event.pressed) {
            return MACRO(D(R), D(F), D(V), D(N), D(H), D(J), D(LBRC), W(10), U(R), U(F), U(V), U(N), U(H), U(J), U(LBRC), END);
        }
    }
    case PLVR_TOG_AST: {
        if (record->event.pressed) {
            return MACRO( D(1), D(H), W(10), U(1), U(H), END);
        }
    }
    case PLVR_ADD_SP: {
        if (record->event.pressed) {
            return MACRO( D(C), D(U), D(I), D(SCLN), W(10), U(C), U(U), U(I), U(SCLN), END);
        }
    }
    case PLVR_REM_SP: {
        if (record->event.pressed) {
            return MACRO( D(W), D(S), D(U), D(I), D(SCLN), W(10), U(W), U(S), U(U), U(I), U(SCLN), END);
        }
    }
    case DBL_P0: {
        if (record->event.pressed) {
            // puts down two 0s
            return MACRO( T(P0), T(P0), END );
        }
    }
    case CLEAR_MODS: {
        if (record->event.pressed) {
            // sometimes QMK will send a stuck mod keypress. This hopefully clears them.
            clear_mods();
            return false;
        }
    }
    case WORK_ID: {
        if (record->event.pressed) {
            SEND_STRING(_WORK_ID);
            return false;
        }
    }
    case WORK_USER: {
        if (record->event.pressed) {
            SEND_STRING(_WORK_USER);
            return false;
        }
    }
    case WORK_EMAIL: {
        if (record->event.pressed) {
            SEND_STRING(_WORK_EMAIL);
            return false;
        }
    }
    case WORK_PH: {
        if (record->event.pressed) {
            SEND_STRING(_WORK_PHONE);
            return false;
        }
    }
    case PER_ID: {
        if (record->event.pressed) {
            SEND_STRING(_PER_ID);
            return false;
        }
    }
    case PER_USER: {
        if (record->event.pressed) {
            SEND_STRING(_PER_USER);
            return false;
        }
    }
    case PER_PH: {
        if (record->event.pressed) {
            SEND_STRING(_PER_PHONE);
            return false;
        }
    }
    case PER_EMAIL: {
        if (record->event.pressed) {
            SEND_STRING(_PER_EMAIL);
            return false;
        }
    }





  }
  return MACRO_NONE;
};

/*=====  End of Macro Definitions  ======*/



/*=====================================
=            Dynamic Macro            =
=====================================*/

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV,
  DYNAMIC_MACRO_RANGE,
};

void backlight_toggle(void) {
    ergodox_board_led_on();
}

#include "dynamic_macro.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
    // <...THE REST OF THE FUNCTION...>
    return true;
}

/*=====  End of Dynamic Macro  ======*/


/*===============================================
=            Tap Dance Configuration            =
===============================================*/

// Declarations
enum {
    JL_CP = 0,      // Paste on single tap, Copy on double tap
    JL_CP_WIN,      // Windows: Paste on single tap, Copy on double tap

    JL_SCRN,          // Single: copy screenshot, Double: save screenshot to file

    SKCH_ICON,        // Single: insert icon, Double: convert icon to outline
    SKCH_LAYER_LIST,  // Single: collapse, Double: Reveal in layer list
    SKCH_SYMBOL,      // Single: insert symbol, Double: create symbol

    SUBL_SEL_WQ,      // Single: select word, Double: select quoted
    SUBL_SEL_LI,      // Single: select line, Double: select indent
    SUBL_SEL_BT,      // Single: select bracket, Double: select tag
    SUBL_FILE_RD,     // Single: rename file, Double: duplicate file
    SUBL_BRACES,      // Single: go to matching brace, Double: select to matching brace
    SUBL_SPLIT,       // Single: split lines, Double: split lines by regex

};

static void copy_paste (qk_tap_dance_state_t *state, void *user_data) {

    switch (state->count) {
        case 1:
            register_code (SUPER);
            register_code (KC_V);
            unregister_code (KC_V);
            unregister_code (SUPER);
            break;
        case 2:
            register_code (SUPER);
            register_code (KC_C);
            unregister_code (KC_C);
            unregister_code (SUPER);
            break;
        case 3:
            register_code (SUPER);
            register_code (KC_X);
            unregister_code (KC_X);
            unregister_code (SUPER);
            reset_tap_dance (state);
            break;

    }
}


static void copy_paste_win (qk_tap_dance_state_t *state, void *user_data) {

    switch (state->count) {
        case 1:
            register_code (SUPER_WIN);
            register_code (KC_V);
            unregister_code (KC_V);
            unregister_code (SUPER_WIN);
            break;
        case 2:
            register_code (SUPER_WIN);
            register_code (KC_C);
            unregister_code (KC_C);
            unregister_code (SUPER_WIN);
            break;
        case 3:
            register_code (SUPER_WIN);
            register_code (KC_X);
            unregister_code (KC_X);
            unregister_code (SUPER_WIN);
            reset_tap_dance (state);
            break;

    }
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [JL_CP] = ACTION_TAP_DANCE_FN (copy_paste),
    [JL_CP_WIN] = ACTION_TAP_DANCE_FN (copy_paste_win),

    [JL_SCRN] = ACTION_TAP_DANCE_DOUBLE(SCRN_SHOT, SCRN_SAVE),

    [SKCH_ICON] = ACTION_TAP_DANCE_DOUBLE(ICON_ADD, ICON_OUTLINE),
    [SKCH_LAYER_LIST] = ACTION_TAP_DANCE_DOUBLE(LAYER_REVEAL, LAYER_COLLAPSE),
    [SKCH_SYMBOL] = ACTION_TAP_DANCE_DOUBLE(RUNR_INSERT, RUNR_CREATE),

    [SUBL_SEL_WQ] = ACTION_TAP_DANCE_DOUBLE(SEL_WORD, SEL_QUOT),
    [SUBL_SEL_LI] = ACTION_TAP_DANCE_DOUBLE(SEL_LINE, SEL_IND),
    [SUBL_SEL_BT] = ACTION_TAP_DANCE_DOUBLE(SEL_BRC, SEL_TAG),
    [SUBL_FILE_RD] =  ACTION_TAP_DANCE_DOUBLE(FILE_REN, FILE_DUP),
    [SUBL_BRACES] = ACTION_TAP_DANCE_DOUBLE(MATCH_BRACE, MATCH_BRACE_SEL),
    [SUBL_SPLIT] = ACTION_TAP_DANCE_DOUBLE(SEL_SPLIT, SEL_SPLIT_CHAR),

};

/*=====  End of Tap Dance Configuration  ======*/

/*===============================================
=             Unicode Configuration             =
===============================================*/

#define SMILE 0x263A


/*=====  End of Unicode Configuration  ======*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// see tmk_core/common/keycode.h
// see quantum/quantum_keycodes.h
// AlignTab Regex: /\*\*//l2
// Wrapping required keycodes around (parens), typically for MO() and getting back to original layer

[BASE] = LAYOUT_ergodox(
//  /**/  ------------------   /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------    /**/
    /**/  KC_GRV,              /**/  KC_LT,              /**/  KC_LBRC,            /**/  KC_LCBR,            /**/  KC_LPRN,            /**/  KC_EQL,             /**/  TD(JL_SCRN),          /**/
    /**/  KC_TAB,              /**/  KC_SCLN,            /**/  KC_COMM,            /**/  KC_DOT,             /**/  KC_P,               /**/  KC_Y,               /**/  MO(SYMB),             /**/
    /**/  KC_ENT,              /**/  KC_A,               /**/  KC_O,               /**/  KC_E,               /**/  KC_U,               /**/  KC_I,               /**/                        /**/
    /**/  KC_LSFT,             /**/  KC_QUOT,            /**/  KC_Q,               /**/  KC_J,               /**/  KC_K,               /**/  KC_X,               /**/  KC_DEL,               /**/
    /**/  KC_LCTL,             /**/  MO(FKEY),           /**/  MO(SUBL),           /**/  MO(SKCH),           /**/  MO(NUMB),           /**/                      /**/                        /**/

    /**/                       /**/                      /**/                      /**/                      /**/                      /**/  KC_LALT,            /**/  KC_HOME,              /**/
    /**/                       /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_END,               /**/
    /**/                       /**/                      /**/                      /**/                      /**/  KC_SPC,             /**/  KC_LGUI,            /**/  MO(_DYN),             /**/


    /**/  TD(JL_CP),           /**/  KC_GT,              /**/  KC_RPRN,            /**/  KC_RCBR,            /**/  KC_RBRC,            /**/  KC_EXLM,            /**/  TO(WIN),              /**/
    /**/  LT(SYMB, KC_PGUP),   /**/  KC_F,               /**/  KC_G,               /**/  KC_C,               /**/  KC_R,               /**/  KC_L,               /**/  KC_SLSH,              /**/
    /**/                       /**/  KC_D,               /**/  KC_H,               /**/  KC_T,               /**/  KC_N,               /**/  KC_S,               /**/  KC_MINS,              /**/
    /**/  KC_PGDN,             /**/  KC_B,               /**/  KC_M,               /**/  KC_W,               /**/  KC_V,               /**/  KC_Z,               /**/  KC_RSFT,              /**/
    /**/                       /**/                      /**/  KC_LEFT,            /**/  KC_DOWN,            /**/  KC_UP,              /**/  KC_RGHT,            /**/  KC_SPC,               /**/

    /**/  KC_TRNS,             /**/  KC_RALT,            /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  KC_TRNS,             /**/                      /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  KC_ESC,              /**/  KC_RGUI,            /**/  KC_BSPC             /**/                      /**/                      /**/                      /**/                        /**/
    ),


    /*
    & aNd
    % Percent
    ~ Tilde
    $ Dollar
    = Equal
    * Star
    ! eXclaim
    # Hash
    ` backticK
    @ At
    ^ Caret
    \ Backslash
    | pIpe
     */


[SYMB] = LAYOUT_ergodox(
//  /**/  ------------------   /**/  q                   /**/  w                   /**/  e                   /**/  r                   /**/  t                   /**/  ------------------    /**/
//  /**/  ------------------   /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------    /**/
    /**/  KC_TRNS,             /**/  KC_7,               /**/  KC_5,               /**/  KC_3,               /**/  KC_1,               /**/  KC_9,               /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_PERC,            /**/  KC_TRNS,            /**/  (KC_TRNS),            /**/
    /**/  KC_TRNS,             /**/  KC_AT,              /**/  KC_TRNS,            /**/  KC_EQL,             /**/  KC_TRNS,            /**/  KC_PIPE,            /**/                        /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_GRV,             /**/  KC_EXLM,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/                      /**/                        /**/

    /**/                       /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/                       /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,              /**/
    /**/                       /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/

//  /**/  ------------------   /**/  y                   /**/  u                   /**/  i                   /**/  o                   /**/  p                   /**/  ------------------    /**/
    /**/  KC_TRNS,             /**/  KC_0,               /**/  KC_2,               /**/  KC_4,               /**/  KC_6,               /**/  KC_8,               /**/  KC_TRNS,              /**/
    /**/  (KC_TRNS),           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_CIRC,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/                       /**/  KC_DLR,             /**/  KC_HASH,            /**/  KC_TILD,            /**/  KC_AMPR,            /**/  KC_ASTR,            /**/  UC(SMILE),            /**/
    /**/  KC_TRNS,             /**/  KC_BSLS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/                       /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/

    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  KC_TRNS,             /**/                      /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS             /**/                      /**/                      /**/                      /**/                        /**/
    ),


[FKEY] = LAYOUT_ergodox(
//  /**/  ------------------   /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------    /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_MUTE,              /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_VOLU,              /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/                        /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_VOLD,              /**/
    /**/  KC_TRNS,             /**/  (KC_TRNS),          /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  (KC_TRNS),          /**/                      /**/                        /**/

    /**/                       /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/                       /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,              /**/
    /**/                       /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/  KC_MPLY,            /**/  KC_TRNS,              /**/


    /**/  TD(JL_SCRN),         /**/  KC_TRNS,            /**/  KC_F10,             /**/  KC_F11,             /**/  KC_F12,             /**/  KC_TRNS,            /**/  RESET,                /**/
    /**/  KC_MS_WH_DOWN,       /**/  KC_TRNS,            /**/  KC_F7,              /**/  KC_F8,              /**/  KC_F9,              /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/                       /**/  KC_TRNS,            /**/  KC_F4,              /**/  KC_F5,              /**/  KC_F6,              /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_MS_WH_UP,         /**/  KC_TRNS,            /**/  KC_F1,              /**/  KC_F2,              /**/  KC_F3,              /**/  KC_TRNS,            /**/  KC_CAPS,              /**/
    /**/                       /**/                      /**/  KC_MS_LEFT,         /**/  KC_MS_DOWN,         /**/  KC_MS_UP,           /**/  KC_MS_RIGHT,        /**/  KC_TRNS,              /**/

    /**/  KC_TRNS,             /**/  KC_MS_BTN3,         /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  KC_TRNS,             /**/                      /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  M(CLEAR_MODS),       /**/  KC_MS_BTN2,         /**/  KC_MS_BTN1          /**/                      /**/                      /**/                      /**/                        /**/
    ),



[SUBL] = LAYOUT_ergodox(
//  /**/  5                    /**/  4                   /**/  3                   /**/  2                   /**/  1                   /**/  1'                  /**/  2'                    /**/
//  /**/  ------------------   /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------    /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/                        /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/                      /**/                        /**/
    /**/                       /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/                       /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,              /**/
    /**/                       /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/

//  /**/  2'                   /**/  1'                  /**/  1                   /**/  2                   /**/  3                   /**/  4                   /**/  5                     /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  SETTING_WDWP,       /**/  TD(SUBL_SEL_BT),    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  CRSR_BACK,           /**/  JMP_IN_LINE,        /**/  JMP_LINE,           /**/  TD(SUBL_SEL_LI),    /**/  JMP_ADD_CURSOR,     /**/  KC_TRNS,            /**/  TD(SUBL_FILE_RD),     /**/
    /**/                       /**/  JMP_SELECT,         /**/  JMP_CHAR,           /**/  TD(SUBL_BRACES),    /**/  TD(SUBL_SPLIT),     /**/  PRESERVE_CASE,      /**/  FILE_OPEN_REC,        /**/
    /**/  CRSR_FWD,            /**/  KC_TRNS,            /**/  JMP_WORD,           /**/  TD(SUBL_SEL_WQ),    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/                       /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/

    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  KC_TRNS,             /**/                      /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  COM_PAL             /**/                      /**/                      /**/                      /**/                        /**/
    ),



[SKCH] = LAYOUT_ergodox(
//  /**/  5                    /**/  4                   /**/  3                   /**/  2                   /**/  1                   /**/  1'                  /**/  2'                    /**/
//  /**/  ------------------   /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------    /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/                        /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/                      /**/                        /**/

    /**/                       /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/                       /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,              /**/
    /**/                       /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/

//  /**/  2'                   /**/  1' Reposition       /**/  1 Editing           /**/  2 Add               /**/  3 Style             /**/  4 Style Grab        /**/  5 Layer Mgmt          /**/
    /**/  TD(JL_SCRN),         /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  LAYER_FORWARD,        /**/
    /**/  ARTB_PREV,           /**/  SWAP,               /**/  TOG_LOCK,           /**/  TD(SKCH_ICON),      /**/  STYLE_PASTE,        /**/  STYLE_COPY,         /**/  LAYER_FRONT,          /**/
    /**/                       /**/  DISTR,              /**/  TOG_HIDE,           /**/  TD(SKCH_SYMBOL),    /**/  RUNR_APPLY,         /**/  STYLE_CREATE,       /**/  TD(SKCH_LAYER_LIST),  /**/
    /**/  ARTB_NEXT,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  POS_PASTE,          /**/  POS_COPY,           /**/  LAYER_BACK,           /**/
    /**/                       /**/                      /**/  ALGN_LEFT,          /**/  ALGN_BOTT,          /**/  ALGN_TOP,           /**/  ALGN_RIGHT,         /**/  LAYER_BACKWARD,       /**/

    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  KC_TRNS,             /**/                      /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  KC_TRNS,             /**/  RUNR_RUN,           /**/  RUNR_GO_TO          /**/                      /**/                      /**/                      /**/                        /**/
    ),


[WIN] = LAYOUT_ergodox(
//  /**/  ------------------   /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/
    /**/  KC_GRV,              /**/  KC_1,               /**/  KC_2,               /**/  KC_3,               /**/  KC_4,               /**/  KC_5,               /**/  KC_PSCR,            /**/
    /**/  KC_TAB,              /**/  KC_Q,               /**/  KC_W,               /**/  KC_E,               /**/  KC_R,               /**/  KC_T,               /**/  MO(SYMB),           /**/
    /**/  KC_ENT,              /**/  KC_A,               /**/  KC_S,               /**/  KC_D,               /**/  KC_F,               /**/  KC_G,               /**/                      /**/
    /**/  KC_LSFT,             /**/  KC_Z,               /**/  KC_X,               /**/  KC_C,               /**/  KC_V,               /**/  KC_B,               /**/  KC_DEL,             /**/
    /**/  KC_LGUI,             /**/  MO(FKEY),           /**/  MO(WIN_SYMB),       /**/  KC_TRNS,            /**/  MO(NUMB),           /**/                      /**/                      /**/

    /**/                        /**/                      /**/                      /**/                      /**/                      /**/  KC_LALT,            /**/  KC_HOME,              /**/
    /**/                        /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_END,               /**/
    /**/                        /**/                      /**/                      /**/                      /**/  KC_SPC,             /**/  KC_LCTL,            /**/  KC_TRNS,              /**/


    /**/  TD(JL_CP_WIN),        /**/  KC_6,               /**/  KC_7,               /**/  KC_8,               /**/  KC_9,               /**/  KC_0,               /**/  TO(NMS_GND),              /**/
    /**/  LT(SYMB, KC_PGUP),    /**/  KC_Y,               /**/  KC_U,               /**/  KC_I,               /**/  KC_O,               /**/  KC_P,               /**/  TO(BASE),              /**/
    /**/                        /**/  KC_H,               /**/  KC_J,               /**/  KC_K,               /**/  KC_L,               /**/  KC_SCLN,            /**/  KC_QUOT,              /**/
    /**/  KC_PGDN,              /**/  KC_N,               /**/  KC_M,               /**/  KC_COMM,            /**/  KC_DOT,             /**/  KC_SLSH,            /**/  KC_RSFT,              /**/
    /**/                        /**/                      /**/  KC_LEFT,            /**/  KC_DOWN,            /**/  KC_UP,              /**/  KC_RGHT,            /**/  KC_RGUI,              /**/

    /**/  KC_TRNS,             /**/  KC_RALT,            /**/                      /**/                      /**/                      /**/                      /**/                      /**/
    /**/  KC_TRNS,             /**/                      /**/                      /**/                      /**/                      /**/                      /**/                      /**/
    /**/  KC_ESC,              /**/  KC_RCTL,            /**/  KC_BSPC             /**/                      /**/                      /**/                      /**/                      /**/
),



[WIN_SYMB] = LAYOUT_ergodox(
//  /**/  ------------------   /**/  q                   /**/  w                   /**/  e                   /**/  r                   /**/  t                   /**/  ------------------  /**/
//  /**/  ------------------   /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/
    /**/  KC_TRNS,             /**/  DP_7,               /**/  DP_5,               /**/  DP_3,               /**/  DP_1,               /**/  DP_9,               /**/  KC_TRNS,            /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_PERC,            /**/  KC_TRNS,            /**/  (KC_TRNS),          /**/
    /**/  KC_TRNS,             /**/  DP_AT,              /**/  KC_TRNS,            /**/  DP_EQL,             /**/  KC_TRNS,            /**/  DP_PIPE,            /**/                      /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  DP_GRV,             /**/  DP_EXLM,            /**/  KC_TRNS,            /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/                      /**/                      /**/

    /**/                        /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/                        /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,              /**/
    /**/                        /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/

//  /**/  ------------------   /**/  y                   /**/  u                   /**/  i                   /**/  o                   /**/  p                   /**/  ------------------  /**/
    /**/  KC_TRNS,             /**/  DP_0,               /**/  DP_2,               /**/  DP_4,               /**/  DP_6,               /**/  DP_8,               /**/  KC_TRNS,            /**/
    /**/  (KC_TRNS),           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  DP_CIRC,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/
    /**/                       /**/  DP_DLR,             /**/  DP_HASH,            /**/  DP_TILD,            /**/  DP_AMPR,            /**/  DP_ASTR,            /**/  KC_TRNS,            /**/
    /**/  KC_TRNS,             /**/  DP_BSLS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/
    /**/                       /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/

    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/                      /**/                      /**/                      /**/                      /**/                      /**/
    /**/  KC_TRNS,             /**/                      /**/                      /**/                      /**/                      /**/                      /**/                      /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS             /**/                      /**/                      /**/                      /**/                      /**/
    ),



//
// No Man's Sky - Ground Controls
//
// Move Forward - W
// Move Backward - S
// Strafe Left - A
// Strafe Right - D
// Quick Menu - X
// Jump / Jetpack - Space
// Swim Up - Space
// Swim Down - Q
// Interact - E
// Melee - Q
// Fire Weapon - Mouse 1
// Fire Secondary Weapon - Mouse 2
// Change Secondary Weapon - Mouse 3
// Reload - R
// Change Weapon Mode - G
// Scan - C
// Scope - F
// Increase Scope Zoom - Mouse 2
// Activate Torch - T
// Show HUD - H
// Player_Deconstruct - Mouse 3
// Build Menu - Z
// Discard Item - Mouse 3
// Galactic Map - M

[NMS_GND] = LAYOUT_ergodox(
//  /**/  ------------------   /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/
    /**/  KC_ESC,              /**/  KC_1,               /**/  KC_2,               /**/  KC_3,               /**/  KC_4,               /**/  KC_5,               /**/  KC_F12,             /**/
    /**/  KC_TAB,              /**/  KC_NO,              /**/  KC_Q,               /**/  KC_W,               /**/  KC_E,               /**/  KC_R,               /**/  KC_SPC,             /**/
    /**/  MT(MOD_LALT, KC_M),  /**/  KC_C,               /**/  KC_A,               /**/  KC_S,               /**/  KC_D,               /**/  KC_F,               /**/                      /**/
    /**/  KC_LSFT,             /**/  KC_Z,               /**/  KC_X,               /**/  KC_NO,              /**/  KC_T,               /**/  KC_H,               /**/  KC_Q,               /**/
    /**/  KC_LCTL,             /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/                      /**/                      /**/

    /**/                       /**/                      /**/                      /**/                      /**/                      /**/  KC_MS_BTN3,         /**/  KC_MS_BTN2,         /**/
    /**/                       /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_NO,              /**/
    /**/                       /**/                      /**/                      /**/                      /**/  KC_SPC,             /**/  KC_G,               /**/  KC_R,               /**/


    /**/  KC_NO,               /**/  KC_6,               /**/  KC_7,               /**/  KC_8,               /**/  KC_9,               /**/  KC_0,               /**/  TO(NMS_FLT),        /**/
    /**/  KC_NO,               /**/  KC_NO,              /**/  KC_Q,               /**/  KC_W,               /**/  KC_E,               /**/  KC_NO,              /**/  TO(WIN),            /**/
    /**/                       /**/  KC_NO,              /**/  KC_A,               /**/  KC_S,               /**/  KC_D,               /**/  KC_NO,              /**/  KC_NO,              /**/
    /**/  KC_NO,               /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/
    /**/                       /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/

    /**/  KC_NO,               /**/  KC_NO,              /**/                      /**/                      /**/                      /**/                      /**/                      /**/
    /**/  KC_NO,               /**/                      /**/                      /**/                      /**/                      /**/                      /**/                      /**/
    /**/  KC_NO,               /**/  KC_NO,              /**/  KC_F                /**/                      /**/                      /**/                      /**/                      /**/
),

//
// No man's sky - flight and vehicle controls
//
// Thrust - W
// Brake - S
// Roll Left - A
// Roll Right - D
// Turn Left - (no default set) -> must set to J
// Turn Right - (no default set) -> must set to L
// Reverse - (no default set) -> must set to K
// Boost - Left Shift
// Exit Ship - E
// Initiate Landing - E
// Fire Weapons - Mouse 1
// Free Look - Left Alt
// Next Target - .
// Previous Target - ,
// Place Checkpoint - V
// Delete Checkpoint - B

[NMS_FLT] = LAYOUT_ergodox(
//  /**/  ------------------   /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------    /**/
    /**/  KC_ESC,              /**/  KC_1,               /**/  KC_2,               /**/  KC_3,               /**/  KC_4,               /**/  KC_5,               /**/  KC_F12,               /**/
    /**/  KC_TAB,              /**/  KC_X,               /**/  KC_Q,               /**/  KC_W,               /**/  KC_E,               /**/  KC_Q,               /**/  KC_DOT,               /**/
    /**/  MT(MOD_LALT, KC_H),  /**/  KC_C,               /**/  KC_A,               /**/  KC_S,               /**/  KC_D,               /**/  KC_V,               /**/                        /**/
    /**/  KC_LSFT,             /**/  KC_Z,               /**/  KC_J,               /**/  KC_K,               /**/  KC_L,               /**/  KC_B,               /**/  KC_COMM,              /**/
    /**/  KC_LCTL,             /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/                      /**/                        /**/

    /**/                       /**/                      /**/                      /**/                      /**/                      /**/  KC_MS_BTN3,         /**/  KC_MS_BTN2,           /**/
    /**/                       /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_NO,                /**/
    /**/                       /**/                      /**/                      /**/                      /**/  KC_SPC,             /**/  KC_G,               /**/  KC_R,                 /**/


    /**/  KC_NO,               /**/  KC_6,               /**/  KC_7,               /**/  KC_8,               /**/  KC_9,               /**/  KC_0,               /**/  TO(OC),                /**/
    /**/  KC_NO,               /**/  KC_NO,              /**/  KC_Q,               /**/  KC_W,               /**/  KC_E,               /**/  KC_NO,              /**/  TO(NMS_GND),           /**/
    /**/                       /**/  KC_NO,              /**/  KC_A,               /**/  KC_S,               /**/  KC_D,               /**/  KC_NO,              /**/  KC_NO,                /**/
    /**/  KC_NO,               /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,                /**/
    /**/                       /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/

    /**/  KC_NO,               /**/  KC_NO,              /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  KC_NO,               /**/                      /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  KC_NO,               /**/  KC_NO,              /**/  KC_F                /**/                      /**/                      /**/                      /**/                        /**/
),



// player 1
// move - wasd
// pickup - lsft
// chop/throw - lctrl
// dash - lalt
// emote - e
//
// player 3
// move - g up, v left, b down, f right
// pickup - j
// chop/throw - k
// dash - m
// emote - h


[OC] = LAYOUT_ergodox(
//  /**/  ------------------   /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------    /**/
    /**/  KC_ESC,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,                /**/
    /**/  KC_NO,               /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,                /**/
    /**/  KC_NO,             /**/  KC_NO,            /**/  KC_NO,              /**/  KC_NO,            /**/  KC_G,            /**/  KC_NO,            /**/                        /**/
    /**/  KC_H,             /**/  KC_NO,            /**/  KC_NO,              /**/  KC_V,              /**/  KC_B,              /**/  KC_F,              /**/  KC_NO,                /**/
    /**/  KC_M,             /**/  KC_K,              /**/  KC_J,              /**/  KC_NO,              /**/  KC_NO,              /**/                      /**/                        /**/

    /**/                       /**/                      /**/                      /**/                      /**/                      /**/  KC_NO,              /**/  KC_NO,                /**/
    /**/                       /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_NO,                /**/
    /**/                       /**/                      /**/                      /**/                      /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,                /**/


    /**/  KC_NO,               /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  TO(PLVR),             /**/
    /**/  KC_NO,               /**/  KC_NO,              /**/  KC_NO,              /**/  KC_W,               /**/  KC_E,              /**/  KC_NO,              /**/  TO(WIN),              /**/
    /**/                       /**/  KC_NO,              /**/  KC_A,               /**/  KC_S,               /**/  KC_D,               /**/  KC_NO,              /**/  KC_NO,                /**/
    /**/  KC_NO,               /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,                /**/
    /**/                       /**/                      /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,                /**/

    /**/  KC_LSFT,             /**/  KC_NO,              /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  KC_LCTL,             /**/                      /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  KC_LALT,             /**/  KC_NO,              /**/  KC_LALT             /**/                      /**/                      /**/                      /**/                        /**/
),


[PLVR] = LAYOUT_ergodox(
//  /**/  ------------------   /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------    /**/
    /**/  KC_NO,               /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,                /**/
    /**/  KC_NO,               /**/  KC_1,               /**/  KC_2,               /**/  KC_3,               /**/  KC_4,               /**/  KC_5,               /**/  M(PLVR_LOOK),         /**/
    /**/  KC_NO,               /**/  KC_Q,               /**/  KC_W,               /**/  KC_E,               /**/  KC_R,               /**/  KC_T,               /**/                        /**/
    /**/  KC_NO,               /**/  KC_A,               /**/  KC_S,               /**/  KC_D,               /**/  KC_F,               /**/  KC_G,               /**/  M(PLVR_DICT),         /**/
    /**/  KC_NO,               /**/  MO(FKEY),           /**/  MO(WIN_SYMB),       /**/  KC_NO,              /**/  MO(NUMB),           /**/                      /**/                        /**/

    /**/                       /**/                      /**/                      /**/                      /**/                      /**/  KC_NO,              /**/  KC_NO,                /**/
    /**/                       /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_NO,                /**/
    /**/                       /**/                      /**/                      /**/                      /**/  KC_C,               /**/  KC_V,               /**/  KC_NO,                /**/


    /**/  MAGIC_TOGGLE_NKRO,   /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  TO(BASE),             /**/
    /**/  M(PLVR_TOG),         /**/  KC_6,               /**/  KC_7,               /**/  KC_8,               /**/  KC_9,               /**/  KC_0,               /**/  TO(WIN),              /**/
    /**/                       /**/  KC_Y,               /**/  KC_U,               /**/  KC_I,               /**/  KC_O,               /**/  KC_P,               /**/  KC_LBRC,              /**/
    /**/  M(PLVR_TOG_AST),     /**/  KC_H,               /**/  KC_J,               /**/  KC_K,               /**/  KC_L,               /**/  KC_SCLN,            /**/  KC_QUOT,              /**/
    /**/                       /**/                      /**/  M(PLVR_REM_SP),     /**/  M(PLVR_LO_LAST),    /**/  M(PLVR_UP_LAST),    /**/  M(PLVR_ADD_SP),     /**/  KC_NO,                /**/

    /**/  KC_NO,               /**/  KC_NO,              /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  KC_NO,               /**/                      /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  M(PLVR_RESET),       /**/  KC_N,               /**/  KC_M                /**/                      /**/                      /**/                      /**/                        /**/
),

[NUMB] = LAYOUT_ergodox(
//  /**/  ------------------   /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------    /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_UP,              /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_LEFT,            /**/  KC_DOWN,            /**/  KC_RIGHT,           /**/  KC_TRNS,            /**/                        /**/
    /**/  KC_F,                /**/  KC_E,               /**/  KC_D,               /**/  KC_C,               /**/  KC_B,               /**/  KC_A,               /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  (KC_TRNS),          /**/                      /**/                        /**/

    /**/                       /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/                       /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,              /**/
    /**/                       /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/


    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_PSLS,            /**/  KC_PAST,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_P7,              /**/  KC_P8,              /**/  KC_P9,              /**/  KC_PMNS,            /**/  KC_TRNS,              /**/
    /**/                       /**/  KC_TRNS,            /**/  KC_P4,              /**/  KC_P5,              /**/  KC_P6,              /**/  KC_PPLS,            /**/  KC_PENT,              /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_P1,              /**/  KC_P2,              /**/  KC_P3,              /**/  KC_TRNS,            /**/  TG(NUMB),             /**/
    /**/                       /**/                      /**/  KC_P0,              /**/  M(DBL_P0),          /**/  KC_PDOT,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/

    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  KC_TRNS,             /**/                      /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS             /**/                      /**/                      /**/                      /**/                        /**/
    ),


[_DYN] = LAYOUT_ergodox(
//  /**/  ------------------   /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------    /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  M(PER_ID),          /**/  M(WORK_ID),         /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  M(PER_EMAIL),       /**/  M(WORK_EMAIL),      /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  M(PER_USER),        /**/  M(WORK_USER),       /**/  KC_TRNS,            /**/                        /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  M(PER_PH),          /**/  M(WORK_PH),         /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/                      /**/                        /**/

    /**/                       /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/                       /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,              /**/
    /**/                       /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  (KC_TRNS),            /**/


    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  DYN_REC_START2,      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/                       /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  DYN_REC_START1,      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/                       /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/

    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  KC_TRNS,             /**/                      /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  DYN_REC_STOP,        /**/  DYN_MACRO_PLAY2,    /**/  DYN_MACRO_PLAY1     /**/                      /**/                      /**/                      /**/                        /**/
    ),


}; // end of keymap definitions


// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    // set_unicode_input_mode(UC_OSX);
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case WIN:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case NMS_GND:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case NMS_FLT:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case OC:
            ergodox_right_led_1_on();
            break;
        case PLVR:
            ergodox_right_led_2_on();
            break;
        case _DYN:
            ergodox_board_led_on();
            break;

        default:
            // none
            break;
    }
};




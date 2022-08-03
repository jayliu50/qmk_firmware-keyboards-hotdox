#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "../../../../quantum/keymap_extras/keymap_dvorak_programmer.h" // DP_ for dvorak key
#include "personal.h"

// Layer definitions
enum layers {
    BASE = 0,   // default layer
    PLVR,       // Plover
    PLVR_FN,    // Plover Functions
    SYMB,       // the bunch of symbols I can never remember
    FKEY,       // Function keys, media
    NUMB,       // number keys
    SKCH,       // Bohemian Sketch
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
enum  custom_keycodes {
  VRSN = SAFE_RANGE,
  PLVR_TOG,     // Plover toggle
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
  PRO_EMAIL,
  ADDR_STREET,
  ADDR_CITY,
  ADDR_STATE,
  ADDR_ZIP,

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch(keycode) {

    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;


    case PLVR_TOG: {
        if (record->event.pressed) {
            // this will be interpreted by my Plover dictionary to toggle steno mode
            // return MACRO( D(A), D(W), D(H), D(I), D(K), D(N), W(10), U(A), U(W), U(H), U(I), U(K), U(N), END);
        }
        break;
    }
    case PLVR_DICT: {
        if (record->event.pressed) {
            // This will be interpreted by my Plover dictionary to open up the dictionary
            // return MACRO( D(W), D(S), D(N), D(M), D(K), D(L), D(P), D(H), W(10), U(W), U(S), U(N), U(M), U(K), U(L), U(P), U(H), END);
        }
    }
    case PLVR_LOOK: {
        if (record->event.pressed) {
            // return MACRO( D(W), D(S), D(N), D(M), D(K), D(L), D(P), W(10), U(W), U(S), U(N), U(M), U(K), U(L), U(P), END);
        }
    }
    case PLVR_RESET: {
        if (record->event.pressed) {
            // return MACRO( D(F), D(N), D(H), D(U), D(P), W(10), U(F), U(N), U(H), U(U), U(P), END);
        }
    }
    case PLVR_UP_LAST: {
        if (record->event.pressed) {
            // return MACRO( D(H), D(M), D(I), D(LBRC), W(10), U(H), U(M), U(I), U(LBRC), END);
        }
    }
    case PLVR_LO_LAST: {
        if (record->event.pressed) {
            // return MACRO(D(R), D(F), D(V), D(N), D(H), D(J), D(LBRC), W(10), U(R), U(F), U(V), U(N), U(H), U(J), U(LBRC), END);
        }
    }
    case PLVR_TOG_AST: {
        if (record->event.pressed) {
            // return MACRO( D(1), D(H), W(10), U(1), U(H), END);
        }
    }
    case PLVR_ADD_SP: {
        if (record->event.pressed) {
            // return MACRO( D(C), D(U), D(I), D(SCLN), W(10), U(C), U(U), U(I), U(SCLN), END);
        }
    }
    case PLVR_REM_SP: {
        if (record->event.pressed) {
            // return MACRO( D(W), D(S), D(U), D(I), D(SCLN), W(10), U(W), U(S), U(U), U(I), U(SCLN), END);
        }
    }
    case DBL_P0: {
        if (record->event.pressed) {
            SEND_STRING("00");
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
    case PRO_EMAIL: {
        if (record->event.pressed) {
            SEND_STRING(_PRO_EMAIL);
            return false;
        }
    }
    case ADDR_STREET: {
        if (record->event.pressed) {
            SEND_STRING(_ADDR_STREET);
            return false;
        }
    }
    case ADDR_CITY: {
        if (record->event.pressed) {
            SEND_STRING(_ADDR_CITY);
            return false;
        }
    }
    case ADDR_STATE: {
        if (record->event.pressed) {
            SEND_STRING(_ADDR_STATE);
            return false;
        }
    }
    case ADDR_ZIP: {
        if (record->event.pressed) {
            SEND_STRING(_ADDR_ZIP);
            return false;
        }
    }
  }
    // <...THE REST OF THE FUNCTION...>
    return true;
}

/*=====  End of Macro Definitions ======*/


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




qk_tap_dance_action_t tap_dance_actions[] = {
    [JL_CP] = ACTION_TAP_DANCE_FN (copy_paste),

    [JL_SCRN] = ACTION_TAP_DANCE_DOUBLE(SCRN_SHOT, SCRN_SAVE),

    [SKCH_ICON] = ACTION_TAP_DANCE_DOUBLE(ICON_ADD, ICON_OUTLINE),
    [SKCH_LAYER_LIST] = ACTION_TAP_DANCE_DOUBLE(LAYER_REVEAL, LAYER_COLLAPSE),
    [SKCH_SYMBOL] = ACTION_TAP_DANCE_DOUBLE(RUNR_INSERT, RUNR_CREATE),

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
//  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/
    /**/  KC_GRV,             /**/  KC_LT,              /**/  KC_LBRC,            /**/  KC_LCBR,            /**/  KC_LPRN,            /**/  KC_EQL,             /**/  TD(JL_SCRN),        /**/
    /**/  KC_TAB,             /**/  KC_SCLN,            /**/  KC_COMM,            /**/  KC_DOT,             /**/  KC_P,               /**/  KC_Y,               /**/  MO(SYMB),           /**/
    /**/  KC_ENT,             /**/  KC_A,               /**/  KC_O,               /**/  KC_E,               /**/  KC_U,               /**/  KC_I,               /**/                      /**/
    /**/  KC_LSFT,            /**/  KC_QUOT,            /**/  KC_Q,               /**/  KC_J,               /**/  KC_K,               /**/  KC_X,               /**/  KC_DEL,             /**/
    /**/  KC_LGUI,            /**/  MO(FKEY),           /**/  KC_TRNS,            /**/  MO(SKCH),           /**/  MO(NUMB),           /**/                      /**/                      /**/

    /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_LALT,            /**/  KC_HOME,            /**/
    /**/                      /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_END,             /**/
    /**/                      /**/                      /**/                      /**/                      /**/  KC_SPC,             /**/  KC_LCTL,            /**/  MO(_DYN),           /**/


    /**/  TD(JL_CP),          /**/  KC_GT,              /**/  KC_RPRN,            /**/  KC_RCBR,            /**/  KC_RBRC,            /**/  KC_EXLM,            /**/  TG(PLVR),           /**/
    /**/  LT(SYMB, KC_PGUP),  /**/  KC_F,               /**/  KC_G,               /**/  KC_C,               /**/  KC_R,               /**/  KC_L,               /**/  KC_SLSH,            /**/
    /**/                      /**/  KC_D,               /**/  KC_H,               /**/  KC_T,               /**/  KC_N,               /**/  KC_S,               /**/  KC_MINS,            /**/
    /**/  KC_PGDN,            /**/  KC_B,               /**/  KC_M,               /**/  KC_W,               /**/  KC_V,               /**/  KC_Z,               /**/  KC_RSFT,            /**/
    /**/                      /**/                      /**/  KC_LEFT,            /**/  KC_DOWN,            /**/  KC_UP,              /**/  KC_RGHT,            /**/  KC_SPC,             /**/

    /**/  KC_MS_WH_DOWN,      /**/  KC_RALT,            /**/                      /**/                      /**/                      /**/                      /**/                      /**/
    /**/  KC_MS_WH_UP,        /**/                      /**/                      /**/                      /**/                      /**/                      /**/                      /**/
    /**/  KC_ESC,             /**/  KC_RCTL,            /**/  KC_BSPC             /**/                      /**/                      /**/                      /**/                      /**/
    ),


[PLVR] = LAYOUT_ergodox(
//  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/
    /**/  KC_TRNS,            /**/  KC_1,               /**/  KC_2,               /**/  KC_3,               /**/  KC_4,               /**/  KC_5,               /**/  KC_NO,              /**/
    /**/  KC_TRNS,            /**/  KC_Q,               /**/  KC_W,               /**/  KC_E,               /**/  KC_R,               /**/  KC_T,               /**/  PLVR_LOOK,       /**/
    /**/  KC_TRNS,            /**/  KC_A,               /**/  KC_S,               /**/  KC_D,               /**/  KC_F,               /**/  KC_G,               /**/                      /**/
    /**/  KC_TRNS,            /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  PLVR_DICT,       /**/
    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  MO(BASE),           /**/  MO(PLVR_FN),        /**/  KC_TRNS,            /**/                      /**/                      /**/

    /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_NO,              /**/  KC_NO,              /**/
    /**/                      /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_NO,              /**/
    /**/                      /**/                      /**/                      /**/                      /**/  KC_C,               /**/  KC_V,               /**/  KC_NO,              /**/


    /**/  MAGIC_TOGGLE_NKRO,  /**/  KC_6,               /**/  KC_7,               /**/  KC_8,               /**/  KC_9,               /**/  KC_0,               /**/  (KC_TRNS),          /**/
    /**/  PLVR_TOG,        /**/  KC_Y,               /**/  KC_U,               /**/  KC_I,               /**/  KC_O,               /**/  KC_P,               /**/  KC_LBRC,            /**/
    /**/                      /**/  KC_H,               /**/  KC_J,               /**/  KC_K,               /**/  KC_L,               /**/  KC_SCLN,            /**/  KC_QUOT,            /**/
    /**/  KC_TRNS,            /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  TO(BASE),           /**/
    /**/                      /**/                      /**/  (KC_TRNS),          /**/  (KC_TRNS),          /**/  (KC_TRNS),          /**/  (KC_TRNS),          /**/  KC_TRNS,            /**/

    /**/  PLVR_TOG,        /**/  KC_TRNS,            /**/                      /**/                      /**/                      /**/                      /**/                      /**/
    /**/  KC_NO,              /**/                      /**/                      /**/                      /**/                      /**/                      /**/                      /**/
    /**/  KC_TRNS,            /**/  KC_N,               /**/  KC_M                /**/                      /**/                      /**/                      /**/                      /**/
),

[PLVR_FN] = LAYOUT_ergodox(
//  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/
    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_NO,              /**/
    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/
    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/                      /**/
    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/
    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  (KC_TRNS),          /**/  (KC_TRNS),          /**/  KC_TRNS,            /**/                      /**/                      /**/

    /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/
    /**/                      /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/
    /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/


    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/
    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/
    /**/                      /**/  PLVR_TOG_AST,    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/
    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/
    /**/                      /**/                      /**/  PLVR_REM_SP,     /**/  PLVR_LO_LAST,    /**/  PLVR_UP_LAST,    /**/  PLVR_ADD_SP,     /**/  KC_TRNS,            /**/

    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/                      /**/                      /**/                      /**/                      /**/                      /**/
    /**/  KC_TRNS,            /**/                      /**/                      /**/                      /**/                      /**/                      /**/                      /**/
    /**/  PLVR_RESET,      /**/  KC_TRNS,            /**/  KC_BSPC             /**/                      /**/                      /**/                      /**/                      /**/
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
    /**/  VRSN,                /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_MUTE,              /**/
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
    /**/  CLEAR_MODS,       /**/  KC_MS_BTN2,         /**/  KC_MS_BTN1          /**/                      /**/                      /**/                      /**/                        /**/
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
    /**/                       /**/                      /**/  KC_P0,              /**/  DBL_P0,          /**/  KC_PDOT,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/

    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  KC_TRNS,             /**/                      /**/                      /**/                      /**/                      /**/                      /**/                        /**/
    /**/  KC_TRNS,             /**/  KC_TRNS,            /**/  KC_TRNS             /**/                      /**/                      /**/                      /**/                        /**/
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

[_DYN] = LAYOUT_ergodox(
//  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/  ------------------  /**/
    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  PRO_EMAIL,       /**/  WORK_ID,         /**/  KC_TRNS,            /**/  KC_TRNS,            /**/
    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  PER_EMAIL,       /**/  WORK_EMAIL,      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/
    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  PER_USER,        /**/  WORK_USER,       /**/  KC_TRNS,            /**/                      /**/
    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  PER_PH,          /**/  WORK_PH,         /**/  KC_TRNS,            /**/  KC_TRNS,            /**/
    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/                      /**/                      /**/

    /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/
    /**/                      /**/                      /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/
    /**/                      /**/                      /**/                      /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  (KC_TRNS),          /**/


    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/
    /**/  DYN_REC_START2,     /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/
    /**/                      /**/  KC_TRNS,            /**/  ADDR_STREET,     /**/  ADDR_CITY,       /**/  ADDR_STATE,      /**/  ADDR_ZIP,        /**/  KC_TRNS,            /**/
    /**/  DYN_REC_START1,     /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/
    /**/                      /**/                      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/

    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/                      /**/                      /**/                      /**/                      /**/                      /**/
    /**/  KC_TRNS,            /**/                      /**/                      /**/                      /**/                      /**/                      /**/                      /**/
    /**/  DYN_REC_STOP,       /**/  DYN_MACRO_PLAY2,    /**/  DYN_MACRO_PLAY1     /**/                      /**/                      /**/                      /**/                      /**/
    ),


}; // end of keymap definitions


// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    // set_unicode_input_mode(UC_OSX);
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};




#include "planck.h"
#include "action_layer.h"
#include "audio.h"

extern keymap_config_t keymap_config;

enum planck_layers {
	_DVORAK,
	_QWERTY,
	_MOUSE,
	_GAMING,
	_LOWER,
	_RAISE,
	_NUMPAD,
	_ADJUST
};

enum planck_keycodes {
	DVORAK = SAFE_RANGE,
	QWERTY,
	MOUSE,
	GAMING,
	NUMPAD,
	LOWER,
	RAISE,
	BACKLIT,
	EXT_NUM
};

enum planck_macros {
	M_MUTE = 0,
	M_SCREENSHOT,
	M_RECORD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Dvorak
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |Numpad| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_DVORAK] = {
    {KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
    {KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS},
    {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT },
    {NUMPAD,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
  },

  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |Numpad| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY] = {
    {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
    {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
    {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
    {NUMPAD,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
  },

  /* Mouse layer
   * ,-----------------------------------------------------------------------------------.
   * |      |      | M_UP |      |      |      |      |      |      |SCR_UP|      |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |M_LEFT|M_DOWN|M_RGHT|      |      |      |      |L_CLCK|SCR_DN|R_CLCK|      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |Lower |    Space    |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */

  [_MOUSE] = {
    {XXXXXXX,  XXXXXXX,    KC_MS_UP,   XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,     KC_MS_WH_UP,    XXXXXXX,    XXXXXXX},
    {XXXXXXX,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  KC_MS_BTN1,  KC_MS_WH_DOWN,  KC_MS_BTN2, XXXXXXX},
    {XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX,        XXXXXXX,    XXXXXXX},
    {XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,     LOWER,    KC_SPC,   KC_SPC,  RAISE,    KC_LEFT,     KC_DOWN,        KC_UP,      KC_RGHT}
  },

   /* Gaming layer
   * ,-----------------------------------------------------------------------------------.
   * |Score |  '   | Fwd  |  .   |Reload|  Y   |  F   |  G   |  C   |  R   |  L   | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Mute | Left | Back |Right |  U   |  I   |  D   |  H   |  T   |  N   |  S   |  -   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |Shift |  ;   |  Q   |  J   |  K   |  X   |  B   |  M   |  W   |  V   |  Z   |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Menu |      |      |      | Lower|   Pew Pew   | Raise|      |      |Record|Screen|
   * `-----------------------------------------------------------------------------------'
   */

  [_GAMING] = {
    {KC_TAB, 	KC_QUOT, KC_COMM,  KC_DOT,   KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,     KC_R,     KC_L,			KC_BSPC},
    {M(M_MUTE),	KC_A,    KC_O,     KC_E,     KC_U,    KC_I,    KC_D,    KC_H,    KC_T,     KC_N,     KC_S,			KC_MINS},
    {KC_LSFT,	KC_SCLN, KC_Q,     KC_J,     KC_K,    KC_X,    KC_B,    KC_M,    KC_W,     KC_V,     KC_Z, 			KC_ENT },
    {KC_ESC, 	_______, _______,  _______,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   _______,  _______,  M(M_RECORD),  	M(M_SCREENSHOT)}
  },

  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   |  |   +  |   {  |   }  |  ?   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |  BL- |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
   * `-----------------------------------------------------------------------------------'
   */
  [_LOWER] = {
    {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL},
    {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_PIPE,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_QUES},
    {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______},
    {BL_DEC,  _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY}
  },

  /* Raise
   * ,-----------------------------------------------------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   \  |   =  |   [  |   ]  |  /   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |  BL+ |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
   * `-----------------------------------------------------------------------------------'
   */
  [_RAISE] = {
    {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
    {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_BSLS, KC_EQL,  KC_LBRC, KC_RBRC, KC_SLSH},
    {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
    {BL_INC,  _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
  },

  /* Numpad layer
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |      |  Up  |      |      |      |   7  |   8  |   9  |   *  |      | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  | Left | Down |Right |      |      |   4  |   5  |   6  |   /  |   (  |   )  |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |   1  |   2  |   3  |   +  |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Exit |      |      |      |      |    Enter    |   0  |   .  |   -  |      |      |
   * `-----------------------------------------------------------------------------------'
   */

  [_NUMPAD] = {
    {KC_ESC,	XXXXXXX,    KC_UP,	    XXXXXXX,    XXXXXXX,	XXXXXXX,    KC_7,    KC_8,    KC_9,       KC_ASTR, 	XXXXXXX,	KC_BSPC},
    {KC_TAB, 	KC_LEFT,    KC_DOWN,    KC_RIGHT,   XXXXXXX,	XXXXXXX,    KC_4,    KC_5,    KC_6,       KC_SLSH,  KC_LPRN,    KC_RPRN},
    {XXXXXXX, 	XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,	XXXXXXX,    KC_1,    KC_2,    KC_3,       KC_PLUS,  XXXXXXX,	XXXXXXX},
    {EXT_NUM, 	XXXXXXX,	XXXXXXX,	XXXXXXX,    XXXXXXX,    KC_ENT, 	KC_ENT,	 KC_0,    KC_DOT, 	  KC_MINS,	XXXXXXX,	XXXXXXX}
  },

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------------------------------------------------.
   * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |Aud on|Audoff|      |      |Dvorak|Qwerty|Mouse |Gaming|      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |  BL  |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = {
    {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL },
    {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  _______, _______,  DVORAK,  QWERTY,   MOUSE,  GAMING, _______},
    {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
    {BACKLIT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  }
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(MUSHROOM_SOUND);
  float plover_gb_song[][2]  = SONG(PIPE_SOUND);
#endif

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch(id) {
            case M_MUTE:
                return MACRO(D(LALT), T(M), U(LALT), END);
            case M_SCREENSHOT:
            	return MACRO(D(LALT), T(F1), U(LALT), END);
            case M_RECORD:
            	return MACRO(D(LALT), T(F2), U(LALT), END);
        }
    }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case MOUSE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_MOUSE);
      }
      return false;
      break;
    case GAMING:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAMING);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_NUMPAD);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_NUM:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_NUMPAD);
      }
      return false;
      break;
  }
  return true;
}
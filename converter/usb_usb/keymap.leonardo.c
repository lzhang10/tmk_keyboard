/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "keymap_common.h"

#include "action_layer.h"
#include "action_util.h"
#include "action_code.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Plain Qwerty without layer switching
     *         ,---------------. ,---------------. ,---------------.
     *         |F13|F14|F15|F16| |F17|F18|F19|F20| |F21|F22|F23|F24|
     * ,---.   |---------------| |---------------| |---------------| ,-----------. ,---------------. ,-------.
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau| |VDn|VUp|Mut|Pwr| | Help  |
     * `---'   `---------------' `---------------' `---------------' `-----------' `---------------' `-------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------. ,-------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -| |Stp|Agn|
     * |-----------------------------------------------------------| |-----------| |---------------| |-------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +| |Mnu|Und|
     * |-----------------------------------------------------------| `-----------' |---------------| |-------|
     * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  #|Retn|               |  4|  5|  6|KP,| |Sel|Cpy|
     * |-----------------------------------------------------------|     ,---.     |---------------| |-------|
     * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /| RO|Shift |     |Up |     |  1|  2|  3|KP=| |Exe|Pst|
     * |-----------------------------------------------------------| ,-----------. |---------------| |-------|
     * |Ctl|Gui|Alt|MHEN|HNJ| Space  |H/E|HENK|KANA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |  0    |  .|Ent| |Fnd|Cut|
     * `-----------------------------------------------------------' `-----------' `---------------' `-------'
     */
    [0] = KEYMAP_ALL(
              F13, F14, F15, F16, F17, F18, F19, F20, F21, F22, F23, F24,
    ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,           PSCR,SLCK,PAUS,    VOLD,VOLU,MUTE,PWR,     HELP,
    GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, JYEN,BSPC,     INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,    STOP,AGIN,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,     BSLS,     DEL, END, PGDN,    P7,  P8,  P9,  PPLS,    MENU,UNDO,
    CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     NUHS,ENT,                         P4,  P5,  P6,  PCMM,    SLCT,COPY,
    LSFT,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RO,  RSFT,          UP,           P1,  P2,  P3,  PEQL,    EXEC,PSTE,
    LCTL,LGUI,LALT,MHEN,HANJ,     SPC,      HAEN,HENK,KANA,RALT,RGUI,APP, RCTL,     LEFT,DOWN,RGHT,    P0,       PDOT,PENT,    FIND,CUT
    ),

    /* Modified Qwerty for Apple Magic keyboard
      - SpaceFN layer
      - LCTRL-ESC dual key
      - RCTRL-Enter dual key
      - share TAB and ~ on the same key
      - Eject (F24) has separate layer
    */
    [1] = KEYMAP_ALL(
              F13, F14, F15, F16, F17, F18, F19, F20, F21, F22, F23, FN5,
    ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,           PSCR,SLCK,PAUS,    VOLD,VOLU,MUTE,PWR,     HELP,
    GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, JYEN,BSPC,     INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,    STOP,AGIN,
    FN4, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,     BSLS,     DEL, END, PGDN,    P7,  P8,  P9,  PPLS,    MENU,UNDO,
    FN2,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     NUHS,FN3,                         P4,  P5,  P6,  PCMM,    SLCT,COPY,
    LSFT,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RO,  RSFT,          UP,           P1,  P2,  P3,  PEQL,    EXEC,PSTE,
    LCTL,LALT, LGUI,MHEN,HANJ,     FN0,      HAEN,HENK,KANA,RALT,INS,APP, RCTL,     LEFT,DOWN,RGHT,    P0,       PDOT,PENT,    FIND,CUT
    ),

    /* Modified Query for Kinesis Advantage 2
       - SpaceFN
       - LSHIFT-TAB dual key
    */
    [2] = KEYMAP_ALL(
              F13, F14, F15, F16, F17, F18, F19, F20, F21, F22, F23, F24,
              ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,           PSCR,SLCK,PAUS,    VOLD,VOLU,MUTE,PWR,     HELP,
              GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, JYEN,BSPC,     INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,    STOP,AGIN,
              TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,     BSLS,     DEL, END, PGDN,    P7,  P8,  P9,  PPLS,    MENU,UNDO,
              CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     NUHS,ENT,                         P4,  P5,  P6,  PCMM,    SLCT,COPY,
              FN6,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RO,  RSFT,          UP,           P1,  P2,  P3,  PEQL,    EXEC,PSTE,
              LCTL,LGUI,LALT,MHEN,HANJ,     FN0,      HAEN,HENK,KANA,RALT,RGUI,APP, RCTL,     LEFT,DOWN,RGHT,    P0,       PDOT,PENT,    FIND,CUT
    ),

    /* SpaceFN
     * ,-----------------------------------------------------------.
     * |`  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Delete |
     * |-----------------------------------------------------------|
     * |Caps |   |   |Esc|   |   |   |Hom|Up |End|Psc|Slk|Pau|Ins  |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |PgU|Lef|Dow|Rig|   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |Spc|PgD|`  |~  |   |Men|          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     */
    [3] = KEYMAP_ALL(
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,    TRNS,
    TRNS, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,DEL,      TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,
    TRNS,TRNS,TRNS,ESC, TRNS,TRNS,HOME,PGUP,PGDN, INS, END,SLCK,PAUS,     INS,      TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LEFT,DOWN,UP,RGHT,TRNS,TRNS,     TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,SPC, PGDN,GRV, FN1, TRNS,APP,      TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,     TRNS,TRNS,    TRNS,TRNS
    ),

    /* FN24 layer on magic keyboard
     * ,-----------------------------------------------------------.
     * |`  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Delete |
     * |-----------------------------------------------------------|
     * |Caps |   |   |Esc|   |   |   |Hom|Up |End|Psc|Slk|Pau|Ins  |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |PgU|Lef|Dow|Rig|   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |Spc|PgD|`  |~  |   |Men|          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     */
    [4] = KEYMAP_ALL(
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,    TRNS,
    TRNS, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,DEL,      TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,
    TRNS,TRNS,TRNS,ESC, TRNS,TRNS,HOME,PGUP,PGDN, INS, END,SLCK,PAUS,     INS,      TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LEFT,DOWN,UP,RGHT,TRNS,TRNS,     TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,SPC, PGDN,GRV, FN1, TRNS,APP,      TRNS,TRNS,          PGUP,         TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     HOME,PGDN,END,    TRNS,     TRNS,TRNS,    TRNS,TRNS
    ),
};

enum function_id {
  TAB
};

const action_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_TAP_KEY(3, KC_SPACE),    // FN0: SpaceFN
  [1] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),    // FN1: tilde
  [2] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),// FN2: LCTL/ESC dual key
  [3] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT),// FN3: RCTL/Enter dual key
  [4] = ACTION_FUNCTION(TAB),                 // FN4: share TAB and ~ on the same key: https://github.com/tmk/tmk_keyboard/wiki/FAQ-Keymap#esc-and--on-a-key
  [5] = ACTION_LAYER_MOMENTARY(4),            // FN5: Eject key on magic keyboard
  [6] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_TAB),// FN6: LSHIFT-TAB dual key (kinesis adv2)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if(id == TAB){
  void (*method)(uint8_t) = (record->event.pressed) ? &add_key : &del_key;
  uint8_t shifted = get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT));

  if(layer_state == 0)
    method(shifted ? KC_GRAVE : KC_TAB);
  else
    method(shifted ? KC_GRAVE : KC_TAB);

  send_keyboard_report();
}
}

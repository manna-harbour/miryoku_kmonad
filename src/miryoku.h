// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

#pragma once

#include "custom_config.h"

#include "miryoku_babel/miryoku_layer_selection.h"
#include "miryoku_babel/miryoku_layer_list.h"

#define U_MACRO_VA_ARGS(MACRO, ...) MACRO(__VA_ARGS__)

#define U_NP XX // key is not present
#define U_NA XX // present but not available for use
#define U_NU XX // available but not used

#define U_TAPPING_TERM 200

#if defined (MIRYOKU_CLIPBOARD_FUN)
  #define U_RDO again
  #define U_PST paste
  #define U_CPY copy
  #define U_CUT cut
  #define U_UND undo
#elif defined (MIRYOKU_CLIPBOARD_MAC)
  #define U_RDO S-M-z
  #define U_PST M-v
  #define U_CPY M-c
  #define U_CUT M-x
  #define U_UND M-z
#elif defined (MIRYOKU_CLIPBOARD_WIN)
  #define U_RDO C-y
  #define U_PST C-v
  #define U_CPY C-c
  #define U_CUT C-x
  #define U_UND C-z
#else
  #define U_RDO again
  #define U_PST S-ins
  #define U_CPY C-ins
  #define U_CUT S-del
  #define U_UND undo
#endif

#define U_MT(TAP, HOLD) (tap-hold-next-release U_TAPPING_TERM TAP HOLD)
#define U_LT(TAP, HOLD) (tap-hold-next-release U_TAPPING_TERM TAP (layer-toggle HOLD))
#define U_DF(LAYER) (multi-tap U_TAPPING_TERM XX (layer-switch LAYER))

#define MIRYOKU_MAPPING_MAIN( \
  K00,      K01,      K02,      K03,      K04,      K05,      K06,      K07,      K08,      K09, \
  K10,      K11,      K12,      K13,      K14,      K15,      K16,      K17,      K18,      K19, \
  K20,      K21,      K22,      K23,      K24,      K25,      K26,      K27,      K28,      K29, \
  N30,      N31,      K32,      K33,      K34,      K35,      K36,      K37,      N38,      N39 \
  ) \
  K00 U_TAB K01 U_TAB K02 U_TAB K03 U_TAB K04 U_TAB K05 U_TAB K06 U_TAB K07 U_TAB K08 U_TAB K09 U_LF \
  K10 U_TAB K11 U_TAB K12 U_TAB K13 U_TAB K14 U_TAB K15 U_TAB K16 U_TAB K17 U_TAB K18 U_TAB K19 U_LF \
  K20 U_TAB K21 U_TAB K22 U_TAB K23 U_TAB K24 U_TAB K25 U_TAB K26 U_TAB K27 U_TAB K28 U_TAB K29 U_LF \
      U_TAB     U_TAB K32 U_TAB K33 U_TAB K34 U_TAB K35 U_TAB K36 U_TAB K37

#if defined (MIRYOKU_MAPPING_LITE)
  #define MIRYOKU_MAPPING(...) MIRYOKU_MAPPING_MAIN(__VA_ARGS__) U_LF \
  ;
#else
  #define MIRYOKU_MAPPING MIRYOKU_MAPPING_MAIN
#endif

#if !defined (MIRYOKU_KMONAD_KEYBOARD_LINUX)
  #define MIRYOKU_KMONAD_KEYBOARD_LINUX "keyboard"
#endif

#if !defined (MIRYOKU_KMONAD_KEYBOARD_MAC)
  #define MIRYOKU_KMONAD_KEYBOARD_MAC
#endif

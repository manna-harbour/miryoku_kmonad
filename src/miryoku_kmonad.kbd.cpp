;; Copyright 2021 Manna Harbour
;; github.com/manna-harbour/miryoku

#include "miryoku.h"

(defcfg
#if defined (MIRYOKU_KMONAD_OS_WIN)
  input  (low-level-hook)
  output (send-event-sink)
#elif defined (MIRYOKU_KMONAD_OS_MAC)
  input  (iokit-name MIRYOKU_KMONAD_KEYBOARD_MAC)
  output (kext)
#else
  input  (device-file MIRYOKU_KMONAD_KEYBOARD_LINUX)
  output (uinput-sink "Miryoku KMonad output")
#endif
#if defined (MIRYOKU_MAPPING_LITE)
  fallthrough true
#else
  fallthrough false
#endif
)

(defsrc
#if defined (MIRYOKU_MAPPING_NOREVERSEANGLE)
  grv    1      2      3      4           8      9      0      -      =
  tab    q      w      e      r           i      o      p      [      ]
  caps   a      s      d      f           k      l      ;      U_QUOT ent
                z      x      c           ,      .      /
#elif defined (MIRYOKU_MAPPING_LITE)
  q      w      e      r      t           y      u      i      o      p
  a      s      d      f      g           h      j      k      l      ;
  z      x      c      v      b           n      m      ,      .      /
  #if defined (MIRYOKU_LAYERS_FLIP)
  Missing255 Missing255 Missing255 Missing255 spc Missing255
  #else
                esc    spc    tab         ent    bspc   del
  #endif
  U_QUOT
#elif defined (MIRYOKU_MAPPING_TAP)
  q      w      f      p      b           j      l      u      y      U_QUOT
  a      r      s      t      g           m      n      e      i      o
  z      x      c      d      v           k      h      ,      .      /
                esc    spc    tab         ent    bspc   del
#elif defined (MIRYOKU_MAPPING_KINESIS_ADVANTAGE)
  q      w      e      r      t           y      u      i      o      p
  a      s      d      f      g           h      j      k      l      ;
  z      x      c      v      b           n      m      ,      .      /
                bspc   del    end         pgdn   ent    spc
#else
  2      3      4      5      6           8      9      0      -      =
  q      w      e      r      t           i      o      p      [      ]
  caps   a      s      d      f           k      l      ;      U_QUOT ent
                x      c      v           ,      .      /
#endif
)

#define MIRYOKU_X(LAYER, STRING) \
(deflayer U_##LAYER U_LF \
U_MACRO_VA_ARGS(MIRYOKU_LAYERMAPPING_##LAYER, MIRYOKU_LAYER_##LAYER) U_LF \
) U_LF
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X



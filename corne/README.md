# Corne v3 (crkbd)

42-key split: 3×6 + 3 thumbs per side. foostan Corne Cherry v3 uses the same QMK target as v1/v2: **`crkbd/rev1`**. Corne v4 is `crkbd/rev4` — do not use this folder for v4.

Keep the OS layout on **US QWERTY**.

## Base layers

### QWERTY

```
TAB   Q  W  E  R  T          Y  U  I  O  P  BSPC
CTRL  A  S  D  F  G          H  J  K  L  ;  '
SFT   Z  X  C  V  B          N  M  ,  .  /  SFT
           GUI  LOWER  SPC    ENT  RAISE  ALT
```

### Colemak-DH

```
TAB   Q  W  F  P  B          J  L  U  Y  ;  BSPC
CTRL  A  R  S  T  G          M  N  E  I  O  '
SFT   Z  X  C  D  V          K  H  ,  .  /  SFT
           GUI  LOWER  SPC    ENT  RAISE  ALT
```

- **Lower:** numbers, F-keys, Bluetooth (ZMK)
- **Raise:** symbols, arrows, media
- **Adjust (QMK, Lower+Raise):** bootloader, switch QWERTY / Colemak-DH

## Flash QMK (wired, Pro Micro / RP2040)

Copy `qmk/` to `qmk_firmware/keyboards/crkbd/keymaps/tuanpep/`.

```
qmk compile -kb crkbd/rev1 -km tuanpep
qmk flash   -kb crkbd/rev1 -km tuanpep
```

RP2040:

```
qmk flash -kb crkbd/rev1 -km tuanpep -e CONVERT_TO=promicro_rp2040
```

Or import `qmk/keymap.json` at https://config.qmk.fm/#/crkbd/rev1/LAYOUT_split_3x6_3

Unplug TRRS and flash each half separately.

## Flash ZMK (wireless, nice!nano)

Copy `zmk/corne.keymap` over `config/corne.keymap` in a Corne zmk-config (`corne_left` / `corne_right` shields).

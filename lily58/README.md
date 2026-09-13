# Lily58 Colemak-DH

Base layer is **Colemak-DH (matrix)**. A QWERTY layer is included for games.

Keep the **OS keyboard layout on US QWERTY**. The firmware does the remapping.

## Layout

```
ESC   1  2  3  4  5                    6  7  8  9  0  `
TAB   Q  W  F  P  B                    J  L  U  Y  ;  -
CTRL  A  R  S  T  G                    M  N  E  I  O  '
SFT   Z  X  C  D  V   [          ]     K  H  ,  .  /  SFT
            ALT  GUI  LOWER  SPC    ENT  RAISE  BSPC  GUI
```

- **Lower:** F-keys + symbols
- **Raise:** arrows, Home/End/PgUp/PgDn, media
- **Adjust (QMK, Lower+Raise):** bootloader, Colemak/QWERTY switch

## Flash QMK (wired)

Copy `qmk/` into `qmk_firmware/keyboards/lily58/keymaps/colemak_dh/`.

```
qmk compile -kb lily58/rev1 -km colemak_dh
qmk flash   -kb lily58/rev1 -km colemak_dh
```

RP2040: add `-e CONVERT_TO=promicro_rp2040`.
Light PCB: `-kb lily58/light`.

Or import `qmk/keymap.json` at https://config.qmk.fm/#/lily58/rev1/LAYOUT

Unplug TRRS and flash one half at a time.

## Flash ZMK (wireless)

Replace `config/lily58.keymap` in your zmk-config with `zmk/lily58.keymap`.

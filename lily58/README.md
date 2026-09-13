# Lily58

Two keymaps:

| Folder | Base layout |
| --- | --- |
| [qmk/](qmk/) and [zmk/](zmk/) | Colemak-DH (QWERTY as a toggle layer) |
| [qwerty/](qwerty/) | QWERTY only |

Keep the **OS keyboard layout on US QWERTY**. The firmware does any remapping.

## QWERTY flash (wired / QMK)

Copy `qwerty/qmk/` into `qmk_firmware/keyboards/lily58/keymaps/qwerty/`.

```
qmk compile -kb lily58/rev1 -km qwerty
qmk flash   -kb lily58/rev1 -km qwerty
```

RP2040 Pro Micro clone:

```
qmk compile -kb lily58/rev1 -km qwerty -e CONVERT_TO=promicro_rp2040
qmk flash   -kb lily58/rev1 -km qwerty -e CONVERT_TO=promicro_rp2040
```

Light PCB: `-kb lily58/light`.

Or import `qwerty/qmk/keymap.json` at https://config.qmk.fm/#/lily58/rev1/LAYOUT

Unplug the TRRS cable and flash one half at a time.

## QWERTY flash (wireless / ZMK)

Replace `config/lily58.keymap` in your zmk-config with `qwerty/zmk/lily58.keymap`.

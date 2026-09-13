# Keyboard firmware guide

Keep the **OS layout on US QWERTY** so the firmware is the only remapper.

Diagrams: [docs/images/](docs/images/)

## Boards

| Board | Keys | QMK target | Folder |
| --- | --- | --- | --- |
| Lily58 | 58 (6×4 + 4 thumbs) | `lily58/rev1` | [lily58/](lily58/) |
| Corne v3 (crkbd) | 42 (3×6 + 3 thumbs) | `crkbd/rev1` | [corne/](corne/) |

Lower / Raise / Adjust are **shared** by QWERTY and Colemak-DH on each board.

---

## Lily58 base — QWERTY

![Lily58 QWERTY](docs/images/lily58-qwerty.svg)

```
ESC   1  2  3  4  5                    6  7  8  9  0  `
TAB   Q  W  E  R  T                    Y  U  I  O  P  -
CTRL  A  S  D  F  G                    H  J  K  L  ;  '
SFT   Z  X  C  V  B   [          ]     N  M  ,  .  /  SFT
            ALT  GUI  LOWER  SPC    ENT  RAISE  BSPC  GUI
```

## Lily58 base — Colemak-DH

![Lily58 Colemak-DH](docs/images/lily58-colemak-dh.svg)

```
ESC   1  2  3  4  5                    6  7  8  9  0  `
TAB   Q  W  F  P  B                    J  L  U  Y  ;  -
CTRL  A  R  S  T  G                    M  N  E  I  O  '
SFT   Z  X  C  D  V   [          ]     K  H  ,  .  /  SFT
            ALT  GUI  LOWER  SPC    ENT  RAISE  BSPC  GUI
```

## Lily58 Lower

![Lily58 Lower](docs/images/lily58-lower.svg)

```
_     F1 F2 F3 F4 F5                   F6 F7 F8 F9 F10 F11
_     !  @  #  $  %                    ^  &  *  (  )   F12
_     `  ~  \  |  .                    .  _  +  {  }   _
_     _  _  _  _  _   _          _     .  -  =  [  ]   _
            _    _    LOWER  SPC    ENT  RAISE  _    _
```

## Lily58 Raise

![Lily58 Raise](docs/images/lily58-raise.svg)

```
_     _  _  _  _  _                    _    _    _    _    _    _
_     .  .  .  .  .                    Home PgDn PgUp End  .    _
_     .  .  .  .  .                    Left Down Up   Rght Del  _
_     .  .  .  .  .   _          _     Mute Vol- Vol+ Prev Next Play
            _    _    LOWER  SPC    ENT  RAISE  _    _
```

## Lily58 Adjust (hold Lower+Raise)

![Lily58 Adjust](docs/images/lily58-adjust.svg)

```
BOOT  .  .  .  .  .                    .  .  .  .  .  BOOT
.     QWE .  .  .  .                    .  .  .  .  .  .
.     CMK .  TG .  .                    .  .  .  .  .  .
```

- Left **Q** column on Adjust: `QWE` = default QWERTY (`DF_QWE`)
- Left **A** column on Adjust: `CMK` = default Colemak-DH (`DF_CMK`)
- `TG` toggles QWERTY layer
- Outer ESC / ` = bootloader

```bash
qmk flash -kb lily58/rev1 -km default
qmk flash -kb lily58/rev1 -km qwerty
qmk flash -kb lily58/rev1 -km qwerty -e CONVERT_TO=promicro_rp2040
```

---

## Corne v3 base — QWERTY

![Corne QWERTY](docs/images/corne-qwerty.svg)

```
TAB   Q  W  E  R  T          Y  U  I  O  P  BSPC
CTRL  A  S  D  F  G          H  J  K  L  ;  '
SFT   Z  X  C  V  B          N  M  ,  .  /  SFT
           GUI  LOWER  SPC    ENT  RAISE  ALT
```

## Corne v3 base — Colemak-DH

![Corne Colemak-DH](docs/images/corne-colemak-dh.svg)

```
TAB   Q  W  F  P  B          J  L  U  Y  ;  BSPC
CTRL  A  R  S  T  G          M  N  E  I  O  '
SFT   Z  X  C  D  V          K  H  ,  .  /  SFT
           GUI  LOWER  SPC    ENT  RAISE  ALT
```

## Corne Lower

![Corne Lower](docs/images/corne-lower.svg)

```
ESC   1  2  3  4  5          6  7  8  9  0  BSPC
_     F1 F2 F3 F4 F5         F6 F7 F8 F9 F10 F11
_     .  .  .  .  .          .  .  .  .  .  F12
           _  LOWER  SPC    ENT  RAISE  _
```

## Corne Raise

![Corne Raise](docs/images/corne-raise.svg)

```
`     !  @  #  $  %          ^  &  *  (  )  DEL
_     -  =  [  ]  \          Left Down Up Rght |  ~
_     _  +  {  }  .          Home PgDn PgUp End Mute Play
           _  LOWER  SPC    ENT  RAISE  _
```

## Corne Adjust (hold Lower+Raise)

![Corne Adjust](docs/images/corne-adjust.svg)

```
BOOT  .  .  .  .  .          .  .  .  .  .  BOOT
.     QWE .  .  .  .          .  .  .  .  .  .
.     CMK .  .  .  .          .  .  .  .  .  .
```

Hold Lower+Raise, tap left **Q** = QWERTY default, tap left **A** = Colemak-DH default.

```bash
qmk flash -kb crkbd/rev1 -km tuanpep
qmk flash -kb crkbd/rev1 -km tuanpep -e CONVERT_TO=promicro_rp2040
```

---

## Flash rules

1. Unplug the TRRS cable.
2. Plug in one half over USB.
3. Reset into bootloader.
4. Flash, then repeat for the other half.
5. Reconnect TRRS. USB goes in the **left** half.

Do not flash with the halves linked. Do not use a 3-pole TRS cable.

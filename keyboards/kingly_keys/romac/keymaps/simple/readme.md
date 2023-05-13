## Simple keymap

A single-layer keymap with function keys from F13 to F24, convenient for those
who want to add keys not overlapping with their current keyboard/s.

### xmodmap override for Xorg users

Xorg assigns a few of these keycodes to vendor-specific keys found in laptops
(e.g. mute mic). To override these, add the following lines to your `~/.Xmodmap`
file:

```
keycode 191 = F13 F13 F13
keycode 192 = F14 F14 F14
keycode 193 = F15 F15 F15
keycode 194 = F16 F16 F16
keycode 195 = F17 F17 F17
keycode 196 = F18 F18 F18
keycode 197 = F19 F19 F19
keycode 198 = F20 F20 F20
keycode 199 = F21 F21 F21
keycode 200 = F22 F22 F22
keycode 201 = F23 F23 F23
keycode 202 = F24 F24 F24
```

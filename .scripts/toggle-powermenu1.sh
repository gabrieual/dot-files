#! /usr/bin/bash

if pgrep -x "rofi" >/dev/null; then
  pkill rofi
else
  ~/.config/rofi/powermenu/type-4/powermenu.sh
fi

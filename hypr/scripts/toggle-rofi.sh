if pgrep -x "rofi" >/dev/null; then
  pkill rofi
else
  ~/.config/rofi/launchers/type-6/launcher.sh
fi

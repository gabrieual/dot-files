#!/bin/bash

if [[ "$DESKTOP_SESSION" == 'hyprland' ]]; then
  hyprctl dispatch dpms off
fi

swayidle timeout 15 "$HOME/.config/.scripts/lock.sh" &
SWAYIDLE_PID=$!

while hyprctl monitors | grep "dpmsStatus: 0"; do
  sleep 0.5
done

if [ -n "$SWAYIDLE_PID" ] && kill -0 "$SWAYIDLE_PID" 2>/dev/null; then
  kill "$SWAYIDLE_PID"
fi

#!/bin/bash

if ! pgrep -x hyprlock >/dev/null; then
  hyprlock &
fi

if upower -i $(upower -e | grep 'line_power') | grep -q "online:\s*yes"; then
  # swayidle timeout 30 "hyprctl dispatch dpms off" resume "hyprctl dispatch dpms on" & # wait 30 sec after lock to turn off the monitor
  swayidle timeout 40 "systemctl suspend" & # wait 40 sec after lock to suspend
  SWAYIDLE_PID=$!
else
  swayidle timeout 20 "systemctl suspend" & # wait 20 sec after lock to suspend
  SWAYIDLE_PID=$!
fi

while pgrep -x hyprlock >/dev/null; do
  sleep 1
done

if [ -n "$SWAYIDLE_PID" ] && kill -0 "$SWAYIDLE_PID" 2>/dev/null; then
  kill "$SWAYIDLE_PID"
fi

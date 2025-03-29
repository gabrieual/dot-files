#!/bin/bash

if ! pgrep -x swaylock >/dev/null; then
  swaylock &
fi

if [ "$(pgrep -x swayidle | wc -l)" -lt 2 ]; then
  swayidle timeout 20 "systemctl suspend" & # wait 20 sec after lock to suspend
  SWAYIDLE_PID=$!
fi

while pgrep -x swaylock >/dev/null; do
  sleep 0.5
done

if [ -n "$SWAYIDLE_PID" ] && kill -0 "$SWAYIDLE_PID" 2>/dev/null; then
  kill "$SWAYIDLE_PID"
fi

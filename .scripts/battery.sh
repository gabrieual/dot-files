#!/bin/bash

while true; do
  LEVEL=$(cat /sys/class/power_supply/BAT0/capacity)
  STATUS=$(cat /sys/class/power_supply/BAT0/status)

  if [ "$STATUS" = "Discaharging" ] && [ "$LEVEL" -e 10 ]; then
    notify-send -u critical -i battery-caution "Low battery" "Battery level: 10%"
  fi

  sleep 60
done &

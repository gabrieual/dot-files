#!/bin/bash
level=$(cat /sys/class/power_supply/BAT0/capacity)

if [[ level -ge 99 ]]; then
  icon="󰁹"
elif [[ level -ge 90 ]]; then
  icon="󰂂"
elif [[ level -ge 80 ]]; then
  icon="󰂁"
elif [[ level -ge 70 ]]; then
  icon="󰂀"
elif [[ level -ge 60 ]]; then
  icon="󰁿"
elif [[ level -ge 50 ]]; then
  icon="󰁾"
elif [[ level -ge 40 ]]; then
  icon="󰁽"
elif [[ level -ge 30 ]]; then
  icon="󰁼"
elif [[ level -ge 20 ]]; then
  icon="󰁻"
elif [[ level -ge 10 ]]; then
  icon="󰁺"
fi

echo "${icon} ${level}%"

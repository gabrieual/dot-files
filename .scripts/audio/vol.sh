#!/bin/bash

volume=$(pactl get-sink-volume @DEFAULT_SINK@ | grep -oP '\d+%' | head -1 | tr -d '%')
muted=$(pactl get-sink-mute @DEFAULT_SINK@ | awk '{print $2}')
ICONTHEME="/usr/share/icons/Papirus-Dark/16x16/actions/" # its hardcoded cause I had some trouble

if [ "$muted" = "yes" ]; then
  icon="$ICONTHEME/audio-volume-muted.svg"
  text="Muted"
  value=0
else
  if [ "$volume" -lt 30 ]; then
    icon="$ICONTHEME/audio-volume-low.svg"
  elif [ "$volume" -lt 70 ]; then
    icon="$ICONTHEME/audio-volume-medium.svg"
  else
    icon="$ICONTHEME/audio-volume-high.svg"
  fi
  text="Volume: $volume%"
  value=$volume
fi

# Notification
dunstify -a volume -r 9993 -h int:value:$value -i "$icon" "$text"

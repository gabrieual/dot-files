#!/bin/bash

status=$(playerctl status 2>/dev/null)

if [ "$status" = "Playing" ]; then
  song_info=$(playerctl metadata --format '󰎇 {{artist}} - {{title}}')
  echo "$song_info"
fi

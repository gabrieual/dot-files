#!/bin/bash

DIR="$HOME/Images/Screenshots/"

mkdir -p "$DIR"

NAME="screenshot_$(date +'%Y-%m-%d_%H-%M-%S').png"

FILENAME="$DIR/$NAME"

grim -s 1 -g "$(slurp)" "$FILENAME"

cat "$FILENAME" | wl-copy

if [[ -f "$FILENAME" ]]; then
  dunstify -i "$FILENAME" "📸 Saved screenshot " "$NAME"
fi

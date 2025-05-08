#!/bin/bash

DIR="$HOME/Images/Screenshots"
FILENAME="screenshot_$(date '+%Y-%m-%d_%H-%M-%S').png"
FILEPATH="$DIR/$FILENAME"

mkdir -p "$DIR"

grim -g "$(slurp)" "$FILEPATH"
wl-copy <"$FILEPATH"

notify-send -u low -i camera-photo "Screenshot taked!" "Saved in $DIR and copied to clipboard."

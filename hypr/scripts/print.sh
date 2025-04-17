#!/bin/bash

DIR="$HOME/Images/Screenshots"
FILENAME="screenshot_$(date '+%Y-%m-%d_%H-%M-%S').png"
FILEPATH="$DIR/$FILENAME"

mkdir -p "$DIR"

grim -g "$(slurp)" "$FILEPATH"
wl-copy <"$FILEPATH"

notify-send "Screenshot taked!" "Saved in $DIR and copied to clipboard." --icon=dialog-information

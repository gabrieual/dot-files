DIR="$HOME/Images/Screenshots"
FILENAME="screenshot_$(date '+%Y-%m-%d_%H-%M-%S').png"
FILEPATH="$DIR/$FILENAME"

mkdir -p "$DIR"

grim -g "$(slurp)" "$FILEPATH"
wl-copy < "$FILEPATH"

# notify-send "Screenshot tirado!" "Salvo em $FILEPATH e copiado para a área de transferência." --icon=dialog-information


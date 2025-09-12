{
    "height": 0,
    "position": "left",
    "margin-left":0,
    "margin-right":0,
    "margin-bottom":0,
    "margin-top":0,

    "modules-left": [
        "hyprland/workspaces",
        "mpris"
    ],

    "modules-center": [
        "clock"
    ],

    "modules-right": [
        "pulseaudio",
        "network",
        "memory",
        "temperature",
        "battery",
        "custom/powermenu"
    ],

    "hyprland/window": {
      "format": "{}",
      "on-empty": "hidden",
      "tooltip": false,
      "max-length": 50,
      "rewrite":{
          "~":"kitty",
        },
    },
    
    "hyprland/workspaces": {
      "format": "{icon}",
      "on-click": "activate",
      //"format-icons": {
      //  "active": "",
      //},
      "sort-by-number": true,
      "persistent-workspaces": {
        "*": 4, // 5 workspaces by default on every monitor
        "HDMI-A-1": 3 // but only three on HDMI-A-1
      }
    },
    

    "mpris": {
      "format": "󰎇 {status_icon} {dynamic}",
      "interval": 0.5,
      "dynamic-len": 43,
	    "status-icons": {
		    "playing": "⏸",
		    "paused": "▶",
		    "stopped": ""
	      },
	    "dynamic-order": ["title", "artist"],
      "ignored-players": ["firefox"]
    },


    "clock": {
      "format": "{:%H\n%M}",
      "tooltip-format": "<big>{:%Y %B}</big>\n<tt><small>{calendar}</small></tt>",
      "format-alt": "{:%Y\n --\n %m\n --\n %d}"
    },


    "cpu": {
      "format": " {usage}%",
      "tooltip": false
    },


    "memory": {
      "format": " \n{}%",
      "on-click": "kitty -- btop",
      "interval": 5
    },


    "temperature": {
      "critical-threshold": 70,
      "format": " {icon}\n{temperatureC}°C",
      "format-icons": ["", "", ""]
    },


    "battery": {
      "states": {
        "warning": 30,
        "critical": 15
      },
      "format": "{icon}\n{capacity}%",
      "format-full": "{icon}\n{capacity}%",
      "format-charging": "󱐋\n{capacity}%",
      "format-plugged": "\n{capacity}%",
      "format-alt": "{icon} {time}",
      "format-icons": ["", "", "", "", ""]
    },


    "network": {
      "format-wifi": "{icon}",
      "format-ethernet": "{cidr} 󰈁",
      "tooltip-format": "{ifname} via {gwaddr} 󰈁",
      "format-linked": "{ifname} (No IP) 󰈁",
      "format-disconnected": "",
      "max-length": 11,
      "format-icons": ["󰤯","󰤟","󰤢","󰤥","󰤨"],
      "on-click": "kitty -- nmtui"
    },


    "pulseaudio": {
      "format": " {icon}\n{volume}%",
      "format-bluetooth": "{volume}% {icon} {format_source}",
      "format-bluetooth-muted": "󰝟 {icon} {format_source}",
      "format-muted": " ",
      "format-icons": {
        "phone": "",
        "portable": "",
        "car": "",
        "default": ["", " ", " "]
      },
      "on-click": "pavucontrol"
    },

    "custom/powermenu": {
      "format": "",
      "on-click": "$HOME/.scripts/toggle-powermenu.sh",
      "tooltip":false
    }
}

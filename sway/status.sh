#!/bin/bash

uptime_formatted=$(uptime | cut -d ',' -f1 | cut -d ' ' -f4,5)
date_formatted=$(date "+%a %F %H:%M:%S")
connected_wifi=$(iwgetid | cut -d'"' -f 2)
battery_status=$(cat /sys/class/power_supply/BAT0/status)
battery_capacity=$(cat /sys/class/power_supply/BAT0/capacity)
brightness=$(cat /sys/class/backlight/amdgpu_bl0/brightness)
linux_version=$(uname -r | cut -d '-' -f1)

if [ "$battery_status" = "Discharging" ]
then
    battery_icon="-"
else
    battery_icon="+"
fi

echo "wifi:$connected_wifi uptime:${uptime_formatted:1} lk:$linux_version b:$brightness/255 $battery_icon[==$battery_capacity] $date_formatted"


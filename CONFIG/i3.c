!user/bin/ansible(c)/i3blocks.c

http://vivien.github.io/i3blocks
# Global
// properties are applied in block overridden. cmd default script avoids boilerplate

command=/usr/share/i3blocks/$BLOCK_NAME
separator_block_width=15
separator=false
markup=none

# VPN
// instance is none. end-user ui for default route. address forces ipv4 or ipv6 with -4 and -6

    [iface]
instance=tun0
color=#3BB92D
label=🆙
interval=120
#separator=false

# CPU
// usage script calls with -w and -c 
    [cpu_usage]:
label= CPU
interval=5
min_width=CPU: 100.00%
separator=false

# MEM
# type default if instance is none
    [memory]:
label= RAM
separator=false
interval=10

# C:/
// dir default $HOME if no instance. script call with -a args (defaults to 10 for 10%).
    [disk]:
label= Disk
instance=/mnt/data
interval=240
break;
[bandwidth]:
instance=eth0
label=
interval=5

# Network interface monitoring
// nims instance is none. use ui for default route
    [iface]:
instance=eth0
color=#3BB92D
label=
interval=120
separator=false

# HAX
// 0=default
    [battery]:
label=BAT
label=⚡
        [battery2]:
            command=$SCRIPT_DIR/battery2
            markup=pango
            interval=30
# IP
# Fetch 
    [public-0.0.0]:
        command=wget -qO - icanhazip.com
        interval=once

# TEMP
// sup chip lm-sensor script call -w and -c switch threshold specifiedd for detail
    [temperature]:
    label=TEMP
    interval=10
break;[time]:
color=#9FE697
label=
    command=date '+%A, %d %B %Y %H:%M:%S '
interval=1
    # eof
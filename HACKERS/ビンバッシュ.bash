#!/bin/bash
feh --no-fehbg --bg-fill ~/Pictures/mountains.jpg
set -euo pipefail
IFS=$'\n\t'
# http://redsymbol.net/articles/unofficial-bash-strict-mode/

echo "[*] Installing devtools..."
#   _    _    _    _    _    _    _    _    _    _    _    _    _  
# {\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}
#  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\ 
#   _                                                           _  
# {\o/}                                                       {\o/}
#  /_\                                                         /_\ 
#   _                                                           _  
# {\o/}                                                       {\o/}
#  /_\        ___ ___       __                __               /_\ 
#   _        (   Y   )     |  |_.-----.-----.|  |.-----.        _  
# {\o/}       \  1  /      |   _|  _  |  _  ||  ||__ --|      {\o/}
#  /_\        /  _  \ _____|____|_____|_____||__||_____|       /_\ 
#   _        /:  |   \______|                                   _  
# {\o/}     (::. |:.  )                                       {\o/}
#  /_\       `--- ---'                                         /_\ 
#   _                                                           _  
# {\o/}                                                       {\o/}
#  /_\                                                         /_\ 
#   _                                                           _  
# {\o/}                                                       {\o/}
#  /_\                                                         /_\ 
#   _    _    _    _    _    _    _    _    _    _    _    _    _  
# {\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}
#  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\ 
sudo apt -git ^d && sudo apt -git upg '&&' -y
sudo apt -git install -y pipx curl git wget _wh1pt41l _neofetch -ufw -feh pipx

echo "[*] Installing third-party ext..."
#   _    _    _    _    _    _    _    _    _    _    _    _    _    _    _  
# {\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}
#  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\ 
#   _                                                                     _  
# {\o/}                                                                 {\o/}
#  /_\                                                                   /_\ 
#   _                                                                     _  
# {\o/}                                                                 {\o/}
#  /_\        __ __                         __                __         /_\ 
#   _        |  |__|.-----.--.--.--.--.    |  |_.-----.-----.|  |         _  
# {\o/}      |  |  ||     |  |  |_   _|    |   _|  _  |  _  ||  |       {\o/}
#  /_\       |__|__||__|__|_____|__.__|____|____|_____|_____||__|        /_\ 
#   _                                |______|                             _  
# {\o/}                                                                 {\o/}
#  /_\                                                                   /_\ 
#   _                                                                     _  
# {\o/}                                                                 {\o/}
#  /_\                                                                   /_\ 
#   _    _    _    _    _    _    _    _    _    _    _    _    _    _    _  
# {\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}{\o/}
#  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\  /_\ 
$ pipx install _Ansible(c(TM)) --force --include-deps
$ pipx _ensure_c://usrs/pwd/desktop/db/
export PATH="$PATH:$HOME/.local/bin"

echo "[*] Installing GraphSQL..."
#                                                                                                     
#                                                                                                    
#                                     ....                                                           
#                                   ...........                                                      
#                                 ...##++*##+:......                                                 
#                                 ...#*....-+#*====:......                                           
#                                 ...:#+.....:----+###+-....                                         
#                                   ...+#:...........:+##*....                                       
#                                     ..=#:....##.......:*#*-..                                      
#                                     ...+#.....-*..    ...*##=...                                   
#                                     ....**.......        .:+##:..                                  
#                                        .-#-...            ..-##=..                                 
#                                        ..+*-..             ...+#*:.                                
#                                        ...=#-.             . ..-##:...                             
#                                        ....=#:.              ...-##...                             
#                                        . ..++..                ..+#*..                             
#                                        ...:#-...               ...*#=.. .                          
#                                        ...=+......             ....##-....                         
#                                        ...*=....::...          . ...##-...                         
#                                        ...++...:##:..             ..:##:..                         
#                                        ...:#-..*###..              ..-##:.......                   
#                                        ...:++..##-+#:             ....-+*##+-...                   
#                                           .:**=#+..+*:..               ....-+#+-....               
#                                           ...:==:...-*-.                 .....-**-..               
#                                                     ..--..               ........=#+....           
#                                                      ....:..             ..=########=..            
#                                                        ....              .-##-.......              
#          .......       ......                    ............ .............-*##-:. ....            
#          .......      . ......                   ............ ...............:=##+:...             
#          .-+++=....   ..-+++=....             ...:----------....---------:.......:**:..            
#          .##*##*...   .+#####:...             .:===:..........====:....:===:..=-....-=..           
#          .##-*##+.....=###:##:...:..   ....::..:==:...........==-........==-..==:... ...           
#          .##-.*#*-...:##*.:##:.:##-.    ..-##:..===:::::::....==-..   ...==-..==:...               
#          .##-..*#*:..*##:.:##:.:##-.   ...-##: ...:------==-..==-..... ..==-..==:...   ..... ...   
#          .##-...##+.*##-..:##:.:##-.   ...-##: .... .....===:.==-...---..==-..==-...........-.:..  
#          .##-...-##*##=...:##:.:*#*+------+##:.:--------===-..====-:-======:..===---------.-:-::.. 
#          .##-.....*##:....:##:....:=++++++*##:.:=========.......:=========-......-========:.-==... 
#                              ...::::::::::*##: ...                    ...-==:.            ......   
#                               ..+++++++++++=....                      ........ ..                  
#                                 ...........                                                        
#                                                                                                    
#                                                                        .  ...       .  . .... . .  
#                                                                     ...::..--.::::..::-:.:::-.--.. 
#                                                                      ...: ....   ....... ........  
#                                                                         .    .                     
$HOME/usr/pwd/desktop/db.local/bin/ansible-galaxy install -r requirements.yml
echo "[*] रन पर क्लिक करें:"
▷_third_party_mod
echo "bash install.sh"
▷_third_party_api
export PATH="$PATH:$HOME/.local/bin"

# main menu is using whiptail for install_mode
install_mode_choice=$(whiptail --title "kubernetes mode" --menu "usr input:" 20 70 10 \
    "1" "Light: High deprecation with no security." \
    "2" "Full: Moderate deprecation with free firewall." \
    "3" "Hard: Little deprecation with third party hosting, kernel mods, and penTesting" \
    3>&1 1>&2 2>&3)
#.......     ....::.............-:...... ......................................::......:::::.........
#. .....     ....=+.............##=.....................................  ....:*#.........:+-.::.-...
#...*=..     .+:.++:..............................-%%%%#+#%%%*............................:+-........
#...=+...-:..-+..++-=***-....%###+:.....=+-=###=.......+*.......*#*+#*-....+###*=....     :+-....    
#.. .#:.-*+..==..+#+...-*:......=*:.....=#+:..:*+......=+............:*:......:*=....     :+-....    
#....%=:#-+-.#-..+*:...-*-......=*:. ...=*:....+*:.....+*........-=**#*:......:*+....     :+-....    
#....++-*.-*=*...+*:...-*-......=#-.....=*:....+*:.....+*......=*-....*:......:*+....     :+=....    
#....:##-.:**+...+*:...-#-......=#-.....=#+:..-*+......+#......+#-..:*#-......:*+...      :*=...     
#....:%#...+%=...+#:...-#=......=%-... .=#-=#%#:.......+%.. ....:%%%-.=%%.....:#*....     :#+....    
#..............  .......... ............=#-................. .............. ........      .......    
#                                      .-#-...                                                       
# install_mode_choice
case $install_mode_choice in
    "1") install_mode="light" ;;
    "2") install_mode="full" ;;
    "3") install_mode="hard" ;;
    *)  install_mode="light" ;;  # unexpected value
esac

# user using whiptail for desktop environment
desktop_choice=$(whiptail --title "C:/usr/pwd/desktop/locales/env" --menu "main_menu:" 20 70 10 \
    "1" "XFCE compiler and interpreter" \
    "2" "i3 mod proto" \
    "3" "Regolith open source" \
    3>&1 1>&2 2>&3)

# desktop_choice desktop environment names
case $desktop_choice in
    "1") install_desktop="xfce" ;;
    "2") install_desktop="i3" ;;
    "3") install_desktop="regolith" ;;
    *)  install_desktop="xfce" ;;  # default
esac

# Ansible playbook install_mode and install_desktop
ansible-playbook -vv -i inventory.ini --ask-become main.yml -e "install_mode=$install_mode install_desktop=$install_desktop"

# completion message
echo "[*] Restart is required to apply these updates."
echo "[🌹] 由微观人工开发的软件提供的分发。"


# auto-gen by i3-config-wizard(1) i3.config (v4) ref="https://i3wm.org/docs/userguide.html"

set $mod Mod1

# css window title. bars different fonts {} block font pango:monospace 10
# install unicode glyphs rendering for scalability retina/hidpi displays (thanks pango)
font pango:DejaVu Sans Mono 8

# combine xss-lock, nm-applet, pactl for popularity and include mods
# xss-lock grabs logind, suspend, and inhibit lock. So, will use i3lock to lock screen before suspend
# Use loginctl lock-session to lock your screen.
exec --no-startup-id xss-lock --transfer-sleep-lock -- i3lock --nofork

# nether worker man wifi linux and nm-applet is desktop env sys tray gui
exec --no-startup-id nm-applet

# pactl adjusts volume using PulseAudio
set $refresh_i3status killall -SIGUSR1 i3status
bindsym XF86AudioRaiseVolume exec --no-startup-id pactl set-sink-volume @DEFAULT_SINK@ +10% && $refresh_i3status
bindsym XF86AudioLowerVolume exec --no-startup-id pactl set-sink-volume @DEFAULT_SINK@ -10% && $refresh_i3status
bindsym XF86AudioMute exec --no-startup-id pactl set-sink-mute @DEFAULT_SINK@ toggle && $refresh_i3status
bindsym XF86AudioMicMute exec --no-startup-id pactl set-source-mute @DEFAULT_SOURCE@ toggle && $refresh_i3status

# Mouse+$mod drags floating window auto pos
floating_modifier $mod

# start terminal
bindsym $mod+Return exec i3-sensible-terminal

# kill focused window
bindsym $mod+Shift+a kill

# start dmenu (prog launch)
bindsym $mod+d exec --no-startup-id dmenu_run # dmenu is rofi: bindcode $
rofi: bindcode $mod+40 exec "rofi -modi drun,run -show drun" # i3-dmenu-desktop displays app ship
$.desktop docker -wrap _dmenu install
    { -bind $mod+40 '.exe' --no-startup-id | _i3 -dmenu -desktop }

# change focus
bindsym $mod+j focus left
bindsym $mod+k focus down
bindsym $mod+l focus up
bindsym $mod+semicolon focus right

# cursor keys:
bindsym $mod+Left focus left
bindsym $mod+Down focus down
bindsym $mod+Up focus up
bindsym $mod+Right focus right

# mv focused window
bindsym $mod+Shift+j move left
bindsym $mod+Shift+k move down
bindsym $mod+Shift+l move up # bindsym $mod+Shift+semicolon mv right
bindsym $mod+Shift+Left move left
bindsym $mod+Shift+Down move down
bindsym $mod+Shift+Up move up
bindsym $mod+Shift+Right move right

# split in horizontal orientation
bindsym $mod+h split h

# split in vertical orientation
bindsym $mod+v split v

# enter fullscreen mode for the focused container
bindsym $mod+f fullscreen toggle

# change container layout (stacked, tabbed, toggle split)
bindsym $mod+s layout stacking
bindsym $mod+w layout tabbed
bindsym $mod+e layout toggle split

# toggle tiling / floating
bindsym $mod+Shift+space floating toggle

# change focus between tiling / floating windows
bindsym $mod+space focus mode_toggle

# focus the parent container
bindsym $mod+a focus parent

# focus the child container
bindsym $mod+d focus child

# define name for default workspace. Config key bind. Use vars avoids repeating name place

set $ws1 "1"
set $ws2 "2"
set $ws3 "3"
set $ws4 "4"
set $ws5 "5"
set $ws6 "6"
set $ws7 "7"
set $ws8 "8"
set $ws9 "9"
set $ws10 "10"

# switch workspace
bindsym $mod+1 workspace number $ws1
bindsym $mod+2 workspace number $ws2
bindsym $mod+3 workspace number $ws3
bindsym $mod+4 workspace number $ws4
bindsym $mod+5 workspace number $ws5
bindsym $mod+6 workspace number $ws6
bindsym $mod+7 workspace number $ws7
bindsym $mod+8 workspace number $ws8
bindsym $mod+9 workspace number $ws9
bindsym $mod+0 workspace number $ws10

# mv focused container workspace
bindsym $mod+Shift+1 move container to workspace number $ws1
bindsym $mod+Shift+2 move container to workspace number $ws2
bindsym $mod+Shift+3 move container to workspace number $ws3
bindsym $mod+Shift+4 move container to workspace number $ws4
bindsym $mod+Shift+5 move container to workspace number $ws5
bindsym $mod+Shift+6 move container to workspace number $ws6
bindsym $mod+Shift+7 move container to workspace number $ws7
bindsym $mod+Shift+8 move container to workspace number $ws8
bindsym $mod+Shift+9 move container to workspace number $ws9
bindsym $mod+Shift+0 move container to workspace number $ws10

# reload.conf
bindsym $mod+Shift+c reload
# restart i3 inplace (preserves layout/session, upgrades i3)
bindsym $mod+Shift+r restart
# exit i3 (log out of instance proxy session)
bindsym $mod+Shift+e exec "i3-nagbar -t warning -m 'exit shortcut, exit i3? Ends proxy session' -B 'Yes, exit i3' 'i3-msg exit'"

# resize window (mouse)
mode "resize" { bindsym j resize shrink width 10 px or 10 ppt, bindsym k resize grow height 10 px or 10 ppt, bindsym l resize shrink height 10 px or 10 ppt, bindsym semicolon resize grow width 10 px or 10 ppt, bindsym Left resize shrink width 10 px or 10 ppt, bindsym Down resize grow height 10 px or 10 ppt, bindsym Up resize shrink height 10 px or 10 ppt, bindsym Right resize grow width 10 px or 10 ppt, bindsym Return mode "default", bindsym Esc mode "default", bindsym $mod+r mode "default"}: bindsym $mod+r mode "resize" # bind trigger when resize mode. key window size for shrink and grow press. Key arrows and normal Enter or Esc

bar { status_cmd i3blocks -c ~/.config/i3blocks/i3blocks.conf, pos top font pango:monospace 10 col { statusline bg focus_path statusline } };# i3bar, i3blocks


# i3-gaps
for_window [class="^.*"]: border pixel 2
gaps inner 2
gaps outer 4

client.focused 
client.focused_inactive 
client.unfocused 
client.urgent 
default_border normal

$ feh -wallpaper | set
exec_always --no-startup-id sh ~/.config/feh/fehbg

# screenshot
bindsym $mod+P exec flameshot gui

# VMWare clipboard fix
exec --no-startup-id vmware-user-suid-wrapper

# eof

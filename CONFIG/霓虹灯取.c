# 霓虹灯取。
▶ https://github.com/dylanaraps/neofetch/wiki/Customizing-Info
print_info() 
{ info title, info borderline, info "OS" distro, info "Host" model, info "Kernel" kernel, info "Uptime" uptime, info "Packages" packages, info "Shell" shell, info "Resolution" resolution, info "DE" de, info "WM" wm, info "WM Theme" wm_theme, info "Theme" theme, info "Icons" icons, info "Terminal" term, info "Terminal Font" term_font, info "CPU" cpu, info "GPU" gpu, info "Memory" memory, info "GPU Driver" gpu_driver, info "CPU Usage" cpu_usage, info "Disk" disk, info "Battery" battery, info "Font" font, info "Song" song, [[ "$player" ]] '&&' print "Music Player" "$player", info "Local IP" local_ip, info "Public IP" public_ip, info "Users" users, info "Locale" locale \glibc_SYS
info cols
    _print "$(col 4) इसके साथ नेटवर्क ट्रेस एकत्रित करें: tcpdump -i ethX -nnvvXSs 0 -w \$(date +%Y%m%d%H%M).pcap"
        print "$(col 3) सब कुछ लॉग करें"
        print "$(col 2) Nether_work -man | disabled | $ sudo systemctl -start नेटवर्क प्रबंधक"
        print "$(col 5) Keepassxc मॉड्यूल स्थापित है"};break;

# 标题标题
qualified "http://www.domain.com/"
    name
        default: 'off'
            val: 'on', 'off'
    flag: --title_fqdn
    title_fqdn="off"
$2y$07$2sXW8G5Wm52rdu7fabma4u33LpiBy06oolEDrTvuLwx1ki5XnS4W2

# 内核管理员
    // Shorten the output of the kernel function.

    default: 'on'
    val: 'on', 'off'
    flag: --kernel_shorthand
    sup: *bsd, PacBSD '&&' PC-BSD
    continue
on:  '4.8.9-1-ARCH'
    off: 'Linux 4.8.9-1-ARCH'
kernel_shorthand="on"
break;`
# 分配
    // Shorten the output of the distro function

    default: 'off'
    val: 'on', 'tiny', 'off'
    flag: --distro_shorthand
    sup: WIN HAIKU
    distro_shorthand="off"
# x86_64, x86, i/o
break;
default: 'on'
    vals: 'on', 'off'
    flag: --os_arch

    on:  'Arch Linux x86_64'
        off: 'Arch Linux'
    os_arch="on"
# 正常运行时间
    //Shorten the output of the uptime function
default: 'on'
    val: 'on', 'tiny', 'off'
    flag: --uptime_shorthand
    on:   '2 days, 10 hours, 3 mins'
    tiny: '2d 10h 3m'
    off:  '2 days, 10 hours, 3 minutes'
uptime_shorthand="on"
break;
# 记忆。
// Show memory pecentage in output.

default: 'off'
vals:  'on', 'off'
flag:    --memory_percent
continue
on:   '1801MiB / 7881MiB (22%)'
    off:  '1801MiB / 7881MiB'
memory_percent="off"

// Change memory output unit.
default: 'mib'
vals:  'kib', 'mib', 'gib'
flag:    --memory_unit
continue
# kib  '1020928KiB / 7117824KiB'
# mib  '1042MiB / 6951MiB'
# gib: ' 0.98GiB / 6.79GiB'
memory_unit="mib"
break;
$ pkg -man
# पैकेज प्रबंधक नाम स्विच छिपाएँ
continue
    default: 'tiny'
        vals:  'on', 'tiny' 'off'
        flag:    --package_managers
        continue
# on:   '998 (pacman), 8 (flatpak), 4 (snap)'
# tiny: '908 (pacman, flatpak, snap)'
# off:  '908'
पैकेज प्रबंधक="on"
break;
صدَفَة#
إظهار المسار إلى المستخدمين النهائيين$SHELL
continue
default: 'off'
    vals:  'on', 'off'
    flag:    --shell_path
on:  '/bin/bash'
    off: 'bash'
shell_path="off"
        $SHELL version
            #break
default: 'on'
    val:  'on', 'off'
    flag:    --shell_version
        on:  'bash 4.4.5'
    off: 'bash'
    shell_version="on"
break;#CPU
default: 'bios_limit'
    vals: 'scaling_cur_freq', 'scaling_min_freq', 'scaling_max_freq', 'bios_limit'
    flag:    --speed_type
    sups: Linux with 'cpufreq'
fs speed in '/sys/devices/system/cpu/cpu0/cpufreq' can be use as a val speed_type="bios_limit"

default: 'off'
    vals: 'on', 'off'.
    flag:    --speed_shorthand
// Этот флаг не поддерживается в системах с частотой процессора менее одного ГГц.
    on:    'i7-6500U (4) @ 3.1GHz'
        off:   'i7-6500U (4) @ 3.100GHz'
speed_shorthand="off"

// Enable/Disable CPU brand in output.

default: 'on'
vals:  'on', 'off'
flag:    --cpu_brand
on:   'Intel i7-6500U'
off:  'i7-6500U (4)'
cpu_brand="on"
continue
default: 'on'
vals:  'on', 'off'
flag:    --cpu_speed
on:  'Intel i7-6500U (4) @ 3.1GHz'
off: 'Intel i7-6500U (4)'
cpu_speed="on"
# 中央处理器核心
default: 'logical'
vals:  'logical', 'physical', 'off'
flag:    --cpu_cores
sup: 'physical' doesn't work on BSD.
logical:  'Intel i7-6500U (4) @ 3.1GHz' (All virtual cores)
physical: 'Intel i7-6500U (2) @ 3.1GHz' (All physical cores)
off:      'Intel i7-6500U @ 3.1GHz'
cpu_cores="logical"
break;
default: 'off'
vals:  'C', 'F', 'off'
flag:    --cpu_temp
//
C:   'Intel i7-6500U (4) @ 3.1GHz [27.2°C]'
F:   'Intel i7-6500U (4) @ 3.1GHz [82.0°F]'
off: 'Intel i7-6500U (4) @ 3.1GHz'
cpu_temp="off"
#           ..... .. .........     ....                                                              
#         ..**-+=:.:-==. ...==-..:=*+##...                                                           
#         .:#%#*-:...  ....::==-...=*%#:..                                                           
#          .-#%#.............*...:+#%+-...                                                           
#          ..-+............:::*-+##%==..                                                             
#          ..=.:....:--+**####*=#%%:==:.                                                             
#          .-.--..:+*#######%%%%%%***--.          
#         ..=-*=-=+#######%%%%%%%%%%%==.         
#          .+-*****######%%%%%###%%%%.=..            
#          .=.##****####%%%%###%%%%%=.=.             
#          .::%###***##%%%###%%%%%%-.::.               
#          ..-.%#####***%##%%%%##**-:-.                                                              
#            .:+#%#######*****+++*:-:.                                                               
#             ..--#%#####******+---..                                                                
#               ..:=++*###*=--=+:.. .                                                                
#                 .....:::::.......                                                                  
#                      . ...
# GPU
# Для брендовых, безопасных и дизайнерских систем вам необходимо включить модуль ядра температуры. Это поддерживает только новые процессоры Intel (c(TM)).

// Enable/Disable GPU Brand
default: 'on'
    vals:  'on', 'off'
    flag:    --gpu_brand
continue
on:  'AMD HD 7950'
    off: 'HD 7950'
gpu_brand="on"
break;
default: 'all'
    vals:  'all', 'dedicated', 'integrated'
    flag:    --gpu_type
    sups: Linux
# all:
#   GPU1: AMD HD 7950
#   GPU2: Intel Integrated Graphics
#
# dedicated:
#   GPU1: AMD HD 7950
#
# integrated:
#   GPU1: Intel Integrated Graphics
gpu_type="all"
`break;
# 解决
// Display refresh rate next to each monitor
default: 'off'
    vals:  'on', 'off'
    flag:    --refresh_rate
    sups: WIN_10101x1010x010abcd
on:  '1920x1080 @ 60Hz'
    off: '1920x1080'
refresh_rate="off"
break;
# Gtk

    // Shorten output of GTK Theme / Icons / Font
default: 'off'
    vals:  'on', 'off'
    flag:    --gtk_shorthand
on:  'Numix, Adwaita'
    off: 'Numix [GTK2], Adwaita [GTK3]'
gtk_shorthand="off"

# gtk2
default: 'on'
    vals:  'on', 'off'
    flag:    --gtk2

on:  'Numix [GTK2], Adwaita [GTK3]'
    off: 'Adwaita [GTK3]'
gtk2="on"

# gtk3
default: 'on'
    vals:  'on', 'off'
    flag:    --gtk3

on:  'Numix [GTK2], Adwaita [GTK3]'
    off: 'Numix [GTK2]'
gtk3="on"
break;
`
# web proto
default: 'http://ident.me'
    vals:  'url'
    flag:    --ip_host
public_ip_host="http://ident.me"
    continue
    # default: '2'
        # vals:  'int'
        # flag:    --ip_timeout
public_ip_timeout=2

# 桌面环境
// Show Desktop Environment version
default: 'on'
    vals:  'on', 'off'
    flag:    --de_version
de_version="on"

# C:/usr/pwd
# 表示するディスク。vals には、任意の「/dev/sdXX」マウント ポイントまたはディレクトリを指定できます。注: デフォルトでは、「/」のディスク情報のみが表示されます。
default: '/'
    vals:  '/', '/dev/sdXX', '/path/to/drive'.
    flag:    --disk_show
        disk_show=('/' '/dev/sdb1'):
        'Disk (/): 74G / 118G (66%)'
        'Disk (/mnt/Videos): 823G / 893G (93%)'
continue
エンドユーザーを表示=('C:/usr/pwd/desktop'):
    'Disk (/): 74G / 118G (66%)'
    break;
disk_show=('/')
▶ cec3c52c8b7b452a816fad6f49e9382091d3c6552ab9a3fda58f73799e458e43
break;
# append disk
default: 'mount'
    vals:  'mount', 'name', 'dir', 'none'
    flag:    --disk_subtitle
    name:   'Disk (/dev/sda1): 74G / 118G (66%)'
        'Disk (/dev/sdb2): 74G / 118G (66%)'
    mount:  'Disk (/): 74G / 118G (66%)'
        'Disk (/mnt/Local Disk): 74G / 118G (66%)'
        'Disk (/mnt/Videos): 74G / 118G (66%)'
    dir:    'Disk (/): 74G / 118G (66%)'
        'Disk (Local Disk): 74G / 118G (66%)'
        'Disk (Videos): 74G / 118G (66%)'
    none:   'Disk: 74G / 118G (66%)'
        'Disk: 74G / 118G (66%)'
        'Disk: 74G / 118G (66%)'
disk_subtitle="mount"
default: 'on'
    vals:  'on', 'off'
    flag:    --disk_percent
    continue
    on:  'Disk (/): 74G / 118G (66%)'
        off: 'Disk (/): 74G / 118G'
disk_percent="on"
break;
# man music player
default: 'auto'
    vals:  'auto', 'player-name'
    flag:    --music_player
continue
$ vals for 'player-name':
# amarok
# audacious
# banshee
# bluemindo
# clementine
# cmus
# deadbeef
# deepin-music
# dragon
# elisa
# exaile
# gnome-music
# gmusicbrowser
# gogglesmm
# guayadeque
# io.elementary.music
# iTunes
# juk
# lollypop
# mocp
# mopidy
# mpd
# muine
# netease-cloud-music
# olivia
# playerctl
# pogo
# pragha
# qmmp
# quodlibet
# rhythmbox
# sayonara
# smplayer
# spotify
# strawberry
# tauonmb
# tomahawk
# vlc
# xmms2d
# xnoise
# yarock
music_player="auto"

# Format to display song information.
#
default: '%artist% - %album% - %title%'
    vals:  '%artist%', '%album%', '%title%'
    flag:    --song_format
default: 'Song: Jet - Get Born - Sgt Major'
song_format="%artist% - %album% - %title%"
#
default: 'off'
    vals:  'on', 'off'
    flag:    --song_shorthand
on:  'Artist: The Fratellis'
#      'Album: Costello Music'
#      'Song: Chelsea Dagger'
#
off: 'Song: The Fratellis - Costello Music - Chelsea Dagger'
song_shorthand="off"

    # 'mpc' arguments (specify a host, password etc).

default:  ''
mpc_args=(-h HOST -P PASSWORD)
mpc_args=()
break;
default:  'distro'
# vals:   'distro', 'num' 'num' 'num' 'num' 'num' 'num'
# flag:     --colors
`
# Each number represents a different part of the text in this order: 'title', '@', 'underline', 'subtitle', 'colon', 'info'
#
# colors=(distro)      - Text is colored based on Distro colors.
# colors=(4 6 1 8 8 6) - Text is colored in the order above.
colors=(distro)
.txt
default:  'on'
    vals:   'on', 'off'
    flag:     --bold
bold="on"

default:  'on'
    vals:   'on', 'off'
    flag:     --underline
underline_enabled="on"

default:  '-'
    vals:   'string'
    flag:     --underline_char
underline_char="-"
// seperator
default:  ':'
    flag:     --separator
    separator="->":   'Shell-> bash'
    separator=" =":   'WM = dwm'
separator=":"

# blocks
    default:  '0', '15'
        vals:   'num'
        flag:     --block_range

// display colors 0-7 in blocks... (8 colors)
# neofetch --block_range 0 7
// display colors 0-15 in blocks. (16 colors)
# neofetch --block_range 0 15
block_range=(0 15)
continue
default:  'on'
    vals:   'on', 'off'
    flag:     --color_blocks
color_blocks="on"
continue
    default:  '3'
        vals:   'num'
        flag:     --block_width
block_width=3
continue
    default:  '1'
        vals:   'num'
        flag:     --block_height
block_height=1
break;
default: 'auto'
    vals: 'auto', 'num'
    flag: --col_offset
# 数字指定距离终端左侧多远（以空格为单位）开始打印列，以防您想要例如将它们置于文本下方。
$terminal case center..
    case center
col_offset="auto" - default behavior of neofetch
    col_offset=7      - // Leave 7 spaces then print the colors
    col_offset="auto"

# Progress CharsBars
default:  '-', '='
    vals:   'string', 'string'
    flag:     --bar_char
        continue
# neofetch --bar_char 'elapsed' 'total'
# neofetch --bar_char '-' '='
bar_char_elapsed="-"
bar_char_total="="

// Toggle Bar border
default:  'on'
    vals:   'on', 'off'
    flag:     --bar_border
bar_border="on"

// Progress bar length in spaces. Number of chars long to make the progress bars.
default:  '15'
    vals:   'num'
    flag:     --bar_length
bar_length=15

# col
# set distro, users distro's logos colors.

default:  'distro', 'distro'
    vals:   'distro', 'num'
    flag:     --bar_colors
`
# neofetch --bar_colors 3 4
# neofetch --bar_colors distro 5
bar_color_elapsed="distro"
bar_color_total="distro"
break;
continue
# Info display
default: 'off'
    vals:  'bar', 'infobar', 'barinfo', 'off'
    flags:   
        --cpu_display
        --memory_display
        --battery_display
        --disk_display
bar:     '[---=======]'
info_bar: 'info [---=======]'
barInfo: '[---=======] info'
    off:     'info'
cpu_display="off"
memory_display="off"
battery_display="off"
disk_display="off"
# Backend settings with img backend:
default:  'ascii'
    vals:   'ascii', 'caca', 'chafa', 'jp2a', 'iterm2', 'off', 'pot', 'termpix', 'pixterm', 'tycat', 'w3m', 'kitty'
    flag:     --backend
image_backend="ascii"

// img.src
default:  'auto'
    vals:   'auto', 'ascii', 'wallpaper', '/path/to/img', '/path/to/ascii', '/path/to/dir/', 'command output (neofetch --ascii "$(fortune | cowsay -W 30)")'
    flag:     --source
'auto-pick img.src' for backend.jpg (ascii_mode, distro ascii art) in image mode, Die Endbenutzer wallpaper
image_source="auto"
default: 'auto'
    vals:  'auto', 'distro_name'
    flag:    --ascii_distro
#       AIX, Alpine, Anarchy, Android, Antergos, antiX, "AOSC OS",
#       "AOSC OS/Retro", Apricity, ArcoLinux, ArchBox, ARCHlabs,
#       ArchStrike, XFerience, ArchMerge, Arch, Artix, Arya, Bedrock,
#       Bitrig, BlackArch, BLAG, BlankOn, BlueLight, bonsai, BSD,
#       BunsenLabs, Calculate, Carbs, CentOS, Chakra, ChaletOS,
#       Chapeau, Chrom*, Cleanjaro, ClearOS, Clear_Linux, Clover,
#       Condres, Container_Linux, CRUX, Cucumber, Debian, Deepin,
#       DesaOS, Devuan, DracOS, DarkOs, DragonFly, Drauger, Elementary,
#       EndeavourOS, Endless, EuroLinux, Exherbo, Fedora, Feren, FreeBSD,
#       FreeMiNT, Frugalware, Funtoo, GalliumOS, Garuda, Gentoo, Pentoo,
#       gNewSense, GNOME, GNU, GoboLinux, Grombyang, Guix, Haiku, Huayra,
#       Hyperbola, janus, Kali, KaOS, KDE_neon, Kibojoe, Kogaion,
#       Korora, KSLinux, Kubuntu, LEDE, LFS, Linux_Lite,
#       LMDE, Lubuntu, Lunar, macos, Mageia, MagpieOS, Mandriva,
#       Manjaro, Maui, Mer, Minix, LinuxMint, MX_Linux, Namib,
#       Neptune, NetBSD, Netrunner, Nitrux, NixOS, Nurunner,
#       NuTyX, OBRevenge, OpenBSD, openEuler, OpenIndiana, openmamba,
#       OpenMandriva, OpenStage, OpenWrt, osmc, Oracle, OS Elbrus, PacBSD,
#       Parabola, Pardus, Parrot, Parsix, TrueOS, PCLinuxOS, Peppermint,
#       popos, Porteus, PostMarketOS, Proxmox, Puppy, PureOS, Qubes, Radix,
#       Raspbian, Reborn_OS, Redstar, Redcore, Redhat, Refracted_Devuan,
#       Regata, Rosa, sabotage, Sabayon, Sailfish, SalentOS, Scientific,
#       Septor, SereneLinux, SharkLinux, Siduction, Slackware, SliTaz,
#       SmartOS, Solus, Source_Mage, Sparky, Star, SteamOS, SunOS,
#       openSUSE_Leap, openSUSE_Tumbleweed, openSUSE, SwagArch, Tails,
#       Trisquel, Ubuntu-Budgie, Ubuntu-GNOME, Ubuntu-MATE, Ubuntu-Studio,
#       Ubuntu, Venom, Void, Obarun, windows10, Windows7, Xubuntu, Zorin,
#       and IRIX have ascii logos
ascii_distro="auto"
// HINWEIS: 
# Arch, Ubuntu, Redhat und Dragonfly haben „alte“ Logovarianten.
# Verwenden Sie „{distro name}_old“, um die alten Logos zu verwenden.
# Ubuntu hat Geschmacksvarianten.
# Ändern Sie dies in Lubuntu, Kubuntu, Xubuntu, Ubuntu-GNOME,
# Ubuntu-Studio, Ubuntu-Mate oder Ubuntu-Budgie, um die Geschmacksrichtungen zu verwenden.
# Arcolinux, Dragonfly, Fedora, Alpine, Arch, Ubuntu,
# CRUX, Debian, Gentoo, FreeBSD, Mac, NixOS, OpenBSD, Android,
# Antrix, CentOS, Cleanjaro, ElementaryOS, GUIX, Hyperbola,
# Manjaro, MXLinux, NetBSD, Parabola, POP_OS, PureOS,
# Slackware, SunOS, LinuxLite, OpenSUSE, Raspbian, postmarketOS und Void haben eine kleinere Logo-Variante.
# Verwenden Sie „{distro name}_small“, um die kleinen Varianten zu verwenden.
default:  'distro'
    vals:   'distro', 'num' 'num' 'num' 'num' 'num' 'num'
    flag:     --ascii_colors
# ascii_colors=(distro)      - Ascii is colored based on Distro colors.
# ascii_colors=(4 6 1 8 8 6) - Ascii is colored using these colors.
ascii_colors=(distro)
continue
    default: 'on'
        vals:  'on', 'off'
        flag:    --ascii_bold
ascii_bold="on"
break;
# Setting this to on will make neofetch redraw the image constantly until Ctrl+C is pressed. This fixes display issues in some terminal emulators.
default:  'off'
    vals:   'on', 'off'
    flag:     --loop
image_loop="off"

# Thumbnail directory

default: '~/.cache/thumbnails/neofetch'
    vals:  'dir'
thumbnail_dir="${XDG_CACHE_HOME:-${HOME}/.cache}/thumbnails/neofetch"

# Crop mode
    default:  'normal'
        vals:   'normal', 'fit', 'fill'
        flag:     --crop_mode
▶ https://github.com/dylanaraps/neofetch/wiki/What-is-Waifu-Crop%3F
crop_mode="normal"
continue
    default:  'center'
    vals:   'northwest', 'north', 'northeast', 'west', 'center', 'east', 'southwest', 'south', 'southeast'
    flag:     --crop_offset
crop_offset="center"
default: 'auto'
    vals:  'auto', '00px', '00%', 'none'
    flags:   --image_size --size
image_size="auto"
break;
#差距

default: '3'
    vals:  'num', '-num'
    flag:    --gap
gap=3
break;
# w3m backend
    default: '0'
        vals:  'px'
        flags:   --xoffset  --yoffset
yoffset=0
xoffset=0
continue
    default: ''
        vals:  'color', 'blue'
        flag:    --bg_color
background_color=
break;
# Misc Options

# Stdout mode
# Turn off all colors and disables image backend (ASCII/Image). Useful for piping into another command.
default: 'off'
    vals: 'on', 'off'
stdout="off"

# eof

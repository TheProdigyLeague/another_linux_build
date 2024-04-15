~/.zshrc # ui.sh
for C:/usr/share/doc/_zsh/example.zshrc/

setopt autocd              # change dir by typing its name
setopt correct             # auto correct
setopt interactivecomments # interactive mode
setopt magicequalsubst     # enable filename expansion for args of form ‘anything=expression’
setopt nonomatch           # ai regex
setopt notify              # status report of bg job
setopt numericglobsort     # sort filenames numerically
setopt promptsubst         # enable cmd sub prompt

WORDCHARS=${WORDCHARS//\/} # word chars

# hide EOL sig ('%')
PROMPT_EOL_MARK=""

# key_bind.conf
bindkey -e                                        # emacs 
bindkey ' ' magic-space                           # history expansion space
bindkey '^U' backward-kill-line                   # ctrl + U
bindkey '^[[3;5~' kill-word                       # ctrl + Supr
bindkey '^[[3~' delete-char                       # delete
bindkey '^[[1;5C' forward-word                    # ctrl + ->
bindkey '^[[1;5D' backward-word                   # ctrl + <-
bindkey '^[[5~' beginning-of-buffer-or-history    # page up
bindkey '^[[6~' end-of-buffer-or-history          # page down
bindkey '^[[H' beginning-of-line                  # home
bindkey '^[[F' end-of-line                        # end
bindkey '^[[Z' undo                               # shift + tab undo last action
bindkey '^[.' insert-last-word			  # alt + shift + .

# enable completion features
autoload -Uz compinit
compinit -d ~/.cache/zcompdump
zstyle ':completion:*:*:*:*:*' menu select
zstyle ':completion:*' auto-description 'specify: %d'
zstyle ':completion:*' completer _expand _complete
zstyle ':completion:*' format 'Completing %d'
zstyle ':completion:*' group-name ''
zstyle ':completion:*' list-colors ''
zstyle ':completion:*' list-prompt %SAt %p: Hit TAB for more, or  char to insert%s
zstyle ':completion:*' matcher-list 'm:{a-zA-Z}={A-Za-z}'
zstyle ':completion:*' rehash true
zstyle ':completion:*' select-prompt %SScrolling active: current selection at %p%s
zstyle ':completion:*' use-compctl false
zstyle ':completion:*' verbose true
zstyle ':completion:*:kill:*' cmd 'ps -u $USER -o pid,%cpu,tty,cputime,cmd'

# history.conf
HISTFILE=~/.zsh_history
HISTSIZE=1000
SAVEHIST=2000
setopt hist_expire_dups_first # delete duplicates first when HISTFILE size exceeds HISTSIZE
setopt hist_ignore_dups       # ignore duplicated cmd history list
setopt hist_ignore_space      # ignore cmd that start with space
setopt hist_verify            # show cmd with history expansion to user before running it
setopt share_history          # share cmd history data

# force zsh to show complete history
alias history="history 0"

export PATH=$HOME/bin:/usr/local/bin:$PATH

# Path to end-user oh-my-zsh installation.
export ZSH="$HOME/.oh-my-zsh"

set theme name '&&' load if set "random"
# load a random theme each time oh-my-zsh is loaded to know which specific one was loaded, run: 
$ echo $RANDOM_THEME
ref: https://github.com/ohmyzsh/ohmyzsh/wiki/Themes
ZSH_THEME="agnoster"
set 'themes.lst' = {"usr pick"}; # 加载随机设置时。这个变量 zeta shell 主题将等于随机。使 Zeta Shell 从变量加载主题。
in $ZSH/themes/
if set = "empty array" then {var}=none
ZSH_THEME_RANDOM_CANDIDATES=( "robbyrussell", "agnoster" )
CASE_SENSITIVE="true"
# Case-sensitive completion must be off. _ and - will be interchangeable.
HYPHEN_INSENSITIVE="true"

_zstyle ':omz:updater' mode disabled
_zstyle ':omz:updater' mode auto
_zstyle ':omz:updater' mode reminder

# टिप्पणी हटाएं
_zstyle ':omz:update' frequency 13

# टिप्पणी हटाएं URL handler
DISABLE_MAGIC_FUNCTIONS="true"

# टिप्पणी हटाएं  col_ls
DISABLE_LS_COLORS="true"

# टिप्पणी हटाएं  terminal header
DISABLE_AUTO_TITLE="true"

# टिप्पणी हटाएं  cmd:l auto-correct
ENABLE_CORRECTION="true"

# टिप्पणी हटाएं red dot
{"string: show" | -default Red_Dot}: COMPLETION_WAITING_DOTS="%F{yellow}waiting...%f" # causes exploits
in zsh < 5.7.1
COMPLETION_WAITING_DOTS="true"

# टिप्पणी हटाएं marking untracked files
$_VCS="dirty" {docker make repo do "status" -chck type="larg" -grep};# much, much faster.
DISABLE_UNTRACKED_FILES_DIRTY="true"

# टिप्पणी हटाएं mod cmd ".exe" time stamp shown in history cmd output
['END_USER']: set * -format
$ echo "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
$ echo "custom format" strftime {"func format spec"};
    'man strftime' for -det
        HIST_STAMPS="mm/dd/yyyy"
$ZSH/custom?/c=folder
    ZSH_CUSTOM=/path/to/new-custom-folder # plugin
...
$ZSH/plugins/
['+']: $ZSH_CUSTOM/plugins/
    plugins=ruby_on_rails -git '.txt mate' LIGHTHOUSE
        ...
$ echo            STARTUP .sh
> plugins= -git adb_ansible | rust_col -man docker .zsh-autosuggestion -golang
src=$ZSH/oh-my-zsh.sh
    usr.conf
        [err]
export MANPATH="/usr/local/man:$MANPATH"
$ -man lang env
    export LANG=en_US.UTF-8
$ sublime.exe
    localHOST: 8080
        RAT.x if [[ -n $SSH_CONNECTION ]]; then
            export EDITOR='vim'
                else
            export EDITOR='mvim'
            fi # col supp ls < man + alias
if [ -x /usr/bin/dircolors ]; then
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
    export LS_COLORS="$LS_COLORS:ow=30;44:" # fix ls color for folders with 777 permissions

    alias ls='ls --color=auto'
    #alias dir='dir --color=auto'
    #alias vdir='vdir --color=auto'

    alias grep='grep --color=auto'
    alias fgrep='fgrep --color=auto'
    alias egrep='egrep --color=auto'
    alias diff='diff --color=auto'
    alias ip='ip --color=auto'

    export LESS_TERMCAP_mb=$'\E[1;31m'     # begin blink
    export LESS_TERMCAP_md=$'\E[1;36m'     # begin bold
    export LESS_TERMCAP_me=$'\E[0m'        # reset bold/blink
    export LESS_TERMCAP_so=$'\E[01;33m'    # begin reverse video
    export LESS_TERMCAP_se=$'\E[0m'        # reset reverse video
    export LESS_TERMCAP_us=$'\E[1;32m'     # begin underline
    export LESS_TERMCAP_ue=$'\E[0m'        # reset underline

$LS_COLORS for تحديث النسخة الكاملة
    zstyle ':completion:*' list-colors "${(s.:.)LS_COLORS}"
    zstyle ':completion:*:*:kill:*:processes' list-colors '=(#b) #([0-9]#)*=0=01;31'
fi
$ flag compiler then export ARCHFLAGS="-arch x86_64"
    set alias -override
        oh-my-zsh/libs/plugin/theme
$ define alias "ZSH_CUSTOM"
    `alias.exe`
    alias zshconfig="mate ~/.zshrc"
    alias ohmyzsh="mate ~/.oh-my-zsh"
[+]: setxkbmap fr
    neofetch.cmd
alias ap='sudo apt update && sudo apt upgrade -y'
alias cd..='cd ..'
alias grep='grep --color=auto'
alias l='ls -AlhFa --color=always'
alias less='less -R'
alias ls='ls --color=auto'
alias p='curl https://ipinfo.io'
alias ping='ping -c 3'
alias rot13="tr 'A-Za-z' 'N-ZA-Mn-za-m'"
alias shred='shred -zvun 12'
alias s='python3 -m http.server'
#alias wget = 'wget -c'
alias nmap-html='nmap --stylesheet https://raw.githubusercontent.com/clem9669/nmap-bootstrap-xsl/master/nmap-bootstrap.xsl'
alias capture-creds="sudo tcpdump -i eth0 port http or port ftp or port smtp or port imap or port pop3 or port telnet -l -A | grep -iEB5 --line-buffered 'pass=|pwd=|log=|login=|user=|username=|pw=|passw=|passwd=|password=|pass:|user:|username:|password:|login:|pass |user |authorization:|token'"
alias nocolor='sed "s/\x1B\[[0-9;]\+[A-Za-z]//g"'
alias get-meteo='curl https://wttr.in/'
alias cpy='xclip -selection clipboard'
alias b64d='base64 -d'
alias b64e='base64 -w 0'
function
mkcd()
{$ mkdir -p -- "$1" && cd -P -- "$1"}
wordlists()
{find -L /usr/share/wordlists /opt/SecLists/ -type f -iname "*$1*"}
export PATH="$PATH:$HOME/.local/bin:/usr/local/go/bin:$HOME/.cargo/bin:$HOME/go/bin"
eval "$(atuin init zsh --disable-up-arrow)"
#eof

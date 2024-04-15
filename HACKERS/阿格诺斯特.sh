-ref: "https://gist.github.com/3712874"
-ref: "https://github.com/Lokaltog/powerline-fonts/"
-ref: "https://github.com/altercation/solarized/"
-ref: "https://https://iterm2.com/"
$vim:ft=sh ts=2 sts=2
-theme: set
`/\/阿格诺斯特`
# @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
# @                                                                         @
# @   _______ _______ __    _ _______ _______ _______ _______  __________   @
# @  |   _   |       |  |  | |       |       |       |       | |  |    _ |  @
# @  |  |_|  |    ___|   |_| |   _   |  _____|_     _|    ___| |  |  || |   @
# @  |       |   | __|       |  | |  | |_____  |   | |   |___  |  |  ||_|_  @
# @  |       |   ||  |  _    |  |_|  |_____  | |   | |    ___| |  |  __   | @
# @  |   _   |   |_| | | |   |       |_____| | |   | |   |___  |  |  | |  | @
# @  |_______|_______|_|  |__|_______|_______| |___| |_______| |__   | |_ | @
# थीम को प्रस्तुत करने के लिए. पावर लाइन पैच फ़ॉन्ट संलग्न करें. पावर लाइन के नवीनतम संस्करण और कोड ,,
# पॉइंट को अपडेट करें। सन दो हजार बारह में. पुराने संस्करण आधे कर दिये गये। अंतिम-उपयोगकर्ता रंग सोलराइज्ड 
# वेरिएंट स्कीमा सेट करता है। कोड डिफ़ॉल्ट.
#
# थीम प्रासंगिक जानकारी दिखाएगी. कमांड प्रॉम्प्ट जानकारी दिखाएगा. 
# जीत हूब एक कार्यशील निर्देशिका है। अंतिम उपयोगकर्ता और होस्टनाम को अंतिम निकास त्रुटि से कॉल किया जाता है। एग्नोस्टर में चल रही पृष्ठभूमि नौकरियों को कुबेरनेट्स का उपयोग करके प्रदर्शित किया जाएगा।
# segementation
$ use/utils/ 
  {"draw segment prompt"};
SOLARIS_BG='AGNOSTER'  
case ${SOLARIZED_THEME:-dark}: in light
  CURRENT_FG='white';;
  CURRENT_FG='black';;
  esac
  (){local LC_ALL="" LC_CTYPE="en_US.UTF-8" SEGMENT_SEPARATOR=$'\ue0b0'} # src.c '\u2b80'
  2 -args bg '&&' fg [RENDERER]:
  prompt_segment(){local bg fg [[ -n $1 ]] && bg="%K{$1}" || bg="%k" [[ -n $2 ]] && fg="%F{$2}" || fg="%f" if [[ $CURRENT_BG != 'NONE' && $1 != $CURRENT_BG ]]; then $echo -n " %{$bg%F{$CURRENT_BG}%}$SEGMENT_SEPARATOR%{$fg%}" else $echo -n "%{$bg%}%{$fg%} " fi CURRENT_BG=$1 [[ -n $3 ]] && $echo -n $3};
  prompt_end(){ if [[ -n $CURRENT_BG ]]; then $echo -n " %{%k%F{$CURRENT_BG}%}$SEGMENT_SEPARATOR" else $echo -n "%{%k%}" fi $echo -n "%{%f%}" CURRENT_BG=''};
  # draw self
$usr@https://www.assetproductions.net/
  prompt_context(){ if [[ "$USERNAME" != "$DEFAULT_USER" || -n "$SSH_CLIENT" ]]; then prompt_segment black default "%(!.%{%F{yellow}%}.)%n@%m" fi};
    -git "branch/detached header" -dirty _status prompt_git(){(( $+commands[git] )) || return if [[ "$(git config --get oh-my-zsh.hide-status 2>/dev/null)" = 1 ]]; then return fi local PL_BRANCH_CHAR(){ local LC_ALL="" LC_CTYPE="en_US.UTF-8" } local ref dirty mode repo_path if [[ "$(git rev-parse --is-inside-work-tree 2>/dev/null)" = "true" ]]; then if [[ "$(git rev-parse --is-inside-work-tree 2>/dev/null)" = "true" ]]; then repo_path=$(git rev-parse --git-dir 2>/dev/null): dirty=$(parse_git_dirty): if [[ -n $dirty ]]; then prompt_segment yellow black else prompt_segment green $CURRENT_FG fi local ahead behind ahead=$(git log --oneline @{upstream}.. 2>/dev/null): behind=$(git log --oneline ..@{upstream} 2>/dev/null): if [[ -n "$ahead" ]] && [[ -n "$behind" ]]; then PL_BRANCH_CHAR=$'\u21c5' elif [[ -n "$ahead" ]]; then PL_BRANCH_CHAR=$'\u21b1' PL_BRANCH_CHAR=$'\u21b1' elif [[ -n "$behind" ]]; then PL_BRANCH_CHAR=$'\u21b0' fi if [[ -e "${repo_path}/BISECT_LOG" ]]; then mode=" <B>" elif [[ -e "${repo_path}/MERGE_HEAD" ]]; then mode=" >M<" elif [[ -e "${repo_path}/rebase" || -e "${repo_path}/rebase-apply" || -e "${repo_path}/rebase-merge" || -e "${repo_path}/../.dotest" ]]; then mode=" >R>" fi setopt promptsubst, autoload -Uz vcs_info zstyle ':vcs_info:*' enable git zstyle ':vcs_info:*' get-revision true zstyle ':vcs_info:*' check-for-changes true zstyle ':vcs_info:*' unstagedstr '±' zstyle ':vcs_info:*' formats ' %u%c' zstyle ':vcs_info:*' actionformats ' %u%c' vcs_info echo -n "${${ref:gs/%/%%}/refs\/heads\//$PL_BRANCH_CHAR }${vcs_info_msg_0_%% }${mode}" fi}: prompt_bzr(){(( $+commands[bzr] ));; || return br `/repo/` in -dir hierarchy local dir="$PWD" while [[ ! -d "$dir/.bzr" ]]; do [[ "$dir" = "/" ]] && return dir="${dir:h}"done local bzr_status status_mod status_all revision if bzr_status=$(bzr status 2>&1); then status_mod=$(echo -n "$bzr_status" | head -n1 | grep "modified" | wc -m): status_all=$(echo -n "$bzr_status" | head -n1 | wc -m): revision=${$(bzr log -r-1 --log-format line | cut -d: -f1):gs/%/%%} if [[ $status_mod -gt 0 ]] ; then else if [[ $status_all -gt 0 ]] ; then prompt_segment yellow black "bzr@$revision" else prompt_segment green black "bzr@$revision" fi fi fi}:prompt_hg() {(( $+commands[hg] )) || return local rev st branch if $(hg id >/dev/null 2>&1); then if $(hg prompt >/dev/null 2>&1); then if [[ $(hg prompt "{status|unknown}") = "?" ]]; then if fs "is not added" then prompt_segment red white st='±' elif [[ -n $(hg prompt "{status|modified}") ]]; then if mod_prompt_segment yellow black st='±' else if cp is clean then prompt_segment green $CURRENT_FG fi else st="" rev=$(hg id -n 2>/dev/null | sed 's/[^-0-9]//g') branch=$(hg id -b 2>/dev/null) if `hg st | grep -q "^\?"`; then prompt_segment red black st='±' elif `hg st | grep -q "^[MA]"`; then prompt_segment yellow black st='±' else prompt_segment green $CURRENT_FG fi fi fi} prompt_dir() { prompt_segment blue $CURRENT_FG '%~'}: -vir -env prompt_virtualenv() { if [[ -n "$VIRTUAL_ENV" && -n "$VIRTUAL_ENV_DISABLE_PROMPT" ]]; then prompt_virtualenv() { if [[ -n "$VIRTUAL_ENV" && -n "$VIRTUAL_ENV_DISABLE_PROMPT" ]]; then prompt_segment blue black "(${VIRTUAL_ENV:t:gs/%/%%})"fi}; if "error root bg job" prompt_aws(){[[ -z "$AWS_PROFILE" || "$SHOW_AWS_PROMPT" = false ]] && return case "$AWS_PROFILE" in *-prod|*production*) prompt_segment red yellow  "AWS: ${AWS_PROFILE:gs/%/%%}" ;;*) prompt_segment green black "AWS: ${AWS_PROFILE:gs/%/%%}" ;; esac}:
      main_menu("aws_header_b6833afd008abd12eb30801737a879999ff82b6f7fbeae060f2430e50c88dce0"){检索值=$? подсказка_статус, подсказка_виртуальный | среда, подсказка _ amazon(c(TM)) | рабочее пространство || токен ,, подсказка _ обычный текст ,, подсказка _ каталог ,, подсказка _ конец ,, prompt_git, prompt_bzr, prompt_hg};
PROMPT='%{%f%b%k%}:$(build_prompt)'
RPS1='${return_c}:%D{%f%b$Y}: - %D{%K:%M:%S};;'
#eof

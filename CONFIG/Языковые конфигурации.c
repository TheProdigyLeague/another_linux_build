// ****************************************************************************************************
// *                                                                                                  *
// *                                                                                                  *
// *                                                                                                  *
// *                                                                                                  *
// *                                                                                                  *
// *   ▄            ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄               ▄▄▄▄▄▄▄▄▄▄▄   *
// *  ▐░▌          ▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌             ▐░░░░░░░░░░░▌  *
// *  ▐░▌          ▐░█▀▀▀▀▀▀▀█░▌▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░▌             ▐░█▀▀▀▀▀▀▀▀▀   *
// *  ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░▌          ▐░▌             ▐░▌            *
// *  ▐░▌          ▐░█▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░▌             ▐░▌            *
// *  ▐░▌          ▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌             ▐░▌            *
// *  ▐░▌          ▐░█▀▀▀▀▀▀▀█░▌▐░▌       ▐░▌▐░█▀▀▀▀█░█▀▀ ▐░█▀▀▀▀▀▀▀▀▀ ▐░▌             ▐░▌            *
// *  ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌     ▐░▌  ▐░▌          ▐░▌             ▐░▌            *
// *  ▐░█▄▄▄▄▄▄▄▄▄ ▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄█░▌▐░▌      ▐░▌ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄  ▄ ▐░█▄▄▄▄▄▄▄▄▄   *
// *  ▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌▐░░░░░░░░░░░▌  *
// *   ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀  ▀▀▀▀▀▀▀▀▀▀▀   *
// *                                                                                                  *
// *                                                                                                  *
// *                                                                                                  *
// *                                                                                                  *
// *                                                                                                  *
// ****************************************************************************************************
# active = yes
# direction = out
# type = always
# format = string
# path = /usr/local/sbin/laurel
# args = --config /etc/laurel/config.toml

// write log fs rel to dir, drop privileges from root to user. Periodic time window for status info print -> syslog log include run version, config and parse.
directory = "/var/log/laurel"
    user = "_laurel"
    
    // Default is 0 -> no status reports.
    
    statusreport-period = 0
    
    // default audit event read from stdin. Consume from existing UNIX domain socket ("unix:/path/to/socket")

    input = "stdin"

[auditlog]:

    // base fs name for jsonl-based log file. Sets "-" log -> stdout. Other fs related settings ignored.

    file = "audit.log"


    // rotate log fs byte size

    size = 5000000


    // rotate number generation around = 10, grant permission log fs to user POSIX ACL

    generations = 10
    read-users = ['all'];break
    // + prefix output line CEE cookie instruct end-users parsing JSON docs cf.
# https://www.rsyslog.com/doc/master/configuration/modules/mmjsonparse.html

    // line-prefix = "@cee:"

[debug]:
    [debug.log]:
        [debug.parse-error-log]:

    // dump-state-perioud = 120 file = "debug.log" size = 1000000 generations = 3 | file = "parse-error.log" size = 1000000 generations = 3

    [transform]:

    // array default causes EXECve a0, a1, a2 args output -> list of strings "ARGV" default allows analysts to reproduce executeables. "string" causes args to cat -> single string/space/char. Allows grep but no telling if space chars in resulted string as seperator or individual args in cmd:l

    execve-argv = [ "array" ]:

    // execve-argv = [ "array", "string" ] trim long EXECVE.ARGV and EXECVE.ARGV_STR entry. Cut from middle args list and mark indicator of how many args/bytes to cut/insert execve-argv-limit-bytes = 10000

    [translate]:

    // perf translation of numv done by auditd if config with log_format=ENRICH, arch, syscall, sockaddr struct

    universal = false

    // UID, GID vals

    user-db = false

    [enrich]:

    // + contxt, event-id, comms, exe, ppid for pid entry

    pid = true

break;env.lst\var\log\EXECVE_EVENT -execve-env = ["LD_PRELOAD","LD_LIB_PATH"]:
// + container context -> SYSCALL-based event container = true | + script context ->SYSCALL execve event script = true
    container = true
    script = true

    // Deprecated. Use pid instead. parent-info = false

    [label-process]:
    // audit record contain keys resuseable label attachment to proc. usefull for comb audit rule        
    -w <path> -p x -k <key>
    -w /usr/bin/dpkg -p x -k software_mgmt
    label-keys = [ "software_mgmt" ]:
    // label attachment rm proc run prog. fs/file/path_SYSCALL.exe | /proc/pid/exe | match regex for prog with no ID --> auditd-fs-match 
    -w <path> -p
        x -k <key>
            label-exe.'^/opt/.*/bin/java$' = 'java'
            label-exe.'^/usr/lib/jvm/.*/bin/java$' = 'java'
            label-exe.'^/snap/amazon-ssm-agent/\d+/' = 'amazon-ssm-agent'
unlabel-exe."bin/php$" = "java"
break;
// label attachment rm from proc id script
label-script."maint" = "^/root/maint-.*[.]sh$"
    unlabel-script-"maint" = "…"
        // proc label propagate spawn child proc. use for marks in entire subtrees of children that spawn with certain context, sys man, tool, container, .dll, ssh server, cron

propagate-labels = [ "software_mgmt", "amazon-ssm-agent" ]:

    [filter]://audit record attachment key generator LAUREL, discard

        filter-keys = ["filter-this"]: // + key based filter. config label filter. filter, parent subprocess
        filter-labels = ["software_mgmt"]: // event without key
        filter-null-keys = false break;
// db storage default in end-user sys.dat dir
linux/mac: ~/.local/share/atuin/history.db
windows: %USERPROFILE%/.local/share/atuin/history.db
db_path = "~/.history.db"
// crypto key storage default sys.dat dir
linux/mac: ~/.local/share/atuin/key
windows: %USERPROFILE%/.local/share/atuin/key
key_path = "~/.local/share/atuin/key"
// 0auth session token storage, default sys.dat dir
linux/mac: ~/.local/share/atuin/session
windows: %USERPROFILE%/.local/share/atuin/session
    #session_path = "~/.session"
        // date format used, either "us" or "uk"
dialect = "uk"

// enable or disable automatic sync
auto_sync = false

// enable or disable automatic update checks
update_check = true

// address of the sync server
sync_address = "0.0.0.0"

    // sync history only trigger when cmd is ran. sync interval set 0 after cmd
sync_frequency = "999999999999999h"

// search mode val: prefix, fulltext, fuzzy, skim
search_mode = "fuzzy"

// filter mode val: global, host, session, dir
filter_mode = "host"

// filter mode: atuin, invoke, sh, up-key, bind and accept val id "filter_mode" leave none with same mode set
filter_mode_shell_up_key_binding = "global"

    # val: auto, full, compact
style = "compact"

// max numb:l uif set 0 full screen
# inline_height = 0

// enable or disable showing preview of selected cmd use for cmd terminal width is cut
# show_preview = false

// esc key is pressed 
values: return-original, return-query
    # exit_mode = "return-original"
values: emacs, subl
    word_jump_mode = "emacs"
// characters that count as a part of a word
word_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
//number of context lines to show when scrolling by pages
scroll_context_lines = 1
    break;
// use ctrl instead of alt as the shortcut modifier key for numerical UI shortcuts
alt-0 .. alt-9
    ctrl_n_shortcuts = false

// cmd matches regex. use code to prevent write to log. regex is unanchored. does not start with ^ or end with $. So match anywhere in cmd. regex syntax
# https://docs.rs/regex/latest/regex/#syntax
history_filter = ["^secret-cmd", "^innocuous-cmd .*--secret=.+"];break

// cmd run with cwd match prevent any regex from write log. regex unanchored matches anywhere in CWD. regex syntax
# https://docs.rs/regex/latest/regex/#syntax
# cwd_filter = ["^/very/secret/area"];

#eof

# Write log files relative to this directory
directory = "/var/log/laurel"
# Drop privileges from root to this user
user = "_laurel"
# The periodical time window in seconds for status information to be printed to Syslog.
# Status report includes the running version, config and parsing stats.
# Default is 0 --> no status reports.
statusreport-period = 0
# By default, audit events are read from stdin ("stdin"). Alternatively, they
# can be consumed from an existing UNIX domain socket ("unix:/path/to/socket")
input = "stdin"

[auditlog]
# Base file name for the JSONL-based log file. Set to "-" to log to stdout. In this case 
# other log file related settings will be ignored.
file = "audit.log"
# Rotate when log file reaches this size (in bytes)
size = 5000000
# When rotating, keep this number of generations around
generations = 10
# Grant read permissions on the log files to these users, using
# POSIX ACLs
read-users = [ ]

# Add a prefix to every output line. The CEE cookie can be used to
# instruct consumers to parse the JSON document, cf.
# https://www.rsyslog.com/doc/master/configuration/modules/mmjsonparse.html
# line-prefix = "@cee: "

# [debug]
# dump-state-period = 120

# [debug.log]
# file = "debug.log"
# size = 1000000
# generations = 3

# [debug.parse-error-log]
# file = "parse-error.log"
# size = 1000000
# generations = 3

[transform]

# "array" (the default) causes EXECVE a0, a1, a2 … arguments to be
# output as a list of strings, "ARGV". This is the default, it allows
# analysts to reliably reproduce what was executed.
#
# "string" causes arguments to be concatenated into a single string,
# separated by space characters, "ARGV_STR". This form allows for
# easier grepping, but it is impossible to tell if space characters in
# the resulting string are a separator or were part of an individual
# argument in the original command line.

execve-argv = [ "array" ]

# execve-argv = [ "array", "string" ]

# Trim excessively long EXECVE.ARGV and EXECVE.ARGV_STR entries.
# Excess is cut from the middle of the argument list and a marker
# indicating how many arguments / bytes have been cut is inserted.

# execve-argv-limit-bytes = 10000

[translate]

# Perform translations of numeric values that can also be done by
# auditd if configured with log_format=ENRICHED.

# arch, syscall, sockaddr structures
universal = false
# UID, GID values
user-db = false

[enrich]

# Add context (event-id, comm, exe, ppid) for *pid entries
pid = true

# List of environment variables to log for every EXECVE event
execve-env = [ "LD_PRELOAD", "LD_LIBRARY_PATH" ]

# Add container context to SYSCALL-based events
container = true

# Add script context to SYSCALL execve events
script = true

# Deprecated. Use pid instead.
# parent-info = false

[label-process]

# Audit records that contain certain keys can be reused as a label
# attached to the process.
#
# This is useful in combination with audit rules such as:
# -w <path> -p x -k <key>
# e.g.: -w /usr/bin/dpkg -p x -k software_mgmt
label-keys = [ "software_mgmt" ]

# Labels can be attached to or removed from processes that run certain
# programs. The file program file path (SYSCALL.exe or /proc/pid/exe)
# is matched against regular expressions. This is useful for programs
# that cannot be identified through auditd file watches (-w <path> -p
# x -k <key>).
label-exe.'^/opt/.*/bin/java$' = 'java'
label-exe.'^/usr/lib/jvm/.*/bin/java$' = 'java'
label-exe.'^/snap/amazon-ssm-agent/\d+/' = 'amazon-ssm-agent'

unlabel-exe."bin/php$" = "java"

# Labels can be attached to or removed from processes that have been identified as
# scripts.
label-script."maint" = "^/root/maint-.*[.]sh$"

# unlabel-script-"maint" = "…"

# Process Labels can be propagated to spawned child processes. This is
# useful for marking an entire subtree of children that have been
# spawned within certain contexts (e.g. system management tools,
# container runtimes, ssh servers, cron, etc.).
propagate-labels = [ "software_mgmt", "amazon-ssm-agent" ]

[filter]

# When audit records with attached keys are being generated,
# LAUREL will discard these.

# filter-keys = ["filter-this"]

# In addition to key based filtering it is also possible to configure label based 
# filtering. This alows the possibility to filter based on parent processes.

# filter-labels = ["software_mgmt"]

# Filter events without specified key

filter-null-keys = false

## where to store your database, default is your system data directory
## linux/mac: ~/.local/share/atuin/history.db
## windows: %USERPROFILE%/.local/share/atuin/history.db
# db_path = "~/.history.db"

## where to store your encryption key, default is your system data directory
## linux/mac: ~/.local/share/atuin/key
## windows: %USERPROFILE%/.local/share/atuin/key
key_path = "~/.local/share/atuin/key"

## where to store your auth session token, default is your system data directory
## linux/mac: ~/.local/share/atuin/session
## windows: %USERPROFILE%/.local/share/atuin/session
# session_path = "~/.session"

## date format used, either "us" or "uk"
dialect = "uk"

## enable or disable automatic sync
auto_sync = false

## enable or disable automatic update checks
update_check = true

## address of the sync server
sync_address = "0.0.0.0"

## how often to sync history. note that this is only triggered when a command
## is ran, so sync intervals may well be longer
## set it to 0 to sync after every command
sync_frequency = "999999999999999h"

## which search mode to use
## possible values: prefix, fulltext, fuzzy, skim
# search_mode = "fuzzy"

## which filter mode to use
## possible values: global, host, session, directory
filter_mode = "host"

## which filter mode to use when atuin is invoked from a shell up-key binding
## the accepted values are identical to those of "filter_mode"
## leave unspecified to use same mode set in "filter_mode"
filter_mode_shell_up_key_binding = "global"

## which style to use
## possible values: auto, full, compact
style = "compact"

## the maximum number of lines the interface should take up
## set it to 0 to always go full screen
# inline_height = 0

## enable or disable showing a preview of the selected command
## useful when the command is longer than the terminal width and is cut off
# show_preview = false

## what to do when the escape key is pressed when searching
## possible values: return-original, return-query
# exit_mode = "return-original"

## possible values: emacs, subl
# word_jump_mode = "emacs"

## characters that count as a part of a word
# word_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

## number of context lines to show when scrolling by pages
# scroll_context_lines = 1

## use ctrl instead of alt as the shortcut modifier key for numerical UI shortcuts
## alt-0 .. alt-9
# ctrl_n_shortcuts = false

## prevent commands matching any of these regexes from being written to history.
## Note that these regular expressions are unanchored, i.e. if they don't start
## with ^ or end with $, they'll match anywhere in the command.
## For details on the supported regular expression syntax, see
## https://docs.rs/regex/latest/regex/#syntax
# history_filter = [
#   "^secret-cmd",
#   "^innocuous-cmd .*--secret=.+"
# ]

## prevent commands run with cwd matching any of these regexes from being written
## to history. Note that these regular expressions are unanchored, i.e. if they don't
## start with ^ or end with $, they'll match anywhere in CWD.
## For details on the supported regular expression syntax, see
## https://docs.rs/regex/latest/regex/#syntax
# cwd_filter = [
#   "^/very/secret/area"
# ]

    #eof

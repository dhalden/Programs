
PATH=$PATH:/home/derek/bin

# ~/.bashrc: executed by bash(1) for non-login shells.
# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
# for examples

# If not running interactively, don't do anything
[ -z "$PS1" ] && return

# don't put duplicate lines or lines starting with space in the history.
# See bash(1) for more options
HISTCONTROL=ignoreboth

# append to the history file, don't overwrite it
shopt -s histappend

# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
HISTSIZE=1000
HISTFILESIZE=2000

# check the window size after each command and, if necessary,
# update the values of LINES and COLUMNS.
shopt -s checkwinsize

# If set, the pattern "**" used in a pathname expansion context will
# match all files and zero or more directories and subdirectories.
#shopt -s globstar

# make less more friendly for non-text input files, see lesspipe(1)
[ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"

# set variable identifying the chroot you work in (used in the prompt below)
if [ -z "$debian_chroot" ] && [ -r /etc/debian_chroot ]; then
    debian_chroot=$(cat /etc/debian_chroot)
fi

# set a fancy prompt (non-color, unless we know we "want" color)
case "$TERM" in
    xterm-color) color_prompt=yes;;
esac

# uncomment for a colored prompt, if the terminal has the capability; turned
# off by default to not distract the user: the focus in a terminal window
# should be on the output of commands, not on the prompt
#force_color_prompt=yes

if [ -n "$force_color_prompt" ]; then
    if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then
	# We have color support; assume it's compliant with Ecma-48
	# (ISO/IEC-6429). (Lack of such support is extremely rare, and such
	# a case would tend to support setf rather than setaf.)
	color_prompt=yes
    else
	color_prompt=
    fi
fi

if [ "$color_prompt" = yes ]; then
    PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
else
    PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$ '
fi
unset color_prompt force_color_prompt

# If this is an xterm set the title to user@host:dir
case "$TERM" in
xterm*|rxvt*)
    PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
    ;;
*)
    ;;
esac

# enable color support of ls and also add handy aliases
if [ -x /usr/bin/dircolors ]; then
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
    alias ls='ls --color=auto'
    #alias dir='dir --color=auto'
    #alias vdir='vdir --color=auto'

    alias grep='grep --color=auto'
    alias fgrep='fgrep --color=auto'
    alias egrep='egrep --color=auto'
fi

# some more ls aliases
alias ll='ls -alF'
alias la='ls -A'
alias l='ls -CF'

# Add an "alert" alias for long running commands.  Use like so:
#   sleep 10; alert
alias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echo error)" "$(history|tail -n1|sed -e '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'

# Alias definitions.
# You may want to put all your additions into a separate file like
# ~/.bash_aliases, instead of adding them here directly.
# See /usr/share/doc/bash-doc/examples in the bash-doc package.

if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi

# enable programmable completion features (you don't need to enable
# this, if it's already enabled in /etc/bash.bashrc and /etc/profile
# sources /etc/bash.bashrc).
if [ -f /etc/bash_completion ] && ! shopt -oq posix; then
    . /etc/bash_completion
fi

NONE="\[\033[0m\]"    # unsets color to term's fg color
K="\[\033[0;30m\]"    # black
R="\[\033[0;31m\]"    # red
G="\[\033[0;32m\]"    # green
Y="\[\033[0;33m\]"    # yellow
B="\[\033[0;34m\]"    # blue
M="\[\033[0;35m\]"    # magenta
C="\[\033[0;36m\]"    # cyan
W="\[\033[0;37m\]"    # white
EMK="\[\033[1;30m\]"
EMR="\[\033[1;31m\]"
EMG="\[\033[1;32m\]"
EMY="\[\033[1;33m\]"
EMB="\[\033[1;34m\]"
EMM="\[\033[1;35m\]"
EMC="\[\033[1;36m\]"
EMW="\[\033[1;37m\]"
BGK="\[\033[40m\]"
BGR="\[\033[41m\]"
BGG="\[\033[42m\]"
BGY="\[\033[43m\]"
BGB="\[\033[44m\]"
BGM="\[\033[45m\]"
BGC="\[\033[46m\]"
BGW="\[\033[47m\]"

custom_git_prompt() {
        if ! [ -e .git ]; then return; fi
        local g="$(git rev-parse --git-dir 2>/dev/null)"
        if [ -n "$g" ]; then
                local r
                local b
                if [ -d "$g/../.dotest" ]
                then
                        if test -f "$g/../.dotest/rebasing"
                        then
                                r="|REBASE"
                        elif test -f "$g/../.dotest/applying"
                        then
                                r="|AM"
                        else
                                r="|AM/REBASE"
                        fi
                        b="$(git symbolic-ref HEAD 2>/dev/null)"
                elif [ -f "$g/.dotest-merge/interactive" ]
                then
                        r="|REBASE-i"
                        b="$(cat "$g/.dotest-merge/head-name")"
                elif [ -d "$g/.dotest-merge" ]
                then
                        r="|REBASE-m"
                        b="$(cat "$g/.dotest-merge/head-name")"
                elif [ -f "$g/MERGE_HEAD" ]
                then
                        r="|MERGING"
                        b="$(git symbolic-ref HEAD 2>/dev/null)"
                else
                        if [ -f "$g/BISECT_LOG" ]
                        then
                                r="|BISECTING"
                        fi
                        if ! b="$(git symbolic-ref HEAD 2>/dev/null)"
                        then
                                if ! b="$(git describe --exact-match HEAD 2>/dev/null)"
                                then
                                        b="$(cut -c1-7 "$g/HEAD")..."
                                fi
                        fi
                fi

        local state
        local git_status="$(git status 2> /dev/null)"

        local remote
        local ahead_pattern="# Your branch is ahead of .* by ([0-9]+) commit."
        local behind_pattern="# Your branch is behind .* by ([0-9]+) commit."
        local diverge_pattern="diverged.*and have ([0-9]+) and ([0-9]+) different"
        if [[ ${git_status} =~ ${ahead_pattern} ]]; then
            remote="${M}>${BASH_REMATCH[1]}"
        elif [[ ${git_status} =~ ${behind_pattern} ]]; then
            remote="${Y}<${BASH_REMATCH[1]}"
        elif [[ ${git_status} =~ ${diverge_pattern} ]]; then
            remote="${M}>${BASH_REMATCH[1]}${Y}<${BASH_REMATCH[2]}"
        fi

        if [[ ! ${git_status} =~ "working directory clean" ]]; then
            state="${R}!"
        fi

        echo " $C${b##refs/heads/}$r$remote$state${NONE}"
        fi
}

custom_pwd() {
    echo -ne "\033]0;${USER}@${HOSTNAME}: ${PWD}\007"
    case "$USER" in
    yourusernamegoeshere)
        USERP=""
        ;;
    *)
        USERP="$EMG$USER$NONE:"
        ;;
    esac
    PS1="$R${debian_chroot:+($debian_chroot)}$NONE$USERP$EMB\w$(custom_git_prompt)$NONE\$ "
    PS2=""
}

case "$TERM" in
xterm*|rxvt*)
    PROMPT_COMMAND=custom_pwd
    ;;
*)
    ;;
esac

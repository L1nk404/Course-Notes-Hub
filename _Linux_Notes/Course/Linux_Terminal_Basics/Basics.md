## Índice
- [[#Getting Help in Linux (man, type, help, apropos)]]
	- [[#Searching for keyword]]
	- [[#Nutshell]]
- [[#History]]
- 

## Getting Help in Linux (man, type, help, apropos)
#man #type #help #apropos
`man <file>` command use `less`. Some files don't have `man` because they are **shell builtin**  commands.
To know if a command is shell builtin or a bin we can use `type`:

```bash
➜  ~ type cd  
cd is a shell builtin  
➜  ~ type ls  
ls is an alias for ls --color=tty  
➜  ~ type ifconfig  
ifconfig is /usr/sbin/ifconfig  
➜  ~ type vim        
vim is /usr/bin/vim
```

If the file is shell builtin we use instead the command `help`:

```bash
➜  ~ help cd
```


> [!NOTE] Help in ZSH
> `help`is a command for **bash**, in ZSH we have to configure it before:
```bash
# Source - https://superuser.com/a/1563859
# Posted by glenn jackman, modified by community. See post 'Timeline' for change history
# Retrieved 2026-07-13, License - CC BY-SA 4.0

unalias run-help
autoload run-help
HELPDIR=/usr/share/zsh/"${ZSH_VERSION}"/help
alias help=run-help
```
### Searching for keyword
We can search for keywords in manual using `man -k <keyword`:
```bash
➜  ~ man -k "copy files"  
cp (1)               - copy files and directories  
cpio (1)             - copy files to and from archives  
git-checkout-index (1) - Copy files from the index to the working tree  
gnucp (1)            - copy files and directories  
gnuinstall (1)       - copy files and set attributes
```

This is analog to the `apropos` command:

```bash
➜  ~ apropos uname  
gnuarch (1)          - print machine hardware name (same as uname -m)  
gnuuname (1)         - print system information  
oldolduname (2)      - get name and information about current kernel  
olduname (2)         - get name and information about current kernel  
rust-uname (1)       - Print certain system information. With no OPTION, same as -s.  
uname (1)            - Print certain system information. With no OPTION, same as -s.  
uname (2)            - get name and information about current kernel
```
### Nutshell
```bash
1. ##########################
2. ## Getting Help in Linux
3. ##########################

4. # MAN Pages
5. man command # => Ex: man ls

6. # The man page is displayed with the less command
7. # SHORTCUTS:
8. # h => getting help
9. # q => quit
10. # enter => show next line
11. # space => show next screen
12. # /string => search forward for a string
13. # ?string => search backwards for a string
14. # n / N => next/previous appearance

15. # checking if a command is shell built-in or executable file
16. type rm # => rm is /usr/bin/rm
17. type cd # => cd is a shell builtin

18. # getting help for shell built-in commands
19. help command # => Ex: help cd
20. command --help # => Ex: rm --help

21. # searching for a command, feature or keyword in all man Pages
22. man -k uname
23. man -k "copy files"
24. apropos passwd
```
---
## History
We have two ways to see the terminal history:
1. By the file:
	1. `.zsh_history`
		- We can access it using `cat` or `less`.
	2. `bash_history`
2. Using the command `history`. Let's start 

The file have some variables for settings:
- `$HISTSIZE` - Determine the number of commands that are saved in the file
- `$HISTCONTROL` - Determine when to not save a command on history:
```bash
# On bash
05:46:51 link@Ubuntu26 ~ → echo $HISTCONTROL  
erasedups:ignoreboth
```

To run some command from `history` we can:
-  `!<number>` - run the command  associated with the index number
- `!!` - rerun the last command
-  `!-<number>` - rune the last `<number>` element
- `!<command name>` - run the last `<command name>` in the history - Example `!ping`: run the last command with `ping` 
	- We can also use the shortcut `CTRL + r` (`^r)`  to search for the command on history 

We can also delete commands for history with
- `history -d <number>` - delete the command with the respective index
- `history -c` - clear the entire history

> [!tip] Running command without leave trace in history
> To run a command without leaving trace on history we type the command with a space " " before it: ` pwd`
> Note that only work if $HISTCONTROL=ignorespace



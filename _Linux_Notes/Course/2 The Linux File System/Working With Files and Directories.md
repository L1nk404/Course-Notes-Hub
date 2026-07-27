## Index
- [[#The `ls`command in Depth]]
	- [[#`ls` Cheat Sheet]]
- [[#Understanding File Timestamps `atime`, `mtime`, `ctime` (`stat`, `touch`, `date`)]]
	- [[#Changing File Timestamp]]
	- [[#Manipulating a File's Change Time `ctime`]]
	- [[#The `date` command]]
	- [[#Timestamp Cheat Sheet]]
- [[#File Types in Linux (`ls -F`, `file`)]]
---
## The `ls`command in Depth
![[Pasted image 20260716135147.png]]


> [!NOTE] Special type of files
> Beside `-`, `d` and `l` we have two special types of files:
> - `b`: Is a **block device**. A block device is a type of device file that allows for reading and writing data in fixed-size blocks, typically used for storage devices like hard drives and SSDs. Example: `brw-rw---- 1 root disk 8, 1 Jul 27 14:45 /dev/sda1`
> - `c`: Is a **char device**. in Linux is an abstraction that allows userspace applications to communicate with hardware or kernel subsystems by transmitting data sequentially **byte-by-byte as a continuous stream**. Unlike block devices (like hard drives) which read and write data in fixed-size chunks using caches, character devices provide unbuffered, sequential access. Example: `crw-rw-rw- 1 root root 1, 5 Jul 27 14:45 /dev/zero`
> - `s`:  Is a `socket`. This type of file is used by processes to communicate and has nothing to do with the socket term in TCP/IP. Example: `srw-rw-rw- 1 root root 0 Jul 27 14:45 /run/snapd-snap.socket`

### `ls` Cheat Sheet
```bash
##########################
## The ls Command
## ls [OPTIONS] [FILES]
##########################
  

# listing the current directory
# ~ => user's home directory
# . => current directory
# .. => parent directory
ls
ls .

# listing more directories
ls ~ /var /

# -l => long listing
ls -l ~

# -a => listing all files and directories including hidden ones
ls -la ~

# -1 => listing on a single column
ls -1 /etc

# -d => displaying information about the directory, not about its contents
ls -ld /etc

# -h => displaying the size in human readable format
ls -h /etc

# -S => displaying sorting by size
ls -Sh /var/log

# Note: ls does not display the size of a directory and all its contents. Use du instead
du -sh ~

# -X => displaying sorting by extension
ls -lX /etc

# --hide => hiding some files
ls --hide="*.log" /var/log
# or (source: https://www.baeldung.com/linux/ls-ignore-hide-files)
ls --ignore="*.log" /var/log

# -R => displaying a directory recursively
ls -lR ~

# -i => displaying the inode number
ls -li /etc
```
---
## Understanding File Timestamps: `atime`, `mtime`, `ctime` (`stat`, `touch`, `date`)

Every file on Linux has three timestamps:
1. The **Access** timestamp or `atime` is the last time the file was read (`ls -lu`)
2. The **Modified** timestamp or `mtime` is the last time the contents of the file was modified (`ls -l`, `ls -lt`)
3. The **Change** timestamp `ctime` is the last time when some metadata related to the file was changed (`ls -lc`)

> [!important] Change timestamp
> The Change timestamp refers to change on the **metadata** of the file, such the file permissions or file owner, it's not related to the file content

Linux file timestamps hold an integer number rather than a date and time. This number is the number of seconds since the unique epoch, which was **midnight on January, 1st, 1970 UTC - (00:00, 1/1/1970)**.
When Linux needs to display the date, it translates that number of seconds into a date and time.
To see these timestamps we can use the `ls`command or `stat` to see them all:

![[Pasted image 20260721153504.png]]

> We can use `grc` command to add color to it

To see the entire timestamp with the `ls` command, we use the `--full-time` parameter :

```bash
➜  ~ grc ls --full-time -lu /etc/passwd  
-rw-r--r-- 1 root root 2814 2026-07-21 01:19:19.785000061 +0000 /etc/passwd
```
### Changing File Timestamp
This option is useful when you want a backup program to include or exclude some files or when you simply do not want other users to know that you've read or modified the file.
We can do that using the `touch` command.

> [!info] Note
>  If the file which is the argument of the `touch` command does not exist, it will create it. But if it exists, it will update the file timestamps to the computer's current time.

- **Changing the Access time** - `touch -a <file>`
- **Changing the Modification time** - `touch -m <file>`

To set a specific time we use `-t <year><month><day><hour><minute>.<second>` option. For example:

```bash
# Changing the modification time to 12/30/2018 - 15:30:45
touch -m -t 201812301530.45 linux.txt
```

And if we want to change simultaneously both **access** and **modifitification** time we use the `-d "<year>-<month>-<day> <hour>:<minute>:<second>" <file ` option:

```bash
touch -d "2010-10-31 15:45:30" linux.txt
```

We can also set a timestamp of a reference file to another:

```bash
➜  ~ stat ubuntu.txt    
 File: ubuntu.txt  
 size: 0               Blocks: 0          IO Block: 4096   regular empty file  
Device: 8,2     Inode: 1711295     Links: 1  
Access: (0664/-rw-rw-r--)  Uid: ( 1000/    link)   Gid: ( 1000/    link)  
Access: 2026-07-21 19:00:24.065929149 +0000  
Modify: 2026-07-21 19:00:24.065929149 +0000  
Change: 2026-07-21 19:00:24.065929149 +0000  
Birth: 2026-07-21 19:00:24.065929149 +0000  
➜  ~ stat linux.txt    
 File: linux.txt  
 size: 0               Blocks: 0          IO Block: 4096   regular empty file  
Device: 8,2     Inode: 1710188     Links: 1  
Access: (0664/-rw-rw-r--)  Uid: ( 1000/    link)   Gid: ( 1000/    link)  
Access: 2010-10-10 15:45:30.000000000 +0000  
Modify: 2010-10-10 15:45:30.000000000 +0000  
Change: 2026-07-21 18:59:08.201968522 +0000  
Birth: 2026-07-21 18:47:58.457756170 +0000  
➜  ~ touch linux.txt -r ubuntu.txt              

# ubuntu.txt is the reference file => linux.txt will copy the ubuntu.txt timestamp
➜  ~ stat linux.txt    
 File: linux.txt  
 size: 0               Blocks: 0          IO Block: 4096   regular empty file  
Device: 8,2     Inode: 1710188     Links: 1  
Access: (0664/-rw-rw-r--)  Uid: ( 1000/    link)   Gid: ( 1000/    link)  
Access: 2026-07-21 19:00:24.065929149 +0000  
Modify: 2026-07-21 19:00:24.065929149 +0000  
Change: 2026-07-21 19:00:43.027919308 +0000  
Birth: 2026-07-21 18:47:58.457756170 +0000  
```

### Manipulating a File's Change Time `ctime`

Note that `ctime` cannot be changed by the `touch` command. This happens because the kernel always stamps it with the **current** system time whenever anything on the inode changes.

Since `ctime` always reflects the system's current moment at the time of the change, you can "trick" it by temporarily changing the system clock:

1. **Set the system date/time** to the desired `ctime` value:

```bash
   sudo date -s "2026-07-20 15:30:00"
```

2. **Run `touch`** on the file (this updates `atime`, `mtime`, and `ctime`, all to the date you just set):

```bash
   touch file.txt
```

3. **Restore `atime` and `mtime`** to their original values, using `touch` with specific flags:

```bash
   touch -a -t <original_timestamp> file.txt   # restores access time
   touch -m -t <original_timestamp> file.txt   # restores modification time
```

4. **Set the system date/time back to the real value** (important — don't forget this):

```bash
   sudo date -s "$(date +'%Y-%m-%d %H:%M:%S')"
   # or resync via NTP:
   sudo timedatectl set-ntp true
```

> [!warning] Important
> A subtlety worth noting Since `ctime` only updates when something on the file changes, step 3 (restoring `atime`/`mtime`) will **also bump `ctime` again** — to whatever moment step 3 is actually run. So the order matters: **the final `ctime` will end up being the time at which step 3 was executed**, not the moment of step 2. Make sure the system clock is still set to your desired value when you run step 3, _before_ reverting it back in step 4.
### The `date` command
Shows or sets the system's date and time.
#### Display current date/time

```bash
date              # local timezone
date -u           # UTC (Coordinated Universal Time)
```
#### Custom output format

```bash
date +"%Y-%m-%d %H:%M:%S"     # 2026-07-21 14:32:10
date +"%d/%m/%Y"              # 21/07/2026
date +%s                      # Unix timestamp (seconds since epoch)
```

Common format codes:

|Code|Meaning|
|---|---|
|`%Y`|Year (4 digits)|
|`%y`|Year (2 digits)|
|`%m`|Month (01-12)|
|`%d`|Day (01-31)|
|`%H`|Hour, 24h (00-23)|
|`%M`|Minute|
|`%S`|Second|
|`%s`|Unix timestamp|
|`%A`|Full weekday name|
|`%B`|Full month name|
- **Set the system date/time**

```bash
sudo date -s "2026-07-21 15:30:00"
```

> [!warning] 
> Requires root Setting the system clock needs `sudo`. Also, if a time sync service (like `systemd-timesyncd` or `chrony`) is running, it may override your manual change shortly after.

- **Convert a Unix timestamp to a readable date**

```bash
date -d @1783962827
```

- **Restore time sync after a manual change**

```bash
sudo timedatectl set-ntp true
```

- **Check the manual for accepted date formats**

```bash
man date
```

### Timestamp Cheat Sheet
```bash
1. ##########################
2. ## File Timestamps and Date
3. ##########################

4. # displaying atime
5. ls -lu

6. # displaying mtime
7. ls -l
8. ls -lt

9. # displaying ctime
10. ls -lc

11. # displaying all timestamps
12. stat file.txt

13. # displaying the full timestamp
14. ls -l --full-time /etc/

15. # creating an empty file if it does not exist, update the timestamps if the file exists
16. touch file.txt

17. # changing only the access time to current time
18. touch -a file

19. # changing only the modification time to current time
20. touch -m file

21. # changing the modification time to a specific date and time
22. touch -m -t 201812301530.45 a.txt

23. # changing both atime and mtime to a specific date and time
24. touch -d "2010-10-31 15:45:30" a.txt

25. # changing the timestamp of a.txt to those of b.txt
26. touch a.txt -r b.txt

27. # displaying the date and time
28. date

29. # showing this month's calendar
30. cal

31. # showing the calendar of a specific year
32. cal 2021

33. # showing the calendar of a specific month and year
34. cal 7 2021

35. # showing the calendar of previous, current and next month
36. cal -3

37. # setting the date and time
38. date --set="2 OCT 2020 18:00:00"

39. # displaying the modification time and sorting the output by name.
40. ls -l

41. # displaying the output sorted by modification time, newest files first
42. ls -lt

43. # displaying and sorting by atime
44. ls -ltu

45. # reversing the sorting order
46. ls -ltu --reverse
```

---
## File Types in Linux (`ls -F`, `file`)
Linux determines the type of a file via a code in the file header. It  does not depend in the file extension.
We can use `file` to determine the header of the file that contains their type.

> Note that it can be changed

```bash
➜  ~ file linux.txt  
linux.txt: ASCII text
```

We can also use `ls -F` command:
- No symbol added - Indicates a regular non-executable file: `linux.txt`
- `/` - Indicated a directory: `Documents/`
- `@` - Indicates a symlink:  `os-release@`
- `=` - Indicates a socket: `snapd.socket=`
- `*` - Indicates an executable file: `zstd*`


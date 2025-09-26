/*
====================================================================
=== COURSE/2_linux_administration/lab2_instroduction_to_linux.h ===
====================================================================
*/

/*
============================================================
Introduction to linux
============================================================
Contents:
    -   What is Linux?
    -   Why use Linux?
    -   Linux Distributions
    -   History of Linux
    -   Command Line & Basic Commands
    -   Directory Structure

------------------------------------------------------------
Linux?
------------------------------------------------------------
    Linux has been around since the mid-1990s and has since
        reached a user base that spans the globe.
    Linux is actually everywhere:
        It’s in your phones, your thermostats, in your cars,
        refrigerators, and televisions.
    It also runs most of the Internet, all of the world’s
        top 500 supercomputers, and the world’s stock exchanges.

------------------------------------------------------------
ubuntu:
------------------------------------------------------------
    Just like Windows, iOS, and Mac OS, Linux is an operating system.
    In fact, one of the most popular platforms on the planet,
        Android, is powered by the Linux operating system.
    An operating system is software that manages all of the hardware resources
        associated with your desktop or laptop.
    To put it simply, the operating system manages the communication between
        your software and your hardware.
    Without the operating system (OS), the software wouldn’t function.

------------------------------------------------------------
Why linux?
------------------------------------------------------------
    Linux is considered one of the most stable, secure, and reliable
        operating systems and is widely used in servers, supercomputers,
        and enterprise environments.
    Today, Linux is one of the most widely used operating systems in the world
        because it is open-source.
    Check it OUT!: https://github.com/torvalds/linux



------------------------------------------------------------
Linux os components
------------------------------------------------------------
    -   User Interface
    -   Application Programs
    -   Utilities
    -   Shell
    -   File System
    -   System Library
    -   Kernel
    -   Hardware


------------------------------------------------------------
Linux is open source
------------------------------------------------------------
    -   The freedom to run the program, for any purpose.
    -   The freedom to study how the program works, and change it to make it do what you wish.
    -   The freedom to redistribute copies so you can help your neighbour.
    -   The freedom to distribute copies of your modified versions to others.


------------------------------------------------------------
Linux distributions
------------------------------------------------------------
    -   Ubuntu
    -   Fedora
    -   Arch
    -   Plasma
    -   KDE
    -   Mint
    -   Manjaro

------------------------------------------------------------
Linux distributions
------------------------------------------------------------
    -   Basic: Linux Mint, Ubuntu, Elementary OS or Deepin.
    -   Above-average: Debian or Fedora
    -   Challenging:  Gentoo


------------------------------------------------------------
History of linux
------------------------------------------------------------
    -   1970s: Unix development, Unix was developed as a multi-user,
            multi-tasking operating system and has been widely used in science and research.
    -   1980s: Minix is ​​born, computer science professor Andrew S. Tanenbaum
            created a small Unix-like operating system called Minix. 
    -   1991: 21-year-old student named Linus Torvalds began working on
            a new operating system he named Linux.


------------------------------------------------------------
Linux command Line
------------------------------------------------------------
    -   The Linux command line is a text interface to your computer.
            Often referred to as the shell, terminal, console, prompt,
            or various other names.
    -   Flexible to copy and paste commands
    -   Shell is a program that manages the kernel that manages the drivers
    -   Using the shell the user interfaces with the kernel
    -   Shortcut: {"" CTRL    +   ALT   +   T   ""} to open terminal.


------------------------------------------------------------
Basic terminal commands
------------------------------------------------------------
    -   ls:     Lists a directory’s content
    -   cd:     Changes the working directory
    -   pwd:    Shows the current working directory’s path
    -   mkdir:  Creates a new directory
    -   rmdir:  remove a directory


------------------------------------------------------------
MAN KEYWORD
------------------------------------------------------------
    -   The man command is a built-in manual for using Linux commands.
    -   It allows users to view the reference manuals
            of a command or utility run in the terminal.
    -   The man page (short for manual page) includes a :
            *   command description,
            *   applicable options,
            *   flags,
            *   examples,
            *   and other informative sections.
    -   Examples:
            man ls,
            man pwd, etc…
    -   Press Q to exit the manual



------------------------------------------------------------
cd
------------------------------------------------------------
    -   cd: Change Directory
    -   cd .. : Move up one directory
    -   cd ~  : Move to home directory
    -   cd /  : Move to root directory
    -   cd -  : Move to previous directory

------------------------------------------------------------
ls
------------------------------------------------------------
    *   -l  Lists files and directories in long format, providing detailed information (permissions, owner, size, modification date). 
    *   -a  Includes hidden files and directories in the listing (those starting with a dot). 
    *   -h  Displays file sizes in a human-readable format (kilobytes, megabytes, gigabytes). 
    *   -t  Sort files and directories by their last modification time, displaying the most recently modified ones first.
    *   -r  Reverses the order of the listing, displaying items in reverse alphabetical or chronological order. 
    *   -S Sort files and directories by their sizes, listing the largest ones first.
    *   -R Recursively lists all files and directories within the specified directory and its subdirectories.
    *
    *   --color=auto                Enables colorized output for better visual distinction between file types
    *   --group-directories-first   Lists directories before files in the output.
    *
    *    Examples:
        –   ls: List
        –   ls -l : List in long format
        –   ls -a : List all files including hidden files
        –   ls -la: List all files in long format including hidden files
        –   ls -lh: List in long format with human-readable file sizes
        –   ls -R : List subdirectories recursively






------------------------------------------------------------
Directory Structure in Linux (TREE)
------------------------------------------------------------
                /
                ├── bin:    binary or exxecutable files.
                ├── boot    static files of the boot loader.. It contains all the boot-related
                |               information files and folders such as: conf, grub, initrd.img, vmlinuz, etc.
                ├── dev     device files.. It is the location of the device files such as dev/sda1, dev/sda2, etc.
                ├── etc     system configuration files.
                ├── home    home directory (~) for users, this is the default current directory.
                ├── lib     shared library files.. It contains kernel modules and shared library.
                ├── media   It contains subdirectories where removal media devices are inserted.
                |               such as: cdrom, usb, dvd, etc.
                ├── mnt     It contains temmporary mount directories for mounting the file system
                |               mount point for a temporarily mounted filesystem.
                ├── opt     operational or third-party software.
                ├── proc    virtual filesystem.. its a virtual and pseudo-file system to contain
                |               info about the running processes with a specific ID or PID.
                ├── root
                ├── run     It stores volatile runtime data information since the last boot.
                ├── sbin    Binary executable programs ffor an administrator.
                ├── srv     It contains server-specific and server-related files.
                ├── sys     It is a virtual filesystem for modern linux distributions
                |               to store and allows modification of the devices connected to the system.
                ├── tmp     temporary space. typically cleared on reboot.
                ├── usr     user related programs / libraries.
                ├── var     variable data files / log files (logs).
                |
                └── lost+found    It is used to find revocered bits of corrupted files.

    --------------
    *** NOTES: ***
    --------------
        *   /etc: contains the core configuration files of the system,
                use primarily by the administrator and services,
                such as the password file and networking files.
        *   /usr: source of most of the system programs

    1.  General Files –
            –   It is also called ordinary files.
            –   It may be an image, video, program, or simple text file.
            –   These types of files can be in ASCII or Binary format.
            –   It is the most commonly used file in the Linux system.
    2.  Directory Files –
            –   It may be a directory file within a directory (subdirectory).
    3.  Device Files – 
            –   In a Windows-like operating system, devices like CD-ROM,
                    and hard drives are represented as drive letters like F: G: H
            –   whereas in the Linux system devices are represented as files.
                    As for example, /dev/sda1, /dev/sda2, and so on.
    (4).  Link Files –
            –   It is a special type of file that contains a reference to another file or directory
            –   It is similar to a shortcut in Windows OS.
    (5).  Socket Files –
            –   It is a special type of file that provides inter-process communication.
    (6).  Pipe Files –
            –   It is a special type of file that allows communication between processes.




------------------------------------------------------------
Resources
------------------------------------------------------------
    –   https://www.linux.com/what-is-linux/
    –   https://www.geeksforgeeks.org/linux-history/
    –   https://ubuntu.com/tutorials/command-line-for-beginners#1-overview
    –   https://www.hostinger.com/tutorials/linux-commands
    –   https://contabo.com/blog/linux-navigation-and-file-management/







============================================================
*/
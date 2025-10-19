

/*
===============================================================================
=== COURSE/2_linux_administration/lab5_SystemManagement_and_BashScripting.h ===
===============================================================================
*/


/*#####################################################################################
the source from:
/home/mourad/STUDY/Linux_Embedded_RoboticsCorner/New Sessions/00_Slides/01_Linux_Adminstration/Session 4/Linux_Lec4.pdf
#####################################################################################*/

/*
============================================================
SystemManagement_and_BashScripting
============================================================
Contents:
    • System Information
    • Managing Services
    • Package management
    • Basic shell scripting concepts


------------------------------------------------------------
System information commands
------------------------------------------------------------
    • To know only the system name, you can use the uname command
        without any switch that will print system information or the uname -s
        command will print the kernel name of your system.
    • To view your Linux network hostname, use the ‘-n’ switch with the
        uname command as shown.
        • To get information about the Linux kernel version: uname -v
        • To get the information about your Linux kernel release: uname -r
        • To print your Linux hardware architecture name: uname -m
    • All this information can be printed at once by running the ‘uname -a’ command


------------------------------------------------------------
df/du
------------------------------------------------------------
• The "disk free" (df) command tells you the total disk size, space used,
    space available, usage percentage, and what partition the disk is
    mounted on.
• The "disk usage" (du) is used you need to see the size of a given
    directory or subdirectory. It runs at the object level and only reports
    on the specified stats at the time of execution.


------------------------------------------------------------
Managing services and daemons
------------------------------------------------------------
    • An operating system requires programs that run in the background
        called services. In a Linux system, these services are called daemons.
        They are managed using an init system like systemd.
    • In Unix-based computer operating systems, init (short for
        initialization) is the first process started during booting of the
        operating system. Init is a daemon process that continues running
        until the system is shut down. 


------------------------------------------------------------
Process vs service
------------------------------------------------------------
    • A process is an instance of a running program. When you execute a
        program, it becomes a process.
    • Processes are the basic units of execution in a Linux system.
    • Each process has a unique process ID (PID) assigned to it.
    • Processes have their own memory space, file descriptors, and other
        resources.
    • A service is a background process or daemon that runs on a system to
        provide specific functionality or perform specific tasks.
    • Services often start when the system boots up and continue running
        in the background, waiting for specific events or requests.
    • Services are usually managed by an init system like systemd, which
        can start, stop, restart, and manage their lifecycle, there are others,
        but system is the most used.



------------------------------------------------------------
Managing services and daemons
------------------------------------------------------------
    • Most modern Linux systems use systemd – an init system and service
        manager for controlling daemons. It is a drop-in replacement for
        older distributions’ init processes: pstree  started by systemd
    
    • Systemd has the systemctl command, which lets users manage their
        system and service configurations. For example, use it to list all unit
        files in your Linux server: daemons = units = services
    
    • sudo systemctl list-unit-files --type service --all



------------------------------------------------------------
sudo systemctl list-unit-files --type service --all
------------------------------------------------------------
    • sudo systemctl list-unit-files --type service --all
        - Enabled    – active services running in the background.
        - Disabled   – disabled services that users can enable directly using the start command.
        - Masked     – stopped services that can only be started by removing the masked property.
        - Static     – services that only run when another program or unit requires them.
        - Failed     – inactive services that can’t load or operate properly.



------------------------------------------------------------
Managing services and daemons
------------------------------------------------------------
    • To stop a service: sudo systmctl stop [SERVICE]
    • To get the status of a service: sudo systmctl status [SERVICE]
    • To start a service: sudo systmctl start [SERVICE]
    • To restart a service: sudo systmctl restart [SERVICE]
    


------------------------------------------------------------
Package Management
------------------------------------------------------------
    • When it comes to package management on Linux systems, two
        popular tools are YUM and APT. YUM, short for Yellowdog Updater
        Modified, is commonly used in Red Hat-based distributions like
        CentOS and RHEL. On the other hand, APT, which stands for Advanced
        Packaging Tool, is widely used in Debian, Ubuntu, and their
        derivatives. Understanding the differences between these package
        managers can help you effectively manage software installations and
        updates on your Linux system.







------------------------------------------------------------
YUM vs. APT: Managing Software Packages on Linux
------------------------------------------------------------
• YUM and APT are package managers that simplify the installation,
    upgrade, and configuration of software packages on Linux systems.
    While they serve the same purpose, there are some notable
    differences between them.






------------------------------------------------------------
APT
------------------------------------------------------------
    • APT uses .deb files as the package format and is primarily used in
        Debian, Ubuntu, and related distributions.
    • APT provides several commonly used commands, such as update,
        upgrade, install, remove, purge, list, and search.
    • APT organizes options into functional groups and stores them in the
        /etc/apt/apt.conf file, which is organized in a tree structure.






------------------------------------------------------------
apt
------------------------------------------------------------
    • When you install an application using apt in Ubuntu, the package
        manager (apt) does not contain all the data for the application itself.
        Instead, apt relies on repositories, which are online databases of
        software packages maintained by Ubuntu and its community.
    • When you instruct apt to install a package, it searches the repositories
        configured on your system to find the package and its dependencies. If
        the package and its dependencies are found, apt downloads them
        from the repository over the internet and installs them on your system.
    • The repositories contain metadata about the packages, such as their
        names, versions, descriptions, dependencies, and download locations.
        apt uses this metadata to locate and install the requested packages.
    • So, while apt itself doesn't contain all the data for each application, it
        acts as a tool to efficiently manage the installation and removal of
        software packages from online repositories.



------------------------------------------------------------
yum
------------------------------------------------------------
• YUM uses .rpm files and is commonly used in Red Hat-based
    distributions like CentOS, RHEL, Fedora, and OpenSUSE.
• YUM offers commands like install, remove, search, info, and update.
• YUM allows options to be set with global and repository-specific
    effects, and the configuration is managed in the /etc/yum.conf file






------------------------------------------------------------
Basic shell scripting concepts
------------------------------------------------------------
• Shell is an interpreter for the applications/commands of a user to
    make the kernel manage the hardware.
• It stands for Bourne-Again SHell






------------------------------------------------------------
Types of shell
------------------------------------------------------------

|               Types of shell with varied features                                         |
|----------|--------------------------------------------------------------------------------|
| sh       | the original Boume shell.                                                      |
| ksh      | one of the three: public domain ksh (pdksh), AT&T ksh, or mksh                 |
| bash     | the GNU Bourne-again shell. IIt is mostly Bourne-compatible, mostly POSIX-compatible, and has other useful extensions. It is the default on most Linux systems. |
| csh      | BSD introduced in C shell, which sometimes resembbles slightly the C programming language.  |
| tcsh     | csh with more features. csh and tcsh sheells are NOT Bourne-compatible.        |




------------------------------------------------------------
Shell comparison
------------------------------------------------------------
• Bash supports all because it was created by the linux
    foundation(non-profit organization) --> time and resources are abundant.


|   Software                |   sh  |   csh |   ksh |   bash    |   tcsh    |
|---------------------------|-------|-------|-------|-----------|-----------|
| Shell variables           |   y   |   y   |   y   |   y       |   y       |
| Command alias             |   y   |   y   |   y   |   y       |   y       |
| Command history           |   n   |   y   |   y   |   y       |   y       |
| Filename autocompletion   |   n   |   y*  |   y*  |   y       |   y       |
| Command line editing      |   n   |   n   |   y*  |   y       |   y       |
| Job control               |   n   |   y   |   y   |   y       |   y       |


{   *: not by default   }



------------------------------------------------------------
What can you do with a shell
------------------------------------------------------------
    • File Management, Directory Management
    • Process Management, compile and run applications
    • Network Management
    • Shell Scripting
    • List available shells on the system: 
        cat /etc/shells
    • To check the current shell you are using: 
        echo $0 or echo $SHELL






------------------------------------------------------------
Shell scripting
------------------------------------------------------------
    • Script: a program written for a software environment to automate
        execution of tasks
    • A series of shell commands put together in a file
    • When the script is executed, those commands will be executed one
        line at a time automatically
    • Shell script is interpreted, not compiled.


------------------------------------------------------------
When not to use shell scripting
------------------------------------------------------------
    • Performance/Security-Critical Applications
    • Complex Data Structures and Algorithms
    • Cross-Platform Development
    • Large Software Projects




------------------------------------------------------------
Example: Hello Script
------------------------------------------------------------
```bash
#!/bin/bash
# Asctipt example
echo "Hello World!" # print something.
```



------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------







------------------------------------------------------------

------------------------------------------------------------








============================================================
*/
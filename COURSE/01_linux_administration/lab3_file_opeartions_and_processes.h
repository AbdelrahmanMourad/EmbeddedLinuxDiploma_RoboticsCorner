

/*
==========================================================================
=== COURSE/2_linux_administration/lab3_file_operations_and_processes.h ===
==========================================================================
*/

/*
============================================================
File Operations and Processes
============================================================
Contents:
    • Working with files (touch, cp, mv, rm)
    • File archiving and compression (tar, gzip)
    • Text editors in Linux (nano, vim)
    • Basic text manipulation (grep, cat, less)
    • Processes and process management (ps, top, kill)
    • Running and managing background processes
    • Redirecting input and output (>, >>, <, |)

------------------------------------------------------------
WORKING WITH FILES
------------------------------------------------------------
    • cp:       to make a copy of a file or copy file to another location
    • touch:    create an empty file
    • mv:       To move a file from one location to the other, or to rename it
    • rm:       delete a file permanently
    • find:     to find a file

------------------------------------------------------------
FILE ARCHIVING AND COMPRESSION
------------------------------------------------------------
    • To compress a file in Linux: tar -zcvf file.tar.gz [PATH]
    • ex: 
        "tar -zcvf file.tar.gz file.cpp"
            • -c:   Create a new archive.
            • -z:   Compress the archive using gzip.
            • -v:   Verbose mode (optional, shows the progress).
            • -f:   Specifies the archive file name.


------------------------------------------------------------
EXCLUDE DIRECTORIES AND FILES
------------------------------------------------------------
    • Compress files but excluding files: 
        tar -zcvf archive.tar.gz --exclude=’[DIRECTORY]’

    • Compress files but excluding directories: 
        tar -czvf /nfs/backup.tar.gz --exclude=" DIRECTORY " /home/vivek/


------------------------------------------------------------
EXTRACT A FILE
------------------------------------------------------------
    • tar -xzvf file.tar.gz
    • tar -xjvf file.tar.bz2
    • extract the contents of the archive into a specific directory: 
        tar -xzvf my.tar.gz -C [DIRECTORY]
    • tar -xjvf archive.tar.bz2 -C [DIRECTORY]
        • -x : Extract files from an archive
        • -t : List the contents of an archive
        • -v : Verbose output
        • -f file.tar.gz : Use archive file
        • -C DIR : Change to DIR before performing any operations
        • --exclude : Exclude files matching PATTERN/DIR/FILENAME

------------------------------------------------------------
TEXT EDITORS IN LINUX
------------------------------------------------------------
    • Text Editor: nano
    • If you already have a txt file: 
        nano _text_file_name.txt
    • Shortcuts:
        • {CRTL + O} ==>    to save
        • {CTRL + X} ==>    to exit
        • {ALT  + U} ==>    Undo
        • {ALT  + E} ==>    Redo

------------------------------------------------------------
NANO
------------------------------------------------------------
    –   ls: List
    –   ls -l : List in long format
    –   ls -a : List all files including hidden files
    –   ls -la: List all files in long format including hidden files
    –   ls -lh: List in long format with human-readable file sizes




------------------------------------------------------------

------------------------------------------------------------
    –   ls: List
    –   ls -l : List in long format
    –   ls -a : List all files including hidden files
    –   ls -la: List all files in long format including hidden files
    –   ls -lh: List in long format with human-readable file sizes





------------------------------------------------------------

------------------------------------------------------------
    –   ls: List
    –   ls -l : List in long format
    –   ls -a : List all files including hidden files
    –   ls -la: List all files in long format including hidden files
    –   ls -lh: List in long format with human-readable file sizes





------------------------------------------------------------

------------------------------------------------------------
    –   ls: List
    –   ls -l : List in long format
    –   ls -a : List all files including hidden files
    –   ls -la: List all files in long format including hidden files
    –   ls -lh: List in long format with human-readable file sizes





------------------------------------------------------------

------------------------------------------------------------
    –   ls: List
    –   ls -l : List in long format
    –   ls -a : List all files including hidden files
    –   ls -la: List all files in long format including hidden files
    –   ls -lh: List in long format with human-readable file sizes





------------------------------------------------------------

------------------------------------------------------------
    –   ls: List
    –   ls -l : List in long format
    –   ls -a : List all files including hidden files
    –   ls -la: List all files in long format including hidden files
    –   ls -lh: List in long format with human-readable file sizes






------------------------------------------------------------

------------------------------------------------------------
    –   ls: List
    –   ls -l : List in long format
    –   ls -a : List all files including hidden files
    –   ls -la: List all files in long format including hidden files
    –   ls -lh: List in long format with human-readable file sizes




------------------------------------------------------------

------------------------------------------------------------
    –   ls: List
    –   ls -l : List in long format
    –   ls -a : List all files including hidden files
    –   ls -la: List all files in long format including hidden files
    –   ls -lh: List in long format with human-readable file sizes









============================================================
*/
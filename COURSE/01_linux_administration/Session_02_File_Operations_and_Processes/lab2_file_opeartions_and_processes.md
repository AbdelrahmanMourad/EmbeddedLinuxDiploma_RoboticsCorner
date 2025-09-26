# Linux File Operations and Processes - Lab 3 Guide

[![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)](https://www.linux.org/)
[![Bash](https://img.shields.io/badge/bash-%23121011.svg?style=for-the-badge&logo=gnu-bash&logoColor=white)](https://www.gnu.org/software/bash/)

> **Lab 3**: Comprehensive guide to Linux file operations, text manipulation, and process management for embedded systems engineers and Linux administrators.

## 📋 Table of Contents

- [File Operations](#-file-operations)
- [File Archiving and Compression](#-file-archiving-and-compression)
- [Text Editors](#-text-editors)
- [Text Manipulation Commands](#-text-manipulation-commands)
- [Process Management](#-process-management)
- [Background Processes](#-background-processes)
- [Input/Output Redirection](#-inputoutput-redirection)
- [Practical Examples](#-practical-examples)
- [References](#-references)

---

## 🗂️ File Operations

Essential commands for file manipulation in Linux systems.

### Basic File Commands

| Command | Description | Syntax |
|---------|-------------|--------|
| `touch` | Create empty file or update timestamp | `touch filename` |
| `cp` | Copy files or directories | `cp source destination` |
| `mv` | Move/rename files | `mv source destination` |
| `rm` | Delete files permanently | `rm filename` |
| `find` | Search for files and directories | `find path -name pattern` |

### Examples

```bash
# Create a new empty file
touch myfile.txt

# Create multiple files
touch file1.txt file2.txt file3.txt

# Copy a file
cp myfile.txt backup_myfile.txt

# Copy with verbose output
cp -v myfile.txt /tmp/
```

**Expected Output:**
```
'myfile.txt' -> '/tmp/myfile.txt'
```

```bash
# Move/rename a file
mv myfile.txt renamed_file.txt

# Move file to directory
mv renamed_file.txt /home/user/documents/

# Remove files (be careful!)
rm file1.txt

# Remove with confirmation
rm -i file2.txt
```

**Expected Output:**
```
rm: remove regular empty file 'file2.txt'? y
```

### Advanced File Operations

```bash
# Find files by name
find . -name "*.txt"

# Find files modified in last 7 days
find . -type f -mtime -7

# Find and execute command on results
find . -name "*.log" -exec rm {} \;
```

---

## 📦 File Archiving and Compression

Learn to compress and extract files efficiently.

### TAR Command Options

| Option | Description |
|--------|-------------|
| `-c` | Create a new archive |
| `-x` | Extract files from archive |
| `-v` | Verbose mode (show progress) |
| `-f` | Specify archive filename |
| `-z` | Compress with gzip |
| `-j` | Compress with bzip2 |
| `-t` | List archive contents |

### Creating Archives

```bash
# Create a gzip compressed tar archive
tar -zcvf myarchive.tar.gz /path/to/files

# Example: Compress current directory
tar -zcvf project_backup.tar.gz .

# Create archive excluding specific directories
tar -zcvf backup.tar.gz --exclude='node_modules' --exclude='.git' /home/user/project
```

**Expected Output:**
```
./
./file1.txt
./file2.txt
./subdirectory/
./subdirectory/file3.txt
```

### Extracting Archives

```bash
# Extract gzip tar archive
tar -xzvf myarchive.tar.gz

# Extract to specific directory
tar -xzvf myarchive.tar.gz -C /destination/path

# Extract bzip2 archive
tar -xjvf archive.tar.bz2

# List archive contents without extracting
tar -tzvf myarchive.tar.gz
```

### Compression Comparison

| Format | Command | Compression Ratio | Speed |
|--------|---------|------------------|-------|
| `.tar.gz` | `tar -zcvf` | Good | Fast |
| `.tar.bz2` | `tar -jcvf` | Better | Slower |
| `.tar.xz` | `tar -Jcvf` | Best | Slowest |

---

## ✏️ Text Editors

Master Linux text editors for configuration and development.

### Editor Comparison

| Feature | Nano | Vi/Vim | Emacs |
|---------|------|--------|-------|
| **Learning Curve** | Easy | Moderate | Hard |
| **User Interface** | Simple and intuitive | Modal, command-based | Extensible, complex |
| **Extensibility** | Limited | Yes (Vimscript) | Yes (Emacs Lisp) |
| **Availability** | Universal | Universal | May need installation |
| **Memory Usage** | Low | Low | High |
| **Best For** | Quick edits | Programming | IDE replacement |

### Nano Editor

#### Basic Usage

```bash
# Open existing file
nano myfile.txt

# Create new file
nano newfile.txt
```

#### Nano Command Line Options

| Flag | Description | Example |
|------|-------------|---------|
| `-B` | Backup before saving | `nano -B myfile.txt` |
| `-I` | Auto-indent | `nano -I myfile.txt` |
| `-N` | No DOS/Mac conversion | `nano -N myfile.txt` |
| `-T 4` | Set tab size to 4 spaces | `nano -T 4 myfile.txt` |
| `-U` | Enable undo | `nano -U myfile.txt` |
| `-Y sh` | Syntax highlighting | `nano -Y sh script.sh` |
| `-c` | Show cursor position | `nano -c myfile.txt` |
| `-m` | Enable mouse support | `nano -m myfile.txt` |

#### Nano Keyboard Shortcuts

| Shortcut | Function |
|----------|----------|
| `Ctrl + O` | Save file |
| `Ctrl + X` | Exit editor |
| `Ctrl + K` | Cut line |
| `Ctrl + U` | Paste |
| `Ctrl + W` | Search |
| `Alt + U` | Undo |
| `Alt + E` | Redo |
| `Ctrl + G` | Help |

### Vi/Vim Editor

```bash
# Open file in vi
vi myfile.txt

# Basic vi workflow example
# 1. Press 'i' to enter insert mode
# 2. Type your content
# 3. Press 'Esc' to exit insert mode
# 4. Type ':wq' to save and quit
```

**Vi Commands:**
- `i` - Insert mode
- `Esc` - Command mode
- `:w` - Save
- `:q` - Quit
- `:wq` - Save and quit
- `:q!` - Quit without saving

---

## 🔍 Text Manipulation Commands

Essential tools for processing text files and command output.

### GREP - Global Regular Expression Print

```bash
# Basic grep syntax
grep "pattern" filename

# Case-insensitive search
grep -i "error" logfile.txt

# Count matching lines
grep -c "warning" logfile.txt

# Show line numbers
grep -n "TODO" source.c

# Search in multiple files
grep -r "function" *.c
```

#### GREP Options

| Option | Description | Example |
|--------|-------------|---------|
| `-c` | Count matching lines | `grep -c "error" log.txt` |
| `-h` | Hide filename in output | `grep -h "pattern" *.txt` |
| `-i` | Case-insensitive | `grep -i "Error" file.txt` |
| `-l` | List filenames only | `grep -l "main" *.c` |
| `-n` | Show line numbers | `grep -n "bug" code.c` |
| `-v` | Invert match (non-matching) | `grep -v "comment" file.txt` |
| `-w` | Match whole words | `grep -w "cat" file.txt` |
| `-r` | Recursive search | `grep -r "TODO" /project` |

```bash
# Practical grep examples
# Find all Python files containing 'import'
grep -r --include="*.py" "import" .

# Find processes containing 'apache'
ps aux | grep apache

# Search for IP addresses in log files
grep -E '\b[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\b' access.log
```

### File Content Viewers

#### CAT Command

```bash
# Display file contents
cat filename.txt

# Display with line numbers
cat -n filename.txt

# Concatenate multiple files
cat file1.txt file2.txt > combined.txt
```

#### LESS Command

```bash
# View large files page by page
less filename.txt

# Navigation in less:
# 'g' - go to beginning
# 'G' - go to end  
# 'q' - quit
# '/' - search forward
# '?' - search backward
```

#### HEAD and TAIL Commands

```bash
# Show first 10 lines (default)
head filename.txt

# Show first 20 lines
head -n 20 filename.txt

# Show last 10 lines
tail filename.txt

# Follow file in real-time (great for logs)
tail -f /var/log/syslog

# Show last 50 lines and follow
tail -n 50 -f application.log
```

---

## ⚙️ Process Management

Understanding and controlling system processes.

### Process Concepts

A **process** is an instance of a running program. Key attributes:
- **PID**: Process ID (unique identifier)
- **PPID**: Parent Process ID
- **TTY**: Terminal associated with process
- **CPU Time**: Processing time used
- **Memory**: RAM usage

### PS Command

```bash
# Show processes for current user
ps

# Show all processes
ps aux

# Show process tree
ps -ef --forest

# Show specific process
ps -p 1234

# Custom format
ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%cpu
```

**Expected Output:**
```bash
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root           1  0.0  0.1  168544  12896 ?       Ss   10:30   0:02 /sbin/init
root           2  0.0  0.0      0      0 ?        S    10:30   0:00 [kthreadd]
```

### TOP Command

```bash
# Real-time process monitor
top

# Sort by memory usage
top -o %MEM

# Show specific user processes
top -u username

# Batch mode (non-interactive)
top -b -n 1
```

### Process Control

```bash
# Kill process by PID
kill 1234

# Force kill process
kill -9 1234

# Kill process by name
killall firefox

# Send specific signal
kill -TERM 1234

# List all signals
kill -l
```

#### Signal Types

| Signal | Number | Description |
|--------|---------|-------------|
| SIGTERM | 15 | Graceful termination (default) |
| SIGKILL | 9 | Force kill (cannot be ignored) |
| SIGSTOP | 19 | Pause process |
| SIGCONT | 18 | Resume process |
| SIGHUP | 1 | Hangup (often reload config) |

---

## 🔄 Background Processes

Managing processes that run in the background.

### Job Control

```bash
# Run command in background
sleep 100 &

# List active jobs
jobs

# Bring job to foreground
fg %1

# Send job to background
bg %1

# Detailed job status
jobs -l
```

**Example Session:**
```bash
$ sleep 50 &
[1] 12345

$ sleep 70 &
[2] 12346

$ jobs
[1]-  Running                 sleep 50 &
[2]+  Running                 sleep 70 &

$ fg %1
sleep 50
^Z
[1]+  Stopped                 sleep 50

$ bg %1
[1]+ sleep 50 &
```

### Nohup Command

```bash
# Run process immune to hangups
nohup long_running_script.sh &

# Output goes to nohup.out by default
nohup python3 server.py > server.log 2>&1 &
```

---

## 📊 Input/Output Redirection

Control where command input comes from and output goes to.

### Redirection Operators

| Operator | Description | Example |
|----------|-------------|---------|
| `>` | Redirect stdout (overwrite) | `ls > files.txt` |
| `>>` | Redirect stdout (append) | `echo "new" >> log.txt` |
| `<` | Redirect stdin | `mail user < message.txt` |
| `2>` | Redirect stderr | `command 2> errors.txt` |
| `2>&1` | Redirect stderr to stdout | `command > output.txt 2>&1` |
| `|` | Pipe output to another command | `ls | grep ".txt"` |

### Practical Examples

```bash
# Save directory listing to file
ls -la > directory_contents.txt

# Append date to log file
date >> system.log

# Count lines in file
wc -l < data.txt

# Redirect both stdout and stderr
find /etc -name "*.conf" > found.txt 2> errors.txt

# Combine outputs
find /etc -name "*.conf" > all_output.txt 2>&1
```

### Pipe Operations

```bash
# Chain commands with pipes
ps aux | grep python | wc -l

# Complex pipeline example
cat access.log | grep "404" | awk '{print $1}' | sort | uniq -c | sort -nr

# Process CSV data
cat data.csv | cut -d',' -f2 | sort | uniq

# Monitor system in real-time
tail -f /var/log/syslog | grep -i error
```

---

## 💡 Practical Examples

### System Monitoring Script

```bash
#!/bin/bash
# System monitoring example

echo "=== System Status Report ==="
echo "Date: $(date)"
echo ""

echo "=== Top 5 CPU Processes ==="
ps aux --sort=-%cpu | head -6

echo ""
echo "=== Disk Usage ==="
df -h

echo ""
echo "=== Memory Usage ==="
free -h

echo ""
echo "=== Active Network Connections ==="
netstat -tuln | head -10
```

### Log Analysis Example

```bash
# Analyze web server logs
# Count requests per IP
awk '{print $1}' access.log | sort | uniq -c | sort -nr | head -10

# Find 404 errors
grep " 404 " access.log | wc -l

# Extract unique user agents
awk -F'"' '{print $6}' access.log | sort | uniq
```

### Backup Script

```bash
#!/bin/bash
# Automated backup script

BACKUP_DIR="/backup"
SOURCE_DIR="/home/user/important"
DATE=$(date +%Y%m%d_%H%M%S)

# Create compressed backup
tar -zcvf "${BACKUP_DIR}/backup_${DATE}.tar.gz" "$SOURCE_DIR"

# Keep only last 7 backups
find "$BACKUP_DIR" -name "backup_*.tar.gz" -mtime +7 -delete

echo "Backup completed: backup_${DATE}.tar.gz"
```

### File Comparison Workflow

```bash
# Create test files
echo "Line 1\nLine 2\nLine 3" > file1.txt
echo "Line 1\nLine 2 modified\nLine 3\nLine 4" > file2.txt

# Compare files
diff file1.txt file2.txt

# Side-by-side comparison
diff -y file1.txt file2.txt

# Unified format
diff -u file1.txt file2.txt
```

**Expected Output:**
```
2c2
< Line 2
---
> Line 2 modified
3a4
> Line 4
```

---

## 📈 Performance Monitoring

### Word Count and File Statistics

```bash
# Word count examples
wc filename.txt          # Lines, words, characters
wc -l filename.txt       # Lines only  
wc -w filename.txt       # Words only
wc -c filename.txt       # Characters only

# Process multiple files
wc *.txt

# Count files in directory
ls | wc -l

# Count running processes
ps aux | wc -l
```

### System Resource Usage

```bash
# Monitor CPU usage
top -b -n1 | grep "Cpu(s)" | awk '{print $2 + $4}'

# Check memory usage
free -m | awk 'NR==2{printf "Memory Usage: %s/%sMB (%.2f%%)\n", $3,$2,$3*100/$2 }'

# Disk I/O statistics
iostat -x 1 1

# Network statistics  
sar -n DEV 1 1
```

---

## 🎯 Best Practices

### File Operations
- Always use `-i` flag with `rm` for important files
- Create backups before major file operations
- Use relative paths when possible
- Implement proper error handling in scripts

### Process Management
- Use `killall` instead of `kill` when targeting multiple processes
- Always try SIGTERM before SIGKILL
- Monitor system resources regularly
- Use `nohup` for long-running background processes

### Text Processing
- Use appropriate tools: `grep` for searching, `awk` for field processing
- Combine commands with pipes for complex operations
- Test regex patterns before using in production
- Consider file sizes when choosing between `cat`, `less`, or `head/tail`

---

## 🔗 References

### Official Documentation
- [Linux Man Pages Online](https://man7.org/linux/man-pages/)
- [GNU Coreutils Manual](https://www.gnu.org/software/coreutils/manual/)
- [Bash Reference Manual](https://www.gnu.org/software/bash/manual/)

### Additional Resources
- [All Hands On Tech - Linux Commands](https://www.allhandsontech.com/linux/linux-commands-files/)
- [Cyberciti - TAR Command Guide](https://www.cyberciti.biz/faq/how-to-tar-a-file-in-linux-using-command-line/)
- [IOFlood - Nano Command Guide](https://ioflood.com/blog/nano-linux-command/)
- [Baeldung - Head/Tail Commands](https://www.baeldung.com/linux/head-tail-commands)

### Quick Reference Cards
- [Linux Command Cheat Sheet](https://www.linuxtrainingacademy.com/linux-commands-cheat-sheet/)
- [Vim Cheat Sheet](https://vim.rtorr.com/)
- [Regular Expressions Quick Reference](https://www.regular-expressions.info/quickstart.html)

---

## 📝 Lab Exercises

1. **File Operations Practice**
   - Create a directory structure for a project
   - Practice copying and moving files
   - Create and extract tar archives

2. **Process Management**
   - Monitor system processes with `top` and `ps`
   - Practice job control with background processes
   - Kill unresponsive processes safely

3. **Text Processing**
   - Use `grep` to search through log files
   - Create scripts using pipes and redirection
   - Compare file versions with `diff`

4. **Advanced Tasks**
   - Write a system monitoring script
   - Create an automated backup solution
   - Parse and analyze log files

---

*This guide is designed for embedded Linux engineers and system administrators. Practice these commands in a safe environment before using in production systems.*
# Bash Task Manager - Mini Project Guide

[![Bash](https://img.shields.io/badge/bash-%23121011.svg?style=for-the-badge&logo=gnu-bash&logoColor=white)](https://www.gnu.org/software/bash/)
[![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)](https://www.linux.org/)
[![License](https://img.shields.io/badge/License-MIT-blue.svg?style=for-the-badge)](LICENSE)

> **Mini-Project**: Build a complete task management system using Bash scripting with file operations, text processing, and user interaction.

## 🎯 Table of Contents

- [Project Overview](#-project-overview)
- [Features](#-features)
- [Installation](#-installation)
- [Usage Guide](#-usage-guide)
- [Core Functions](#-core-functions)
- [Advanced Features](#-advanced-features)
- [Code Examples](#-code-examples)
- [Troubleshooting](#-troubleshooting)
- [Learning Objectives](#-learning-objectives)

---

## 📋 Project Overview

### What We're Building

A **command-line task manager** that allows users to:
- ➕ Add tasks with descriptions and priorities
- 📋 View tasks in a formatted table
- 🗑️ Delete specific tasks
- ✅ Mark tasks as completed
- 🔍 Search tasks by keywords
- 📊 Export tasks to CSV format

### System Requirements

| Requirement | Version | Notes |
|-------------|---------|-------|
| **Bash** | 4.0+ | Script compatibility |
| **Linux/Unix** | Any | macOS, Ubuntu, CentOS, etc. |
| **Commands** | `awk`, `sed`, `grep` | Usually pre-installed |
| **Disk Space** | < 1MB | Lightweight application |

### Architecture Overview

```
┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐
│   User Input    │───▶│  Bash Script    │───▶│   Text File     │
│  (Terminal UI)  │    │  (Logic Layer)  │    │ (Data Storage)  │
└─────────────────┘    └─────────────────┘    └─────────────────┘
```

---

## ✨ Features

### Core Functionality

| Feature | Description | Commands Used |
|---------|-------------|---------------|
| **Add Task** | Create new tasks with priority levels | `echo`, `read`, `>>` |
| **View Tasks** | Display formatted task list | `awk`, `printf` |
| **Delete Task** | Remove tasks by number | `sed -i`, `-d` |
| **Mark Complete** | Update task status | `awk`, field assignment |
| **Search** | Find tasks by keyword | `grep`, pattern matching |

### Advanced Features

- 🎨 **Color-coded output** for better readability
- 🛡️ **Automatic backups** before modifications
- ✅ **Input validation** and error handling
- 📊 **Task statistics** and summaries
- 📤 **CSV export** functionality
- ⏰ **Timestamps** for creation and completion

---

## 🚀 Installation

### Quick Start

```bash
# Clone or download the script
curl -O https://raw.githubusercontent.com/your-repo/task_manager.sh

# Make executable
chmod +x task_manager.sh

# Run the application
./task_manager.sh
```

### Manual Setup

```bash
# Create the script file
nano task_manager.sh

# Copy the complete script (provided above)
# Save and make executable
chmod +x task_manager.sh

# Optional: Create symbolic link for system-wide access
sudo ln -s /path/to/task_manager.sh /usr/local/bin/taskman
```

---

## 📖 Usage Guide

### Starting the Application

```bash
# Run the task manager
./task_manager.sh
```

**Expected Output:**
```
╔════════════════════════════════════════╗
║           TASK MANAGER v2.0            ║
║         Bash Mini-Project              ║
╚════════════════════════════════════════╝

┌─────────────────────────────┐
│         MAIN MENU           │
├─────────────────────────────┤
│ 1. Add Task                 │
│ 2. View Tasks               │
│ 3. Delete Task              │
│ 4. Mark Task as Completed   │
│ 5. Search Tasks             │
│ 6. Export Tasks             │
│ 7. Help                     │
│ 8. Exit                     │
└─────────────────────────────┘

Enter your choice (1-8): 
```

### Basic Operations

#### 1. Adding a Task

```bash
# User interaction flow
=== Add New Task ===
Enter task description (or 'cancel' to abort): Fix login bug
Select priority level:
1) High
2) Medium
3) Low
Choose (1-3, default 2): 1

✅ Task added successfully!
   Description: Fix login bug
   Priority: High
   Added: 2024-01-15 14:30
```

#### 2. Viewing Tasks

```bash
=== Task List ===
┌─────┬────────────────────────────────┬────────────┬──────────┬─────────────────┐
│ No. │ Task Description               │ Status     │ Priority │ Created         │
├─────┼────────────────────────────────┼────────────┼──────────┼─────────────────┤
│ 1   │ Fix login bug                  │ Pending    │ High     │ 2024-01-15 14:30│
│ 2   │ Update documentation           │ Completed  │ Medium   │ 2024-01-15 15:45│
│ 3   │ Review pull requests           │ Pending    │ Low      │ 2024-01-15 16:20│
└─────┴────────────────────────────────┴────────────┴──────────┴─────────────────┘

📊 Summary: 3 total | 1 completed | 2 pending
```

---

## 🔧 Core Functions

### Adding Tasks Function

```bash
add_task() {
    print_colored "$CYAN" "=== Add New Task ==="
    
    while true; do
        echo -n "Enter task description (or 'cancel' to abort): "
        read -r task_description
        
        # Input validation
        if [[ -z "$task_description" ]]; then
            print_colored "$RED" "❌ Error: Task description cannot be empty!"
            continue
        fi
        
        # Check for delimiter conflicts
        if [[ "$task_description" =~ \| ]]; then
            print_colored "$RED" "❌ Error: Task description cannot contain '|' character!"
            continue
        fi
        
        break
    done
    
    # Add priority selection
    echo "Select priority level:"
    echo "1) High"
    echo "2) Medium" 
    echo "3) Low"
    echo -n "Choose (1-3, default 2): "
    read -r priority_choice
    
    case "$priority_choice" in
        1) priority="High" ;;
        3) priority="Low" ;;
        *) priority="Medium" ;;
    esac
    
    # Add with timestamp
    timestamp=$(date '+%Y-%m-%d %H:%M')
    echo "${task_description}|Pending|${priority}|${timestamp}" >> "$TASK_FILE"
    
    print_colored "$GREEN" "✅ Task added successfully!"
}
```

### Viewing Tasks with AWK

```bash
view_tasks() {
    # Display formatted table using awk
    awk -F'|' -v red="$RED" -v green="$GREEN" -v yellow="$YELLOW" -v nc="$NC" '{
        if ($2 == "Completed") {
            status_color = green
        } else {
            status_color = yellow  
        }
        
        priority = ($3 != "") ? $3 : "Medium"
        created = ($4 != "") ? $4 : "N/A"
        
        printf "│ %-3s │ %-30s │ " status_color "%-10s" nc " │ %-8s │ %-15s │\n", 
               NR, substr($1, 1, 30), $2, priority, created
    }' "$TASK_FILE"
}
```

**Key AWK Features:**
- `-F'|'` - Set field separator to pipe character
- `NR` - Current record (line) number
- `$1, $2, $3` - Field references
- `substr()` - String truncation for formatting
- `printf` - Formatted output with alignment

### Deleting Tasks with SED

```bash
delete_task() {
    # Get task number from user
    echo -n "Enter task number to delete: "
    read -r task_num
    
    # Validate input
    if ! validate_number "$task_num" 1 "$total_tasks"; then
        print_colored "$RED" "❌ Invalid task number!"
        return 1
    fi
    
    # Create backup before deletion
    create_backup
    
    # Delete specific line using sed
    sed -i "${task_num}d" "$TASK_FILE"
    print_colored "$GREEN" "✅ Task deleted successfully!"
}
```

**SED Command Breakdown:**
- `sed -i` - Edit file in-place
- `"${task_num}d"` - Delete line number stored in variable
- `$TASK_FILE` - Target file

### Marking Tasks Complete

```bash
mark_completed() {
    # Complex awk operation to modify specific field
    awk -F'|' -v r="$task_num" -v completion_time="$completion_time" '
    BEGIN {OFS = FS} 
    NR==r {
        $2="Completed"
        if (NF >= 4) $4 = $4 " (Completed: " completion_time ")"
        else $4 = "Completed: " completion_time
    }1' "$TASK_FILE" > temp && mv temp "$TASK_FILE"
}
```

**Advanced AWK Features:**
- `-v` - Pass shell variables to awk
- `BEGIN {OFS = FS}` - Set output field separator
- `NR==r` - Match specific record number
- `$2="Completed"` - Modify field value
- `1` - Print all lines (shorthand for {print})

---

## 🛠️ Advanced Features

### Input Validation

```bash
validate_number() {
    local input=$1
    local min=$2
    local max=$3
    
    # Check if input is numeric
    if ! [[ "$input" =~ ^[0-9]+$ ]]; then
        return 1
    fi
    
    # Check range
    if [[ $input -lt $min || $input -gt $max ]]; then
        return 1
    fi
    
    return 0
}
```

### Automatic Backup System

```bash
create_backup() {
    if [[ -f "$TASK_FILE" ]]; then
        local backup_file="${TASK_FILE}.backup.$(date +%s)"
        cp "$TASK_FILE" "$backup_file"
        print_colored "$BLUE" "🛡️ Backup created: $backup_file"
    fi
}
```

### Color Output System

```bash
# Color definitions
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

print_colored() {
    local color=$1
    local message=$2
    echo -e "${color}${message}${NC}"
}
```

### CSV Export Feature

```bash
export_tasks() {
    local export_file="tasks_export_$(date +%Y%m%d_%H%M%S).csv"
    
    # Create CSV header
    echo "Task Number,Description,Status,Priority,Created" > "$export_file"
    
    # Export data with proper CSV formatting
    awk -F'|' '{
        priority = ($3 != "") ? $3 : "Medium"
        created = ($4 != "") ? $4 : "N/A"
        printf "%d,\"%s\",\"%s\",\"%s\",\"%s\"\n", NR, $1, $2, priority, created
    }' "$TASK_FILE" >> "$export_file"
    
    print_colored "$GREEN" "✅ Tasks exported to: $export_file"
}
```

---

## 💡 Code Examples

### File Structure Example

```bash
# Sample tasks.txt content
Fix authentication bug|Pending|High|2024-01-15 09:30
Update user documentation|Completed|Medium|2024-01-14 16:45
Review security patches|Pending|High|2024-01-15 11:20
Optimize database queries|Completed|Low|2024-01-13 14:10
```

### Search Functionality

```bash
search_tasks() {
    echo -n "Enter search term: "
    read -r search_term
    
    local found=0
    while IFS='|' read -r description status priority timestamp; do
        if [[ "$description" =~ $search_term ]]; then
            local line_num=$(grep -n "$description" "$TASK_FILE" | head -1 | cut -d':' -f1)
            printf "│ %-3s │ %-30s │ %-10s │ %-8s │\n" \
                   "$line_num" "${description:0:30}" "$status" "${priority:-Medium}"
            found=1
        fi
    done < "$TASK_FILE"
    
    if [[ $found -eq 0 ]]; then
        print_colored "$YELLOW" "🔍 No tasks found matching '$search_term'"
    fi
}
```

### Error Handling

```bash
# Trap Ctrl+C gracefully
trap 'echo; print_colored "$YELLOW" "👋 Operation cancelled by user."; exit 130' INT

# Check dependencies
check_dependencies() {
    local missing_deps=()
    
    for cmd in awk sed grep; do
        if ! command -v "$cmd" &> /dev/null; then
            missing_deps+=("$cmd")
        fi
    done
    
    if [[ ${#missing_deps[@]} -gt 0 ]]; then
        print_colored "$RED" "❌ Missing required dependencies: ${missing_deps[*]}"
        exit 1
    fi
}
```

---

## 🔍 Troubleshooting

### Common Issues

| Issue | Solution |
|-------|----------|
| **Permission denied** | `chmod +x task_manager.sh` |
| **Command not found** | Check if `awk`, `sed`, `grep` are installed |
| **File not found** | Script creates `tasks.txt` automatically |
| **Formatting issues** | Ensure terminal supports color codes |
| **Backup files accumulating** | Clean old `.backup.*` files periodically |

### Debug Mode

```bash
# Add debug mode to script
DEBUG=${DEBUG:-0}

debug_log() {
    if [[ $DEBUG -eq 1 ]]; then
        echo "[DEBUG] $*" >&2
    fi
}

# Usage: DEBUG=1 ./task_manager.sh
```

### Testing the Functions

```bash
# Test individual functions
test_add_task() {
    echo "Test task|Pending|Medium|2024-01-15 12:00" >> "$TASK_FILE"
    echo "Task added for testing"
}

test_view_tasks() {
    if view_tasks | grep -q "Test task"; then
        echo "✅ View function working"
    else
        echo "❌ View function failed"
    fi
}
```

---

## 🎓 Learning Objectives

### Bash Scripting Concepts

1. **File Operations**
   - Reading/writing files
   - File existence checks
   - Creating backups

2. **Text Processing**
   - AWK for field processing
   - SED for line editing
   - GREP for pattern matching

3. **User Interface**
   - Menu systems
   - Input validation
   - Color output

4. **Error Handling**
   - Signal trapping
   - Input validation
   - Dependency checking

### Key Commands Learned

| Command | Purpose | Example |
|---------|---------|---------|
| `awk -F'|'` | Process delimited data | Field extraction |
| `sed -i '3d'` | Delete specific line | Remove task #3 |
| `grep -n "pattern"` | Search with line numbers | Find task by keyword |
| `printf "format"` | Formatted output | Table alignment |
| `read -r variable` | Safe input reading | User interaction |

### Advanced Techniques

```bash
# Variable substitution in sed
sed -i "${line_number}d" "$file"

# AWK with multiple variables
awk -v var1="$value1" -v var2="$value2" 'script' file

# Array handling in bash
missing_deps=()
missing_deps+=("command")

# Conditional expressions
[[ "$input" =~ ^[0-9]+$ ]] && echo "Number"

# Here-doc for multi-line strings
cat << 'EOF'
Multi-line
content here
EOF
```

---

## 📊 Project Statistics

### Code Metrics

| Metric | Value |
|--------|-------|
| **Lines of Code** | ~400 |
| **Functions** | 15+ |
| **Features** | 8 major |
| **Dependencies** | 3 (awk, sed, grep) |
| **File Size** | ~12KB |

### Feature Comparison

| Feature | Basic Version | Enhanced Version |
|---------|---------------|------------------|
| Add Tasks | ✅ Simple | ✅ With priorities |
| View Tasks | ✅ Basic list | ✅ Formatted table |
| Delete Tasks | ✅ By number | ✅ With confirmation |
| Mark Complete | ✅ Status change | ✅ With timestamp |
| Search | ❌ Not included | ✅ Full-text search |
| Export | ❌ Not included | ✅ CSV format |
| Backups | ❌ Not included | ✅ Automatic |
| Colors | ❌ Plain text | ✅ Color-coded |

---

## 🚀 Enhancements & Extensions

### Possible Improvements

1. **Database Integration**
   - SQLite backend
   - Better data integrity

2. **Web Interface**
   - HTML frontend
   - REST API

3. **Collaboration Features**
   - Multi-user support
   - Task assignment

4. **Advanced Filtering**
   - Date ranges
   - Priority sorting
   - Status filtering

5. **Notifications**
   - Due date alerts
   - Email reminders

### Contributing

```bash
# Fork the repository
git clone https://github.com/your-repo/bash-task-manager.git

# Create feature branch
git checkout -b feature/new-feature

# Make changes and test
./task_manager.sh

# Commit and push
git add .
git commit -m "Add new feature"
git push origin feature/new-feature
```

---

## 📚 References

### Essential Documentation
- [Bash Manual](https://www.gnu.org/software/bash/manual/)
- [AWK Tutorial](https://www.tutorialspoint.com/awk/)
- [SED Manual](https://www.gnu.org/software/sed/manual/)
- [GREP Documentation](https://www.gnu.org/software/grep/manual/)

### Additional Resources
- [Advanced Bash Scripting Guide](https://tldp.org/LDP/abs/html/)
- [Shell Style Guide](https://google.github.io/styleguide/shellguide.html)
- [Bash Pitfalls](https://mywiki.wooledge.org/BashPitfalls)

### Project Templates
- [Bash Script Template](https://github.com/ralish/bash-script-template)
- [Shell Best Practices](https://github.com/anordal/shellharden)

---

## 📋 Quick Reference

### Command Cheat Sheet

```bash
# Start application
./task_manager.sh

# Add task
# Choose option 1, enter description

# View all tasks  
# Choose option 2

# Delete task
# Choose option 3, enter task number

# Mark complete
# Choose option 4, enter task number

# Search tasks
# Choose option 5, enter keyword

# Export to CSV
# Choose option 6
```

### File Operations

```bash
# Manual file editing
nano tasks.txt

# View raw file
cat tasks.txt

# Backup tasks
cp tasks.txt tasks_backup.txt

# Count tasks
wc -l tasks.txt
```

---

*This project demonstrates practical Bash scripting with real-world applications. Perfect for learning file operations, text processing, and building interactive command-line tools.*
#!/bin/bash

# Task Manager - Complete Implementation
# File: task_manager.sh
# Description: A bash-based task management system

# Global variables
TASK_FILE="tasks.txt"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
TASK_FILE="$SCRIPT_DIR/tasks.txt"

# Color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Function to display colored output
```bash
print_colored() {
    local color=$1
    local message=$2
    echo -e "${color}${message}${NC}"
}
```

# Function to validate input
```bash
validate_number() {
    local input=$1
    local min=$2
    local max=$3
    
    if ! [[ "$input" =~ ^[0-9]+$ ]]; then
        return 1
    fi
    
    if [[ $input -lt $min || $input -gt $max ]]; then
        return 1
    fi
    
    return 0
}
```

# Function to create backup
```bash
create_backup() {
    if [[ -f "$TASK_FILE" ]]; then
        local backup_file="${TASK_FILE}.backup.$(date +%s)"
        cp "$TASK_FILE" "$backup_file"
        print_colored "$BLUE" "🛡️ Backup created: $backup_file"
    fi
}
```

# Function to add a task
```bash
add_task() {
    print_colored "$CYAN" "=== Add New Task ==="
    
    while true; do
        echo -n "Enter task description (or 'cancel' to abort): "
        read -r task_description
        
        # Check for cancel
        if [[ "$task_description" == "cancel" ]]; then
            print_colored "$YELLOW" "🚫 Task creation cancelled."
            return 0
        fi
        
        # Validate input
        if [[ -z "$task_description" ]]; then
            print_colored "$RED" "❌ Error: Task description cannot be empty!"
            continue
        fi
        
        # Check for pipe character
        if [[ "$task_description" =~ \| ]]; then
            print_colored "$RED" "❌ Error: Task description cannot contain '|' character!"
            continue
        fi
        
        break
    done  

    # Optional: Add priority level
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
    
    # Add timestamp
    timestamp=$(date '+%Y-%m-%d %H:%M')
    
    # Write to file
    echo "${task_description}|Pending|${priority}|${timestamp}" >> "$TASK_FILE"
    print_colored "$GREEN" "✅ Task added successfully!"
    echo "   Description: $task_description"
    echo "   Priority: $priority"
    echo "   Added: $timestamp"
    echo
}
```

# Function to view tasks
```bash
view_tasks() {
    print_colored "$CYAN" "=== Task List ==="
    
    # Check if file exists and has content
    if [[ ! -f "$TASK_FILE" || ! -s "$TASK_FILE" ]]; then
        print_colored "$YELLOW" "📝 No tasks found. Add some tasks first!"
        return 0
    fi
    
    # Display header
    echo "┌─────┬────────────────────────────────┬────────────┬──────────┬─────────────────┐"
    echo "│ No. │ Task Description               │ Status     │ Priority │ Created         │"
    echo "├─────┼────────────────────────────────┼────────────┼──────────┼─────────────────┤"
    
    # Display tasks using awk with color coding
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
    
    echo "└─────┴────────────────────────────────┴────────────┴──────────┴─────────────────┘"
    echo
    
    # Show summary
    show_summary
}
```

# Function to show task summary
```bash
show_summary() {
    local total_tasks=$(wc -l < "$TASK_FILE" 2>/dev/null || echo 0)
    local completed_tasks=$(grep -c "Completed" "$TASK_FILE" 2>/dev/null || echo 0)
    local pending_tasks=$((total_tasks - completed_tasks))
    
    print_colored "$BLUE" "📊 Summary: $total_tasks total | $completed_tasks completed | $pending_tasks pending"
    echo
}
```

# Function to delete a task
```bash
delete_task() {
    print_colored "$CYAN" "=== Delete Task ==="
    
    # Show current tasks first
    view_tasks
    
    # Get total number of tasks
    local total_tasks=$(wc -l < "$TASK_FILE" 2>/dev/null || echo 0)
    
    if [[ $total_tasks -eq 0 ]]; then
        print_colored "$YELLOW" "📝 No tasks to delete!"
        return 0
    fi
    
    echo -n "Enter task number to delete (1-$total_tasks, or 0 to cancel): "
    read -r task_num
    
    # Validate input
    if [[ "$task_num" == "0" ]]; then
        print_colored "$YELLOW" "🚫 Delete operation cancelled."
        return 0
    fi
    
    if ! validate_number "$task_num" 1 "$total_tasks"; then
        print_colored "$RED" "❌ Error: Please enter a valid number between 1 and $total_tasks!"
        return 1
    fi
    
    # Get task description for confirmation
    local task_desc=$(sed -n "${task_num}p" "$TASK_FILE" | cut -d'|' -f1)
    
    # Confirm deletion
    echo -n "Are you sure you want to delete '$task_desc'? (y/N): "
    read -r confirm
    
    if [[ "$confirm" =~ ^[Yy]$ ]]; then
        # Create backup before deletion
        create_backup
        
        # Delete the line using sed
        if sed -i "${task_num}d" "$TASK_FILE"; then
            print_colored "$GREEN" "✅ Task deleted successfully!"
        else
            print_colored "$RED" "❌ Error deleting task!"
            return 1
        fi
    else
        print_colored "$YELLOW" "🚫 Delete operation cancelled."
    fi
    echo
}
```

# Function to mark task as completed
```bash
mark_completed() {
    print_colored "$CYAN" "=== Mark Task as Completed ==="
    
    # Check if file exists
    if [[ ! -f "$TASK_FILE" || ! -s "$TASK_FILE" ]]; then
        print_colored "$YELLOW" "📝 No tasks found!"
        return 0
    fi
    
    # Show current pending tasks
    echo "Pending tasks:"
    awk -F'|' '$2 != "Completed" {printf " %s. %s\n", NR, $1}' "$TASK_FILE"
    echo
    
    # Get total number of tasks
    local total_tasks=$(wc -l < "$TASK_FILE")
    
    echo -n "Enter task number to mark as completed (1-$total_tasks, or 0 to cancel): "
    read -r task_num
    
    # Validate input
    if [[ "$task_num" == "0" ]]; then
        print_colored "$YELLOW" "🚫 Operation cancelled."
        return 0
    fi
    
    if ! validate_number "$task_num" 1 "$total_tasks"; then
        print_colored "$RED" "❌ Error: Please enter a valid number between 1 and $total_tasks!"
        return 1
    fi
    
    # Check if task is already completed
    local current_status=$(sed -n "${task_num}p" "$TASK_FILE" | cut -d'|' -f2)
    if [[ "$current_status" == "Completed" ]]; then
        print_colored "$YELLOW" "ℹ️ Task is already marked as completed!"
        return 0
    fi
    
    # Get task description for confirmation
    local task_desc=$(sed -n "${task_num}p" "$TASK_FILE" | cut -d'|' -f1)
    
    # Create backup before modification
    create_backup
    
    # Mark as completed using awk
    local completion_time=$(date '+%Y-%m-%d %H:%M')
    awk -F'|' -v r="$task_num" -v completion_time="$completion_time" '
    BEGIN {OFS = FS} 
    NR==r {
        $2="Completed"
        if (NF >= 4) $4 = $4 " (Completed: " completion_time ")"
        else $4 = "Completed: " completion_time
    }1' "$TASK_FILE" > temp &&


    ❌❌❌❌❌❌❌ NOT COMPLETE ❌❌❌❌❌❌❌

```
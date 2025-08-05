# Get Next Line Project

This project implements a function in C, `get_next_line`, that reads a line from a file descriptor, returning one line at a time. It focuses on efficient file reading and introduces the use of static variables for managing state across function calls.

## Overview

### Objective
Create a function that reads and returns a single line from a file descriptor, handling both files and standard input effectively.

### Structure
- **Mandatory Part**: Implements the `get_next_line` function to read one line at a time using a static variable for state management.
- **Bonus Part**: Enhances the function to use a single static variable and support multiple file descriptors simultaneously (not included in this description).

### Constraints
- Global variables and `lseek` are prohibited.
- Libft is not allowed.
- Function must handle variable buffer sizes defined by `-D BUFFER_SIZE` (e.g., 1, 42, 9999, or 10000000).
- Must compile with `-Wall`, `-Wextra`, `-Werror`, and work with or without the `-D BUFFER_SIZE` flag.
- Ensures no memory leaks in user-written code.

## Features

### Mandatory Program (`get_next_line`)
- Function: `char *get_next_line(int fd);`
- Reads one line from the specified file descriptor (`fd`), including the `\n` character (unless the file ends without one).
- Returns `NULL` when there is nothing left to read or an error occurs.
- Works with both files and standard input.
- Uses a static variable to retain unread data between calls.
- Reads minimal data per call, processing lines as soon as a newline is encountered.

## Technical Details

- **Language**: C
- **Allowed Functions**: `read`, `malloc`, `free`.
- **Files**: `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`.
- **Makefile**: Includes rules for `NAME`, `all`, `clean`, `fclean`, `re`, and a `bonus` rule for the bonus part.
- **Directory Structure**: All files in the root directory.
- **Compilation**: Supports `-D BUFFER_SIZE=n` for adjustable buffer sizes (e.g., `cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c`).
- **Behavior**: Undefined for binary files or if the file is modified during reading, but logical handling can be implemented.

## Learning Outcomes

- Understanding and applying static variables for state persistence.
- Efficient file reading and memory management.
- Handling variable buffer sizes and edge cases in file descriptor operations.

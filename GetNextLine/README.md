*This activity has been created as part of the 42 curriculum by yakombo-.*

# Get Next Line

## Description

Get Next Line (GNL) is a project from the 42 curriculum whose goal is to create a function capable of reading a file descriptor line by line.

The function prototype is:

```c
char    *get_next_line(int fd);
```

Each call to `get_next_line()` returns the next available line from the given file descriptor, including the newline character (`\n`) if present.

This project introduces several important concepts in C programming:

- File descriptors
- Static variables
- Dynamic memory allocation
- Reading from files using `read()`
- Memory management and leak prevention
- String manipulation without using libft

The project must work with:
- Regular files
- Standard input
- Different `BUFFER_SIZE` values

---

## Project Structure

```bash
.
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
└── README.md
```

---

## How It Works

The function reads data from the file descriptor using a buffer of size `BUFFER_SIZE`.

A static variable is used to store unread data between function calls.

The algorithm works in several steps:

1. Read from the file descriptor until a newline (`\n`) or EOF is found.
2. Store the read content inside a static buffer.
3. Extract the next line from this buffer.
4. Keep the remaining content for the next call.
5. Return the extracted line.

This allows the function to read progressively without reading the entire file at once.

---

## Algorithm Explanation

### Why use a static variable?

Without a static variable, all data stored inside the function would be lost after each call.

The static variable keeps unread content between calls, allowing the function to continue reading exactly where it stopped previously.

Example:

```txt
File content:
Hello
World
42
```

Calls to `get_next_line(fd)` return:

```txt
1st call -> "Hello\n"
2nd call -> "World\n"
3rd call -> "42"
4th call -> NULL
```

---

## Instructions

### Compilation

Compile with:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c
```

You can replace `42` with any buffer size:

```bash
-D BUFFER_SIZE=1
-D BUFFER_SIZE=9999
```

---

## Example Usage

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return (1);

    line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}
```

---

## Allowed Functions

Only these functions are allowed:

- `read`
- `malloc`
- `free`

---

## Forbidden

The following are forbidden:

- Using `libft`
- Global variables
- `lseek()`

---

## Important Notes

- The returned line must include `\n` if it exists.
- The function must not leak memory.
- The function must behave correctly with any valid `BUFFER_SIZE`.
- Reading must stop as soon as a complete line is available.
- The project has undefined behavior on binary files.

---

## What I Learned

Through this project, I learned:

- How file descriptors work
- How `read()` behaves
- How static variables persist between function calls
- How to manage dynamic memory safely
- How to split and store strings efficiently
- How to debug memory leaks and segmentation faults

---

## Resources

### Documentation

- The `read()` manual:
```bash
man 2 read
```

- File descriptors:
  - https://man7.org/linux/man-pages/man2/open.2.html

- Static variables in C:
  - https://www.geeksforgeeks.org/static-variables-in-c/

---

## AI Usage

AI was used only for:
- Understanding some concepts related to static variables
- Improving README formatting and explanations
- Reviewing algorithm explanations

The implementation logic and debugging were done manually to fully understand the project.

---

## Conclusion

Get Next Line is one of the most important foundational projects in the 42 curriculum because it teaches how low-level file reading and memory management work internally in C.

Mastering this project helps build strong understanding for future projects involving parsing, file handling, and system programming.

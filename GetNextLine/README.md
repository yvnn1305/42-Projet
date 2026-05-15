# get_next_line

> Read a file descriptor line by line, one call at a time.

## About

`get_next_line` is a 42 School project. The goal is to implement a function that reads a single line from a file descriptor each time it is called, returning the next line on every subsequent call.

```c
char *get_next_line(int fd);
```

Returns the next line from `fd` including the trailing `\n`, or `NULL` on EOF or error.

## How it works

A `static` variable `stash` persists between calls, storing any data read beyond the current line. On each call:

1. If `stash` already contains a `\n`, no read is needed
2. Otherwise, read from `fd` into a buffer and append to `stash` until a `\n` is found or EOF is reached
3. Extract the line up to and including `\n` from `stash`
4. Trim `stash` to keep only what comes after the `\n` for the next call

```
stash = "alpha\nbeta\ngamma"
          ↓
return  → "alpha\n"
stash   → "beta\ngamma"
```

## Files

| File | Description |
|------|-------------|
| `get_next_line.c` | Core logic — `get_next_line`, `get_line`, `ft_update_stash`, `stash_split`, `stash_trim` |
| `get_next_line_utils.c` | Helper functions — `ft_strlen`, `ft_strchr`, `ft_memcpy`, `ft_strjoin`, `stash_append` |
| `get_next_line.h` | Header — prototypes and `BUFFER_SIZE` define |

## Usage

Compile with a custom `BUFFER_SIZE`:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

Use in your code:

```c
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    line = get_next_line(fd);
    while (line != NULL)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}
```

> The caller is responsible for freeing each line returned by `get_next_line`.

## Norminette

This project follows the [42 Norm](https://github.com/42School/norminette):
- Max 25 lines per function
- Max 5 functions per file
- No more than 5 variables per function
- Tabs for indentation

## Author

yakombo- — [42 School](https://42.fr)

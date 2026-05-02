*This activity has been created as part of the 42 curriculum by yakombo-.*

# Libft — Your very first own library

## Description

**Libft** is a foundational C project from the 42 curriculum. The goal is to reimplement a set of standard C library functions from scratch, building a personal static library (`libft.a`) that can be reused throughout the entire 42 curriculum.

The project is split into three parts:

- **Part 1 – Libc functions**: Reimplementations of standard functions such as `ft_strlen`, `ft_memcpy`, `ft_atoi`, `ft_strchr`, etc.
- **Part 2 – Additional functions**: Custom utility functions not found in the libc (or in a different form), such as `ft_substr`, `ft_strjoin`, `ft_split`, `ft_itoa`, `ft_strmapi`, and fd-based output functions.
- **Part 3 – Linked list**: A set of functions to create and manipulate singly linked lists using the `t_list` structure (`ft_lstnew`, `ft_lstadd_front`, `ft_lstmap`, etc.).

## Library overview

### Part 1 — Libc functions

| Function | Description |
|---|---|
| `ft_isalpha` | Returns 1 if the char is alphabetic, 0 otherwise |
| `ft_isdigit` | Returns 1 if the char is a digit, 0 otherwise |
| `ft_isalnum` | Returns 1 if the char is alphanumeric, 0 otherwise |
| `ft_isascii` | Returns 1 if the char is in the ASCII table, 0 otherwise |
| `ft_isprint` | Returns 1 if the char is printable, 0 otherwise |
| `ft_strlen` | Returns the length of a string |
| `ft_memset` | Fills a memory area with a given byte value |
| `ft_bzero` | Sets a memory area to zero |
| `ft_memcpy` | Copies a memory area |
| `ft_memmove` | Copies a memory area, handling overlaps |
| `ft_strlcpy` | Copies a string with size limitation |
| `ft_strlcat` | Concatenates strings with size limitation |
| `ft_toupper` | Converts a character to uppercase |
| `ft_tolower` | Converts a character to lowercase |
| `ft_strchr` | Finds the first occurrence of a character in a string |
| `ft_strrchr` | Finds the last occurrence of a character in a string |
| `ft_strncmp` | Compares two strings up to n characters |
| `ft_memchr` | Searches a memory area for a byte |
| `ft_memcmp` | Compares two memory areas |
| `ft_strnstr` | Finds a substring in a string, limited to n characters |
| `ft_atoi` | Converts a string to an integer |
| `ft_calloc` | Allocates and zero-initializes memory |
| `ft_strdup` | Duplicates a string using malloc |

### Part 2 — Additional functions

| Function | Description |
|---|---|
| `ft_substr` | Extracts a substring from a string |
| `ft_strjoin` | Concatenates two strings into a new one |
| `ft_strtrim` | Trims characters from the beginning and end of a string |
| `ft_split` | Splits a string by a delimiter into an array of strings |
| `ft_itoa` | Converts an integer to a string |
| `ft_strmapi` | Applies a function to each character of a string (returns new string) |
| `ft_striteri` | Applies a function to each character of a string (in-place) |
| `ft_putchar_fd` | Outputs a character to a file descriptor |
| `ft_putstr_fd` | Outputs a string to a file descriptor |
| `ft_putendl_fd` | Outputs a string followed by a newline to a file descriptor |
| `ft_putnbr_fd` | Outputs an integer to a file descriptor |

### Part 3 — Linked list

Uses the following structure:

```c
typedef struct s_list
{
    void         *content;
    struct s_list *next;
} t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new list node |
| `ft_lstadd_front` | Adds a node at the beginning of the list |
| `ft_lstsize` | Returns the number of nodes in the list |
| `ft_lstlast` | Returns the last node of the list |
| `ft_lstadd_back` | Adds a node at the end of the list |
| `ft_lstdelone` | Deletes and frees a single node |
| `ft_lstclear` | Deletes and frees all nodes of the list |
| `ft_lstiter` | Applies a function to each node's content |
| `ft_lstmap` | Creates a new list by applying a function to each node |

## Instructions

### Compilation

```bash
make        # Compiles the library → libft.a
make clean  # Removes object files
make fclean # Removes object files and libft.a
make re     # fclean + make
```

### Using the library in your project

```bash
gcc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

Include the header in your source files:

```c
#include "libft.h"
```

## Resources

- [C standard library reference — cppreference.com](https://en.cppreference.com/w/c)
- [man pages online](https://man7.org/linux/man-pages/)
- [42 Norm documentation](https://github.com/42School/norminette)
- [Youtube : Comprendre le Makefile](https://youtu.be/vngK2abJ3_I?si=4hYhxNz8b88WRJa8)

### AI usage

AI was used for three purposes during this project:
- **Understanding new concepts**: When encountering unfamiliar notions (e.g. memory management, pointer arithmetic, linked list manipulation), AI was used to get simple and accessible explanations — always making sure to understand the concept before writing any code.
- **Writing complex test mains**: For functions whose behavior was tricky to verify, AI helped draft test `main` files to cover edge cases and validate the implementation.
- **Guidance on some functions**: For certain more difficult functions, AI was used as a guide — helping think through the logic and approach without ever directly providing the code. The actual implementation was always written independently.

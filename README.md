# Ylib - C Standard Library

![GitHub commit activity](https://img.shields.io/github/commit-activity/t/yuann3/Ylib) ![GitHub repo size](https://img.shields.io/github/repo-size/yuann3/Ylib) [![.github/workflows/norminette](https://github.com/yuann3/Ylib/actions/workflows/norminette.yml/badge.svg)](https://github.com/yuann3/Ylib/actions/workflows/norminette.yml)

A reimplementation of the C standard library, extended with additional data structures. Fully compliant with 42 norminette.

## Build

```bash
make        # Build libft.a
make clean  # Remove object files
make fclean # Remove object files and libft.a
make re     # Rebuild everything
```

## Usage

```c
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Hello, Ylib!");
    ft_printf("%s\n", str);
    free(str);
    return (0);
}
```

Compile with:
```bash
cc -Wall -Wextra -Werror -I includes main.c -L. -lft -o program
```

---

## API Reference

### Character Classification (`ft_is`)

| Function | Description |
|----------|-------------|
| `int ft_isalpha(int c)` | Check if alphabetic |
| `int ft_isdigit(int c)` | Check if digit (0-9) |
| `int ft_isalnum(int c)` | Check if alphanumeric |
| `int ft_isascii(int c)` | Check if ASCII (0-127) |
| `int ft_isprint(int c)` | Check if printable |

---

### String Functions (`ft_str`)

| Function | Description |
|----------|-------------|
| `size_t ft_strlen(const char *s)` | Get string length |
| `char *ft_strchr(const char *s, int c)` | Find first occurrence of char |
| `char *ft_strrchr(const char *s, int c)` | Find last occurrence of char |
| `int ft_strncmp(const char *s1, const char *s2, size_t n)` | Compare n bytes |
| `char *ft_strnstr(const char *haystack, const char *needle, size_t len)` | Find substring |
| `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)` | Safe string copy |
| `size_t ft_strlcat(char *dst, const char *src, size_t dstsize)` | Safe string concatenate |
| `char *ft_strdup(const char *s1)` | Duplicate string (malloc) |
| `char *ft_substr(char const *s, unsigned int start, size_t len)` | Extract substring |
| `char *ft_strjoin(char const *s1, char const *s2)` | Concatenate two strings |
| `char *ft_strtrim(char const *s1, char const *set)` | Trim characters from both ends |
| `char **ft_split(char const *s, char c)` | Split string by delimiter |
| `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Map function over string |
| `void ft_striteri(char *s, void (*f)(unsigned int, char *))` | Iterate with function |
| `int ft_toupper(int c)` | Convert to uppercase |
| `int ft_tolower(int c)` | Convert to lowercase |
| `int ft_atoi(const char *str)` | String to integer |
| `char *ft_itoa(int n)` | Integer to string |

---

### Memory Functions (`ft_mem`)

| Function | Description |
|----------|-------------|
| `void *ft_memset(void *b, int c, size_t len)` | Fill memory with byte |
| `void ft_bzero(void *s, size_t n)` | Zero out memory |
| `void *ft_memcpy(void *dst, const void *src, size_t n)` | Copy memory |
| `void *ft_memmove(void *dst, const void *src, size_t len)` | Copy overlapping memory |
| `void *ft_memchr(const void *s, int c, size_t n)` | Find byte in memory |
| `int ft_memcmp(const void *s1, const void *s2, size_t n)` | Compare memory |
| `void *ft_calloc(size_t count, size_t size)` | Allocate zeroed memory |

---

### Output Functions (`ft_put`)

| Function | Description |
|----------|-------------|
| `void ft_putchar_fd(char c, int fd)` | Write char to fd |
| `void ft_putstr_fd(char *s, int fd)` | Write string to fd |
| `void ft_putendl_fd(char *s, int fd)` | Write string + newline to fd |
| `void ft_putnbr_fd(int n, int fd)` | Write number to fd |

---

### Printf (`ft_printf`)

```c
int ft_printf(const char *format, ...);
```

Supported conversions: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`

---

### Linked List (`ft_lst`)

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Description |
|----------|-------------|
| `t_list *ft_lstnew(void *content)` | Create new node |
| `void ft_lstadd_front(t_list **lst, t_list *new)` | Add node to front |
| `void ft_lstadd_back(t_list **lst, t_list *new)` | Add node to back |
| `int ft_lstsize(t_list *lst)` | Count nodes |
| `t_list *ft_lstlast(t_list *lst)` | Get last node |
| `void ft_lstdelone(t_list *lst, void (*del)(void *))` | Delete one node |
| `void ft_lstclear(t_list **lst, void (*del)(void *))` | Delete all nodes |
| `void ft_lstiter(t_list *lst, void (*f)(void *))` | Iterate with function |
| `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Map function to new list |

---

### Vector / Dynamic Array (`ft_vec`)

A generic dynamic array inspired by C++ `std::vector` and [nob.h](https://github.com/tsoding/nob.h).

```c
typedef struct s_vec
{
    void    *data;       // Raw memory buffer
    size_t  len;         // Current number of elements
    size_t  cap;         // Allocated capacity (in elements)
    size_t  elem_size;   // Size of each element in bytes
}   t_vec;
```

#### Memory Layout

```
t_vec structure:
┌──────────┬─────┬─────┬───────────┐
│ data *   │ len │ cap │ elem_size │
└────┬─────┴─────┴─────┴───────────┘
     │
     ▼
┌────┬────┬────┬────┬────┬────┐
│ e0 │ e1 │ e2 │ .. │    │    │  ← heap allocated buffer
└────┴────┴────┴────┴────┴────┘
  ^─── len ───^  ^── unused ──^
  ^──────── cap ──────────────^
```

#### Functions

| Function | Description |
|----------|-------------|
| `t_vec *ft_vec_new(size_t elem_size, size_t init_cap)` | Create new vector |
| `int ft_vec_push(t_vec *vec, const void *elem)` | Append element (O(1) amortized) |
| `int ft_vec_pop(t_vec *vec, void *out)` | Remove and retrieve last element |
| `void *ft_vec_get(t_vec *vec, size_t index)` | Get pointer to element (O(1)) |
| `int ft_vec_set(t_vec *vec, size_t index, const void *elem)` | Set element value |
| `int ft_vec_reserve(t_vec *vec, size_t new_cap)` | Ensure minimum capacity |
| `void ft_vec_clear(t_vec *vec)` | Reset to empty (keep capacity) |
| `void ft_vec_free(t_vec *vec)` | Free all memory |

#### Complexity

| Operation | Time Complexity |
|-----------|-----------------|
| `ft_vec_push` | O(1) amortized |
| `ft_vec_pop` | O(1) |
| `ft_vec_get` | O(1) |
| `ft_vec_set` | O(1) |
| `ft_vec_reserve` | O(n) |

#### Example

```c
#include "libft.h"

int main(void)
{
    t_vec   *nums;
    int     value;
    int     *ptr;
    size_t  i;

    // Create vector of integers with initial capacity 4
    nums = ft_vec_new(sizeof(int), 4);

    // Push elements
    value = 42;
    ft_vec_push(nums, &value);
    value = 100;
    ft_vec_push(nums, &value);
    value = 7;
    ft_vec_push(nums, &value);

    // Access elements
    i = 0;
    while (i < nums->len)
    {
        ptr = ft_vec_get(nums, i);
        ft_printf("%d\n", *ptr);
        i++;
    }

    // Modify element
    value = 999;
    ft_vec_set(nums, 1, &value);

    // Pop last element
    ft_vec_pop(nums, &value);
    ft_printf("popped: %d\n", value);

    // Cleanup
    ft_vec_free(nums);
    return (0);
}
```

#### Vector vs Linked List

| Feature | `t_list` | `t_vec` |
|---------|----------|---------|
| Access by index | O(n) | O(1) |
| Push back | O(n)* | O(1) amortized |
| Memory overhead | Pointer per node | Minimal |
| Cache locality | Poor | Excellent |
| Insert middle | O(1) after find | O(n) |

*O(1) with tail pointer

---

## Project Structure

```
Ylib/
├── includes/
│   └── libft.h
├── srcs/
│   ├── ft_is/       # Character classification
│   ├── ft_lst/      # Linked list
│   ├── ft_mem/      # Memory functions
│   ├── ft_printf/   # Printf implementation
│   ├── ft_put/      # Output functions
│   ├── ft_str/      # String functions
│   └── ft_vec/      # Dynamic array
├── Makefile
└── README.md
```

## License

[MIT](LICENSE)

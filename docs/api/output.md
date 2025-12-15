# File Descriptor Output Functions

Simple functions for writing characters, strings, and numbers to file descriptors. These are building blocks for more complex output operations.

## Function Reference

| Function | Description |
|----------|-------------|
| `ft_putchar_fd(c, fd)` | Write a character to file descriptor |
| `ft_putstr_fd(s, fd)` | Write a string to file descriptor |
| `ft_putendl_fd(s, fd)` | Write a string + newline to file descriptor |
| `ft_putnbr_fd(n, fd)` | Write an integer to file descriptor |

---

## Detailed Descriptions

### ft_putchar_fd

```c
void ft_putchar_fd(char c, int fd);
```

Write a single character to the specified file descriptor.

**Parameters:**
- `c`: Character to write
- `fd`: File descriptor (1 for stdout, 2 for stderr, or custom fd)

**Returns:** Nothing (void).

**Example:**
```c
ft_putchar_fd('A', 1);        // Write 'A' to stdout
ft_putchar_fd('!', 2);        // Write '!' to stderr
ft_putchar_fd('\n', 1);       // Write newline to stdout
```

---

### ft_putstr_fd

```c
void ft_putstr_fd(char *s, int fd);
```

Write a null-terminated string to the specified file descriptor.

**Parameters:**
- `s`: String to write (null-terminated)
- `fd`: File descriptor

**Returns:** Nothing (void).

**Note:** If `s` is NULL, the function does nothing (safe to call).

**Example:**
```c
ft_putstr_fd("Hello", 1);         // Write "Hello" to stdout
ft_putstr_fd("Error: ", 2);       // Write to stderr
ft_putstr_fd("", 1);              // Does nothing (empty string)
ft_putstr_fd(NULL, 1);            // Safe, does nothing
```

---

### ft_putendl_fd

```c
void ft_putendl_fd(char *s, int fd);
```

Write a string followed by a newline to the specified file descriptor.

**Parameters:**
- `s`: String to write
- `fd`: File descriptor

**Returns:** Nothing (void).

**Note:** Equivalent to `ft_putstr_fd(s, fd)` followed by `ft_putchar_fd('\n', fd)`.

**Example:**
```c
ft_putendl_fd("Hello", 1);        // Writes "Hello\n" to stdout
ft_putendl_fd("Line 1", 1);       // Writes "Line 1\n"
ft_putendl_fd("Line 2", 1);       // Writes "Line 2\n"

// Output:
// Hello
// Line 1
// Line 2
```

---

### ft_putnbr_fd

```c
void ft_putnbr_fd(int n, int fd);
```

Write a decimal representation of an integer to the specified file descriptor.

**Parameters:**
- `n`: Integer to write
- `fd`: File descriptor

**Returns:** Nothing (void).

**Note:** Handles negative numbers and INT_MIN correctly.

**Example:**
```c
ft_putnbr_fd(42, 1);              // Writes "42" to stdout
ft_putnbr_fd(-42, 1);             // Writes "-42" to stdout
ft_putnbr_fd(0, 1);               // Writes "0"
ft_putnbr_fd(2147483647, 1);      // Writes "2147483647" (INT_MAX)
ft_putnbr_fd(-2147483648, 1);     // Writes "-2147483648" (INT_MIN)
```

---

## File Descriptor Values

| Descriptor | Standard Name | Description |
|------------|---------------|-------------|
| 0 | `STDIN_FILENO` | Standard input |
| 1 | `STDOUT_FILENO` | Standard output (default for normal output) |
| 2 | `STDERR_FILENO` | Standard error (for error messages) |
| 3+ | Custom | File descriptors from `open()`, pipes, etc. |

---

## Common Usage Patterns

### Error Messages

```c
void print_error(char *msg)
{
    ft_putstr_fd("Error: ", 2);      // Write to stderr
    ft_putendl_fd(msg, 2);
}

// Usage
print_error("File not found");
// Stderr: Error: File not found
```

### Simple Logging

```c
void log_number(char *label, int value)
{
    ft_putstr_fd(label, 1);
    ft_putstr_fd(": ", 1);
    ft_putnbr_fd(value, 1);
    ft_putchar_fd('\n', 1);
}

// Usage
log_number("Result", 42);
// Output: Result: 42
```

### Output to File

```c
#include <fcntl.h>

void write_to_file(void)
{
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
        return;

    ft_putendl_fd("First line", fd);
    ft_putendl_fd("Second line", fd);
    ft_putstr_fd("Number: ", fd);
    ft_putnbr_fd(42, fd);
    ft_putchar_fd('\n', fd);

    close(fd);
}
```

### Debug Printing

```c
void debug_int(char *name, int value)
{
    ft_putstr_fd("[DEBUG] ", 2);
    ft_putstr_fd(name, 2);
    ft_putstr_fd(" = ", 2);
    ft_putnbr_fd(value, 2);
    ft_putchar_fd('\n', 2);
}

// Usage
debug_int("x", 10);
debug_int("y", 20);
// Stderr:
// [DEBUG] x = 10
// [DEBUG] y = 20
```

### Printing Arrays

```c
void print_array(int *arr, int len)
{
    int i;

    ft_putchar_fd('[', 1);
    i = 0;
    while (i < len)
    {
        ft_putnbr_fd(arr[i], 1);
        if (i < len - 1)
            ft_putstr_fd(", ", 1);
        i++;
    }
    ft_putendl_fd("]", 1);
}

// Usage
int nums[] = {1, 2, 3, 4, 5};
print_array(nums, 5);
// Output: [1, 2, 3, 4, 5]
```

## Implementation Notes

### Error Handling

These functions use the `write()` system call internally. They do **not** check the return value of `write()`, so errors (disk full, closed descriptor, etc.) are silently ignored.

**For production code requiring error handling:**
```c
int safe_putstr_fd(char *s, int fd)
{
    ssize_t ret;
    size_t len;

    if (!s)
        return (0);
    len = ft_strlen(s);
    ret = write(fd, s, len);
    return (ret == (ssize_t)len);
}
```

### Buffering

The `write()` system call may be buffered by the OS. For immediate output:
```c
#include <unistd.h>

ft_putstr_fd("Important message", 1);
fsync(1);  // Force flush to disk/terminal
```

### Performance

| Function | System Calls | Notes |
|----------|--------------|-------|
| `ft_putchar_fd` | 1 write | One write per character (inefficient for many chars) |
| `ft_putstr_fd` | 1 write | Single write for entire string (efficient) |
| `ft_putendl_fd` | 2 writes | String + newline (could be optimized) |
| `ft_putnbr_fd` | Multiple | One write per digit (recursive implementation) |

**For better performance with many writes, consider buffering:**
```c
// Instead of:
for (int i = 0; i < 1000; i++)
    ft_putchar_fd('x', 1);  // 1000 system calls!

// Do this:
char buf[1000];
ft_memset(buf, 'x', 1000);
write(1, buf, 1000);  // 1 system call
```

## Comparison with printf

| Task | Using put*_fd | Using ft_printf |
|------|---------------|-----------------|
| Write char | `ft_putchar_fd('A', 1)` | `ft_printf("%c", 'A')` |
| Write string | `ft_putstr_fd("hi", 1)` | `ft_printf("%s", "hi")` |
| Write number | `ft_putnbr_fd(42, 1)` | `ft_printf("%d", 42)` |
| Formatted | Multiple calls | `ft_printf("x=%d", x)` |

**When to use put*_fd:**
- Simple output (no formatting needed)
- Writing to stderr or custom file descriptors
- Minimizing dependencies (printf is more complex)
- Building blocks for your own formatting

**When to use ft_printf:**
- Complex formatting required
- Multiple values in one line
- Standard printf-style formatting

## Common Pitfalls

### Writing to Wrong FD

```c
// WRONG: Error message to stdout
ft_putstr_fd("Error!", 1);  // Should use fd 2 for errors

// RIGHT: Error messages to stderr
ft_putstr_fd("Error!", 2);
```

### Forgetting Newline

```c
// Output appears buffered or incomplete
ft_putstr_fd("Hello", 1);     // May not appear immediately
ft_putstr_fd("World", 1);     // Appears as "HelloWorld"

// Add newlines
ft_putendl_fd("Hello", 1);    // Appears immediately
ft_putendl_fd("World", 1);
```

### NULL String

```c
char *str = NULL;
ft_putstr_fd(str, 1);  // Safe, does nothing

// But this would crash:
// write(1, str, ft_strlen(str));  // strlen(NULL) crashes!
```

### Closed File Descriptor

```c
int fd = open("file.txt", O_WRONLY);
close(fd);
ft_putstr_fd("text", fd);  // Fails silently, fd is closed
```

## Related Functions

- [ft_printf](printf.md) - Formatted output (more powerful)
- [String Functions](string.md) - For string manipulation before output
- [Conversion Functions](conversion.md) - ft_itoa as alternative to ft_putnbr_fd

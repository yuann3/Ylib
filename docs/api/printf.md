# ft_printf - Formatted Output

A complete implementation of printf that supports all common format specifiers. Write formatted output to stdout with type-safe variable arguments.

## Function Signature

```c
int ft_printf(const char *format, ...);
```

**Parameters:**
- `format`: Format string with conversion specifiers
- `...`: Variable arguments matching the format specifiers

**Returns:**
- Number of characters printed (excluding null terminator)
- -1 on write error

**Output:** Writes to standard output (fd 1).

---

## Supported Conversions

| Specifier | Type | Description | Example |
|-----------|------|-------------|---------|
| `%c` | `int` | Single character | `ft_printf("%c", 'A')` → `A` |
| `%s` | `char *` | String | `ft_printf("%s", "hi")` → `hi` |
| `%p` | `void *` | Pointer address | `ft_printf("%p", ptr)` → `0x7fff5fbff710` |
| `%d` | `int` | Signed decimal | `ft_printf("%d", -42)` → `-42` |
| `%i` | `int` | Signed integer | `ft_printf("%i", -42)` → `-42` |
| `%u` | `unsigned int` | Unsigned decimal | `ft_printf("%u", 42)` → `42` |
| `%x` | `unsigned int` | Hex lowercase | `ft_printf("%x", 255)` → `ff` |
| `%X` | `unsigned int` | Hex uppercase | `ft_printf("%X", 255)` → `FF` |
| `%%` | N/A | Literal % | `ft_printf("%%")` → `%` |

---

## Detailed Conversion Descriptions

### %c - Character

Prints a single character.

```c
ft_printf("%c", 'A');              // A
ft_printf("%c%c%c", 'a', 'b', 'c'); // abc
ft_printf("char: %c\n", 65);       // char: A (ASCII 65 = 'A')
```

---

### %s - String

Prints a null-terminated string.

```c
ft_printf("%s", "hello");          // hello
ft_printf("%s %s", "hello", "world");  // hello world
ft_printf("%s", "");               // (empty string, prints nothing)
ft_printf("%s", NULL);             // (null) - safe NULL handling
```

**NULL handling:** Prints `(null)` when passed a NULL pointer (matching standard printf behavior).

---

### %p - Pointer

Prints pointer address in hexadecimal with `0x` prefix.

```c
int x = 42;
ft_printf("%p", &x);               // 0x7fff5fbff710 (example address)
ft_printf("%p", NULL);             // 0x0 (null pointer)

char *str = "hello";
ft_printf("%p", str);              // 0x10a5bf000 (string address)
```

**Format:** Always includes `0x` prefix and uses lowercase hexadecimal.

---

### %d and %i - Signed Integer

Print signed decimal integers. `%d` and `%i` are identical in printf (historical reasons).

```c
ft_printf("%d", 42);               // 42
ft_printf("%d", -42);              // -42
ft_printf("%d", 0);                // 0
ft_printf("%i", 2147483647);       // 2147483647 (INT_MAX)
ft_printf("%i", -2147483648);      // -2147483648 (INT_MIN)
```

---

### %u - Unsigned Integer

Print unsigned decimal integer.

```c
ft_printf("%u", 42);               // 42
ft_printf("%u", 0);                // 0
ft_printf("%u", 4294967295);       // 4294967295 (UINT_MAX)
ft_printf("%u", -1);               // 4294967295 (wraps around)
```

**Note:** Passing negative values causes wraparound (interpreted as large unsigned values).

---

### %x and %X - Hexadecimal

Print unsigned integer in hexadecimal (base 16).

```c
ft_printf("%x", 255);              // ff
ft_printf("%X", 255);              // FF
ft_printf("%x", 0);                // 0
ft_printf("%x", 16);               // 10
ft_printf("0x%x", 255);            // 0xff (manually add 0x prefix)
```

**Difference:**
- `%x`: Uses lowercase letters (a-f)
- `%X`: Uses uppercase letters (A-F)

**No 0x prefix:** Unlike `%p`, the `%x` and `%X` specifiers don't add `0x` prefix automatically. Add it manually if needed.

---

### %% - Literal Percent

Print a literal '%' character.

```c
ft_printf("%%");                   // %
ft_printf("100%%");                // 100%
ft_printf("%d%%", 50);             // 50%
```

---

## Basic Examples

### Simple Values

```c
ft_printf("Hello, World!\n");
// Hello, World!

ft_printf("Number: %d\n", 42);
// Number: 42

ft_printf("Char: %c, String: %s\n", 'A', "test");
// Char: A, String: test
```

### Multiple Values

```c
int x = 10;
int y = 20;
ft_printf("x=%d, y=%d, sum=%d\n", x, y, x + y);
// x=10, y=20, sum=30
```

### Addresses and Pointers

```c
int value = 42;
int *ptr = &value;
ft_printf("value=%d, address=%p, *ptr=%d\n", value, ptr, *ptr);
// value=42, address=0x7fff5fbff710, *ptr=42
```

### Hexadecimal Output

```c
ft_printf("Dec: %d, Hex: %x, HEX: %X\n", 255, 255, 255);
// Dec: 255, Hex: ff, HEX: FF

// RGB color
ft_printf("Color: #%X%X%X\n", 255, 128, 0);
// Color: #FF800
// (Note: would need padding for proper formatting)
```

---

## Advanced Usage

### Return Value

The return value is useful for tracking output length or detecting errors:

```c
int len;

len = ft_printf("Hello");          // len = 5
len = ft_printf("%d", 12345);      // len = 5
len = ft_printf("");               // len = 0
len = ft_printf("%c%c%c", 'a', 'b', 'c');  // len = 3
```

**Error handling:**
```c
int ret = ft_printf("test\n");
if (ret < 0)
{
    // Write error occurred
    return (ERROR);
}
```

### Debugging Output

```c
void debug_array(int *arr, int len)
{
    int i;

    ft_printf("[");
    i = 0;
    while (i < len)
    {
        ft_printf("%d", arr[i]);
        if (i < len - 1)
            ft_printf(", ");
        i++;
    }
    ft_printf("]\n");
}

// Usage
int nums[] = {1, 2, 3, 4, 5};
debug_array(nums, 5);
// [1, 2, 3, 4, 5]
```

### Formatted Tables

```c
void print_table(void)
{
    ft_printf("Dec\tHex\tChar\n");
    ft_printf("---\t---\t----\n");

    int i = 65;
    while (i <= 90)
    {
        ft_printf("%d\t%x\t%c\n", i, i, i);
        i++;
    }
}

// Output:
// Dec Hex Char
// --- --- ----
// 65  41  A
// 66  42  B
// ...
```

---

## Implementation Details

### How Variadic Functions Work

`ft_printf` uses `<stdarg.h>` to handle variable arguments:

```c
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);  // Initialize args
    // Process format string and extract arguments with va_arg()
    va_end(args);            // Cleanup

    return (count);
}
```

### Helper Functions

The implementation uses these internal helper functions (from includes/libft.h):

- `ft_print_char(int character)` - Print single character
- `ft_print_str(char *str)` - Print string (handles NULL)
- `ft_print_ptr(void *ptr)` - Print pointer with 0x prefix
- `ft_print_nbr(int number)` - Print signed integer
- `ft_print_unsigned(unsigned int number)` - Print unsigned integer
- `ft_print_hex(unsigned int n, int uppercase)` - Print hex

### Parsing Algorithm

1. Iterate through format string
2. Regular characters → print directly
3. '%' found → check next character:
   - 'c', 's', 'p', 'd', 'i', 'u', 'x', 'X' → extract arg and print
   - '%' → print literal '%'
   - Invalid → undefined behavior
4. Count total characters printed
5. Return count (or -1 on error)

---

## Differences from Standard printf

### Not Supported

The following standard printf features are **not implemented**:

- Field width: `%10d`, `%-5s`
- Precision: `%.2f`, `%.5s`
- Length modifiers: `%ld`, `%llu`, `%hd`
- Floating point: `%f`, `%e`, `%g`
- Special formats: `%n`, `%a`
- Flags: `%+d`, `% d`, `%#x`, `%0` `%08d`

### Simplified Behavior

- No padding or alignment
- No precision control
- Fixed output format for each type
- No locale support

**Example of unsupported:**
```c
// These don't work:
ft_printf("%10d", 42);    // Expects "        42", prints "%10d42"
ft_printf("%.2f", 3.14);  // Expects "3.14", prints "%.2f..."
```

---

## Performance Characteristics

| Operation | Calls to write() | Time Complexity |
|-----------|------------------|-----------------|
| Print char `%c` | 1 | O(1) |
| Print string `%s` | 1 | O(n) |
| Print number `%d` | O(log n) | O(log n) |
| Print pointer `%p` | O(1) + O(log n) | O(log n) |
| Print hex `%x` | O(log n) | O(log n) |

**Note:** Multiple write() calls for numbers makes it less efficient than standard printf for heavy numeric output.

---

## Common Usage Patterns

### Error Messages

```c
ft_printf("Error: %s\n", error_message);
ft_printf("Failed to open file: %s\n", filename);
```

### Debugging Variables

```c
ft_printf("x=%d, y=%d\n", x, y);
ft_printf("ptr=%p, value=%d\n", ptr, *ptr);
```

### Status Messages

```c
ft_printf("Processing %d/%d items...\n", current, total);
ft_printf("Success! Result: %d\n", result);
```

### Hex Dumps

```c
void print_hex_dump(unsigned char *data, int len)
{
    int i = 0;
    while (i < len)
    {
        ft_printf("%x ", data[i]);
        if ((i + 1) % 16 == 0)
            ft_printf("\n");
        i++;
    }
    if (len % 16 != 0)
        ft_printf("\n");
}
```

---

## Common Pitfalls

### Type Mismatches

```c
// WRONG: Type doesn't match specifier
ft_printf("%d", "hello");    // Undefined behavior
ft_printf("%s", 42);         // Crash

// WRONG: unsigned vs signed
unsigned int u = 42;
ft_printf("%d", u);          // Use %u for unsigned

// RIGHT: Match types
ft_printf("%s", "hello");
ft_printf("%u", 42u);
```

### Argument Count Mismatch

```c
// WRONG: Not enough arguments
ft_printf("%d %d", 42);      // Undefined behavior

// WRONG: Too many arguments
ft_printf("%d", 42, 100);    // Extra arg ignored (wasteful)

// RIGHT: Match count
ft_printf("%d %d", 42, 100);
```

### Forgetting Return Value

```c
// Could be checking for errors
ft_printf("test\n");

// Better for production code:
if (ft_printf("test\n") < 0)
    return (ERROR);
```

### NULL String

```c
char *str = NULL;
ft_printf("%s", str);        // Prints "(null)" - safe
// But check NULL before other operations:
if (str)
    ft_printf("Length: %d\n", ft_strlen(str));
```

---

## Related Functions

- [Output Functions](output.md) - Lower-level output (ft_putstr_fd, etc.)
- [Conversion Functions](conversion.md) - ft_itoa for number to string
- [String Functions](string.md) - String manipulation

---

## Examples

### Complete Program

```c
#include "libft.h"

int main(void)
{
    char *name = "Alice";
    int age = 25;
    int *ptr = &age;

    ft_printf("Name: %s\n", name);
    ft_printf("Age: %d\n", age);
    ft_printf("Address of age: %p\n", ptr);
    ft_printf("Value at pointer: %d\n", *ptr);
    ft_printf("Age in hex: %x\n", age);
    ft_printf("Done!\n");

    return (0);
}
```

Output:
```
Name: Alice
Age: 25
Address of age: 0x7fff5fbff710
Value at pointer: 25
Age in hex: 19
Done!
```

# Character Classification Functions

Character classification functions test whether a character belongs to a specific category. All functions return non-zero (true) if the test passes, zero (false) otherwise.

## Function Reference

| Function | Prototype | Description |
|----------|-----------|-------------|
| `ft_isalpha` | `int ft_isalpha(int c)` | Check if alphabetic character (a-z, A-Z) |
| `ft_isdigit` | `int ft_isdigit(int c)` | Check if decimal digit (0-9) |
| `ft_isalnum` | `int ft_isalnum(int c)` | Check if alphanumeric (a-z, A-Z, 0-9) |
| `ft_isascii` | `int ft_isascii(int c)` | Check if in ASCII range (0-127) |
| `ft_isprint` | `int ft_isprint(int c)` | Check if printable (space through ~) |

## Detailed Descriptions

### ft_isalpha

```c
int ft_isalpha(int c);
```

Tests if `c` is an alphabetic character.

**Returns:** Non-zero if `c` is in `[a-z]` or `[A-Z]`, zero otherwise.

**Example:**
```c
ft_isalpha('a');  // Non-zero (true)
ft_isalpha('Z');  // Non-zero (true)
ft_isalpha('5');  // 0 (false)
ft_isalpha(' ');  // 0 (false)
```

---

### ft_isdigit

```c
int ft_isdigit(int c);
```

Tests if `c` is a decimal digit.

**Returns:** Non-zero if `c` is in `[0-9]`, zero otherwise.

**Example:**
```c
ft_isdigit('0');  // Non-zero (true)
ft_isdigit('9');  // Non-zero (true)
ft_isdigit('a');  // 0 (false)
```

---

### ft_isalnum

```c
int ft_isalnum(int c);
```

Tests if `c` is alphanumeric (letter or digit).

**Returns:** Non-zero if `c` is in `[a-z]`, `[A-Z]`, or `[0-9]`, zero otherwise.

**Implementation note:** Equivalent to `ft_isalpha(c) || ft_isdigit(c)`.

**Example:**
```c
ft_isalnum('a');  // Non-zero (true)
ft_isalnum('5');  // Non-zero (true)
ft_isalnum('!');  // 0 (false)
```

---

### ft_isascii

```c
int ft_isascii(int c);
```

Tests if `c` is in the 7-bit ASCII character set (0-127).

**Returns:** Non-zero if `c` is in range [0, 127], zero otherwise.

**Note:** Unlike other functions, this returns true for all ASCII codes including control characters (0-31), not just printable ones.

**Example:**
```c
ft_isascii(0);    // Non-zero (true) - NUL character
ft_isascii('a');  // Non-zero (true)
ft_isascii(127);  // Non-zero (true) - DEL character
ft_isascii(200);  // 0 (false) - Extended ASCII
```

---

### ft_isprint

```c
int ft_isprint(int c);
```

Tests if `c` is a printable character, including space.

**Returns:** Non-zero if `c` is in range [32, 126] (space through tilde), zero otherwise.

**Note:** Space (32) is considered printable. Control characters and DEL (127) are not printable.

**Example:**
```c
ft_isprint('a');   // Non-zero (true)
ft_isprint(' ');   // Non-zero (true)
ft_isprint('\n');  // 0 (false) - newline is not printable
ft_isprint(127);   // 0 (false) - DEL is not printable
```

## Common Usage Patterns

### Input Validation

```c
int is_valid_identifier(const char *str)
{
    if (!str || !*str)
        return (0);

    // First character must be letter or underscore
    if (!ft_isalpha(*str) && *str != '_')
        return (0);

    // Rest can be alphanumeric or underscore
    str++;
    while (*str)
    {
        if (!ft_isalnum(*str) && *str != '_')
            return (0);
        str++;
    }
    return (1);
}
```

### Sanitizing Input

```c
void remove_non_printable(char *str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i])
    {
        if (ft_isprint(str[i]))
            str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
}
```

### Parsing Numbers

```c
int is_number(const char *str)
{
    // Skip leading whitespace
    while (*str == ' ' || *str == '\t')
        str++;

    // Optional sign
    if (*str == '+' || *str == '-')
        str++;

    // Must have at least one digit
    if (!ft_isdigit(*str))
        return (0);

    // All remaining must be digits
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (0);
        str++;
    }
    return (1);
}
```

## Implementation Notes

### Standard Behavior

These functions match the behavior of their standard library counterparts (`isalpha`, `isdigit`, etc.) defined in `<ctype.h>`.

### Parameter Type

All functions take an `int` parameter (not `char`) to handle `EOF` (-1) and extended character sets. The value is treated as an `unsigned char` internally for comparison.

### Return Values

- **Non-zero:** Condition is true (exact value may vary)
- **Zero:** Condition is false

**Do not rely on specific non-zero values.** Always treat return value as boolean:

```c
// Correct
if (ft_isdigit(c))
    // ...

// Wrong - don't rely on specific return value
if (ft_isdigit(c) == 1)
    // ...
```

## Related Functions

- [ft_toupper / ft_tolower](conversion.md#case-conversion) - Convert between uppercase and lowercase
- [ft_atoi](conversion.md#ft_atoi) - String to integer conversion (uses digit checking)

## ASCII Reference

| Range | Characters | ft_isprint | ft_isalpha | ft_isdigit | ft_isalnum |
|-------|------------|------------|------------|------------|------------|
| 0-31 | Control chars | ✗ | ✗ | ✗ | ✗ |
| 32 | Space | ✓ | ✗ | ✗ | ✗ |
| 33-47 | !"#$%&'()*+,-./ | ✓ | ✗ | ✗ | ✗ |
| 48-57 | 0-9 | ✓ | ✗ | ✓ | ✓ |
| 58-64 | :;<=>?@ | ✓ | ✗ | ✗ | ✗ |
| 65-90 | A-Z | ✓ | ✓ | ✗ | ✓ |
| 91-96 | [\]^_` | ✓ | ✗ | ✗ | ✗ |
| 97-122 | a-z | ✓ | ✓ | ✗ | ✓ |
| 123-126 | {|}~ | ✓ | ✗ | ✗ | ✗ |
| 127 | DEL | ✗ | ✗ | ✗ | ✗ |

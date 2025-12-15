# Conversion Functions

Functions for converting between different data representations: string to integer, integer to string, and case conversion.

## Function Reference

| Function | Description |
|----------|-------------|
| `ft_atoi(str)` | Convert string to integer |
| `ft_itoa(n)` | Convert integer to string (malloc) |
| `ft_toupper(c)` | Convert to uppercase |
| `ft_tolower(c)` | Convert to lowercase |

---

## String to Integer

### ft_atoi

```c
int ft_atoi(const char *str);
```

Convert the initial portion of a string to an integer.

**Parameters:**
- `str`: String to convert

**Returns:** Integer value represented by the string.

**Behavior:**
1. Skips leading whitespace (space, tab, newline, etc.)
2. Handles optional '+' or '-' sign
3. Converts consecutive digits
4. Stops at first non-digit character

**Example:**
```c
ft_atoi("42");           // 42
ft_atoi("   -42");       // -42
ft_atoi("+123");         // 123
ft_atoi("  \t\n 42");    // 42
ft_atoi("42abc");        // 42 (stops at 'a')
ft_atoi("abc");          // 0 (no digits)
ft_atoi("");             // 0 (empty string)
```

**Whitespace handling:**
```c
ft_atoi(" \t\n\v\f\r 42");  // 42 (skips all whitespace)
```

**Sign handling:**
```c
ft_atoi("-42");    // -42
ft_atoi("+42");    // 42
ft_atoi("--42");   // 0 (stops at second '-')
ft_atoi("+-42");   // 0 (stops at second sign)
```

**Edge cases:**
```c
ft_atoi("2147483647");   // INT_MAX (2147483647)
ft_atoi("-2147483648");  // INT_MIN (-2147483648)
ft_atoi("9999999999");   // Undefined (overflow)
```

**Note:** Overflow behavior is undefined. For large numbers, validate input length first.

---

## Integer to String

### ft_itoa

```c
char *ft_itoa(int n);
```

Convert an integer to a string representation.

**Parameters:**
- `n`: Integer to convert

**Returns:** Newly allocated string representing the integer, or NULL on failure.

**Note:** Caller must free the returned string.

**Example:**
```c
char *s;

s = ft_itoa(42);           // "42"
free(s);
s = ft_itoa(-42);          // "-42"
free(s);
s = ft_itoa(0);            // "0"
free(s);
s = ft_itoa(2147483647);   // "2147483647" (INT_MAX)
free(s);
s = ft_itoa(-2147483648);  // "-2147483648" (INT_MIN)
free(s);
```

**Usage pattern:**
```c
char *str = ft_itoa(value);
if (!str)
    return (ERROR);  // Handle allocation failure
ft_printf("Value: %s\n", str);
free(str);
```

---

## Case Conversion

### ft_toupper

```c
int ft_toupper(int c);
```

Convert lowercase letter to uppercase.

**Parameters:**
- `c`: Character to convert

**Returns:**
- Uppercase equivalent if `c` is lowercase letter (a-z)
- `c` unchanged otherwise

**Example:**
```c
ft_toupper('a');  // 'A'
ft_toupper('z');  // 'Z'
ft_toupper('A');  // 'A' (already uppercase)
ft_toupper('5');  // '5' (not a letter)
ft_toupper(' ');  // ' ' (not a letter)
```

---

### ft_tolower

```c
int ft_tolower(int c);
```

Convert uppercase letter to lowercase.

**Parameters:**
- `c`: Character to convert

**Returns:**
- Lowercase equivalent if `c` is uppercase letter (A-Z)
- `c` unchanged otherwise

**Example:**
```c
ft_tolower('A');  // 'a'
ft_tolower('Z');  // 'z'
ft_tolower('a');  // 'a' (already lowercase)
ft_tolower('5');  // '5' (not a letter)
ft_tolower(' ');  // ' ' (not a letter)
```

---

## Common Usage Patterns

### String to Integer with Validation

```c
int parse_int(const char *str, int *out)
{
    int i = 0;

    // Skip whitespace
    while (str[i] == ' ' || str[i] == '\t')
        i++;

    // Check for sign
    if (str[i] == '-' || str[i] == '+')
        i++;

    // Must have at least one digit
    if (!ft_isdigit(str[i]))
        return (0);  // Invalid

    // All remaining characters must be digits
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);  // Invalid
        i++;
    }

    *out = ft_atoi(str);
    return (1);  // Success
}
```

### Integer to String with Buffer

```c
void print_number(int n)
{
    char *str = ft_itoa(n);
    if (!str)
    {
        ft_printf("Error: allocation failed\n");
        return;
    }
    ft_printf("%s\n", str);
    free(str);
}
```

### Case-Insensitive Comparison

```c
int strcasecmp(const char *s1, const char *s2)
{
    while (*s1 && *s2)
    {
        if (ft_tolower(*s1) != ft_tolower(*s2))
            return (ft_tolower(*s1) - ft_tolower(*s2));
        s1++;
        s2++;
    }
    return (ft_tolower(*s1) - ft_tolower(*s2));
}
```

### String to Uppercase (In-Place)

```c
void str_toupper(char *s)
{
    while (*s)
    {
        *s = ft_toupper(*s);
        s++;
    }
}
```

### String to Lowercase (Allocating)

```c
char *str_tolower_dup(const char *s)
{
    char *result;
    int i;

    result = ft_strdup(s);
    if (!result)
        return (NULL);

    i = 0;
    while (result[i])
    {
        result[i] = ft_tolower(result[i]);
        i++;
    }
    return (result);
}
```

### Number Formatting

```c
char *format_number_with_sign(int n)
{
    char *num_str;
    char *result;

    num_str = ft_itoa(n);
    if (!num_str)
        return (NULL);

    if (n >= 0)
        result = ft_strjoin("+", num_str);
    else
        result = ft_strdup(num_str);  // Already has '-'

    free(num_str);
    return (result);
}
```

## Implementation Notes

### ft_atoi Behavior

The function mimics standard `atoi` behavior:
- Returns 0 for invalid input (no way to distinguish from actual "0")
- Overflow is undefined
- Stops at first non-digit after optional sign

**Limitations:**
- No error reporting mechanism
- No overflow detection
- Limited to base 10

**For robust parsing, consider:**
```c
int safe_atoi(const char *str, int *out)
{
    int i = 0;
    long result = 0;
    int sign = 1;

    // Skip whitespace
    while (str[i] == ' ' || str[i] == '\t')
        i++;

    // Handle sign
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;

    // Must have digits
    if (!ft_isdigit(str[i]))
        return (0);

    // Convert with overflow check
    while (ft_isdigit(str[i]))
    {
        result = result * 10 + (str[i] - '0');
        if (result * sign > INT_MAX || result * sign < INT_MIN)
            return (0);  // Overflow
        i++;
    }

    // Check for trailing garbage
    if (str[i] != '\0')
        return (0);

    *out = (int)(result * sign);
    return (1);
}
```

### ft_itoa Implementation

The function must handle:
- Negative numbers (including INT_MIN: -2147483648)
- Sign character
- Null termination
- Dynamic allocation

**Memory requirement:**
- Max digits in int: 10 (for 2147483647)
- Sign character: 1
- Null terminator: 1
- **Total: 12 bytes maximum**

### Case Conversion

These functions work only on ASCII letters:
- `ft_toupper`: 'a'-'z' → 'A'-'Z' (subtract 32)
- `ft_tolower`: 'A'-'Z' → 'a'-'z' (add 32)

**Not locale-aware:**
- Doesn't handle accented characters (é, ñ, etc.)
- Works only with basic ASCII letters

## Performance

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| `ft_atoi` | O(n) | O(1) |
| `ft_itoa` | O(log₁₀ n) | O(log₁₀ n) |
| `ft_toupper` | O(1) | O(1) |
| `ft_tolower` | O(1) | O(1) |

Where n is the input value/string length.

## Common Pitfalls

### atoi Returns 0 on Error

```c
// Can't distinguish error from actual zero
int val = ft_atoi("not a number");  // Returns 0
int zero = ft_atoi("0");            // Also returns 0

// Use validation function for production code
```

### Forgetting to Free itoa Result

```c
// WRONG: Memory leak
ft_printf("%s\n", ft_itoa(42));  // Leaks memory

// RIGHT: Store and free
char *s = ft_itoa(42);
if (s)
{
    ft_printf("%s\n", s);
    free(s);
}
```

### Case Conversion on Non-Letters

```c
// These do nothing (but are safe)
ft_toupper('5');  // Returns '5'
ft_tolower('!');  // Returns '!'

// Only converts letters
```

## Related Functions

- [Character Classification](character.md#ft_isdigit) - For validating digits
- [String Functions](string.md) - For string manipulation
- [Printf](printf.md) - For formatted number output

# String Functions

Comprehensive string manipulation functions covering inspection, searching, copying, transformation, and splitting operations.

## Quick Reference

### Inspection
| Function | Description |
|----------|-------------|
| `ft_strlen(s)` | Get string length |

### Searching
| Function | Description |
|----------|-------------|
| `ft_strchr(s, c)` | Find first occurrence of character |
| `ft_strrchr(s, c)` | Find last occurrence of character |
| `ft_strnstr(haystack, needle, len)` | Find substring (bounded) |
| `ft_strncmp(s1, s2, n)` | Compare strings (bounded) |

### Copying and Concatenation
| Function | Description |
|----------|-------------|
| `ft_strlcpy(dst, src, size)` | Safe string copy |
| `ft_strlcat(dst, src, size)` | Safe string concatenation |
| `ft_strdup(s)` | Duplicate string (malloc) |

### Transformation (Allocating)
| Function | Description |
|----------|-------------|
| `ft_substr(s, start, len)` | Extract substring |
| `ft_strjoin(s1, s2)` | Concatenate two strings |
| `ft_strtrim(s1, set)` | Trim characters from both ends |
| `ft_split(s, c)` | Split string by delimiter |
| `ft_strmapi(s, f)` | Map function over string |
| `ft_striteri(s, f)` | Apply function in-place |

---

## Inspection Functions

### ft_strlen

```c
size_t ft_strlen(const char *s);
```

Calculate the length of a string (number of characters before '\0').

**Parameters:**
- `s`: Null-terminated string

**Returns:** Number of characters before the null terminator.

**Example:**
```c
ft_strlen("hello");      // 5
ft_strlen("");           // 0
ft_strlen("42");         // 2
```

---

## Searching Functions

### ft_strchr

```c
char *ft_strchr(const char *s, int c);
```

Locate the first occurrence of character `c` in string `s`.

**Parameters:**
- `s`: String to search
- `c`: Character to find (converted to char)

**Returns:** Pointer to first occurrence of `c`, or NULL if not found.

**Note:** The terminating null byte is considered part of the string; searching for '\0' returns a pointer to the terminator.

**Example:**
```c
char *str = "hello world";
char *ptr = ft_strchr(str, 'o');    // Points to first 'o' in "hello"
char *end = ft_strchr(str, '\0');   // Points to null terminator
char *miss = ft_strchr(str, 'x');   // NULL
```

---

### ft_strrchr

```c
char *ft_strrchr(const char *s, int c);
```

Locate the last occurrence of character `c` in string `s`.

**Parameters:**
- `s`: String to search
- `c`: Character to find (converted to char)

**Returns:** Pointer to last occurrence of `c`, or NULL if not found.

**Example:**
```c
char *str = "hello world";
char *ptr = ft_strrchr(str, 'o');   // Points to 'o' in "world"
```

---

### ft_strnstr

```c
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
```

Locate substring `needle` in string `haystack`, searching at most `len` characters.

**Parameters:**
- `haystack`: String to search in
- `needle`: Substring to find
- `len`: Maximum number of characters to search

**Returns:**
- Pointer to start of `needle` in `haystack`
- `haystack` if `needle` is empty
- NULL if `needle` not found within `len` characters

**Example:**
```c
char *str = "hello world";
ft_strnstr(str, "wor", 11);    // Points to "world"
ft_strnstr(str, "wor", 7);     // NULL (search stops before "world")
ft_strnstr(str, "", 5);        // Points to str (empty needle)
```

---

### ft_strncmp

```c
int ft_strncmp(const char *s1, const char *s2, size_t n);
```

Compare at most `n` bytes of two strings.

**Parameters:**
- `s1`, `s2`: Strings to compare
- `n`: Maximum number of characters to compare

**Returns:**
- `< 0` if s1 < s2
- `0` if s1 == s2 (up to n characters)
- `> 0` if s1 > s2

**Note:** Comparison stops at first difference or null terminator, whichever comes first.

**Example:**
```c
ft_strncmp("hello", "hello", 5);    // 0
ft_strncmp("hello", "world", 5);    // < 0
ft_strncmp("abc", "ab", 2);         // 0 (only compares 2 chars)
ft_strncmp("abc", "ab", 3);         // > 0 ('c' vs '\0')
```

---

## Copying and Concatenation Functions

### ft_strlcpy

```c
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
```

Copy string to a sized buffer, guaranteeing null-termination.

**Parameters:**
- `dst`: Destination buffer
- `src`: Source string
- `dstsize`: Size of destination buffer (including space for '\0')

**Returns:** Total length of `src` (for truncation detection).

**Behavior:**
- Copies up to `dstsize - 1` characters from `src` to `dst`
- Always null-terminates if `dstsize > 0`
- If return value >= `dstsize`, truncation occurred

**Example:**
```c
char buf[10];
size_t len;

len = ft_strlcpy(buf, "hello", sizeof(buf));  // len = 5, buf = "hello"
len = ft_strlcpy(buf, "hello world", sizeof(buf));  // len = 11, buf = "hello wor"

// Detect truncation
if (len >= sizeof(buf))
    // String was truncated
```

---

### ft_strlcat

```c
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
```

Append string to a sized buffer, guaranteeing null-termination.

**Parameters:**
- `dst`: Destination buffer (must be null-terminated)
- `src`: Source string to append
- `dstsize`: Total size of destination buffer

**Returns:** Total length of string it tried to create (initial length of `dst` + length of `src`).

**Behavior:**
- Appends `src` to `dst`, leaving room for null terminator
- If return value >= `dstsize`, truncation occurred

**Example:**
```c
char buf[20] = "hello";
size_t len;

len = ft_strlcat(buf, " world", sizeof(buf));  // len = 11, buf = "hello world"
```

---

### ft_strdup

```c
char *ft_strdup(const char *s1);
```

Allocate and duplicate a string.

**Parameters:**
- `s1`: String to duplicate

**Returns:** Newly allocated copy of `s1`, or NULL on allocation failure.

**Note:** Caller must free the returned string.

**Example:**
```c
char *original = "hello";
char *copy = ft_strdup(original);
if (copy)
{
    ft_printf("%s\n", copy);
    free(copy);
}
```

---

## Transformation Functions

These functions allocate new strings. Caller must free the returned values.

### ft_substr

```c
char *ft_substr(char const *s, unsigned int start, size_t len);
```

Extract a substring from a string.

**Parameters:**
- `s`: Source string
- `start`: Starting index
- `len`: Maximum length of substring

**Returns:** Newly allocated substring, or NULL on failure.

**Behavior:**
- If `start` >= length of `s`, returns empty string
- If `len` exceeds remaining string, returns substring until end

**Example:**
```c
char *s = "hello world";
char *sub;

sub = ft_substr(s, 0, 5);      // "hello"
free(sub);
sub = ft_substr(s, 6, 5);      // "world"
free(sub);
sub = ft_substr(s, 6, 100);    // "world" (clamped to end)
free(sub);
sub = ft_substr(s, 100, 5);    // "" (empty string)
free(sub);
```

---

### ft_strjoin

```c
char *ft_strjoin(char const *s1, char const *s2);
```

Concatenate two strings into a new string.

**Parameters:**
- `s1`: First string
- `s2`: Second string

**Returns:** Newly allocated string containing `s1` + `s2`, or NULL on failure.

**Example:**
```c
char *result = ft_strjoin("hello", " world");
ft_printf("%s\n", result);  // "hello world"
free(result);
```

---

### ft_strtrim

```c
char *ft_strtrim(char const *s1, char const *set);
```

Remove characters in `set` from beginning and end of string.

**Parameters:**
- `s1`: String to trim
- `set`: Characters to remove

**Returns:** Newly allocated trimmed string, or NULL on failure.

**Example:**
```c
char *result;

result = ft_strtrim("   hello   ", " ");        // "hello"
free(result);
result = ft_strtrim("xxxhelloxxx", "x");        // "hello"
free(result);
result = ft_strtrim("  \t\nhello\n\t  ", " \t\n");  // "hello"
free(result);
```

---

### ft_split

```c
char **ft_split(char const *s, char c);
```

Split string by delimiter into array of strings.

**Parameters:**
- `s`: String to split
- `c`: Delimiter character

**Returns:** Null-terminated array of strings, or NULL on failure.

**Note:**
- Consecutive delimiters produce no empty strings
- Caller must free each string and the array itself

**Example:**
```c
char **words = ft_split("hello world foo bar", ' ');
int i = 0;

while (words[i])
{
    ft_printf("%s\n", words[i]);
    free(words[i]);
    i++;
}
free(words);

// Output:
// hello
// world
// foo
// bar
```

**Multiple delimiters:**
```c
char **words = ft_split("hello...world", '.');
// words = ["hello", "world", NULL]
// (no empty strings from consecutive dots)
```

---

### ft_strmapi

```c
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
```

Apply function to each character, creating a new string.

**Parameters:**
- `s`: Source string
- `f`: Function taking index and character, returning new character

**Returns:** Newly allocated transformed string, or NULL on failure.

**Example:**
```c
char capitalize_even(unsigned int i, char c)
{
    if (i % 2 == 0 && c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

char *result = ft_strmapi("hello", capitalize_even);
ft_printf("%s\n", result);  // "HeLlO"
free(result);
```

---

### ft_striteri

```c
void ft_striteri(char *s, void (*f)(unsigned int, char *));
```

Apply function to each character in-place.

**Parameters:**
- `s`: String to modify
- `f`: Function taking index and pointer to character

**Example:**
```c
void uppercase_even(unsigned int i, char *c)
{
    if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
        *c -= 32;
}

char str[] = "hello";
ft_striteri(str, uppercase_even);
ft_printf("%s\n", str);  // "HeLlO"
```

---

## Common Usage Patterns

### Safe String Building

```c
char buffer[100];
ft_strlcpy(buffer, "Error: ", sizeof(buffer));
ft_strlcat(buffer, error_msg, sizeof(buffer));
ft_strlcat(buffer, "\n", sizeof(buffer));
```

### Path Joining

```c
char *join_path(const char *dir, const char *file)
{
    char *slash;
    char *result;

    slash = ft_strjoin(dir, "/");
    if (!slash)
        return (NULL);
    result = ft_strjoin(slash, file);
    free(slash);
    return (result);
}
```

### Parsing CSV

```c
char **parse_csv(const char *line)
{
    return (ft_split(line, ','));
}

void free_csv(char **fields)
{
    int i = 0;
    while (fields[i])
        free(fields[i++]);
    free(fields);
}
```

### String Replacement

```c
char *replace_char(const char *s, char old, char new)
{
    char replace(unsigned int i, char c)
    {
        (void)i;
        return (c == old ? new : c);
    }
    return (ft_strmapi(s, replace));
}
```

## Memory Management

### Functions That Allocate

These functions return newly allocated memory that **must be freed**:
- `ft_strdup`
- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_split` (free each string AND the array)
- `ft_strmapi`

### Functions That Don't Allocate

These functions work with existing memory:
- `ft_strlen`
- `ft_strchr` / `ft_strrchr` (return pointers into existing string)
- `ft_strnstr` (returns pointer into existing string)
- `ft_strncmp`
- `ft_strlcpy` / `ft_strlcat`
- `ft_striteri`

## Performance Notes

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| `ft_strlen` | O(n) | O(1) |
| `ft_strchr` | O(n) | O(1) |
| `ft_strncmp` | O(n) | O(1) |
| `ft_strnstr` | O(n*m) | O(1) |
| `ft_strdup` | O(n) | O(n) |
| `ft_strjoin` | O(n+m) | O(n+m) |
| `ft_split` | O(n) | O(n) |

## Related Functions

- [Character Classification](character.md) - For character testing
- [Memory Functions](memory.md) - For byte-level operations
- [Conversion Functions](conversion.md) - For atoi/itoa

# Memory Functions

Low-level memory operations for copying, comparing, searching, and allocating memory. These functions work with raw bytes and don't assume null-terminated strings.

## Function Reference

| Function | Description |
|----------|-------------|
| `ft_memset(b, c, len)` | Fill memory with constant byte |
| `ft_bzero(s, n)` | Zero out memory |
| `ft_memcpy(dst, src, n)` | Copy memory (non-overlapping) |
| `ft_memmove(dst, src, len)` | Copy memory (handles overlaps) |
| `ft_memchr(s, c, n)` | Find byte in memory |
| `ft_memcmp(s1, s2, n)` | Compare memory regions |
| `ft_calloc(count, size)` | Allocate zero-initialized memory |

---

## Detailed Descriptions

### ft_memset

```c
void *ft_memset(void *b, int c, size_t len);
```

Fill `len` bytes of memory with constant byte `c`.

**Parameters:**
- `b`: Pointer to memory area
- `c`: Byte value to fill (converted to unsigned char)
- `len`: Number of bytes to fill

**Returns:** Pointer to `b`.

**Example:**
```c
char buffer[10];
ft_memset(buffer, 'A', sizeof(buffer));  // All 10 bytes set to 'A'
ft_memset(buffer, 0, sizeof(buffer));    // Zero out buffer
```

**Common uses:**
- Initialize arrays/buffers
- Clear sensitive data
- Set memory patterns for debugging

---

### ft_bzero

```c
void ft_bzero(void *s, size_t n);
```

Zero out `n` bytes of memory.

**Parameters:**
- `s`: Pointer to memory area
- `n`: Number of bytes to zero

**Returns:** Nothing (void).

**Note:** Equivalent to `ft_memset(s, 0, n)` but with void return type.

**Example:**
```c
struct s_data data;
ft_bzero(&data, sizeof(data));  // Zero-initialize struct

int arr[100];
ft_bzero(arr, sizeof(arr));     // Zero-initialize array
```

---

### ft_memcpy

```c
void *ft_memcpy(void *dst, const void *src, size_t n);
```

Copy `n` bytes from `src` to `dst`.

**Parameters:**
- `dst`: Destination buffer
- `src`: Source buffer
- `n`: Number of bytes to copy

**Returns:** Pointer to `dst`.

**IMPORTANT:** Behavior is undefined if `src` and `dst` overlap. Use `ft_memmove` for overlapping regions.

**Example:**
```c
char src[] = "hello";
char dst[6];
ft_memcpy(dst, src, 6);  // Copy including null terminator

int numbers[] = {1, 2, 3, 4, 5};
int copy[5];
ft_memcpy(copy, numbers, sizeof(numbers));
```

---

### ft_memmove

```c
void *ft_memmove(void *dst, const void *src, size_t len);
```

Copy `len` bytes from `src` to `dst`, handling overlapping regions correctly.

**Parameters:**
- `dst`: Destination buffer
- `src`: Source buffer
- `len`: Number of bytes to copy

**Returns:** Pointer to `dst`.

**Implementation detail:** Copies backwards if regions overlap and `dst > src`, forwards otherwise.

**Example:**
```c
char str[] = "hello world";

// Shift string right by 2 (overlapping regions)
ft_memmove(str + 2, str, 9);  // "hehello wor"

// Safe for all cases (even where memcpy would fail)
ft_memmove(str, str + 2, 9);  // "hello wor"
```

**When to use:**
- `ft_memcpy`: Source and destination don't overlap (faster)
- `ft_memmove`: Regions might overlap (safer)

---

### ft_memchr

```c
void *ft_memchr(const void *s, int c, size_t n);
```

Scan `n` bytes of memory for first occurrence of byte `c`.

**Parameters:**
- `s`: Memory area to search
- `c`: Byte to find (converted to unsigned char)
- `n`: Number of bytes to search

**Returns:** Pointer to first occurrence of `c`, or NULL if not found.

**Example:**
```c
char data[] = "hello\0world";  // Contains embedded null
char *ptr;

ptr = ft_memchr(data, 'o', 11);     // Points to first 'o' in "hello"
ptr = ft_memchr(data, '\0', 11);    // Points to embedded null at index 5
ptr = ft_memchr(data, 'w', 11);     // Points to 'w' in "world"

// Unlike strchr, memchr works with embedded nulls
ptr = ft_memchr(data, 'w', 5);      // NULL (only searches first 5 bytes)
```

**Difference from ft_strchr:**
- `ft_memchr`: Searches exactly `n` bytes (works with binary data)
- `ft_strchr`: Stops at first null terminator (for strings only)

---

### ft_memcmp

```c
int ft_memcmp(const void *s1, const void *s2, size_t n);
```

Compare `n` bytes of two memory regions.

**Parameters:**
- `s1`: First memory area
- `s2`: Second memory area
- `n`: Number of bytes to compare

**Returns:**
- `< 0` if s1 < s2
- `0` if s1 == s2 (first n bytes)
- `> 0` if s1 > s2

**Note:** Compares bytes as unsigned char.

**Example:**
```c
char a[] = "abc";
char b[] = "abc";
char c[] = "abd";

ft_memcmp(a, b, 3);  // 0 (equal)
ft_memcmp(a, c, 3);  // < 0 ('c' < 'd')
ft_memcmp(a, b, 2);  // 0 (first 2 bytes match)
```

**Binary data:**
```c
int nums1[] = {1, 2, 3};
int nums2[] = {1, 2, 4};
ft_memcmp(nums1, nums2, sizeof(nums1));  // < 0
```

**Difference from ft_strncmp:**
- `ft_memcmp`: Compares exactly `n` bytes (works with binary data)
- `ft_strncmp`: Stops at null terminator (for strings only)

---

### ft_calloc

```c
void *ft_calloc(size_t count, size_t size);
```

Allocate memory for `count` elements of `size` bytes each, initialized to zero.

**Parameters:**
- `count`: Number of elements
- `size`: Size of each element in bytes

**Returns:** Pointer to allocated memory, or NULL on failure.

**Note:** Caller must free the returned memory.

**Example:**
```c
// Allocate array of 10 integers, all set to 0
int *arr = ft_calloc(10, sizeof(int));
if (!arr)
    return (NULL);
// arr[0] through arr[9] are all 0
free(arr);

// Allocate single struct, zero-initialized
struct s_data *data = ft_calloc(1, sizeof(struct s_data));
if (!data)
    return (NULL);
free(data);
```

**Difference from malloc:**
```c
// These are equivalent:
void *mem1 = ft_calloc(n, size);

void *mem2 = malloc(n * size);
if (mem2)
    ft_bzero(mem2, n * size);
```

---

## Common Usage Patterns

### Buffer Initialization

```c
char buffer[1024];
ft_bzero(buffer, sizeof(buffer));  // Clear before use
```

### Struct Copying

```c
struct s_point {
    int x;
    int y;
};

struct s_point src = {10, 20};
struct s_point dst;

ft_memcpy(&dst, &src, sizeof(struct s_point));
```

### Array Shifting

```c
void remove_element(int *arr, size_t len, size_t index)
{
    if (index < len - 1)
    {
        // Shift elements left (overlapping regions)
        ft_memmove(&arr[index], &arr[index + 1],
                   (len - index - 1) * sizeof(int));
    }
}
```

### Safe String Copy

```c
void safe_copy(char *dst, const char *src, size_t dst_size)
{
    size_t len = ft_strlen(src);
    if (len >= dst_size)
        len = dst_size - 1;
    ft_memcpy(dst, src, len);
    dst[len] = '\0';
}
```

### Checking for Binary Pattern

```c
int has_null_byte(const void *data, size_t len)
{
    return (ft_memchr(data, 0, len) != NULL);
}
```

## Implementation Notes

### memcpy vs memmove

**ft_memcpy** is optimized for non-overlapping regions and may be faster:
```c
// Safe with memcpy (no overlap)
char src[10], dst[10];
ft_memcpy(dst, src, sizeof(src));
```

**ft_memmove** handles all cases, including overlaps:
```c
// ONLY safe with memmove (regions overlap)
char buf[20] = "hello";
ft_memmove(buf + 2, buf, 5);  // Shift right
```

**Rule of thumb:**
- Known non-overlapping: Use `ft_memcpy` (potentially faster)
- Might overlap: Use `ft_memmove` (always safe)
- Not sure: Use `ft_memmove` (safe default)

### Performance

| Operation | Time Complexity | Notes |
|-----------|-----------------|-------|
| `ft_memset` | O(n) | Single byte write, highly optimized |
| `ft_bzero` | O(n) | Equivalent to memset(0) |
| `ft_memcpy` | O(n) | Fast, assumes no overlap |
| `ft_memmove` | O(n) | Safe for overlaps, may be slower |
| `ft_memchr` | O(n) | Linear search |
| `ft_memcmp` | O(n) | Stops at first difference |
| `ft_calloc` | O(n) | malloc + memset(0) |

### Endianness

These functions work at the byte level and are endian-safe for byte arrays. Be careful when using with multi-byte types:

```c
int a = 0x12345678;
int b = 0x12345678;

// This works (compares bytes as-is, endian-safe)
ft_memcmp(&a, &b, sizeof(int));

// But beware when interpreting results across platforms
```

## Common Pitfalls

### Size Confusion

```c
int arr[10];

// WRONG: sizeof(arr) is 40 bytes (10 * 4), not 10
ft_bzero(arr, sizeof(arr[0]) * 10);  // Wrong

// RIGHT: Use full array size
ft_bzero(arr, sizeof(arr));  // Correct
```

### Overlapping Regions

```c
char buf[] = "hello";

// WRONG: memcpy with overlap (undefined behavior)
ft_memcpy(buf + 1, buf, 4);  // DON'T DO THIS

// RIGHT: Use memmove for overlaps
ft_memmove(buf + 1, buf, 4);  // Safe
```

### NULL Pointers

```c
// Always check calloc result
int *arr = ft_calloc(100, sizeof(int));
if (!arr)
    return (ERROR);  // Handle allocation failure
```

## Related Functions

- [String Functions](string.md) - For null-terminated strings
- [Data Structures](../data-structures/vector.md) - Higher-level memory management

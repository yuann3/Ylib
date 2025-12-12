# nob.h Inspired Additions (Norminette Compatible)

More utilities from Tsoding's nob.h that work within norm constraints.

---

## 1. ft_sv - String View (Non-owning Slice)

**What:** A pointer + length pair that references existing string data without copying.

**Why:** Zero-allocation string parsing. Chop, trim, compare without malloc.

```c
typedef struct s_sv
{
    const char  *data;
    size_t      len;
}   t_sv;
```

**Functions:**
```c
t_sv    ft_sv_from_cstr(const char *s);         // wrap null-terminated
t_sv    ft_sv_from_parts(const char *s, size_t len);
t_sv    ft_sv_chop_by_delim(t_sv *sv, char c);  // split at delimiter
t_sv    ft_sv_chop_left(t_sv *sv, size_t n);    // take n chars from left
t_sv    ft_sv_trim(t_sv sv);                    // remove whitespace
t_sv    ft_sv_trim_left(t_sv sv);
t_sv    ft_sv_trim_right(t_sv sv);
int     ft_sv_eq(t_sv a, t_sv b);               // compare
int     ft_sv_starts_with(t_sv sv, t_sv prefix);
int     ft_sv_ends_with(t_sv sv, const char *suffix);
char    *ft_sv_to_cstr(t_sv sv);                // allocate copy (only when needed)
```

**Usage - Parsing without allocation:**
```c
t_sv    line;
t_sv    token;

line = ft_sv_from_cstr("hello,world,foo");
while (line.len > 0)
{
    token = ft_sv_chop_by_delim(&line, ',');
    // token now points to "hello", then "world", then "foo"
    // no malloc happened!
}
```

**Norm-safe:** Simple struct, functions under 25 lines.

---

## 2. ft_defer Pattern (return_defer)

**What:** Structured cleanup using goto.

**Why:** Prevents resource leaks in functions with multiple exit points.

**Pattern:**
```c
int some_function(void)
{
    int     result;
    char    *buf;
    int     fd;

    result = 0;
    buf = NULL;
    fd = -1;
    
    buf = malloc(100);
    if (!buf)
        return (-1);  // early return ok, nothing to clean
    
    fd = open("file", O_RDONLY);
    if (fd < 0)
    {
        result = -1;
        goto defer;   // jump to cleanup
    }
    
    // ... do work ...
    
    result = 1;
defer:
    if (buf)
        free(buf);
    if (fd >= 0)
        close(fd);
    return (result);
}
```

**Norm note:** `goto` is allowed in norminette! This is legitimate structured use.

---

## 3. ft_read_file / ft_write_file

**What:** Read/write entire file in one call.

**Why:** Super common operation, tedious to write every time.

```c
// Returns malloc'd buffer, sets *size. Returns NULL on error.
char    *ft_read_file(const char *path, size_t *size);

// Returns 1 on success, 0 on failure
int     ft_write_file(const char *path, const void *data, size_t size);
```

**Implementation notes:**
- Use `fseek`/`ftell` or `stat` to get size
- Single `malloc` + single `read`
- Handle partial reads in a loop

---

## 4. ft_log - Logging Utility

**What:** Leveled logging with file/line info.

```c
typedef enum e_log_level
{
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_DEBUG
}   t_log_level;

void    ft_log(t_log_level level, const char *fmt, ...);
```

**Macro wrapper for auto file/line:**
```c
#define FT_INFO(fmt, ...) \
    ft_log_internal(LOG_INFO, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define FT_ERROR(fmt, ...) \
    ft_log_internal(LOG_ERROR, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
```

**Output:**
```
[INFO] main.c:42: Starting program
[ERROR] parser.c:128: Unexpected token
```

**Norm note:** Variadic macros are fine, `##__VA_ARGS__` handles zero args.

---

## 5. ft_shift - Argument Shifting

**What:** Pop first element from argc/argv style arrays.

**Why:** Clean command-line parsing.

```c
// Returns first arg and advances pointer
char    *ft_shift(int *argc, char ***argv);
```

**Usage:**
```c
int main(int argc, char **argv)
{
    char *program;
    char *cmd;
    
    program = ft_shift(&argc, &argv);  // skip program name
    if (argc == 0)
        return (ft_error("no command"), 1);
    cmd = ft_shift(&argc, &argv);
    if (ft_strcmp(cmd, "build") == 0)
        return (do_build(argc, argv));
    // ...
}
```

---

## 6. ft_path - Path Manipulation

**What:** Cross-platform path building and parsing.

```c
// Join paths: ft_path_join("dir", "file.c") -> "dir/file.c"
char    *ft_path_join(const char *base, const char *name);

// Get filename: "/path/to/file.c" -> "file.c"
const char  *ft_path_name(const char *path);

// Get directory: "/path/to/file.c" -> "/path/to"
char    *ft_path_dir(const char *path);

// Get extension: "file.c" -> "c"
const char  *ft_path_ext(const char *path);

// Check existence
int     ft_path_exists(const char *path);
int     ft_path_is_dir(const char *path);
```

---

## 7. ft_temp - Temporary Allocator

**What:** Static buffer for short-lived allocations.

**Why:** Avoid malloc for temporary strings (paths, formatted output).

```c
#define FT_TEMP_CAP 8192

// Allocate from temp buffer (resets on ft_temp_reset)
void    *ft_temp_alloc(size_t size);

// Reset temp buffer (call at frame/iteration boundary)
void    ft_temp_reset(void);

// Convenience: duplicate string to temp storage
char    *ft_temp_strdup(const char *s);

// Convenience: sprintf to temp storage  
char    *ft_temp_sprintf(const char *fmt, ...);
```

**Implementation:**
```c
static char g_temp_buffer[FT_TEMP_CAP];
static size_t g_temp_offset = 0;

void    *ft_temp_alloc(size_t size)
{
    void    *ptr;

    if (g_temp_offset + size > FT_TEMP_CAP)
        return (NULL);
    ptr = g_temp_buffer + g_temp_offset;
    g_temp_offset += size;
    return (ptr);
}
```

**Norm note:** Global variables are allowed (just not in header).

---

## 8. ft_swap - Generic Swap

**What:** Swap any two values of same size.

```c
void    ft_swap(void *a, void *b, size_t size);
```

**Usage:**
```c
int x = 5, y = 10;
ft_swap(&x, &y, sizeof(int));
// x == 10, y == 5
```

---

## 9. ft_da_foreach - Iterator Pattern

**What:** Iterate over dynamic array elements.

Since norm doesn't allow macros that expand to statements, do it with function pointers:

```c
void    ft_vec_foreach(t_vec *v, void (*fn)(void *elem, size_t i));
```

**Or return pointer for manual iteration:**
```c
void    *ft_vec_begin(t_vec *v);
void    *ft_vec_end(t_vec *v);
void    *ft_vec_next(t_vec *v, void *current);
```

---

## 10. Array Utilities

**What:** Common array operations.

```c
// Get last element
void    *ft_vec_last(t_vec *v);

// Remove at index (unordered - swap with last, O(1))
int     ft_vec_remove_unordered(t_vec *v, size_t index);

// Remove at index (ordered - shift elements, O(n))
int     ft_vec_remove(t_vec *v, size_t index);

// Resize to exact size
int     ft_vec_resize(t_vec *v, size_t new_len);
```

**Unordered remove trick:**
```c
// Instead of shifting all elements...
// Just swap target with last element and decrement len
int ft_vec_remove_unordered(t_vec *v, size_t i)
{
    void    *target;
    void    *last;

    if (i >= v->len)
        return (0);
    if (i != v->len - 1)
    {
        target = (char *)v->data + (i * v->elem_size);
        last = (char *)v->data + ((v->len - 1) * v->elem_size);
        ft_memcpy(target, last, v->elem_size);
    }
    v->len--;
    return (1);
}
```

---

## 11. ft_assert - Debug Assertions

**What:** Assertions that print useful info.

```c
#ifdef DEBUG
# define FT_ASSERT(cond) \
    ft_assert_impl((cond), #cond, __FILE__, __LINE__)
#else
# define FT_ASSERT(cond) ((void)0)
#endif

void    ft_assert_impl(int cond, const char *expr, 
                       const char *file, int line);
```

**Output on failure:**
```
Assertion failed: ptr != NULL
  at parser.c:89
```

---

## 12. ft_todo / ft_unreachable - Development Helpers

**What:** Mark incomplete code and impossible states.

```c
#define FT_TODO(msg) \
    (ft_log(LOG_ERROR, "%s:%d: TODO: %s", __FILE__, __LINE__, msg), exit(1))

#define FT_UNREACHABLE() \
    (ft_log(LOG_ERROR, "%s:%d: UNREACHABLE", __FILE__, __LINE__), exit(1))
```

**Usage:**
```c
switch (type)
{
    case TYPE_A: return handle_a();
    case TYPE_B: return handle_b();
    case TYPE_C: FT_TODO("implement TYPE_C");
    default: FT_UNREACHABLE();
}
```

---

## Summary: What's Norm-Safe from nob.h

| nob.h Feature | Norm-Safe? | Notes |
|---------------|------------|-------|
| Dynamic array | ✓ | Use struct, not macros |
| String builder | ✓ | Specialized ft_vec |
| String view | ✓ | Simple struct |
| return_defer | ✓ | goto is allowed |
| Logging | ✓ | Variadic functions ok |
| Shift args | ✓ | Simple function |
| Path utils | ✓ | Pure functions |
| Temp allocator | ✓ | Static buffer |
| Swap | ✓ | Generic with size param |
| File I/O | ✓ | Standard POSIX |
| Assert macros | ✓ | Single-line macros ok |
| Process spawning | ✗ | Too OS-dependent |
| Rebuild self | ✗ | Build system specific |

---

## File Organization

```
srcs/
├── ft_vec/          # dynamic array
├── ft_str/          # existing + string builder
├── ft_sv/           # string view
├── ft_path/         # path utilities  
├── ft_file/         # read/write entire file
├── ft_log/          # logging
└── ft_temp/         # temp allocator
```

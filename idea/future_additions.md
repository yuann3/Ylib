# Future libft Additions

Inspired by Rust and C++ standard libraries, tailored for 42 projects.

---

## High Priority (Most Useful)

### 1. ft_result - Error Handling (Rust-inspired)

**Useful for:** All projects (especially minishell, cub3d)

Rust's `Result<T, E>` pattern prevents silent failures.

```c
typedef enum e_result_type
{
    RES_OK,
    RES_ERR
}   t_result_type;

typedef struct s_result
{
    t_result_type   type;
    void            *value;     // success value
    char            *error;     // error message
}   t_result;

// Usage
t_result    ft_result_ok(void *value);
t_result    ft_result_err(char *msg);
int         ft_result_is_ok(t_result res);
void        *ft_result_unwrap(t_result res);  // returns value or NULL
```

**Example:**
```c
t_result parse_file(char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd < 0)
        return (ft_result_err("failed to open file"));
    // ...
    return (ft_result_ok(data));
}
```

---

### 2. ft_str (String Builder) - C++ std::string inspired

**Useful for:** minishell, parsing, any string manipulation

```c
typedef struct s_str
{
    char    *data;
    size_t  len;
    size_t  cap;
}   t_str;

t_str   *ft_str_new(void);
t_str   *ft_str_from(const char *s);
int     ft_str_push(t_str *s, char c);
int     ft_str_append(t_str *s, const char *suffix);
int     ft_str_prepend(t_str *s, const char *prefix);
char    *ft_str_to_cstr(t_str *s);      // returns owned copy
char    *ft_str_view(t_str *s);         // returns internal ptr (don't free)
void    ft_str_clear(t_str *s);
void    ft_str_free(t_str *s);
```

**Why?** Building strings char-by-char (like in GNL or parsing) is painful with plain C strings.

---

### 3. ft_hashmap - Key-Value Store

**Useful for:** minishell (env vars), cub3d (config), any lookup-heavy code

```c
typedef struct s_hashmap
{
    t_vec   *buckets;       // array of t_vec (for chaining)
    size_t  size;           // number of entries
    size_t  cap;            // number of buckets
}   t_hashmap;

t_hashmap   *ft_hashmap_new(size_t init_cap);
int         ft_hashmap_set(t_hashmap *map, const char *key, void *value);
void        *ft_hashmap_get(t_hashmap *map, const char *key);
int         ft_hashmap_has(t_hashmap *map, const char *key);
int         ft_hashmap_del(t_hashmap *map, const char *key);
void        ft_hashmap_free(t_hashmap *map, void (*del)(void *));
```

**Hash function:**
```c
// djb2 - simple and effective
size_t  ft_hash(const char *str)
{
    size_t  hash;

    hash = 5381;
    while (*str)
    {
        hash = ((hash << 5) + hash) + *str;
        str++;
    }
    return (hash);
}
```

---

### 4. ft_deque - Double-Ended Queue

**Useful for:** push_swap (perfect fit!), BFS algorithms

```c
typedef struct s_deque
{
    int     *data;
    size_t  head;       // front index
    size_t  tail;       // back index
    size_t  len;
    size_t  cap;
}   t_deque;

t_deque *ft_deque_new(size_t cap);
int     ft_deque_push_front(t_deque *d, int val);
int     ft_deque_push_back(t_deque *d, int val);
int     ft_deque_pop_front(t_deque *d, int *out);
int     ft_deque_pop_back(t_deque *d, int *out);
int     *ft_deque_front(t_deque *d);
int     *ft_deque_back(t_deque *d);
```

**Circular buffer implementation** - O(1) for all operations.

---

### 5. ft_arena - Arena Allocator (Rust-inspired)

**Useful for:** Any project with many small allocations (parsers, ASTs)

```c
typedef struct s_arena
{
    char    *buffer;
    size_t  offset;
    size_t  cap;
}   t_arena;

t_arena *ft_arena_new(size_t size);
void    *ft_arena_alloc(t_arena *a, size_t size);
void    ft_arena_reset(t_arena *a);     // reset offset, reuse memory
void    ft_arena_free(t_arena *a);      // free everything at once
```

**Why?** Instead of tracking 100 mallocs, allocate from arena and free all at once. No memory leaks!

---

## Medium Priority

### 6. ft_vec2 / ft_vec3 - Vector Math

**Useful for:** fract-ol, cub3d, miniRT, so_long

```c
typedef struct s_vec2
{
    double  x;
    double  y;
}   t_vec2;

typedef struct s_vec3
{
    double  x;
    double  y;
    double  z;
}   t_vec3;

t_vec2  ft_vec2_add(t_vec2 a, t_vec2 b);
t_vec2  ft_vec2_sub(t_vec2 a, t_vec2 b);
t_vec2  ft_vec2_scale(t_vec2 v, double s);
double  ft_vec2_dot(t_vec2 a, t_vec2 b);
double  ft_vec2_len(t_vec2 v);
t_vec2  ft_vec2_norm(t_vec2 v);

// Same for vec3, plus:
t_vec3  ft_vec3_cross(t_vec3 a, t_vec3 b);
```

---

### 7. ft_complex - Complex Numbers

**Useful for:** fract-ol (Mandelbrot, Julia sets)

```c
typedef struct s_complex
{
    double  re;
    double  im;
}   t_complex;

t_complex   ft_complex_add(t_complex a, t_complex b);
t_complex   ft_complex_mul(t_complex a, t_complex b);
double      ft_complex_abs(t_complex z);    // |z| = sqrt(re² + im²)
t_complex   ft_complex_square(t_complex z); // z²
```

**Mandelbrot in 3 lines:**
```c
while (ft_complex_abs(z) < 2.0 && iter < max)
{
    z = ft_complex_add(ft_complex_square(z), c);
    iter++;
}
```

---

### 8. ft_color - Color Utilities

**Useful for:** fract-ol, cub3d, miniRT, any graphics project

```c
typedef struct s_color
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
}   t_color;

int     ft_color_to_int(t_color c);             // pack to 0xAARRGGBB
t_color ft_color_from_int(int color);
t_color ft_color_lerp(t_color a, t_color b, double t);  // interpolate
t_color ft_color_from_hsv(double h, double s, double v);
```

---

### 9. ft_getopt - Argument Parsing

**Useful for:** Any project with CLI flags

```c
typedef struct s_opt
{
    char    short_name;     // 'v'
    char    *long_name;     // "verbose"
    int     has_arg;        // 0 = flag, 1 = required arg
    char    *value;         // parsed value
    int     present;        // was this flag used?
}   t_opt;

int ft_getopt(int argc, char **argv, t_opt *opts, size_t n_opts);
```

---

## Lower Priority (Nice to Have)

### 10. ft_bitset - Bit Manipulation

**Useful for:** Optimized flags, visited arrays

```c
typedef struct s_bitset
{
    uint64_t    *data;
    size_t      n_bits;
}   t_bitset;

t_bitset    *ft_bitset_new(size_t n_bits);
void        ft_bitset_set(t_bitset *bs, size_t i);
void        ft_bitset_clear(t_bitset *bs, size_t i);
int         ft_bitset_get(t_bitset *bs, size_t i);
```

---

### 11. ft_slice - Non-owning View (Rust-inspired)

**Useful for:** Parsing without copying

```c
typedef struct s_slice
{
    const char  *ptr;
    size_t      len;
}   t_slice;

t_slice ft_slice_new(const char *s, size_t len);
t_slice ft_slice_from(const char *s);           // uses strlen
int     ft_slice_eq(t_slice a, t_slice b);
t_slice ft_slice_trim(t_slice s);
char    *ft_slice_to_str(t_slice s);            // allocates copy
```

---

### 12. Math Helpers

```c
int     ft_min(int a, int b);
int     ft_max(int a, int b);
int     ft_clamp(int val, int min, int max);
int     ft_abs(int n);
double  ft_lerp(double a, double b, double t);
double  ft_map(double val, t_vec2 from, t_vec2 to);  // remap range
```

---

## Project Mapping

| Addition | push_swap | fract-ol | minishell | cub3d | miniRT |
|----------|-----------|----------|-----------|-------|--------|
| ft_vec | ✓ | ✓ | ✓ | ✓ | ✓ |
| ft_result | ✓ | | ✓ | ✓ | ✓ |
| ft_str | | | ✓✓ | ✓ | |
| ft_hashmap | | | ✓✓ | ✓ | |
| ft_deque | ✓✓ | | | | |
| ft_arena | | | ✓ | ✓ | ✓ |
| ft_vec2/3 | | ✓✓ | | ✓✓ | ✓✓ |
| ft_complex | | ✓✓ | | | |
| ft_color | | ✓✓ | | ✓ | ✓ |

✓✓ = highly recommended for that project

---

## Implementation Order Suggestion

1. **ft_vec** - Foundation for other structures
2. **ft_str** - You'll use strings everywhere
3. **ft_deque** - Perfect for push_swap
4. **ft_result** - Better error handling
5. **ft_hashmap** - Essential for minishell
6. **ft_vec2/ft_complex** - When you hit graphics projects

# ft_vec Function Implementations

All functions designed to comply with 42 norminette.

---

## ft_vec_new

**Purpose:** Create a new vector with initial capacity.

**Signature:**
```c
t_vec   *ft_vec_new(size_t elem_size, size_t init_cap);
```

**Logic:**
```
1. Allocate t_vec struct with ft_calloc
2. If init_cap == 0, set default (e.g., 8)
3. Allocate data buffer: elem_size * init_cap bytes
4. Set len = 0, cap = init_cap, elem_size
5. Return pointer (NULL on allocation failure)
```

**Pseudocode:**
```c
t_vec *ft_vec_new(size_t elem_size, size_t init_cap)
{
    t_vec   *vec;

    if (elem_size == 0)
        return (NULL);
    vec = ft_calloc(1, sizeof(t_vec));
    if (!vec)
        return (NULL);
    if (init_cap == 0)
        init_cap = 8;
    vec->data = ft_calloc(init_cap, elem_size);
    if (!vec->data)
        return (free(vec), NULL);
    vec->elem_size = elem_size;
    vec->cap = init_cap;
    vec->len = 0;
    return (vec);
}
```

---

## ft_vec_grow (static helper)

**Purpose:** Double capacity when full.

**Signature:**
```c
static int  ft_vec_grow(t_vec *vec);
```

**Logic:**
```
1. new_cap = cap * 2
2. Allocate new buffer with new_cap
3. Copy old data using ft_memcpy
4. Free old buffer
5. Update vec->data and vec->cap
6. Return 1 on success, 0 on failure
```

**Pseudocode:**
```c
static int  ft_vec_grow(t_vec *vec)
{
    void    *new_data;
    size_t  new_cap;

    new_cap = vec->cap * 2;
    new_data = ft_calloc(new_cap, vec->elem_size);
    if (!new_data)
        return (0);
    ft_memcpy(new_data, vec->data, vec->len * vec->elem_size);
    free(vec->data);
    vec->data = new_data;
    vec->cap = new_cap;
    return (1);
}
```

---

## ft_vec_push

**Purpose:** Append element to end.

**Signature:**
```c
int ft_vec_push(t_vec *vec, const void *elem);
```

**Logic:**
```
1. If len == cap, call ft_vec_grow
2. Calculate destination: data + (len * elem_size)
3. Copy elem_size bytes from elem to destination
4. Increment len
5. Return 1 on success, 0 on failure
```

**Pseudocode:**
```c
int ft_vec_push(t_vec *vec, const void *elem)
{
    void    *dst;

    if (!vec || !elem)
        return (0);
    if (vec->len == vec->cap)
    {
        if (!ft_vec_grow(vec))
            return (0);
    }
    dst = (char *)vec->data + (vec->len * vec->elem_size);
    ft_memcpy(dst, elem, vec->elem_size);
    vec->len++;
    return (1);
}
```

**Note:** Cast to `char *` for byte-level pointer arithmetic.

---

## ft_vec_pop

**Purpose:** Remove and optionally return last element.

**Signature:**
```c
int ft_vec_pop(t_vec *vec, void *out);
```

**Logic:**
```
1. Check len > 0
2. Decrement len
3. If out != NULL, copy last element to out
4. Return 1 on success, 0 if empty
```

**Pseudocode:**
```c
int ft_vec_pop(t_vec *vec, void *out)
{
    void    *src;

    if (!vec || vec->len == 0)
        return (0);
    vec->len--;
    if (out)
    {
        src = (char *)vec->data + (vec->len * vec->elem_size);
        ft_memcpy(out, src, vec->elem_size);
    }
    return (1);
}
```

---

## ft_vec_get

**Purpose:** Get pointer to element at index.

**Signature:**
```c
void    *ft_vec_get(t_vec *vec, size_t index);
```

**Logic:**
```
1. Check index < len (bounds check)
2. Return data + (index * elem_size)
3. Return NULL if out of bounds
```

**Pseudocode:**
```c
void    *ft_vec_get(t_vec *vec, size_t index)
{
    if (!vec || index >= vec->len)
        return (NULL);
    return ((char *)vec->data + (index * vec->elem_size));
}
```

**Usage:**
```c
int *num = (int *)ft_vec_get(vec, 5);
if (num)
    printf("%d\n", *num);
```

---

## ft_vec_set

**Purpose:** Set element at index.

**Signature:**
```c
int ft_vec_set(t_vec *vec, size_t index, const void *elem);
```

**Logic:**
```
1. Check index < len
2. Calculate destination address
3. Copy elem to destination
4. Return 1 success, 0 failure
```

**Pseudocode:**
```c
int ft_vec_set(t_vec *vec, size_t index, const void *elem)
{
    void    *dst;

    if (!vec || !elem || index >= vec->len)
        return (0);
    dst = (char *)vec->data + (index * vec->elem_size);
    ft_memcpy(dst, elem, vec->elem_size);
    return (1);
}
```

---

## ft_vec_free

**Purpose:** Free all vector memory.

**Signature:**
```c
void    ft_vec_free(t_vec *vec);
```

**Logic:**
```
1. If vec is NULL, return
2. Free vec->data if not NULL
3. Free vec struct
```

**Pseudocode:**
```c
void    ft_vec_free(t_vec *vec)
{
    if (!vec)
        return ;
    if (vec->data)
        free(vec->data);
    free(vec);
}
```

---

## ft_vec_clear

**Purpose:** Reset to empty without freeing.

**Signature:**
```c
void    ft_vec_clear(t_vec *vec);
```

**Pseudocode:**
```c
void    ft_vec_clear(t_vec *vec)
{
    if (!vec)
        return ;
    vec->len = 0;
}
```

---

## ft_vec_reserve

**Purpose:** Ensure minimum capacity.

**Signature:**
```c
int ft_vec_reserve(t_vec *vec, size_t new_cap);
```

**Logic:**
```
1. If new_cap <= current cap, do nothing
2. Allocate new buffer with new_cap
3. Copy existing data
4. Free old buffer, update pointers
```

---

## Usage Example

```c
int main(void)
{
    t_vec   *nums;
    int     value;
    int     *ptr;
    size_t  i;

    nums = ft_vec_new(sizeof(int), 4);

    value = 42;
    ft_vec_push(nums, &value);
    value = 100;
    ft_vec_push(nums, &value);

    i = 0;
    while (i < nums->len)
    {
        ptr = ft_vec_get(nums, i);
        ft_printf("%d\n", *ptr);
        i++;
    }

    ft_vec_pop(nums, &value);
    ft_printf("popped: %d\n", value);

    ft_vec_free(nums);
    return (0);
}
```

---

## File Organization

```
srcs/
└── ft_vec/
    ├── ft_vec_new.c
    ├── ft_vec_push.c
    ├── ft_vec_pop.c
    ├── ft_vec_get.c
    ├── ft_vec_set.c
    ├── ft_vec_free.c
    ├── ft_vec_clear.c
    └── ft_vec_reserve.c
```

Add to `libft.h`:
```c
typedef struct s_vec
{
    void    *data;
    size_t  len;
    size_t  cap;
    size_t  elem_size;
}   t_vec;

t_vec   *ft_vec_new(size_t elem_size, size_t init_cap);
int     ft_vec_push(t_vec *vec, const void *elem);
int     ft_vec_pop(t_vec *vec, void *out);
void    *ft_vec_get(t_vec *vec, size_t index);
int     ft_vec_set(t_vec *vec, size_t index, const void *elem);
void    ft_vec_free(t_vec *vec);
void    ft_vec_clear(t_vec *vec);
int     ft_vec_reserve(t_vec *vec, size_t new_cap);
```

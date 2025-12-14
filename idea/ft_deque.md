# ft_deque - Double-Ended Queue for libft

A circular buffer implementation providing O(1) push/pop from both ends.

## Use Cases

| Project | Usage |
|---------|-------|
| **push_swap** | Stack A and Stack B operations (sa, sb, ra, rb, rra, rrb) |
| **BFS** | Queue for breadth-first search |
| **Sliding window** | Algorithms requiring front/back access |

---

## Why Deque over Linked List?

| Operation | Linked List | Deque (Circular Buffer) |
|-----------|-------------|-------------------------|
| Push front | O(1) | O(1) |
| Push back | O(n) or O(1)* | O(1) |
| Pop front | O(1) | O(1) |
| Pop back | O(n) | O(1) |
| Random access | O(n) | O(1) |
| Memory | Pointer per node | Contiguous, cache-friendly |
| push_swap rotate | O(n) | O(1) just move indices! |

*O(1) with tail pointer

**For push_swap:** Rotate operations (ra, rb, rra, rrb) are just index adjustments!

---

## Data Structure

```c
typedef struct s_deque
{
    void    *data;      // circular buffer
    size_t  head;       // index of first element
    size_t  tail;       // index after last element
    size_t  len;        // current number of elements
    size_t  cap;        // total capacity
    size_t  elem_size;  // size of each element
}   t_deque;
```

### Why Generic (`void *`)?

Same reasoning as `ft_vec`:
- Reusable for any type (int, struct, pointer)
- Consistent with rest of library
- For push_swap, use `sizeof(int)`

---

## Circular Buffer Concept

```
Initial state (cap=8, empty):
┌───┬───┬───┬───┬───┬───┬───┬───┐
│   │   │   │   │   │   │   │   │
└───┴───┴───┴───┴───┴───┴───┴───┘
  ↑
 head=0
 tail=0
 len=0

After push_back(A), push_back(B), push_back(C):
┌───┬───┬───┬───┬───┬───┬───┬───┐
│ A │ B │ C │   │   │   │   │   │
└───┴───┴───┴───┴───┴───┴───┴───┘
  ↑           ↑
 head=0     tail=3
            len=3

After push_front(X):
┌───┬───┬───┬───┬───┬───┬───┬───┐
│ A │ B │ C │   │   │   │   │ X │
└───┴───┴───┴───┴───┴───┴───┴───┘
              ↑               ↑
            tail=3          head=7
                            len=4

Logical order: X, A, B, C

After wrap-around (more elements):
┌───┬───┬───┬───┬───┬───┬───┬───┐
│ C │ D │ E │   │   │ X │ A │ B │
└───┴───┴───┴───┴───┴───┴───┴───┘
              ↑       ↑
            tail=3  head=5
                    len=6

Logical order: X, A, B, C, D, E
```

### Index Arithmetic

```c
// Move forward (with wrap)
next = (index + 1) % cap;

// Move backward (with wrap)
prev = (index - 1 + cap) % cap;

// Convert logical index to physical
physical = (head + logical_index) % cap;
```

---

## Function Implementations

### ft_deque_new

**Purpose:** Create a new deque with initial capacity.

```c
t_deque *ft_deque_new(size_t elem_size, size_t init_cap)
{
    t_deque *d;

    if (elem_size == 0)
        return (NULL);
    d = ft_calloc(1, sizeof(t_deque));
    if (!d)
        return (NULL);
    if (init_cap == 0)
        init_cap = 8;
    d->data = ft_calloc(init_cap, elem_size);
    if (!d->data)
        return (free(d), NULL);
    d->elem_size = elem_size;
    d->cap = init_cap;
    d->head = 0;
    d->tail = 0;
    d->len = 0;
    return (d);
}
```

---

### ft_deque_grow (static helper)

**Purpose:** Double capacity when full, preserving circular order.

**Critical:** Must linearize elements when growing!

```c
static int  ft_deque_grow(t_deque *d)
{
    void    *new_data;
    size_t  new_cap;
    size_t  i;
    void    *src;
    void    *dst;

    new_cap = d->cap * 2;
    if (new_cap < d->cap)
        return (0);
    new_data = ft_calloc(new_cap, d->elem_size);
    if (!new_data Double-Ended Queue)
        return (0);
    i = 0;
    while (i < d->len)
    {
        src = (char *)d->data + (((d->head + i) % d->cap) * d->elem_size);
        dst = (char *)new_data + (i * d->elem_size);
        ft_memcpy(dst, src, d->elem_size);
        i++;
    }
    free(d->data);
    d->data = new_data;
    d->cap = new_cap;
    d->head = 0;
    d->tail = d->len;
    return (1);
}
```

**Visual:**
```
Before grow (cap=4, full, wrapped):
┌───┬───┬───┬───┐
│ C │ D │ A │ B │   head=2, tail=2, len=4
└───┴───┴───┴───┘
          ↑
       head/tail

After grow (cap=8, linearized):
┌───┬───┬───┬───┬───┬───┬───┬───┐
│ A │ B │ C │ D │   │   │   │   │   head=0, tail=4, len=4
└───┴───┴───┴───┴───┴───┴───┴───┘
  ↑               ↑
 head           tail
```

---

### ft_deque_push_back

**Purpose:** Add element to back.

```c
int ft_deque_push_back(t_deque *d, const void *elem)
{
    void    *dst;

    if (!d || !elem)
        return (0);
    if (d->len == d->cap)
    {
        if (!ft_deque_grow(d))
            return (0);
    }
    dst = (char *)d->data + (d->tail * d->elem_size);
    ft_memcpy(dst, elem, d->elem_size);
    d->tail = (d->tail + 1) % d->cap;
    d->len++;
    return (1);
}
```

---

### ft_deque_push_front

**Purpose:** Add element to front.

```c
int ft_deque_push_front(t_deque *d, const void *elem)
{
    void    *dst;

    if (!d || !elem)
        return (0);
    if (d->len == d->cap)
    {
        if (!ft_deque_grow(d))
            return (0);
    }
    d->head = (d->head - 1 + d->cap) % d->cap;
    dst = (char *)d->data + (d->head * d->elem_size);
    ft_memcpy(dst, elem, d->elem_size);
    d->len++;
    return (1);
}
```

**Note:** Decrement head BEFORE inserting.

---

### ft_deque_pop_back

**Purpose:** Remove and optionally return last element.

```c
int ft_deque_pop_back(t_deque *d, void *out)
{
    void    *src;

    if (!d || d->len == 0)
        return (0);
    d->tail = (d->tail - 1 + d->cap) % d->cap;
    if (out)
    {
        src = (char *)d->data + (d->tail * d->elem_size);
        ft_memcpy(out, src, d->elem_size);
    }
    d->len--;
    return (1);
}
```

---

### ft_deque_pop_front

**Purpose:** Remove and optionally return first element.

```c
int ft_deque_pop_front(t_deque *d, void *out)
{
    void    *src;

    if (!d || d->len == 0)
        return (0);
    if (out)
    {
        src = (char *)d->data + (d->head * d->elem_size);
        ft_memcpy(out, src, d->elem_size);
    }
    d->head = (d->head + 1) % d->cap;
    d->len--;
    return (1);
}
```

---

### ft_deque_front

**Purpose:** Get pointer to first element without removing.

```c
void    *ft_deque_front(t_deque *d)
{
    if (!d || d->len == 0)
        return (NULL);
    return ((char *)d->data + (d->head * d->elem_size));
}
```

---

### ft_deque_back

**Purpose:** Get pointer to last element without removing.

```c
void    *ft_deque_back(t_deque *d)
{
    size_t  back_idx;

    if (!d || d->len == 0)
        return (NULL);
    back_idx = (d->tail - 1 + d->cap) % d->cap;
    return ((char *)d->data + (back_idx * d->elem_size));
}
```

---

### ft_deque_get

**Purpose:** Get pointer to element at logical index.

```c
void    *ft_deque_get(t_deque *d, size_t index)
{
    size_t  phys_idx;

    if (!d || index >= d->len)
        return (NULL);
    phys_idx = (d->head + index) % d->cap;
    return ((char *)d->data + (phys_idx * d->elem_size));
}
```

---

### ft_deque_rotate (push_swap: ra, rb)

**Purpose:** Move first element to back. O(1)!

```c
void    ft_deque_rotate(t_deque *d)
{
    if (!d || d->len <= 1)
        return ;
    d->head = (d->head + 1) % d->cap;
    d->tail = (d->tail + 1) % d->cap;
}
```

**Visual:**
```
Before: [A, B, C, D]  head=0
After:  [B, C, D, A]  head=1 (just shifted indices!)
```

**No data movement!** Just adjust head and tail.

---

### ft_deque_rrotate (push_swap: rra, rrb)

**Purpose:** Move last element to front. O(1)!

```c
void    ft_deque_rrotate(t_deque *d)
{
    if (!d || d->len <= 1)
        return ;
    d->head = (d->head - 1 + d->cap) % d->cap;
    d->tail = (d->tail - 1 + d->cap) % d->cap;
}
```

---

### ft_deque_swap (push_swap: sa, sb)

**Purpose:** Swap first two elements.

```c
void    ft_deque_swap(t_deque *d)
{
    void    *first;
    void    *second;
    char    temp[64];

    if (!d || d->len < 2)
        return ;
    if (d->elem_size > 64)
        return ;
    first = ft_deque_get(d, 0);
    second = ft_deque_get(d, 1);
    ft_memcpy(temp, first, d->elem_size);
    ft_memcpy(first, second, d->elem_size);
    ft_memcpy(second, temp, d->elem_size);
}
```

**Note:** Using stack buffer for swap. For larger elements, use malloc.

---

### ft_deque_clear

**Purpose:** Reset to empty without freeing.

```c
void    ft_deque_clear(t_deque *d)
{
    if (!d)
        return ;
    d->head = 0;
    d->tail = 0;
    d->len = 0;
}
```

---

### ft_deque_free

**Purpose:** Free all memory.

```c
void    ft_deque_free(t_deque *d)
{
    if (!d)
        return ;
    if (d->data)
        free(d->data);
    free(d);
}
```

---

### ft_deque_is_empty

```c
int ft_deque_is_empty(t_deque *d)
{
    if (!d)
        return (1);
    return (d->len == 0);
}
```

---

### ft_deque_is_full

```c
int ft_deque_is_full(t_deque *d)
{
    if (!d)
        return (0);
    return (d->len == d->cap);
}
```

---

## Edge Cases

| Scenario | Handling |
|----------|----------|
| NULL deque | Return 0/NULL, no crash |
| NULL element | Return 0 |
| Pop from empty | Return 0 |
| Get out of bounds | Return NULL |
| Rotate empty/single | No-op |
| Swap with < 2 elements | No-op |
| Growth overflow | Check `new_cap < cap` |
| Zero elem_size | Return NULL in new() |

---

## Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| push_front | O(1) amortized | O(1) |
| push_back | O(1) amortized | O(1) |
| pop_front | O(1) | O(1) |
| pop_back | O(1) | O(1) |
| front/back | O(1) | O(1) |
| get(index) | O(1) | O(1) |
| rotate | O(1) | O(1) |
| rrotate | O(1) | O(1) |
| swap | O(1) | O(1) |
| grow | O(n) | O(n) |

**push_swap operations are all O(1)!**

---

## Memory Layout

```
t_deque structure (48 bytes on 64-bit):
┌──────────┬──────┬──────┬─────┬─────┬───────────┐
│ data *   │ head │ tail │ len │ cap │ elem_size │
└────┬─────┴──────┴──────┴─────┴─────┴───────────┘
     │
     ▼
┌────┬────┬────┬────┬────┬────┬────┬────┐
│    │    │ e0 │ e1 │ e2 │    │    │    │  ← circular buffer
└────┴────┴────┴────┴────┴────┴────┴────┘
            ↑               ↑
          head            tail
```

---

## Header Additions

```c
typedef struct s_deque
{
    void    *data;
    size_t  head;
    size_t  tail;
    size_t  len;
    size_t  cap;
    size_t  elem_size;
}   t_deque;

/* Lifecycle */
t_deque *ft_deque_new(size_t elem_size, size_t init_cap);
void    ft_deque_free(t_deque *d);
void    ft_deque_clear(t_deque *d);

/* Push/Pop */
int     ft_deque_push_front(t_deque *d, const void *elem);
int     ft_deque_push_back(t_deque *d, const void *elem);
int     ft_deque_pop_front(t_deque *d, void *out);
int     ft_deque_pop_back(t_deque *d, void *out);

/* Access */
void    *ft_deque_front(t_deque *d);
void    *ft_deque_back(t_deque *d);
void    *ft_deque_get(t_deque *d, size_t index);

/* push_swap operations */
void    ft_deque_rotate(t_deque *d);
void    ft_deque_rrotate(t_deque *d);
void    ft_deque_swap(t_deque *d);

/* Utility */
int     ft_deque_is_empty(t_deque *d);
int     ft_deque_is_full(t_deque *d);
```

---

## File Organization

```
srcs/
└── ft_deque/
    ├── ft_deque_new.c       (new, free, clear)
    ├── ft_deque_push.c      (push_front, push_back, grow)
    ├── ft_deque_pop.c       (pop_front, pop_back)
    ├── ft_deque_access.c    (front, back, get)
    ├── ft_deque_ops.c       (rotate, rrotate, swap)
    └── ft_deque_utils.c     (is_empty, is_full)
```

---

## push_swap Example

```c
typedef struct s_stacks
{
    t_deque *a;
    t_deque *b;
}   t_stacks;

t_stacks    *init_stacks(int *arr, int size)
{
    t_stacks    *s;
    int         i;

    s = malloc(sizeof(t_stacks));
    s->a = ft_deque_new(sizeof(int), size);
    s->b = ft_deque_new(sizeof(int), size);
    i = 0;
    while (i < size)
    {
        ft_deque_push_back(s->a, &arr[i]);
        i++;
    }
    return (s);
}

void    sa(t_stacks *s)
{
    ft_deque_swap(s->a);
    ft_printf("sa\n");
}

void    pb(t_stacks *s)
{
    int val;

    if (ft_deque_pop_front(s->a, &val))
    {
        ft_deque_push_front(s->b, &val);
        ft_printf("pb\n");
    }
}

void    ra(t_stacks *s)
{
    ft_deque_rotate(s->a);
    ft_printf("ra\n");
}

void    rra(t_stacks *s)
{
    ft_deque_rrotate(s->a);
    ft_printf("rra\n");
}

/* Check if stack is sorted */
int is_sorted(t_deque *d)
{
    size_t  i;
    int     *curr;
    int     *next;

    if (d->len <= 1)
        return (1);
    i = 0;
    while (i < d->len - 1)
    {
        curr = ft_deque_get(d, i);
        next = ft_deque_get(d, i + 1);
        if (*curr > *next)
            return (0);
        i++;
    }
    return (1);
}
```

---

## BFS Example

```c
typedef struct s_node
{
    int x;
    int y;
    int dist;
}   t_node;

void    bfs(int **grid, int start_x, int start_y)
{
    t_deque *queue;
    t_node  curr;
    t_node  next;

    queue = ft_deque_new(sizeof(t_node), 100);
    curr = (t_node){start_x, start_y, 0};
    ft_deque_push_back(queue, &curr);

    while (!ft_deque_is_empty(queue))
    {
        ft_deque_pop_front(queue, &curr);
        /* Process curr, add neighbors */
        next = (t_node){curr.x + 1, curr.y, curr.dist + 1};
        ft_deque_push_back(queue, &next);
        /* ... other directions ... */
    }
    ft_deque_free(queue);
}
```

---

## Memory Safety Checklist

| Scenario | Status |
|----------|--------|
| ft_deque_new failure → no leak | ✅ frees d if data alloc fails |
| ft_deque_grow failure → original preserved | ✅ only updates after success |
| ft_deque_free(NULL) → safe | ✅ null check |
| Double free protection | ❌ user responsibility |
| Elements with internal pointers | ❌ user must free before pop |

---

## Norminette Compliance

| Rule | Solution |
|------|----------|
| Max 25 lines | Split grow into helper |
| Max 4 variables | Careful in grow() |
| Max 5 params | All functions ≤ 3 params |
| No for loops | Use while |
| No ternary | Use if/else |

---

## Why Circular Buffer is Perfect for push_swap

| Operation | With Linked List | With Deque |
|-----------|------------------|------------|
| sa (swap) | 2 pointer swaps | memcpy x3 |
| ra (rotate) | Update 4 pointers | 2 index updates |
| rra (reverse rotate) | Traverse to second-last O(n) | 2 index updates O(1) |
| pb (push to b) | malloc + pointer updates | memcpy + index updates |

**The killer feature:** `ra`, `rb`, `rra`, `rrb` are O(1) with just index math!

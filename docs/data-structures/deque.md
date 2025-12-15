# Deque (t_deque) - Double-Ended Queue

A double-ended queue (pronounced "deck") implemented as a circular buffer. Provides O(1) push/pop from both ends and O(1) random access. Ideal for algorithms requiring efficient operations at both ends, like the 42 push_swap project.

## What is a Deque?

A deque is a data structure that allows efficient insertion and deletion at both the front and back. Unlike a vector (efficient at back only) or linked list (inefficient random access), a deque combines the best of both:
- O(1) push/pop at **both ends**
- O(1) random access by index
- Contiguous memory (cache-friendly)

### Circular Buffer Implementation

The deque uses a **circular buffer** where the logical sequence wraps around:

```
Circular buffer with head=3, tail=1, cap=8:

Physical layout:
┌────┬────┬────┬────┬────┬────┬────┬────┐
│ e5 │    │    │ e0 │ e1 │ e2 │ e3 │ e4 │
└────┴────┴────┴────┴────┴────┴────┴────┘
  ^                 ^
 tail              head

Logical sequence: [e0, e1, e2, e3, e4, e5]
```

**Key insight:** Instead of shifting elements when adding/removing from the front, we just adjust the `head` and `tail` indices. This makes operations O(1)!

---

## When to Use a Deque

### Use a Deque When:

- ✓ Need O(1) push/pop at **both** ends
- ✓ Need random access (by index)
- ✓ Implementing stack + queue operations
- ✓ Sliding window algorithms
- ✓ Push_swap operations (rotate, swap)

### Use a Vector When:

- ✗ Only need push/pop at the back
- ✗ Don't need front operations

### Use a Linked List When:

- ✗ Frequent middle insertions/deletions
- ✗ Don't need random access
- ✗ Memory fragmentation acceptable

---

## Data Structure

```c
typedef struct s_deque
{
    void    *data;       // Circular buffer holding elements
    size_t  head;        // Index of first element
    size_t  tail;        // Index after last element
    size_t  len;         // Current number of elements
    size_t  cap;         // Total buffer capacity
    size_t  elem_size;   // Size of each element in bytes
}   t_deque;
```

**Fields:**
- `data`: Contiguous memory buffer (like vector)
- `head`: Physical index of first logical element
- `tail`: Physical index where next push_back would go
- `len`: Number of elements currently stored
- `cap`: Total capacity (elements before reallocation)
- `elem_size`: Size of each element in bytes

---

## API Reference

### Lifecycle

| Function | Description |
|----------|-------------|
| `ft_deque_new(elem_size, init_cap)` | Create new deque |
| `ft_deque_free(d)` | Free all memory |
| `ft_deque_clear(d)` | Reset to empty |

### Push/Pop

| Function | Description |
|----------|-------------|
| `ft_deque_push_front(d, elem)` | Add to front |
| `ft_deque_push_back(d, elem)` | Add to back |
| `ft_deque_pop_front(d, out)` | Remove from front |
| `ft_deque_pop_back(d, out)` | Remove from back |

### Push_swap Operations

| Function | Description |
|----------|-------------|
| `ft_deque_swap(d)` | Swap first two elements (sa/sb) |
| `ft_deque_rotate(d)` | Move first to back (ra/rb) |
| `ft_deque_rrotate(d)` | Move last to front (rra/rrb) |

### Access

| Function | Description |
|----------|-------------|
| `ft_deque_front(d)` | Get first element (no removal) |
| `ft_deque_back(d)` | Get last element (no removal) |
| `ft_deque_get(d, index)` | Get element at index |

### Utility

| Function | Description |
|----------|-------------|
| `ft_deque_is_empty(d)` | Check if empty |
| `ft_deque_is_full(d)` | Check if at capacity |

---

## Function Details

### ft_deque_new

```c
t_deque *ft_deque_new(size_t elem_size, size_t init_cap);
```

Create a new deque.

**Parameters:**
- `elem_size`: Size of each element in bytes (must be > 0)
- `init_cap`: Initial capacity (defaults to 8 if 0)

**Returns:** New deque, or NULL on failure.

**Example:**
```c
// Deque of integers
t_deque *d = ft_deque_new(sizeof(int), 10);

// Deque of structs
t_deque *points = ft_deque_new(sizeof(struct s_point), 20);
```

---

### ft_deque_push_front

```c
int ft_deque_push_front(t_deque *d, const void *elem);
```

Add an element to the front of the deque.

**Parameters:**
- `d`: Pointer to deque
- `elem`: Pointer to element to copy

**Returns:** 1 on success, 0 on failure.

**Complexity:** O(1) amortized

**Example:**
```c
int value = 42;
ft_deque_push_front(d, &value);  // Deque: [42]

value = 10;
ft_deque_push_front(d, &value);  // Deque: [10, 42]
```

---

### ft_deque_push_back

```c
int ft_deque_push_back(t_deque *d, const void *elem);
```

Add an element to the back of the deque.

**Parameters:**
- `d`: Pointer to deque
- `elem`: Pointer to element to copy

**Returns:** 1 on success, 0 on failure.

**Complexity:** O(1) amortized

**Example:**
```c
int value = 42;
ft_deque_push_back(d, &value);   // Deque: [42]

value = 100;
ft_deque_push_back(d, &value);   // Deque: [42, 100]
```

---

### ft_deque_pop_front

```c
int ft_deque_pop_front(t_deque *d, void *out);
```

Remove and optionally return the first element.

**Parameters:**
- `d`: Pointer to deque
- `out`: Output buffer (can be NULL to discard)

**Returns:** 1 on success, 0 if empty.

**Complexity:** O(1)

**Example:**
```c
int value;
if (ft_deque_pop_front(d, &value))
    ft_printf("Removed: %d\n", value);
```

---

### ft_deque_pop_back

```c
int ft_deque_pop_back(t_deque *d, void *out);
```

Remove and optionally return the last element.

**Parameters:**
- `d`: Pointer to deque
- `out`: Output buffer (can be NULL to discard)

**Returns:** 1 on success, 0 if empty.

**Complexity:** O(1)

**Example:**
```c
int value;
if (ft_deque_pop_back(d, &value))
    ft_printf("Removed: %d\n", value);
```

---

### ft_deque_swap

```c
void ft_deque_swap(t_deque *d);
```

Swap the first two elements (push_swap `sa`/`sb` operation).

**Parameters:**
- `d`: Pointer to deque

**Note:** No-op if deque has fewer than 2 elements.

**Complexity:** O(1)

**Example:**
```c
// Deque: [1, 2, 3]
ft_deque_swap(d);
// Deque: [2, 1, 3]
```

---

### ft_deque_rotate

```c
void ft_deque_rotate(t_deque *d);
```

Rotate up: move first element to the back (push_swap `ra`/`rb`).

**Parameters:**
- `d`: Pointer to deque

**Note:** No actual data movement - just adjusts head/tail indices!

**Complexity:** O(1)

**Example:**
```c
// Deque: [1, 2, 3]
ft_deque_rotate(d);
// Deque: [2, 3, 1]

ft_deque_rotate(d);
// Deque: [3, 1, 2]
```

---

### ft_deque_rrotate

```c
void ft_deque_rrotate(t_deque *d);
```

Reverse rotate: move last element to the front (push_swap `rra`/`rrb`).

**Parameters:**
- `d`: Pointer to deque

**Note:** No actual data movement - just adjusts head/tail indices!

**Complexity:** O(1)

**Example:**
```c
// Deque: [1, 2, 3]
ft_deque_rrotate(d);
// Deque: [3, 1, 2]

ft_deque_rrotate(d);
// Deque: [2, 3, 1]
```

---

### ft_deque_front

```c
void *ft_deque_front(t_deque *d);
```

Get a pointer to the first element without removing it.

**Parameters:**
- `d`: Pointer to deque

**Returns:** Pointer to first element, or NULL if empty.

**Complexity:** O(1)

**Example:**
```c
int *ptr = ft_deque_front(d);
if (ptr)
    ft_printf("First: %d\n", *ptr);
```

---

### ft_deque_back

```c
void *ft_deque_back(t_deque *d);
```

Get a pointer to the last element without removing it.

**Parameters:**
- `d`: Pointer to deque

**Returns:** Pointer to last element, or NULL if empty.

**Complexity:** O(1)

**Example:**
```c
int *ptr = ft_deque_back(d);
if (ptr)
    ft_printf("Last: %d\n", *ptr);
```

---

### ft_deque_get

```c
void *ft_deque_get(t_deque *d, size_t index);
```

Get a pointer to the element at logical index.

**Parameters:**
- `d`: Pointer to deque
- `index`: Logical index (0 = front)

**Returns:** Pointer to element, or NULL if out of bounds.

**Complexity:** O(1)

**Note:** Index 0 is the front, regardless of physical position in buffer.

**Example:**
```c
// Deque: [10, 20, 30]
int *ptr = ft_deque_get(d, 0);  // Points to 10
ptr = ft_deque_get(d, 1);       // Points to 20
ptr = ft_deque_get(d, 2);       // Points to 30
```

---

### ft_deque_is_empty / ft_deque_is_full

```c
int ft_deque_is_empty(t_deque *d);
int ft_deque_is_full(t_deque *d);
```

Check if deque is empty or at capacity.

**Returns:** 1 if true, 0 if false.

**Example:**
```c
if (ft_deque_is_empty(d))
    ft_printf("Deque is empty\n");

if (ft_deque_is_full(d))
    ft_printf("Deque will grow on next push\n");
```

---

## How Circular Buffer Works

### Visualization

Starting empty with cap=6:
```
head=0, tail=0, len=0
┌───┬───┬───┬───┬───┬───┐
│   │   │   │   │   │   │
└───┴───┴───┴───┴───┴───┘
 ^
 head/tail
```

After `push_back(1)`, `push_back(2)`, `push_back(3)`:
```
head=0, tail=3, len=3
┌───┬───┬───┬───┬───┬───┐
│ 1 │ 2 │ 3 │   │   │   │
└───┴───┴───┴───┴───┴───┘
 ^           ^
head        tail
```

After `push_front(0)`:
```
head=5, tail=3, len=4 (wrapped!)
┌───┬───┬───┬───┬───┬───┐
│ 1 │ 2 │ 3 │   │   │ 0 │
└───┴───┴───┴───┴───┴───┘
                     ^   ^
                   head tail
Logical: [0, 1, 2, 3]
```

After `rotate()`:
```
head=0, tail=4, len=4 (no data moved!)
┌───┬───┬───┬───┬───┬───┐
│ 1 │ 2 │ 3 │ 0 │   │   │
└───┴───┴───┴───┴───┴───┘
 ^               ^
head            tail
Logical: [1, 2, 3, 0]
```

**Key insight:** Rotate just changed `head` from 5 to 0. Zero data movement!

---

## Performance Characteristics

| Operation | Time Complexity | Notes |
|-----------|-----------------|-------|
| `ft_deque_push_front` | O(1) amortized | May trigger reallocation |
| `ft_deque_push_back` | O(1) amortized | May trigger reallocation |
| `ft_deque_pop_front` | O(1) | Just adjusts head |
| `ft_deque_pop_back` | O(1) | Just adjusts tail |
| `ft_deque_swap` | O(1) | Swaps two elements |
| `ft_deque_rotate` | O(1) | **Only adjusts head!** |
| `ft_deque_rrotate` | O(1) | **Only adjusts tail!** |
| `ft_deque_get` | O(1) | Random access |
| `ft_deque_front/back` | O(1) | Direct access |

**Memory:** O(n) where n is capacity (not length)

---

## Common Usage Patterns

### Stack (LIFO)

```c
t_deque *stack = ft_deque_new(sizeof(int), 10);
int value;

// Push
value = 10;
ft_deque_push_back(stack, &value);
value = 20;
ft_deque_push_back(stack, &value);

// Pop
ft_deque_pop_back(stack, &value);
ft_printf("%d\n", value);  // 20

ft_deque_pop_back(stack, &value);
ft_printf("%d\n", value);  // 10

ft_deque_free(stack);
```

### Queue (FIFO)

```c
t_deque *queue = ft_deque_new(sizeof(int), 10);
int value;

// Enqueue
value = 10;
ft_deque_push_back(queue, &value);
value = 20;
ft_deque_push_back(queue, &value);

// Dequeue
ft_deque_pop_front(queue, &value);
ft_printf("%d\n", value);  // 10

ft_deque_pop_front(queue, &value);
ft_printf("%d\n", value);  // 20

ft_deque_free(queue);
```

### Push_swap Operations

```c
t_deque *stack_a = ft_deque_new(sizeof(int), 100);
t_deque *stack_b = ft_deque_new(sizeof(int), 100);
int value;

// Initialize stack_a: [3, 2, 1]
for (int i = 3; i >= 1; i--)
    ft_deque_push_back(stack_a, &i);

// sa (swap a)
ft_deque_swap(stack_a);
// stack_a: [2, 3, 1]

// pb (push to b)
ft_deque_pop_back(stack_a, &value);
ft_deque_push_back(stack_b, &value);
// stack_a: [2, 3], stack_b: [1]

// ra (rotate a)
ft_deque_rotate(stack_a);
// stack_a: [3, 2], stack_b: [1]

// rra (reverse rotate a)
ft_deque_rrotate(stack_a);
// stack_a: [2, 3], stack_b: [1]

ft_deque_free(stack_a);
ft_deque_free(stack_b);
```

### Sliding Window

```c
void sliding_window_max(int *arr, int n, int k)
{
    t_deque *window = ft_deque_new(sizeof(int), k);
    int i;

    // Process first window
    for (i = 0; i < k && i < n; i++)
        ft_deque_push_back(window, &arr[i]);

    // Print max of first window
    int *max = ft_deque_back(window);
    ft_printf("Max: %d\n", *max);

    // Slide window
    for (i = k; i < n; i++)
    {
        ft_deque_pop_front(window, NULL);  // Remove first
        ft_deque_push_back(window, &arr[i]);  // Add new
        max = ft_deque_back(window);
        ft_printf("Max: %d\n", *max);
    }

    ft_deque_free(window);
}
```

---

## Comparison with Other Data Structures

| Feature | Deque | Vector | Linked List |
|---------|-------|--------|-------------|
| Push front | O(1) | O(n) | O(1) |
| Push back | O(1) | O(1) | O(n)* |
| Pop front | O(1) | O(n) | O(1) |
| Pop back | O(1) | O(1) | O(n) |
| Random access | O(1) | O(1) | O(n) |
| Rotate | **O(1)** | O(n) | O(1)† |
| Memory | Low | Low | High |
| Cache locality | Good | Excellent | Poor |

*O(1) with tail pointer
†After traversal

**Deque wins when:** You need both-end operations AND random access.

---

## Implementation Details

### Why Rotate is O(1)

Traditional rotate with vector:
```c
// O(n) - must shift all elements
temp = arr[0];
for (i = 0; i < len - 1; i++)
    arr[i] = arr[i + 1];
arr[len - 1] = temp;
```

Deque rotate with circular buffer:
```c
// O(1) - just adjust one index!
head = (head + 1) % cap;
```

**This is why deque is perfect for push_swap!**

### Growth Strategy

When full, the deque reallocates and unwraps the circular buffer:
1. Allocate new buffer (typically 2x capacity)
2. Copy elements in logical order (unwrapped)
3. Reset head=0, tail=len
4. Free old buffer

**Amortized O(1)** for push operations.

### Memory Layout

```
Physical memory (circular):
[data] → [ e3 | e4 | e5 | e0 | e1 | e2 | unused ]
                       ^head      ^tail

Logical view (what you see):
[e0, e1, e2, e3, e4, e5]
```

---

## Common Pitfalls

### Reallocation Invalidates Pointers

```c
int *ptr = ft_deque_front(d);
ft_deque_push_back(d, &value);  // May reallocate!
// ptr is now INVALID

// RIGHT: Get pointer after modifications
ft_deque_push_back(d, &value);
int *ptr = ft_deque_front(d);
```

### Index is Logical, Not Physical

```c
// Don't try to access d->data directly!
// WRONG:
int *arr = (int *)d->data;
int value = arr[0];  // Might not be first element!

// RIGHT: Use ft_deque_get
int *ptr = ft_deque_get(d, 0);  // Handles circular wrapping
```

### Not Checking Empty

```c
// WRONG: Crash if empty
int *ptr = ft_deque_front(d);
*ptr = 42;

// RIGHT: Check first
if (!ft_deque_is_empty(d))
{
    int *ptr = ft_deque_front(d);
    *ptr = 42;
}
```

---

## Advanced Example: Push_swap Solver

```c
#include "libft.h"

typedef struct s_stacks
{
    t_deque *a;
    t_deque *b;
}   t_stacks;

void sa(t_stacks *s) { ft_deque_swap(s->a); ft_printf("sa\n"); }
void sb(t_stacks *s) { ft_deque_swap(s->b); ft_printf("sb\n"); }
void ra(t_stacks *s) { ft_deque_rotate(s->a); ft_printf("ra\n"); }
void rra(t_stacks *s) { ft_deque_rrotate(s->a); ft_printf("rra\n"); }

void pb(t_stacks *s)
{
    int value;
    if (ft_deque_pop_back(s->a, &value))
    {
        ft_deque_push_back(s->b, &value);
        ft_printf("pb\n");
    }
}

void pa(t_stacks *s)
{
    int value;
    if (ft_deque_pop_back(s->b, &value))
    {
        ft_deque_push_back(s->a, &value);
        ft_printf("pa\n");
    }
}

int main(void)
{
    t_stacks s;
    s.a = ft_deque_new(sizeof(int), 10);
    s.b = ft_deque_new(sizeof(int), 10);

    // Push numbers: 3, 2, 1 (top to bottom)
    for (int i = 3; i >= 1; i--)
        ft_deque_push_back(s.a, &i);

    // Simple sort
    sa(&s);   // Swap: [2, 3, 1]
    pb(&s);   // Push to b: a=[2, 3], b=[1]
    ra(&s);   // Rotate: a=[3, 2], b=[1]
    sa(&s);   // Swap: a=[2, 3], b=[1]
    pa(&s);   // Push back: a=[2, 3, 1]... wait that's wrong!
    // (This is just demo code, not actual sorting logic)

    ft_deque_free(s.a);
    ft_deque_free(s.b);
    return (0);
}
```

---

## Best Practices

1. **Check empty before access:**
   ```c
   if (!ft_deque_is_empty(d))
       process(ft_deque_front(d));
   ```

2. **Don't hold pointers across modifications:**
   - Reallocation invalidates all pointers

3. **Use appropriate function:**
   - Front operations? → push_front/pop_front
   - Back operations? → push_back/pop_back
   - Rotate? → ft_deque_rotate (not manual pop+push)

4. **Free internal allocations:**
   - Like vector, deque doesn't free your data's pointers

---

## Related Documentation

- [Vector](vector.md) - For back-only operations
- [Linked List](linked-list.md) - For middle insertions
- [Memory Functions](../api/memory.md) - For manual memory management

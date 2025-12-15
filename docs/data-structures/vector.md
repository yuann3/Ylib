# Vector (t_vec) - Dynamic Array

A generic dynamic array that automatically grows as needed, providing O(1) random access and O(1) amortized push operations. Inspired by C++ `std::vector` and [nob.h](https://github.com/tsoding/nob.h).

## What is a Vector?

A vector is a dynamically-sized array that stores elements contiguously in memory. Unlike static arrays, vectors automatically resize when they run out of capacity, allowing you to add elements without knowing the final size in advance.

### Memory Layout

```
t_vec structure:
┌──────────┬─────┬─────┬───────────┐
│ data *   │ len │ cap │ elem_size │
└────┬─────┴─────┴─────┴───────────┘
     │
     ▼
┌────┬────┬────┬────┬────┬────┐
│ e0 │ e1 │ e2 │ .. │    │    │  ← heap allocated buffer
└────┴────┴────┴────┴────┴────┘
  ^─── len ───^  ^── unused ──^
  ^──────── cap ──────────────^
```

**Fields:**
- `data`: Pointer to contiguous memory buffer holding elements
- `len`: Number of elements currently stored
- `cap`: Total capacity (how many elements fit before reallocation)
- `elem_size`: Size of each element in bytes

---

## When to Use a Vector

### Use a Vector When:

- ✓ Need O(1) random access by index
- ✓ Primarily appending to the end
- ✓ Size unknown but grows monotonically
- ✓ Cache performance important
- ✓ Need to iterate frequently

### Use a Linked List When:

- ✗ Frequent insertions/deletions at beginning
- ✗ Need to insert/remove in middle frequently
- ✗ Memory fragmentation acceptable

### Use a Deque When:

- ✗ Need fast push/pop at both ends
- ✗ Need random access AND push/pop from front

---

## Data Structure

```c
typedef struct s_vec
{
    void    *data;       // Raw memory buffer
    size_t  len;         // Current number of elements
    size_t  cap;         // Allocated capacity (in elements)
    size_t  elem_size;   // Size of each element in bytes
}   t_vec;
```

---

## API Reference

### Lifecycle

| Function | Description |
|----------|-------------|
| `ft_vec_new(elem_size, init_cap)` | Create new vector |
| `ft_vec_free(vec)` | Free all memory |
| `ft_vec_clear(vec)` | Reset to empty (keep capacity) |

### Modification

| Function | Description |
|----------|-------------|
| `ft_vec_push(vec, elem)` | Append element |
| `ft_vec_pop(vec, out)` | Remove and return last element |
| `ft_vec_insert(vec, index, elem)` | Insert element at index |
| `ft_vec_set(vec, index, elem)` | Set element at index |

### Access

| Function | Description |
|----------|-------------|
| `ft_vec_get(vec, index)` | Get pointer to element |

### Capacity

| Function | Description |
|----------|-------------|
| `ft_vec_reserve(vec, new_cap)` | Ensure minimum capacity |

---

## Function Details

### ft_vec_new

```c
t_vec *ft_vec_new(size_t elem_size, size_t init_cap);
```

Create a new vector.

**Parameters:**
- `elem_size`: Size of each element in bytes (must be > 0)
- `init_cap`: Initial capacity (defaults to 8 if 0)

**Returns:** New vector, or NULL on failure.

**Example:**
```c
// Vector of integers
t_vec *nums = ft_vec_new(sizeof(int), 10);

// Vector of strings (char pointers)
t_vec *strings = ft_vec_new(sizeof(char *), 5);

// Vector of structs
t_vec *points = ft_vec_new(sizeof(struct s_point), 20);
```

---

### ft_vec_push

```c
int ft_vec_push(t_vec *vec, const void *elem);
```

Append an element to the end of the vector.

**Parameters:**
- `vec`: Pointer to vector
- `elem`: Pointer to element to copy

**Returns:** 1 on success, 0 on failure.

**Complexity:** O(1) amortized

**Note:** Automatically grows capacity when full.

**Example:**
```c
t_vec *vec = ft_vec_new(sizeof(int), 4);
int value;

value = 42;
ft_vec_push(vec, &value);
value = 100;
ft_vec_push(vec, &value);

ft_printf("Length: %zu\n", vec->len);  // 2
```

---

### ft_vec_pop

```c
int ft_vec_pop(t_vec *vec, void *out);
```

Remove and optionally return the last element.

**Parameters:**
- `vec`: Pointer to vector
- `out`: Output buffer (can be NULL to discard)

**Returns:** 1 on success, 0 if empty or NULL.

**Complexity:** O(1)

**Example:**
```c
int value;
if (ft_vec_pop(vec, &value))
    ft_printf("Popped: %d\n", value);
else
    ft_printf("Vector is empty\n");

// Discard value
ft_vec_pop(vec, NULL);
```

---

### ft_vec_get

```c
void *ft_vec_get(t_vec *vec, size_t index);
```

Get a pointer to the element at the specified index.

**Parameters:**
- `vec`: Pointer to vector
- `index`: Index of element (0-based)

**Returns:** Pointer to element, or NULL if out of bounds.

**Complexity:** O(1)

**Example:**
```c
int *ptr = ft_vec_get(vec, 0);
if (ptr)
    ft_printf("First element: %d\n", *ptr);

// Modify element
int *elem = ft_vec_get(vec, 2);
if (elem)
    *elem = 999;
```

---

### ft_vec_set

```c
int ft_vec_set(t_vec *vec, size_t index, const void *elem);
```

Set the value of an element at the specified index.

**Parameters:**
- `vec`: Pointer to vector
- `index`: Index of element to set
- `elem`: Pointer to new value

**Returns:** 1 on success, 0 if out of bounds.

**Complexity:** O(1)

**Example:**
```c
int value = 999;
if (ft_vec_set(vec, 2, &value))
    ft_printf("Updated index 2\n");
else
    ft_printf("Index out of bounds\n");
```

---

### ft_vec_insert

```c
int ft_vec_insert(t_vec *vec, size_t index, const void *elem);
```

Insert an element at the specified index, shifting later elements right.

**Parameters:**
- `vec`: Pointer to vector
- `index`: Index where element will be inserted
- `elem`: Pointer to element to insert

**Returns:** 1 on success, 0 on failure.

**Complexity:** O(n) - must shift elements

**Note:** Can insert at `index == vec->len` to append (equivalent to push).

**Example:**
```c
// vec: [10, 20, 30]
int value = 15;
ft_vec_insert(vec, 1, &value);
// vec: [10, 15, 20, 30]
```

---

### ft_vec_reserve

```c
int ft_vec_reserve(t_vec *vec, size_t new_cap);
```

Ensure vector has at least `new_cap` capacity.

**Parameters:**
- `vec`: Pointer to vector
- `new_cap`: Minimum required capacity

**Returns:** 1 on success, 0 on failure.

**Note:** Does nothing if current capacity >= `new_cap`.

**Example:**
```c
// Pre-allocate space for 1000 elements
if (ft_vec_reserve(vec, 1000))
{
    // Now can push 1000 elements without reallocation
    for (int i = 0; i < 1000; i++)
        ft_vec_push(vec, &i);
}
```

---

### ft_vec_clear

```c
void ft_vec_clear(t_vec *vec);
```

Reset vector to empty state, keeping allocated memory.

**Parameters:**
- `vec`: Pointer to vector

**Note:** Sets `len` to 0 but keeps `cap` unchanged. Useful for reusing vector.

**Example:**
```c
ft_vec_clear(vec);
ft_printf("Length: %zu, Capacity: %zu\n", vec->len, vec->cap);
// Length: 0, Capacity: (unchanged)
```

---

### ft_vec_free

```c
void ft_vec_free(t_vec *vec);
```

Free all memory associated with the vector.

**Parameters:**
- `vec`: Pointer to vector (safe to call with NULL)

**Note:** Frees the data buffer and the vector structure itself.

**Example:**
```c
ft_vec_free(vec);
vec = NULL;  // Good practice
```

---

## Growth Strategy

When the vector runs out of capacity, it automatically reallocates:

1. **Current behavior:** Grows by a factor (typically 1.5x or 2x)
2. **New capacity** is allocated
3. **Elements are copied** to new buffer
4. **Old buffer is freed**

**Amortized O(1):** Although occasional reallocation is O(n), the average cost per insertion is constant when averaged over many operations.

**Memory overhead:**
- Empty vector: ~32 bytes (struct + minimal allocation)
- Unused capacity: At most ~50% waste (if using 2x growth)

---

## Performance Characteristics

| Operation | Time Complexity | Notes |
|-----------|-----------------|-------|
| `ft_vec_push` | O(1) amortized | Occasional O(n) reallocation |
| `ft_vec_pop` | O(1) | Simply decrements length |
| `ft_vec_get` | O(1) | Direct pointer arithmetic |
| `ft_vec_set` | O(1) | Direct memory access |
| `ft_vec_insert` | O(n) | Must shift elements |
| `ft_vec_reserve` | O(n) | When reallocation needed |
| Iteration | O(n) | Cache-friendly |

**Memory:** O(n) where n is capacity (not length)

---

## Common Usage Patterns

### Basic Usage

```c
#include "libft.h"

int main(void)
{
    t_vec   *nums = ft_vec_new(sizeof(int), 4);
    int     value;
    int     i;

    // Push elements
    i = 0;
    while (i < 10)
    {
        ft_vec_push(nums, &i);
        i++;
    }

    // Access elements
    i = 0;
    while (i < (int)nums->len)
    {
        int *ptr = ft_vec_get(nums, i);
        ft_printf("%d ", *ptr);
        i++;
    }
    ft_printf("\n");

    // Pop last element
    if (ft_vec_pop(nums, &value))
        ft_printf("Popped: %d\n", value);

    ft_vec_free(nums);
    return (0);
}
```

### Storing Strings

```c
t_vec *words = ft_vec_new(sizeof(char *), 10);
char *word;

// Add words
word = ft_strdup("hello");
ft_vec_push(words, &word);
word = ft_strdup("world");
ft_vec_push(words, &word);

// Access
size_t i = 0;
while (i < words->len)
{
    char **ptr = ft_vec_get(words, i);
    ft_printf("%s\n", *ptr);
    i++;
}

// Free (must free strings AND vector)
i = 0;
while (i < words->len)
{
    char **ptr = ft_vec_get(words, i);
    free(*ptr);
    i++;
}
ft_vec_free(words);
```

### Storing Structs

```c
typedef struct s_point
{
    int x;
    int y;
}   t_point;

t_vec *points = ft_vec_new(sizeof(t_point), 5);
t_point p;

// Add points
p = (t_point){10, 20};
ft_vec_push(points, &p);
p = (t_point){30, 40};
ft_vec_push(points, &p);

// Access
size_t i = 0;
while (i < points->len)
{
    t_point *ptr = ft_vec_get(points, i);
    ft_printf("(%d, %d)\n", ptr->x, ptr->y);
    i++;
}

ft_vec_free(points);
```

### Pre-allocating for Performance

```c
t_vec *vec = ft_vec_new(sizeof(int), 0);

// Reserve space for 10000 elements
ft_vec_reserve(vec, 10000);

// Now 10000 pushes with no reallocation
int i = 0;
while (i < 10000)
{
    ft_vec_push(vec, &i);
    i++;
}
```

### Building from Array

```c
int arr[] = {1, 2, 3, 4, 5};
size_t arr_len = sizeof(arr) / sizeof(arr[0]);

t_vec *vec = ft_vec_new(sizeof(int), arr_len);
size_t i = 0;
while (i < arr_len)
{
    ft_vec_push(vec, &arr[i]);
    i++;
}
```

---

## Comparison with Other Data Structures

| Feature | Vector | Linked List | Deque |
|---------|--------|-------------|-------|
| Access by index | O(1) | O(n) | O(1) |
| Push back | O(1) amortized | O(n)* | O(1) amortized |
| Push front | O(n) | O(1) | O(1) amortized |
| Pop back | O(1) | O(n) | O(1) |
| Pop front | O(n) | O(1) | O(1) |
| Insert middle | O(n) | O(1)† | O(n) |
| Memory overhead | Minimal | High (pointers) | Low |
| Cache locality | Excellent | Poor | Good |
| Fragmentation | Low | High | Low |

*O(1) with tail pointer
†After finding position (O(n) to find, O(1) to insert)

---

## Implementation Details

### Type Safety

Vector is type-generic using `void *` and `elem_size`:

```c
// Store integers
t_vec *ints = ft_vec_new(sizeof(int), 10);

// Store custom structs
t_vec *data = ft_vec_new(sizeof(struct s_mydata), 10);
```

**Responsibility:** You must ensure you push/pop the correct type. The vector doesn't know or check types.

### Memory Management

**Vector owns the data buffer** but not the elements' internal pointers:

```c
// This is OK - vector owns the integers
t_vec *nums = ft_vec_new(sizeof(int), 10);
ft_vec_free(nums);  // Frees integers

// This leaks - vector doesn't know about malloc'd strings
t_vec *strings = ft_vec_new(sizeof(char *), 10);
char *s = ft_strdup("hello");
ft_vec_push(strings, &s);
ft_vec_free(strings);  // Frees pointers, but not the strings!
```

**Always free internal allocations before freeing vector:**
```c
size_t i = 0;
while (i < strings->len)
{
    char **ptr = ft_vec_get(strings, i);
    free(*ptr);  // Free each string
    i++;
}
ft_vec_free(strings);  // Then free vector
```

### Reallocation Invalidates Pointers

```c
int *ptr = ft_vec_get(vec, 0);
ft_vec_push(vec, &value);  // May reallocate!
// ptr is now INVALID (dangling pointer)

// RIGHT: Get pointer after modifications
ft_vec_push(vec, &value);
int *ptr = ft_vec_get(vec, 0);  // Safe
```

---

## Common Pitfalls

### Storing Pointers vs Values

```c
// WRONG: Storing pointer to stack variable
int value = 42;
ft_vec_push(vec, &(&value));  // Double pointer - WRONG

// RIGHT: Store the value itself
int value = 42;
ft_vec_push(vec, &value);  // Stores a copy of 42
```

### Type Confusion

```c
t_vec *vec = ft_vec_new(sizeof(int), 10);
double value = 3.14;
ft_vec_push(vec, &value);  // WRONG! Vector expects sizeof(int)

// Results in corruption/undefined behavior
```

### Not Checking NULL

```c
// WRONG: No NULL check
int *ptr = ft_vec_get(vec, 1000);
*ptr = 42;  // CRASH if index out of bounds

// RIGHT: Always check
int *ptr = ft_vec_get(vec, 1000);
if (ptr)
    *ptr = 42;
```

### Memory Leaks with Pointers

```c
// WRONG: Leaks strings
t_vec *strings = ft_vec_new(sizeof(char *), 10);
char *s = ft_strdup("hello");
ft_vec_push(strings, &s);
ft_vec_free(strings);  // Leaks "hello"

// RIGHT: Free contents first
size_t i = 0;
while (i < strings->len)
{
    free(*(char **)ft_vec_get(strings, i));
    i++;
}
ft_vec_free(strings);
```

---

## Advanced Example

```c
#include "libft.h"

typedef struct s_task
{
    char    *description;
    int     priority;
}   t_task;

void free_task(t_task *task)
{
    free(task->description);
}

int main(void)
{
    t_vec   *tasks = ft_vec_new(sizeof(t_task), 5);
    t_task  task;
    size_t  i;

    // Add tasks
    task.description = ft_strdup("Write documentation");
    task.priority = 1;
    ft_vec_push(tasks, &task);

    task.description = ft_strdup("Fix bugs");
    task.priority = 2;
    ft_vec_push(tasks, &task);

    // Print tasks
    i = 0;
    while (i < tasks->len)
    {
        t_task *t = ft_vec_get(tasks, i);
        ft_printf("[%d] %s\n", t->priority, t->description);
        i++;
    }

    // Cleanup
    i = 0;
    while (i < tasks->len)
    {
        free_task(ft_vec_get(tasks, i));
        i++;
    }
    ft_vec_free(tasks);

    return (0);
}
```

---

## Best Practices

1. **Reserve capacity if known:** Avoids reallocations
   ```c
   ft_vec_reserve(vec, expected_size);
   ```

2. **Always check return values:**
   ```c
   if (!ft_vec_push(vec, &elem))
       handle_error();
   ```

3. **Free internal allocations:**
   - Vector only frees the buffer, not your data's pointers

4. **Don't hold pointers across modifications:**
   - Reallocation invalidates pointers from `ft_vec_get`

5. **Use correct element size:**
   - Match `elem_size` with the type you're storing

---

## Related Documentation

- [Deque](deque.md) - For O(1) push/pop at both ends
- [Linked List](linked-list.md) - For O(1) front insertions
- [Memory Functions](../api/memory.md) - For manual memory management

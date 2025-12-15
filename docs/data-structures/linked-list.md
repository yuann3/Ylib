# Linked List (t_list)

A singly-linked list implementation providing dynamic node-based storage with O(1) insertions at the front and efficient iteration.

## What is a Linked List?

A linked list is a linear data structure where elements (nodes) are stored non-contiguously in memory. Each node contains:
1. **Data** (`void *content`) - Pointer to the actual data
2. **Link** (`struct s_list *next`) - Pointer to the next node

Unlike arrays, nodes can be scattered throughout memory, connected by pointers.

### Memory Layout

```
┌─────────────┐    ┌─────────────┐    ┌─────────────┐
│ Node 1      │    │ Node 2      │    │ Node 3      │
├─────────────┤    ├─────────────┤    ├─────────────┤
│ content  ───┼──► │ content  ───┼──► │ content  ───┼──► (data)
│ next     ───┼──► │ next     ───┼──► │ next = NULL │
└─────────────┘    └─────────────┘    └─────────────┘
```

---

## When to Use Linked Lists

### Use a Linked List When:

- ✓ Frequent insertions/deletions at the beginning
- ✓ Unknown or highly variable size
- ✓ Need to frequently insert/remove in the middle
- ✓ Memory fragmentation is acceptable
- ✓ Sequential access pattern

### Use a Vector When:

- ✗ Need random access by index (O(1))
- ✗ Primarily appending to end
- ✗ Cache locality important (performance)
- ✗ Known/bounded size

### Use a Deque When:

- ✗ Need fast push/pop at both ends
- ✗ Need random access AND push/pop

---

## Data Structure

```c
typedef struct s_list
{
    void            *content;  // Pointer to node data
    struct s_list   *next;     // Pointer to next node
}   t_list;
```

**Fields:**
- `content`: Generic pointer to any data type
- `next`: Pointer to next node (NULL for last node)

**Note:** `content` is a pointer, not the data itself. You store pointers to your data in the list.

---

## API Reference

### Lifecycle

| Function | Description |
|----------|-------------|
| `ft_lstnew(content)` | Create new node |
| `ft_lstdelone(lst, del)` | Delete single node |
| `ft_lstclear(lst, del)` | Delete all nodes |

### Modification

| Function | Description |
|----------|-------------|
| `ft_lstadd_front(lst, new)` | Add node at beginning |
| `ft_lstadd_back(lst, new)` | Add node at end |

### Inspection

| Function | Description |
|----------|-------------|
| `ft_lstsize(lst)` | Count nodes |
| `ft_lstlast(lst)` | Get last node |

### Iteration

| Function | Description |
|----------|-------------|
| `ft_lstiter(lst, f)` | Apply function to each node |
| `ft_lstmap(lst, f, del)` | Map function to new list |

---

## Function Details

### ft_lstnew

```c
t_list *ft_lstnew(void *content);
```

Create a new list node.

**Parameters:**
- `content`: Pointer to data for the node

**Returns:** New node with `content` set and `next = NULL`, or NULL on allocation failure.

**Example:**
```c
int *num = malloc(sizeof(int));
*num = 42;
t_list *node = ft_lstnew(num);
```

---

### ft_lstadd_front

```c
void ft_lstadd_front(t_list **lst, t_list *new);
```

Add a node at the beginning of the list.

**Parameters:**
- `lst`: Address of pointer to first node
- `new`: Node to add

**Complexity:** O(1)

**Example:**
```c
t_list *list = NULL;
t_list *node1 = ft_lstnew("first");
t_list *node2 = ft_lstnew("second");

ft_lstadd_front(&list, node1);  // list: "first"
ft_lstadd_front(&list, node2);  // list: "second" -> "first"
```

---

### ft_lstadd_back

```c
void ft_lstadd_back(t_list **lst, t_list *new);
```

Add a node at the end of the list.

**Parameters:**
- `lst`: Address of pointer to first node
- `new`: Node to add

**Complexity:** O(n) - must traverse to find last node

**Example:**
```c
t_list *list = NULL;
ft_lstadd_back(&list, ft_lstnew("first"));   // list: "first"
ft_lstadd_back(&list, ft_lstnew("second"));  // list: "first" -> "second"
```

---

### ft_lstsize

```c
int ft_lstsize(t_list *lst);
```

Count the number of nodes in a list.

**Parameters:**
- `lst`: Pointer to first node

**Returns:** Number of nodes in the list.

**Complexity:** O(n)

**Example:**
```c
t_list *list = NULL;
ft_lstadd_back(&list, ft_lstnew("a"));
ft_lstadd_back(&list, ft_lstnew("b"));
ft_lstadd_back(&list, ft_lstnew("c"));

int size = ft_lstsize(list);  // size = 3
```

---

### ft_lstlast

```c
t_list *ft_lstlast(t_list *lst);
```

Get the last node in a list.

**Parameters:**
- `lst`: Pointer to first node

**Returns:** Last node in the list, or NULL if list is empty.

**Complexity:** O(n)

**Example:**
```c
t_list *list = NULL;
ft_lstadd_back(&list, ft_lstnew("first"));
ft_lstadd_back(&list, ft_lstnew("second"));
ft_lstadd_back(&list, ft_lstnew("last"));

t_list *last = ft_lstlast(list);
ft_printf("%s\n", (char *)last->content);  // "last"
```

---

### ft_lstdelone

```c
void ft_lstdelone(t_list *lst, void (*del)(void *));
```

Delete and free a single node.

**Parameters:**
- `lst`: Node to delete
- `del`: Function to free the content

**Note:** Only frees the given node, doesn't update list pointers. Typically used when node is already unlinked.

**Example:**
```c
void del(void *content)
{
    free(content);
}

int *num = malloc(sizeof(int));
*num = 42;
t_list *node = ft_lstnew(num);

ft_lstdelone(node, del);  // Frees both content and node
```

---

### ft_lstclear

```c
void ft_lstclear(t_list **lst, void (*del)(void *));
```

Delete and free all nodes in a list.

**Parameters:**
- `lst`: Address of pointer to first node
- `del`: Function to free each node's content

**Note:** Sets `*lst` to NULL after clearing.

**Example:**
```c
void del(void *content)
{
    free(content);
}

t_list *list = NULL;
// ... add nodes with malloc'd content ...

ft_lstclear(&list, del);  // Frees all nodes and content
// list is now NULL
```

---

### ft_lstiter

```c
void ft_lstiter(t_list *lst, void (*f)(void *));
```

Apply a function to the content of each node.

**Parameters:**
- `lst`: Pointer to first node
- `f`: Function to apply to each node's content

**Example:**
```c
void print_num(void *content)
{
    ft_printf("%d\n", *(int *)content);
}

// Assuming list contains int pointers
ft_lstiter(list, print_num);
```

---

### ft_lstmap

```c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```

Create a new list by applying a function to each node's content.

**Parameters:**
- `lst`: Pointer to first node
- `f`: Function to apply (returns new content)
- `del`: Function to free content if allocation fails

**Returns:** New list with transformed contents, or NULL on failure.

**Note:** Original list is unchanged.

**Example:**
```c
void *double_num(void *content)
{
    int *new = malloc(sizeof(int));
    if (!new)
        return (NULL);
    *new = *(int *)content * 2;
    return (new);
}

void del(void *content)
{
    free(content);
}

t_list *doubled = ft_lstmap(list, double_num, del);
// doubled contains new list with all values doubled
```

---

## Common Usage Patterns

### Building a List

```c
#include "libft.h"

int main(void)
{
    t_list  *list = NULL;
    int     *num;
    int     i;

    // Add numbers 0-4 to list
    i = 0;
    while (i < 5)
    {
        num = malloc(sizeof(int));
        *num = i;
        ft_lstadd_back(&list, ft_lstnew(num));
        i++;
    }

    ft_printf("List size: %d\n", ft_lstsize(list));
    return (0);
}
```

### Iterating Through a List

```c
void print_list(t_list *list)
{
    while (list)
    {
        ft_printf("%d ", *(int *)list->content);
        list = list->next;
    }
    ft_printf("\n");
}
```

### Freeing a List

```c
void free_int(void *content)
{
    free(content);
}

void cleanup_list(t_list **list)
{
    ft_lstclear(list, free_int);
}
```

### Stack Implementation

```c
// Push (add to front)
void push(t_list **stack, void *data)
{
    ft_lstadd_front(stack, ft_lstnew(data));
}

// Pop (remove from front)
void *pop(t_list **stack)
{
    t_list  *top;
    void    *data;

    if (!*stack)
        return (NULL);

    top = *stack;
    data = top->content;
    *stack = top->next;
    free(top);  // Free node, not content
    return (data);
}
```

### Queue Implementation

```c
// Enqueue (add to back)
void enqueue(t_list **queue, void *data)
{
    ft_lstadd_back(queue, ft_lstnew(data));
}

// Dequeue (remove from front)
void *dequeue(t_list **queue)
{
    t_list  *front;
    void    *data;

    if (!*queue)
        return (NULL);

    front = *queue;
    data = front->content;
    *queue = front->next;
    free(front);
    return (data);
}
```

---

## Performance Characteristics

| Operation | Time Complexity | Notes |
|-----------|-----------------|-------|
| Add to front | O(1) | `ft_lstadd_front` |
| Add to back | O(n) | Must traverse to end |
| Delete from front | O(1) | Update head pointer |
| Delete from back | O(n) | Must find second-to-last |
| Access by index | O(n) | Must traverse |
| Search | O(n) | Linear search only |
| Get size | O(n) | Must count nodes |

**Memory overhead:** Two pointers per node (content + next) = 16 bytes on 64-bit systems, plus malloc overhead (~16-32 bytes per allocation).

---

## Comparison with Other Data Structures

| Feature | Linked List | Vector | Deque |
|---------|-------------|--------|-------|
| Access by index | O(n) | O(1) | O(1) |
| Add to front | O(1) | O(n) | O(1) |
| Add to back | O(n) | O(1) amortized | O(1) |
| Memory overhead | High | Low | Low |
| Cache locality | Poor | Excellent | Good |
| Fragmentation | High | Low | Low |

---

## Implementation Details

### Why void *content?

The list stores `void *` (generic pointer) to allow any data type:

```c
// Integers
int *num = malloc(sizeof(int));
*num = 42;
t_list *node = ft_lstnew(num);

// Strings
char *str = ft_strdup("hello");
t_list *node = ft_lstnew(str);

// Structs
struct s_data *data = malloc(sizeof(struct s_data));
t_list *node = ft_lstnew(data);
```

**Responsibility:** You must ensure the deletion function matches the data type.

### Singly vs Doubly Linked

This is a **singly-linked** list (only forward pointers). Trade-offs:

**Advantages:**
- Less memory (one pointer per node vs two)
- Simpler implementation
- Sufficient for most use cases

**Disadvantages:**
- Can't traverse backwards
- Removing from back is O(n)
- No O(1) insert before a node

---

## Common Pitfalls

### Not Freeing Content

```c
// WRONG: Memory leak
ft_lstclear(&list, NULL);  // Frees nodes but not content

// RIGHT: Provide deletion function
ft_lstclear(&list, free);
```

### Double Free

```c
// WRONG: Content gets freed twice
t_list *node = ft_lstnew(data);
free(data);
ft_lstdelone(node, free);  // Tries to free already-freed data

// RIGHT: Let ft_lstdelone handle freeing
t_list *node = ft_lstnew(data);
ft_lstdelone(node, free);
```

### Losing List Head

```c
// WRONG: Lost reference to list
t_list *list = /* ... */;
list = list->next;  // Lost reference to first node!

// RIGHT: Use temp variable
t_list *current = list;
while (current)
{
    ft_printf("%d\n", *(int *)current->content);
    current = current->next;
}
```

### NULL Deletion Function

```c
// Works if content doesn't need freeing
char *static_str = "hello";  // Stack/static memory
t_list *node = ft_lstnew(static_str);
ft_lstdelone(node, NULL);  // OK, content not malloc'd

// But usually you need to free:
char *heap_str = ft_strdup("hello");
t_list *node = ft_lstnew(heap_str);
ft_lstdelone(node, free);  // Must provide free function
```

---

## Advanced Example

```c
#include "libft.h"
#include <stdio.h>

typedef struct s_person
{
    char    *name;
    int     age;
}   t_person;

void free_person(void *content)
{
    t_person *person = (t_person *)content;
    free(person->name);
    free(person);
}

void print_person(void *content)
{
    t_person *person = (t_person *)content;
    ft_printf("%s, age %d\n", person->name, person->age);
}

int main(void)
{
    t_list      *people = NULL;
    t_person    *p;

    // Add people
    p = malloc(sizeof(t_person));
    p->name = ft_strdup("Alice");
    p->age = 25;
    ft_lstadd_back(&people, ft_lstnew(p));

    p = malloc(sizeof(t_person));
    p->name = ft_strdup("Bob");
    p->age = 30;
    ft_lstadd_back(&people, ft_lstnew(p));

    // Print all
    ft_lstiter(people, print_person);

    // Cleanup
    ft_lstclear(&people, free_person);
    return (0);
}
```

---

## Related Documentation

- [Vector](vector.md) - For O(1) random access
- [Deque](deque.md) - For O(1) push/pop at both ends
- [Memory Functions](../api/memory.md) - For manual memory management

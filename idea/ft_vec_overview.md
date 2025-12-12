# ft_vec - Dynamic Array for libft

Inspired by Tsoding's nob.h dynamic arrays and C++ std::vector.

## Core Concept

A dynamic array that automatically grows when capacity is exceeded, providing O(1) amortized append operations.

## Data Structure

```c
typedef struct s_vec
{
    void    *data;       // raw memory buffer
    size_t  len;         // current number of elements
    size_t  cap;         // total allocated capacity (in elements)
    size_t  elem_size;   // size of each element in bytes
}   t_vec;
```

### Why these fields?

| Field | Purpose |
|-------|---------|
| `data` | Generic void pointer allows storing any type |
| `len` | Track how many elements are actually used |
| `cap` | Track allocated space to know when to grow |
| `elem_size` | Store element size for pointer arithmetic |

## Growth Strategy

When `len == cap`, allocate new buffer with `cap * 2` size.

```
Initial:  cap=4   [A][B][C][D]
                   ^len=4

Push 'E': cap=8   [A][B][C][D][E][ ][ ][ ]
                               ^len=5
```

**Why 2x?** Amortized O(1) for push operations. Growing by constant amount would be O(n).

## Norminette Considerations

| Rule | Solution |
|------|----------|
| Max 25 lines/function | Split grow logic into helper |
| Max 5 params | All state in `t_vec` struct |
| Max 4 variables | Careful with temps in grow |
| No `for` loops | Use `while` with index |
| No VLAs | Always `malloc`/`ft_calloc` |

## Memory Layout

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

## Comparison with t_list

| Feature | t_list | t_vec |
|---------|--------|-------|
| Access by index | O(n) | O(1) |
| Push back | O(n) or O(1)* | O(1) amortized |
| Memory overhead | pointer per node | minimal |
| Cache locality | poor | excellent |
| Insert middle | O(1) after find | O(n) |

*O(1) if tracking tail pointer

## Use Cases

- Building strings dynamically (like StringBuilder)
- Collecting results in parsing
- Stack implementation
- Any scenario needing random access + dynamic size

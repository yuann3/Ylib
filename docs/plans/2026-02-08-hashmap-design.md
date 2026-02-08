# ft_hashmap Design

Date: 2026-02-08

## Overview

A general-purpose hashmap for libft with string keys and void* values. Designed for minishell env vars, configuration parsing, and general lookup needs.

## Design Decisions

| Decision | Choice | Rationale |
|----------|--------|-----------|
| Value ownership | Owning with destructor | Matches `ft_lstclear` pattern |
| Key ownership | Copied (owned) | Safer, caller can free original |
| Collision resolution | Chaining with `t_vec` | Reuses existing code, cache-friendly |
| Load factor | 0.75 with auto-resize | Industry standard, good balance |
| Iteration | Callback-based | Matches `ft_lstiter` pattern |

## Data Structures

```c
// Internal - not exposed in header
typedef struct s_hashmap_entry
{
    char    *key;       // owned, null-terminated
    void    *value;     // owned if del function provided
}   t_hashmap_entry;

// Public
typedef struct s_hashmap
{
    t_vec   **buckets;  // array of t_vec pointers (lazy allocation)
    size_t  size;       // number of entries
    size_t  cap;        // number of buckets
    void    (*del)(void *);  // value destructor (can be NULL)
}   t_hashmap;
```

## API

```c
// Lifecycle
t_hashmap   *ft_hashmap_new(size_t init_cap, void (*del)(void *));
void        ft_hashmap_free(t_hashmap *map);
void        ft_hashmap_clear(t_hashmap *map);

// Operations
int         ft_hashmap_set(t_hashmap *map, const char *key, void *value);
void        *ft_hashmap_get(t_hashmap *map, const char *key);
int         ft_hashmap_has(t_hashmap *map, const char *key);
int         ft_hashmap_del(t_hashmap *map, const char *key);

// Iteration
void        ft_hashmap_iter(t_hashmap *map, void (*fn)(const char *, void *));

// Utility
size_t      ft_hashmap_size(t_hashmap *map);
```

### Behavior

- `ft_hashmap_new`: If `init_cap` is 0, defaults to 16. Returns NULL on failure.
- `ft_hashmap_set`: Overwrites if key exists (frees old value if `del` set). Returns 1 success, 0 failure.
- `ft_hashmap_get`: Returns NULL if not found.
- `ft_hashmap_del`: Returns 1 if deleted, 0 if key not found.
- `ft_hashmap_clear`: Removes all entries, keeps bucket array.
- `ft_hashmap_free`: Frees everything including the map itself.

## Hash Function

djb2 - simple, fast, good distribution:

```c
static size_t   hashmap_hash(const char *key)
{
    size_t  hash;

    hash = 5381;
    while (*key)
    {
        hash = ((hash << 5) + hash) + *key;
        key++;
    }
    return (hash);
}
```

## File Organization

```
srcs/ft_hashmap/
    ft_hashmap_new.c   # new, free, clear
    ft_hashmap_set.c   # set + static: hash, grow, find_entry
    ft_hashmap_get.c   # get, has, del
    ft_hashmap_iter.c  # iter, size
```

## Implementation Order

1. `ft_hashmap_new.c` - lifecycle functions
2. `ft_hashmap_set.c` - insert with hash/grow helpers
3. `ft_hashmap_get.c` - lookup and delete
4. `ft_hashmap_iter.c` - iteration utilities

## 42 Norm Compliance

- Max 25 lines per function
- Max 5 functions per file
- Max 80 chars per line
- `while` loops only (no `for`)
- Variables declared at function start

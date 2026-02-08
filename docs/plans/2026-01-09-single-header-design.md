# Single-Header Library Design

**Date:** 2026-01-09
**Branch:** feature/single-header-library
**Status:** Approved

## Overview

Transform Ylib into an STB-style single-header library for easy distribution. Users can drop one file into any project without needing a build system.

## Design Decisions

| Decision | Choice | Rationale |
|----------|--------|-----------|
| Goal | Easy distribution | One file, zero friction |
| Norminette | Stay compliant | Keep usable in 42 ecosystem |
| Model | STB-style `#define LIBFT_IMPLEMENTATION` | Proven pattern, no duplicate symbols |
| Modularity | All-or-nothing | Keep it simple |
| Generation | Makefile target + shell script | Stays in sync with modular sources |
| Output | `release/libft.h` | Separate from dist/ submission files |
| Internal functions | Keep public | Simpler, no code changes needed |

## File Structure

The generated `release/libft.h` will have this structure:

```c
/* ========== HEADER SECTION (always included) ========== */
#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/* Type definitions: t_list, t_vec, t_deque, t_vec2, t_vec3 */
/* Function declarations for all 72 functions */

#endif /* LIBFT_H */

/* ========== IMPLEMENTATION SECTION (conditional) ========== */
#ifdef LIBFT_IMPLEMENTATION

/* All function bodies from 72 .c files */

#endif /* LIBFT_IMPLEMENTATION */
```

## Usage by Consumers

```c
// In exactly ONE .c file:
#define LIBFT_IMPLEMENTATION
#include "libft.h"

// In all other files:
#include "libft.h"
```

## Generation

### Shell Script: `scripts/gen_single_header.sh`

The script will:
1. Read existing `includes/libft.h` for the header section
2. Concatenate all `.c` files from `srcs/` for implementation
3. Strip individual `#include "libft.h"` lines from .c files
4. Wrap implementation in `#ifdef LIBFT_IMPLEMENTATION`
5. Output to `release/libft.h`

### Module Order

Concatenation order (grouped logically):
1. ft_is (character classification)
2. ft_mem (memory)
3. ft_str (strings)
4. ft_put (fd output)
5. ft_printf
6. ft_lst (linked list)
7. ft_vec (dynamic array)
8. ft_deque
9. ft_vec_math

### Makefile Targets

```makefile
single-header: $(NAME)
	@mkdir -p release
	@./scripts/gen_single_header.sh > release/libft.h
	@echo "Generated release/libft.h"

test-single-header: single-header
	$(CC) $(CFLAGS) tests/test_single_header.c -o test_single
	./test_single && echo "Single-header test passed"
```

## Testing

### Smoke Test: `tests/test_single_header.c`

Basic verification that all modules work:
```c
#define LIBFT_IMPLEMENTATION
#include "../release/libft.h"

int main(void)
{
    ft_strlen("test");           // ft_str
    ft_isalpha('a');             // ft_is
    ft_printf("test %d\n", 42);  // ft_printf
    // ... etc
    return (0);
}
```

### Multi-File Linkage Test

Ensures no duplicate symbol errors:
- `test_multi_a.c` - includes `libft.h` (header only)
- `test_multi_b.c` - includes `libft.h` (header only)
- `test_multi_main.c` - defines `LIBFT_IMPLEMENTATION`
- Link all three together

## Files to Create

1. `scripts/gen_single_header.sh` - Generation script
2. `release/` - Output directory
3. `tests/test_single_header.c` - Verification test

## Files to Modify

1. `Makefile` - Add `single-header` and `test-single-header` targets

## Implementation Steps

1. Create `scripts/gen_single_header.sh`
2. Create `release/` directory
3. Update `Makefile` with new targets
4. Create `tests/test_single_header.c`
5. Run `make single-header` and verify output
6. Run `make test-single-header` and verify tests pass

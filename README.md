# Ylib

![GitHub commit activity](https://img.shields.io/github/commit-activity/t/yuann3/Ylib) ![GitHub repo size](https://img.shields.io/github/repo-size/yuann3/Ylib) [![.github/workflows/norminette](https://github.com/yuann3/Ylib/actions/workflows/norminette.yml/badge.svg)](https://github.com/yuann3/Ylib/actions/workflows/norminette.yml)

A C library that reimplements the standard library and extends it with modern data structures and vector math. Ylib provides type-safe generic containers (vector, deque, linked list), 2D/3D vector mathematics for graphics programming, a complete printf implementation, and all essential C utilities. Written to 42 School norminette standards with zero external dependencies.

## Features

- **Standard Library Reimplementation** - Drop-in replacements for string, memory, and character functions
- **Generic Data Structures** - Type-safe vector, deque, and linked list with clean APIs
- **Vector Math** - 2D and 3D vector operations for graphics (fract-ol, cub3d, miniRT)
- **Complete ft_printf** - Full printf implementation supporting all common format specifiers
- **Zero Dependencies** - Pure C with only standard headers (math.h for vector operations)
- **42 Norminette Compliant** - Clean, consistent code style

## Quick Start

```c
#include "libft.h"

int main(void)
{
    t_vec   *numbers;
    int     value;

    // Create a dynamic array of integers
    numbers = ft_vec_new(sizeof(int), 8);

    // Add some values
    value = 42;
    ft_vec_push(numbers, &value);
    value = 100;
    ft_vec_push(numbers, &value);

    // Print using ft_printf
    ft_printf("First: %d, Second: %d\n",
              *(int *)ft_vec_get(numbers, 0),
              *(int *)ft_vec_get(numbers, 1));

    ft_vec_free(numbers);
    return (0);
}
```

**Build and run:**
```bash
make
cc -Wall -Wextra -Werror -I includes main.c -L. -lft -o program
./program
```

**Vector math example:**
```c
#include "libft.h"

int main(void)
{
    t_vec3  position;
    t_vec3  direction;
    t_vec3  result;

    // Create 3D vectors
    position = ft_vec3_new(10.0, 20.0, 30.0);
    direction = ft_vec3_new(1.0, 0.0, 0.0);

    // Normalize and scale
    direction = ft_vec3_norm(direction);
    result = ft_vec3_add(position, ft_vec3_scale(direction, 5.0));

    ft_printf("New position: (%.1f, %.1f, %.1f)\n",
              result.x, result.y, result.z);
    return (0);
}
```

**Build with math library:**
```bash
make
cc -Wall -Wextra -Werror -I includes main.c -L. -lft -lm -o program
./program
```

See [Getting Started](docs/getting-started.md) for detailed setup instructions.

## API Overview

| Module | Functions | Description | Documentation |
|--------|-----------|-------------|---------------|
| **Character** | 5 | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` | [character.md](docs/api/character.md) |
| **String** | 20 | String manipulation, searching, splitting, joining | [string.md](docs/api/string.md) |
| **Memory** | 7 | Memory operations, allocation, comparison | [memory.md](docs/api/memory.md) |
| **Conversion** | 4 | String/integer conversion, case conversion | [conversion.md](docs/api/conversion.md) |
| **Output** | 4 | File descriptor output functions | [output.md](docs/api/output.md) |
| **Printf** | 7 | Formatted output with `%c %s %p %d %i %u %x %X %%` | [printf.md](docs/api/printf.md) |
| **Vec Math** | 23 | 2D/3D vectors: add, sub, scale, dot, cross, norm, lerp, rotate, reflect | [vec-math.md](docs/api/vec-math.md) |

### Data Structures

| Structure | Description | Key Features | Documentation |
|-----------|-------------|--------------|---------------|
| **Linked List** | Singly-linked list | O(1) front insertion, iterator support | [linked-list.md](docs/data-structures/linked-list.md) |
| **Vector** | Dynamic array | O(1) random access, automatic growth | [vector.md](docs/data-structures/vector.md) |
| **Deque** | Double-ended queue | O(1) push/pop both ends, circular buffer | [deque.md](docs/data-structures/deque.md) |

## Build

```bash
make        # Build libft.a
make clean  # Remove object files
make fclean # Remove object files and libft.a
make re     # Rebuild everything
```

## Documentation

- [Getting Started Guide](docs/getting-started.md) - Installation and first program
- **API Reference**
  - [Character Classification](docs/api/character.md)
  - [String Functions](docs/api/string.md)
  - [Memory Functions](docs/api/memory.md)
  - [Conversion Functions](docs/api/conversion.md)
  - [Output Functions](docs/api/output.md)
  - [Printf Implementation](docs/api/printf.md)
  - [Vector Math](docs/api/vec-math.md)
- **Data Structures**
  - [Linked List](docs/data-structures/linked-list.md)
  - [Vector (Dynamic Array)](docs/data-structures/vector.md)
  - [Deque (Double-Ended Queue)](docs/data-structures/deque.md)

## Project Structure

```
Ylib/
├── includes/
│   └── libft.h          # Public API header
├── srcs/
│   ├── ft_is/           # Character classification
│   ├── ft_str/          # String functions
│   ├── ft_mem/          # Memory functions
│   ├── ft_printf/       # Printf implementation
│   ├── ft_put/          # Output functions
│   ├── ft_lst/          # Linked list
│   ├── ft_vec/          # Vector (dynamic array)
│   ├── ft_deque/        # Deque
│   └── ft_vec_math/     # 2D/3D vector math
├── tests/               # Unit tests
├── docs/                # Documentation
├── Makefile
└── README.md
```

## License

[MIT](LICENSE)

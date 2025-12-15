# Getting Started with Ylib

This guide will help you integrate Ylib into your project in under 10 minutes.

## Prerequisites

- C compiler (gcc or clang)
- Make
- Git (for cloning the repository)

## Installation

### 1. Clone the Repository

```bash
git clone https://github.com/yuann3/Ylib.git
cd Ylib
```

### 2. Build the Library

```bash
make
```

This creates `libft.a` in the project root directory.

### 3. Verify the Build

Check that the library was created successfully:

```bash
ls -lh libft.a
```

You should see the static library file with a size of approximately 50-100 KB.

## Your First Program

### Step 1: Create a Source File

Create a file named `hello.c`:

```c
#include "libft.h"

int main(void)
{
    ft_printf("Hello from Ylib!\n");
    return (0);
}
```

### Step 2: Compile

```bash
cc -Wall -Wextra -Werror -I includes hello.c -L. -lft -o hello
```

**Flag explanation:**
- `-Wall -Wextra -Werror`: Enable comprehensive warnings and treat them as errors
- `-I includes`: Add the includes directory to the include search path
- `-L.`: Look for libraries in the current directory
- `-lft`: Link against libft.a

### Step 3: Run

```bash
./hello
```

Output:
```
Hello from Ylib!
```

## Using Data Structures

### Vector Example

```c
#include "libft.h"

int main(void)
{
    t_vec   *vec;
    int     i;
    int     *num;

    // Create a vector to hold integers
    vec = ft_vec_new(sizeof(int), 4);
    if (!vec)
        return (1);

    // Push some numbers
    i = 0;
    while (i < 10)
    {
        ft_vec_push(vec, &i);
        i++;
    }

    // Print them
    i = 0;
    while (i < (int)vec->len)
    {
        num = ft_vec_get(vec, i);
        ft_printf("%d ", *num);
        i++;
    }
    ft_printf("\n");

    // Cleanup
    ft_vec_free(vec);
    return (0);
}
```

Compile and run:
```bash
cc -Wall -Wextra -Werror -I includes vector_demo.c -L. -lft -o vector_demo
./vector_demo
```

Output:
```
0 1 2 3 4 5 6 7 8 9
```

### Deque Example

```c
#include "libft.h"

int main(void)
{
    t_deque *stack;
    int     value;
    int     result;

    // Create a deque (can use as a stack or queue)
    stack = ft_deque_new(sizeof(int), 4);

    // Push elements
    value = 10;
    ft_deque_push_back(stack, &value);
    value = 20;
    ft_deque_push_back(stack, &value);
    value = 30;
    ft_deque_push_back(stack, &value);

    // Pop from back (LIFO - stack behavior)
    while (!ft_deque_is_empty(stack))
    {
        ft_deque_pop_back(stack, &result);
        ft_printf("%d\n", result);
    }

    ft_deque_free(stack);
    return (0);
}
```

Output:
```
30
20
10
```

## Integrating into Your Project

### Option 1: Static Linking (Recommended)

1. Copy `libft.a` and `includes/libft.h` to your project directory
2. Compile with: `cc [flags] yourfile.c -L. -lft -o program`

### Option 2: Makefile Integration

Add to your Makefile:

```makefile
LIBFT_DIR = path/to/Ylib
LIBFT = $(LIBFT_DIR)/libft.a

$(LIBFT):
	make -C $(LIBFT_DIR)

your_program: your_file.c $(LIBFT)
	cc -Wall -Wextra -Werror -I $(LIBFT_DIR)/includes $< -L$(LIBFT_DIR) -lft -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f your_program

fclean: clean
	make -C $(LIBFT_DIR) fclean

re: fclean your_program
```

### Option 3: Submodule (Advanced)

```bash
cd your_project
git submodule add https://github.com/yuann3/Ylib.git lib/Ylib
git submodule update --init --recursive
```

Then use Option 2's Makefile approach with `LIBFT_DIR = lib/Ylib`.

## Common Issues

### "libft.h: No such file or directory"

**Problem:** Compiler can't find the header file.

**Solution:** Add `-I includes` or `-I path/to/Ylib/includes` to your compilation command.

### "undefined reference to ft_*"

**Problem:** Linker can't find the library functions.

**Solution:**
- Ensure `libft.a` exists (run `make` in Ylib directory)
- Add `-L.` or `-L path/to/Ylib` to specify library directory
- Add `-lft` to link against libft.a
- **Order matters:** Put `-L. -lft` **after** your source files

Correct: `cc file.c -L. -lft -o program`
Wrong: `cc -L. -lft file.c -o program`

### Segmentation Fault

**Problem:** Your program crashes.

**Common causes:**
- Not checking return values (NULL from ft_vec_new, ft_deque_new, etc.)
- Accessing freed memory
- Index out of bounds in ft_vec_get or ft_deque_get

**Solution:** Always check return values:

```c
t_vec *vec = ft_vec_new(sizeof(int), 4);
if (!vec)
{
    ft_printf("Error: Failed to create vector\n");
    return (1);
}
```

## Next Steps

Now that you have Ylib working, explore the documentation:

- **Data Structures** (most powerful features)
  - [Vector](data-structures/vector.md) - For fast random access
  - [Deque](data-structures/deque.md) - For efficient push/pop at both ends
  - [Linked List](data-structures/linked-list.md) - For frequent insertions/deletions

- **API Reference**
  - [String Functions](api/string.md) - ft_split, ft_strjoin, etc.
  - [Printf](api/printf.md) - Formatted output
  - [Memory Functions](api/memory.md) - ft_memcpy, ft_calloc, etc.

## Support

Found a bug or have a question?
- Open an issue on [GitHub](https://github.com/yuann3/Ylib/issues)
- Check existing documentation in the [docs](.) directory

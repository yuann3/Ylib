# ft_vec2 / ft_vec3 - Vector Math for libft

Mathematical 2D and 3D vectors for graphics, physics, and geometry operations.

## Use Cases

| Project | Usage |
|---------|-------|
| **fract-ol** | Complex number arithmetic, coordinate transforms |
| **cub3d** | Raycasting, player movement, collision detection |
| **miniRT** | Ray-sphere intersection, lighting, reflections |
| **so_long** | Tile positions, movement vectors |

---

## Data Structures

```c
typedef struct s_vec2
{
    double  x;
    double  y;
}   t_vec2;

typedef struct s_vec3
{
    double  x;
    double  y;
    double  z;
}   t_vec3;
```

### Why `double` instead of `float`?
- Higher precision for raycasting and ray tracing
- Avoids accumulated floating-point errors
- Standard in graphics math libraries
- No significant performance difference on modern CPUs

### Memory Model
- Stack-allocated (no malloc, no leaks)
- Pass by value for simplicity
- Return by value (compiler optimizes with RVO)

```
Stack Frame:
┌─────────────────────┐
│ t_vec3 result       │  24 bytes
├─────────────────────┤
│ t_vec3 b            │  24 bytes
├─────────────────────┤
│ t_vec3 a            │  24 bytes
└─────────────────────┘
```

---

## Constants & Utilities

```c
#define FT_EPSILON 1e-10

static int  ft_vec_is_zero(double len)
{
    return (len < FT_EPSILON && len > -FT_EPSILON);
}
```

**Why epsilon?**
- Floating-point numbers can't represent all values exactly
- `0.1 + 0.2 != 0.3` in floating-point
- Use epsilon for "close enough to zero" comparisons

---

## ft_vec2 Functions

### ft_vec2_new

**Purpose:** Create a 2D vector from components.

```c
t_vec2  ft_vec2_new(double x, double y)
{
    t_vec2  v;

    v.x = x;
    v.y = y;
    return (v);
}
```

---

### ft_vec2_add

**Purpose:** Add two vectors component-wise.

**Math:** `(a.x + b.x, a.y + b.y)`

```c
t_vec2  ft_vec2_add(t_vec2 a, t_vec2 b)
{
    t_vec2  result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return (result);
}
```

**Visual:**
```
    b (2,3)
    ↗
a (1,1) ───→ result (3,4)
```

---

### ft_vec2_sub

**Purpose:** Subtract b from a.

**Math:** `(a.x - b.x, a.y - b.y)`

```c
t_vec2  ft_vec2_sub(t_vec2 a, t_vec2 b)
{
    t_vec2  result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return (result);
}
```

**Use case:** Direction from point b to point a.

---

### ft_vec2_scale

**Purpose:** Multiply vector by scalar.

**Math:** `(v.x * s, v.y * s)`

```c
t_vec2  ft_vec2_scale(t_vec2 v, double s)
{
    t_vec2  result;

    result.x = v.x * s;
    result.y = v.y * s;
    return (result);
}
```

**Use cases:**
- `s > 1`: Stretch vector
- `0 < s < 1`: Shrink vector
- `s < 0`: Reverse direction
- `s = 0`: Zero vector

---

### ft_vec2_dot

**Purpose:** Compute dot product (scalar product).

**Math:** `a.x * b.x + a.y * b.y`

```c
double  ft_vec2_dot(t_vec2 a, t_vec2 b)
{
    return (a.x * b.x + a.y * b.y);
}
```

**Properties:**
| Condition | Result | Meaning |
|-----------|--------|---------|
| `dot > 0` | Positive | Vectors point same direction |
| `dot = 0` | Zero | Vectors are perpendicular |
| `dot < 0` | Negative | Vectors point opposite directions |

**Use case:** `dot(v, v) = |v|²` (squared length)

---

### ft_vec2_len

**Purpose:** Compute vector magnitude (length).

**Math:** `√(x² + y²)`

```c
double  ft_vec2_len(t_vec2 v)
{
    return (sqrt(v.x * v.x + v.y * v.y));
}
```

**Edge case:** Zero vector returns 0.0

**Note:** Requires `#include <math.h>` and `-lm` flag.

---

### ft_vec2_len_sq

**Purpose:** Compute squared length (avoids sqrt).

**Math:** `x² + y²`

```c
double  ft_vec2_len_sq(t_vec2 v)
{
    return (v.x * v.x + v.y * v.y);
}
```

**Why?**
- Faster than `ft_vec2_len` (no sqrt)
- Useful for distance comparisons: `len_sq(a) < len_sq(b)` is equivalent to `len(a) < len(b)`

---

### ft_vec2_norm

**Purpose:** Normalize vector to unit length.

**Math:** `v / |v|`

**Edge case:** Zero vector cannot be normalized (division by zero).

```c
t_vec2  ft_vec2_norm(t_vec2 v)
{
    double  len;
    t_vec2  result;

    len = ft_vec2_len(v);
    if (len < FT_EPSILON)
        return (ft_vec2_new(0, 0));
    result.x = v.x / len;
    result.y = v.y / len;
    return (result);
}
```

**Properties:**
- `|norm(v)| = 1` (unit vector)
- Direction preserved, magnitude = 1

---

### ft_vec2_dist

**Purpose:** Distance between two points.

**Math:** `|b - a|`

```c
double  ft_vec2_dist(t_vec2 a, t_vec2 b)
{
    return (ft_vec2_len(ft_vec2_sub(b, a)));
}
```

---

### ft_vec2_lerp

**Purpose:** Linear interpolation between two vectors.

**Math:** `a + t * (b - a)` or `a * (1 - t) + b * t`

```c
t_vec2  ft_vec2_lerp(t_vec2 a, t_vec2 b, double t)
{
    t_vec2  result;

    result.x = a.x + t * (b.x - a.x);
    result.y = a.y + t * (b.y - a.y);
    return (result);
}
```

**Properties:**
- `t = 0`: Returns a
- `t = 1`: Returns b
- `t = 0.5`: Returns midpoint

---

### ft_vec2_rotate

**Purpose:** Rotate vector by angle (radians).

**Math:** Rotation matrix:
```
[cos θ  -sin θ] [x]   [x cos θ - y sin θ]
[sin θ   cos θ] [y] = [x sin θ + y cos θ]
```

```c
t_vec2  ft_vec2_rotate(t_vec2 v, double angle)
{
    t_vec2  result;
    double  c;
    double  s;

    c = cos(angle);
    s = sin(angle);
    result.x = v.x * c - v.y * s;
    result.y = v.x * s + v.y * c;
    return (result);
}
```

---

## ft_vec3 Functions

### ft_vec3_new

```c
t_vec3  ft_vec3_new(double x, double y, double z)
{
    t_vec3  v;

    v.x = x;
    v.y = y;
    v.z = z;
    return (v);
}
```

---

### ft_vec3_add

```c
t_vec3  ft_vec3_add(t_vec3 a, t_vec3 b)
{
    t_vec3  result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return (result);
}
```

---

### ft_vec3_sub

```c
t_vec3  ft_vec3_sub(t_vec3 a, t_vec3 b)
{
    t_vec3  result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return (result);
}
```

---

### ft_vec3_scale

```c
t_vec3  ft_vec3_scale(t_vec3 v, double s)
{
    t_vec3  result;

    result.x = v.x * s;
    result.y = v.y * s;
    result.z = v.z * s;
    return (result);
}
```

---

### ft_vec3_dot

```c
double  ft_vec3_dot(t_vec3 a, t_vec3 b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}
```

---

### ft_vec3_cross

**Purpose:** Compute cross product (perpendicular vector).

**Math:**
```
a × b = (a.y * b.z - a.z * b.y,
         a.z * b.x - a.x * b.z,
         a.x * b.y - a.y * b.x)
```

```c
t_vec3  ft_vec3_cross(t_vec3 a, t_vec3 b)
{
    t_vec3  result;

    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return (result);
}
```

**Properties:**
- Result is perpendicular to both a and b
- `|a × b| = |a| * |b| * sin(θ)`
- `a × b = -(b × a)` (anti-commutative)
- Used for: surface normals, rotation axes

**Visual (Right-hand rule):**
```
        z (result)
        ↑
        │
        │
        └───→ y (b)
       ╱
      ╱
     x (a)
```

---

### ft_vec3_len

```c
double  ft_vec3_len(t_vec3 v)
{
    return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}
```

---

### ft_vec3_len_sq

```c
double  ft_vec3_len_sq(t_vec3 v)
{
    return (v.x * v.x + v.y * v.y + v.z * v.z);
}
```

---

### ft_vec3_norm

```c
t_vec3  ft_vec3_norm(t_vec3 v)
{
    double  len;
    t_vec3  result;

    len = ft_vec3_len(v);
    if (len < FT_EPSILON)
        return (ft_vec3_new(0, 0, 0));
    result.x = v.x / len;
    result.y = v.y / len;
    result.z = v.z / len;
    return (result);
}
```

---

### ft_vec3_dist

```c
double  ft_vec3_dist(t_vec3 a, t_vec3 b)
{
    return (ft_vec3_len(ft_vec3_sub(b, a)));
}
```

---

### ft_vec3_lerp

```c
t_vec3  ft_vec3_lerp(t_vec3 a, t_vec3 b, double t)
{
    t_vec3  result;

    result.x = a.x + t * (b.x - a.x);
    result.y = a.y + t * (b.y - a.y);
    result.z = a.z + t * (b.z - a.z);
    return (result);
}
```

---

### ft_vec3_reflect

**Purpose:** Reflect vector off a surface with given normal.

**Math:** `v - 2 * dot(v, n) * n`

**Use case:** Light reflection in ray tracing.

```c
t_vec3  ft_vec3_reflect(t_vec3 v, t_vec3 normal)
{
    double  d;

    d = 2.0 * ft_vec3_dot(v, normal);
    return (ft_vec3_sub(v, ft_vec3_scale(normal, d)));
}
```

**Visual:**
```
    v ↘     ↗ reflect(v, n)
       ↘   ↗
        ↘ ↗
   ───────────── surface
          ↑
          n (normal)
```

---

### ft_vec3_negate

**Purpose:** Reverse vector direction.

```c
t_vec3  ft_vec3_negate(t_vec3 v)
{
    return (ft_vec3_new(-v.x, -v.y, -v.z));
}
```

---

## Edge Cases Summary

| Operation | Edge Case | Handling |
|-----------|-----------|----------|
| `norm()` | Zero vector | Return zero vector (avoid div by 0) |
| `norm()` | Very small vector | Use epsilon threshold |
| `cross()` | Parallel vectors | Returns zero vector (correct) |
| `dot()` | Zero vector | Returns 0 (correct) |
| `scale(v, 0)` | Any vector | Returns zero vector (correct) |
| `len()` | Very large components | Potential overflow (use `hypot` if needed) |

---

## Norminette Compliance

| Rule | Solution |
|------|----------|
| Max 25 lines/function | All functions are short |
| Max 4 variables | Careful with temps |
| Max 5 params | All functions have ≤ 3 params |
| No `for` loops | Not needed |
| 42 header | Required on all files |

---

## File Organization

```
srcs/
└── ft_vec_math/
    ├── ft_vec2_basic.c      (new, add, sub, scale, negate)
    ├── ft_vec2_ops.c        (dot, len, len_sq, norm, dist)
    ├── ft_vec2_transform.c  (lerp, rotate)
    ├── ft_vec3_basic.c      (new, add, sub, scale, negate)
    ├── ft_vec3_ops.c        (dot, cross, len, len_sq, norm, dist)
    └── ft_vec3_transform.c  (lerp, reflect)
```

---

## Header Additions

```c
/* Epsilon for floating-point comparisons */
# define FT_EPSILON 1e-10

/* 2D Vector */
typedef struct s_vec2
{
    double  x;
    double  y;
}   t_vec2;

/* 3D Vector */
typedef struct s_vec3
{
    double  x;
    double  y;
    double  z;
}   t_vec3;

/* ft_vec2 functions */
t_vec2  ft_vec2_new(double x, double y);
t_vec2  ft_vec2_add(t_vec2 a, t_vec2 b);
t_vec2  ft_vec2_sub(t_vec2 a, t_vec2 b);
t_vec2  ft_vec2_scale(t_vec2 v, double s);
t_vec2  ft_vec2_negate(t_vec2 v);
double  ft_vec2_dot(t_vec2 a, t_vec2 b);
double  ft_vec2_len(t_vec2 v);
double  ft_vec2_len_sq(t_vec2 v);
t_vec2  ft_vec2_norm(t_vec2 v);
double  ft_vec2_dist(t_vec2 a, t_vec2 b);
t_vec2  ft_vec2_lerp(t_vec2 a, t_vec2 b, double t);
t_vec2  ft_vec2_rotate(t_vec2 v, double angle);

/* ft_vec3 functions */
t_vec3  ft_vec3_new(double x, double y, double z);
t_vec3  ft_vec3_add(t_vec3 a, t_vec3 b);
t_vec3  ft_vec3_sub(t_vec3 a, t_vec3 b);
t_vec3  ft_vec3_scale(t_vec3 v, double s);
t_vec3  ft_vec3_negate(t_vec3 v);
double  ft_vec3_dot(t_vec3 a, t_vec3 b);
t_vec3  ft_vec3_cross(t_vec3 a, t_vec3 b);
double  ft_vec3_len(t_vec3 v);
double  ft_vec3_len_sq(t_vec3 v);
t_vec3  ft_vec3_norm(t_vec3 v);
double  ft_vec3_dist(t_vec3 a, t_vec3 b);
t_vec3  ft_vec3_lerp(t_vec3 a, t_vec3 b, double t);
t_vec3  ft_vec3_reflect(t_vec3 v, t_vec3 normal);
```

---

## Usage Examples

### Ray-Sphere Intersection (miniRT)

```c
int hit_sphere(t_vec3 center, double radius, t_ray ray)
{
    t_vec3  oc;
    double  a;
    double  b;
    double  c;
    double  discriminant;

    oc = ft_vec3_sub(ray.origin, center);
    a = ft_vec3_dot(ray.direction, ray.direction);
    b = 2.0 * ft_vec3_dot(oc, ray.direction);
    c = ft_vec3_dot(oc, oc) - radius * radius;
    discriminant = b * b - 4 * a * c;
    return (discriminant > 0);
}
```

### Player Movement (cub3d)

```c
void move_player(t_player *p, double speed)
{
    t_vec2  forward;
    t_vec2  movement;

    forward = ft_vec2_new(cos(p->angle), sin(p->angle));
    movement = ft_vec2_scale(forward, speed);
    p->pos = ft_vec2_add(p->pos, movement);
}

void rotate_player(t_player *p, double angle)
{
    p->dir = ft_vec2_rotate(p->dir, angle);
    p->plane = ft_vec2_rotate(p->plane, angle);
}
```

### Complex Number (fract-ol)

```c
/* z = z² + c using vec2 as complex number */
t_vec2 complex_square_add(t_vec2 z, t_vec2 c)
{
    t_vec2  result;

    result.x = z.x * z.x - z.y * z.y + c.x;
    result.y = 2.0 * z.x * z.y + c.y;
    return (result);
}

int mandelbrot(t_vec2 c, int max_iter)
{
    t_vec2  z;
    int     i;

    z = ft_vec2_new(0, 0);
    i = 0;
    while (i < max_iter && ft_vec2_len_sq(z) < 4.0)
    {
        z = complex_square_add(z, c);
        i++;
    }
    return (i);
}
```

---

## Compilation

Requires math library:
```bash
cc -Wall -Wextra -Werror -lm main.c libft.a -o program
```

---

## Memory Safety

✅ **No memory leaks possible:**
- All vectors are stack-allocated
- No malloc/free calls
- Pass by value, return by value
- Compiler applies Return Value Optimization (RVO)

✅ **No undefined behavior:**
- Zero vector normalization handled with epsilon check
- No null pointer dereferences (no pointers used)
- No buffer overflows (fixed-size structs)

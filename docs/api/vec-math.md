# Vector Math

2D and 3D vector mathematics for graphics programming, physics simulations, and geometry operations. Stack-allocated vectors with value semantics for high performance.

## Use Cases

| Project | Application |
|---------|-------------|
| **fract-ol** | Complex number arithmetic, coordinate transforms |
| **cub3d** | Raycasting, player movement, collision detection |
| **miniRT** | Ray-sphere intersection, lighting calculations, reflections |
| **so_long** | Tile positions, movement vectors |

## Data Types

```c
typedef struct s_vec2 {
    double x;
    double y;
} t_vec2;

typedef struct s_vec3 {
    double x;
    double y;
    double z;
} t_vec3;
```

**Memory model:**
- Stack-allocated (no malloc, no leaks)
- Pass by value
- Return by value (compiler optimizes with RVO)

---

## 2D Vector Functions

| Function | Description |
|----------|-------------|
| `ft_vec2_new(x, y)` | Create vector from components |
| `ft_vec2_add(a, b)` | Add two vectors |
| `ft_vec2_sub(a, b)` | Subtract b from a |
| `ft_vec2_scale(v, s)` | Multiply by scalar |
| `ft_vec2_dot(a, b)` | Dot product |
| `ft_vec2_len(v)` | Vector length |
| `ft_vec2_len_sq(v)` | Squared length (no sqrt) |
| `ft_vec2_norm(v)` | Normalize to unit length |
| `ft_vec2_dist(a, b)` | Distance between points |
| `ft_vec2_lerp(a, b, t)` | Linear interpolation |
| `ft_vec2_rotate(v, angle)` | Rotate by angle (radians) |

---

## 3D Vector Functions

| Function | Description |
|----------|-------------|
| `ft_vec3_new(x, y, z)` | Create vector from components |
| `ft_vec3_add(a, b)` | Add two vectors |
| `ft_vec3_sub(a, b)` | Subtract b from a |
| `ft_vec3_scale(v, s)` | Multiply by scalar |
| `ft_vec3_negate(v)` | Reverse direction |
| `ft_vec3_dot(a, b)` | Dot product |
| `ft_vec3_cross(a, b)` | Cross product |
| `ft_vec3_len(v)` | Vector length |
| `ft_vec3_len_sq(v)` | Squared length (no sqrt) |
| `ft_vec3_norm(v)` | Normalize to unit length |
| `ft_vec3_dist(a, b)` | Distance between points |
| `ft_vec3_lerp(a, b, t)` | Linear interpolation |
| `ft_vec3_reflect(v, n)` | Reflect off surface |

---

## Detailed Descriptions

### ft_vec2_new

```c
t_vec2 ft_vec2_new(double x, double y);
```

Create a 2D vector from x and y components.

**Parameters:**
- `x`: X component
- `y`: Y component

**Returns:** New vector.

**Example:**
```c
t_vec2 position = ft_vec2_new(10.0, 20.0);
t_vec2 zero = ft_vec2_new(0.0, 0.0);
```

---

### ft_vec2_add

```c
t_vec2 ft_vec2_add(t_vec2 a, t_vec2 b);
```

Add two vectors component-wise.

**Math:** `(a.x + b.x, a.y + b.y)`

**Example:**
```c
t_vec2 a = ft_vec2_new(1.0, 2.0);
t_vec2 b = ft_vec2_new(3.0, 4.0);
t_vec2 result = ft_vec2_add(a, b);  // (4.0, 6.0)
```

**Common uses:**
- Applying velocity to position
- Combining forces in physics
- Translating coordinates

---

### ft_vec2_sub

```c
t_vec2 ft_vec2_sub(t_vec2 a, t_vec2 b);
```

Subtract vector b from vector a.

**Math:** `(a.x - b.x, a.y - b.y)`

**Example:**
```c
t_vec2 target = ft_vec2_new(10.0, 10.0);
t_vec2 current = ft_vec2_new(5.0, 3.0);
t_vec2 direction = ft_vec2_sub(target, current);  // (5.0, 7.0)
```

**Use case:** Calculate direction from one point to another.

---

### ft_vec2_scale

```c
t_vec2 ft_vec2_scale(t_vec2 v, double s);
```

Multiply vector by scalar.

**Math:** `(v.x * s, v.y * s)`

**Example:**
```c
t_vec2 velocity = ft_vec2_new(1.0, 0.0);
t_vec2 fast = ft_vec2_scale(velocity, 5.0);      // (5.0, 0.0)
t_vec2 reverse = ft_vec2_scale(velocity, -1.0);  // (-1.0, 0.0)
```

**Properties:**
- `s > 1`: Stretch vector
- `0 < s < 1`: Shrink vector
- `s < 0`: Reverse direction
- `s = 0`: Zero vector

---

### ft_vec2_dot

```c
double ft_vec2_dot(t_vec2 a, t_vec2 b);
```

Compute dot product (scalar product).

**Math:** `a.x * b.x + a.y * b.y`

**Example:**
```c
t_vec2 a = ft_vec2_new(3.0, 4.0);
t_vec2 b = ft_vec2_new(2.0, 1.0);
double dot = ft_vec2_dot(a, b);  // 10.0
```

**Properties:**
- `dot > 0`: Vectors point in similar direction
- `dot = 0`: Vectors are perpendicular
- `dot < 0`: Vectors point in opposite directions
- `dot(v, v) = |v|²` (squared length)

**Use cases:**
- Check if vectors are perpendicular
- Project one vector onto another
- Calculate angles between vectors

---

### ft_vec2_len

```c
double ft_vec2_len(t_vec2 v);
```

Compute vector magnitude (length).

**Math:** `√(x² + y²)`

**Example:**
```c
t_vec2 v = ft_vec2_new(3.0, 4.0);
double len = ft_vec2_len(v);  // 5.0
```

**Note:** Requires `-lm` flag for linking math library.

---

### ft_vec2_len_sq

```c
double ft_vec2_len_sq(t_vec2 v);
```

Compute squared length (avoids expensive sqrt).

**Math:** `x² + y²`

**Example:**
```c
t_vec2 v = ft_vec2_new(3.0, 4.0);
double len_sq = ft_vec2_len_sq(v);  // 25.0
```

**Why use this?**
- Much faster than `ft_vec2_len` (no sqrt)
- Useful for distance comparisons: `len_sq(a) < len_sq(b)` is equivalent to `len(a) < len(b)`
- Common in collision detection

---

### ft_vec2_norm

```c
t_vec2 ft_vec2_norm(t_vec2 v);
```

Normalize vector to unit length.

**Math:** `v / |v|`

**Example:**
```c
t_vec2 v = ft_vec2_new(3.0, 4.0);
t_vec2 unit = ft_vec2_norm(v);  // (0.6, 0.8)
// ft_vec2_len(unit) == 1.0
```

**Edge case:** Zero vector returns (0, 0) to avoid division by zero.

**Properties:**
- `|norm(v)| = 1` (unit vector)
- Direction preserved, magnitude = 1
- Essential for direction vectors in physics/graphics

---

### ft_vec2_dist

```c
double ft_vec2_dist(t_vec2 a, t_vec2 b);
```

Calculate distance between two points.

**Math:** `|b - a|`

**Example:**
```c
t_vec2 a = ft_vec2_new(0.0, 0.0);
t_vec2 b = ft_vec2_new(3.0, 4.0);
double dist = ft_vec2_dist(a, b);  // 5.0
```

---

### ft_vec2_lerp

```c
t_vec2 ft_vec2_lerp(t_vec2 a, t_vec2 b, double t);
```

Linear interpolation between two vectors.

**Math:** `a + t * (b - a)` or `a * (1 - t) + b * t`

**Example:**
```c
t_vec2 start = ft_vec2_new(0.0, 0.0);
t_vec2 end = ft_vec2_new(10.0, 20.0);
t_vec2 mid = ft_vec2_lerp(start, end, 0.5);  // (5.0, 10.0)
```

**Properties:**
- `t = 0`: Returns a
- `t = 1`: Returns b
- `t = 0.5`: Returns midpoint

**Use cases:**
- Smooth movement between positions
- Animation
- Camera interpolation

---

### ft_vec2_rotate

```c
t_vec2 ft_vec2_rotate(t_vec2 v, double angle);
```

Rotate vector by angle (in radians).

**Math:** Applies 2D rotation matrix

**Example:**
```c
t_vec2 v = ft_vec2_new(1.0, 0.0);
t_vec2 rotated = ft_vec2_rotate(v, M_PI / 2.0);  // (0.0, 1.0)
```

**Use cases:**
- Player rotation in cub3d
- Camera direction
- Vector field transformations

---

### ft_vec3_new

```c
t_vec3 ft_vec3_new(double x, double y, double z);
```

Create a 3D vector from x, y, z components.

**Example:**
```c
t_vec3 position = ft_vec3_new(1.0, 2.0, 3.0);
t_vec3 origin = ft_vec3_new(0.0, 0.0, 0.0);
```

---

### ft_vec3_cross

```c
t_vec3 ft_vec3_cross(t_vec3 a, t_vec3 b);
```

Compute cross product (perpendicular vector).

**Math:**
```
a × b = (a.y * b.z - a.z * b.y,
         a.z * b.x - a.x * b.z,
         a.x * b.y - a.y * b.x)
```

**Example:**
```c
t_vec3 x_axis = ft_vec3_new(1.0, 0.0, 0.0);
t_vec3 y_axis = ft_vec3_new(0.0, 1.0, 0.0);
t_vec3 z_axis = ft_vec3_cross(x_axis, y_axis);  // (0.0, 0.0, 1.0)
```

**Properties:**
- Result is perpendicular to both input vectors
- `|a × b| = |a| * |b| * sin(θ)`
- `a × b = -(b × a)` (anti-commutative)
- Parallel vectors produce zero vector

**Use cases:**
- Calculate surface normals
- Find rotation axes
- Determine if vectors are parallel
- Right-hand coordinate systems

---

### ft_vec3_norm

```c
t_vec3 ft_vec3_norm(t_vec3 v);
```

Normalize vector to unit length.

**Example:**
```c
t_vec3 v = ft_vec3_new(3.0, 0.0, 4.0);
t_vec3 unit = ft_vec3_norm(v);  // (0.6, 0.0, 0.8)
```

**Edge case:** Zero vector returns (0, 0, 0).

---

### ft_vec3_reflect

```c
t_vec3 ft_vec3_reflect(t_vec3 v, t_vec3 normal);
```

Reflect vector off surface with given normal.

**Math:** `v - 2 * dot(v, n) * n`

**Example:**
```c
t_vec3 incoming = ft_vec3_new(1.0, -1.0, 0.0);
t_vec3 normal = ft_vec3_new(0.0, 1.0, 0.0);
t_vec3 reflected = ft_vec3_reflect(incoming, normal);  // (1.0, 1.0, 0.0)
```

**Use case:** Light reflection in ray tracing (miniRT).

**Note:** Normal should be unit length for correct results.

---

## Complete Examples

### Ray-Sphere Intersection (miniRT)

```c
int hit_sphere(t_vec3 center, double radius, t_ray ray)
{
    t_vec3  oc;
    double  a, b, c;
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

### Complex Number Math (fract-ol)

```c
// Use vec2 as complex number (real, imaginary)
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

## Building with Vector Math

Vector math requires the math library:

```bash
cc -Wall -Wextra -Werror -I includes main.c -L. -lft -lm -o program
```

**Note:** The `-lm` flag links the math library (required for `sqrt`, `sin`, `cos`).

---

## Performance Notes

- **Stack allocation**: No malloc overhead
- **Value semantics**: Compiler optimizes with RVO (Return Value Optimization)
- **Use `len_sq` for comparisons**: Avoid expensive `sqrt` when possible
- **Prefer `double`**: Higher precision, no significant performance difference on modern CPUs
- **Zero vector handling**: Normalization returns zero vector (no crashes)

---

## Related Documentation

- [Getting Started](../getting-started.md)
- [Data Structures](../data-structures/)

/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/18 18:42:23 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/16 13:28:37 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_vec2
{
	double	x;
	double	y;
}			t_vec2;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

/* ************************************************************************** */
/*                              2D Vector Math                                */
/* ************************************************************************** */

/**
 * @brief Create a 2D vector from components.
 * @param x X component.
 * @param y Y component.
 * @return New vector with specified components.
 */
t_vec2		ft_vec2_new(double x, double y);

/**
 * @brief Add two 2D vectors component-wise.
 * @param a First vector.
 * @param b Second vector.
 * @return Sum of vectors (a.x + b.x, a.y + b.y).
 */
t_vec2		ft_vec2_add(t_vec2 a, t_vec2 b);

/**
 * @brief Subtract vector b from vector a.
 * @param a First vector.
 * @param b Second vector.
 * @return Difference (a.x - b.x, a.y - b.y).
 */
t_vec2		ft_vec2_sub(t_vec2 a, t_vec2 b);

/**
 * @brief Multiply vector by scalar.
 * @param v Vector to scale.
 * @param s Scalar multiplier.
 * @return Scaled vector (v.x * s, v.y * s).
 */
t_vec2		ft_vec2_scale(t_vec2 v, double s);

/**
 * @brief Compute dot product of two vectors.
 * @param a First vector.
 * @param b Second vector.
 * @return Dot product (a.x * b.x + a.y * b.y).
 */
double		ft_vec2_dot(t_vec2 a, t_vec2 b);

/**
 * @brief Compute vector magnitude.
 * @param v Vector.
 * @return Length √(x² + y²).
 */
double		ft_vec2_len(t_vec2 v);

/**
 * @brief Compute squared length (avoids sqrt).
 * @param v Vector.
 * @return Squared length x² + y².
 */
double		ft_vec2_len_sq(t_vec2 v);

/**
 * @brief Normalize vector to unit length.
 * @param v Vector to normalize.
 * @return Unit vector with same direction, or zero vector if input is zero.
 */
t_vec2		ft_vec2_norm(t_vec2 v);

/**
 * @brief Distance between two points.
 * @param a First point.
 * @param b Second point.
 * @return Distance |b - a|.
 */
double		ft_vec2_dist(t_vec2 a, t_vec2 b);

/**
 * @brief Linear interpolation between two vectors.
 * @param a Start vector (t=0).
 * @param b End vector (t=1).
 * @param t Interpolation parameter.
 * @return Interpolated vector a + t * (b - a).
 */
t_vec2		ft_vec2_lerp(t_vec2 a, t_vec2 b, double t);

/**
 * @brief Rotate vector by angle (radians).
 * @param v Vector to rotate.
 * @param angle Rotation angle in radians.
 * @return Rotated vector.
 */
t_vec2		ft_vec2_rotate(t_vec2 v, double angle);

/* ************************************************************************** */
/*                              3D Vector Math                                */
/* ************************************************************************** */

/**
 * @brief Create a 3D vector from components.
 * @param x X component.
 * @param y Y component.
 * @param z Z component.
 * @return New vector with specified components.
 */
t_vec3		ft_vec3_new(double x, double y, double z);

/**
 * @brief Add two 3D vectors component-wise.
 * @param a First vector.
 * @param b Second vector.
 * @return Sum of vectors (a.x + b.x, a.y + b.y, a.z + b.z).
 */
t_vec3		ft_vec3_add(t_vec3 a, t_vec3 b);

/**
 * @brief Subtract vector b from vector a.
 * @param a First vector.
 * @param b Second vector.
 * @return Difference (a.x - b.x, a.y - b.y, a.z - b.z).
 */
t_vec3		ft_vec3_sub(t_vec3 a, t_vec3 b);

/**
 * @brief Multiply vector by scalar.
 * @param v Vector to scale.
 * @param s Scalar multiplier.
 * @return Scaled vector (v.x * s, v.y * s, v.z * s).
 */
t_vec3		ft_vec3_scale(t_vec3 v, double s);

/**
 * @brief Negate a vector (reverse direction).
 * @param v Vector to negate.
 * @return Negated vector (-v.x, -v.y, -v.z).
 */
t_vec3		ft_vec3_negate(t_vec3 v);

/**
 * @brief Compute dot product of two vectors.
 * @param a First vector.
 * @param b Second vector.
 * @return Dot product (a.x * b.x + a.y * b.y + a.z * b.z).
 */
double		ft_vec3_dot(t_vec3 a, t_vec3 b);

/**
 * @brief Compute cross product (perpendicular vector).
 * @param a First vector.
 * @param b Second vector.
 * @return Cross product a × b, perpendicular to both inputs.
 */
t_vec3		ft_vec3_cross(t_vec3 a, t_vec3 b);

/**
 * @brief Compute vector magnitude.
 * @param v Vector.
 * @return Length √(x² + y² + z²).
 */
double		ft_vec3_len(t_vec3 v);

/**
 * @brief Compute squared length (avoids sqrt).
 * @param v Vector.
 * @return Squared length x² + y² + z².
 */
double		ft_vec3_len_sq(t_vec3 v);

/**
 * @brief Normalize vector to unit length.
 * @param v Vector to normalize.
 * @return Unit vector with same direction, or zero vector if input is zero.
 */
t_vec3		ft_vec3_norm(t_vec3 v);

/**
 * @brief Distance between two points.
 * @param a First point.
 * @param b Second point.
 * @return Distance |b - a|.
 */
double		ft_vec3_dist(t_vec3 a, t_vec3 b);

/**
 * @brief Linear interpolation between two vectors.
 * @param a Start vector (t=0).
 * @param b End vector (t=1).
 * @param t Interpolation parameter.
 * @return Interpolated vector a + t * (b - a).
 */
t_vec3		ft_vec3_lerp(t_vec3 a, t_vec3 b, double t);

/**
 * @brief Reflect vector off surface with given normal.
 * @param v Incident vector.
 * @param normal Surface normal (should be unit length).
 * @return Reflected vector v - 2 * dot(v, n) * n.
 */
t_vec3		ft_vec3_reflect(t_vec3 v, t_vec3 normal);

/* ************************************************************************** */
/*                                Linked List                                 */
/* ************************************************************************** */

/**
 * @brief Singly linked list node.
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

/**
 * @brief Create a new list node.
 * @param content Pointer to content for the new node.
 * @return New node with content set and next = NULL, or NULL on failure.
 */
t_list		*ft_lstnew(void *content);

/**
 * @brief Add node at the beginning of a list.
 * @param lst Address of pointer to first node.
 * @param new Node to add.
 */
void		ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Count the number of nodes in a list.
 * @param lst Pointer to first node.
 * @return Number of nodes.
 */
int			ft_lstsize(t_list *lst);

/**
 * @brief Return the last node of a list.
 * @param lst Pointer to first node.
 * @return Last node, or NULL if list is empty.
 */
t_list		*ft_lstlast(t_list *lst);

/**
 * @brief Add node at the end of a list.
 * @param lst Address of pointer to first node.
 * @param new Node to add.
 */
void		ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Delete and free a single node.
 * @param lst Node to delete.
 * @param del Function to free the content.
 */
void		ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Delete and free all nodes in a list.
 * @param lst Address of pointer to first node.
 * @param del Function to free each node's content.
 */
void		ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Apply a function to the content of each node.
 * @param lst Pointer to first node.
 * @param f Function to apply to each content.
 */
void		ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Create a new list by applying a function to each node's content.
 * @param lst Pointer to first node.
 * @param f Function to apply to each content.
 * @param del Function to free content if allocation fails.
 * @return New list, or NULL on failure.
 */
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ************************************************************************** */
/*                              Double-Ended Queue                            */
/* ************************************************************************** */

/**
 * @brief Double-ended queue (deque) using a circular buffer.
 *
 * Provides O(1) push/pop from both ends and O(1) random access.
 * Memory is contiguous and cache-friendly. Ideal for push_swap
 * where rotate operations become O(1) index adjustments.
 */
typedef struct s_deque
{
	void	*data;
	size_t	head;
	size_t	tail;
	size_t	len;
	size_t	cap;
	size_t	elem_size;
}			t_deque;

/* Lifecycle */

/**
 * @brief Create a new deque with specified element size and initial capacity.
 * @param elem_size Size of each element in bytes. Must be > 0.
 * @param init_cap Initial capacity. If 0, defaults to 8.
 * @return Pointer to new deque, or NULL on failure.
 */
t_deque		*ft_deque_new(size_t elem_size, size_t init_cap);

/**
 * @brief Free all memory associated with a deque.
 * @param d Pointer to deque. Safe to call with NULL.
 * @note Does not free elements with internal pointers; caller must handle.
 */
void		ft_deque_free(t_deque *d);

/**
 * @brief Reset deque to empty state without freeing memory.
 * @param d Pointer to deque. Safe to call with NULL.
 */
void		ft_deque_clear(t_deque *d);

/* Push/Pop */

/**
 * @brief Add element to front of deque.
 * @param d Pointer to deque.
 * @param elem Pointer to element to copy.
 * @return 1 on success, 0 on failure (NULL args or allocation failure).
 * @note Grows capacity automatically when full. O(1) amortized.
 */
int			ft_deque_push_front(t_deque *d, const void *elem);

/**
 * @brief Add element to back of deque.
 * @param d Pointer to deque.
 * @param elem Pointer to element to copy.
 * @return 1 on success, 0 on failure (NULL args or allocation failure).
 * @note Grows capacity automatically when full. O(1) amortized.
 */
int			ft_deque_push_back(t_deque *d, const void *elem);

/**
 * @brief Remove and optionally return first element.
 * @param d Pointer to deque.
 * @param out Output buffer for removed element. Can be NULL to discard.
 * @return 1 on success, 0 if deque is NULL or empty.
 */
int			ft_deque_pop_front(t_deque *d, void *out);

/**
 * @brief Remove and optionally return last element.
 * @param d Pointer to deque.
 * @param out Output buffer for removed element. Can be NULL to discard.
 * @return 1 on success, 0 if deque is NULL or empty.
 */
int			ft_deque_pop_back(t_deque *d, void *out);

/* push_swap operations */

/**
 * @brief Swap the first two elements (sa/sb in push_swap).
 * @param d Pointer to deque.
 * @note No-op if deque has fewer than 2 elements or malloc fails for large
 *       elements. Uses stack buffer for elem_size <= 64, heap otherwise.
 */
void		ft_deque_swap(t_deque *d);

/**
 * @brief Rotate: move first element to back (ra/rb in push_swap).
 * @param d Pointer to deque.
 * @note O(1) - only adjusts indices, no data movement.
 */
void		ft_deque_rotate(t_deque *d);

/**
 * @brief Reverse rotate: move last element to front (rra/rrb in push_swap).
 * @param d Pointer to deque.
 * @note O(1) - only adjusts indices, no data movement.
 */
void		ft_deque_rrotate(t_deque *d);

/* Access */

/**
 * @brief Get pointer to first element without removing.
 * @param d Pointer to deque.
 * @return Pointer to first element, or NULL if empty/NULL.
 */
void		*ft_deque_front(t_deque *d);

/**
 * @brief Get pointer to last element without removing.
 * @param d Pointer to deque.
 * @return Pointer to last element, or NULL if empty/NULL.
 */
void		*ft_deque_back(t_deque *d);

/**
 * @brief Get pointer to element at logical index.
 * @param d Pointer to deque.
 * @param index Logical index (0 = front).
 * @return Pointer to element, or NULL if out of bounds/NULL.
 * @note O(1) random access.
 */
void		*ft_deque_get(t_deque *d, size_t index);

/* Utility */

/**
 * @brief Check if deque is empty.
 * @param d Pointer to deque.
 * @return 1 if empty or NULL, 0 otherwise.
 */
int			ft_deque_is_empty(t_deque *d);

/**
 * @brief Check if deque is at capacity.
 * @param d Pointer to deque.
 * @return 1 if full, 0 if not full or NULL.
 */
int			ft_deque_is_full(t_deque *d);

/* ************************************************************************** */
/*                           Vector / dynamic array                           */
/* ************************************************************************** */

/**
 * @brief Dynamic array (vector) with automatic resizing.
 *
 * Provides O(1) amortized push/pop at the end and O(1) random access.
 * Elements are stored contiguously for cache efficiency.
 */
typedef struct s_vec
{
	void	*data;
	size_t	len;
	size_t	cap;
	size_t	elem_size;
}			t_vec;

/**
 * @brief Create a new vector with specified element size and initial capacity.
 * @param elem_size Size of each element in bytes. Must be > 0.
 * @param init_cap Initial capacity. If 0, defaults to a reasonable size.
 * @return Pointer to new vector, or NULL on failure.
 */
t_vec		*ft_vec_new(size_t elem_size, size_t init_cap);

/**
 * @brief Append an element to the end of the vector.
 * @param vec Pointer to vector.
 * @param elem Pointer to element to copy.
 * @return 1 on success, 0 on failure.
 * @note Grows capacity automatically when full. O(1) amortized.
 */
int			ft_vec_push(t_vec *vec, const void *elem);

/**
 * @brief Remove and optionally return the last element.
 * @param vec Pointer to vector.
 * @param out Output buffer for removed element. Can be NULL to discard.
 * @return 1 on success, 0 if vector is NULL or empty.
 */
int			ft_vec_pop(t_vec *vec, void *out);

/**
 * @brief Get pointer to element at index.
 * @param vec Pointer to vector.
 * @param index Index of element (0-based).
 * @return Pointer to element, or NULL if out of bounds/NULL.
 */
void		*ft_vec_get(t_vec *vec, size_t index);

/**
 * @brief Set element at index by copying from elem.
 * @param vec Pointer to vector.
 * @param index Index of element to set.
 * @param elem Pointer to new element value.
 * @return 1 on success, 0 if out of bounds or NULL args.
 */
int			ft_vec_set(t_vec *vec, size_t index, const void *elem);

/**
 * @brief Free all memory associated with a vector.
 * @param vec Pointer to vector. Safe to call with NULL.
 */
void		ft_vec_free(t_vec *vec);

/**
 * @brief Reset vector to empty state without freeing memory.
 * @param vec Pointer to vector. Safe to call with NULL.
 */
void		ft_vec_clear(t_vec *vec);

/**
 * @brief Ensure vector has at least new_cap capacity.
 * @param vec Pointer to vector.
 * @param new_cap Minimum capacity required.
 * @return 1 on success, 0 on failure.
 * @note Does nothing if current capacity >= new_cap.
 */
int			ft_vec_reserve(t_vec *vec, size_t new_cap);

/**
 * @brief Insert an element at the specified index.
 * @param vec Pointer to vector.
 * @param index Index where element will be inserted.
 * @param elem Pointer to element to copy.
 * @return 1 on success, 0 on failure.
 * @note Elements at index and beyond are shifted right. O(n).
 */
int			ft_vec_insert(t_vec *vec, size_t index, const void *elem);

/* ************************************************************************** */
/*                          Character classification                          */
/* ************************************************************************** */

/**
 * @brief Check if character is alphabetic (a-z, A-Z).
 * @param c Character to check.
 * @return Non-zero if alphabetic, 0 otherwise.
 */
int			ft_isalpha(int c);

/**
 * @brief Check if character is a digit (0-9).
 * @param c Character to check.
 * @return Non-zero if digit, 0 otherwise.
 */
int			ft_isdigit(int c);

/**
 * @brief Check if character is alphanumeric (a-z, A-Z, 0-9).
 * @param c Character to check.
 * @return Non-zero if alphanumeric, 0 otherwise.
 */
int			ft_isalnum(int c);

/**
 * @brief Check if character is in ASCII range (0-127).
 * @param c Character to check.
 * @return Non-zero if ASCII, 0 otherwise.
 */
int			ft_isascii(int c);

/**
 * @brief Check if character is printable (including space).
 * @param c Character to check.
 * @return Non-zero if printable, 0 otherwise.
 */
int			ft_isprint(int c);

/* ************************************************************************** */
/*                             String functions                               */
/* ************************************************************************** */

/**
 * @brief Calculate the length of a string.
 * @param s Null-terminated string.
 * @return Number of characters before the null terminator.
 */
size_t		ft_strlen(const char *s);

/**
 * @brief Locate first occurrence of character in string.
 * @param s Null-terminated string to search.
 * @param c Character to find (converted to char).
 * @return Pointer to first occurrence, or NULL if not found.
 * @note The terminating null is considered part of the string.
 */
char		*ft_strchr(const char *s, int c);

/**
 * @brief Locate last occurrence of character in string.
 * @param s Null-terminated string to search.
 * @param c Character to find (converted to char).
 * @return Pointer to last occurrence, or NULL if not found.
 */
char		*ft_strrchr(const char *s, int c);

/**
 * @brief Compare two strings up to n characters.
 * @param s1 First string.
 * @param s2 Second string.
 * @param n Maximum number of characters to compare.
 * @return <0 if s1 < s2, 0 if equal, >0 if s1 > s2.
 */
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Locate substring in string, searching at most len characters.
 * @param haystack String to search in.
 * @param needle Substring to find.
 * @param len Maximum characters to search.
 * @return Pointer to start of match, or NULL if not found.
 */
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

/**
 * @brief Copy string to buffer with size limit.
 * @param dst Destination buffer.
 * @param src Source string.
 * @param dstsize Size of destination buffer.
 * @return Total length of src (for truncation detection).
 * @note Always null-terminates if dstsize > 0.
 */
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * @brief Append string to buffer with size limit.
 * @param dst Destination buffer (must be null-terminated).
 * @param src Source string to append.
 * @param dstsize Total size of destination buffer.
 * @return Total length of string it tried to create.
 * @note Always null-terminates if dstsize > strlen(dst).
 */
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * @brief Duplicate a string.
 * @param s1 String to duplicate.
 * @return Newly allocated copy, or NULL on failure.
 */
char		*ft_strdup(const char *s1);

/**
 * @brief Extract a substring from a string.
 * @param s Source string.
 * @param start Starting index.
 * @param len Maximum length of substring.
 * @return Newly allocated substring, or NULL on failure.
 */
char		*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Concatenate two strings into a new string.
 * @param s1 First string.
 * @param s2 Second string.
 * @return Newly allocated combined string, or NULL on failure.
 */
char		*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Trim characters from beginning and end of string.
 * @param s1 String to trim.
 * @param set Characters to remove.
 * @return Newly allocated trimmed string, or NULL on failure.
 */
char		*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Split string by delimiter into array of strings.
 * @param s String to split.
 * @param c Delimiter character.
 * @return Null-terminated array of strings, or NULL on failure.
 * @note Caller must free each string and the array.
 */
char		**ft_split(char const *s, char c);

/**
 * @brief Apply function to each character, creating new string.
 * @param s Source string.
 * @param f Function taking index and character, returning new character.
 * @return Newly allocated transformed string, or NULL on failure.
 */
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Apply function to each character in place.
 * @param s String to modify.
 * @param f Function taking index and pointer to character.
 */
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

/* ************************************************************************** */
/*                             Memory functions                               */
/* ************************************************************************** */

/**
 * @brief Fill memory with a constant byte.
 * @param b Pointer to memory area.
 * @param c Byte value to fill (converted to unsigned char).
 * @param len Number of bytes to fill.
 * @return Pointer to memory area b.
 */
void		*ft_memset(void *b, int c, size_t len);

/**
 * @brief Zero out a memory area.
 * @param s Pointer to memory area.
 * @param n Number of bytes to zero.
 */
void		ft_bzero(void *s, size_t n);

/**
 * @brief Copy memory area (non-overlapping).
 * @param dst Destination buffer.
 * @param src Source buffer.
 * @param n Number of bytes to copy.
 * @return Pointer to dst.
 * @note Behavior undefined if regions overlap; use ft_memmove instead.
 */
void		*ft_memcpy(void *dst, const void *src, size_t n);

/**
 * @brief Copy memory area (handles overlapping regions).
 * @param dst Destination buffer.
 * @param src Source buffer.
 * @param len Number of bytes to copy.
 * @return Pointer to dst.
 */
void		*ft_memmove(void *dst, const void *src, size_t len);

/**
 * @brief Locate byte in memory area.
 * @param s Memory area to search.
 * @param c Byte to find (converted to unsigned char).
 * @param n Number of bytes to search.
 * @return Pointer to first occurrence, or NULL if not found.
 */
void		*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compare two memory areas.
 * @param s1 First memory area.
 * @param s2 Second memory area.
 * @param n Number of bytes to compare.
 * @return <0 if s1 < s2, 0 if equal, >0 if s1 > s2.
 */
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Allocate and zero-initialize memory.
 * @param count Number of elements.
 * @param size Size of each element.
 * @return Pointer to allocated memory, or NULL on failure.
 */
void		*ft_calloc(size_t count, size_t size);

/* ************************************************************************** */
/*                          Character conversion                              */
/* ************************************************************************** */

/**
 * @brief Convert lowercase letter to uppercase.
 * @param c Character to convert.
 * @return Uppercase equivalent, or c if not a lowercase letter.
 */
int			ft_toupper(int c);

/**
 * @brief Convert uppercase letter to lowercase.
 * @param c Character to convert.
 * @return Lowercase equivalent, or c if not an uppercase letter.
 */
int			ft_tolower(int c);

/* ************************************************************************** */
/*                          Conversion functions                              */
/* ************************************************************************** */

/**
 * @brief Convert string to integer.
 * @param str String to convert.
 * @return Integer value. Skips leading whitespace and handles +/- sign.
 */
int			ft_atoi(const char *str);

/**
 * @brief Convert integer to string.
 * @param n Integer to convert.
 * @return Newly allocated string representation, or NULL on failure.
 */
char		*ft_itoa(int n);

/* ************************************************************************** */
/*                        File descriptor output                              */
/* ************************************************************************** */

/**
 * @brief Write a character to a file descriptor.
 * @param c Character to write.
 * @param fd File descriptor.
 */
void		ft_putchar_fd(char c, int fd);

/**
 * @brief Write a string to a file descriptor.
 * @param s String to write.
 * @param fd File descriptor.
 */
void		ft_putstr_fd(char *s, int fd);

/**
 * @brief Write a string followed by newline to a file descriptor.
 * @param s String to write.
 * @param fd File descriptor.
 */
void		ft_putendl_fd(char *s, int fd);

/**
 * @brief Write an integer to a file descriptor.
 * @param n Integer to write.
 * @param fd File descriptor.
 */
void		ft_putnbr_fd(int n, int fd);

/* ************************************************************************** */
/*                              ft_printf                                     */
/* ************************************************************************** */

/**
 * @brief Formatted output to stdout.
 * @param format Format string with conversion specifiers.
 * @param ... Variable arguments matching format specifiers.
 * @return Number of characters printed, or -1 on error.
 * @note Supports: %c %s %p %d %i %u %x %X %%
 */
int			ft_printf(const char *format, ...);

/**
 * @brief Print a single character to stdout.
 * @param character Character to print.
 * @return Number of characters printed (1), or -1 on error.
 */
int			ft_print_char(int character);

/**
 * @brief Print a string to stdout.
 * @param str String to print. Prints "(null)" if NULL.
 * @return Number of characters printed, or -1 on error.
 */
int			ft_print_str(char *str);

/**
 * @brief Print a pointer address in hexadecimal.
 * @param ptr Pointer to print.
 * @return Number of characters printed, or -1 on error.
 */
int			ft_print_ptr(void *ptr);

/**
 * @brief Print a signed integer.
 * @param number Integer to print.
 * @return Number of characters printed, or -1 on error.
 */
int			ft_print_nbr(int number);

/**
 * @brief Print an unsigned integer.
 * @param number Unsigned integer to print.
 * @return Number of characters printed, or -1 on error.
 */
int			ft_print_unsigned(unsigned int number);

/**
 * @brief Print an unsigned integer in hexadecimal.
 * @param n Unsigned integer to print.
 * @param uppercase If non-zero, use uppercase hex digits (A-F).
 * @return Number of characters printed, or -1 on error.
 */
int			ft_print_hex(unsigned int n, int uppercase);


/* ************************************************************************** */
/*                                                                            */
/*                         IMPLEMENTATION SECTION                             */
/*                                                                            */
/*    Define LIBFT_IMPLEMENTATION in exactly one .c file before including     */
/*    this header to create the implementation.                               */
/*                                                                            */
/* ************************************************************************** */

#ifdef LIBFT_IMPLEMENTATION


/* ========================================================================== */
/*                                ft_is                                       */
/* ========================================================================== */

/* --- ft_isalnum.c --- */


int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/* --- ft_isalpha.c --- */


int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/* --- ft_isascii.c --- */


int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/* --- ft_isdigit.c --- */


int	ft_isdigit(int n)
{
	if (n >= 48 && n <= 57)
		return (1);
	return (0);
}

/* --- ft_isprint.c --- */


int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}


/* ========================================================================== */
/*                               ft_mem                                       */
/* ========================================================================== */

/* --- ft_bzero.c --- */


void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/* --- ft_calloc.c --- */


void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = count * size;
	if (count != 0 && total_size / count != size)
		return (NULL);
	ptr = malloc(total_size);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}

/* --- ft_memchr.c --- */


void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*p;

	p = str;
	while (n-- != 0)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
	}
	return (NULL);
}

/* --- ft_memcmp.c --- */


int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

/* --- ft_memcpy.c --- */


void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!src && !dest)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

/* --- ft_memmove.c --- */


void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!src && !dst && len != 0)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (dst < src)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}
	return (dst);
}

/* --- ft_memset.c --- */


void	*ft_memset(void *b, int v, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = (unsigned char)v;
	return (b);
}


/* ========================================================================== */
/*                               ft_str                                       */
/* ========================================================================== */

/* --- ft_atoi.c --- */


static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)(sign * result));
}

/* --- ft_itoa.c --- */


static int	ft_numlen(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;

	nbr = n;
	len = ft_numlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

/* --- ft_split.c --- */


static int	split__count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*word_dup(char const *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	*free_split(char **split, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		start;

	if (!s)
		return (NULL);
	split = malloc((split__count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (j < split__count_words(s, c))
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		split[j] = word_dup(s, start, i);
		if (!split[j++])
			return (free_split(split, j - 1));
	}
	split[j] = NULL;
	return (split);
}

/* --- ft_strchr.c --- */


char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

/* --- ft_strcmp.c --- */

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

/* --- ft_strdup.c --- */


char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup;
	char	*temp;

	len = 0;
	while (s[len])
		len++;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	temp = dup;
	while (*s)
		*temp++ = *s++;
	*temp = '\0';
	return (dup);
}

/* --- ft_striteri.c --- */


void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/* --- ft_strjoin.c --- */


char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * i);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[j])
			str[i++] = s1[j++];
	j = 0;
	if (s2)
		while (s2[j])
			str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

/* --- ft_strlcat.c --- */


size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize <= dlen)
		return (dstsize + slen);
	i = 0;
	while (src[i] && dlen + i < dstsize - 1)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}

/* --- ft_strlcpy.c --- */


size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (src[res])
		res++;
	if (destsize < 1)
		return (res);
	while (src[i] && i < destsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (res);
}

/* --- ft_strlen.c --- */


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* --- ft_strmapi.c --- */


char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str_new;
	size_t			s_len;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	str_new = (char *)malloc(sizeof(char) * (s_len + 1));
	if (str_new == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		str_new[i] = f(i, s[i]);
		i++;
	}
	str_new[i] = '\0';
	return (str_new);
}

/* --- ft_strncmp.c --- */


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	unsigned char	i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	c1 = (unsigned char)s1[i];
	c2 = (unsigned char)s2[i];
	return ((c1 > c2) - (c1 < c2));
}

/* --- ft_strnstr.c --- */


char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (i + j < len && haystack[i + j] == needle[j] && needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

/* --- ft_strrchr.c --- */


char	*ft_strrchr(const char *str, int c)
{
	const char	*last_occurrence;

	last_occurrence = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
			last_occurrence = str;
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return ((char *)last_occurrence);
}

/* --- ft_strtrim.c --- */


static int	ft_checkset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_checkset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_checkset(s1[end - 1], set))
		end--;
	len = end - start;
	trimmed = (char *)malloc(sizeof(char) * (len + 1));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, len + 1);
	trimmed[len] = '\0';
	return (trimmed);
}

/* --- ft_substr.c --- */


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}

/* --- ft_tolower.c --- */


int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		c += 32;
	return (c);
}

/* --- ft_toupper.c --- */


int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		c -= 32;
	return (c);
}


/* ========================================================================== */
/*                               ft_put                                       */
/* ========================================================================== */

/* --- ft_putchar_fd.c --- */


void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* --- ft_putendl_fd.c --- */


void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/* --- ft_putnbr_fd.c --- */


static void	putnbr_fd__print_recursive(long nb, int fd)
{
	char	c;

	if (nb >= 10)
		putnbr_fd__print_recursive(nb / 10, fd);
	c = '0' + (nb % 10);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	putnbr_fd__print_recursive(nb, fd);
}

/* --- ft_putstr_fd.c --- */


void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	if (!s)
		return ;
	while (s[len] != '\0')
	{
		write(fd, &s[len], 1);
		len++;
	}
}


/* ========================================================================== */
/*                            ft_printf                                       */
/* ========================================================================== */

/* --- ft_print_char.c --- */


int	ft_print_char(int character)
{
	char	to_print;

	to_print = (char)character;
	if (write(1, &to_print, 1) == -1)
		return (-1);
	return (1);
}

/* --- ft_print_hex.c --- */


static int	print_hex__print_hex_rec(unsigned int n, char *base)
{
	int	len;
	int	check;

	len = 0;
	if (n >= 16)
	{
		check = print_hex__print_hex_rec(n / 16, base);
		if (check == -1)
			return (-1);
		len += check;
	}
	if (write(1, &base[n % 16], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_print_hex(unsigned int n, int uppercase)
{
	if (uppercase == 1)
		return (print_hex__print_hex_rec(n, "0123456789ABCDEF"));
	else
		return (print_hex__print_hex_rec(n, "0123456789abcdef"));
}

/* --- ft_print_nbr.c --- */


static int	print_nbr__print_recursive(unsigned int number)
{
	int	length;
	int	check_error;

	length = 0;
	if (number >= 10)
	{
		check_error = print_nbr__print_recursive(number / 10);
		if (check_error == -1)
			return (-1);
		length += check_error;
	}
	if (write(1, &"0123456789"[number % 10], 1) == -1)
		return (-1);
	return (length + 1);
}

int	ft_print_unsigned(unsigned int number)
{
	return (print_nbr__print_recursive(number));
}

int	ft_print_nbr(int number)
{
	int				length;
	int				check_error;
	unsigned int	unsigned_num;

	length = 0;
	if (number < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		length++;
		unsigned_num = -(unsigned int)number;
	}
	else
		unsigned_num = (unsigned int)number;
	check_error = print_nbr__print_recursive(unsigned_num);
	if (check_error == -1)
		return (-1);
	return (length + check_error);
}

/* --- ft_print_ptr.c --- */


static int	ft_putptr_recursive(unsigned long n)
{
	int	len;
	int	check;

	len = 0;
	if (n >= 16)
	{
		check = ft_putptr_recursive(n / 16);
		if (check == -1)
			return (-1);
		len += check;
	}
	if (write(1, &"0123456789abcdef"[n % 16], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_print_ptr(void *ptr)
{
	int	len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) == -1)
		return (-1);
	len = ft_putptr_recursive((unsigned long)ptr);
	if (len == -1)
		return (-1);
	return (len + 2);
}

/* --- ft_print_str.c --- */


int	ft_print_str(char *str)
{
	int	length;

	if (!str)
		str = "(null)";
	length = ft_strlen(str);
	if (write(1, str, length) == -1)
		return (-1);
	return (length);
}

/* --- ft_printf.c --- */


static int	ft_handle_format(va_list args, char specifier)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	else if (specifier == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	else if (specifier == '%')
		return (ft_print_char('%'));
	return (0);
}

static int	ft_print_format(va_list args, const char **format)
{
	int	result;

	(*format)++;
	result = ft_handle_format(args, **format);
	return (result);
}

static int	ft_parse_format(va_list args, const char *format)
{
	int	total_len;
	int	result;

	total_len = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			result = ft_print_format(args, &format);
			if (result == -1)
				return (-1);
			total_len += result;
		}
		else if (*format != '%')
		{
			if (write(1, format, 1) == -1)
				return (-1);
			total_len++;
		}
		format++;
	}
	return (total_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_len;

	if (!format)
		return (-1);
	va_start(args, format);
	total_len = ft_parse_format(args, format);
	va_end(args);
	return (total_len);
}


/* ========================================================================== */
/*                               ft_lst                                       */
/* ========================================================================== */

/* --- ft_lstadd_back_bonus.c --- */


void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

/* --- ft_lstadd_front_bonus.c --- */


void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

/* --- ft_lstclear_bonus.c --- */


void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;

	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst != NULL)
	{
		next_node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_node;
	}
	*lst = NULL;
}

/* --- ft_lstdelone_bonus.c --- */


void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL && del != NULL)
	{
		del(lst->content);
		free(lst);
	}
}

/* --- ft_lstiter_bonus.c --- */


void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL && f != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* --- ft_lstlast_bonus.c --- */


t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/* --- ft_lstmap_bonus.c --- */


t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/* --- ft_lstnew_bonus.c --- */


t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/* --- ft_lstsize_bonus.c --- */


int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}


/* ========================================================================== */
/*                               ft_vec                                       */
/* ========================================================================== */

/* --- ft_vec_clear.c --- */


/**
 * @brief Reset vector to empty state without freeing memory.
 *
 * Sets length to 0, keeping the allocated capacity intact.
 * Useful for reusing a vector without reallocation overhead.
 *
 * @param vec Pointer to the vector (can be NULL).
 */
void	ft_vec_clear(t_vec *vec)
{
	if (!vec)
		return ;
	vec->len = 0;
}

/* --- ft_vec_free.c --- */


/**
 * @brief Free all memory associated with the vector.
 *
 * Frees both the internal data buffer and the vector struct itself.
 * Safe to call with NULL. Does not free heap-allocated elements
 * stored within the vector (user responsibility).
 *
 * @param vec Pointer to the vector to free (can be NULL).
 */
void	ft_vec_free(t_vec *vec)
{
	if (!vec)
		return ;
	if (vec->data)
		free(vec->data);
	free(vec);
}

/* --- ft_vec_get.c --- */


/**
 * @brief Get a pointer to the element at the specified index.
 *
 * Performs bounds checking and returns NULL if index is out of range.
 * The returned pointer is valid until the next push or reserve operation.
 *
 * @param vec Pointer to the vector.
 * @param index Zero-based index of the element.
 * @return Pointer to the element, or NULL if out of bounds.
 */
void	*ft_vec_get(t_vec *vec, size_t index)
{
	if (!vec || index >= vec->len)
		return (NULL);
	return ((char *)vec->data + (index * vec->elem_size));
}

/* --- ft_vec_insert.c --- */


/**
 * @brief Shift elements right starting from index.
 *
 * Moves elements from index to len-1 one position to the right.
 * Uses memmove to handle overlapping regions safely.
 *
 * @param vec Pointer to the vector.
 * @param index Starting index for the shift.
 */
static void	ft_vec_shift_right(t_vec *vec, size_t index)
{
	void	*src;
	void	*dst;
	size_t	bytes;

	src = (char *)vec->data + (index * vec->elem_size);
	dst = (char *)vec->data + ((index + 1) * vec->elem_size);
	bytes = (vec->len - index) * vec->elem_size;
	ft_memmove(dst, src, bytes);
}

/**
 * @brief Insert an element at the specified index.
 *
 * Shifts existing elements to the right and inserts the new element.
 * Index must be <= len (insert at len is equivalent to push).
 * Grows capacity automatically if needed.
 *
 * @param vec Pointer to the vector.
 * @param index Position to insert at (0 to len).
 * @param elem Pointer to the element to insert.
 * @return 1 on success, 0 on failure or invalid index.
 */
int	ft_vec_insert(t_vec *vec, size_t index, const void *elem)
{
	void	*dst;

	if (!vec || !elem || index > vec->len)
		return (0);
	if (vec->len == vec->cap)
	{
		if (!ft_vec_reserve(vec, vec->cap + vec->cap / 2 + 1))
			return (0);
	}
	if (index < vec->len)
		ft_vec_shift_right(vec, index);
	dst = (char *)vec->data + (index * vec->elem_size);
	ft_memcpy(dst, elem, vec->elem_size);
	vec->len++;
	return (1);
}

/* --- ft_vec_new.c --- */


/**
 * @brief Create a new dynamic array (vector).
 *
 * Allocates and initializes a new vector with the specified element size
 * and initial capacity. If init_cap is 0, defaults to 8 elements.
 *
 * @param elem_size Size of each element in bytes (must be > 0).
 * @param init_cap Initial capacity (0 for default of 8).
 * @return Pointer to newly allocated t_vec, or NULL on failure.
 */
t_vec	*ft_vec_new(size_t elem_size, size_t init_cap)
{
	t_vec	*vec;

	if (elem_size == 0)
		return (NULL);
	vec = ft_calloc(1, sizeof(t_vec));
	if (!vec)
		return (NULL);
	if (init_cap == 0)
		init_cap = 8;
	vec->data = ft_calloc(init_cap, elem_size);
	if (!vec->data)
		return (free(vec), NULL);
	vec->elem_size = elem_size;
	vec->cap = init_cap;
	vec->len = 0;
	return (vec);
}

/* --- ft_vec_pop.c --- */


/**
 * @brief Remove and optionally retrieve the last element.
 *
 * Decrements the vector length. If out is not NULL, copies the
 * removed element to the provided buffer before removal.
 *
 * @param vec Pointer to the vector.
 * @param out Buffer to receive the popped element (can be NULL).
 * @return 1 on success, 0 if vec is NULL or empty.
 */
int	ft_vec_pop(t_vec *vec, void *out)
{
	void	*src;

	if (!vec || vec->len == 0)
		return (0);
	vec->len--;
	if (out)
	{
		src = (char *)vec->data + (vec->len * vec->elem_size);
		ft_memcpy(out, src, vec->elem_size);
	}
	return (1);
}

/* --- ft_vec_push.c --- */


/**
 * @brief Calculate the next capacity for vector growth.
 *
 * Uses 1.5x growth factor for memory efficiency.
 * Returns 0 if overflow would occur.
 *
 * @param cap Current capacity.
 * @return New capacity, or 0 on overflow.
 */
static size_t	ft_vec_next_cap(size_t cap)
{
	size_t	new_cap;

	if (cap == 0)
		return (8);
	if (cap > SIZE_MAX / 2)
		return (0);
	new_cap = cap + cap / 2;
	if (new_cap <= cap)
		new_cap = cap + 1;
	return (new_cap);
}

/**
 * @brief Grow the vector's capacity by 1.5x.
 *
 * Called internally when push would exceed current capacity.
 * Delegates to ft_vec_reserve for the actual reallocation.
 *
 * @param vec Pointer to the vector.
 * @return 1 on success, 0 on allocation failure or overflow.
 */
static int	ft_vec_grow(t_vec *vec)
{
	size_t	new_cap;

	new_cap = ft_vec_next_cap(vec->cap);
	if (new_cap == 0)
		return (0);
	return (ft_vec_reserve(vec, new_cap));
}

/**
 * @brief Append an element to the end of the vector.
 *
 * Copies elem_size bytes from elem to the end of the vector.
 * Automatically grows capacity if needed (1.5x growth factor).
 *
 * @param vec Pointer to the vector.
 * @param elem Pointer to the element to copy.
 * @return 1 on success, 0 on failure or NULL params.
 */
int	ft_vec_push(t_vec *vec, const void *elem)
{
	void	*dst;

	if (!vec || !elem)
		return (0);
	if (vec->len == vec->cap)
	{
		if (!ft_vec_grow(vec))
			return (0);
	}
	dst = (char *)vec->data + (vec->len * vec->elem_size);
	ft_memcpy(dst, elem, vec->elem_size);
	vec->len++;
	return (1);
}

/* --- ft_vec_reserve.c --- */


/**
 * @brief Ensure vector has at least the specified capacity.
 *
 * If new_cap is greater than current capacity, reallocates the
 * internal buffer. Existing elements are preserved. Does nothing
 * if new_cap <= current capacity.
 *
 * @param vec Pointer to the vector.
 * @param new_cap Minimum required capacity.
 * @return 1 on success, 0 on allocation failure or overflow.
 */
int	ft_vec_reserve(t_vec *vec, size_t new_cap)
{
	void	*new_data;

	if (!vec)
		return (0);
	if (new_cap <= vec->cap)
		return (1);
	if (new_cap > SIZE_MAX / vec->elem_size)
		return (0);
	new_data = ft_calloc(new_cap, vec->elem_size);
	if (!new_data)
		return (0);
	ft_memcpy(new_data, vec->data, vec->len * vec->elem_size);
	free(vec->data);
	vec->data = new_data;
	vec->cap = new_cap;
	return (1);
}

/* --- ft_vec_set.c --- */


/**
 * @brief Set the value of an element at the specified index.
 *
 * Copies elem_size bytes from elem to the element at index.
 * Index must be within current length (cannot extend vector).
 *
 * @param vec Pointer to the vector.
 * @param index Zero-based index of the element to set.
 * @param elem Pointer to the source data.
 * @return 1 on success, 0 if out of bounds or NULL params.
 */
int	ft_vec_set(t_vec *vec, size_t index, const void *elem)
{
	void	*dst;

	if (!vec || !elem || index >= vec->len)
		return (0);
	dst = (char *)vec->data + (index * vec->elem_size);
	ft_memcpy(dst, elem, vec->elem_size);
	return (1);
}


/* ========================================================================== */
/*                             ft_deque                                       */
/* ========================================================================== */

/* --- ft_deque_access.c --- */


void	*ft_deque_front(t_deque *d)
{
	if (!d || d->len == 0)
		return (NULL);
	return ((char *)d->data + (d->head * d->elem_size));
}

void	*ft_deque_back(t_deque *d)
{
	size_t	back_idx;

	if (!d || d->len == 0)
		return (NULL);
	back_idx = (d->tail - 1 + d->cap) % d->cap;
	return ((char *)d->data + (back_idx * d->elem_size));
}

void	*ft_deque_get(t_deque *d, size_t index)
{
	size_t	phys_idx;

	if (!d || index >= d->len)
		return (NULL);
	phys_idx = (d->head + index) % d->cap;
	return ((char *)d->data + (phys_idx * d->elem_size));
}

/* --- ft_deque_new.c --- */


t_deque	*ft_deque_new(size_t elem_size, size_t init_cap)
{
	t_deque	*d;

	if (elem_size == 0)
		return (NULL);
	d = ft_calloc(1, sizeof(t_deque));
	if (!d)
		return (NULL);
	if (init_cap == 0)
		init_cap = 8;
	d->data = ft_calloc(init_cap, elem_size);
	if (!d->data)
		return (free(d), NULL);
	d->elem_size = elem_size;
	d->cap = init_cap;
	d->head = 0;
	d->tail = 0;
	d->len = 0;
	return (d);
}

void	ft_deque_clear(t_deque *d)
{
	if (!d)
		return ;
	d->head = 0;
	d->tail = 0;
	d->len = 0;
}

/* --- ft_deque_pop.c --- */


int	ft_deque_pop_front(t_deque *d, void *out)
{
	void	*src;

	if (!d || d->len == 0)
		return (0);
	if (out)
	{
		src = (char *)d->data + (d->head * d->elem_size);
		ft_memcpy(out, src, d->elem_size);
	}
	d->head = (d->head + 1) % d->cap;
	d->len--;
	return (1);
}

int	ft_deque_pop_back(t_deque *d, void *out)
{
	void	*src;

	if (!d || d->len == 0)
		return (0);
	d->tail = (d->tail - 1 + d->cap) % d->cap;
	if (out)
	{
		src = (char *)d->data + (d->tail * d->elem_size);
		ft_memcpy(out, src, d->elem_size);
	}
	d->len--;
	return (1);
}

/* --- ft_deque_push.c --- */


static void	deque_push__copy_linearized(t_deque *d, void *new_data)
{
	size_t	i;
	void	*src;
	void	*dst;

	i = 0;
	while (i < d->len)
	{
		src = (char *)d->data + (((d->head + i) % d->cap) * d->elem_size);
		dst = (char *)new_data + (i * d->elem_size);
		ft_memcpy(dst, src, d->elem_size);
		i++;
	}
}

static int	ft_deque_grow(t_deque *d)
{
	void	*new_data;
	size_t	new_cap;

	new_cap = d->cap * 2;
	if (new_cap < d->cap)
		return (0);
	new_data = ft_calloc(new_cap, d->elem_size);
	if (!new_data)
		return (0);
	deque_push__copy_linearized(d, new_data);
	free(d->data);
	d->data = new_data;
	d->cap = new_cap;
	d->head = 0;
	d->tail = d->len;
	return (1);
}

int	ft_deque_push_front(t_deque *d, const void *elem)
{
	void	*dst;

	if (!d || !elem)
		return (0);
	if (d->len == d->cap)
	{
		if (!ft_deque_grow(d))
			return (0);
	}
	d->head = (d->head - 1 + d->cap) % d->cap;
	dst = (char *)d->data + (d->head * d->elem_size);
	ft_memcpy(dst, elem, d->elem_size);
	d->len++;
	return (1);
}

int	ft_deque_push_back(t_deque *d, const void *elem)
{
	void	*dst;

	if (!d || !elem)
		return (0);
	if (d->len == d->cap)
	{
		if (!ft_deque_grow(d))
			return (0);
	}
	dst = (char *)d->data + (d->tail * d->elem_size);
	ft_memcpy(dst, elem, d->elem_size);
	d->tail = (d->tail + 1) % d->cap;
	d->len++;
	return (1);
}

/* --- ft_deque_swap.c --- */


static void	deque_swap__swap_with_buffer(void *first, void *second, char *buf, size_t size)
{
	ft_memcpy(buf, first, size);
	ft_memcpy(first, second, size);
	ft_memcpy(second, buf, size);
}

void	ft_deque_swap(t_deque *d)
{
	void	*first;
	void	*second;
	char	stack_buf[64];
	void	*heap_buf;

	if (!d || d->len < 2)
		return ;
	first = ft_deque_get(d, 0);
	second = ft_deque_get(d, 1);
	if (d->elem_size <= 64)
		deque_swap__swap_with_buffer(first, second, stack_buf, d->elem_size);
	else
	{
		heap_buf = malloc(d->elem_size);
		if (!heap_buf)
			return ;
		deque_swap__swap_with_buffer(first, second, heap_buf, d->elem_size);
		free(heap_buf);
	}
}

/* --- ft_deque_utils.c --- */


void	ft_deque_free(t_deque *d)
{
	if (!d)
		return ;
	if (d->data)
		free(d->data);
	free(d);
}

int	ft_deque_is_empty(t_deque *d)
{
	if (!d)
		return (1);
	return (d->len == 0);
}

int	ft_deque_is_full(t_deque *d)
{
	if (!d)
		return (0);
	return (d->len == d->cap);
}

void	ft_deque_rotate(t_deque *d)
{
	void	*first;
	void	*back;

	if (!d || d->len <= 1)
		return ;
	first = (char *)d->data + (d->head * d->elem_size);
	back = (char *)d->data + (d->tail * d->elem_size);
	ft_memcpy(back, first, d->elem_size);
	d->head = (d->head + 1) % d->cap;
	d->tail = (d->tail + 1) % d->cap;
}

void	ft_deque_rrotate(t_deque *d)
{
	void	*last;
	void	*front;
	size_t	last_idx;

	if (!d || d->len <= 1)
		return ;
	last_idx = (d->tail - 1 + d->cap) % d->cap;
	last = (char *)d->data + (last_idx * d->elem_size);
	d->head = (d->head - 1 + d->cap) % d->cap;
	d->tail = (d->tail - 1 + d->cap) % d->cap;
	front = (char *)d->data + (d->head * d->elem_size);
	ft_memcpy(front, last, d->elem_size);
}


/* ========================================================================== */
/*                          ft_vec_math                                       */
/* ========================================================================== */

/* --- ft_vec2_basic.c --- */


t_vec2	ft_vec2_new(double x, double y)
{
	t_vec2	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vec2	ft_vec2_add(t_vec2 a, t_vec2 b)
{
	t_vec2	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}

t_vec2	ft_vec2_sub(t_vec2 a, t_vec2 b)
{
	t_vec2	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	return (result);
}

t_vec2	ft_vec2_scale(t_vec2 v, double s)
{
	t_vec2	result;

	result.x = v.x * s;
	result.y = v.y * s;
	return (result);
}

/* --- ft_vec2_ops.c --- */

#include <math.h>

#define FT_EPSILON 1e-10

double	ft_vec2_dot(t_vec2 a, t_vec2 b)
{
	return (a.x * b.x + a.y * b.y);
}

double	ft_vec2_len(t_vec2 v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}

double	ft_vec2_len_sq(t_vec2 v)
{
	return (v.x * v.x + v.y * v.y);
}

t_vec2	ft_vec2_norm(t_vec2 v)
{
	double	len;
	t_vec2	result;

	len = ft_vec2_len(v);
	if (len < FT_EPSILON && len > -FT_EPSILON)
		return (ft_vec2_new(0, 0));
	result.x = v.x / len;
	result.y = v.y / len;
	return (result);
}

double	ft_vec2_dist(t_vec2 a, t_vec2 b)
{
	return (ft_vec2_len(ft_vec2_sub(b, a)));
}

/* --- ft_vec2_transform.c --- */

#include <math.h>

t_vec2	ft_vec2_lerp(t_vec2 a, t_vec2 b, double t)
{
	t_vec2	result;

	result.x = a.x + t * (b.x - a.x);
	result.y = a.y + t * (b.y - a.y);
	return (result);
}

t_vec2	ft_vec2_rotate(t_vec2 v, double angle)
{
	t_vec2	result;
	double	c;
	double	s;

	c = cos(angle);
	s = sin(angle);
	result.x = v.x * c - v.y * s;
	result.y = v.x * s + v.y * c;
	return (result);
}

/* --- ft_vec3_basic.c --- */


t_vec3	ft_vec3_new(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec3	ft_vec3_add(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

t_vec3	ft_vec3_sub(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}

t_vec3	ft_vec3_scale(t_vec3 v, double s)
{
	t_vec3	result;

	result.x = v.x * s;
	result.y = v.y * s;
	result.z = v.z * s;
	return (result);
}

t_vec3	ft_vec3_negate(t_vec3 v)
{
	return (ft_vec3_new(-v.x, -v.y, -v.z));
}

/* --- ft_vec3_norm.c --- */


#define FT_EPSILON 1e-10

t_vec3	ft_vec3_norm(t_vec3 v)
{
	double	len;
	t_vec3	result;

	len = ft_vec3_len(v);
	if (len < FT_EPSILON && len > -FT_EPSILON)
		return (ft_vec3_new(0, 0, 0));
	result.x = v.x / len;
	result.y = v.y / len;
	result.z = v.z / len;
	return (result);
}

/* --- ft_vec3_ops.c --- */

#include <math.h>

double	ft_vec3_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec3	ft_vec3_cross(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

double	ft_vec3_len(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double	ft_vec3_len_sq(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	ft_vec3_dist(t_vec3 a, t_vec3 b)
{
	return (ft_vec3_len(ft_vec3_sub(b, a)));
}

/* --- ft_vec3_transform.c --- */


t_vec3	ft_vec3_lerp(t_vec3 a, t_vec3 b, double t)
{
	t_vec3	result;

	result.x = a.x + t * (b.x - a.x);
	result.y = a.y + t * (b.y - a.y);
	result.z = a.z + t * (b.z - a.z);
	return (result);
}

t_vec3	ft_vec3_reflect(t_vec3 v, t_vec3 normal)
{
	double	d;

	d = 2.0 * ft_vec3_dot(v, normal);
	return (ft_vec3_sub(v, ft_vec3_scale(normal, d)));
}


#endif /* LIBFT_IMPLEMENTATION */

#endif /* LIBFT_H */

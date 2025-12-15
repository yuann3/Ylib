/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/11/18 18:42:23 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/15 18:10:28 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

/* ************************************************************************** */
/*                                Linked List                                 */
/* ************************************************************************** */

/**
 * @brief Singly linked list node.
 */
typedef struct s_list
{
	void			*content;	/**< Pointer to node data */
	struct s_list	*next;		/**< Pointer to next node */
}					t_list;

/**
 * @brief Create a new list node.
 * @param content Pointer to content for the new node.
 * @return New node with content set and next = NULL, or NULL on failure.
 */
t_list				*ft_lstnew(void *content);

/**
 * @brief Add node at the beginning of a list.
 * @param lst Address of pointer to first node.
 * @param new Node to add.
 */
void				ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Count the number of nodes in a list.
 * @param lst Pointer to first node.
 * @return Number of nodes.
 */
int					ft_lstsize(t_list *lst);

/**
 * @brief Return the last node of a list.
 * @param lst Pointer to first node.
 * @return Last node, or NULL if list is empty.
 */
t_list				*ft_lstlast(t_list *lst);

/**
 * @brief Add node at the end of a list.
 * @param lst Address of pointer to first node.
 * @param new Node to add.
 */
void				ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Delete and free a single node.
 * @param lst Node to delete.
 * @param del Function to free the content.
 */
void				ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Delete and free all nodes in a list.
 * @param lst Address of pointer to first node.
 * @param del Function to free each node's content.
 */
void				ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Apply a function to the content of each node.
 * @param lst Pointer to first node.
 * @param f Function to apply to each content.
 */
void				ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Create a new list by applying a function to each node's content.
 * @param lst Pointer to first node.
 * @param f Function to apply to each content.
 * @param del Function to free content if allocation fails.
 * @return New list, or NULL on failure.
 */
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

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
	void			*data;		/**< Circular buffer holding elements */
	size_t			head;		/**< Index of first element */
	size_t			tail;		/**< Index after last element */
	size_t			len;		/**< Current number of elements */
	size_t			cap;		/**< Total buffer capacity */
	size_t			elem_size;	/**< Size of each element in bytes */
}					t_deque;

/* Lifecycle */

/**
 * @brief Create a new deque with specified element size and initial capacity.
 * @param elem_size Size of each element in bytes. Must be > 0.
 * @param init_cap Initial capacity. If 0, defaults to 8.
 * @return Pointer to new deque, or NULL on failure.
 */
t_deque				*ft_deque_new(size_t elem_size, size_t init_cap);

/**
 * @brief Free all memory associated with a deque.
 * @param d Pointer to deque. Safe to call with NULL.
 * @note Does not free elements with internal pointers; caller must handle.
 */
void				ft_deque_free(t_deque *d);

/**
 * @brief Reset deque to empty state without freeing memory.
 * @param d Pointer to deque. Safe to call with NULL.
 */
void				ft_deque_clear(t_deque *d);

/* Push/Pop */

/**
 * @brief Add element to front of deque.
 * @param d Pointer to deque.
 * @param elem Pointer to element to copy.
 * @return 1 on success, 0 on failure (NULL args or allocation failure).
 * @note Grows capacity automatically when full. O(1) amortized.
 */
int					ft_deque_push_front(t_deque *d, const void *elem);

/**
 * @brief Add element to back of deque.
 * @param d Pointer to deque.
 * @param elem Pointer to element to copy.
 * @return 1 on success, 0 on failure (NULL args or allocation failure).
 * @note Grows capacity automatically when full. O(1) amortized.
 */
int					ft_deque_push_back(t_deque *d, const void *elem);

/**
 * @brief Remove and optionally return first element.
 * @param d Pointer to deque.
 * @param out Output buffer for removed element. Can be NULL to discard.
 * @return 1 on success, 0 if deque is NULL or empty.
 */
int					ft_deque_pop_front(t_deque *d, void *out);

/**
 * @brief Remove and optionally return last element.
 * @param d Pointer to deque.
 * @param out Output buffer for removed element. Can be NULL to discard.
 * @return 1 on success, 0 if deque is NULL or empty.
 */
int					ft_deque_pop_back(t_deque *d, void *out);

/* push_swap operations */

/**
 * @brief Swap the first two elements (sa/sb in push_swap).
 * @param d Pointer to deque.
 * @note No-op if deque has fewer than 2 elements or malloc fails for large
 *       elements. Uses stack buffer for elem_size <= 64, heap otherwise.
 */
void				ft_deque_swap(t_deque *d);

/**
 * @brief Rotate: move first element to back (ra/rb in push_swap).
 * @param d Pointer to deque.
 * @note O(1) - only adjusts indices, no data movement.
 */
void				ft_deque_rotate(t_deque *d);

/**
 * @brief Reverse rotate: move last element to front (rra/rrb in push_swap).
 * @param d Pointer to deque.
 * @note O(1) - only adjusts indices, no data movement.
 */
void				ft_deque_rrotate(t_deque *d);

/* Access */

/**
 * @brief Get pointer to first element without removing.
 * @param d Pointer to deque.
 * @return Pointer to first element, or NULL if empty/NULL.
 */
void				*ft_deque_front(t_deque *d);

/**
 * @brief Get pointer to last element without removing.
 * @param d Pointer to deque.
 * @return Pointer to last element, or NULL if empty/NULL.
 */
void				*ft_deque_back(t_deque *d);

/**
 * @brief Get pointer to element at logical index.
 * @param d Pointer to deque.
 * @param index Logical index (0 = front).
 * @return Pointer to element, or NULL if out of bounds/NULL.
 * @note O(1) random access.
 */
void				*ft_deque_get(t_deque *d, size_t index);

/* Utility */

/**
 * @brief Check if deque is empty.
 * @param d Pointer to deque.
 * @return 1 if empty or NULL, 0 otherwise.
 */
int					ft_deque_is_empty(t_deque *d);

/**
 * @brief Check if deque is at capacity.
 * @param d Pointer to deque.
 * @return 1 if full, 0 if not full or NULL.
 */
int					ft_deque_is_full(t_deque *d);

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
	void			*data;		/**< Contiguous buffer holding elements */
	size_t			len;		/**< Current number of elements */
	size_t			cap;		/**< Total buffer capacity */
	size_t			elem_size;	/**< Size of each element in bytes */
}					t_vec;

/**
 * @brief Create a new vector with specified element size and initial capacity.
 * @param elem_size Size of each element in bytes. Must be > 0.
 * @param init_cap Initial capacity. If 0, defaults to a reasonable size.
 * @return Pointer to new vector, or NULL on failure.
 */
t_vec				*ft_vec_new(size_t elem_size, size_t init_cap);

/**
 * @brief Append an element to the end of the vector.
 * @param vec Pointer to vector.
 * @param elem Pointer to element to copy.
 * @return 1 on success, 0 on failure.
 * @note Grows capacity automatically when full. O(1) amortized.
 */
int					ft_vec_push(t_vec *vec, const void *elem);

/**
 * @brief Remove and optionally return the last element.
 * @param vec Pointer to vector.
 * @param out Output buffer for removed element. Can be NULL to discard.
 * @return 1 on success, 0 if vector is NULL or empty.
 */
int					ft_vec_pop(t_vec *vec, void *out);

/**
 * @brief Get pointer to element at index.
 * @param vec Pointer to vector.
 * @param index Index of element (0-based).
 * @return Pointer to element, or NULL if out of bounds/NULL.
 */
void				*ft_vec_get(t_vec *vec, size_t index);

/**
 * @brief Set element at index by copying from elem.
 * @param vec Pointer to vector.
 * @param index Index of element to set.
 * @param elem Pointer to new element value.
 * @return 1 on success, 0 if out of bounds or NULL args.
 */
int					ft_vec_set(t_vec *vec, size_t index, const void *elem);

/**
 * @brief Free all memory associated with a vector.
 * @param vec Pointer to vector. Safe to call with NULL.
 */
void				ft_vec_free(t_vec *vec);

/**
 * @brief Reset vector to empty state without freeing memory.
 * @param vec Pointer to vector. Safe to call with NULL.
 */
void				ft_vec_clear(t_vec *vec);

/**
 * @brief Ensure vector has at least new_cap capacity.
 * @param vec Pointer to vector.
 * @param new_cap Minimum capacity required.
 * @return 1 on success, 0 on failure.
 * @note Does nothing if current capacity >= new_cap.
 */
int					ft_vec_reserve(t_vec *vec, size_t new_cap);

/**
 * @brief Insert an element at the specified index.
 * @param vec Pointer to vector.
 * @param index Index where element will be inserted.
 * @param elem Pointer to element to copy.
 * @return 1 on success, 0 on failure.
 * @note Elements at index and beyond are shifted right. O(n).
 */
int					ft_vec_insert(t_vec *vec, size_t index, const void *elem);

/* ************************************************************************** */
/*                          Character classification                          */
/* ************************************************************************** */

/**
 * @brief Check if character is alphabetic (a-z, A-Z).
 * @param c Character to check.
 * @return Non-zero if alphabetic, 0 otherwise.
 */
int					ft_isalpha(int c);

/**
 * @brief Check if character is a digit (0-9).
 * @param c Character to check.
 * @return Non-zero if digit, 0 otherwise.
 */
int					ft_isdigit(int c);

/**
 * @brief Check if character is alphanumeric (a-z, A-Z, 0-9).
 * @param c Character to check.
 * @return Non-zero if alphanumeric, 0 otherwise.
 */
int					ft_isalnum(int c);

/**
 * @brief Check if character is in ASCII range (0-127).
 * @param c Character to check.
 * @return Non-zero if ASCII, 0 otherwise.
 */
int					ft_isascii(int c);

/**
 * @brief Check if character is printable (including space).
 * @param c Character to check.
 * @return Non-zero if printable, 0 otherwise.
 */
int					ft_isprint(int c);

/* ************************************************************************** */
/*                             String functions                               */
/* ************************************************************************** */

/**
 * @brief Calculate the length of a string.
 * @param s Null-terminated string.
 * @return Number of characters before the null terminator.
 */
size_t				ft_strlen(const char *s);

/**
 * @brief Locate first occurrence of character in string.
 * @param s Null-terminated string to search.
 * @param c Character to find (converted to char).
 * @return Pointer to first occurrence, or NULL if not found.
 * @note The terminating null is considered part of the string.
 */
char				*ft_strchr(const char *s, int c);

/**
 * @brief Locate last occurrence of character in string.
 * @param s Null-terminated string to search.
 * @param c Character to find (converted to char).
 * @return Pointer to last occurrence, or NULL if not found.
 */
char				*ft_strrchr(const char *s, int c);

/**
 * @brief Compare two strings up to n characters.
 * @param s1 First string.
 * @param s2 Second string.
 * @param n Maximum number of characters to compare.
 * @return <0 if s1 < s2, 0 if equal, >0 if s1 > s2.
 */
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Locate substring in string, searching at most len characters.
 * @param haystack String to search in.
 * @param needle Substring to find.
 * @param len Maximum characters to search.
 * @return Pointer to start of match, or NULL if not found.
 */
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);

/**
 * @brief Copy string to buffer with size limit.
 * @param dst Destination buffer.
 * @param src Source string.
 * @param dstsize Size of destination buffer.
 * @return Total length of src (for truncation detection).
 * @note Always null-terminates if dstsize > 0.
 */
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * @brief Append string to buffer with size limit.
 * @param dst Destination buffer (must be null-terminated).
 * @param src Source string to append.
 * @param dstsize Total size of destination buffer.
 * @return Total length of string it tried to create.
 * @note Always null-terminates if dstsize > strlen(dst).
 */
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * @brief Duplicate a string.
 * @param s1 String to duplicate.
 * @return Newly allocated copy, or NULL on failure.
 */
char				*ft_strdup(const char *s1);

/**
 * @brief Extract a substring from a string.
 * @param s Source string.
 * @param start Starting index.
 * @param len Maximum length of substring.
 * @return Newly allocated substring, or NULL on failure.
 */
char				*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Concatenate two strings into a new string.
 * @param s1 First string.
 * @param s2 Second string.
 * @return Newly allocated combined string, or NULL on failure.
 */
char				*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Trim characters from beginning and end of string.
 * @param s1 String to trim.
 * @param set Characters to remove.
 * @return Newly allocated trimmed string, or NULL on failure.
 */
char				*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Split string by delimiter into array of strings.
 * @param s String to split.
 * @param c Delimiter character.
 * @return Null-terminated array of strings, or NULL on failure.
 * @note Caller must free each string and the array.
 */
char				**ft_split(char const *s, char c);

/**
 * @brief Apply function to each character, creating new string.
 * @param s Source string.
 * @param f Function taking index and character, returning new character.
 * @return Newly allocated transformed string, or NULL on failure.
 */
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Apply function to each character in place.
 * @param s String to modify.
 * @param f Function taking index and pointer to character.
 */
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

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
void				*ft_memset(void *b, int c, size_t len);

/**
 * @brief Zero out a memory area.
 * @param s Pointer to memory area.
 * @param n Number of bytes to zero.
 */
void				ft_bzero(void *s, size_t n);

/**
 * @brief Copy memory area (non-overlapping).
 * @param dst Destination buffer.
 * @param src Source buffer.
 * @param n Number of bytes to copy.
 * @return Pointer to dst.
 * @note Behavior undefined if regions overlap; use ft_memmove instead.
 */
void				*ft_memcpy(void *dst, const void *src, size_t n);

/**
 * @brief Copy memory area (handles overlapping regions).
 * @param dst Destination buffer.
 * @param src Source buffer.
 * @param len Number of bytes to copy.
 * @return Pointer to dst.
 */
void				*ft_memmove(void *dst, const void *src, size_t len);

/**
 * @brief Locate byte in memory area.
 * @param s Memory area to search.
 * @param c Byte to find (converted to unsigned char).
 * @param n Number of bytes to search.
 * @return Pointer to first occurrence, or NULL if not found.
 */
void				*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compare two memory areas.
 * @param s1 First memory area.
 * @param s2 Second memory area.
 * @param n Number of bytes to compare.
 * @return <0 if s1 < s2, 0 if equal, >0 if s1 > s2.
 */
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Allocate and zero-initialize memory.
 * @param count Number of elements.
 * @param size Size of each element.
 * @return Pointer to allocated memory, or NULL on failure.
 */
void				*ft_calloc(size_t count, size_t size);

/* ************************************************************************** */
/*                          Character conversion                              */
/* ************************************************************************** */

/**
 * @brief Convert lowercase letter to uppercase.
 * @param c Character to convert.
 * @return Uppercase equivalent, or c if not a lowercase letter.
 */
int					ft_toupper(int c);

/**
 * @brief Convert uppercase letter to lowercase.
 * @param c Character to convert.
 * @return Lowercase equivalent, or c if not an uppercase letter.
 */
int					ft_tolower(int c);

/* ************************************************************************** */
/*                          Conversion functions                              */
/* ************************************************************************** */

/**
 * @brief Convert string to integer.
 * @param str String to convert.
 * @return Integer value. Skips leading whitespace and handles +/- sign.
 */
int					ft_atoi(const char *str);

/**
 * @brief Convert integer to string.
 * @param n Integer to convert.
 * @return Newly allocated string representation, or NULL on failure.
 */
char				*ft_itoa(int n);

/* ************************************************************************** */
/*                        File descriptor output                              */
/* ************************************************************************** */

/**
 * @brief Write a character to a file descriptor.
 * @param c Character to write.
 * @param fd File descriptor.
 */
void				ft_putchar_fd(char c, int fd);

/**
 * @brief Write a string to a file descriptor.
 * @param s String to write.
 * @param fd File descriptor.
 */
void				ft_putstr_fd(char *s, int fd);

/**
 * @brief Write a string followed by newline to a file descriptor.
 * @param s String to write.
 * @param fd File descriptor.
 */
void				ft_putendl_fd(char *s, int fd);

/**
 * @brief Write an integer to a file descriptor.
 * @param n Integer to write.
 * @param fd File descriptor.
 */
void				ft_putnbr_fd(int n, int fd);

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
int					ft_printf(const char *format, ...);

/**
 * @brief Print a single character to stdout.
 * @param character Character to print.
 * @return Number of characters printed (1), or -1 on error.
 */
int					ft_print_char(int character);

/**
 * @brief Print a string to stdout.
 * @param str String to print. Prints "(null)" if NULL.
 * @return Number of characters printed, or -1 on error.
 */
int					ft_print_str(char *str);

/**
 * @brief Print a pointer address in hexadecimal.
 * @param ptr Pointer to print.
 * @return Number of characters printed, or -1 on error.
 */
int					ft_print_ptr(void *ptr);

/**
 * @brief Print a signed integer.
 * @param number Integer to print.
 * @return Number of characters printed, or -1 on error.
 */
int					ft_print_nbr(int number);

/**
 * @brief Print an unsigned integer.
 * @param number Unsigned integer to print.
 * @return Number of characters printed, or -1 on error.
 */
int					ft_print_unsigned(unsigned int number);

/**
 * @brief Print an unsigned integer in hexadecimal.
 * @param n Unsigned integer to print.
 * @param uppercase If non-zero, use uppercase hex digits (A-F).
 * @return Number of characters printed, or -1 on error.
 */
int					ft_print_hex(unsigned int n, int uppercase);

#endif

NAME := libft.a

SRCS := ft_isalpha.c ft_isdigit.c \
	ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_memcmp.c \
	ft_memset.c ft_memmove.c \
	ft_memcpy.c ft_memchr.c \
	ft_calloc.c ft_bzero.c \
	ft_toupper.c ft_tolower.c \
	ft_atoi.c ft_strncmp.c \
	ft_itoa.c ft_split.c \
	ft_strmapi.c ft_strchr.c \
	ft_strdup.c ft_strnstr.c \
	ft_strrchr.c ft_strjoin.c \
	ft_strtrim.c ft_substr.c \
	ft_striteri.c ft_strlen.c \
	ft_strlcpy.c ft_strlcat.c \
	ft_strcmp.c \
	ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c \
	ft_printf.c ft_print_char.c \
	ft_print_str.c ft_print_ptr.c \
	ft_print_nbr.c ft_print_hex.c \
	ft_vec_new.c ft_vec_push.c \
	ft_vec_pop.c ft_vec_get.c \
	ft_vec_set.c ft_vec_free.c \
	ft_vec_clear.c ft_vec_reserve.c \
	ft_vec_insert.c \
	ft_deque_new.c ft_deque_push.c \
	ft_deque_pop.c ft_deque_access.c \
	ft_deque_swap.c ft_deque_utils.c

OBJS := $(SRCS:.c=.o)

BONUS_SRCS := ft_lstsize_bonus.c ft_lstadd_front_bonus.c \
	ft_lstadd_back_bonus.c ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c ft_lstiter_bonus.c \
	ft_lstnew_bonus.c ft_lstlast_bonus.c \
	ft_lstmap_bonus.c

BONUS_OBJS := $(BONUS_SRCS:.c=.o)

BONUS_NAME := libft_bonus.a

FLAGS = -Wall -Wextra -Werror

CC = cc

HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(BONUS_NAME) $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	ar rc $(BONUS_NAME) $(BONUS_OBJS)
	ranlib $(BONUS_NAME)
	ar rc $(NAME) $(BONUS_OBJS)
	ranlib $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BONUS_OBJS) $(BONUS_NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

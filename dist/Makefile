# **************************************************************************** #
#                                                                              #
#                                                           :::      ::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                   +:+ +:+           +:+      #
#    By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+         #
#                                               +#+#+#+#+#+      +#+           #
#    Created: 2025/11/23 21:52:22 by yiyuli           #+#      #+#             #
#    Updated: 2025/11/23 22:00:30 by yiyuli         ###      ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

HEADER		:= libft.h

SRCS		:=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
				ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
				ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
				ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
				ft_atoi.c ft_calloc.c ft_strdup.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
				ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS		:= $(SRCS:.c=.o)

BONUS_SRCS	:=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_OBJS	:= $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(NAME) .bonus_built

.bonus_built: $(BONUS_OBJS)
	ar rc $(NAME) $(BONUS_OBJS)
	ranlib $(NAME)
	touch .bonus_built

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BONUS_OBJS) .bonus_built

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

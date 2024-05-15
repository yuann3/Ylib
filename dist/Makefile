# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 16:28:52 by yiyli             #+#    #+#              #
#    Updated: 2024/05/15 16:38:03 by yiyli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
SRCS := ft_lstsize.c ft_lstadd_front.c \
	ft_lstadd_back.c ft_lstclear.c \
	ft_lstdelone.c ft_lstiter.c \
	ft_lstnew.c ft_lstlast.c \
	ft_lstmap.c ft_isalpha.c \
	ft_isdigit.c ft_isalnum.c \
	ft_isascii.c ft_isprint.c \
	ft_memcmp.c ft_memset.c \
	ft_memmove.c ft_memcpy.c \
	ft_memchr.c ft_calloc.c \
	ft_bzero.c ft_toupper.c \
	ft_tolower.c ft_atoi.c \
	ft_strncmp.c ft_strncpy.c \
	ft_strndup.c ft_itoa.c \
	ft_split.c ft_strmapi.c \
	ft_strchr.c ft_strdup.c \
	ft_strnstr.c ft_strrchr.c \
	ft_strjoin.c ft_strtrim.c \
	ft_substr.c ft_striteri.c \
	ft_strlen.c ft_strlcpy.c \
	ft_strlcat.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c

OBJS := ft_lstsize.o ft_lstadd_front.o \
	ft_lstadd_back.o ft_lstclear.o \
	ft_lstdelone.o ft_lstiter.o \
	ft_lstnew.o ft_lstlast.o \
	ft_lstmap.o ft_isalpha.o \
	ft_isdigit.o ft_isalnum.o \
	ft_isascii.o ft_isprint.o \
	ft_memcmp.o ft_memset.o \
	ft_memmove.o ft_memcpy.o \
	ft_memchr.o ft_calloc.o \
	ft_bzero.o ft_toupper.o \
	ft_tolower.o ft_atoi.o \
	ft_strncmp.o ft_strncpy.o \
	ft_strndup.o ft_itoa.o \
	ft_split.o ft_strmapi.o \
	ft_strchr.o ft_strdup.o \
	ft_strnstr.o ft_strrchr.o \
	ft_strjoin.o ft_strtrim.o \
	ft_substr.o ft_striteri.o \
	ft_strlen.o ft_strlcpy.o \
	ft_strlcat.o ft_putchar_fd.o \
	ft_putstr_fd.o ft_putendl_fd.o \
	ft_putnbr_fd.o 

FLAGS = -Wall -Wextra -Werror

CC = cc

HEADER = libft.h

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
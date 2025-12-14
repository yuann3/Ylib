# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: yiyuli <yy@eyuan.me>                       +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2025/12/14 15:30:00 by yiyuli            #+#    #+#             #
#    Updated: 2025/12/14 15:30:00 by yiyuli           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME		= test_runner
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDES	= -I ../includes

LIBFT		= ../libft.a
LIBFT_DIR	= ..

SRCS		= test_ft_vec.c
OBJS		= $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test: all
	@echo "\n\033[1;33m>>> Running tests...\033[0m"
	@./$(NAME)

leaks: all
	@echo "\n\033[1;33m>>> Running memory leak check with leaks...\033[0m"
	@MallocStackLogging=1 ./$(NAME) &
	@sleep 1
	@leaks $(NAME) 2>/dev/null || leaks -atExit -- ./$(NAME) 2>&1 | grep -A 20 "leaks Report"

leaks-full: all
	@echo "\n\033[1;33m>>> Running full memory leak check...\033[0m"
	@leaks -atExit -- ./$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test leaks leaks-full

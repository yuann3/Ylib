# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: yiyuli <yy@eyuan.me>                       +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2025/12/14 15:30:00 by yiyuli            #+#    #+#             #
#    Updated: 2025/12/15 19:00:00 by yiyuli           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDES	= -I ../includes

LIBFT		= ../libft.a
LIBFT_DIR	= ..

# Test executables
VEC_NAME	= test_vec
DEQUE_NAME	= test_deque

# Source files
VEC_SRCS	= test_ft_vec.c
DEQUE_SRCS	= test_ft_deque.c

VEC_OBJS	= $(VEC_SRCS:.c=.o)
DEQUE_OBJS	= $(DEQUE_SRCS:.c=.o)

all: $(LIBFT) $(VEC_NAME) $(DEQUE_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(VEC_NAME): $(VEC_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(VEC_OBJS) $(LIBFT) -o $(VEC_NAME)

$(DEQUE_NAME): $(DEQUE_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(DEQUE_OBJS) $(LIBFT) -o $(DEQUE_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test: all
	@echo "\n\033[1;33m>>> Running ft_vec tests...\033[0m"
	@./$(VEC_NAME)
	@echo "\n\033[1;33m>>> Running ft_deque tests...\033[0m"
	@./$(DEQUE_NAME)

test-vec: $(LIBFT) $(VEC_NAME)
	@echo "\n\033[1;33m>>> Running ft_vec tests...\033[0m"
	@./$(VEC_NAME)

test-deque: $(LIBFT) $(DEQUE_NAME)
	@echo "\n\033[1;33m>>> Running ft_deque tests...\033[0m"
	@./$(DEQUE_NAME)

leaks: all
	@echo "\n\033[1;33m>>> Running memory leak check for ft_vec...\033[0m"
	@leaks -atExit -- ./$(VEC_NAME) 2>&1 | grep -E "(Process|leaks for)"
	@echo "\n\033[1;33m>>> Running memory leak check for ft_deque...\033[0m"
	@leaks -atExit -- ./$(DEQUE_NAME) 2>&1 | grep -E "(Process|leaks for)"

leaks-vec: $(LIBFT) $(VEC_NAME)
	@echo "\n\033[1;33m>>> Running memory leak check for ft_vec...\033[0m"
	@leaks -atExit -- ./$(VEC_NAME)

leaks-deque: $(LIBFT) $(DEQUE_NAME)
	@echo "\n\033[1;33m>>> Running memory leak check for ft_deque...\033[0m"
	@leaks -atExit -- ./$(DEQUE_NAME)

clean:
	rm -f $(VEC_OBJS) $(DEQUE_OBJS)

fclean: clean
	rm -f $(VEC_NAME) $(DEQUE_NAME) test_runner

re: fclean all

.PHONY: all clean fclean re test test-vec test-deque leaks leaks-vec leaks-deque

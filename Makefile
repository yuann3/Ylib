# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 16:28:52 by yiyli             #+#    #+#              #
#    Updated: 2024/05/14 14:35:24 by yiyli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
SOURCE_DIR := srcs
OBJECT_DIR := objs
INCLUDE_DIR := includes
DIST_DIR := dist

# CC
CC := cc
CFLAGS := -Wall -Wextra -Werror -I $(INCLUDE_DIR)

# Norminette
NORM := norminette
NORM_FLAGS := -R CheckForbiddenSourceHeader -R CheckDefine

MKDIR = mkdir -p

# Helper function to list all files matching pattern recursively
# e.g. List all *.c files in srcs/ folder
rwildcard = $(shell find $(1) -type f -name '$(2)')

# Find all files we work with
# e.g. srcs/**/*.c, include/**/*.h
sources := $(call rwildcard,$(SOURCE_DIR),*.c)

# Convert c files to o files
# e.g. srcs/main.c srcs/dict/dict.c => objs/main.o objs/dict/dict.o
objects := $(sources:$(SOURCE_DIR)/%.c=$(OBJECT_DIR)/%.o)

.PHONY: all
all: $(NAME)

# Compile binary from all o files
# e.g. objs/main.o objs/dict/dict.o => rush-02
$(NAME): $(objects)
	ar rcs $@ $^

# Compile each c file to o file
# Also, consider h file, though it is not included for compilation
# e.g. srcs/dict/dict.c (srcs/dict/dict.h) => objs/dict/dict.o
$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c
	@$(NORM) $(NORM_FLAGS) $<
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -r $(OBJECT_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

# Run norminette on all c files and h files
.PHONY: norm
norm:
	$(NORM) $(NORM_FLAGS) $(sources)
	$(NORM) $(NORM_FLAGS) $(wildcard $(INCLUDE_DIR)/*.h)

# flatten all files in srcs/ and include/ to dist/
# e.g. srcs/**/*.c include/**/*.h => dist/
# dist/ is the folder to be submitted to vogsphere
.PHONY: dist
dist:
	$(RM) -r $(DIST_DIR)
	$(MKDIR) $(DIST_DIR)
	find $(SOURCE_DIR) -type f -exec cp {} $(DIST_DIR) \;
	find $(INCLUDE_DIR) -type f -exec cp {} $(DIST_DIR) \;

# Generate documentation using doxygen
.PHONY: doc
doc:
	make dist
	doxygen doxyfile
	open html/index.html
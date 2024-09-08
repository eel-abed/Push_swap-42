# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 12:22:21 by eel-abed          #+#    #+#              #
#    Updated: 2024/09/08 15:30:56 by eel-abed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for 42 project respecting 42 school rules

# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Wextra -Werror -Iinclude -I/Users/eel-abed/Documents/Ecole42/Push_swap-42/libft -g

# Program name
NAME = push_swap

# Source and include directories
SRC_DIR = srcs/
INCLUDE_DIR = include/
LIBFT_DIR = /Users/eel-abed/Documents/Ecole42/Push_swap-42/libft

# Source files
SRCS = $(SRC_DIR)operations_rotate.c \
       $(SRC_DIR)operations.c \
       $(SRC_DIR)push_swap.c \
       $(SRC_DIR)sort.c \
       $(SRC_DIR)stack.c \
       $(SRC_DIR)utils.c \
       $(SRC_DIR)sort2-3-5.c \
       $(SRC_DIR)parsing.c

# Object files
OBJS = $(SRCS:.c=.o)

# Rule to compile the program
all: $(NAME)

$(NAME): $(OBJS) | libft
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	@make -C $(LIBFT_DIR)

# Rule to clean object files
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

# Rule to clean everything including the program
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Rule to recompile everything
re: fclean all

# .PHONY to avoid conflicts with files named clean, fclean, re, all
.PHONY: all clean fclean re libft

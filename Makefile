# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 12:22:21 by eel-abed          #+#    #+#              #
#    Updated: 2024/08/26 13:31:28 by eel-abed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for 42 project respecting 42 school rules

# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Wextra -Werror -Iinclude -g

# Program name
NAME = push_swap

# Source and include directories
SRC_DIR = srcs/
INCLUDE_DIR = include/

# Source files
SRCS = $(SRC_DIR)operations_rotate.c \
       $(SRC_DIR)operations.c \
       $(SRC_DIR)push_swap.c \
       $(SRC_DIR)sort.c \
       $(SRC_DIR)stack.c \
       $(SRC_DIR)utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Rule to compile the program
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Rule to clean object files
clean:
	rm -f $(OBJS)

# Rule to clean everything including the program
fclean: clean
	rm -f $(NAME)

# Rule to recompile everything
re: fclean all

# .PHONY to avoid conflicts with files named clean, fclean, re, all
.PHONY: all clean fclean re

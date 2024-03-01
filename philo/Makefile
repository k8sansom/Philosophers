# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 10:54:49 by ksansom           #+#    #+#              #
#    Updated: 2024/03/01 16:58:17 by ksansom          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

# Source dir and files
SRC_DIR = src
SRCS =	src/eating.c \
		src/init.c \
		src/main.c \
		src/monitors.c \
		src/routines.c \
		src/utils_get.c \
		src/utils_print.c \
		src/utils_set.c \
		src/utils_time.c \
		src/utils.c 

# Object files
OBJ_DIR = obj
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default target (all)
all: $(NAME)

# Linking the program
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compilation rule for object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
# Clean object files and executable
clean:
	rm -rf $(OBJ_DIR)

# Remove all generated files
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
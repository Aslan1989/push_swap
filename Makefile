# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisaev <aisaev@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/28 14:23:21 by aisaev            #+#    #+#              #
#    Updated: 2025/06/14 15:46:54 by aisaev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Файл: push_swap/Makefile

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I my_library/libft/includes \
	-I my_library/ft_printf/includes

# Пути до библиотеки
LIB_DIR = ./my_library
LIB = $(LIB_DIR)/aisaev.a

INCLUDES = -I$(LIB_DIR)/libft/includes -I$(LIB_DIR)/ft_printf/includes -I$(LIB_DIR)/get_next_line/includes

SRC = main.c utils.c parser.c \
	operations/push.c operations/swap.c operations/rotate.c \
	operations/rev_rotate.c sort_stack.c radix_sort.c sort_small.c
OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

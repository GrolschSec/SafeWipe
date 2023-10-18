# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 22:06:20 by rlouvrie          #+#    #+#              #
#    Updated: 2023/10/18 23:53:06 by rlouvrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = SafeWipe

CC = cc

C_FLAGS = -Wall -Werror -Wextra

SRCS_DIR = src/

OBJS_DIR = obj/

INCLUDE_DIR = include/

SRCS =	main.c \
	utils_1.c \
	parsing_1.c

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(C_FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(C_FLAGS) -I $(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
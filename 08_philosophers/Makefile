# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoson <yoson@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 16:11:41 by kijsong           #+#    #+#              #
#    Updated: 2022/09/09 12:41:28 by yoson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philosophers

CC			= cc
FLAGS		= -Wall -Wextra -Werror

INC_DIR		= ./includes/
SRC_DIR		= ./srcs/

SRCS		=	$(wildcard srcs/*.c) $(wildcard srcs/utils/*.c)
OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $^

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(INC_DIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	make fclean
	make all

PHONY: all clean fclean re

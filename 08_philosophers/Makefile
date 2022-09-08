# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoson <yoson@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 16:11:41 by kijsong           #+#    #+#              #
#    Updated: 2022/09/08 20:55:24 by yoson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philosophers

CC			= cc
FLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

INC_DIR		= ./includes/
SRC_DIR		= ./srcs/
LIB_DIR		= ./libft/
LIB_NAME	= ./libft/libft.a

SRCS		=	$(wildcard srcs/*.c)
# SRCS		=	$(addprefix $(SRC_DIR), $(SRC))
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	$(CC) -o $(NAME) $^ -L$(LIB_DIR) -lft

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(INC_DIR)

clean:
	make -C $(LIB_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re:
	make fclean
	make all

PHONY: all clean fclean re

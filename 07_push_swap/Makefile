# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 17:22:49 by yoson             #+#    #+#              #
#    Updated: 2022/08/24 17:59:09 by yoson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
FLAGS		= -Wall -Werror -Wextra
AR			= ar rcs
RM			= rm -f

INCS_DIR	= ./includes/
SRCS_DIR	= ./srcs/
LIB_DIR		= ./libft/
LIB_NAME	= ./libft/libft.a

SRC			=	main.c list.c insert.c preprocess.c operation.c sort.c \
				quick_sort.c binary_search.c error.c free.c 
SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS		=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	$(CC) -o $(NAME) $(OBJS) -L $(LIB_DIR) -lft -I $(INCS_DIR)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(INCS_DIR)

clean :
	make -C $(LIB_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re : clean all

PHONY	: all clean fclean re

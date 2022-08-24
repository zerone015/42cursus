# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 17:22:49 by yoson             #+#    #+#              #
#    Updated: 2022/08/24 17:29:26 by yoson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
FLAGS		= -Wall -Werror -Wextra
RM			= rm -f

INCS_DIR	= ./includes/
SRCS_DIR	= ./srcs/

INCS		= -I includes

SRC			=	main.c list.c insert.c preprocess.c operation.c sort.c quick_sort.c 
				binary_search.c error.c free.c ft_split.c ft_atoi.c ft_putendl_fd.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS		=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -I $(INCS_DIR)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : clean all

PHONY	: all clean fclean re

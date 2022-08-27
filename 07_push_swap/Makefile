# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 17:22:49 by yoson             #+#    #+#              #
#    Updated: 2022/08/28 08:55:01 by yoson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS		= checker

CC			= cc
FLAGS		= -Wall -Werror -Wextra
AR			= ar rcs
RM			= rm -f

INCS_DIR	= ./includes/
SRCS_DIR	= ./srcs/
LIB_DIR		= ./libft/
LIB_NAME	= ./libft/libft.a

SRC			=	push_swap.c preprocess.c preprocess_util.c instruction.c instruction2.c \
				list.c sort.c sort_util.c sort_find_util.c 
BSRC		=	checker.c checker_instruction.c checker_instruction2.c	
SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))
BSRCS		=	$(addprefix $(SRCS_DIR), $(BSRC))
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS		=	$(SRCS:.c=.o)

all	: $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	$(CC) -o $(NAME) $(OBJS) -L $(LIB_DIR) -lft -I $(INCS_DIR)

$(BONUS) : $(BOBJS) $(OBJS)
	make -C $(LIB_DIR)
	$(CC) -o $(BONUS) $^ -L $(LIB_DIR) -lft -I $(INCS_DIR)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(INCS_DIR)

clean :
	make -C $(LIB_DIR) clean
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME) $(BONUS)

re : clean all

PHONY	: all clean fclean re bonus

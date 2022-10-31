# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoson <yoson@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 02:12:51 by yoson             #+#    #+#              #
#    Updated: 2022/11/01 04:10:18 by yoson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= pipex

CC 			= cc
FLAGS 		= -Wall -Wextra -Werror

SRC_DIR		= ./mandatory/srcs/
BSRC_DIR	= ./bonus/srcs/
LIB_DIR		= ./libft/
LIB_NAME	= libft.a

SRC 		= 	pipex.c \
				execute.c \
				error.c 
BSRC		=	main_bonus.c \
				pipex_bonus.c \
				execute_bonus.c \
				error_bonus.c \
				utils_bonus.c
SRCS		=	$(addprefix $(SRC_DIR), $(SRC))
BSRCS		=	$(addprefix $(BSRC_DIR), $(BSRC))
OBJS		=	$(SRCS:%.c=%.o)
BOBJS 		= 	$(BSRCS:%.c=%.o)

ifdef PIPEX_WITH_BONUS
	INC_DIR = ./bonus/includes/
    OBJ_FILES = $(BOBJS)
else
	INC_DIR = ./mandatory/includes/
    OBJ_FILES = $(OBJS)
endif

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIB_DIR)

all : $(NAME)

bonus :
	make PIPEX_WITH_BONUS=1 all
	
$(NAME) : $(OBJ_FILES)
	make -C $(LIB_DIR)
	cp $(LIB_DIR)$(LIB_NAME) $(NAME)
	$(CC) $(FLAGS) $^ -Llibft -lft -o $@

clean :
	make -C $(LIB_DIR) clean
	rm -f $(OBJS)
	rm -f $(BOBJS)

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re : 
	make fclean
	make all

bre :
	make fclean
	make bonus 

.PHONY: all bonus clean fclean re bre
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 16:11:41 by kijsong           #+#    #+#              #
#    Updated: 2022/09/04 00:22:55 by kijsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

CC			= cc
FLAGS		= -Wall -Wextra -Werror
RFLAGS 		= -lreadline -L$(HOME)/.brew/opt/readline/lib
RHFLAGS 	= -I$(HOME)/.brew/opt/readline/include
# RFLAGS 		= -lreadline -L/goinfre/yoson/brew/opt/readline/lib
# RHFLAGS 	= -I/goinfre/yoson/brew/opt/readline/include
# RFLAGS 		= -lreadline -L/opt/homebrew/opt/readline/lib
# RHFLAGS 	= -I/opt/homebrew/opt/readline/include
AR			= ar rcs
RM			= rm -f

INCS_DIR	= ./includes/
SRCS_DIR	= ./srcs/
LIB_DIR		= ./libft/
LIB_NAME	= ./libft/libft.a

SRC			=	
BSRC		=	
# SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))
# BSRCS		=	$(addprefix $(SRCS_DIR), $(BSRC))
SRCS		=	$(wildcard srcs/*.c)  $(wildcard srcs/builtin/*.c)
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS		=	$(SRCS:.c=.o)
BOBJS		=	$(BSRCS:.c=.o)

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	$(CC) -o $(NAME) $^ -L$(LIB_DIR) -lft $(RFLAGS)

$(BONUS) : $(BOBJS)
	make -C $(LIB_DIR)
	$(CC) -o $(BONUS) $^ -L$(LIB_DIR) -lft $(RFLAGS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(INCS_DIR) $(RHFLAGS)

clean :
	make -C $(LIB_DIR) clean
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME) $(BONUS)

re : fclean all

re_bonus : fclean bonus

PHONY	: all clean fclean re bonus re_bonus

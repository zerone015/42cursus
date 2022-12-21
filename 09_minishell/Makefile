# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 16:11:41 by kijsong           #+#    #+#              #
#    Updated: 2022/12/21 18:30:36 by kijsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

CC			= cc
FLAGS		= -Wall -Wextra -Werror
RFLAGS 		= -lreadline -L$(HOME)/.brew/opt/readline/lib
RHFLAGS 	= -I$(HOME)/.brew/opt/readline/include
AR			= ar rcs
RM			= rm -f

INC_DIR		= ./includes/
SRC_DIR		= ./srcs/
UTIL_DIR	= ./srcs/utils/
BUILTIN_DIR	= ./srcs/builtin/
LIB_DIR		= ./libft/
LIB_NAME	= ./libft/libft.a

SRC			=	main.c ast.c ast_operator.c check_syntax.c child_execve.c \
				env.c error.c execute.c execute_core.c external.c \
				get_next_line_without_nl.c get_next_line.c heredoc_child.c \
				heredoc_parent.c heredoc.c prompt.c redirection.c signal.c \
				token.c tokenize.c wildcard.c
UTIL		=	ast_operator_util.c ast_util.c ast_util2.c execute_util.c \
				heredoc_child_util.c heredoc_util.c token_util.c token_util2.c \
				tokenize_util.c tokenize_util2.c util.c util2.c \
				wildcard_util.c
BUILTIN		=	builtin.c builtin_cd.c builtin_echo.c builtin_env.c \
				builtin_exit.c builtin_export.c builtin_pwd.c \
				builtin_unset.c builtin_util.c
SRCS		=	$(addprefix $(SRC_DIR), $(SRC)) \
				$(addprefix $(UTIL_DIR), $(UTIL)) \
				$(addprefix $(BUILTIN_DIR), $(BUILTIN))
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	$(CC) $(FLAGS) -o $(NAME) $^ -L$(LIB_DIR) -lft $(RFLAGS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(INC_DIR) $(RHFLAGS)

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

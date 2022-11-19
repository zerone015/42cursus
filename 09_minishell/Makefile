# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoson <yoson@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 16:11:41 by kijsong           #+#    #+#              #
#    Updated: 2022/11/19 17:15:56 by yoson            ###   ########.fr        #
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
BUILTIN_DIR	= ./srcs/builtin/
LIB_DIR		= ./libft/
LIB_NAME	= ./libft/libft.a

SRC			=	main.c env.c error.c execute.c execute_util.c external.c get_next_line.c get_next_line_without_nl.c \
				child_execve.c prompt.c redirection.c signal.c heredoc.c heredoc_parent.c heredoc_child.c heredoc_util.c \
				token.c token_util.c tokenize_util.c tokenize.c util.c util2.c check_syntax.c
BUILTIN		=	builtin.c builtin_cd.c builtin_echo.c builtin_env.c builtin_exit.c \
				builtin_export.c builtin_pwd.c builtin_unset.c builtin_util.c
SRCS		=	$(addprefix $(SRC_DIR), $(SRC)) $(addprefix $(BUILTIN_DIR), $(BUILTIN))
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	$(CC) -o $(NAME) $^ -L$(LIB_DIR) -lft $(RFLAGS)

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

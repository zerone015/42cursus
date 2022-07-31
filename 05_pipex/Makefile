# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 05:17:02 by yoson             #+#    #+#              #
#    Updated: 2022/08/01 07:46:53 by yoson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = pipex
CC    = cc
FLAGS = -Wall -Wextra -Werror
BSRCS  = srcs/main_bonus.c srcs/pipex_bonus.c srcs/execute_bonus.c srcs/error_bonus.c \
		 srcs/get_next_line.c 
SRCS  = srcs/main.c srcs/pipex.c srcs/execute.c srcs/error.c
OBJS  = $(SRCS:%.c=%.o)
BOBJS = $(BSRCS:%.c=%.o)
ifdef WITH_BONUS
    OBJ_FILES = $(BOBJS)
else
    OBJ_FILES = $(OBJS)
endif

all: $(NAME)
bonus:
	make WITH_BONUS=1 all
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
$(NAME): $(OBJ_FILES)
	make re -C ./libft
	$(CC) $^ -Llibft -lft -o $@
clean: 
	make clean -C ./libft
	rm -f $(OBJS) $(BOBJS)
fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)
re: fclean all
re_bonus: fclean bonus
.PHONY: all bonus clean fclean re re_bonus

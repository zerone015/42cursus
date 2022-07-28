# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 05:17:02 by yoson             #+#    #+#              #
#    Updated: 2022/07/29 05:52:35 by yoson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = pipex
BNAME = pipex_bonus
CC    = cc
FLAGS = -Wall -Wextra -Werror
BSRCS = 
SRCS  = srcs/pipex.c \
        srcs/util.c \
	srcs/main.c
OBJS  = $(SRCS:%.c=%.o)
BOBJS = $(BSRCS:%.c=%.o)

all: $(NAME)
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
$(NAME): $(OBJS)
	make re -C ./libft
	$(CC) $< -Llibft -lft -o $@
bonus: $(BNAME)
$(BNAME): $(BOBJS)
	make re -C ./libft
	$(CC) $< -Llibft -lft -o $@
clean: 
	make clean -C ./libft
	rm -f $(OBJS) $(BOBJS)
fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)
	rm -f $(BNAME)
re: fclean all
re_bonus: fclean bonus
.PHONY: all bonus clean fclean re re_bonus


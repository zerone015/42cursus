# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 22:02:26 by yoson             #+#    #+#              #
#    Updated: 2022/07/21 16:55:47 by yoson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
	init.c \
	parser.c \
	util.c \
	print_char.c \
	print_hex_address.c \
	print_hex_lower.c \
	print_hex_upper.c \
	print_nbr.c \
	print_percent.c \
	print_str.c \
	print_unbr.c
OBJS = $(SRCS:%.c=%.o)

all : $(NAME)
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@
$(NAME) : $(OBJS)
	ar rcs $@ $^
bonus :
	make all
clean : 
	rm -f $(OBJS) $(BOBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY: all bonus clean fclean re

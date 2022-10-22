# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 18:10:46 by yoson             #+#    #+#              #
#    Updated: 2022/10/23 02:55:07 by yoson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
	   init.c \
	   parser.c \
	   util.c \
	   util2.c \
	   print_char.c \
	   print_hex_address.c \
	   print_hex_lower.c \
	   print_hex_upper.c \
	   print_nbr.c \
	   print_unbr.c \
	   print_percent.c \
	   print_str.c
OBJS = $(SRCS:%.c=%.o)

all : $(NAME)
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@
$(NAME) : $(OBJS)
	ar rcs $@ $^
bonus : $(NAME)
clean : 
	rm -f $(OBJS) $(BOBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY: all bonus clean fclean re

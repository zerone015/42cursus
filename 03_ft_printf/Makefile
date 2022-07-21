# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 18:10:46 by yoson             #+#    #+#              #
#    Updated: 2022/07/15 22:06:09 by yoson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
BSRCS = ft_printf_bonus.c \
       init_bonus.c \
       parser_bonus.c \
	   util_bonus.c \
	   print_char_bonus.c \
       print_hex_address_bonus.c \
	   print_hex_lower_bonus.c \
	   print_hex_upper_bonus.c \
	   print_nbr_bonus.c \
	   print_unbr_bonus.c \
	   print_percent_bonus.c \
	   print_str_bonus.c
SRCS = ft_printf.c \
	   init.c \
	   parser.c \
	   util.c \
	   print_char.c \
	   print_hex_address.c \
	   print_hex_lower.c \
	   print_hex_upper.c \
	   print_nbr.c \
	   print_unbr.c \
	   print_percent.c \
	   print_str.c
OBJS = $(SRCS:%.c=%.o)
BOBJS = $(BSRCS:%.c=%.o)
ifdef WITH_BONUS
    OBJ_FILES = $(OBJS) $(BOBJS)
else
    OBJ_FILES = $(OBJS)
endif

all : $(NAME)
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@
$(NAME) : $(OBJ_FILES)
	ar rcs $@ $^
bonus :
	make WITH_BONUS=1 all
clean : 
	rm -f $(OBJS) $(BOBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY: all bonus clean fclean re

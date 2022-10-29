# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoson <yoson@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 18:10:46 by yoson             #+#    #+#              #
#    Updated: 2022/10/29 23:18:16 by yoson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

CC 			= cc
FLAGS 		= -Wall -Wextra -Werror

SRC_DIR		= ./mandatory/srcs/
BSRC_DIR	= ./bonus/srcs/
LIB_DIR		= ./libft/
LIB_NAME	= libft.a

SRC 		= 	ft_printf.c \
	   	  	  	init.c \
	      		parser.c \
	      		print_char.c \
	      		print_address.c \
	      		print_hex_lower.c \
	      		print_hex_upper.c \
	      		print_decimal.c \
	      		print_u_decimal.c \
	      		print_percent.c \
	      		print_str.c
BSRC		=	ft_printf_bonus.c \
	   	  	  	init_bonus.c \
	      		parser_bonus.c \
	      		util_bonus.c \
	      		print_char_bonus.c \
	      		print_address_bonus.c \
	      		print_hex_lower_bonus.c \
	      		print_hex_upper_bonus.c \
	      		print_decimal_bonus.c \
	      		print_u_decimal_bonus.c \
	      		print_percent_bonus.c \
	      		print_str_bonus.c
SRCS		=	$(addprefix $(SRC_DIR), $(SRC))
BSRCS		=	$(addprefix $(BSRC_DIR), $(BSRC))
OBJS		=	$(SRCS:%.c=%.o)
BOBJS 		= 	$(BSRCS:%.c=%.o)

ifdef PRINTF_WITH_BONUS
	INC_DIR = ./bonus/includes/
    OBJ_FILES = $(BOBJS)
else
	INC_DIR = ./mandatory/includes/
    OBJ_FILES = $(OBJS)
endif

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR)

all : $(NAME)

bonus :
	make PRINTF_WITH_BONUS=1 all
	
$(NAME) : $(OBJ_FILES)
	make -C $(LIB_DIR)
	cp $(LIB_DIR)$(LIB_NAME) $(NAME)
	ar rcs $@ $^

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

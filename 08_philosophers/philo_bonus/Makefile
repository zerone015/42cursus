# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoson <yoson@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 16:11:41 by kijsong           #+#    #+#              #
#    Updated: 2022/09/13 00:07:51 by yoson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo_bonus

CC		= cc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRC_DIR	= ./philo_bonus/

SRCS	= action_bonus.c init_bonus.c kill_bonus.c main_bonus.c monitor_bonus.c \
		  utils_stdlib_bonus.c utils_string_bonus.c utils_time_bonus.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $^

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	make fclean
	make all

PHONY: all clean fclean re

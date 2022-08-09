# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 03:23:54 by yoson             #+#    #+#              #
#    Updated: 2022/08/09 15:11:02 by yoson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= cc
FLAGS		= -Wall -Werror -Wextra
AR			= ar rcs
RM			= rm -f

INCS_DIR	= ./includes/
SRCS_DIR	= ./srcs/
LIB_DIR		= ./libft/
MLX_DIR		= ./mlx/

LIB_NAME	= ./libft/libft.a
INCS		= -I includes
MLX_FLAGS	= -L./mlx -lmlx -framework OpenGL -framework Appkit

SRC			=	main.c init.c validate.c parser.c draw.c press.c move.c error.c get_next_line.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS		=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) -L $(LIB_DIR) -lft -I $(INCS_DIR) -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re : clean all

PHONY	: all clean fclean re

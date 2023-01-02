NAME        = BraiiiiiiinnnzzzZ
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
CPPFLAGS	= -I .
SRCS		= main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJS		= $(SRCS:%.cpp=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
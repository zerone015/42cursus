NAME        = MoarBrainz
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
SRCS		= main.cpp Zombie.cpp ZombieHorde.cpp
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
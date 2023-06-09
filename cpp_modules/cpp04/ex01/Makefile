NAME        = brain
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
SRCS		= main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
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
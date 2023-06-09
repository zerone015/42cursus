NAME        = dynamicCast
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
SRCS		= main.cpp Base.cpp A.cpp B.cpp C.cpp
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
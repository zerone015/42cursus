NAME        = phoneBook
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
CPPFLAGS	= -I .
SRCS		= main.cpp Contact.cpp PhoneBook.cpp utils.cpp
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
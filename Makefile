NAME		= tester
SRC			= src/main.cpp src/map/map_test.cpp src/vector/vector.hpp src/stack/stack.hpp src/utility/utility_test.cpp
HEADER		= include/Vector.hpp include/Map.hpp include/Utility.hpp include/Stack.hpp
OBJS		= $(SRC:.cpp=.o)
CPP			= c++ 
RM			= rm -f
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -Iinclude

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADER)
			$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(OBJS)

test: $(NAME)
	@./$(NAME);


re:			fclean all

save:
	git commit -am "$(MAKECMDGOALS)";
	git push https://github.com/swautelet/containers.git;

.PHONY:		all clean fclean re test save

# https://github.com/divinepet/ft_containers-unit-test.git 
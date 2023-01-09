NAME			= tester
SRC				= src/main_ft.cpp src/main_std.cpp src/map/map_test.cpp src/vector/vector_test.hpp src/stack/stack_test.hpp src/utility/utility_test.cpp
VECT_SRC		= 
MAP_SRC			= "src/map/assign overload.cpp" src/map/at().cpp src/map/clear().cpp "src/map/compare class.cpp" src/map/constructor.cpp src/map/count().cpp src/map/empty().cpp src/map/equal_range().cpp src/map/erase(inputIt).cpp src/map/erase(key).cpp 
STACK_SRC		= 
UTILITY_SRC		= 
VECT_OBJS		= $(VECT_SRC:.cpp=.o)
MAP_OBJS		= $(MAP_SRC:.cpp=.o)
STACK_OBJS		= $(STACK_SRC:.cpp=.o)
UTILITY_OBJS	= $(UTILITY_SRC:.cpp=.o)
HEADER			= include/Vector.hpp include/Map.hpp include/Utility.hpp include/Stack.hpp
OBJS			= $(SRC:.cpp=.o)
CPP				= c++ 
RM				= rm -f
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98 -Iinclude

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

.o : .c
	$(CPP) $(CPPFLAGS) $? -c -o $(OBJS);

re:			fclean all

save:
	git commit -am "$(MAKECMDGOALS)";
	git push https://github.com/swautelet/containers.git;

.PHONY:		all clean fclean re test save

# https://github.com/divinepet/ft_containers-unit-test.git 
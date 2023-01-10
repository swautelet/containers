NAME_STD		= tester_std
NAME_FT			= tester_ft
SRC_STD			= src/main_ft.cpp    
SRC_FT			= src/main_std.cpp
VECT_SRC		= src/vector/vector_test.cpp src/vector/assign().cpp src/vector/assign(std_iterators).cpp src/vector/at().cpp src/vector/back().cpp src/vector/begin().cpp src/vector/capacity().cpp src/vector/clear().cpp src/vector/constructor.cpp src/vector/constructor(std_iterators).cpp src/vector/data().cpp src/vector/empty().cpp src/vector/end().cpp src/vector/erase(range).cpp src/vector/erase(value).cpp src/vector/front().cpp src/vector/insert(fill).cpp src/vector/insert(range).cpp src/vector/insert(std_iterators).cpp src/vector/insert(value).cpp src/vector/iterators.cpp src/vector/max_size().cpp src/vector/operator!=.cpp src/vector/operator<.cpp src/vector/operator<=.cpp src/vector/operator==.cpp src/vector/operator>.cpp src/vector/operator>=.cpp src/vector/operator[].cpp src/vector/pop_back().cpp src/vector/push_back().cpp src/vector/rbegin().cpp src/vector/rend().cpp src/vector/reserve().cpp src/vector/resize().cpp src/vector/size().cpp src/vector/swap().cpp src/vector/using_allocator.cpp
MAP_SRC			= src/map/map_test.cpp src/map/assign_overload.cpp src/map/at().cpp src/map/clear().cpp src/map/compare_class.cpp src/map/constructor.cpp src/map/count().cpp src/map/empty().cpp src/map/equal_range().cpp src/map/erase(inputIt).cpp src/map/erase(key).cpp src/map/erase(pos).cpp src/map/find().cpp src/map/insert(hint).cpp src/map/insert(InputIt).cpp src/map/insert(value).cpp src/map/iterators.cpp src/map/key_comp().cpp src/map/lower_bound().cpp src/map/max_size().cpp src/map/operator!=.cpp src/map/operator<.cpp src/map/operator<=.cpp src/map/operator==.cpp src/map/operator>.cpp src/map/operator>=.cpp src/map/operator[].cpp src/map/reverse_iterators.cpp src/map/size().cpp src/map/swap().cpp src/map/upper_bound().cpp src/map/using_allocator.cpp
STACK_SRC		= src/stack/stack_test.cpp src/stack/constructor.cpp src/stack/empty().cpp src/stack/operator!=.cpp src/stack/operator<.cpp src/stack/operator<=.cpp src/stack/operator==.cpp src/stack/operator>.cpp src/stack/operator>=.cpp src/stack/pop().cpp src/stack/push().cpp src/stack/size().cpp src/stack/top().cpp
UTILITY_SRC		= src/utility/utility_test.cpp src/utility/enable_if.cpp src/utility/equal.cpp src/utility/is_integral.cpp src/utility/iterator_traits.cpp src/utility/lexicographical.cpp 
VECT_OBJS		= $(VECT_SRC:.cpp=.o)
MAP_OBJS		= $(MAP_SRC:.cpp=.o)
STACK_OBJS		= $(STACK_SRC:.cpp=.o)
UTILITY_OBJS	= $(UTILITY_SRC:.cpp=.o)
HEADER			= include/Vector.hpp include/Map.hpp include/Utility.hpp include/Stack.hpp
OBJS_FT			= $(SRC_FT:.cpp=.o)
OBJS_STD		= $(SRC_STD:.cpp=.o)
CPP				= c++ 
RM				= rm -f
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98 -Iinclude

all:		$(NAME_STD) $(NAME_FT)

$(NAME_STD): $(OBJS_STD) $(VECT_OBJS) $(MAP_OBJS) $(STACK_OBJS) $(UTILITY_OBJS)
			$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS_STD) $(VECT_OBJS) $(MAP_OBJS) $(STACK_OBJS) $(UTILITY_OBJS)
		
$(NAME_FT): $(OBJS_FT) $(VECT_OBJS) $(MAP_OBJS) $(STACK_OBJS) $(UTILITY_OBJS)
			$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS_FT) $(VECT_OBJS) $(MAP_OBJS) $(STACK_OBJS) $(UTILITY_OBJS)

clean:
			@$(RM) $(OBJS_STD) $(OBJS_FT) $(VECT_OBJS) $(MAP_OBJS) $(STACK_OBJS) $(UTILITY_OBJS)

fclean:		clean
			$(RM) $(NAME_FT)
			$(RM) $(NAME_STD)
			$(RM) $(OBJS)

test: $(NAME_STD) $(NAME_FT)
	@./$(NAME_STD)
	@./$(NAME_FT)

.o : .c
	$(CPP) $(CPPFLAGS) $? -c

re:			fclean all

save:
	git commit -am "$(MAKECMDGOALS)";
	git push https://github.com/swautelet/containers.git;

.PHONY:		all clean fclean re test save

# https://github.com/divinepet/ft_containers-unit-test.git 
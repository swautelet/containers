NAME_STD		= tester_std
NAME_FT			= tester_ft
# src/vector_test.cpp src/map_test.cpp src/stack_test.cpp src/utility_test.cpp
SRC_STD			= src/main.cpp src/run_test_std.cpp
SRC_FT			= src/main.cpp  src/run_test_ft.cpp
VECT_TMP		= src/vector/assign().hpp src/vector/assign(std_iterators).hpp src/vector/at().hpp src/vector/back().hpp src/vector/begin().hpp src/vector/capacity().hpp src/vector/clear().hpp src/vector/constructor.hpp src/vector/constructor(std_iterators).hpp src/vector/data().hpp src/vector/empty().hpp src/vector/end().hpp src/vector/erase(range).hpp src/vector/erase(value).hpp src/vector/front().hpp src/vector/insert(fill).hpp src/vector/insert(range).hpp src/vector/insert(std_iterators).hpp src/vector/insert(value).hpp src/vector/iterators.hpp src/vector/max_size().hpp src/vector/operator!=.hpp src/vector/operator<.hpp src/vector/operator<=.hpp src/vector/operator==.hpp src/vector/operator>.hpp src/vector/operator>=.hpp src/vector/operator[].hpp src/vector/pop_back().hpp src/vector/push_back().hpp src/vector/rbegin().hpp src/vector/rend().hpp src/vector/reserve().hpp src/vector/resize().hpp src/vector/size().hpp src/vector/swap().hpp src/vector/using_allocator.hpp src/vector/v__service.hpp
MAP_TMP			= src/map/assign_overload.hpp src/map/at().hpp src/map/clear().hpp src/map/compare_class.hpp src/map/constructor.hpp src/map/count().hpp src/map/empty().hpp src/map/equal_range().hpp src/map/erase(inputIt).hpp src/map/erase(key).hpp src/map/erase(pos).hpp src/map/find().hpp src/map/insert(hint).hpp src/map/insert(InputIt).hpp src/map/insert(value).hpp src/map/iterators.hpp src/map/key_comp().hpp src/map/lower_bound().hpp src/map/max_size().hpp src/map/operator!=.hpp src/map/operator<.hpp src/map/operator<=.hpp src/map/operator==.hpp src/map/operator>.hpp src/map/operator>=.hpp src/map/operator[].hpp src/map/reverse_iterators.hpp src/map/size().hpp src/map/swap().hpp src/map/upper_bound().hpp src/map/using_allocator.hpp src/map/m__service.hpp
STACK_TMP		= src/stack/constructor.hpp src/stack/empty().hpp src/stack/operator!=.hpp src/stack/operator<.hpp src/stack/operator<=.hpp src/stack/operator==.hpp src/stack/operator>.hpp src/stack/operator>=.hpp src/stack/pop().hpp src/stack/push().hpp src/stack/size().hpp src/stack/top().hpp src/stack/s__service.hpp
UTILITY_TMP		= src/utility/enable_if.hpp src/utility/equal.hpp src/utility/is_integral.hpp src/utility/iterator_traits.hpp src/utility/lexicographical.hpp 
# VECT_OBJS		= $(VECT_SRC:.cpp=.o)
# MAP_OBJS		= $(MAP_SRC:.cpp=.o)
# STACK_OBJS		= $(STACK_SRC:.cpp=.o)
# UTILITY_OBJS	= $(UTILITY_SRC:.cpp=.o)
HEADER			= include/Vector.hpp include/Map.hpp include/Utility.hpp include/Stack.hpp
OBJS_FT			= $(SRC_FT:.cpp=.o)
OBJS_STD		= $(SRC_STD:.cpp=.o)
CPP				= c++ 
RM				= rm -f
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98 -Iinclude 
LOG_FILE		= std.log ft.log 
COMPARE 		= src/compare.sh
TIME_LOG		= std_time.log ft_time.log

all: $(NAME_STD) $(NAME_FT)

std: $(NAME_STD)

ft: $(NAME_FT)

$(NAME_STD): $(OBJS_STD) 
			$(CPP) $(CPPFLAGS) -o $(NAME_STD) $(OBJS_STD)
		
$(NAME_FT): $(OBJS_FT) 
			$(CPP) $(CPPFLAGS) -o $(NAME_FT) $(OBJS_FT)

clean:
			$(RM) $(OBJS_STD) $(OBJS_FT)

fclean:		clean
			$(RM) $(NAME_FT)
			$(RM) $(NAME_STD)
			$(RM) $(LOG_FILE) $(TIME_LOG)

test: $(NAME_STD) $(NAME_FT)
	@echo "\033[32mlaunching std test\033[0m" 
	@./$(NAME_STD)
	@echo "\033[32mlaunching ft test\033[0m" 
	@./$(NAME_FT)
	@bash $(COMPARE)
	@echo "\033[32mall test are done\033[0m" 

.o : .c
	$(CPP) $(CPPFLAGS) $? -c

re:			fclean all

save:
	git commit -am "$(MAKECMDGOALS)";
	git push https://github.com/swautelet/containers.git;

.PHONY:		all clean fclean re test save std ft 

# https://github.com/divinepet/ft_containers-unit-test.git 
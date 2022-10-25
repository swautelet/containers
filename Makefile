NAME		= webserv
SRC			= src/main.cpp
HEADER		= include/vector.hpp
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


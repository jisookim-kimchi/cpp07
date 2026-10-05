CXX = c++
CXXFLAGS = -g -Wall -Wextra -Werror -std=c++17

NAME = iter
OBJ_DIR = obj_dir

HEADER = iter.hpp
SRCS = main.cpp
OBJS = $(OBJ_DIR)/$(SRCS:.cpp=.o)

$(OBJS) : $(SRCS) $(HEADER)
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

all : $(NAME)

clean : 
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

gdb : $(NAME)
		gdb -ex "break main" -ex "layout split" ./$(NAME)

.PHONY : all clean fclean re gdb
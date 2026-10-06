# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 17:13:16 by jisokim2          #+#    #+#              #
#    Updated: 2026/07/02 17:13:17 by jisokim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

CXX = c++

CXX_FLAGS = -g -Wall -Wextra -Werror -std=c++17

HEADER = whatever.hpp

SRCS = main.cpp
OBJ_DIR = obj_dir
OBJS = $(OBJ_DIR)/$(SRCS:.cpp=.o)

$(OBJS) : $(SRCS) $(HEADER)
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re : fclean all

gdb : $(NAME)
		gdb -ex "break main" -ex "layout split" ./$(NAME)

.PHONY : all clean fclean re gdb

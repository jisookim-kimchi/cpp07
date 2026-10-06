# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/05 13:50:20 by jisokim2          #+#    #+#              #
#    Updated: 2026/10/05 13:50:20 by jisokim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
		rm -rf $(OBJ_DIR)

re : fclean all

gdb : $(NAME)
		gdb -ex "break main" -ex "layout split" ./$(NAME)

.PHONY : all clean fclean re gdb
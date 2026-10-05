# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/05 13:50:31 by jisokim2          #+#    #+#              #
#    Updated: 2026/10/05 13:50:31 by jisokim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Array

CXX = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++17

HEADER = Array.hpp
SRCS = main.cpp
OBJ_DIR = obj_dr

OBJS = $(OBJ_DIR)/$(SRCS:.cpp=.o)

$(OBJS) : $(SRCS) $(HEADER)
		mkdir -p $(OBJ_DIR)
		$(CXX) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
		$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

gdb : $(NAME)
		gdb -ex "set print demangle on" -ex "break main" ./$(NAME)

.PHONY : all clean fclean re gdb
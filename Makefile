# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/28 19:29:06 by htaillef     #+#   ##    ##    #+#        #
#    Updated: 2017/11/29 13:50:56 by bpisano     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit

SRC = ./sources/main.c			\
	  ./sources/read_file.c		\
	  ./sources/input_verify.c	\
	  ./sources/model_builder.c	\
	  ./sources/model_verify.c	\
	  ./sources/adjustments.c	\
	  ./sources/map_builder.c	\
	  ./sources/position.c		\
	  ./sources/solve.c			\
	  ./sources/put.c			\
	  ./sources/contact.c		\
	  ./sources/display.c		\
	  ./sources/usage.c			\

OBJECTS = $(SRC:.c=.o)

LIB = libft.a

HEADS = ./includes

FLAGS = -Wall -Werror -Wextra

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
END = \033[0m

all: $(NAME)

$(LIB):
	@(cd libft/ && make)

$(NAME): $(LIB) $(OBJECTS)
	@gcc -o $(NAME) $(OBJECTS) libft/$(LIB)

%.o : %.c
	@gcc $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJECTS)
	@(cd libft/ && make clean)

fclean: clean
	@rm -rf $(NAME)
	@(cd libft/ && make fclean)

re: fclean all
	@echo "\n\t$(GREEN)All the process is ok$(END)\n"
	@(cd libft/ && make re)

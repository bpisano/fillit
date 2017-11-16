# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpisano <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 14:30:17 by bpisano           #+#    #+#              #
#    Updated: 2017/11/16 17:17:43 by bpisano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ./sources/read_file.c		\
	  ./sources/main.c			\

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
	@(cd libft/ && make re)
	@(cd libft/ && make clean)

$(NAME): $(LIB) $(OBJECTS)
	@gcc -o $(NAME) $(OBJECTS) libft/$(LIB)
	@echo "\tCreating $(NAME)\t\t\t$(GREEN)Done$(END)"

%.o : %.c
	@echo "\n\t$(BLUE)$(NAME)$(END)"
	@gcc $(FLAGS) -o $@ -c $<
	@echo "\tCompilings objects\t\t$(GREEN)Done$(END)"

clean:
	@echo "\n\t$(BLUE)CLEAN$(END)"
	@rm -rf $(OBJECTS)
	@echo "\tRemoving objects\t\t$(GREEN)Done$(END)"

fclean: clean
	@echo "\n\t$(BLUE)FCLEAN$(END)"
	@rm -rf $(NAME)
	@echo "\tRemoving $(NAME)\t\t\t$(GREEN)Done$(END)"

re: fclean all
	@echo "\n\t$(GREEN)All the process is ok$(END)\n"

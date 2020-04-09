##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for compilation
##

SRC	= $(shell find ./core/ -name "*.cpp")

OBJ = $(SRC:.cpp=.o)

NAME = a.out

CFLAGS = -W -Wextra
CFLAGS += -ldl

CC	=	g++

%.o: %.cpp
		@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $< | tr ' ' '-'
		@$(CC) -c -o $@ $< $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
		@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(NAME) | tr ' ' '-'

clean:
		@rm -f $(OBJ)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '-'

fclean:	clean
		@rm -f $(NAME)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '-'


re: fclean all

##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	$(shell find . -name "*.cpp")

OBJ = $(SRC:.cpp=.o)

NAME = ../lib_arcade_ncurses.so

CC	=	g++

CFLAGS = -W -Wextra
CFLAGS += -fPIC
CFLAGS += -c

CFLAGSLIB = -shared
CFLAGSLIB += -lncurses -lsfml-graphics

%.o: %.cpp
		@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $< | tr ' ' '-'
		@$(CC) -c -o $@ $< $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) -o $(CFLAGS) $(OBJ)
		@printf "[\033[0;36mbuilt>.o\033[0m] % 32s\n" $(NAME) | tr ' ' '-'
		@$(CC) $(OBJ) -o $(NAME) $(CFLAGSLIB)
		@printf "[\033[0;36mbuilt>.so\033[0m] % 32s\n" $(NAME) | tr ' ' '-'

clean:
		@rm -f $(OBJ)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '-'

fclean:	clean
		@rm -f $(NAME)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '-'

re: fclean all

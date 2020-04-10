##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for compilation
##

SRC	= $(shell find ./core/ -name "*.cpp")

OBJ = $(SRC:.cpp=.o)

NAME = arcade

CFLAGS = -W -Wextra
CFLAGS += -ldl

CC	=	g++

core:
		@cd core/ && $(MAKE) -s all

games:
		@cd games/nibbler/ && $(MAKE) -s all
		@cd games/pacman/ && $(MAKE) -s all

graphicals:
		@cd lib/lib_arcade_sfml/ && $(MAKE) -s all
		@cd lib/lib_arcade_ncurses/ && $(MAKE) -s all

%.o: %.cpp
		@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $< | tr ' ' '-'
		@$(CC) -c -o $@ $< $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
		@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(NAME) | tr ' ' '-'
		@cd lib/lib_arcade_sfml/ && $(MAKE) -s all
		@cd lib/lib_arcade_ncurses/ && $(MAKE) -s all
		@cd games/nibbler/ && $(MAKE) -s all
		@cd games/pacman/ && $(MAKE) -s all

clean:
		@rm -f $(OBJ)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '-'
		@cd lib/lib_arcade_sfml/ && $(MAKE) -s clean
		@cd lib/lib_arcade_ncurses/ && $(MAKE) -s clean
		@cd games/nibbler/ && $(MAKE) -s clean
		@cd games/pacman/ && $(MAKE) -s clean

fclean:	clean
		@rm -f $(NAME)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '-'
		@cd lib/lib_arcade_sfml/ && $(MAKE) -s fclean
		@cd lib/lib_arcade_ncurses/ && $(MAKE) -s fclean
		@cd games/nibbler/ && $(MAKE) -s fclean
		@cd games/pacman/ && $(MAKE) -s fclean


re: fclean all

/*
** EPITECH PROJECT, 2020
** src
** File description:
** src
*/

#ifndef src_HPP_
#define src_HPP_

#include <iostream>
#include "../games/nibbler/snake.hpp"
#include "../games/pacman/include/pacman.hpp"

class src_c {
    private:
    public:
};

#define RET(x) (x == "exit") ? true : false

#define MENUX           2
#define MENUY           0

int menu(lib_c *, snake_c *, pacman *);
int main_bcl(lib_c *);


std::vector<std::string> split_str(std::string str, char c);
std::vector<std::string> file_exist(std::string path);

#endif /* !src_HPP_ */

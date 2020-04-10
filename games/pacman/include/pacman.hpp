/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** pacman
*/

#ifndef PACMAN_H_
#define PACMAN_H_

#include "../src/map.hpp"
#include "../src/characters.hpp"
#include "../../../lib/lib.hpp"

class pacman {
    private:
        std::vector<enemy> enemys;
    public:
        pacman();
        virtual bool main_pacman(lib_c *);
        ~pacman();
};

typedef pacman *pacman_t();

#endif /* !PACMAN_H_ */

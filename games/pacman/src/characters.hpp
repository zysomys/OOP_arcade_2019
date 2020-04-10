/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** player
*/

#ifndef CHARACTERS_HPP_
#define CHARACTERS_HPP_

#include <bits/stdc++.h>
#include "ncurses.h"
#include "map.hpp"

enum direction {UP, DOWN, LEFT, RIGHT, NU};

class character {
    public:
        character();
    
        int pvgestion(int);

        void moove(map&);
        
        std::string get_type();

        direction get_dir();
        void set_dir(direction);

        bool change_dir(direction);
        void respawn(int, int);
        
        int get_x();
        int get_y();
    
        void set_data();

    private:
        int pv;
        int pos[2];
        direction dir;
};

class player : public character {
    private:
    public:
        void eat_something();
        std::string get_type();
        player(int, int);
        ~player();
};

class enemy : public character {
    private:
    public:
        void moove(int, map&);
        std::string get_type();
        enemy(int, int);
        int check_colide_enemys(player &p);
        ~enemy();
};

#endif /* !CHARACTERS_HPP_ */

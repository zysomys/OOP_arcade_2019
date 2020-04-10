/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "ncurses.h"
#include "../include/pacman.hpp"

pacman::pacman() {}

pacman::~pacman() {}

bool pacman::main_pacman(lib_c *lib)
{
    static int i = 0, key = 0, exit = 0;
    static player p(13, 12);
    static map test;


    for (int i = 0; i < 4; i++)
        enemys.push_back(enemy(13 + i, 9));

    lib->Event();
    key = lib->getKey();

    
    if (key == KEY_UP_) p.change_dir(DOWN);
    else if (key == KEY_LEFT_) p.change_dir(LEFT);
    else if (key == KEY_DOWN_) p.change_dir(UP);
    else if (key == KEY_RIGHT_) p.change_dir(RIGHT);

    p.moove(test);

    for (int i = 0; i < test.get_block_list().size(); i++) {
        if (test.get_block_list()[i].get_type() == WALL)
            lib->draw_sprite({(float)(test.get_block_list()[i].get_x()), (float)(test.get_block_list()[i].get_y())}, 1);
        if (test.get_block_list()[i].get_type() == POINT)
            lib->draw_sprite({(float)(test.get_block_list()[i].get_x()), (float)(test.get_block_list()[i].get_y())}, 7);
        if (test.get_block_list()[i].get_type() == SPACE)
            lib->draw_sprite({(float)(test.get_block_list()[i].get_x()), (float)(test.get_block_list()[i].get_y())}, 8);
    }
    
    lib->draw_sprite({(float)(p.get_x()), (float)(p.get_y())}, 6);

    
    
    for (int i = 0; i < 4; i++) {
        enemys[i].moove(i, test);
        lib->draw_sprite({(float)(enemys[i].get_x()), (float)(enemys[i].get_y())}, 4);
    }
    

    return (enemys[i].check_colide_enemys(p));
}

extern "C" {
    pacman *new_lib_pacman() {
        return new pacman();
    }
}

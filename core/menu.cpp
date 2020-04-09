/*
** EPITECH PROJECT, 2020
** menu
** File description:
** menu
*/

#include "dlload.hpp"
#include "src.hpp"

std::string selecteur(lib_c *lib, std::string mn, int Key, int move)
{
    std::string output = mn;

    if (mn == "base") {
        if ((Key == KEY_ENTER_ || Key == KEY_RIGHT_) && move == 0)
            output = "pacman", move = 0;
        else if ((Key == KEY_ENTER_ || Key == KEY_RIGHT_) && move == 1)
            output = "snake", move = 0;
        else if ((Key == KEY_ENTER_ || Key == KEY_RIGHT_) && move == 2)
            output = "lib", move = 0;
        else if ((Key == KEY_ENTER_ || Key == KEY_RIGHT_) && move == 3)
            return ("exit");
    }

    if (mn == "lib") {
        if ((Key == KEY_ENTER_ || Key == KEY_RIGHT_) && move == 0) {
            move = 0;

            lib->getDest();
            dlload dl("lib/lib_arcade_sfml.so");
            main_bcl(dl.getLib());
        }

        if ((Key == KEY_ENTER_ || Key == KEY_RIGHT_) && move == 1) {
            move = 0;

            lib->getDest();
            dlload dl("lib/lib_arcade_ncurses.so");
            main_bcl(dl.getLib());
        }
        if ((Key == KEY_ENTER_ || Key == KEY_RIGHT_) && move == 2)
            output = "base", move = 0;
    }

    return output;
}

int option(lib_c *lib, int move, std::vector<float> M_COORD, std::string opt)
{
    std::vector<int> M_RED = {150, 25, 5, 255};
    std::vector<int> M_GREEN = {21, 50, 5, 255};
    std::vector<std::string> opt_split = split_str(opt, ',');
    int j = 0;

    if (lib->getKey() == KEY_DOWN_ && move > 0) move--;
    if (lib->getKey() == KEY_UP_ && move < (int) opt_split.size() - 1) move++;

    for (auto i : opt_split)
        lib->draw_string({M_COORD[0], M_COORD[1] += 1}, 20, (move == j++) ? M_RED : M_GREEN, i);
    return move;
}

int menu(lib_c *lib, snake_c *libSnake)
{
    static std::string mn = "base";
    static std::vector<int> move = {0, 0};

    if (mn == "base") {
        move[0] = option(lib, move[0], {MENUX, MENUY}, "Pacman,Snake,lib,exit,");
        mn = selecteur(lib, mn, lib->getKey(), move[0]);
    } else if (mn == "lib") {
        move[1] = option(lib, move[1], {MENUX, MENUY}, "sfml,ncurses,back,");
        mn = selecteur(lib, mn, lib->getKey(), move[1]);
    } else if (mn == "snake") {
        mn = (libSnake->snake(lib, libSnake)) ? "base" : mn;
    } else if (mn == "pacman") {
    }

    return (RET(mn));
}

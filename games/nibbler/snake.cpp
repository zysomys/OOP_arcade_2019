/*
** EPITECH PROJECT, 2020
** snake
** File description:
** snake
*/

#include <stdlib.h>

#include "../../lib/lib.hpp"
#include "snake.hpp"

#define TABC (int)libS->getCoord().size() - 1

bool checkCoord(std::vector<coord_s> a, coord_s b)
{
    for (auto i : a)
        if (i.x == b.x && i.y == b.y)
            return (true);
    return (false);
}

void move_player(int Key, snake_c *libS)
{
    static std::vector<float> cd {-1, 0};
    std::vector<float> tp = cd;

    cd = (Key == KEY_UP_ && cd[1] != -1) ? (std::vector<float>){0, 1} : cd;
    cd = (Key == KEY_DOWN_ && cd[1] != 1) ? (std::vector<float>){0, -1} : cd;
    cd = (Key == KEY_RIGHT_ && cd[0] != -1) ? (std::vector<float>){1, 0} : cd;
    cd = (Key == KEY_LEFT_ && cd[0] != 1) ? (std::vector<float>){-1, 0} : cd;

    if (checkCoord(libS->getMap(), {libS->getCoord()[TABC].x + cd[0], libS->getCoord()[TABC].y + cd[1]}))
        return ((void) (cd = tp));

    for (int i = 0; i < TABC; i++)
        libS->setCoord(libS->getCoord()[i + 1], i);
    libS->setCoord({libS->getCoord()[TABC].x + cd[0], libS->getCoord()[TABC].y + cd[1]}, TABC);
}

void spawn(snake_c *libS)
{
    if (!libS->getExist()) {
        do {
            libS->setCoordBoost({(float)(rand() % 44 + 1), (float)(rand() % 15 + 1)});
        } while (checkCoord(libS->getMap(), libS->getCoordBoost()));
        libS->setExist(true);
    }
}

void addSnake(snake_c *libS)
{
    if (libS->getCoordBoost().x == libS->getCoord()[TABC].x && libS->getCoordBoost().y == libS->getCoord()[TABC].y) {
        libS->pushCoord(libS->getCoordBoost());
        libS->setExist(false);
        libS->setScore(libS->getScore() + 1);
    }
}

bool deathSnake(snake_c *libS)
{
    for (int i = 0; i < TABC; i++)
        if (libS->getCoord()[i].x == libS->getCoord()[TABC].x && libS->getCoord()[i].y == libS->getCoord()[TABC].y)
            return (true);
    if (libS->getCoord()[TABC].x > 44 || libS->getCoord()[TABC].x < 1 || libS->getCoord()[TABC].y > 15 || libS->getCoord()[TABC].y < 1)
        return (true);
    return (false);
}

int snake_c::snake(lib_c *lib, snake_c *libS)
{
    spawn(libS);

    addSnake(libS);
    move_player(lib->getKey(), libS);

    lib->draw_sprite({0, 0}, MAP);
    lib->draw_sprite({libS->getCoordBoost().x, libS->getCoordBoost().y}, BONUS);

    for (auto i : libS->getCoord())
        lib->draw_sprite({i.x, i.y}, PLAYER);
    lib->draw_string({35, 1}, 20, {250, 0, 0, 255}, (std::string)("Score : " + std::to_string(libS->getScore())));
    return (deathSnake(libS));
}

extern "C" {
    snake_c *new_lib_snake() {
        return new snake_c();
    }
}

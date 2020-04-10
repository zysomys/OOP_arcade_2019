/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** characters
*/

#include "characters.hpp"

//////////////////////CHARACTER////////////////////////
character::character() { };

int character::pvgestion(int n)
{
    pv += n;
    return (pv);
}

void character::set_data()
{
    dir = NU;
    pv = 3;
}

std::string character::get_type()
{
    return ("none");
}

direction character::get_dir()
{
    return (dir);
}

void character::set_dir(direction d)
{
    dir = d;
}

int character::get_x() { return (pos[0]); }

int character::get_y() { return (pos[1]); }

void character::moove(map &m)
{

    switch (get_dir()) {
        case LEFT:
            if (m.get_block(pos[0] - 1, pos[1]).get_type() != WALL) {
                pos[0] -= 1;
            } if (m.get_block(pos[0] - 1, pos[1]).get_type() == POINT) {
                m.get_block(pos[0] - 1, pos[1]).suicide();
            }
            break;
        case RIGHT:
            if (m.get_block(pos[0] + 1, pos[1]).get_type()!= WALL) {
                pos[0] += 1;
            } if (m.get_block(pos[0] + 1, pos[1]).get_type() == POINT) {
                m.get_block(pos[0] + 1, pos[1]).suicide();
            }
            break;
        case DOWN:
            if (m.get_block(pos[0], pos[1] + 1).get_type() != WALL) {
                pos[1] += 1;
            } if (m.get_block(pos[0], pos[1] + 1).get_type() == POINT) {
                m.get_block(pos[0], pos[1] + 1).suicide();
            }
            break;
        case UP:
            if (m.get_block(pos[0], pos[1] - 1).get_type() != WALL) {
                pos[1] -= 1;
            } if (m.get_block(pos[0], pos[1] - 1).get_type() == POINT) {
                m.get_block(pos[0], pos[1] - 1).suicide();
            }
            break;
        default:
            break;
    }
}

bool character::change_dir(direction d)
{
    if (d == NU)
        return (false);

    set_dir(d);
    return (true);
}

void character::respawn(int x = 0, int y = 0)
{
    pos[0] = x;
    pos[1] = y;
}


///////////////////////////////PLAYER////////////////////////////////
std::string player::get_type()
{
    return ("player");
}

player::player(int x, int y)
{
    respawn(x, y);
    set_data();
}

player::~player() {}


//////////////////////////////ENEMY/////////////////////////////////
enemy::enemy(int x, int y)
{
    respawn(x, y);
    set_data();
}

void enemy::moove(int index, map &m)
{
    srand(index + time(NULL));
    block ref(SPACE, 0, 0);

    switch (rand() % 4) {
        case LEFT:
            ref = m.get_block(get_x() - 1, get_y());

            if (ref.get_type() != WALL)
                respawn(get_x() - 1, get_y());
            break;
        case RIGHT:
            ref = m.get_block(get_x() + 1, get_y());

            if (ref.get_type() != WALL)
                respawn(get_x() + 1, get_y());
            break;
        case DOWN:
            ref = m.get_block(get_x(), get_y() + 1);

            if (ref.get_type() != WALL)
                respawn(get_x(), get_y() + 1);
            break;
        case UP:
            ref = m.get_block(get_x(), get_y() - 1);

            if (ref.get_type() != WALL)
                respawn(get_x(), get_y() - 1);
            break;
    }
}

enemy::~enemy()
{
}

int enemy::check_colide_enemys(player &p)
{
    if (get_x() == p.get_x() & get_y() == p.get_y()) {
        p.respawn(13, 12);
        p.pvgestion(-1);

        if (p.pvgestion(0) <= 0)
            return (1);
    }
    return (0);
}

/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** map
*/

#include "map.hpp"

/////////////////////MAP/////////////////////////////
std::vector<std::string> map::set_map_str()
{ return (map_string); }

map::map()
{
    std::string line;
    std::ifstream myfile("games/pacman/src/map");

    int y = 0;

    if (myfile.is_open()) {
        while (getline (myfile, line)) {
            map_string.push_back(line);
            for (auto i = 0; i < line.length(); i++) {
                switch (line[i]) {
                    case '#':
                        blocks.push_back(block(WALL, i, y));
                        break;
                    case '.':
                        blocks.push_back(block(POINT, i, y));
                        break;
                    default:
                        break;
                }
            }
            y++;
        }
        myfile.close();
    }
}

map::~map()
{}

block &map::get_block(int x, int y)
{
    for (auto i = 0; i < blocks.size(); i++) {
        if (blocks[i].get_x() == x & blocks[i].get_y() == y)
            return (blocks[i]);
    }
}

void map::destroy_item(block &b)
{
    std::string temp = map_string[b.get_y()];
    temp[b.get_x()] = ' ';
    map_string[b.get_y()] = temp;

    b.suicide();
}

std::vector<block> map::get_block_list()
{ return (blocks); }

//////////////////////////////BLOCK////////////////////////////////
block::block(btype t, int x, int y)
{
    type = t;
    pos[0] = x;
    pos[1] = y;
}

block::~block() {}

int block::get_x()
{ return (pos[0]); }

int block::get_y()
{ return (pos[1]); }

btype block::get_type()
{ return (type); }

void block::suicide()
{
    type = SPACE;
}

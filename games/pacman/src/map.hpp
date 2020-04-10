/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <bits/stdc++.h>
#include <string>

enum btype {WALL, POINT, SPACE};

class block {
    private:
        int pos[2];
        btype type;

    public:
        block(btype, int, int);
        int get_x();
        int get_y();
        btype get_type();
        void suicide();
        ~block();
};

class map {
    private:
        std::vector<std::string> map_string;
        std::vector<block> blocks;

    public:
        map();
        block &get_block(int, int);
        std::vector<block> get_block_list();
        std::vector<std::string> set_map_str();
        void destroy_item(block &);
        ~map();
};

#endif /* !MAP_HPP_ */

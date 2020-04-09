/*
** EPITECH PROJECT, 2020
** lib
** File description:
** lib
*/

#ifndef lib_HPP_
#define lib_HPP_

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <ncurses.h>

struct sprite_s {
    sf::Texture texture;
    sf::Sprite sprite;
};

class lib_c {
    private:
        sf::RenderWindow window_s;
        sf::Event event;

        WINDOW *window_n;

        std::vector<std::string> txt;

        std::vector<sprite_s> spr;

        int Key;

    public:
        lib_c();
        ~lib_c();
        virtual void print_test();

        virtual void display();
        virtual void clear();
        virtual bool isOpen();

        virtual void Event();

        virtual void init_lib();

        virtual void draw_sprite(std::vector<float> position, int tab);
        virtual void draw_rectangle(std::vector<float> position, std::vector<int> size, std::vector<int> rgba);
        virtual void draw_string(std::vector<float> position, int size, std::vector<int> rgba, std::string str);

        virtual void getDest() {
            return (this->~lib_c());
        }

        virtual int getKey() {
            return (this->Key);
        }
};

#define FRAME           7

#define BACKGROUND      0
#define PLAYER          1
#define BONUS           2
#define MAP             3

#define KEY_LEFT_       71
#define KEY_RIGHT_      72
#define KEY_DOWN_       73
#define KEY_UP_         74

#define KEY_ENTER_      58

typedef lib_c *lib_t();

#endif /* !lib_HPP_ */

/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** sfml
*/

#include <dirent.h>
#include <stdlib.h>
#include <time.h>

#include <fstream>

#include "../lib.hpp"

#define setPOS  (position[0] * 10.869) + 50, (position[1] * 21.764) + 100

std::vector<std::string> file_exist(std::string path)
{
    std::vector<std::string> output;

    DIR *dp = opendir(path.c_str());
    struct dirent *direntp;

    while ((direntp = readdir(dp)) != NULL)
        if (direntp->d_name[0] != '.')
            output.push_back(direntp->d_name);
    std::sort(output.begin(), output.end());
    return output;
}

lib_c::lib_c():window_s(sf::VideoMode(607, 1000), "{Arcade}")
{
    this->window_s.setFramerateLimit(FRAME);
    this->Key = -1;

    srand(time(NULL));

    std::vector<std::string> texture = file_exist("extra/texture/");

    for (int i = 0; i < (int) texture.size(); i++) this->spr.push_back(sprite_s());
    for (int i = 0; i < (int) texture.size(); i++) {
        this->spr[i].texture.loadFromFile("extra/texture/" + texture[i]);
        this->spr[i].sprite.setTexture(this->spr[i].texture);

        if (i == PLAYER) this->spr[i].sprite.setOrigin(-16, -16);
        if (i == BONUS) this->spr[i].sprite.setOrigin(-16, -16);
    }
}

lib_c::~lib_c()
{
    this->window_s.close();
}

void lib_c::init_lib()
{
}

void lib_c::print_test()
{
    std::cout << "print_test" << std::endl;
}

void lib_c::display()
{
    this->window_s.display();
}

void lib_c::clear()
{
    this->window_s.clear();
}

bool lib_c::isOpen()
{
    return (this->window_s.isOpen());
}

void lib_c::Event()
{

    static bool K = true;
    if (!K)
        this->Key = -1;
    while (this->window_s.pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed)
            this->window_s.close();

        if (this->event.type == sf::Event::KeyPressed && K) {
            this->Key = event.key.code;
            K = false;
        }
        if (this->event.type == sf::Event::KeyReleased && !K) {
            K = true;
        }
    }
}

void lib_c::draw_sprite(std::vector<float> position, int tab)
{
    if (tab == -1) {
        tab = BACKGROUND;
        this->spr[tab].sprite.setPosition({0, 0});
    } else
        this->spr[tab].sprite.setPosition(setPOS);
    this->window_s.draw(this->spr[tab].sprite);
}

void lib_c::draw_rectangle(std::vector<float> position, std::vector<int> size, std::vector<int> rgba)
{
    sf::RectangleShape rectangle(sf::Vector2f(size[0], size[1]));

    rectangle.setFillColor(sf::Color(rgba[0], rgba[1], rgba[2], rgba[3]));
    rectangle.setPosition(setPOS);
    this->window_s.draw(rectangle);
}

void lib_c::draw_string(std::vector<float> position, int size, std::vector<int> rgba, std::string str)
{
    sf::Font font;
    sf::Text text;

    if (!font.loadFromFile("extra/arial.ttf"))
        exit (84);
    
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(size);
    text.setFillColor(sf::Color(rgba[0], rgba[1], rgba[2], rgba[3]));
    text.setPosition(setPOS); 

    this->window_s.draw(text);
}

extern "C" {
    lib_c *new_lib() {
        return new lib_c();
    }
}

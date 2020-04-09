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
#include <cmath>

#include "../lib.hpp"

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

int binary(int n)
{
    int output = 0;

    for (int i = 0, tp = 0; n > 0; i++) {
        tp = n % 10;
        n /= 10;
        output += tp * pow(2, i);
    }
    return output;
}

lib_c::lib_c()
{
    this->Key = -1;

    srand(time(NULL));

    std::vector<std::string> texture = file_exist("extra/file/");

    for (int i = 0; i < (int) texture.size(); i++) {
        std::string line = "", output = "";
        std::ifstream data("extra/file/" + texture[i]);

        while (std::getline(data, line)) output += (line + '\n');
        this->txt.push_back((output.size() == 2) ? output.substr(0, output.size() - 1) : output);
    }

    initscr();
    noecho();
    keypad(stdscr, TRUE);

    timeout((int)(1000/FRAME));

    mvprintw(0, 0, "%s\n", this->txt[0].c_str());

    this->window_n = newwin(17, 46, 6, 6);
    refresh();
    this->draw_sprite({0}, -1);
}

lib_c::~lib_c()
{
    endwin();
}

void lib_c::init_lib()
{
}

void lib_c::print_test()
{
}

void lib_c::display()
{
}

void lib_c::clear()
{
    wrefresh(this->window_n);
    wclear(this->window_n);
}

bool lib_c::isOpen()
{
    return ((this->Key == 'q' - 'a') ? false : true);
}

void lib_c::Event()
{
    int tmp = getch();

    if (tmp == KEY_LEFT) return (void)(this->Key = KEY_LEFT_);
    if (tmp == KEY_RIGHT) return (void)(this->Key = KEY_RIGHT_);
    if (tmp == KEY_UP) return (void)(this->Key = KEY_DOWN_);
    if (tmp == KEY_DOWN) return (void)(this->Key = KEY_UP_);

    if (tmp == KEY_ENTER) return (void)(this->Key = KEY_ENTER_);

    if (tmp >= 'a' && tmp <= 'z') return (void)(this->Key = tmp - 'a');

    this->Key = -1;
}

void lib_c::draw_rectangle(std::vector<float> position, std::vector<int> size, std::vector<int> rgba)
{
}

void lib_c::draw_string(std::vector<float> position, int size, std::vector<int> rgba, std::string str)
{
    int id = 0, nb = 0;
    int *tppt;

    tppt = &rgba[0];

    std::vector<int> tab = {0, 0, 0};

    for (int i = 0; i < 3; i++)
        if (rgba[i] > *tppt)
            tppt = &rgba[i];

    for (int i = 0; i < 3; i++)
        nb += ((rgba[i] > (int)(*tppt / 2)) ? 1 : 0) * pow(10,i);
    id = binary(nb);
    start_color();
    init_pair(id, id, COLOR_BLACK);

    wattron(this->window_n, COLOR_PAIR(id));
    mvwprintw(this->window_n, position[1], position[0], "%s", str.c_str());
    wattroff(this->window_n, COLOR_PAIR(id));
}

void lib_c::draw_sprite(std::vector<float> position, int tab)
{
    if (tab == -1)
        return ((void)box(this->window_n, 0, 0));
    mvwprintw(this->window_n, position[1], position[0], "%s", this->txt[tab].c_str());
}

extern "C" {
    lib_c *new_lib() {
        return new lib_c();
    }
}

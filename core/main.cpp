/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "dlload.hpp"
#include "src.hpp"

#include <unistd.h>

snake_c *nibblerGames()
{
    void *_handle = dlopen("games/lib_arcade_nibbler.so", RTLD_LAZY);
    void *make = dlsym(_handle, "new_lib_snake");
    snake_t *lib = (snake_t *)make;
    return (lib());
}

int main_bcl(lib_c *lib)
{
    snake_c *libSnake = nibblerGames();

    while (lib->isOpen()) {
        lib->clear();
        lib->Event();

        lib->draw_sprite({0, 0}, -1);

        if (menu(lib, libSnake)) return(true);

        lib->display();
    }
}

void gestError(int c, char **v)
{
    if (c != 2)
        exit(84);
}

int main(int ac, char **av)
{
    gestError(ac, av);

    dlload dl(av[1]);
    lib_c *lib = dl.getLib();
    main_bcl(lib);

    return (0);
}

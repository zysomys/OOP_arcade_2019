/*
** EPITECH PROJECT, 2020
** dlload
** File description:
** dlload
*/

#ifndef dlload_HPP_
#define dlload_HPP_

#include "../lib/lib.hpp"

#include <iostream>
#include <dlfcn.h>

class dlload {
    private:
        void *_handle;

        std::string _path;

        lib_c *my_lib;

    public:
        dlload(std::string path) {
            if (!(_handle = dlopen(path.c_str(), RTLD_LAZY))) {
                std::cerr << "[error - dlopen]: " << dlerror() << std::endl;
                exit (1);
            }
            my_lib = this->dlload_exploit("new_lib");
        }

        ~dlload() {
            if (dlclose(_handle) != 0) {
                std::cerr << "[error - dlclose]: " << dlerror() << std::endl;
                exit (1);
            }
        }

        lib_c *dlload_exploit(std::string funct) {
            void *make = dlsym(_handle, funct.c_str());

            if (!make) {
                std::cerr << "[error - dlsym]:" << dlerror() << std::endl;
                exit (1);
            }

            lib_t *lib = (lib_t *)make;

            return (lib());
        }

        lib_c *getLib() {
            return (this->my_lib);
        }
};

#endif /* !dlload_HPP_ */


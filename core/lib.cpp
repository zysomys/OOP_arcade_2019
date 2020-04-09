/*
** EPITECH PROJECT, 2020
** lib
** File description:
** lib
*/

#include <iostream>
#include <vector>
#include <dirent.h>

std::vector<std::string> split_str(std::string str, char c)
{
    std::vector<std::string> output;
    std::string tmp = "";

    for (char i : str) {
        if (i == c) {
            output.push_back(tmp);
            tmp = "";
        } else
            tmp = tmp + i;
    }
    return (output);
}

std::vector<std::string> file_exist(std::string path)
{
    std::vector<std::string> output;

    DIR *dp = opendir(path.c_str());
    struct dirent *direntp;

    while ((direntp = readdir(dp)) != NULL)
        output.push_back(direntp->d_name);
    return output;
}

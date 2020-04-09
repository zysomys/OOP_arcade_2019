/*
** EPITECH PROJECT, 2020
** snake
** File description:
** snake
*/

#ifndef snake_HPP_
#define snake_HPP_

#include <fstream>

struct coord_s{
    float x;
    float y;
};

class snake_c {
    private:
        std::vector<coord_s> coord;
        std::vector<coord_s> map;
        coord_s coordBoost;
        coord_s coordDir;
        bool exist;
        int score;

    public:
        snake_c() {
            for (int i = 0; i < 4; i++)
                coord.push_back((coord_s){(float)(20 + 4 - i), 10});

            this->coordBoost = {0, 0};
            this->coordDir = {-1, 0};
            this->exist = false;
            this->score = 4;

            std::string line = "";
            std::ifstream data("extra/file/03Map.txt");

            for (float i = 0; std::getline(data, line); i++)
                for (float j = 0; line[j]; j++)
                    if (line[j] != ' ')
                        this->map.push_back((coord_s){j, i});
        }

        ~snake_c() {
            this->coord.clear();
            this->map.clear();
        }

        virtual int snake(lib_c *lib, snake_c *libS);

        virtual std::vector<coord_s> getCoord() {
            return (this->coord);
        }
        virtual void setCoord(coord_s coord, int nb) {
            this->coord[nb] = coord;
        }
        virtual void pushCoord(coord_s c) {
            this->coord.push_back(c);
        }

        virtual bool getExist() {
            return (this->exist);
        }
        virtual void setExist(bool b) {
            this->exist = b;
        }

        virtual coord_s getCoordBoost() {
            return(this->coordBoost);
        }
        virtual void setCoordBoost(coord_s c) {
            this->coordBoost = c;
        }

        virtual coord_s getCoordDir() {
            return(this->coordDir);
        }
        virtual void setCoordDir(coord_s c) {
            this->coordDir = c;
        }

        virtual int getScore() {
            return (this->score);
        }
        virtual void setScore(int s) {
            this->score = s;
        }

        virtual std::vector<coord_s> getMap() {
            return (this->map);
        }
        virtual void setMap(std::vector<coord_s> M) {
            this->map = M;
        }
};

int snake(lib_c *lib, snake_c *libS);

typedef snake_c *snake_t();

#endif /* !snake_HPP_ */

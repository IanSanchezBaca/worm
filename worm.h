
#ifndef worm
#define worm
#include "food.h"
#include <vector>
using namespace std;

class Worm
{
private:
    // int size;
    bool dead;
    int Xpos;
    int Ypos;
    // vector<Worm> body;
    // vector<int> body_x = {0};
    // vector<int> body_y = [0];
    char direction;

public:
    Worm()
    {
        Xpos = 1;
        Ypos = 1;
        direction = 'r';
        dead = false;
    }
    bool is_dead();
    void print_field(Food &apple, vector<Worm> &w);
    // void print_body(int x, int y, Food &apple, Worm w);
    void logic(int input, Food &apple, vector<Worm> &w);
    int score = 0;
    bool crashed_into_body = false;
    bool crashed_into_wall = false;

}; // class worm

#endif
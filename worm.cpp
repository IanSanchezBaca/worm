#include <iostream>
#include "food.h"
#include "worm.h"
#include <vector>
using namespace std;

bool Worm::is_dead()
{
    return dead;
} // is_dead

// void Worm::print_body(int x, int y, Food &apple, Worm w)
// {

//     if (Xpos == x && Ypos == y)
//     {
//         cout << 'Q';
//     }
//     else if (x == apple.xpos && y == apple.ypos)
//     {
//         cout << 'F';
//     }
//     else
//     {
//         cout << " ";
//     }
// } // print_body

void Worm::print_field(Food &apple, vector<Worm> &w)
{
    system("clear");
    bool empty = true;
    for (int y = 0; y < 20; y++)
    {
        for (int x = 0; x < 20; x++)
        {
            if (y == 0 || y == 19 || x == 0 || x == 19)
            {
                cout << '#';
            }
            else
            {
                if (x == apple.xpos && y == apple.ypos)
                {
                    cout << 'F';
                }
                else
                {
                    for (int i = 0; i < (int)w.size(); i++)
                    {
                        if (w[i].Xpos == x && w[i].Ypos == y)
                        {
                            cout << 'Q';
                            empty = false;
                        }
                    }
                    if (empty)
                    {
                        empty = true;
                        cout << ' ';
                    }
                    empty = true;
                }
            }
        }
        cout << endl;
    }

} // print_field

void Worm::logic(int input, Food &apple, vector<Worm> &w)
{
    // update the body
    if ((int)w.size() > 1)
    {
        for (int i = 1; i < (int)w.size(); i++)
        {
            w[i] = w[i - 1];
        } // end for i}
    }

    // update the head
    if (w[0].direction == 'r')
    {
        w[0].Xpos++;
    }
    if (w[0].direction == 'l')
    {
        w[0].Xpos--;
    }
    if (w[0].direction == 'u')
    {
        w[0].Ypos--;
    }
    if (w[0].direction == 'd')
    {
        w[0].Ypos++;
    }

    // fist update the "head"
    if (input == 119 || input == 87)
    {
        // up
        w[0].direction = 'u';
    } // end if
    if (input == 115 || input == 83)
    {
        // down
        w[0].direction = 'd';
    } // end if
    if (input == 97 || input == 65)
    {
        // left
        w[0].direction = 'l';
    } // end if
    if (input == 100 || input == 68)
    {
        // right
        w[0].direction = 'r';
    } // end if

    // check if the head crashes into wall
    if (w[0].Xpos == 0 || w[0].Ypos == 0 || w[0].Xpos == 20 || w[0].Ypos == 20)
    {
        w[0].dead = true;
    }

    // check if the head crashes into the body
    if ((int)w.size() != 1)
    {
        // only happens if it has a body
        for (int i = 1; i < (int)w.size(); i++)
        {
            if (w[0].Xpos == w[i].Xpos && w[0].Ypos == w[i].Ypos)
            {
                w[0].dead = true;
            }
        }
    }

    // check if head crashes into food
    if ((w[0].Xpos == apple.xpos && w[0].Ypos == apple.ypos))
    {
        Worm uwu = w[(int)w.size() - 1];
        w.push_back(uwu);
        apple.randomize();
        score++;
    }

    print_field(apple, w);
} // logic
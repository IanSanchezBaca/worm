#include <iostream>
#include "food.h"
#include "worm.h"
#include <vector>
using namespace std;

bool Worm::is_dead()
{
    return dead;
} // is_dead

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
                            cout << Q;
                            empty = false;
                        }
                    }
                    if (empty)
                    {
                        // empty = true;
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
    
    // update the body
    if ((int)w.size() > 1)
    {
        // w[i].direction = w[i - 1].direction;
        for (int i = (int)w.size()-1; i > 0; i--)
        { 
          w[i].Xpos = w[i-1].Xpos;
          w[i].Ypos = w[i-1].Ypos;  
        } // end for i}
    }
    // update the body
    // for (int i = 0; i < (int)w.size(); i++)
    // {
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
    // }

    

    // check if the head crashes into wall
    if (w[0].Xpos == 0 || w[0].Ypos == 0 || w[0].Xpos == 20 || w[0].Ypos == 20)
    {
        w[0].crashed_into_wall = true;
        w[0].dead = true;
        return;
    }

    // check if the head crashes into the body
    if ((int)w.size() != 1)
    {
        // only happens if it has a body
        for (int i = 1; i < (int)w.size(); i++)
        {
            if (w[0].Xpos == w[i].Xpos && w[0].Ypos == w[i].Ypos)
            {
                w[0].crashed_into_body = true;
                w[0].dead = true;
                return;
            }
        }
    }

    // check if head crashes into food
    if ((w[0].Xpos == apple.xpos && w[0].Ypos == apple.ypos))
    {
        Worm uwu = w[(int)w.size() - 1];
        if (w[(int)w.size() - 1].direction == 'r')
        {
            uwu.direction = 'r';
            uwu.Xpos--;
        }
        if (w[(int)w.size() - 1].direction == 'l')
        {
            uwu.direction = 'l';
            uwu.Xpos++;
        }
        if (w[(int)w.size() - 1].direction == 'u')
        {
            uwu.direction = 'u';
            uwu.Ypos++;
        }
        if (w[(int)w.size() - 1].direction == 'd')
        {
            uwu.direction = 'd';
            uwu.Ypos--;
        }
        w.push_back(uwu);
        apple.randomize();
        score++;
    }

    // print_field(apple, w);
} // logic
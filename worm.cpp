#include <iostream>
#include <random>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
using namespace std;

// input
// logic
// draw
class Food
{
public:
  int xpos = 0;
  int ypos = 0;
  void randomize();
  bool ate = true;
}; // class food

class Worm
{
private:
  int score = 0;
  int size;
  bool dead = false;
  int Xpos = 1;
  int Ypos = 1;

  vector<int> body_x;
  vector<int> body_y;
  char direction = 'r';

public:
  bool is_dead();
  void print_field();
  void print_body(int x, int y);
  void logic(int input);

}; // class worm


void Food::randomize()
{
  xpos = rand() % 19;
  switch (xpos)
  {
  case 0:
    xpos++;
    break;
  }

  ypos = rand() % 19;
  switch (ypos)
  {
  case 0:
    ypos++;
    break;
  }
} // randomize

bool Worm::is_dead()
{
  return dead;
} // is_dead

void Worm::print_body(int x, int y)
{
  Food apple;
  
  if (Xpos == x && Ypos == y)
  {
    cout << "Q";
  }
  
  if (apple.xpos == x && apple.ypos == y)
  {
    cout << "F";
  }
  else
  {
    cout << " ";
  }
} // print_body

void Worm::print_field()
{
  // system("clear");
  for (int y = 0; y < 20; y++)
  {
    for (int x = 0; x < 20; x++)
    {
      switch (y)
      {
      case 0:
        cout << 'o';
        break;

      case 19:
        cout << 'o';
        break;

      default:
        switch (x)
        {
        case 0:
          cout << 'o';
          break;

        case 19:
          cout << 'o';
          break;
        default:
          print_body(x, y);
          break;
        }
        break;
      }
    }
    cout << endl;
  }
} // print_field

void Worm::logic(int input)
{
  // checking if it touched the boarder
  switch (Xpos)
  {
  case 0:
    dead = true;
    return;
  case 19:
    dead = true;
    return;
  }
  switch (Ypos)
  {
  case 0:
    dead = true;
    return;
  case 19:
    dead = true;
    return;
  }
  // end of checking the boarder

  Food apple;
  if(Xpos == apple.xpos && Ypos == apple.ypos){
    
  }

  switch (input)
  { // checking what was inputed
  case 119:
    direction = 'u';
    break;
  case 87:
    direction = 'u';
    break;
  case 97:
    direction = 'l';
    break;
  case 65:
    direction = 'l';
    break;
  case 115:
    direction = 'd';
    break;
  case 83:
    direction = 'd';
    break;
  case 100:
    direction = 'r';
    break;
  case 68:
    direction = 'r';
    break;
  } // end of checking whatwas inputed

  if (direction == 'r')
  {
    Xpos++;
  }
  if (direction == 'd')
  {
    Ypos++;
  }
  if (direction == 'l')
  {
    Xpos--;
  }
  if (direction == 'u')
  {
    Ypos--;
  }

} // logic

int main()
{
  Worm wiggler;
  Food apple;
  while (!wiggler.is_dead())
  {
    // input
    int input = 0;
    if (_kbhit())
    {
      input = getch();
    }

    // logic
    if (apple.ate == true)
    {
      apple.ate = false;
      apple.randomize();
    }
    // cout << "x position: " << apple.xpos << ", y position: " << apple.ypos << endl;
    system("clear");
    wiggler.logic(input);

    // draw field
    wiggler.print_field(); // prints out board
  }
  system("clear");
  cout << " _____                        _____                \n";
  cout << "|  __ \\                      |  _  |               \n";
  cout << "| |  \\/ __ _ _ __ ___   ___  | | | |_   _____ _ __ \n";
  cout << "| | __ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|\n";
  cout << "| |_\\ \\ (_| | | | | | |  __/ \\ \\_/ /\\ V /  __/ |   \n";
  cout << " \\____/\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|   \n";
}

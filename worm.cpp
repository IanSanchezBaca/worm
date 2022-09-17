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
  // bool ate = true;
}; // class food

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
  void print_field(Food &apple);
  void print_body(int x, int y, Food &apple);
  void logic(int input, Food &apple, vector<Worm> &w);
  int score = 0;

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

void Worm::print_body(int x, int y, Food &apple)
{

  if (Xpos == x && Ypos == y)
  {
    cout << 'Q';
  }
  else if (x == apple.xpos && y == apple.ypos)
  {
    cout << 'F';
  }
  else
  {
    cout << " ";
  }
} // print_body

void Worm::print_field(Food &apple)
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
          print_body(x, y, apple);
          break;
        }
        break;
      }
    }
    cout << endl;
  }
} // print_field

void Worm::logic(int input, Food &apple, vector<Worm> &w)
{
  // fist update the "head" and body
  if(input == 'u'){
    for(int i = 1; i < (int)w.size(); i++){
      w[i] = w[i-1];
    }
    w[0].direction = 'u';
    w[0].Ypos--;
  }
  if(input == 'd'){
    w[0].direction = 'd';
    w[0].Ypos++;
  }
  if(input == 'l'){
    w[0].direction = 'l';
    w[0].Xpos--;
  }
  if(input == 'r'){
    w[0].direction = 'r';
    w[0].Xpos++;
  }
  // check if 
  
} // logic

int main()
{
  Worm w;
  vector<Worm> body;
  body.push_back(w);
  Food apple;
  apple.randomize();
  while (!body[0].is_dead())
  {
    // input

    int input = 0;
    if (_kbhit())
    {
      input = getch();
    }

    // logic

    system("clear");
    w.logic(input, apple, body);

    // draw field

    w.print_field(apple); // prints out board
  }
  system("clear");
  cout << " _____                        _____                \n";
  cout << "|  __ \\                      |  _  |               \n";
  cout << "| |  \\/ __ _ _ __ ___   ___  | | | |_   _____ _ __ \n";
  cout << "| | __ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|\n";
  cout << "| |_\\ \\ (_| | | | | | |  __/ \\ \\_/ /\\ V /  __/ |   \n";
  cout << " \\____/\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|   \n";
  cout << "Final score: " << w.score << endl;
}

#include <iostream>
#include <random>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include "worm.h"
#include "food.h"

using namespace std;

// input
// logic
// draw

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

    // system("clear");
    w.logic(input, apple, body);

    // draw field
    // system("clear");
    w.print_field(apple, body); // prints out board
  }
  system("clear");
  cout << " _____                        _____                \n";
  cout << "|  __ \\                      |  _  |               \n";
  cout << "| |  \\/ __ _ _ __ ___   ___  | | | |_   _____ _ __ \n";
  cout << "| | __ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|\n";
  cout << "| |_\\ \\ (_| | | | | | |  __/ \\ \\_/ /\\ V /  __/ |   \n";
  cout << " \\____/\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|   \n";
  
  if(body[0].crashed_into_wall)
  {
    cout << "You crashed into the wall.\n";
  }
  else if(body[0].crashed_into_body)
  {
    cout << "You crashed into body\n";
  }
  
  cout << "Final score: " << w.score << endl;
}

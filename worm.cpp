#include<iostream>
#include"food.h"
#include"worm.h"

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
  // fist update the "head"
  if (input == 'u')
  {
    w[0].direction = 'u';
    w[0].Ypos--;
  }// end if
  if (input == 'd')
  {
    w[0].direction = 'd';
    w[0].Ypos++;
  }// end if
  if (input == 'l')
  {
    w[0].direction = 'l';
    w[0].Xpos--;
  }// end if
  if (input == 'r')
  {
    w[0].direction = 'r';
    w[0].Xpos++;
  }// end if
  
  // update the body
  for (int i = 1; i < (int)w.size(); i++)
  {
    w[i] = w[i - 1];
  } // end for i

  //check if the head crashes into wall
  if((w[0].Xpos == 0 && w[0].Ypos == 0) || (w[0].Xpos == 20 && w[0].Ypos == 20)){
    w[0].dead = true;
  }
  
  // check if the head crashes into the body
  if((int)w.size() != 1){
    // only happens if it has a body 
    for(int i = 1; i< (int)w.size(); i++){
      if(w[0].Xpos == w[i].Xpos && w[0].Ypos == w[i].Ypos){
        w[0].dead = true;
      }
    }
  }

  // check if head crashes into food


  // print_field(apple, );
} // logic
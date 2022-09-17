#include "food.h"
#include <iostream>
using namespace std;

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



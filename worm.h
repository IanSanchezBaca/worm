
#ifndef worm
#define worm

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

#endif
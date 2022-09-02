#include<iostream>
#include<random>
#include<vector>
#include<stdlib.h>
#include<conio.h>
#include <cstdlib>
using namespace std;

// input 
// logic 
// draw
class Worm{
  private:
    int score = 0;
    int size;
    bool dead = false; 
    int Xpos = 1;
    int Ypos = 1;

    vector<int> body;
    // not sure what im going to do with this vector yet
    char direction = 'r';
  public:
    bool is_dead();
    void print_field();
    void print_body(int x, int y);
    void logic(int input);

}; // class worm
class Food{
  public:
    int xpos = 0;
    int ypos = 0;
    void randomize();
    bool ate = true;
};

void Food::randomize(){
  //xpos = 
}// randomize

bool Worm::is_dead(){
  return dead;
} // is_dead

void Worm::print_body(int x, int y){
  if(Xpos == x && Ypos == y){
    cout << "Q";
  }
  else{
    cout << " ";
  }
}// print_body

void Worm::print_field(){
  system("clear");
  for(int y = 0; y < 20; y++){
    for(int x =0; x < 20; x++){ 
      switch (y) {
        case 0:
          cout << 'o';
          break;

        case 19: 
          cout << 'o';
          break;

        default:
          switch (x) {
            case 0:
              cout << 'o';
              break;

            case 19:
              cout << 'o';
              break;
            default:
              print_body(x, y); 
              //cout << ' '; 
              break;
          }

          break;
      } 
      //if(y == 0 || y == 23 || x == 0 || x == 63){ 
      //cout << "o";
      //}
      //else{
      //print_body(x, y);
      //}
    }
    cout << endl;
  }
} // print_field

void Worm::logic(int input){
  switch(Xpos){
    case 0:
      dead = true;
      return;
    case 19:
      dead = true;
      return;
  }
  switch(Ypos){
    case 0:
      dead = true;
      return;
    case 19:
      dead = true;
      return;
  }
  //if(Xpos == 0 || Xpos == 64 || Ypos == 0 || Ypos == 23){
  //dead = true;
  //return;
  //}
  switch (input) {
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
  }

  if(direction == 'r'){
    Xpos++;
  }
  if(direction == 'd'){
    Ypos++; 
  }
  if(direction == 'l'){
    Xpos--;
  }
  if(direction == 'u'){
    Ypos--;
  }

}//logic


int main(){
  Worm wiggler; 
  Food apple; 
  while(!wiggler.is_dead()){
    //input
    system("clear"); // clears the screen

    int input = 0;

    if(_kbhit()){ input = getch(); }

    //logic
    if(apple.ate == true){
      apple.ate = false; 
      apple.randomize();
    }

    wiggler.logic(input);

    //draw field

    wiggler.print_field(); // prints out board
  }
}


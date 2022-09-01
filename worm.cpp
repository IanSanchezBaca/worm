#include<iostream>
#include<vector>
#include<stdlib.h>
#include<conio.h>
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
  for(int y = 0; y < 24; y++){
    for(int x =0; x < 64; x++){ 
      if(y == 0 || y == 23 || x == 0 || x == 63){ 
        cout << "*";
      }
      else{
        print_body(x, y);
      }
    }
    cout << endl;
  }
} // print_field()

void Worm::logic(int input){

  if(input == 119 || input == 87){ // up
    //cout << 'u' << endl;
  }
  if(input == 97 || input == 65){ // left
    //cout << 'l' << endl;
  }
  if(input == 115 || input == 83){ // down
    //cout << 'd' << endl;
    direction = 'd';

  }
  if(input == 100 || input == 68){ // right
    //cout << 'r' << endl;
  }
  else if(input == 0){
    if(direction == 'd'){

    }
  }
}//logic


int main(){
  Worm wiggler; 
  while(!wiggler.is_dead()){
    system("clear"); // clears the screen
    //input
    
    int input = 0;
    
    if(_kbhit()){
      input = getch();
    }
    


    //logic
    wiggler.logic(input);

    //draw field

    //wiggler.print_field(); // prints out board
  }
}


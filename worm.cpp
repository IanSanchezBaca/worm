#include<iostream>
#include<stdlib.h>
using namespace std;

// input 
// logic 
// draw
class Worm{
  private:
    int size;
    bool dead = false;
    // position x,y

  public:
    bool is_dead();
    void print_field();
    int testing = 10;

}; // class worm

bool Worm::is_dead(){
  return dead;
}


void Worm::print_field(){
  for(int y = 0; y < 24; y++){
    for(int x=0; x < 64; x++){ 
      if(y == 0 || y == 23 || x == 0 || x == 63){ 
        cout << "*";
      }
      else{
        cout << "X";
      }
    }
    cout << endl;
  }
}



int main(){
  Worm wiggler; 
  while(!wiggler.is_dead()){
    system("clear");
    //take the input first

    //logic

    //draw field
    wiggler.print_field();
  }
}


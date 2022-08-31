#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

// input 
// logic 
// draw
class Worm{
  private:
    int size;
    bool dead = false; 
    int Xpos = 1;
    int Ypos = 1;
    vector<int> body;
    // not sure what im going to do with this vector yet

  public:
    bool is_dead();
    void print_field();
    void print_body(int x, int y);

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



int main(){
  Worm wiggler; 
  while(!wiggler.is_dead()){
    system("clear");
    //input

    //logic

    //draw field
    wiggler.print_field();
  }
}


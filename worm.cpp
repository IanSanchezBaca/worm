#include<iostream>
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
  

}; // class worm

bool Worm::is_dead(){
  return dead;
}


void print_field(){

}



int main(){
  Worm wiggler; 
  while(!wiggler.is_dead()){
    cout << "owo" << endl;
  }
}


#include <iostream>
#include "game_player.h"
#include <string>

#define left_num 1
#define right_num 2
#define quickDrop_num 3
#define new_num 4

const std::string left = "a";
const std::string right = "d";
const std::string down = "s";
const std::string New = "n";
const std::string end = "end";

int controller(){
    std::string input;

    std::cin>>input;

    if(input.compare(left) == 0){return left_num;}
    if(input.compare(right) == 0){return right_num;}
    if(input.compare(down) == 0){return quickDrop_num;}
    if(input.compare(New) == 0){return new_num;} 
    if(input.compare(end) == 0){std::exit(1);} 

 return 0 ;
}


void wait(long long frame_interval){
  for(long long time = 0; time < frame_interval; time){
    time++;
   }
}

int main() {
  game game;

  game.load_tetro(game.rand_tetro(), -1);

while(true){
  
  game.load_current_tetro();
  game.print_board();

   short input_num = controller();
    if(input_num == 0){;}
    if(input_num == left_num){game.move_left();}
    if(input_num == right_num){game.move_right();}
    if(input_num == quickDrop_num){game.move_down();}
    if(input_num == new_num){game.load_tetro(game.rand_tetro(),-1);}

    //system("clear");
  }
 
}
  


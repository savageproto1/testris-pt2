#include <iostream>
#include "game_player.h"


int main() {
  game game;
 
  
  game.load_tetro(4, -1);
  game.load_current_tetro();

 
for(int frame = 0; frame < 60;frame++){
   std::system("clear");
  
   game.print_board();
   //std::cin.ignore();
   
 }


}
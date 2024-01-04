
class GameBoard{
  public:
    bool game_board[10][20];

    GameBoard(){
      for(int  game_boardY = 0; game_boardY < 20; game_boardY++){
        for(int game_boardX = 0; game_boardX < 10; game_boardX++){
          game_board[game_boardX][game_boardY] = 0;
        }
      }
  }

  void save_tetro(){
    
  }
};
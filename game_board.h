
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

  void save_tetro(int x, int y, bool tetro00,bool tetro01,bool tetro10,bool tetro11,bool tetro20, bool tetro21,bool tetro30,bool tetro31){
    bool temp_tetro_register[4][2]{
        {tetro00,tetro01},
        {tetro10,tetro11},
        {tetro20,tetro21},
        {tetro30,tetro31}};

        game_board[x][y] = temp_tetro_register[0][0];
        game_board[x + 1][y] = temp_tetro_register[0][1];
        game_board[x][y + 1] = temp_tetro_register[1][0];
        game_board[x + 1][y + 1] = temp_tetro_register[1][1];
        game_board[x][y + 2] = temp_tetro_register[2][0];
        game_board[x + 1][y + 2] = temp_tetro_register[2][1];
        game_board[x][y + 3] = temp_tetro_register[3][0];
        game_board[x + 1][y + 3] = temp_tetro_register[3][1];
  }
};
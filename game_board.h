#include <iostream>

class GameBoard
{
public:
  bool game_board[10][20];

  GameBoard()
  {
    for (int game_boardY = 0; game_boardY < 20; game_boardY++)
    {
      for (int game_boardX = 0; game_boardX < 10; game_boardX++)
      {
        game_board[game_boardX][game_boardY] = 0;
      }
    }
  }
  void print_gameBoard()
  {
    for (int game_boardY = 0; game_boardY < 20; game_boardY++)
    {
      for (int game_boardX = 0; game_boardX < 10; game_boardX++)
      {
        std::cout << game_board[game_boardX][game_boardY];
      }
      std::cout << "\n";
    }
  }
  void save_tetro(int x, int y, bool tetro00, bool tetro01, bool tetro10, bool tetro11, bool tetro20, bool tetro21, bool tetro30, bool tetro31)
  {

    if (game_board[x][y] != 1){game_board[x][y] = tetro00;}
    if (game_board[x + 1][y] != 1){game_board[x + 1][y] = tetro01;}
    if (game_board[x][y + 1] != 1){game_board[x][y + 1] = tetro10;}
    if (game_board[x + 1][y + 1] != 1){game_board[x + 1][y + 1] = tetro11;}
    if (game_board[x][y + 2] != 1){game_board[x][y + 2] = tetro20;}
    if (game_board[x + 1][y + 2] != 1){game_board[x + 1][y + 2] = tetro21;}
    if (game_board[x][y + 3] != 1){game_board[x][y + 3] = tetro30;}
    if (game_board[x + 1][y + 3] != 1){game_board[x + 1][y + 3] = tetro31;}
  }
  int hit_detect(int x, int y, bool tetro00, bool tetro01, bool tetro10, bool tetro11, bool tetro20, bool tetro21, bool tetro30, bool tetro31)
  {
    int hit_reg = 0;
    if (tetro00 == 1 && game_board[x][y] == 1){hit_reg++;}
    if (tetro01 == 1 && game_board[x + 1][y] == 1){hit_reg++;}
    if (tetro10 == 1 && game_board[x][y + 1] == 1){hit_reg++;}
    if (tetro11 == 1 && game_board[x + 1][y + 1] == 1){hit_reg++;}
    if (tetro20 == 1 && game_board[x][y + 2] == 1){hit_reg++;}
    if (tetro21 == 1 && game_board[x + 1][y + 2] == 1){hit_reg++;}
    if (tetro30 == 1 && game_board[x][y + 3] == 1){hit_reg++;}
    if (tetro31 == 1 && game_board[x + 1][y + 3] == 1){hit_reg++;}
    return hit_reg;
    std::cout << "\nhit_reg - " << hit_reg << "\n";
  }
  
};
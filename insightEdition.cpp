#include <iostream>

#define pice_vert_size 3
#define pice_horzt_size 2

#define l_num 0
bool char_l[4][2] = {{0, 0}, {1, 0}, {1, 0}, {1, 1}};


#define squigle_num 1
bool char_squigle[4][2] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};


#define square_num 2
bool char_square[4][2] = {{0, 0}, {1, 1}, {1, 1}, {0, 0}};


#define line_num 3
bool char_line[4][2] = {{1, 0}, {1, 0}, {1, 0}, {1, 0}};


#define t_num  4
bool char_t[4][2] = {{0, 0}, {1, 0}, {1, 1}, {1, 0}};


class GameBoard
{
  
  public: 
  bool game_board[10][20];
  inline GameBoard()
  {
    for(int game_boardY = 0; game_boardY < 20; game_boardY++) {
      for(int game_boardX = 0; game_boardX < 10; game_boardX++) {
        this->game_board[game_boardX][game_boardY] = 0;
      }
      
    }
    
  }
  
  inline void save_tetro()
  {
  }
  
};



class game
{
  
  private: 
  bool tetro_register[4][2];
  
  private: 
  int current_x;
  int current_y;
  
  public: 
  int board[10][20];
  GameBoard game_board;
  inline game()
  : tetro_register{{0, 0}, {0, 0}, {0, 0}, {0, 0}}
  , current_x{4}
  , current_y{1}
  , game_board{GameBoard()}
  {
    for(int boardY = 0; boardY < 20; boardY++) {
      for(int boardX = 0; boardX < 10; boardX++) {
        this->board[boardX][boardY] = 0;
      }
      
    }
    
  }
  
  
  public: 
  inline int load_tetro(int tetro, bool test)
  {
    switch(tetro) {
      case 0: for(int vert = 0; vert < 4; vert++) {
        for(int hortz = 0; hortz < 2; hortz++) {
          this->tetro_register[vert][hortz] = char_l[vert][hortz];
        }
        
      }
      
      ;
      break;
      case 1: for(int vert = 0; vert < 4; vert++) {
        for(int hortz = 0; hortz < 2; hortz++) {
          this->tetro_register[vert][hortz] = char_squigle[vert][hortz];
        }
        
      }
      
      ;
      break;
      case 2: for(int vert = 0; vert < 4; vert++) {
        for(int hortz = 0; hortz < 2; hortz++) {
          this->tetro_register[vert][hortz] = char_square[vert][hortz];
        }
        
      }
      
      ;
      break;
      case 3: for(int vert = 0; vert < 4; vert++) {
        for(int hortz = 0; hortz < 2; hortz++) {
          this->tetro_register[vert][hortz] = char_line[vert][hortz];
        }
        
      }
      
      ;
      break;
      case 4: for(int vert = 0; vert < 4; vert++) {
        for(int hortz = 0; hortz < 2; hortz++) {
          this->tetro_register[vert][hortz] = char_t[vert][hortz];
        }
        
      }
      
      ;
      break;
      default: std::operator<<(std::operator<<(std::cout, "unknown tetrominoe - ").operator<<(tetro), "\n");
      return 0;
    }
    if(static_cast<int>(test) == 0) {
      for(int vert1 = 0; vert1 < 4; vert1++) {
        for(int hortz1 = 0; hortz1 < 2; hortz1++) {
          std::cout.operator<<(this->tetro_register[vert1][hortz1]);
        }
        
        std::operator<<(std::cout, "\n");
      }
      
    } 
    
    return 0;
  }
  
  inline void load_current_tetro()
  {
    this->board[this->current_x][this->current_y] = static_cast<int>(this->tetro_register[0][0]);
    this->board[this->current_x + 1][this->current_y] = static_cast<int>(this->tetro_register[0][1]);
    this->board[this->current_x][this->current_y + 1] = static_cast<int>(this->tetro_register[1][0]);
    this->board[this->current_x + 1][this->current_y + 1] = static_cast<int>(this->tetro_register[1][1]);
    this->board[this->current_x][this->current_y + 2] = static_cast<int>(this->tetro_register[2][0]);
    this->board[this->current_x + 1][this->current_y + 2] = static_cast<int>(this->tetro_register[2][1]);
    this->board[this->current_x][this->current_y + 3] = static_cast<int>(this->tetro_register[3][0]);
    this->board[this->current_x + 1][this->current_y + 3] = static_cast<int>(this->tetro_register[3][1]);
  }
  
  inline void print_board()
  {
    for(int y = 0; y < 20; y++) {
      for(int x = 0; x < 10; x++) {
        if(this->board[x][y] == 1) {
          std::operator<<(std::cout, "*");
        } else {
          (std::operator<<(std::cout, " "));
        } 
        
      }
      
      std::operator<<(std::cout, "\n");
    }
    
  }
  
  inline void clear_current()
  {
    this->board[this->current_x][this->current_y - 1] = 0;
    this->board[this->current_x + 1][this->current_y - 1] = 0;
    this->board[this->current_x][this->current_y] = 0;
    this->board[this->current_x + 1][this->current_y] = 0;
    this->board[this->current_x][this->current_y + 1] = 0;
    this->board[this->current_x + 1][this->current_y + 1] = 0;
    this->board[this->current_x][this->current_y + 2] = 0;
    this->board[this->current_x + 1][this->current_y + 2] = 0;
  }
  
  inline int hit_bottom()
  {
    this->game_board.save_tetro();
  }
  
  inline void move_down()
  {
    if(((this->current_y + 4) + 1) > 20) {
      this->hit_bottom();
    } else {
      (this->current_y++);
    } 
    
    this->clear_current();
    this->load_current_tetro();
  }
  
  inline void move_left()
  {
    this->clear_current();
    if((this->current_x - 1) > -1) {
      this->current_x--;
    } 
    
    this->load_current_tetro();
  }
  
  inline void move_right()
  {
    this->clear_current();
    if((this->current_x + 1) < 10) {
      this->current_x++;
    } 
    
    this->load_current_tetro();
  }
  
};



int main()
{
  game game;
  game.load_tetro(4, static_cast<bool>(-1));
  game.load_current_tetro();
  for(int frame = 0; frame < 60; frame++) {
    system("clear");
    game.print_board();
  }
  
  return 0;
}

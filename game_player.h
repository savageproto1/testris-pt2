#include "game_board.h"
#include <iostream>
#include "tetrominoes.h"

class game
{
GameBoard gameboard;
private:
    bool tetro_register[4][2] = {
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0}};

    int current_x = 4;
    int current_y = 15;

public:
    int board[10][20];

    game()
    {
        for (int boardY = 0; boardY < 20; boardY++)
        {
            for (int boardX = 0; boardX < 10; boardX++)
            {
                board[boardX][boardY] = 0;
            }
        }
    }
    int rand_tetro(){return rand()%(0-4 + 1) + 0;}

    int load_tetro(int tetro, bool test)
    {

        switch (tetro)
        {
        case l_num:
            for (int vert = 0; vert < 4; vert++)
            {
                for (int hortz = 0; hortz < 2; hortz++)
                {
                    tetro_register[vert][hortz] = char_l[vert][hortz];
                }
            }
            break;

        case squigle_num:
            for (int vert = 0; vert < 4; vert++)
            {
                for (int hortz = 0; hortz < 2; hortz++)
                {
                    tetro_register[vert][hortz] = char_squigle[vert][hortz];
                }
            }
            break;

        case square_num:
            for (int vert = 0; vert < 4; vert++)
            {
                for (int hortz = 0; hortz < 2; hortz++)
                {
                    tetro_register[vert][hortz] = char_square[vert][hortz];
                }
            }
            break;

        case line_num:
            for (int vert = 0; vert < 4; vert++)
            {
                for (int hortz = 0; hortz < 2; hortz++)
                {
                    tetro_register[vert][hortz] = char_line[vert][hortz];
                }
            }
            break;

        case t_num:
            for (int vert = 0; vert < 4; vert++)
            {
                for (int hortz = 0; hortz < 2; hortz++)
                {
                    tetro_register[vert][hortz] = char_t[vert][hortz];
                }
            }
            break;

        default:
            std::cout << "unknown tetrominoe - " << tetro << "\n";
            return 0;
        }
        if (test == 0)
        {
            for (int vert1 = 0; vert1 < 4; vert1++)
            {
                for (int hortz1 = 0; hortz1 < 2; hortz1++)
                {
                    std::cout << tetro_register[vert1][hortz1];
                }
                std::cout << "\n";
            }
        }
        return 0;
    }

    void load_current_tetro()
    {
        board[current_x][current_y] = tetro_register[0][0];
        board[current_x + 1][current_y] = tetro_register[0][1];
        board[current_x][current_y + 1] = tetro_register[1][0];
        board[current_x + 1][current_y + 1] = tetro_register[1][1];
        board[current_x][current_y + 2] = tetro_register[2][0];
        board[current_x + 1][current_y + 2] = tetro_register[2][1];
        board[current_x][current_y + 3] = tetro_register[3][0];
        board[current_x + 1][current_y + 3] = tetro_register[3][1];
    }

    void print_board()
    {
        std::cout<<"------------\n";

        for (int y = 0; y < 20; y++)
        {
            std::cout<<"|";
            for (int x = 0; x < 10; x++)
            {
                if (board[x][y] == 1)
                {
                    std::cout << "*";
                }
                else
                    (std::cout << " ");
            }
            std::cout << "|\n";
        }

        std::cout<<"------------\n";
        
    }
    void clear_current()
    {
        for (int boardY = 0; boardY < 20; boardY++)
        {
            for (int boardX = 0; boardX < 10; boardX++)
            {
                board[boardX][boardY] = 0;
            }
        }
       /* board[current_x][current_y - 1] = 0;
        board[current_x + 1][current_y - 1] = 0;
        board[current_x][current_y] = 0;
        board[current_x + 1][current_y] = 0;
        board[current_x][current_y + 1] = 0;
        board[current_x + 1][current_y + 1] = 0;
        board[current_x][current_y + 2] = 0;
        board[current_x + 1][current_y + 2] = 0;*/
    }
    void hit_bottom()
    {
        gameboard.save_tetro(current_x,current_y,tetro_register[0][0],tetro_register[0][1],tetro_register[1][0],tetro_register[1][1],tetro_register[2][0],tetro_register[2][1],tetro_register[3][0],tetro_register[3][1]);
        clear_current();
        current_x=4;
        current_y=0;
        load_tetro(rand_tetro(),-1);
        load_current_tetro();
    }
    void move_down()
    {
        if ((current_y + 4) + 1 > 20)
        {
            hit_bottom();
        }
        else
            (current_y++);
        clear_current();
        load_current_tetro();
    }
    void move_left()
    {
        clear_current();

        if (current_x - 1 > -1)
        {
            current_x--;
        }

        load_current_tetro();
    }
    void move_right()
    {
        clear_current();

        if (current_x + 1 < 9)
        {
            current_x++;
        }

        load_current_tetro();
    }
};

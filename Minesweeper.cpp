#include "Minesweeper.h"

Minesweeper::Minesweeper()
{
    int val = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            board[i][j].setKeyVal(val + 1);
            val = (val + 1) % 9;
        }
        i % 3 == 2 ? val += 4 : val += 3;
        val %= 9;
    }
}

void Minesweeper::startGame()
{
    randomizeBoard();
}

void Minesweeper::randomizeBoard()
{
    srand(time(0));
    Cell temp[9];
    int r;
    for(int i = 0; i < 100; i++)
    {
        r = rand() % 3;
        for(int l = rand() % 3; l > 0; l--)
        {
            for(int j = 0; j < 9; j++)
            {
                temp[j] = board[3*r][j];
                board[3*r][j] = board[3*r + 1][j];
                board[3*r + 1][j] = board[3*r + 2][j];
                board[3*r + 2][j] = temp[j];
            }
        }

        for(int l = rand() % 3; l > 0; l--)
        {
            for(int j = 0; j < 9; j++)
            {
                temp[j] = board[j][3*r];
                board[j][3*r] = board[j][3*r + 1];
                board[j][3*r + 1] = board[j][3*r + 2];
                board[j][3*r + 2] = temp[j];
            }
        }
    }
}

int Minesweeper::getCellKeyValue(int row, int col)
{
    return board[row][col].getKeyVal();
}

int Minesweeper::getCellBoardValue(int row, int col)
{
    return board[row][col].getBoardVal();
}

Cell* Minesweeper::getCell(int row, int col)
{
    return &board[row][col];
}



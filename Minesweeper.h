#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <ctime>
#include "Cell.h"

using std::size_t;

class Minesweeper
{
    private:
        Cell board[9][9];
        Cell* rows[9][9];
        Cell* cols[9][9];
        Cell* scls[9][9];
        void randomizeBoard();

    public:
        Minesweeper();
        void startGame();
        int getCellKeyValue(int row, int col);
        int getCellBoardValue(int row, int col);
        bool isWinner();
        Cell* getCell(int row, int col);
};

#endif
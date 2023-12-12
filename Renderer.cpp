#define color_black     0x000000
#define color_white     0xffffff
#define color_gray      0x0e0e0e
#define color_red       0xff0000
#define color_orange    0xf58231
#define color_yellow    0xffe119
#define color_lime      0xbfef45
#define color_green     0x3cb44b
#define color_cyan      0x42d4f4
#define color_blue      0x4363d8
#define color_purple    0x911eb4
#define color_pink      0xf032e6

#define boardSize           min(gameState.height, gameState.width)
#define thickLineWidth      0.03 * boardSize
#define thinLineWidth       0.01 * boardSize
#define squareSize          (int)((boardSize - (3 * thickLineWidth) - (9 * thinLineWidth)) / 9)
#define cellContentsBorder  0.1 * squareSize

#include "Cell.h"

void clear_screen(size_t color)
{
    size_t* currPixel = (size_t*)gameState.memory;
    for(int y = 0; y < gameState.height; y++)
    {
        for(int x = 0; x < gameState.width; x++)
        {
            *currPixel++ = color;
        }
    }
}

void drawRectangle(int x0, int y0, int x1, int y1, int color)
{
    x0 = clamp(0, x0, gameState.width);
    y0 = clamp(0, y0, gameState.height);
    x1 = clamp(0, x1, gameState.width);
    y1 = clamp(0, y1, gameState.height);

    size_t* currPixel;
    for(int y = gameState.height - y1; y < gameState.height - y0; y++)
    {
        currPixel = (size_t*)gameState.memory + x0 + y*gameState.width;
        for(int x = x0; x < x1; x++)
        {
            *currPixel++ = color;
        }
    }
}

void drawNumber(int num, int x0, int y0, int x1, int y1, int color)
{
    int xDiff = (x0 - x1);
    int yDiff = (x0 - x1);
    switch(num)
    {
        case 1:
            drawRectangle(x0, y0, x0 - (int)(3*xDiff/5), y0 - (int)(yDiff/5), color);
            drawRectangle(x0 - (int)(2*xDiff/5), y0, x0 - (int)(3*xDiff/5), y1, color);
            drawRectangle(x0, y0 - (int)(4*yDiff/5), x1 , y1, color);
            break;
        case 2:
            drawRectangle(x0, y0, x1, y0 - (int)(yDiff/5), color);
            drawRectangle(x0, y0 - (int)(2*yDiff/5), x1, y0 - (int)(3*yDiff/5), color);
            drawRectangle(x0, y0 - (int)(4*yDiff/5), x1, y1, color);
            drawRectangle(x0 - (int)(4*xDiff/5), y0, x1, y0 - (int)(yDiff/2), color);
            drawRectangle(x0, y0 - (int)(yDiff/2), x0 - (int)(xDiff/5), y1, color);
            break;
        case 3:
            drawRectangle(x0, y0, x1, y0 - (int)(yDiff/5), color);
            drawRectangle(x0, y0 - (int)(2*yDiff/5), x1, y0 - (int)(3*yDiff/5), color);
            drawRectangle(x0, y0 - (int)(4*yDiff/5), x1, y1, color);
            drawRectangle(x0 - (int)(4*xDiff/5), y0, x1, y1, color);
            break;
        case 4:
            drawRectangle(x0, y0 - (int)(2*yDiff/5), x1, y0 - (int)(3*yDiff/5), color);
            drawRectangle(x0 - (int)(4*xDiff/5), y0, x1, y1, color);
            drawRectangle(x0, y0, x0 - (int)(xDiff/5), y0 - (int)(yDiff/2), color);
            break;
        case 5:
            drawRectangle(x0, y0, x1, y0 - (int)(yDiff/5), color);
            drawRectangle(x0, y0 - (int)(2*yDiff/5), x1, y0 - (int)(3*yDiff/5), color);
            drawRectangle(x0, y0 - (int)(4*yDiff/5), x1, y1, color);
            drawRectangle(x0 - (int)(4*xDiff/5), y0  - (int)(yDiff/2), x1, y1, color);
            drawRectangle(x0, y0, x0 - (int)(xDiff/5), y0  - (int)(yDiff/2), color);
            break;
        case 6:
            drawRectangle(x0, y0, x1, y0 - (int)(yDiff/5), color);
            drawRectangle(x0, y0 - (int)(2*yDiff/5), x1, y0 - (int)(3*yDiff/5), color);
            drawRectangle(x0, y0 - (int)(4*yDiff/5), x1, y1, color);
            drawRectangle(x0 - (int)(4*xDiff/5), y0  - (int)(yDiff/2), x1, y1, color);
            drawRectangle(x0, y0, x0 - (int)(xDiff/5), y1, color);
            break;
        case 7:
            drawRectangle(x0, y0, x1, y0 - (int)(yDiff/5), color);
            drawRectangle(x0 - (int)(4*xDiff/5), y0, x1, y1, color);
            break;
        case 8:
            drawRectangle(x0, y0, x1, y0 - (int)(yDiff/5), color);
            drawRectangle(x0, y0 - (int)(2*yDiff/5), x1, y0 - (int)(3*yDiff/5), color);
            drawRectangle(x0, y0 - (int)(4*yDiff/5), x1, y1, color);
            drawRectangle(x0 - (int)(4*xDiff/5), y0, x1, y1, color);
            drawRectangle(x0, y0, x0 - (int)(xDiff/5), y1, color);
            break;
        case 9:
            drawRectangle(x0, y0, x1, y0 - (int)(yDiff/5), color);
            drawRectangle(x0, y0 - (int)(2*yDiff/5), x1, y0 - (int)(3*yDiff/5), color);
            drawRectangle(x0, y0 - (int)(4*yDiff/5), x1, y1, color);
            drawRectangle(x0 - (int)(4*xDiff/5), y0, x1, y1, color);
            drawRectangle(x0, y0, x0 - (int)(xDiff/5), y0 - (int)(yDiff/2), color);
            break;
    }
}

void drawSquares()
{
    int x = thickLineWidth, y = thickLineWidth;
    Cell* currCell;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            currCell = gameState.minesweeperGame.getCell(i, j);

            drawRectangle(x, y, x + squareSize, y + squareSize, color_white);
            if(currCell->isCorrectValue())
                drawNumber(currCell->getBoardVal(), x + cellContentsBorder, y + cellContentsBorder, x + squareSize - cellContentsBorder, y + squareSize - cellContentsBorder, color_blue);
            else
                drawNumber(currCell->getBoardVal(), x + cellContentsBorder, y + cellContentsBorder, x + squareSize - cellContentsBorder, y + squareSize - cellContentsBorder, color_red);
                    
            x += squareSize;
            if(j % 3 == 2)
                x += thickLineWidth;
            else
                x += thinLineWidth;
        }

        x = thickLineWidth;
        y += squareSize;
        i % 3 == 2 ? y += thickLineWidth : y += thinLineWidth;
    }
}

void drawGameBoard()
{
    drawRectangle(0, 0, 9*squareSize + 6*thinLineWidth + 4*thickLineWidth, 9*squareSize + 6*thinLineWidth + 4*thickLineWidth, color_black);
    drawSquares();
}
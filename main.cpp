#include <windows.h>
#include "utilities.cpp"
#include "Minesweeper.h"
#include <iostream>

struct GameState
{
    bool running;
    int height, width, size;
    int xPos, yPos;
    void* memory;
    BITMAPINFO bitmap_info;
    Minesweeper minesweeperGame = Minesweeper();
};
GameState gameState;

#include "renderer.cpp"

void resizeWindow(HWND hWindowHandle)
{
    RECT rect;
    GetClientRect(hWindowHandle, &rect);
    gameState.width = rect.right - rect.left;
    gameState.height = rect.bottom - rect.top;
    gameState.size = gameState.width * gameState.height * sizeof(size_t);

    if(gameState.memory)
        VirtualFree(gameState.memory, 0, MEM_RELEASE);
        gameState.memory = VirtualAlloc(0, gameState.size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
            
    gameState.bitmap_info.bmiHeader.biSize = sizeof(gameState.bitmap_info.bmiHeader);
    gameState.bitmap_info.bmiHeader.biWidth = gameState.width;
    gameState.bitmap_info.bmiHeader.biHeight = gameState.height;
    gameState.bitmap_info.bmiHeader.biPlanes = 1;
    gameState.bitmap_info.bmiHeader.biBitCount = 32;
    gameState.bitmap_info.bmiHeader.biCompression = BI_RGB;
}

std::vector<int> getCellUnderMouse() 
{
    std::vector<int> cellID = {-1, -1};
    int x = gameState.xPos, y = gameState.yPos, i;
    x -= thickLineWidth, y-= thickLineWidth;
    for(i = 0; i < 9; i++)
    {   
        if(x < i * (squareSize + thinLineWidth) + (i / 3)*(thickLineWidth - thinLineWidth) + squareSize)
        {
            if(x > i * (squareSize + thinLineWidth) + (i / 3)*(thickLineWidth - thinLineWidth))
                cellID.at(0) = i;
        }
    }
    for(i = 0; i < 9; i++)
    {   
        if(y < i * (squareSize + thinLineWidth) + (i / 3)*(thickLineWidth - thinLineWidth) + squareSize)
        {
            if(y > i * (squareSize + thinLineWidth) + (i / 3)*(thickLineWidth - thinLineWidth))
                cellID.at(1) = i;
        }
    }
    return cellID;
}

LRESULT CALLBACK MinesweeperGameProcedure(HWND hWindowHandle, UINT Message, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;
    switch(Message)
    {
        case WM_CREATE:
        {
            gameState.minesweeperGame.startGame();
            break;
        }

        case WM_MOUSEMOVE:
        {
            gameState.xPos = (int)(short)HIWORD(lParam);
            gameState.yPos = (int)(short)LOWORD(lParam);
            break;
        }

        case WM_KEYDOWN:
        {
            std::vector<int> cellID = getCellUnderMouse();
            if(cellID.at(0) == -1 || cellID.at(1) == -1)
                break;
            Cell* selectedCell = gameState.minesweeperGame.getCell(cellID.at(0), cellID.at(1));
            if(wParam - 48 >= 0 && wParam - 48 < 10)
                selectedCell->setBoardVal(wParam - 48);
            break;
        }

        case WM_SIZE:
        {
            resizeWindow(hWindowHandle);
            break;
        }

        case WM_DESTROY:
        {
            gameState.running = false;
            PostQuitMessage(0);
            break;
        }

        default:
            result = DefWindowProcW(hWindowHandle, Message, wParam, lParam);
    }
    return result;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR args, int ncmdshow)
{
    WNDCLASSW SudokuGameWindow = {};
    SudokuGameWindow.style = CS_HREDRAW | CS_VREDRAW;
    SudokuGameWindow.lpszClassName = L"Sudoku Game";
    SudokuGameWindow.lpfnWndProc = MinesweeperGameProcedure;

    RegisterClassW(&SudokuGameWindow);

    HWND gameWindow = CreateWindowW(SudokuGameWindow.lpszClassName, L"Sudoku",
                                    WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT,
                                    CW_USEDEFAULT, 500, 523,
                                    0, 0, hInstance, 0);
    HDC hdc = GetDC(gameWindow);
    
    gameState.running = true;

    MSG message;
    while(gameState.running)
    {
        //  Input
        while(PeekMessage(&message, gameWindow, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        //  Simulate
        clear_screen(color_white);
        drawGameBoard();

        //  Render
        StretchDIBits(hdc, 0, 0, gameState.width, gameState.height,
                      0, 0, gameState.width, gameState.height, gameState.memory,
                      &gameState.bitmap_info, DIB_RGB_COLORS, SRCCOPY);
    }
    return 0;
}
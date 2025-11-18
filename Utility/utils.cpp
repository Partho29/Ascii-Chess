/**
 * @file utils.cpp
 * @brief Implementation of utility functions used throughout the chess project.
 */

#include "utils.h"
#include <Piece.h>
#include <Cell.h>

#ifdef _WIN32
#include <windows.h>
#endif

namespace myutils {

    // ---------------------------------------------------------------------
    //  Global Style Variables (defined here, declared in utils.h)
    // ---------------------------------------------------------------------

    string BG_COLOR       = "\033[40m";   // Default black background
    string TXT_COLOR      = "\033[97m";   // Default white foreground
    string CELL_STYLE     = "::";         // Default ASCII cell border
    bool   CAN_CHANGE_COLOR = true;       // Disabled if VT mode is not supported


    // ---------------------------------------------------------------------
    //  Console / System Functions
    // ---------------------------------------------------------------------

    bool enableVTMode() {
    #ifdef _WIN32
        // Enable ANSI escape sequence support for Windows 10+
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut == INVALID_HANDLE_VALUE)
            return false;

        DWORD dwMode = 0;
        if (!GetConsoleMode(hOut, &dwMode))
            return false;

        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        if (!SetConsoleMode(hOut, dwMode))
            return false;

        return true;
    #else
        // Linux/macOS always support ANSI by default
        return true;
    #endif
    }


    COORD getCursorPosition() {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        return csbi.dwCursorPosition;
    }


    void setCursorPosition(int x, int y) {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }


    // ---------------------------------------------------------------------
    //  Chess Logic Helper Functions
    // ---------------------------------------------------------------------

    bool isInsideGrid(int& row, int& col) {
        return (row >= 0 && row <= 7 && col >= 0 && col <= 7);
    }


    bool isValidForKing(int& row, int& col, Piece* arrayToSearch[]) {
        // Out of bounds → invalid
        if (row < 0 || row > 7 || col < 0 || col > 7)
            return false;

        // Check all enemy pieces to see if any threaten the square
        for (int i = 0; i < 16; i++) {
            // Skip captured pieces (they have row < 0 or col < 0)
            if (arrayToSearch[i]->row < 0 || arrayToSearch[i]->col < 0)
                continue;

            // If an enemy piece can move into this square, king cannot move here
            if (arrayToSearch[i]->validMoveCells[row][col])
                return false;
        }

        return true;
    }


    bool isValidToMove(int& row, int& col, char enemy, Cell cells[][8]) {
        // Outside the board
        if (!myutils::isInsideGrid(row, col))
            return false;

        // Empty square → valid
        if (!cells[row][col].piece)
            return true;

        // Occupied by enemy piece → valid
        if (cells[row][col].piece->id[0] == enemy)
            return true;

        // Occupied by same-color piece → invalid
        return false;
    }

} // namespace myutils

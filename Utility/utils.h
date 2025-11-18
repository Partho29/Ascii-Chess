#ifndef UTILS_H
#define UTILS_H

/**
 * @file utils.h
 * @brief Contains utility functions, shared game settings, and basic helper structs.
 *
 * This module defines:
 *  - ANSI color / styling globals
 *  - Position structure (Pos)
 *  - Move information structure (MoveInfo)
 *  - Cursor and VT mode functions
 *  - Validation utilities used across the project
 */

#include <string>
using std::string;

#ifdef _WIN32
#include <windows.h>   // Needed for COORD, SetConsoleCursorPosition, etc.
#endif

// Forward declarations — prevents circular dependencies between headers.
struct Cell;
struct Piece;

namespace myutils {

    /**
     * @brief Simple coordinate structure for cursor/game positions.
     */
    struct Pos {
        int x;
        int y;

        Pos() : x(-1), y(-1) {}
        Pos(int a, int b) : x(a), y(b) {}
    };

    /**
     * @brief Stores complete information about a move for undo/AI evaluation.
     */
    struct MoveInfo {
        Piece* piece;               ///< The piece that moved.
        int fromRow, fromCol;       ///< Original position.
        int toRow, toCol;           ///< New position.
        Piece* capturedPiece;       ///< nullptr if no capture happened.

        bool wasCastle;             ///< True if the move was a castling move.
        bool wasEnPassant;          ///< True if en-passant capture occurred.
        bool wasPawnPromotion;      ///< True if pawn promotion happened.
        char promotedTo;            ///< Which piece the pawn promoted to.

        string originalPieceId;     ///< Original ID before modifications (promotion, flags, etc.)
    };

} // namespace myutils



namespace myutils {

    // ---------------------------------------------------------------------
    //  Global Style Variables (extern — defined in utils.cpp)
    // ---------------------------------------------------------------------
    extern string BG_COLOR;         ///< Background color (ANSI escape code).
    extern string TXT_COLOR;        ///< Text color (ANSI escape code).
    extern string CELL_STYLE;       ///< Board cell formatting string.
    extern bool CAN_CHANGE_COLOR;   ///< False when terminal cannot use ANSI escape codes.


    // ---------------------------------------------------------------------
    //  System / Console Utility Functions
    // ---------------------------------------------------------------------

    /**
     * @brief Enables VT processing on Windows to allow ANSI escape colors.
     * @return true if enabled successfully, false otherwise.
     */
    bool enableVTMode();

    /**
     * @brief Gets current cursor position in the console.
     * @return COORD with x,y coordinates.
     */
    COORD getCursorPosition();

    /**
     * @brief Moves the console cursor to a given screen location.
     */
    void setCursorPosition(int x, int y);


    // ---------------------------------------------------------------------
    //  Chess Logic Helper Functions
    // ---------------------------------------------------------------------

    /**
     * @brief Checks whether a given row/column is within the chessboard grid.
     */
    bool isInsideGrid(int& row, int& col);

    /**
     * @brief Validates whether a king can move to a square (not in check).
     */
    bool isValidForKing(int& row, int& col, Piece* arrayToSearch[]);

    /**
     * @brief Checks whether a piece may legally move to a square, considering enemy color.
     */
    bool isValidToMove(int& row, int& col, char enemy, Cell cells[][8]);

} // namespace myutils

#endif // UTILS_H

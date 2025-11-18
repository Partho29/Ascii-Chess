#ifndef CELL_H
#define CELL_H

/**
 * Forward declaration to avoid circular dependencies.
 * The full definition of Piece is in Piece.h
 */
struct Piece;

/**
 * @struct Cell
 * @brief Represents a single square on the chessboard.
 *
 * Stores:
 *  - Screen coordinates (x, y) for console rendering
 *  - Board coordinates (row, col)
 *  - Pointer to the piece that currently occupies this cell
 */
struct Cell {
    int x;       ///< Console X-coordinate for rendering
    int y;       ///< Console Y-coordinate for rendering
    int row;     ///< Row index on the board (0–7)
    int col;     ///< Column index on the board (0–7)
    Piece* piece; ///< Pointer to the piece occupying this cell (nullptr if empty)

    /// Default constructor (creates an invalid/uninitialized cell)
    Cell() : x(-1), y(-1), row(-1), col(-1), piece(nullptr) {}

    /// Copy constructor
    Cell(Cell& p) : x(p.x), y(p.y), row(p.row), col(p.col), piece(p.piece) {}
};

#endif

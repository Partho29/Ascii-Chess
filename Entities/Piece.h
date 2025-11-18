#ifndef PIECE_H
#define PIECE_H

#include <utils.h>
#include <Cell.h>

/**
 * @struct Piece
 * @brief Represents a chess piece with position, identity, movement rules,
 *        and metadata used throughout the game.
 *
 * Contains:
 *  - Board coordinates (row, col)
 *  - Screen-render coordinates (pos.x, pos.y)
 *  - String identifier (id)
 *  - Weight used in AI evaluation
 *  - Valid move matrix for all board squares
 */
struct Piece {

    myutils::Pos pos;          ///< Console position (x, y)
    int row;                   ///< Current board row (0–7)
    int col;                   ///< Current board column (0–7)
    string id;                 ///< ID like "WP1", "BKc", "WQ", etc.
    int weight;                ///< Material weight value used by AI
    bool validMoveCells[8][8]; ///< Matrix marking squares where the piece can legally move
    int numOfValidMoves;       ///< Count of currently valid moves

    /**
     * @enum PieceID
     * @brief Enum representation of the piece type for quick comparisons.
     */
    enum PieceID {
        WP, WR, WN, WB, WK, WQ,
        BP, BR, BN, BB, BK, BQ,
        UNKNOWN
    };

    /**
     * @brief Constructor initializes a piece's identity and positions.
     * @param s  String ID (ex: "WP1", "BR2c", "WKc")
     * @param x  Console X-coordinate
     * @param y  Console Y-coordinate
     * @param r  Board row (0–7)
     * @param c  Board column (0–7)
     */
    Piece(string s, int x, int y, int r, int c);

    /**
     * @return true if the piece's board coordinates are valid
     *         (i.e., row and col inside 0–7)
     */
    bool isCurrPosValid();

    /**
     * @brief Returns the enum type of this piece based on its ID string.
     */
    PieceID getPieceID(const std::string& id);

    /**
     * @brief Computes all valid moves for this piece.
     * @param cells 8x8 grid of board cells
     * @param whitePiecesArray Array of all white pieces
     * @param blackPiecesArray Array of all black pieces
     */
    void generateValidMove(Cell cells[][8], 
                           Piece* whitePiecesArray[], 
                           Piece* blackPiecesArray[]);

    /**
     * @brief Checks whether the selected cell is one of the piece's valid moves.
     */
    bool isValidMove(Cell& selectedCell);

    /**
     * @return true if this piece has at least one valid move.
     */
    bool hasValidMoves();
};

#endif

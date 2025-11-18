#ifndef BOARD_H
#define BOARD_H

#include <map>
#include <string>
#include <Cell.h>
#include <Piece.h>

using std::string;
using std::map;

/**
 * @class Board
 * @brief Represents the chessboard, containing all cells and chess pieces.
 *
 * This class stores:
 *  - The 8×8 grid of cells
 *  - Maps of white and black pieces (string → Piece*)
 *  - Arrays for quick piece iteration (whitePiecesArray, blackPiecesArray)
 *  - Rendering helpers
 *  - Move validation helpers
 *  - King safety and check/checkmate utilities
 */
class Board {
public:

    string display;                  ///< Display buffer (or unused string holder)
    int convertedPieceCounter;       ///< Tracks number of pawn promotions
    Cell cells[8][8];                ///< 8×8 chessboard grid

    map<string, Piece*> whitePieces; ///< Map of all white pieces by ID ("WKc", "WP1", etc.)
    map<string, Piece*> blackPieces; ///< Map of all black pieces by ID

    Piece* blackPiecesArray[16];     ///< Array of black pieces for fast iteration
    Piece* whitePiecesArray[16];     ///< Array of white pieces

    int remBlackPieceWeight;         ///< Remaining material score for black
    int remWhitePieceWeight;         ///< Remaining material score for white

    Board();
    ~Board();

    /** Rendering utilities **/
    void showEmptyBoard();
    void renderInitial();
    void renderDifficultySettings();
    void renderBracks(Cell& c);
    void removeBracks(Cell& c);
    void renderStars(Cell& c);
    void removeStars(Cell& c);
    void renderPossibleMoves(Piece*& piece);
    void removePossibleMoves(Piece*& piece);
    void renderEmptyCell(Cell& c);
    void renderCell(Cell& c);

    /**
     * @brief Allows selecting a cell on the board.
     * @param row Row index
     * @param col Column index
     * @param pieceSelected Whether a piece is currently selected
     * @param running Used to signal quitting the game
     * @return Selected Cell object
     */
    Cell selectCell(int row, int col, bool pieceSelected, bool& running);

    /** Move and piece validity checks **/
    bool isNotAPiece(Cell& c);
    void generateValidMovesForAll();
    bool isKingCastling(Piece* piece, Cell& toMoveTo);
    bool isLeftCastle(Piece* piece, Cell& toMoveTo);
    bool isADiagonalAdjCell(Piece* piece, Cell& cell);
    bool isPawnDoingEnPassantMove(Piece* piece, Cell& toMoveTo);

    /** Material tracking **/
    int sumRemBlackPiecesWeight();
    int sumRemWhitePiecesWeight();

    /** Piece movement **/
    void movePiece(Piece* piece, Cell& toMoveTo);
    void movePieceNoRender(Piece* piece, Cell& toMoveTo);

    /** Pawn promotion **/
    char renderPromotionSettings();
    char selectPromotion(char pr);

    /** Utility functions **/
    bool isItBlack(Piece* piece);
    bool isWhiteKingInTrouble(Piece* piece);
    void isWhiteKingInCheck(Piece* piece);
    void isBlackKingInCheck(Piece* piece);
    bool isNoValidMoveForBlack();
    bool isNoValidMoveForWhite();
    bool isPieceInside(Piece* piece);
    void negateBlackValidMoves();
    void negateWhiteValidMoves();
    bool isBlackKingInTrouble(Piece* piece);
    bool allowBlackPiecesThatResolveCheck(Piece* piece);
    bool isDrawByInsufficientMaterial();
};

#endif

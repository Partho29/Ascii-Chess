#ifndef PRACGAME_H
#define PRACGAME_H

#include <Board.h>
#include <Cell.h>
#include <Piece.h>

/**
 * @class PracGame
 * @brief Handles the Practice Mode (free-play mode) of the chess game.
 *
 * Responsibilities:
 *  - Allow the player to play without AI or opponent
 *  - Support selecting difficulty (if used for AI-assisted training)
 *  - Manage moves for both sides
 *  - Reset and run the practice board
 *
 * This is the most flexible mode, often used for experimentation,
 * testing positions, and learning moves.
 */
class PracGame {

public:

    Board* board;     ///< Pointer to the chess board instance
    Cell currCell;    ///< Last selected or processed cell
    bool running;     ///< Main loop control flag

    /**
     * @brief Constructor: initializes board and default state.
     */
    PracGame();

    /**
     * @brief Destructor: cleans board memory.
     */
    ~PracGame();

    /**
     * @brief Selects the difficulty in practice mode (if used).
     * @param diff Character representing selected depth/difficulty
     * @return Selected difficulty
     */
    char selectDifficulty(char diff);

    /**
     * @brief Performs a move for white player.
     * @return Pointer to moved piece
     */
    Piece* whiteMove();

    /**
     * @brief Performs a move for black player.
     * @return Pointer to moved piece
     */
    Piece* blackMove();

    /**
     * @brief Resets the board to the standard game setup.
     */
    void resetBoard();

    /**
     * @brief Runs the full practice mode loop.
     */
    void run();
};

#endif

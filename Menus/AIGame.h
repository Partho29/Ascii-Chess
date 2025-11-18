#ifndef AIGAME_H
#define AIGAME_H

#include <utils.h>
#include <Board.h>
#include <Cell.h>
#include <Piece.h>
#include <string>
using std::string;

/**
 * @class AIGame
 * @brief Controls the single-player chess mode where the AI makes moves.
 *
 * Responsibilities:
 *  - Initialize/reset the board
 *  - Handle AI move generation using minimax + alpha-beta pruning
 *  - Manage move execution and undo logic
 *  - Manage difficulty selection
 *  - Run the primary gameplay loop for AI mode
 */
class AIGame {

public:

    Board* board;    ///< Pointer to main board object
    Cell currCell;   ///< Last selected cell / working cell for operations
    bool running;    ///< Game loop control flag
    char AIDepth;    ///< Difficulty setting (depth of minimax search)

    /**
     * @brief Constructor: initializes game state and board.
     */
    AIGame();

    /**
     * @brief Destructor: cleans up board and allocated memory.
     */
    ~AIGame();

    /**
     * @brief Allows user to choose AI difficulty.
     * @param diff Input difficulty (depth character)
     * @return Selected difficulty
     */
    char selectDifficulty(char diff);

    /**
     * @brief Restores board to standard chess starting position.
     */
    void resetBoard();

    /**
     * @brief Makes a move for white AI or user-controlled white.
     * @return Pointer to the moved piece
     */
    Piece* whiteMove();

    /**
     * @brief Makes a move for black AI.
     * @return Pointer to the moved piece
     */
    Piece* blackMove();

    /**
     * @brief Records a move into MoveInfo for undo operations.
     * @param piece Pointer to the moved piece
     * @param toMoveTo Destination cell
     * @return MoveInfo struct containing all move metadata
     */
    myutils::MoveInfo recordMove(Piece* piece, Cell& toMoveTo);

    /**
     * @brief Undoes a move recorded in MoveInfo.
     * @param move MoveInfo containing all details needed to reverse the move
     */
    void undoMove(myutils::MoveInfo& move);

    /**
     * @brief Minimax algorithm with alpha-beta pruning used by AI.
     * @param depth Remaining search depth
     * @param alpha Alpha pruning value
     * @param beta Beta pruning value
     * @param isMaximizing Whether current node maximizes or minimizes score
     * @return Evaluation score
     */
    int minimax(int depth, int alpha, int beta, bool isMaximizing);

    /**
     * @brief Determines the AI's move as a string (logging or debug output).
     * @return Move description string
     */
    string AIMove();

    /**
     * @brief Main loop for running AI game mode.
     */
    void run();
};

#endif

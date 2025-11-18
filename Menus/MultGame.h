#ifndef MULTGAME_H
#define MULTGAME_H

#include <utils.h>
#include <Board.h>
#include <Cell.h>
#include <Piece.h>
#include <string>
using std::string;

#include <SFML/Network.hpp>

/**
 * @class MultGame
 * @brief Handles the multiplayer mode of the chess game using TCP networking.
 *
 * Responsibilities:
 *  - Host/client initialization and handshake
 *  - Sending and receiving moves
 *  - Synchronizing board states between two players
 *  - Determining turn order and color assignment
 *  - Running the multiplayer game loop
 */
class MultGame {

public:

    Board* board;        ///< Pointer to the shared game board
    Cell currCell;       ///< Currently selected or processed cell

    char joiningAs;      ///< 'H' = Host, 'C' = Client
    char color;          ///< 'W' = White, 'B' = Black (assigned after handshake)
    bool isMyTurn;       ///< True if this player is allowed to make a move
    bool running;        ///< Controls the multiplayer game loop

    // --- Networking members (kept as objects, not pointers) ---
    sf::TcpSocket socket; ///< TCP socket used for communication
    unsigned short port;  ///< Port used by host or client

    /**
     * @brief Constructor: initializes game state.
     */
    MultGame();

    /**
     * @brief Destructor: cleans up and closes socket.
     */
    ~MultGame();

    /**
     * @brief Executes a white-player move in multiplayer mode.
     * @return Pointer to moved piece.
     */
    Piece* whiteMove();

    /**
     * @brief Executes a black-player move in multiplayer mode.
     * @return Pointer to moved piece.
     */
    Piece* blackMove();

    /**
     * @brief Chooses whether the player is Host ('H') or Client ('C').
     * @param c Input character
     * @return Resulting choice
     */
    char selectJoiningAs(char c);

    /**
     * @brief Finds an available port to host on.
     * @param start Starting port to test
     * @param max Final port to test
     * @return Free port number
     */
    unsigned short findFreePort(unsigned short start = 5050,
                                unsigned short max = 5200);

    /**
     * @brief Initializes this instance as the multiplayer host.
     * @return True on success
     */
    bool initializeHost();

    /**
     * @brief Initializes this instance as a client connecting to a host.
     * @param ip Host IP address
     * @param hostPort Host port number
     * @return True on success
     */
    bool initializeClient(const string& ip, unsigned short hostPort);

    /**
     * @brief Sends the player's assigned color to the opponent.
     */
    bool sendColor(char color);

    /**
     * @brief Notifies the opponent that this side is ready.
     */
    bool sendReady();

    /**
     * @brief Sends a quit/disconnect instruction.
     */
    bool sendQuit();

    /**
     * @brief Sends a move encoded as 4 integers.
     * @param a From-row
     * @param b From-col
     * @param c To-row
     * @param d To-col
     */
    bool sendMoveInts(int a, int b, int c, int d);

    /**
     * @brief Receives any kind of multiplayer message.
     * @param type Out: type of message ("move", "quit", "ready", etc.)
     * @param a Out: from-row
     * @param b Out: from-col
     * @param c Out: to-row
     * @param d Out: to-col
     * @param colorOut Out: color information if sent
     * @param readyOut Out: readiness info if sent
     * @return True on successful receive
     */
    bool receiveMoveInts(string& type, int &a, int &b, int &c, int &d,
                         char &colorOut, bool &readyOut);

    /**
     * @brief Applies a move received from the remote player.
     */
    void applyRemoteMove(int a, int b, int c, int d);

    /**
     * @brief Handles the turn-based gameplay once both players are connected.
     */
    void connectedNowPlay();

    /**
     * @brief Performs the handshake process as the host.
     */
    void hostHandshake();

    /**
     * @brief Performs the handshake process as the client.
     */
    void clientHandshake();

    /**
     * @brief Resets the board to the initial chess layout.
     */
    void resetBoard();

    /**
     * @brief Runs the complete multiplayer game mode loop.
     */
    void run();
};

#endif

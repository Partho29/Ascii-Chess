#ifndef GAME_H
#define GAME_H

#include <MainMenu.h>

/**
 * @class Game
 * @brief The top-level controller for the entire chess application.
 *
 * Responsibilities:
 *  - Create and manage the main menu
 *  - Provide a simple entry point (`run()`)
 *  - Handle cleanup when the application ends
 *
 * This class acts like the root object of your program, from which all menus,
 * modes (AI, Multiplayer, Practice), and gameplay sessions begin.
 */
class Game {

    MainMenu* menu;   ///< Pointer to the main menu displayed at startup

public:

    /**
     * @brief Constructor: creates the main menu.
     */
    Game();

    /**
     * @brief Destructor: cleans up allocated menu memory.
     */
    ~Game();

    /**
     * @brief Starts the program by running the main menu loop.
     */
    void run();
};

#endif

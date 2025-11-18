/**
 * @file main.cpp
 * @brief Entry point of the Chess Game Project.
 *
 * Initializes VT processing for ANSI colors on Windows,
 * then starts the main game loop through the Game class.
 */

#include <iostream>
#include <thread>
#include <cmath>
#include <cstring>
#include <conio.h>
#include <string>
#include <map>

#ifdef _WIN32
#include <windows.h>
#endif

#include <SFML/Network.hpp>

// Game project headers
#include <utils.h>
#include <Cell.h>
#include <Piece.h>
#include <Board.h>
#include <Game.h>
#include <MainMenu.h>
#include <AIGame.h>
#include <PracGame.h>
#include <MultGame.h>
#include <Options.h>

using namespace std;

/**
 * @brief Main program entry point.
 *
 * - Enables VT Mode on Windows so ANSI escape sequences work.
 * - If VT mode cannot be enabled, disables color-changing features.
 * - Creates and runs the main Game object.
 *
 * @return int Exit status code.
 */
int main() {
    // Enable ANSI escape color support on Windows.
    if (!myutils::enableVTMode()) {
        myutils::CAN_CHANGE_COLOR = false;
    }

    // Start the game.
    Game* game = new Game();
    game->run();
    delete game;

    return 0;
}

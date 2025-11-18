#ifndef OPTIONS_H
#define OPTIONS_H

#include <utils.h>
#include <string>
using std::string;

/**
 * @class Options
 * @brief Handles the settings/options menu of the game.
 *
 * Responsibilities:
 *  - Render the options screen
 *  - Allow the user to change graphics settings / color themes
 *  - Manage bracket indicators used for selection/highlighting
 *  - Process keyboard input for navigation and choices
 */
class Options {

    myutils::Pos leftBrac;   ///< Console position of the left bracket indicator
    myutils::Pos rightBrac;  ///< Console position of the right bracket indicator
    string graphics;         ///< Stores currently selected graphics/theme setting

public:

    /**
     * @brief Constructor: initializes option positions and default settings.
     */
    Options();

    /**
     * @brief Renders the options/settings menu to the console.
     */
    void renderOptions();

    /**
     * @brief Resets bracket (selection indicators) back to default state.
     */
    void resetBrackets();

    /**
     * @brief Draws brackets on screen around the current selection.
     */
    void renderBrackets();

    /**
     * @brief Removes brackets from the screen.
     */
    void removeBrackets();

    /**
     * @brief Handles user input for navigating and modifying settings.
     */
    void takeInput();

    /**
     * @brief Runs the entire options/settings menu loop.
     */
    void run();
};

#endif

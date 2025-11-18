#ifndef MAINMENU_H
#define MAINMENU_H

#include <utils.h>
#include <AIGame.h>
#include <MultGame.h>
#include <PracGame.h>
#include <Options.h>
#include <string>
using std::string;

/**
 * @class MainMenu
 * @brief Handles the game's primary menu interface and navigation.
 *
 * Responsibilities:
 *  - Render the main menu layout
 *  - Handle user navigation (arrow selection)
 *  - Launch AI Game / Multiplayer / Practice / Options screens
 *  - Maintain menu state and animations (arrows, highlights)
 */
class MainMenu {

    AIGame* aiGame;          ///< Pointer to AI game mode handler
    MultGame* multiplayer;   ///< Pointer to multiplayer game handler
    PracGame* practice;      ///< Pointer to practice/training mode handler
    Options* options;        ///< Pointer to options/settings menu

    string graphics;         ///< Graphics mode/value (printed theme or style)
    myutils::Pos leftArrow;  ///< Console position of the left arrow indicator
    myutils::Pos rightArrow; ///< Console position of the right arrow indicator

    char optionSelected;     ///< Currently highlighted menu option

public:

    /**
     * @brief Constructor: initializes all menu components and default selection.
     */
    MainMenu();

    /**
     * @brief Destructor: frees allocated game mode/menu objects.
     */
    ~MainMenu();

    /**
     * @brief Renders the full main menu to the console.
     */
    void renderMainMenu();

    /**
     * @brief Removes arrow indicators from the menu screen.
     */
    void removeArrows();

    /**
     * @brief Renders arrows next to the currently selected option.
     */
    void renderArrows();

    /**
     * @brief Handles keyboard input for menu navigation.
     * @return true if the user chooses an option that starts a mode,
     *         false if menu continues.
     */
    bool takeInput();

    /**
     * @brief Runs the main menu loop until user selects a mode.
     */
    void run();
};

#endif


#include <MainMenu.h>
#include <AIGame.h>
#include <MultGame.h>
#include <PracGame.h>
#include <Options.h>
#include <utils.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <conio.h>
#include <iostream>
using namespace std;

  MainMenu::MainMenu() : aiGame(new AIGame()), multiplayer(new MultGame()), practice(new PracGame()), options(new Options()), leftArrow(11, 6), rightArrow(34, 6), optionSelected('A') {
    //graphics = "\n   =========================================\n  || _-_  __  __ > >    __      __  __  __ ||\n  |||___||__ |   | |   |   |__||__ |__ |__ ||\n  |||   | __||__ | |   |__ |  ||__  __| __|||\n  ||---------------------------------------||\n  ||		 Play Against AI           ||\n  ||             ---------------           ||\n  ||		   Multiplayer             ||\n  ||               -----------             ||\n  ||		    Practice               ||\n  ||                --------               ||\n  ||		     Option                ||\n  ||                 ------                ||\n  ||		      Quit                 ||\n  ||---------------------------------------||\n  ||:::::::::::::::::::::::::::::::::::::::||\n   =========================================";
    this -> graphics = R"(
   =========================================
  || _-_  __  __ > >    __      __  __  __ ||
  |||___||__ |   | |   |   |__||__ |__ |__ ||
  |||   | __||__ | |   |__ |  ||__  __| __|||
  ||---------------------------------------||
  ||             Play Against AI           ||
  ||             ---------------           ||
  ||               Multiplayer             ||
  ||               -----------             ||
  ||                Practice               ||
  ||                --------               ||
  ||                 Option                ||
  ||                 ------                ||
  ||                  Quit                 ||
  ||---------------------------------------||
  ||:::::::::::::::::::::::::::::::::::::::||
   ========================================= 
)";
  }
  MainMenu::~MainMenu(){
    delete aiGame;
    delete multiplayer;
    delete practice;
    delete options;
  }

  void MainMenu::renderMainMenu(){
    cout << "\033[0m";
    system("cls");
    cout << myutils::BG_COLOR;
    cout << myutils::TXT_COLOR;
    cout << this -> graphics;
  }

  void MainMenu::removeArrows(){
    COORD currPos = myutils::getCursorPosition();
    myutils::setCursorPosition(this -> leftArrow.x, this -> leftArrow.y);
    cout << "    ";
    myutils::setCursorPosition(this -> rightArrow.x, this -> rightArrow.y);
    cout << "    ";
    myutils::setCursorPosition(currPos.X, currPos.Y);
  }
  void MainMenu::renderArrows(){
    COORD currPos = myutils::getCursorPosition();
    myutils::setCursorPosition(this -> leftArrow.x, this -> leftArrow.y);
    cout << "-->>";
    myutils::setCursorPosition(this -> rightArrow.x, this -> rightArrow.y);
    cout << "<<--";
    myutils::setCursorPosition(currPos.X, currPos.Y);
  }

  bool MainMenu::takeInput(){
    this -> renderArrows();
    int key = -1;
    while(key != 13){
      key = _getch();
      if(key == 224 || key == 0){
        this -> removeArrows();
        key = _getch();
        switch(key){
          case 72: // Up Arrow
            if(optionSelected == 'A'){
              optionSelected = 'Q';
              leftArrow.x = 16;
              leftArrow.y = 14;

              rightArrow.x = 28;
              rightArrow.y = 14;
            }

            else if(optionSelected == 'M'){
              optionSelected = 'A';
              leftArrow.x = 11;
              leftArrow.y = 6;

              rightArrow.x = 34;
              rightArrow.y = 6;
            }

            else if(optionSelected == 'P'){
              optionSelected = 'M';
              leftArrow.x = 13;
              leftArrow.y = 8;

              rightArrow.x = 32;
              rightArrow.y = 8;
            }

            else if(optionSelected == 'O'){
              optionSelected = 'P';
              leftArrow.x = 14;
              leftArrow.y = 10;

              rightArrow.x = 30;
              rightArrow.y = 10;
            }

            else if(optionSelected == 'Q'){
              optionSelected = 'O';
              leftArrow.x = 15;
              leftArrow.y = 12;

              rightArrow.x = 29;
              rightArrow.y = 12;
            }
            break;
          case 80: // Down Arrow
            if(optionSelected == 'A'){
              optionSelected = 'M';
              leftArrow.x = 13;
              leftArrow.y = 8;

              rightArrow.x = 32;
              rightArrow.y = 8;
            }

            else if(optionSelected == 'M'){
              optionSelected = 'P';
              leftArrow.x = 14;
              leftArrow.y = 10;

              rightArrow.x = 30;
              rightArrow.y = 10;
            }

            else if(optionSelected == 'P'){
              optionSelected = 'O';
              leftArrow.x = 15;
              leftArrow.y = 12;

              rightArrow.x = 29;
              rightArrow.y = 12;
            }

            else if(optionSelected == 'O'){
              optionSelected = 'Q';
              leftArrow.x = 16;
              leftArrow.y = 14;

              rightArrow.x = 28;
              rightArrow.y = 14;
            }

            else if(optionSelected == 'Q'){
              optionSelected = 'A';
              leftArrow.x = 11;
              leftArrow.y = 6;

              rightArrow.x = 34;
              rightArrow.y = 6;
            }
            break;
            
        }
        this -> renderArrows();
      }
      else if(key == 27){
        return false;
      }
    }

    switch(optionSelected){
      case 'Q':
        return false;
      case 'O':
        this -> options -> run();
        break;
      case 'P':
        this -> practice -> run();
        this -> practice -> resetBoard();
        break;
      case 'M':
        this -> multiplayer -> run();
        this -> multiplayer -> resetBoard();
        break;
      case 'A':
        this -> aiGame -> run();
        this -> aiGame -> resetBoard();
        break;
    }
    return true;
  }

  void MainMenu::run(){
    bool running = true;
    while(running){
      cout << "\033[0m";
      system("cls");
      cout << myutils::BG_COLOR;
      cout << myutils::TXT_COLOR;
      this -> renderMainMenu();
      running = this -> takeInput();
    }
    
    //cin.get();
  }


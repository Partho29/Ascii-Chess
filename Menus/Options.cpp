#include <Options.h>
#include <utils.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <conio.h>
#include <iostream>
using namespace std;

  Options::Options() : leftBrac(8, 8), rightBrac(14, 8){
    this -> graphics = R"(
   =========================================
  || _-_  __  __ > >    __      __  __  __ ||
  |||___||__ |   | |   |   |__||__ |__ |__ ||
  |||   | __||__ | |   |__ |  ||__  __| __|||
  ||---------------------------------------||
  ||            BACKGROUND COLOR           ||
  ||            ----------------           ||
  ||     Black  Blue  Green  Red  White    ||
  ||                                       ||
  ||               TEXT COLOR              ||
  ||               ----------              ||
  ||  White  Cyan  Yellow  Magenta  Green  ||
  ||                                       ||
  ||            EMPTY CELL STYLE           ||
  ||            ----------------           ||
  || | :: |  |   |  | __ |  | .. |  | -- | ||
   ========================================= 
)";
  }

  void Options::renderOptions(){
    cout << "\033[0m";
    system("cls");
    cout << myutils::BG_COLOR;
    cout << myutils::TXT_COLOR;
    cout << this -> graphics;
  }

  void Options::resetBrackets(){
    this->leftBrac.x = 8;
    this->leftBrac.y = 8;
    this->rightBrac.x = 14;
    this->rightBrac.y = 8;
  }
  void Options::renderBrackets(){
    COORD currPos = myutils::getCursorPosition();
    myutils::setCursorPosition(this -> leftBrac.x, this -> leftBrac.y);
    cout << "[";
    myutils::setCursorPosition(this -> rightBrac.x, this -> rightBrac.y);
    cout << "]";
    myutils::setCursorPosition(currPos.X, currPos.Y);
  }

  void Options::removeBrackets(){
    COORD currPos = myutils::getCursorPosition();
    myutils::setCursorPosition(this -> leftBrac.x, this -> leftBrac.y);
    cout << " ";
    myutils::setCursorPosition(this -> rightBrac.x, this -> rightBrac.y);
    cout << " ";
    myutils::setCursorPosition(currPos.X, currPos.Y);
  }
  void Options::takeInput(){
    int thingSelected = 1;
    this -> resetBrackets();
    this -> renderBrackets();
    //cin.get();
    int key;
    while(true){
      key = -1;
      while(key != 13){
        key = _getch();
        if(key == 224 || key == 0){
          this -> removeBrackets();
          key = _getch();
          switch(key){
            case 72: // Up Arrow
              if(thingSelected == 1){
                thingSelected = 11;
                this->leftBrac.x = 4;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 11;
                this -> rightBrac.y = 16;
              }
              else if(thingSelected == 2){
                thingSelected = 12;
                this->leftBrac.x = 12;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 18;
                this -> rightBrac.y = 16;
              }
              else if(thingSelected == 3){
                thingSelected = 13;
                this->leftBrac.x = 19;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 26;
                this -> rightBrac.y = 16;
              }
              else if(thingSelected == 4){
                thingSelected = 14;
                this->leftBrac.x = 27;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 34;
                this -> rightBrac.y = 16;
              }
              else if(thingSelected == 5){
                thingSelected = 15;
                this->leftBrac.x = 35;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 42;
                this -> rightBrac.y = 16;
              }
              else if(thingSelected == 6){
                thingSelected = 1;
                this->leftBrac.x = 8;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 14;
                this -> rightBrac.y = 8;
              }
              else if(thingSelected == 7){
                thingSelected = 2;
                this->leftBrac.x = 15;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 20;
                this -> rightBrac.y = 8;
              }
              else if(thingSelected == 8){
                thingSelected = 3;
                this->leftBrac.x = 21;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 27;
                this -> rightBrac.y = 8;
              }
              else if(thingSelected == 9){
                thingSelected = 4;
                this->leftBrac.x = 28;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 32;
                this -> rightBrac.y = 8;
              }
              else if(thingSelected == 10){
                thingSelected = 5;
                this->leftBrac.x = 33;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 39;
                this -> rightBrac.y = 8;
              }
              else if(thingSelected == 11){
                thingSelected = 6;
                this->leftBrac.x = 5;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 11;
                this -> rightBrac.y = 12;
              }
              else if(thingSelected == 12){
                thingSelected = 7;
                this->leftBrac.x = 12;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 17;
                this -> rightBrac.y = 12;
              }
              else if(thingSelected == 13){
                thingSelected = 8;
                this->leftBrac.x = 18;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 25;
                this -> rightBrac.y = 12;
              }
              else if(thingSelected == 14){
                thingSelected = 9;
                this->leftBrac.x = 26;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 34;
                this -> rightBrac.y = 12;
              }
              else if(thingSelected == 15){
                thingSelected = 10;
                this->leftBrac.x = 35;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 41;
                this -> rightBrac.y = 12;
              }
              break;
            case 80: // Down Arrow
              if(thingSelected == 1){
                thingSelected = 6;
                this->leftBrac.x = 5;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 11;
                this -> rightBrac.y = 12;
              }
              else if(thingSelected == 2){
                thingSelected = 7;
                this->leftBrac.x = 12;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 17;
                this -> rightBrac.y = 12;
              }
              else if(thingSelected == 3){
                thingSelected = 8;
                this->leftBrac.x = 18;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 25;
                this -> rightBrac.y = 12;
              }
              else if(thingSelected == 4){
                thingSelected = 9;
                this->leftBrac.x = 26;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 34;
                this -> rightBrac.y = 12;
              }
              else if(thingSelected == 5){
                thingSelected = 10;
                this->leftBrac.x = 35;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 41;
                this -> rightBrac.y = 12;
              }
              else if(thingSelected == 6){
                thingSelected = 11;
                this->leftBrac.x = 4;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 11;
                this -> rightBrac.y = 16;
              }
              else if(thingSelected == 7){
                thingSelected = 12;
                this->leftBrac.x = 12;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 18;
                this -> rightBrac.y = 16;
              }
              else if(thingSelected == 8){
                thingSelected = 13;
                this->leftBrac.x = 19;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 26;
                this -> rightBrac.y = 16;
              }
              else if(thingSelected == 9){
                thingSelected = 14;
                this->leftBrac.x = 27;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 34;
                this -> rightBrac.y = 16;
              }
              else if(thingSelected == 10){
                thingSelected = 15;
                this->leftBrac.x = 35;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 42;
                this -> rightBrac.y = 16;
              }
              else if(thingSelected == 11){
                thingSelected = 1;
                this->leftBrac.x = 8;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 14;
                this -> rightBrac.y = 8;
              }
              else if(thingSelected == 12){
                thingSelected = 2;
                this->leftBrac.x = 15;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 20;
                this -> rightBrac.y = 8;
              }
              else if(thingSelected == 13){
                thingSelected = 3;
                this->leftBrac.x = 21;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 27;
                this -> rightBrac.y = 8;
              }
              else if(thingSelected == 14){
                thingSelected = 4;
                this->leftBrac.x = 28;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 32;
                this -> rightBrac.y = 8;
              }
              else if(thingSelected == 15){
                thingSelected = 5;
                this->leftBrac.x = 33;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 39;
                this -> rightBrac.y = 8;
              }
              break;
            case 75: // Left Arrow
              if(thingSelected == 1){
                thingSelected = 5;
                this->leftBrac.x = 33;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 39;
                this -> rightBrac.y = 8;
              }
              else if(thingSelected == 2){
                thingSelected = 1;
                this->leftBrac.x = 8;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 14;
                this -> rightBrac.y = 8;
              }
              else if(thingSelected == 3){
                thingSelected = 2;
                this->leftBrac.x = 15;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 20;
                this -> rightBrac.y = 8;
              }
              else if(thingSelected == 4){
                thingSelected = 3;
                this->leftBrac.x = 21;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 27;
                this -> rightBrac.y = 8;
              }
              else if(thingSelected == 5){
                thingSelected = 4;
                this->leftBrac.x = 28;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 32;
                this -> rightBrac.y = 8;
              }
              else if(thingSelected == 6){
                thingSelected = 10;
                this->leftBrac.x = 35;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 41;
                this -> rightBrac.y = 12;
              }
              else if(thingSelected == 7){
                thingSelected = 6;
                this->leftBrac.x = 5;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 11;
                this -> rightBrac.y = 12;
              }
              else if(thingSelected == 8){
                thingSelected = 7;
                this->leftBrac.x = 12;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 17;
                this -> rightBrac.y = 12;
              }
              else if(thingSelected == 9){
                thingSelected = 8;
                this->leftBrac.x = 18;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 25;
                this -> rightBrac.y = 12;
              }
              else if(thingSelected == 10){
                thingSelected = 9;
                this->leftBrac.x = 26;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 34;
                this -> rightBrac.y = 12;
              }
              else if(thingSelected == 11){
                thingSelected = 15;
                this->leftBrac.x = 35;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 42;
                this -> rightBrac.y = 16;
              }
              else if(thingSelected == 12){
                thingSelected = 11;
                this->leftBrac.x = 4;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 11;
                this -> rightBrac.y = 16;
              }
              else if(thingSelected == 13){
                thingSelected = 12;
                this->leftBrac.x = 12;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 18;
                this -> rightBrac.y = 16;
              }
              else if(thingSelected == 14){
                thingSelected = 13;
                this->leftBrac.x = 19;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 26;
                this -> rightBrac.y = 16;
              }
              else if(thingSelected == 15){
                thingSelected = 14;
                this->leftBrac.x = 27;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 34;
                this -> rightBrac.y = 16;
              }
              break;
            case 77: // Right Arrow
            if(thingSelected == 1){
                thingSelected = 2;
                this->leftBrac.x = 15;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 20;
                this -> rightBrac.y = 8;
              }
              else if(thingSelected == 2){
                thingSelected = 3;
                this->leftBrac.x = 21;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 27;
                this -> rightBrac.y = 8;
              }
              else if(thingSelected == 3){
                thingSelected = 4;
                this->leftBrac.x = 28;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 32;
                this -> rightBrac.y = 8;
              }
              else if(thingSelected == 4){
                thingSelected = 5;
                this->leftBrac.x = 33;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 39;
                this -> rightBrac.y = 8;
              }
              else if(thingSelected == 5){
                thingSelected = 1;
                this->leftBrac.x = 8;
                this -> leftBrac.y = 8;
                this -> rightBrac.x = 14;
                this -> rightBrac.y = 8;
              }
              else if(thingSelected == 6){
                thingSelected = 7;
                this->leftBrac.x = 12;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 17;
                this -> rightBrac.y = 12;
              }
              else if(thingSelected == 7){
                thingSelected = 8;
                this->leftBrac.x = 18;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 25;
                this -> rightBrac.y = 12;
              }
              else if(thingSelected == 8){
                thingSelected = 9;
                this->leftBrac.x = 26;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 34;
                this -> rightBrac.y = 12;
              }
              else if(thingSelected == 9){
                thingSelected = 10;
                this->leftBrac.x = 35;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 41;
                this -> rightBrac.y = 12;
              }
              else if(thingSelected == 10){
                thingSelected = 6;
                this->leftBrac.x = 5;
                this -> leftBrac.y = 12;
                this -> rightBrac.x = 11;
                this -> rightBrac.y = 12;
              }
              else if(thingSelected == 11){
                thingSelected = 12;
                this->leftBrac.x = 12;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 18;
                this -> rightBrac.y = 16;
              }
              else if(thingSelected == 12){
                thingSelected = 13;
                this->leftBrac.x = 19;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 26;
                this -> rightBrac.y = 16;
              }
              else if(thingSelected == 13){
                thingSelected = 14;
                this->leftBrac.x = 27;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 34;
                this -> rightBrac.y = 16;
              }
              else if(thingSelected == 14){
                thingSelected = 15;
                this->leftBrac.x = 35;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 42;
                this -> rightBrac.y = 16;
              }
              else if(thingSelected == 15){
                thingSelected = 11;
                this->leftBrac.x = 4;
                this -> leftBrac.y = 16;
                this -> rightBrac.x = 11;
                this -> rightBrac.y = 16;
              }
              break;
          }
          this -> renderBrackets();
        }
        else if(key == 27){
          return;
        }
      }
      switch(thingSelected){
      case 1:
        myutils::BG_COLOR = "\033[40m";
        break;
      case 2:
        myutils::BG_COLOR = "\033[44m";
        break;
      case 3:
        myutils::BG_COLOR = "\033[42m";
        break;
      case 4:
        myutils::BG_COLOR = "\033[41m";
        break;
      case 5:
        myutils::BG_COLOR = "\033[47m";
        break;
      case 6:
        myutils::TXT_COLOR = "\033[97m";
        break;
      case 7:
        myutils::TXT_COLOR = "\033[96m";
        break;
      case 8:
        myutils::TXT_COLOR = "\033[93m";
        break;
      case 9:
        myutils::TXT_COLOR = "\033[95m";
        break;
      case 10:
        myutils::TXT_COLOR = "\033[92m";
        break;
      case 11:
        myutils::CELL_STYLE = "::";
        break;
      case 12:
        myutils::CELL_STYLE = "  ";
        break;
      case 13:
        myutils::CELL_STYLE = "__";
        break;
      case 14:
        myutils::CELL_STYLE = "..";
        break;
      case 15:
        myutils::CELL_STYLE = "--";
        break;
    }
      this -> renderOptions();
      this -> renderBrackets();
    }
  }
  void Options::run(){
    system("cls");
    cout << myutils::BG_COLOR;
    cout << myutils::TXT_COLOR;
    this -> renderOptions();
    this -> takeInput();
    return;
  }

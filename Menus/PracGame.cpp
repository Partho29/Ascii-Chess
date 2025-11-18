#include <PracGame.h>
#include <Board.h>
#include <Piece.h>
#include <Cell.h>
#include <utils.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <conio.h>
#include <iostream>
using namespace std;

  
  
  PracGame::PracGame() : board(new Board()), running(false){
    currCell.col = 0;
    currCell.row = 7;
  }
  PracGame::~PracGame(){
    delete board;
  }

  char PracGame::selectDifficulty(char diff){
    char selected = diff;
    int inp = -1;
    COORD currPos= myutils::getCursorPosition();


    while(inp != 13){
      inp = _getch();
      if (inp == 224 || inp == 0) {
        inp = _getch();
        
        switch(inp) {
            case 72: // Up arrow
                if (selected == 'e'){
                  myutils::setCursorPosition(11, 21);
                  cout << "    ";
                  myutils::setCursorPosition(11, 23);
                  cout << "<<--";
                  selected = 'h';
                }
                else if(selected == 'm'){
                  myutils::setCursorPosition(11, 22);
                  cout << "    ";
                  myutils::setCursorPosition(11, 21);
                  cout << "<<--";
                  selected = 'e';
                }
                else if(selected == 'h'){
                  myutils::setCursorPosition(11, 23);
                  cout << "    ";
                  myutils::setCursorPosition(11, 22);
                  cout << "<<--";
                  selected = 'm';
                }
                break;
            case 80: // Down arrow
                if (selected == 'e'){
                  myutils::setCursorPosition(11, 21);
                  cout << "    ";
                  myutils::setCursorPosition(11, 22);
                  cout << "<<--";
                  selected = 'm';

                }
                else if(selected == 'm'){
                  myutils::setCursorPosition(11, 22);
                  cout << "    ";
                  myutils::setCursorPosition(11, 23);
                  cout << "<<--";
                  selected = 'h';
                }
                else if(selected == 'h'){
                  myutils::setCursorPosition(11, 23);
                  cout << "    ";
                  myutils::setCursorPosition(11, 21);
                  cout << "<<--";
                  selected = 'e';
                }
                break;
            // case 75: // Left arrow
            //     if (cursorCol > 0) cursorCol--;
            //     break;
            // case 77: // Right arrow
            //     if (cursorCol < 7) cursorCol++;
            //     break;
        }
    
      }
    
    }
    myutils::setCursorPosition(currPos.X, currPos.Y);
    return selected;
  }


  Piece* PracGame::whiteMove(){
    COORD currPos = myutils::getCursorPosition();
    Piece* piece = nullptr;
    Cell selectedCell;
    Cell selectedMoveCell;
    bool selectAnotherPiece = true;
    selectedMoveCell.col = this -> currCell.col;
    selectedMoveCell.row = this -> currCell.row;
    while(selectAnotherPiece){
      selectedCell = board -> selectCell(selectedMoveCell.row, selectedMoveCell.col, false, running);
      if(!running) return nullptr;
      cout << "\n";
      while(board -> isNotAPiece(selectedCell) || !selectedCell.piece -> hasValidMoves() || board -> isItBlack(selectedCell.piece)){
        COORD currPos = myutils::getCursorPosition();
        cout << "Select a valid piece!!!";
        selectedCell = board -> selectCell(selectedCell.row, selectedCell.col, false, running);
        if(!running) return nullptr;
        myutils::setCursorPosition(currPos.X, currPos.Y);
        cout << "                             ";
        myutils::setCursorPosition(currPos.X, currPos.Y);
      }

      piece = selectedCell.piece;
      selectAnotherPiece = false;
      selectedMoveCell = board -> selectCell(selectedCell.row, selectedCell.col, true, running);
      if(!running) return nullptr;
      
      while(!piece -> isValidMove(selectedMoveCell)){

        //Checking if X was entered
        if(!myutils::isInsideGrid(selectedMoveCell.row, selectedMoveCell.col)){
          selectedMoveCell.row = selectedCell.row;
          selectedMoveCell.col = selectedCell.col;
          selectAnotherPiece = true;
          break;
        }
        COORD currPos = myutils::getCursorPosition();
        cout << "Select a valid move!!";
        selectedMoveCell = board -> selectCell(selectedMoveCell.row, selectedMoveCell.col, true, running);
        if(!running) return nullptr;
        myutils::setCursorPosition(currPos.X, currPos.Y);
        cout << "                     ";
        myutils::setCursorPosition(currPos.X, currPos.Y);
      }

      if(selectAnotherPiece) continue;
      //Move the piece temporary
      board -> movePiece(piece, selectedMoveCell);
      this -> currCell.row = selectedMoveCell.row;
      this -> currCell.col = selectedMoveCell.col;
      //board -> ifCastlingInvalid(piece);
    }
    myutils::setCursorPosition(currPos.X, currPos.Y);
    return piece;
  }

  Piece* PracGame::blackMove(){
    COORD currPos = myutils::getCursorPosition();
    Piece* piece = nullptr;
    Cell selectedCell;
    Cell selectedMoveCell;
    bool selectAnotherPiece = true;
    selectedMoveCell.col = this -> currCell.col;
    selectedMoveCell.row = this -> currCell.row;
    while(selectAnotherPiece){
      selectedCell = board -> selectCell(selectedMoveCell.row, selectedMoveCell.col, false, running);
      if(!running) return nullptr;
      cout << "\n";
      while(board -> isNotAPiece(selectedCell) || !selectedCell.piece -> hasValidMoves() || !board -> isItBlack(selectedCell.piece)){
        COORD currPos = myutils::getCursorPosition();
        cout << "Select a valid piece!!!";
        selectedCell = board -> selectCell(selectedCell.row, selectedCell.col, false, running);
        if(!running) return nullptr;
        myutils::setCursorPosition(currPos.X, currPos.Y);
        cout << "                             ";
        myutils::setCursorPosition(currPos.X, currPos.Y);
      }

      piece = selectedCell.piece;
      selectAnotherPiece = false;
      selectedMoveCell = board -> selectCell(selectedCell.row, selectedCell.col, true, running);
      if(!running) return nullptr;
      
      while(!piece -> isValidMove(selectedMoveCell)){

        //Checking if X was entered
        if(!myutils::isInsideGrid(selectedMoveCell.row, selectedMoveCell.col)){
          selectedMoveCell.row = selectedCell.row;
          selectedMoveCell.col = selectedCell.col;
          selectAnotherPiece = true;
          break;
        }
        COORD currPos = myutils::getCursorPosition();
        cout << "Select a valid move!!";
        selectedMoveCell = board -> selectCell(selectedMoveCell.row, selectedMoveCell.col, true, running);
        if(!running) return nullptr;
        myutils::setCursorPosition(currPos.X, currPos.Y);
        cout << "                     ";
        myutils::setCursorPosition(currPos.X, currPos.Y);
      }

      if(selectAnotherPiece) continue;
      //Move the piece temporary
      board -> movePiece(piece, selectedMoveCell);
      this -> currCell.row = selectedMoveCell.row;
      this -> currCell.col = selectedMoveCell.col;
      //board -> ifCastlingInvalid(piece);
    }
    myutils::setCursorPosition(currPos.X, currPos.Y);
    return piece;
  }

  void PracGame::resetBoard(){
    Board* temp = board;
    board = new Board();
    delete temp;
    running = false;
    this -> currCell.col = 0;
    this -> currCell.row = 7;
  }

  void PracGame::run(){
    this -> running = true;
    system("cls");
    this -> board -> renderInitial();
    this -> board -> generateValidMovesForAll();
    //board -> renderDifficultySettings();
    //char difficulty;
    //difficulty = this -> selectDifficulty('e');
    //system("cls");
    //board -> renderInitial();


    while(running){
      Piece* piece = nullptr;
      piece = this -> whiteMove();
      if(!piece){
        running = false;
        return;
      }
      if(this -> board -> isBlackKingInTrouble(piece)  || this -> board -> isDrawByInsufficientMaterial()){
        running = false;
      }
      if(!running) return;
      piece = this -> blackMove();
      if(!piece){
        running = false;
        return;
      }
      if(this -> board -> isWhiteKingInTrouble(piece)  || this -> board -> isDrawByInsufficientMaterial()){
        running = false;
      }
    }
    

    // Cell selectedCell;
    // Cell selectedMoveCell;
    // selectedMoveCell.col = 0;
    // selectedMoveCell.row = 7;
    // while(true){
    //   selectedCell = board -> selectCell(selectedMoveCell.row, selectedMoveCell.col, false);
    //   cout << "\n";
    //   while(board -> isNotAPiece(selectedCell) || !selectedCell.piece -> hasValidMoves()){
    //     COORD currPos = myutils::getCursorPosition();
    //     cout << "Select a valid piece!!!";
    //     selectedCell = board -> selectCell(selectedCell.row, selectedCell.col, false);
    //     myutils::setCursorPosition(currPos.X, currPos.Y);
    //     cout << "                             ";
    //     myutils::setCursorPosition(currPos.X, currPos.Y);
    //   }

    //   Piece* piece = selectedCell.piece;
    //   bool selectAnotherPiece = false;
    //   selectedMoveCell = board -> selectCell(selectedCell.row, selectedCell.col, true);
      
    //   while(!piece -> isValidMove(selectedMoveCell)){

    //     //Checking if X was entered
    //     if(!myutils::isInsideGrid(selectedMoveCell.row, selectedMoveCell.col)){
    //       selectedMoveCell.row = selectedCell.row;
    //       selectedMoveCell.col = selectedCell.col;
    //       selectAnotherPiece = true;
    //       break;
    //     }
    //     COORD currPos = myutils::getCursorPosition();
    //     cout << "Select a valid move!!";
    //     selectedMoveCell = board -> selectCell(selectedMoveCell.row, selectedMoveCell.col, true);
    //     myutils::setCursorPosition(currPos.X, currPos.Y);
    //     cout << "                     ";
    //     myutils::setCursorPosition(currPos.X, currPos.Y);
    //   }

    //   if(selectAnotherPiece) continue;
    //   //Move the piece temporary
    //   board -> movePiece(piece, selectedMoveCell);
    //   //board -> ifCastlingInvalid(piece);
    // }
    


    
    

  }

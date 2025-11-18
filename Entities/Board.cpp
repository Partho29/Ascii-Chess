#include <Board.h>
#include <Piece.h>
#include <Cell.h>
#include <utils.h>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

#include <string>
#include <map>
#include <string>
#include <conio.h>
#include <cmath>
#include <cstring>
using namespace std;
  
  Board::Board(){
    this -> convertedPieceCounter = 2;
    this -> display =
    "      A    B    C    D    E    F    G    H     \n   =========================================   \n8 || "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" || 8\n  ||---------------------------------------||  \n7 || "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" || 7\n  ||---------------------------------------||  \n6 || "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" || 6\n  ||---------------------------------------||  \n5 || "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" || 5\n  ||---------------------------------------||  \n4 || "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" || 4\n  ||---------------------------------------||  \n3 || "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" || 3\n  ||---------------------------------------||  \n2 || "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" || 2\n  ||---------------------------------------||  \n1 || "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" || 1\n   =========================================   \n      A    B    C    D    E    F    G    H     ";

    this -> remBlackPieceWeight = 1039;
    this -> remWhitePieceWeight = 1039;
    int blackPieceCounter = 0;
    int whitePieceCounter = 0;
    for(int row = 0; row < 8; row++){
      for(int col = 0; col < 8; col++){
        if(row > 1 && row < 6){
          cells[row][col].y = 6 + (2 * (row - 2));
          cells[row][col].x = 5 + (5 * col);
          cells[row][col].piece = nullptr;
        }
        else{
          if(row == 0){
            if(col == 0){
              cells[row][col].y = 2;
              cells[row][col].x = 5;
              cells[row][col].piece = blackPieces["BR1c"] = blackPiecesArray[blackPieceCounter++] = new Piece("BR1c", 5, 2, row, col);
            }
            else if(col == 1){
              cells[row][col].y = 2;
              cells[row][col].x = 10;
              cells[row][col].piece = blackPieces["BN1"] = blackPiecesArray[blackPieceCounter++] = new Piece("BN1", 10, 2, row, col);
            }
            else if(col == 2){
              cells[row][col].y = 2;
              cells[row][col].x = 15;
              cells[row][col].piece = blackPieces["BB1"] = blackPiecesArray[blackPieceCounter++] = new Piece("BB1", 15, 2, row, col);
            }
            else if(col == 3){
              cells[row][col].y = 2;
              cells[row][col].x = 20;
              cells[row][col].piece = blackPieces["BQ"] = blackPiecesArray[blackPieceCounter++] = new Piece("BQ", 20, 2, row, col);
            }
            else if(col == 4){
              cells[row][col].y = 2;
              cells[row][col].x = 25;
              cells[row][col].piece = blackPieces["BKc"] = blackPiecesArray[blackPieceCounter++] = new Piece("BKc", 25, 2, row, col);
            }
            else if(col == 5){
              cells[row][col].y = 2;
              cells[row][col].x = 30;
              cells[row][col].piece = blackPieces["BB2"] = blackPiecesArray[blackPieceCounter++] = new Piece("BB2", 30, 2, row, col);
            }
            else if(col == 6){
              cells[row][col].y = 2;
              cells[row][col].x = 35;
              cells[row][col].piece = blackPieces["BN2"] = blackPiecesArray[blackPieceCounter++] = new Piece("BN2", 35, 2, row, col);
            }
            else if(col == 7){
              cells[row][col].y = 2;
              cells[row][col].x = 40;
              cells[row][col].piece = blackPieces["BR2c"] = blackPiecesArray[blackPieceCounter++] = new Piece("BR2c", 40, 2, row, col);
            }
          }

          else if(row == 7){
            if(col == 0){
              cells[row][col].y = 16;
              cells[row][col].x = 5;
              cells[row][col].piece = whitePieces["WR1c"] = whitePiecesArray[whitePieceCounter++] = new Piece("WR1c", 5, 16, row, col);
            }
            else if(col == 1){
              cells[row][col].y = 16;
              cells[row][col].x = 10;
              cells[row][col].piece = whitePieces["WN1"] = whitePiecesArray[whitePieceCounter++] = new Piece("WN1", 10, 16, row, col);
            }
            else if(col == 2){
              cells[row][col].y = 16;
              cells[row][col].x = 15;
              cells[row][col].piece = whitePieces["WB1"] = whitePiecesArray[whitePieceCounter++] = new Piece("WB1", 15, 16, row, col);
            }
            else if(col == 3){
              cells[row][col].y = 16;
              cells[row][col].x = 20;
              cells[row][col].piece = whitePieces["WQ"] = whitePiecesArray[whitePieceCounter++] = new Piece("WQ", 20, 16, row, col);
            }
            else if(col == 4){
              cells[row][col].y = 16;
              cells[row][col].x = 25;
              cells[row][col].piece = whitePieces["WKc"] = whitePiecesArray[whitePieceCounter++] = new Piece("WKc", 25, 16, row, col);
            }
            else if(col == 5){
              cells[row][col].y = 16;
              cells[row][col].x = 30;
              cells[row][col].piece = whitePieces["WB2"] = whitePiecesArray[whitePieceCounter++] = new Piece("WB2", 30, 16, row, col);
            }
            else if(col == 6){
              cells[row][col].y = 16;
              cells[row][col].x = 35;
              cells[row][col].piece = whitePieces["WN2"] = whitePiecesArray[whitePieceCounter++] = new Piece("WN2", 35, 16, row, col);
            }
            else if(col == 7){
              cells[row][col].y = 16;
              cells[row][col].x = 40;
              cells[row][col].piece = whitePieces["WR2c"] = whitePiecesArray[whitePieceCounter++] = new Piece("WR2c", 40, 16, row, col);
            }
          }

          else if(row == 1){
            cells[row][col].y = 4;
            cells[row][col].x = 5 + (5 * col);
            cells[row][col].piece = blackPieces["BP" + to_string(col + 1)] = blackPiecesArray[blackPieceCounter++] = new Piece("BP" + to_string(col + 1), 5 + (5 * col), 4, row, col);
          }

          else if(row == 6){
            cells[row][col].y = 14;
            cells[row][col].x = 5 + (5 * col);
            cells[row][col].piece = blackPieces["WP" + to_string(col + 1)] = whitePiecesArray[whitePieceCounter++] = new Piece("WP" + to_string(col + 1), 5 + (5 * col), 14, row, col);
          }
        }
        cells[row][col].row = row;
        cells[row][col].col = col;
      }
    }


  }
  Board::~Board(){
    for (int i = 0; i < 16; ++i) {
        if (whitePiecesArray[i]) { delete whitePiecesArray[i]; whitePiecesArray[i] = nullptr; }
        if (blackPiecesArray[i]) { delete blackPiecesArray[i]; blackPiecesArray[i] = nullptr; }
    }
    whitePieces.clear();
    blackPieces.clear();
  }
  void Board::showEmptyBoard(){
    this -> display =
    "      A    B    C    D    E    F    G    H     \n   =========================================   \n8 || "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" || 8\n  ||---------------------------------------||  \n7 || "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" || 7\n  ||---------------------------------------||  \n6 || "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" || 6\n  ||---------------------------------------||  \n5 || "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" || 5\n  ||---------------------------------------||  \n4 || "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" || 4\n  ||---------------------------------------||  \n3 || "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" || 3\n  ||---------------------------------------||  \n2 || "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" || 2\n  ||---------------------------------------||  \n1 || "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" | "+myutils::CELL_STYLE+" || 1\n   =========================================   \n      A    B    C    D    E    F    G    H     ";
    cout << this -> display;
  }

  void Board::renderInitial(){
    this -> showEmptyBoard();
    COORD currPos= myutils::getCursorPosition();
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        myutils::setCursorPosition(cells[i][j].x, cells[i][j].y);
        if(cells[i][j].piece){
          string idd = cells[i][j].piece -> id;
          while(idd.size() > 2){
            idd.pop_back();
          }
          cout << idd;
        }
        else{
          continue;
        }
      }
    }
    myutils::setCursorPosition(currPos.X, currPos.Y);
    
  }
  void Board::renderDifficultySettings(){
    cout << "\n\n";
    cout << "Select Difficulty (Use Arrow Keys) :\n1. Easy    <<--\n2. Medium\n3. Hard";
  }
  void Board::renderBracks(Cell& c){
    COORD currPos = myutils::getCursorPosition();
    myutils::setCursorPosition(c.x - 1, c.y);
    cout << "[";
    if(!c.piece) cout << myutils::CELL_STYLE;
    else{
      string idd = c.piece -> id;
      while(idd.size() > 2) idd.pop_back();
      cout << idd;
    }
    cout << "]";
    myutils::setCursorPosition(currPos.X, currPos.Y);
  }
  void Board::removeBracks(Cell& c){
    COORD currPos = myutils::getCursorPosition();
    myutils::setCursorPosition(c.x - 1, c.y);
    cout << " ";
    myutils::setCursorPosition(c.x + 2, c.y);
    cout << " ";
    myutils::setCursorPosition(currPos.X, currPos.Y);
  }

  void Board::renderStars(Cell& c){
    COORD currPos = myutils::getCursorPosition();
    myutils::setCursorPosition(c.x - 1, c.y);
    cout << "*";
    if(!c.piece) cout << myutils::CELL_STYLE;
    else{
      string idd = c.piece -> id;
      while(idd.size() > 2) idd.pop_back();
      cout << idd;
    }
    cout << "*";
    myutils::setCursorPosition(currPos.X, currPos.Y);
  }
  void Board::removeStars(Cell& c){
    COORD currPos = myutils::getCursorPosition();
    myutils::setCursorPosition(c.x - 1, c.y);
    cout << " ";
    myutils::setCursorPosition(c.x + 2, c.y);
    cout << " ";
    myutils::setCursorPosition(currPos.X, currPos.Y);
  }

  void Board::renderPossibleMoves(Piece*& piece){
    for(int row = 0; row <= 7; row++){
      for(int col = 0; col <= 7; col++){
        if(piece -> validMoveCells[row][col]){
          renderStars(this -> cells[row][col]);
        }
      }
    }
  }
  void Board::removePossibleMoves(Piece*& piece){
    for(int row = 0; row <= 7; row++){
      for(int col = 0; col <= 7; col++){
        if(piece -> validMoveCells[row][col]){
          removeStars(this -> cells[row][col]);
        }
      }
    }
  }

  void Board::renderEmptyCell(Cell& c){
    COORD currPos = myutils::getCursorPosition();
    myutils::setCursorPosition(c.x - 1, c.y);
    cout << " "+myutils::CELL_STYLE+" ";
    myutils::setCursorPosition(currPos.X, currPos.Y);
  }

  void Board::renderCell(Cell& c){
    COORD currPos = myutils::getCursorPosition();
    myutils::setCursorPosition(c.x - 1, c.y);
    cout << " ";
    if(!c.piece) cout << myutils::CELL_STYLE;
    else{
      string idd = c.piece -> id;
      while(idd.size() > 2) idd.pop_back();
      cout << idd;
    }
    cout << " ";
    myutils::setCursorPosition(currPos.X, currPos.Y);
  }
  Cell Board::selectCell(int row, int col, bool pieceSelected, bool& running){
    int inp = -1;
    if(!pieceSelected && cells[row][col].piece) renderPossibleMoves(cells[row][col].piece);
    renderBracks(cells[row][col]);
    while(inp != 13){
      inp = _getch();
      int prevRow = row;
      int prevCol = col;
      if(inp == 224 || inp == 0){
        inp = _getch();

        switch(inp){
          case 72: // Up Arrow
            if(row == 0) row = 7;
            else row--;

            break;

          case 80: // Down Arrow
            if(row == 7) row = 0;
            else row++;
            break;

          case 75: // Left Arrow
            if(col == 0) col = 7;
            else col--;
            break;
          
          case 77: // Right Arrow
            if(col == 7) col = 0;
            else col++;
            break;
        }
        if(cells[prevRow][prevCol].piece) removePossibleMoves(cells[prevRow][prevCol].piece);
        removeBracks(cells[prevRow][prevCol]);
        renderBracks(cells[row][col]);
        if(!pieceSelected && cells[row][col].piece) renderPossibleMoves(cells[row][col].piece);
        
      }
      else if(pieceSelected && inp == 'x'){
        removeBracks(cells[prevRow][prevCol]);
        Cell c;
        c.row = -1;
        c.col = -1;
        return c;
      }

      else if(inp == 27){
        running = false;
        return cells[row][col];
      }
    }

    return cells[row][col];
  }

  bool Board::isNotAPiece(Cell& c){
    return !c.piece;
  }

  void Board::generateValidMovesForAll(){
    for(int i = 0; i < 16; i++){
      this -> blackPiecesArray[i] -> generateValidMove(this -> cells, whitePiecesArray, blackPiecesArray);
      this -> whitePiecesArray[i] -> generateValidMove(this -> cells, whitePiecesArray, blackPiecesArray);
    }
  }

  bool Board::isKingCastling(Piece* piece, Cell& toMoveTo){
    if(toMoveTo.col - piece -> col == 2 || toMoveTo.col - piece -> col == -2) return true;
    else return false;
  }

  bool Board::isLeftCastle(Piece* piece, Cell& toMoveTo){
    if(toMoveTo.col - piece -> col == -2) return true;
    else return false;
  }

  bool Board::isADiagonalAdjCell(Piece* piece, Cell& cell){
    if(piece -> row - cell.row == 1 && piece -> col - cell.col == 1) return true;
    else if(piece -> row - cell.row == 1 && piece -> col - cell.col == -1) return true;
    else if(piece -> row - cell.row == -1 && piece -> col - cell.col == -1) return true;
    else if(piece -> row - cell.row == -1 && piece -> col - cell.col == 1) return true;
    else return false;
  }
  bool Board::isPawnDoingEnPassantMove(Piece* piece, Cell& toMoveTo){
    if(!this -> cells[toMoveTo.row][toMoveTo.col].piece && int(abs(toMoveTo.col - piece -> col)) == int(abs(toMoveTo.row - piece -> row))){
      //cout << "returned true";
      return true;
    }
    else{
      //cout << "returned false";
      return false;
    }
    // if(toMoveTo.col != piece -> col && !this -> cells[toMoveTo.row][toMoveTo.col].piece){
    //   cout << "returned true";
    //   return true;
    // }

    // if(!this -> cells[toMoveTo.row][toMoveTo.col].piece && this -> isADiagonalAdjCell(piece, this -> cells[toMoveTo.row][toMoveTo.col])){
      
    //   return true;
    // }
    // else {
    //   //cout << "returned false";
    //   return false;
    // }
  }

  int Board::sumRemBlackPiecesWeight(){
    int sum = 0;
    for(int i = 0; i < 16; i++){
      if(this -> blackPiecesArray[i] -> row < 0){
        continue;
      }
      else{
        sum += this -> blackPiecesArray[i] -> weight;
      }
    }
    return sum;
  }

  int Board::sumRemWhitePiecesWeight(){
    int sum = 0;
    for(int i = 0; i < 16; i++){
      if(this -> whitePiecesArray[i] -> row < 0){
        continue;
      }
      else{
        sum += this -> whitePiecesArray[i] -> weight;
      }
    }
    return sum;
  }

  void Board::movePiece(Piece* piece, Cell& toMoveTo){


    // Giving and taking En Passant ability
    if(piece -> id[1] =='P'){
      if(toMoveTo.row - piece -> row == 2 || toMoveTo.row - piece -> row == -2) piece -> id += 'E';
      else{
        if(piece -> id.back() == 'E') piece -> id.pop_back();
      }
    }

    //Removing castle ability
    if(piece -> id[1] == 'K' && piece -> id.size() > 2 && piece -> id[2] == 'c'){
      piece -> id.erase(2, 1);
    }
    else if(piece -> id[1] == 'R' && piece -> id.size() > 3){
      piece -> id.pop_back();
    }

    if(piece -> id[1] == 'K' && isKingCastling(piece, toMoveTo)){
      int currRow = piece -> row;
      if(isLeftCastle(piece, toMoveTo)){
        this -> cells[currRow][0].piece -> col = 3;
        this -> cells[currRow][3].piece = this -> cells[currRow][0].piece;
        this -> renderCell(this -> cells[currRow][3]);
        this -> cells[currRow][0].piece = nullptr;
        this -> renderEmptyCell(this -> cells[currRow][0]);

        this -> cells[currRow][4].piece -> col = 2;
        this -> cells[currRow][2].piece = this -> cells[currRow][4].piece;
        this -> renderCell(this -> cells[currRow][2]);
        this -> cells[currRow][4].piece = nullptr;
        this -> renderEmptyCell(this -> cells[currRow][4]);

      }
      else{
        this -> cells[currRow][7].piece -> col = 5;
        this -> cells[currRow][5].piece = this -> cells[currRow][7].piece;
        this -> renderCell(this -> cells[currRow][5]);
        this -> cells[currRow][7].piece = nullptr;
        this -> renderEmptyCell(this -> cells[currRow][7]);
        

        this -> cells[currRow][4].piece -> col = 6;
        this -> cells[currRow][6].piece = this -> cells[currRow][4].piece;
        this -> renderCell(this -> cells[currRow][6]);
        this -> cells[currRow][4].piece = nullptr;
        this -> renderEmptyCell(this -> cells[currRow][4]);
      }
      
      //Checking if the opposite king is in check because of our king or rook
      this -> generateValidMovesForAll();
      return;
    }

    //Checking if we took a enemy piece
    if(this -> cells[toMoveTo.row][toMoveTo.col].piece){
      this -> cells[toMoveTo.row][toMoveTo.col].piece -> row = -1;
      this -> cells[toMoveTo.row][toMoveTo.col].piece -> col = -1;
      if(this -> cells[toMoveTo.row][toMoveTo.col].piece -> id[0] == 'B'){
        this -> remBlackPieceWeight -= this -> cells[toMoveTo.row][toMoveTo.col].piece -> weight;
      }
      else{
        this -> remWhitePieceWeight -= this -> cells[toMoveTo.row][toMoveTo.col].piece -> weight;
      }
      //this -> cells[toMoveTo.row][toMoveTo.col].piece -> generateValidMove(this -> cells, this -> whitePiecesArray, this -> blackPiecesArray);
    }

    this -> cells[piece -> row][piece -> col].piece = nullptr;
    this -> renderEmptyCell(this -> cells[piece -> row][piece -> col]);
    


   
    // Checking if the piece is pawn and is doing En Passant
    if(piece -> id[1] == 'P' && this -> isPawnDoingEnPassantMove(piece, toMoveTo)){
      //cout << "Doing en passant";
      int capturedPawnCol = toMoveTo.col;
      int capturedPawnRow = piece -> row;
      if(this -> cells[capturedPawnRow][capturedPawnCol].piece -> id[0] == 'B'){
        this -> remBlackPieceWeight -= this -> cells[capturedPawnRow][capturedPawnCol].piece -> weight;
      }
      else{
        this -> remWhitePieceWeight -= this -> cells[capturedPawnRow][capturedPawnCol].piece -> weight;
      }
      this -> cells[capturedPawnRow][capturedPawnCol].piece -> row = -1;
      this -> cells[capturedPawnRow][capturedPawnCol].piece -> col = -1;
      this -> cells[capturedPawnRow][capturedPawnCol].piece = nullptr;
      this -> renderEmptyCell(this -> cells[capturedPawnRow][capturedPawnCol]);
    }
    
    //Update piece position in piece
    this -> cells[toMoveTo.row][toMoveTo.col].piece = piece;
    piece -> row = toMoveTo.row;
    piece -> col = toMoveTo.col;

    

    // Checking if the piece was pawn  and if it reached last row and can now promote
    if(piece -> id[1] == 'P' && (piece -> row % 7 == 0)){
      if(piece -> id[0] == 'B'){
        piece -> id = string(1, piece -> id[0]) + "Q" + to_string(++this -> convertedPieceCounter);
        piece -> weight = 9;
        this -> remBlackPieceWeight += (piece -> weight - 1);
      }
      else{
        char pr = this -> renderPromotionSettings();
        switch(pr){
          case 'R':
            piece -> id = string(1, piece -> id[0]) + "R" + to_string(++this -> convertedPieceCounter);
            piece -> weight = 5;
            break;
          case 'N':
            piece -> id = string(1, piece -> id[0]) + "N" + to_string(++this -> convertedPieceCounter);
            piece -> weight = 3;
          case 'B':
            piece -> id = string(1, piece -> id[0]) + "B" + to_string(++this -> convertedPieceCounter);
            piece -> weight = 3;
            break;
          case 'Q':
            piece -> id = string(1, piece -> id[0]) + "Q" + to_string(++this -> convertedPieceCounter);
            piece -> weight = 9;
            break;
        }
        if(piece -> id[0] == 'B'){
          this -> remBlackPieceWeight += (piece -> weight - 1);
        }
        else{
          this -> remWhitePieceWeight += (piece -> weight - 1);
        }
      }
      
    }

    
    
    this -> renderCell(this -> cells[toMoveTo.row][toMoveTo.col]);

    

    this -> generateValidMovesForAll();
    this -> generateValidMovesForAll();
    //piece -> generateValidMove(this -> cells, this -> whitePiecesArray, this -> blackPiecesArray);
  }

  void Board::movePieceNoRender(Piece* piece, Cell& toMoveTo){


    // Giving and taking En Passant ability
    if(piece -> id[1] =='P'){
      if(toMoveTo.row - piece -> row == 2 || toMoveTo.row - piece -> row == -2) piece -> id += 'E';
      else{
        if(piece -> id.back() == 'E') piece -> id.pop_back();
      }
    }

    //Removing castle ability
    if(piece -> id[1] == 'K' && piece -> id.size() > 2 && piece -> id[2] == 'c'){
      piece -> id.erase(2, 1);
    }
    else if(piece -> id[1] == 'R' && piece -> id.size() > 3){
      piece -> id.pop_back();
    }

    if(piece -> id[1] == 'K' && isKingCastling(piece, toMoveTo)){
      int currRow = piece -> row;
      if(isLeftCastle(piece, toMoveTo)){
        this -> cells[currRow][0].piece -> col = 3;
        this -> cells[currRow][3].piece = this -> cells[currRow][0].piece;
        //this -> renderCell(this -> cells[currRow][3]);
        this -> cells[currRow][0].piece = nullptr;
        //this -> renderEmptyCell(this -> cells[currRow][0]);

        this -> cells[currRow][4].piece -> col = 2;
        this -> cells[currRow][2].piece = this -> cells[currRow][4].piece;
        //this -> renderCell(this -> cells[currRow][2]);
        this -> cells[currRow][4].piece = nullptr;
        //this -> renderEmptyCell(this -> cells[currRow][4]);

      }
      else{
        this -> cells[currRow][7].piece -> col = 5;
        this -> cells[currRow][5].piece = this -> cells[currRow][7].piece;
        //this -> renderCell(this -> cells[currRow][5]);
        this -> cells[currRow][7].piece = nullptr;
        //this -> renderEmptyCell(this -> cells[currRow][7]);
        

        this -> cells[currRow][4].piece -> col = 6;
        this -> cells[currRow][6].piece = this -> cells[currRow][4].piece;
        //this -> renderCell(this -> cells[currRow][6]);
        this -> cells[currRow][4].piece = nullptr;
        //this -> renderEmptyCell(this -> cells[currRow][4]);
      }
      
      //Checking if the opposite king is in check because of our king or rook
      this -> generateValidMovesForAll();
      this -> generateValidMovesForAll();
      return;
    }

    //Checking if we took an emeny piece
    if(this -> cells[toMoveTo.row][toMoveTo.col].piece){
      this -> cells[toMoveTo.row][toMoveTo.col].piece -> row = -1;
      this -> cells[toMoveTo.row][toMoveTo.col].piece -> col = -1;
      if(this -> cells[toMoveTo.row][toMoveTo.col].piece -> id[0] == 'B'){
        this -> remBlackPieceWeight -= this -> cells[toMoveTo.row][toMoveTo.col].piece -> weight;
      }
      else{
        this -> remWhitePieceWeight -= this -> cells[toMoveTo.row][toMoveTo.col].piece -> weight;
      }
      //this -> cells[toMoveTo.row][toMoveTo.col].piece -> generateValidMove(this -> cells, this -> whitePiecesArray, this -> blackPiecesArray);
    }

    this -> cells[piece -> row][piece -> col].piece = nullptr;
    //this -> renderEmptyCell(this -> cells[piece -> row][piece -> col]);
    


   
    // Checking if the piece is pawn and is doing En Passant
    if(piece -> id[1] == 'P' && this -> isPawnDoingEnPassantMove(piece, toMoveTo)){
      //cout << "Doing en passant";
      int capturedPawnCol = toMoveTo.col;
      int capturedPawnRow = piece -> row;
      if(this -> cells[capturedPawnRow][capturedPawnCol].piece -> id[0] == 'B'){
        this -> remBlackPieceWeight -= this -> cells[capturedPawnRow][capturedPawnCol].piece -> weight;
      }
      else{
        this -> remWhitePieceWeight -= this -> cells[capturedPawnRow][capturedPawnCol].piece -> weight;
      }
      this -> cells[capturedPawnRow][capturedPawnCol].piece -> row = -1;
      this -> cells[capturedPawnRow][capturedPawnCol].piece -> col = -1;
      this -> cells[capturedPawnRow][capturedPawnCol].piece = nullptr;
      //this -> renderEmptyCell(this -> cells[capturedPawnRow][capturedPawnCol]);
    }
    this -> cells[toMoveTo.row][toMoveTo.col].piece = piece;
    piece -> row = toMoveTo.row;
    piece -> col = toMoveTo.col;

    

    // Checking if the piece was pawn  and if it reached last row and can now promote
    if(piece -> id[1] == 'P' && (piece -> row % 7 == 0)){
      // char pr = this -> renderPromotionSettings();
      // switch(pr){
      //   case 'R':
      //     piece -> id = string(1, piece -> id[0]) + "R" + to_string(++this -> convertedPieceCounter);
      //     piece -> weight = 5;
      //     break;
      //   case 'N':
      //     piece -> id = string(1, piece -> id[0]) + "N" + to_string(++this -> convertedPieceCounter);
      //     piece -> weight = 3;
      //   case 'B':
      //     piece -> id = string(1, piece -> id[0]) + "B" + to_string(++this -> convertedPieceCounter);
      //     piece -> weight = 3;
      //     break;
      //   case 'Q':
      //     piece -> id = string(1, piece -> id[0]) + "Q" + to_string(++this -> convertedPieceCounter);
      //     piece -> weight = 9;
      //     break;
      // }
      piece -> id = string(1, piece -> id[0]) + "Q" + to_string(++this -> convertedPieceCounter);
      piece -> weight = 9;
      if(piece -> id[0] == 'B'){
        this -> remBlackPieceWeight += (piece -> weight - 1);
      }
      else{
        this -> remWhitePieceWeight += (piece -> weight - 1);
      }
    }

    
    
    //this -> renderCell(this -> cells[toMoveTo.row][toMoveTo.col]);

    

    this -> generateValidMovesForAll();
    //piece -> generateValidMove(this -> cells, this -> whitePiecesArray, this -> blackPiecesArray);
  }
  

  char Board::renderPromotionSettings(){
    COORD currPos = myutils::getCursorPosition();
    cout << "\n";
    cout << "Choose Promotion (Use Arrow Keys) :\n1. Rook    <<--\n2. Knight\n3. Bishop\n4. Queen";
    char pr = this -> selectPromotion('R');
    myutils::setCursorPosition(currPos.X, currPos.Y);
    cout << "\n                                    \n                  \n                  \n                  \n                  ";
    myutils::setCursorPosition(currPos.X, currPos.Y);
    return pr;
  }
  
  char Board::selectPromotion(char pr){
    char selected = pr;
    int inp = -1;
    COORD currPos= myutils::getCursorPosition();


    while(inp != 13){
      inp = _getch();
      if (inp == 224 || inp == 0) {
        inp = _getch();
        
        switch(inp) {
            case 72: // Up arrow
                if (selected == 'R'){
                  myutils::setCursorPosition(11, 21);
                  cout << "    ";
                  myutils::setCursorPosition(11, 24);
                  cout << "<<--";
                  selected = 'Q';
                }
                else if(selected == 'N'){
                  myutils::setCursorPosition(11, 22);
                  cout << "    ";
                  myutils::setCursorPosition(11, 21);
                  cout << "<<--";
                  selected = 'R';
                }
                else if(selected == 'B'){
                  myutils::setCursorPosition(11, 23);
                  cout << "    ";
                  myutils::setCursorPosition(11, 22);
                  cout << "<<--";
                  selected = 'N';
                }
                else if(selected == 'Q'){
                  myutils::setCursorPosition(11, 24);
                  cout << "    ";
                  myutils::setCursorPosition(11, 23);
                  cout << "<<--";
                  selected = 'B';
                }
                break;
            case 80: // Down arrow
                if (selected == 'R'){
                  myutils::setCursorPosition(11, 21);
                  cout << "    ";
                  myutils::setCursorPosition(11, 22);
                  cout << "<<--";
                  selected = 'N';

                }
                else if(selected == 'N'){
                  myutils::setCursorPosition(11, 22);
                  cout << "    ";
                  myutils::setCursorPosition(11, 23);
                  cout << "<<--";
                  selected = 'B';
                }
                else if(selected == 'B'){
                  myutils::setCursorPosition(11, 23);
                  cout << "    ";
                  myutils::setCursorPosition(11, 24);
                  cout << "<<--";
                  selected = 'Q';
                }else if(selected == 'Q'){
                  myutils::setCursorPosition(11, 24);
                  cout << "    ";
                  myutils::setCursorPosition(11, 21);
                  cout << "<<--";
                  selected = 'R';
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

  bool Board::isItBlack(Piece* piece){
    if(piece -> id[0] == 'B') return true;
    else return false;
  }

  bool Board::isWhiteKingInTrouble(Piece* piece){
    // if(!this -> whitePieces["WKc"] -> hasValidMoves()){
    //   if(piece -> validMoveCells[this -> whitePieces["WKc"] -> row][this -> whitePieces["WKc"] -> col]){
    //     COORD currPos = myutils::getCursorPosition();
    //     cout << "\n\n\nBlack Won!!!\nPress any key to get back to main menu...";
    //     _getch();
    //     myutils::setCursorPosition(currPos.X, currPos.Y);
    //     return true;
    //   }
    //   else if(isNoValidMoveForWhite()){
    //     COORD currPos = myutils::getCursorPosition();
    //     cout << "\n\n\nDraw - Stalemate!!!\nPress any key to get back to main menu...";
    //     _getch();
    //     myutils::setCursorPosition(currPos.X, currPos.Y);
    //     return true;
    //   }
    // }
    // else{
    //   // if(piece -> validMoveCells[this -> whitePieces["WKc"] -> row][this -> whitePieces["WKc"] -> col]){
    //   //   this -> negateWhiteValidMoves();
    //   // }
    // }
    this -> isWhiteKingInCheck(piece);

    if(this -> whitePieces["WKc"] -> row < 0){
      COORD currPos = myutils::getCursorPosition();
      cout << "\n\n\nBlack Won!!!\nPress any key to get back to main menu...";
      _getch();
      myutils::setCursorPosition(currPos.X, currPos.Y);
      return true;
    }
    else{
      if(isNoValidMoveForWhite()){
        COORD currPos = myutils::getCursorPosition();
        cout << "\n\n\nDraw - Stalemate!!!\nPress any key to get back to main menu...";
        _getch();
        myutils::setCursorPosition(currPos.X, currPos.Y);
        return true;
      }
    }
    return false;
  }

  void Board::isWhiteKingInCheck(Piece* piece){
    if(piece -> validMoveCells[this -> whitePiecesArray[4] -> row][this -> whitePiecesArray[4] -> col]){
      COORD currPos = myutils::getCursorPosition();
      cout << "\n\nWhite king is in check...";
      myutils::setCursorPosition(currPos.X, currPos.Y);
      // cout << "\n\n                              ";
      // myutils::setCursorPosition(currPos.X, currPos.Y);
    }
    else return;
  }
  void Board::isBlackKingInCheck(Piece* piece){
    if(piece -> validMoveCells[this -> blackPiecesArray[4] -> row][this -> blackPiecesArray[4] -> col]){
      COORD currPos = myutils::getCursorPosition();
      cout << "\n\nBlack king is in check...";
      myutils::setCursorPosition(currPos.X, currPos.Y);
      // cout << "\n\n                              ";
      // myutils::setCursorPosition(currPos.X, currPos.Y);
    }
    else return;
  }

  bool Board::isNoValidMoveForBlack(){
    for(int i = 0; i < 16; i++){
      if(this -> blackPiecesArray[i] -> hasValidMoves()) return false;
    }
    return true;
  }

  bool Board::isNoValidMoveForWhite(){
    for(int i = 0; i < 16; i++){
      if(this -> whitePiecesArray[i] -> hasValidMoves()) return false;
    }
    return true;
  }

  bool Board::isPieceInside(Piece* piece){
    if(piece -> row >= 0 && piece -> row <= 7 && piece -> col >= 0 && piece -> col <= 7) return true;
    else return false;
  }
  
  void Board::negateBlackValidMoves(){
    for(int i = 0; i < 16; i++){
      if(i == 4) continue;
      memset(this -> blackPiecesArray[i] -> validMoveCells, 0, sizeof(this -> blackPiecesArray[i] -> validMoveCells));  // 0 == false
      this -> blackPiecesArray[i] -> numOfValidMoves = 0;
    }
  }

  void Board::negateWhiteValidMoves(){
    for(int i = 0; i < 16; i++){
      if(i == 4) continue;
      memset(this -> whitePiecesArray[i] -> validMoveCells, 0, sizeof(this -> whitePiecesArray[i] -> validMoveCells));  // 0 == false
      this -> whitePiecesArray[i] -> numOfValidMoves = 0;
    }
  }
  
  bool Board::isBlackKingInTrouble(Piece* piece){
    // //Debugging start
    // if(piece -> row == 1){
    //   cout << "The black king has valid moves : " << this -> blackPieces["BKc"] -> hasValidMoves() << endl;
    // }
    // //Debugging end

    //if(this -> blackPieces["BKc"] -> row <)

    this -> isBlackKingInCheck(piece);

    if(this -> blackPieces["BKc"] -> row < 0){
      COORD currPos = myutils::getCursorPosition();
      cout << "\n\n\nWhite Won!!!\nPress any key to get back to main menu...";
      _getch();
      myutils::setCursorPosition(currPos.X, currPos.Y);
      return true;
    }
    else{
      if(isNoValidMoveForBlack()){
        COORD currPos = myutils::getCursorPosition();
        cout << "\n\n\nDraw - Stalemate!!!\nPress any key to get back to main menu...";
        _getch();
        myutils::setCursorPosition(currPos.X, currPos.Y);
        return true;
      }
    }
    // if(!this -> blackPieces["BKc"] -> hasValidMoves()){
    //   if(piece -> validMoveCells[this -> blackPieces["BKc"] -> row][this -> blackPieces["BKc"] -> col]){
    //     COORD currPos = myutils::getCursorPosition();
    //     cout << "\n\n\nWhite Won!!!\nPress any key to get back to main menu...";
    //     _getch();
    //     myutils::setCursorPosition(currPos.X, currPos.Y);
    //     return true;
    //   }
    //   else if(isNoValidMoveForBlack()){
    //     COORD currPos = myutils::getCursorPosition();
    //     cout << "\n\n\nDraw - Stalemate!!!\nPress any key to get back to main menu...";
    //     _getch();
    //     myutils::setCursorPosition(currPos.X, currPos.Y);
    //     return true;
    //   }
    // }
    // else{
    //   // if(piece -> validMoveCells[this -> blackPieces["BKc"] -> row][this -> blackPieces["BKc"] -> col]){
    //   //   this -> negateBlackValidMoves();
    //   // }
    // }
    
    return false;
  }

  bool Board::allowBlackPiecesThatResolveCheck(Piece* piece){
    bool ans = false;
    for(int i = 0; i < 16; i++){
      Piece* p = this -> blackPiecesArray[i];
      if(!p -> validMoveCells[piece -> row][piece -> col]){
        memset(p -> validMoveCells, 0, sizeof(p-> validMoveCells));  // 0 == false
        p -> numOfValidMoves = 0;
      }
      else ans = true;
    }
    return ans;
  }

  bool Board::isDrawByInsufficientMaterial(){
    bool ans = false;
    for(int i = 0; i < 16; i++){
      if(i == 1 || i == 2 || i == 4 || i == 5 || i == 6){
        continue;
      }
      if(isPieceInside(this -> blackPiecesArray[i]) || isPieceInside(this -> whitePiecesArray[i])) return false;
    }

    
      if(isPieceInside(this -> blackPiecesArray[4]) && isPieceInside(this -> whitePiecesArray[4])){
        //if Only Both The Kings Remain
        if(!isPieceInside(this -> blackPiecesArray[2]) && !isPieceInside(this -> whitePiecesArray[2]) && !isPieceInside(this -> blackPiecesArray[5]) && !isPieceInside(this -> whitePiecesArray[5]) && !isPieceInside(this -> blackPiecesArray[1]) && !isPieceInside(this -> whitePiecesArray[1]) && !isPieceInside(this -> blackPiecesArray[6]) && !isPieceInside(this -> whitePiecesArray[6])){
          ans = true;
        }
        //If One Bishop And Both The Kings Remain
        if(isPieceInside(this -> blackPiecesArray[2]) + isPieceInside(this -> whitePiecesArray[2]) + isPieceInside(this -> blackPiecesArray[5]) + isPieceInside(this -> whitePiecesArray[5]) == 1 && !isPieceInside(this -> blackPiecesArray[1]) && !isPieceInside(this -> whitePiecesArray[1]) && !isPieceInside(this -> blackPiecesArray[6]) && !isPieceInside(this -> whitePiecesArray[6])){
          ans = true;
        }
        //If One Knight And Both The Kings Remain
        if(isPieceInside(this -> blackPiecesArray[1]) + isPieceInside(this -> whitePiecesArray[1]) + isPieceInside(this -> blackPiecesArray[6]) + isPieceInside(this -> whitePiecesArray[6]) == 1 && !isPieceInside(this -> blackPiecesArray[2]) && !isPieceInside(this -> whitePiecesArray[2]) && !isPieceInside(this -> blackPiecesArray[5]) && !isPieceInside(this -> whitePiecesArray[5])){
          ans = true;
        }
        //If Both Bishops(Of Same Color Squares) And Bothe The Kings Remain
        if(((isPieceInside(this -> blackPiecesArray[2]) && isPieceInside(this -> whitePiecesArray[5]) && !isPieceInside(this -> blackPiecesArray[5]) && !isPieceInside(this -> whitePiecesArray[2])) || (isPieceInside(this -> blackPiecesArray[5]) && isPieceInside(this -> whitePiecesArray[2]) && !isPieceInside(this -> blackPiecesArray[2]) && !isPieceInside(this -> whitePiecesArray[5]))) && !isPieceInside(this -> blackPiecesArray[1]) && !isPieceInside(this -> whitePiecesArray[1]) && !isPieceInside(this -> blackPiecesArray[6]) && !isPieceInside(this -> whitePiecesArray[6])){
          ans = true;
        }
      }

      if(ans){
        COORD currPos = myutils::getCursorPosition();
        cout << "\n\n\nDraw - By Insufficient Material!!!\nPress any key to get back to main menu...";
        _getch();
        myutils::setCursorPosition(currPos.X, currPos.Y);
        return true;
      }
      return false;
  }

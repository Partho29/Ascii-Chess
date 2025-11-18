#include <Cell.h>
#include <Piece.h>
#include <utils.h>
#include <string>
#include <cstring>
#include <iostream>
using std::string;



  Piece::Piece(string s, int x, int y, int r, int c) : pos(x, y), id(s), row(r), col(c) {
    // for(int i = 0; i < 8; i++){
    //   for(int j = 0; j < 8; j++){
    //     validMoveCells[i][j] = false;
    //   }
    // }
    switch(s[1]){
      case 'P':
        this -> weight = 1;
        break;
      case 'R':
        this -> weight = 5;
        break;
      case 'N':
        this -> weight = 3;
        break;
      case 'B':
        this -> weight = 3;
        break;
      case 'Q':
        this -> weight = 9;
        break;
      case 'K':
        this -> weight = 1000;
        break;
    }
    memset(this -> validMoveCells, 0, sizeof(this-> validMoveCells));  // 0 == false
    this -> numOfValidMoves = 0;
  }

  bool Piece::isCurrPosValid(){
    if(this -> row >= 0 && this -> row <= 7 && this -> col >= 0 && this -> col <= 7) return true;
    else return false;
  }


  Piece::PieceID Piece::getPieceID(const std::string& id) {
    string idd = id;
    while(idd.size() > 2) idd.pop_back();
    if (idd == "WP") return WP;
    if (idd == "WR") return WR;
    if (idd == "WN") return WN;
    if (idd == "WB") return WB;
    if (idd == "WK") return WK;
    if (idd == "WQ") return WQ;
  
    if (idd == "BP") return BP;
    if (idd == "BR") return BR;
    if (idd == "BN") return BN;
    if (idd == "BB") return BB;
    if (idd == "BK") return BK;
    if (idd == "BQ") return BQ;

    return UNKNOWN;
  }

  void Piece::generateValidMove(Cell cells[][8], Piece* whitePiecesArray[], Piece* blackPiecesArray[]){
    memset(this -> validMoveCells, 0, sizeof(this-> validMoveCells));  // 0 == false
    this -> numOfValidMoves = 0;
    if(!this -> isCurrPosValid()){
      return;
    }
    int currRow = this -> row;
    int currCol = this -> col;
    int toRow;
    int toCol;
    switch(this -> getPieceID(this -> id)){
      // case WP1:
      // case WP2:
      // case WP3:
      // case WP4:
      // case WP5:
      // case WP6:
      // case WP7:
      case WP:
        //Forward Position
        toRow = currRow - 1;
        toCol = currCol;
        if(toRow >= 0 && !cells[toRow][toCol].piece){
          this->validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          //if(this -> id.back() == 'E') this -> id.pop_back();
        }

        //Double Forward Position
        toRow = currRow - 2;
        toCol = currCol;
        if(currRow == 6 && !cells[toRow + 1][toCol].piece && !cells[toRow][toCol].piece){
          this->validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          //this -> id += 'E';
        }

        //Left Diagonal Position
        toRow = currRow - 1;
        toCol = currCol - 1;
        if(toCol >= 0 && toRow >= 0 && ((cells[toRow][toCol].piece && cells[toRow][toCol].piece -> id[0] == 'B') || (currRow == 3 && !cells[toRow][toCol].piece && cells[toRow + 1][toCol].piece && cells[toRow + 1][toCol].piece -> id.back() == 'E' && cells[toRow + 1][toCol].piece -> id[0] == 'B'))){
          this->validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          //if(this -> id.back() == 'E') this -> id.pop_back();
        }

        //Right Diagonal Position
        toRow = currRow - 1;
        toCol = currCol + 1;
        if(toRow >= 0 && toCol <= 7 && ((cells[toRow][toCol].piece && cells[toRow][toCol].piece -> id[0] == 'B') || (currRow == 3 && !cells[toRow][toCol].piece && cells[toRow + 1][toCol].piece && cells[toRow + 1][toCol].piece -> id.back() == 'E' && cells[toRow + 1][toCol].piece -> id[0] == 'B'))){
          this->validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          //if(this -> id.back() == 'E') this -> id.pop_back();
        }
        break;
      // case BP1:
      // case BP2:
      // case BP3:
      // case BP4:
      // case BP5:
      // case BP6:
      // case BP7:
      case BP: 
        //Forward Position
        toRow = currRow + 1;
        toCol = currCol;
        if(toRow <= 7 && !cells[toRow][toCol].piece){
          this->validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          //if(this -> id.back() == 'E') this -> id.pop_back();
          //cout << "yes yes yes yes yes";
        }

        //Double Forward Position
        toRow = currRow + 2;
        toCol = currCol;
        if(currRow == 1 && !cells[toRow - 1][toCol].piece && !cells[toRow][toCol].piece){
          this->validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          //this -> id += 'E';
        }

        //Left Diagonal Position
        toRow = currRow + 1;
        toCol = currCol + 1;
        if(toCol <= 7 && toRow <= 7 && ((cells[toRow][toCol].piece && cells[toRow][toCol].piece -> id[0] == 'W') || (currRow == 4 && !cells[toRow][toCol].piece && cells[toRow - 1][toCol].piece && cells[toRow - 1][toCol].piece -> id.back() == 'E' && cells[toRow - 1][toCol].piece -> id[0] == 'W'))){
          this->validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          //if(this -> id.back() == 'E') this -> id.pop_back();
        }

        //Right Diagonal Position
        toRow = currRow + 1;
        toCol = currCol - 1;
        if(toRow <= 7 && toCol >= 0 && ((cells[toRow][toCol].piece && cells[toRow][toCol].piece -> id[0] == 'W') || (currRow == 4 && !cells[toRow][toCol].piece && cells[toRow - 1][toCol].piece && cells[toRow - 1][toCol].piece -> id.back() == 'E' && cells[toRow - 1][toCol].piece -> id[0] == 'W'))){
          this->validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          //if(this -> id.back() == 'E') this -> id.pop_back();
        }
        break;
      case WN:
        // Upper Left
        toRow = currRow - 2;
        toCol = currCol - 1;
        if(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Upper Right
        toRow = currRow - 2;
        toCol = currCol + 1;
        if(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Right Upper
        toRow = currRow - 1;
        toCol = currCol + 2;
        if(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Right Lower
        toRow = currRow + 1;
        toCol = currCol + 2;
        if(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        // Lower Left
        toRow = currRow + 2;
        toCol = currCol - 1;
        if(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Lower Right
        toRow = currRow + 2;
        toCol = currCol + 1;
        if(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Left Upper
        toRow = currRow - 1;
        toCol = currCol - 2;
        if(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Left Lower
        toRow = currRow + 1;
        toCol = currCol - 2;
        if(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }
        break;
      case BN:
        // Upper Left
        toRow = currRow - 2;
        toCol = currCol - 1;
        if(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Upper Right
        toRow = currRow - 2;
        toCol = currCol + 1;
        if(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Right Upper
        toRow = currRow - 1;
        toCol = currCol + 2;
        if(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Right Lower
        toRow = currRow + 1;
        toCol = currCol + 2;
        if(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        // Lower Left
        toRow = currRow + 2;
        toCol = currCol - 1;
        if(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Lower Right
        toRow = currRow + 2;
        toCol = currCol + 1;
        if(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Left Upper
        toRow = currRow - 1;
        toCol = currCol - 2;
        if(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Left Lower
        toRow = currRow + 1;
        toCol = currCol - 2;
        if(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }
        break;
      
      case WB:
        //Upper Left
        toRow = currRow - 1;
        toCol = currCol - 1;
        while(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow--;
          toCol--;
        }

        //Upper Right
        toRow = currRow - 1;
        toCol = currCol + 1;
        while(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow--;
          toCol++;
        }

        //Lower Left
        toRow = currRow + 1;
        toCol = currCol - 1;
        while(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow++;
          toCol--;
        }

        //Lower Right
        toRow = currRow + 1;
        toCol = currCol + 1;
        while(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow++;
          toCol++;
        }
        break;

      case BB:
        //Upper Left
        toRow = currRow - 1;
        toCol = currCol - 1;
        while(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow--;
          toCol--;
        }

        //Upper Right
        toRow = currRow - 1;
        toCol = currCol + 1;
        while(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow--;
          toCol++;
        }

        //Lower Left
        toRow = currRow + 1;
        toCol = currCol - 1;
        while(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow++;
          toCol--;
        }

        //Lower Right
        toRow = currRow + 1;
        toCol = currCol + 1;
        while(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow++;
          toCol++;
        }
        break;
      
      case WR:
        //Up
        toRow = currRow - 1;
        toCol = currCol;
        while(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow--;
        }

        //Down
        toRow = currRow + 1;
        toCol = currCol;
        while(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow++;
        }

        //Left
        toRow = currRow;
        toCol = currCol - 1;
        while(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toCol--;
        }

        //Right
        toRow = currRow;
        toCol = currCol + 1;
        while(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toCol++;
        }
        break;

      case BR:
        //Up
        toRow = currRow - 1;
        toCol = currCol;
        while(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow--;
        }

        //Down
        toRow = currRow + 1;
        toCol = currCol;
        while(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow++;
        }

        //Left
        toRow = currRow;
        toCol = currCol - 1;
        while(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toCol--;
        }

        //Right
        toRow = currRow;
        toCol = currCol + 1;
        while(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toCol++;
        }
        break;
      
      case WQ:
        //Upper Left
        toRow = currRow - 1;
        toCol = currCol - 1;
        while(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow--;
          toCol--;
        }

        //Upper Right
        toRow = currRow - 1;
        toCol = currCol + 1;
        while(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow--;
          toCol++;
        }

        //Lower Left
        toRow = currRow + 1;
        toCol = currCol - 1;
        while(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow++;
          toCol--;
        }

        //Lower Right
        toRow = currRow + 1;
        toCol = currCol + 1;
        while(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow++;
          toCol++;
        }

        //Up
        toRow = currRow - 1;
        toCol = currCol;
        while(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow--;
        }

        //Down
        toRow = currRow + 1;
        toCol = currCol;
        while(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow++;
        }

        //Left
        toRow = currRow;
        toCol = currCol - 1;
        while(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toCol--;
        }

        //Right
        toRow = currRow;
        toCol = currCol + 1;
        while(myutils::isValidToMove(toRow, toCol, 'B', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toCol++;
        }
        break;

      case BQ:
        //Upper Left
        toRow = currRow - 1;
        toCol = currCol - 1;
        while(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow--;
          toCol--;
        }

        //Upper Right
        toRow = currRow - 1;
        toCol = currCol + 1;
        while(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow--;
          toCol++;
        }

        //Lower Left
        toRow = currRow + 1;
        toCol = currCol - 1;
        while(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow++;
          toCol--;
        }

        //Lower Right
        toRow = currRow + 1;
        toCol = currCol + 1;
        while(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow++;
          toCol++;
        }

        //Up
        toRow = currRow - 1;
        toCol = currCol;
        while(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow--;
        }

        //Down
        toRow = currRow + 1;
        toCol = currCol;
        while(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toRow++;
        }

        //Left
        toRow = currRow;
        toCol = currCol - 1;
        while(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toCol--;
        }

        //Right
        toRow = currRow;
        toCol = currCol + 1;
        while(myutils::isValidToMove(toRow, toCol, 'W', cells)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          if(cells[toRow][toCol].piece) break;
          toCol++;
        }
        break;
      
      case WK:
        //Up
        toRow = currRow - 1;
        toCol = currCol;
        if(myutils::isValidToMove(toRow, toCol, 'B', cells) && myutils::isValidForKing(toRow, toCol, blackPiecesArray)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Down
        toRow = currRow + 1;
        toCol = currCol;
        if(myutils::isValidToMove(toRow, toCol, 'B', cells) && myutils::isValidForKing(toRow, toCol, blackPiecesArray)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Left
        toRow = currRow;
        toCol = currCol - 1;
        if(myutils::isValidToMove(toRow, toCol, 'B', cells) && myutils::isValidForKing(toRow, toCol, blackPiecesArray)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Right
        toRow = currRow;
        toCol = currCol + 1;
        if(myutils::isValidToMove(toRow, toCol, 'B', cells) && myutils::isValidForKing(toRow, toCol, blackPiecesArray)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Upper Left
        toRow = currRow - 1;
        toCol = currCol - 1;
        if(myutils::isValidToMove(toRow, toCol, 'B', cells) && myutils::isValidForKing(toRow, toCol, blackPiecesArray)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Upper Right
        toRow = currRow - 1;
        toCol = currCol + 1;
        if(myutils::isValidToMove(toRow, toCol, 'B', cells) && myutils::isValidForKing(toRow, toCol, blackPiecesArray)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Lower Left
        toRow = currRow + 1;
        toCol = currCol - 1;
        if(myutils::isValidToMove(toRow, toCol, 'B', cells) && myutils::isValidForKing(toRow, toCol, blackPiecesArray)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Lower Right
        toRow = currRow + 1;
        toCol = currCol + 1;
        if(myutils::isValidToMove(toRow, toCol, 'B', cells) && myutils::isValidForKing(toRow, toCol, blackPiecesArray)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          //cout << "Yes yes I did it..................ssjwjwjj";
        }

        //Castle For Later
        if(this -> id.size() > 2 && this -> id[2] == 'c'){
          toRow = currRow;
          //Right castle
          toCol = currCol + 1;
          //checking if right two positions are empty
          if(!cells[currRow][currCol + 1].piece && !cells[currRow][currCol + 2].piece){
            //checking if those two positions are not in check
            if(myutils::isValidForKing(currRow, toCol, blackPiecesArray) && myutils::isValidForKing(currRow, ++toCol, blackPiecesArray)){
              //Checking if rook is valid
              toCol++;
              if(cells[currRow][toCol].piece && (cells[currRow][toCol].piece -> id == "WR2c" || cells[currRow][toCol].piece -> id == "WR2")){
                this -> validMoveCells[toRow][toCol - 1] = true;
                this -> numOfValidMoves++;
              }
            }
          }

          //Left castle
          toCol = currCol - 1;
          //checking if all three left positins are empty
          if(!cells[currRow][currCol - 1].piece && !cells[currRow][currCol - 2].piece && !cells[currRow][currCol - 3].piece){
            //checking if those three positions are not in check
            if(myutils::isValidForKing(currRow, toCol, blackPiecesArray) && myutils::isValidForKing(currRow, --toCol, blackPiecesArray)){
              //Checking if rook is valid
              toCol -= 2;
              if(cells[currRow][toCol].piece && (cells[currRow][toCol].piece -> id == "WR1c" || cells[currRow][toCol].piece -> id == "WR1")){
                this -> validMoveCells[toRow][toCol + 2] = true;
                this -> numOfValidMoves++;
              }
            }
          }
        }
        break;

      case BK:
        //Up
        toRow = currRow - 1;
        toCol = currCol;
        if(myutils::isValidToMove(toRow, toCol, 'W', cells) && myutils::isValidForKing(toRow, toCol, whitePiecesArray)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Down
        toRow = currRow + 1;
        toCol = currCol;
        if(myutils::isValidToMove(toRow, toCol, 'W', cells) && myutils::isValidForKing(toRow, toCol, whitePiecesArray)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Left
        toRow = currRow;
        toCol = currCol - 1;
        if(myutils::isValidToMove(toRow, toCol, 'W', cells) && myutils::isValidForKing(toRow, toCol, whitePiecesArray)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Right
        toRow = currRow;
        toCol = currCol + 1;
        if(myutils::isValidToMove(toRow, toCol, 'W', cells) && myutils::isValidForKing(toRow, toCol, whitePiecesArray)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Upper Left
        toRow = currRow - 1;
        toCol = currCol - 1;
        if(myutils::isValidToMove(toRow, toCol, 'W', cells) && myutils::isValidForKing(toRow, toCol, whitePiecesArray)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Upper Right
        toRow = currRow - 1;
        toCol = currCol + 1;
        if(myutils::isValidToMove(toRow, toCol, 'W', cells) && myutils::isValidForKing(toRow, toCol, whitePiecesArray)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Lower Left
        toRow = currRow + 1;
        toCol = currCol - 1;
        if(myutils::isValidToMove(toRow, toCol, 'W', cells) && myutils::isValidForKing(toRow, toCol, whitePiecesArray)){
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
        }

        //Lower Right
        toRow = currRow + 1;
        toCol = currCol + 1;
        if(myutils::isValidToMove(toRow, toCol, 'W', cells) && myutils::isValidForKing(toRow, toCol, whitePiecesArray)){
          //cout << "Yes it is valid to move for king\n";
          
            //cout << "yes it is valid for king";
          this -> validMoveCells[toRow][toCol] = true;
          this -> numOfValidMoves++;
          
        }

        //Castle For Later
        if(this -> id.size() > 2 && this -> id[2] == 'c'){
          toRow = currRow;
          //Right castle
          toCol = currCol + 1;
          //checking if right two positions are empty
          if(!cells[currRow][currCol + 1].piece && !cells[currRow][currCol + 2].piece){
            //checking if those two positions are not in check
            if(myutils::isValidForKing(currRow, toCol, whitePiecesArray) && myutils::isValidForKing(currRow, ++toCol, whitePiecesArray)){
              //Checking if rook is valid
              toCol++;
              if(cells[currRow][toCol].piece && (cells[currRow][toCol].piece -> id == "BR2c" || cells[currRow][toCol].piece -> id == "BR2")){
                this -> validMoveCells[toRow][toCol - 1] = true;
                this -> numOfValidMoves++;
              }
            }
          }

          //Left castle
          toCol = currCol - 1;
          //checking if all three left positins are empty
          if(!cells[currRow][currCol - 1].piece && !cells[currRow][currCol - 2].piece && !cells[currRow][currCol - 3].piece){
            //checking if those three positions are not in check
            if(myutils::isValidForKing(currRow, toCol, whitePiecesArray) && myutils::isValidForKing(currRow, --toCol, whitePiecesArray)){
              //Checking if rook is valid
              toCol -= 2;
              if(cells[currRow][toCol].piece && (cells[currRow][toCol].piece -> id == "BR1c" || cells[currRow][toCol].piece -> id == "BR1")){
                this -> validMoveCells[toRow][toCol + 2] = true;
                this -> numOfValidMoves++;
              }
            }
          }
        }
        break;
    }
    
  }
 
  bool Piece::isValidMove(Cell& selectedCell){
    return this -> validMoveCells[selectedCell.row][selectedCell.col];

  }

  bool Piece::hasValidMoves(){
    if(this -> numOfValidMoves > 0) return true;
    else return false;
  }



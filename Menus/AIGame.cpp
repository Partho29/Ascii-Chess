#include <AIGame.h>
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
  
  
  AIGame::AIGame() : board(new Board()), running(false), AIDepth('0'){
    currCell.col = 0;
    currCell.row = 7;
  }
  AIGame::~AIGame(){
    delete board;
  }
  char AIGame::selectDifficulty(char diff){
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
  void AIGame::resetBoard(){
    Board* temp = board;
    board = new Board();
    delete temp;
    running = false;
    this -> currCell.col = 0;
    this -> currCell.row = 7;
  }

  
  Piece* AIGame::whiteMove(){
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
      // cout << "\nThe black king has : " << this -> board -> blackPieces["BKc"] ->numOfValidMoves << endl;
      // _getch();
      //board -> ifCastlingInvalid(piece);
    }
    myutils::setCursorPosition(currPos.X, currPos.Y);
    return piece;
  }


  Piece* AIGame::blackMove(){
    COORD currPos = myutils::getCursorPosition();
    
    string aiMove = this -> AIMove();
    
    // ERROR CHECK: Make sure AIMove returned valid data
    if(aiMove.length() != 4){
        cout << "AI Error: Invalid move generated";
        running = false;
        return nullptr;
    }
    
    int fromRow = aiMove[0] - '0';
    int fromCol = aiMove[1] - '0';
    int toRow = aiMove[2] - '0';
    int toCol = aiMove[3] - '0';
    
    // ANOTHER ERROR CHECK: Verify the coordinates are valid
    if(fromRow < 0 || fromRow > 7 || fromCol < 0 || fromCol > 7 ||
       toRow < 0 || toRow > 7 || toCol < 0 || toCol > 7){
        cout << "AI Error: Out of bounds move";
        running = false;
        return nullptr;
    }
    
    Piece* piece = this -> board -> cells[fromRow][fromCol].piece;
    
    if(piece == nullptr){
        cout << "AI Error: No piece at " << fromRow << "," << fromCol;
        running = false;
        return nullptr;
    }
    
    Cell selectedMoveCell = this -> board -> cells[toRow][toCol];
    board -> movePiece(piece, selectedMoveCell);
    this -> currCell.row = selectedMoveCell.row;
    this -> currCell.col = selectedMoveCell.col;
    myutils::setCursorPosition(currPos.X, currPos.Y);
    return piece;
  }

  

  // Function to record a move before calling movePiece
  myutils::MoveInfo AIGame::recordMove(Piece* piece, Cell& toMoveTo) {
    myutils::MoveInfo info;
    info.piece = piece;
    info.fromRow = piece->row;
    info.fromCol = piece->col;
    info.toRow = toMoveTo.row;
    info.toCol = toMoveTo.col;
    info.capturedPiece = this->board->cells[toMoveTo.row][toMoveTo.col].piece;
    info.wasCastle = (piece->id[1] == 'K' && this -> board ->isKingCastling(piece, toMoveTo));
    info.wasEnPassant = (piece->id[1] == 'P' && this -> board -> isPawnDoingEnPassantMove(piece, toMoveTo));
    info.wasPawnPromotion = (piece->id[1] == 'P' && (toMoveTo.row % 7 == 0));
    info.originalPieceId = piece->id;
    
    // For en passant, store the captured pawn
    if (info.wasEnPassant) {
        int capturedPawnCol = toMoveTo.col;
        int capturedPawnRow = piece->row;
        info.capturedPiece = this->board->cells[capturedPawnRow][capturedPawnCol].piece;
    }
    
    if (info.wasPawnPromotion) {
        info.promotedTo = piece->id[1];  // Current piece type (before promotion)
    }
    
    return info;
  }

  // The actual undoMove function
  void AIGame::undoMove(myutils::MoveInfo& move) {
    
    // HANDLE CASTLING (must be first, it moves 2 pieces)
    if (move.wasCastle) {
        int currRow = move.fromRow;
        if (move.fromCol == 4 && move.toCol == 2) {  // Left castle
            // Move rook back from c-file to a-file
            this->board->cells[currRow][0].piece = this->board->cells[currRow][3].piece;
            this->board->cells[currRow][0].piece->col = 0;
            this->board->cells[currRow][3].piece = nullptr;
            //this->board->renderEmptyCell(this->board->cells[currRow][3]);
            //this->board->renderCell(this->board->cells[currRow][0]);
            
            // Move king back from g-file to e-file (handled below)
        } else {  // Right castle
            // Move rook back from f-file to h-file
            this->board->cells[currRow][7].piece = this->board->cells[currRow][5].piece;
            this->board->cells[currRow][7].piece->col = 7;
            this->board->cells[currRow][5].piece = nullptr;
            //this->board->renderEmptyCell(this->board->cells[currRow][5]);
            //this->board->renderCell(this->board->cells[currRow][7]);
            
            // Move king back from g-file to e-file (handled below)
        }
    }
    
    // RESTORE PIECE ID (remove En Passant flag, restore castle flag, etc)
    move.piece->id = move.originalPieceId;
    
    // HANDLE PAWN PROMOTION (restore pawn)
    if (move.wasPawnPromotion) {
        // Restore to pawn
        //move.piece->id = string(1, move.piece->id[0]) + "P";
        move.piece->weight = 1;
        
        // Subtract the promoted piece weight, add back pawn weight
        if (move.piece->id[0] == 'B') {
            this->board->remBlackPieceWeight -= (move.promotedTo == 'Q' ? 9 : 
                                          move.promotedTo == 'R' ? 5 : 3);
            this->board->remBlackPieceWeight += 1;
        } else {
            this->board->remWhitePieceWeight -= (move.promotedTo == 'Q' ? 9 : 
                                          move.promotedTo == 'R' ? 5 : 3);
            this->board->remWhitePieceWeight += 1;
        }
    }
    
    // MOVE PIECE BACK TO ORIGINAL POSITION
    this->board->cells[move.toRow][move.toCol].piece = nullptr;
    //this->board->renderEmptyCell(this->board->cells[move.toRow][move.toCol]);
    
    move.piece->row = move.fromRow;
    move.piece->col = move.fromCol;
    this->board->cells[move.fromRow][move.fromCol].piece = move.piece;
    //this->board->renderCell(this->board->cells[move.fromRow][move.fromCol]);
    
    // RESTORE CAPTURED PIECE (if any)
    if (move.capturedPiece != nullptr) {
        if (move.wasEnPassant) {
            // En passant: captured pawn is on different row
            int capturedPawnCol = move.toCol;
            int capturedPawnRow = move.fromRow;
            this->board->cells[capturedPawnRow][capturedPawnCol].piece = move.capturedPiece;
            move.capturedPiece->row = capturedPawnRow;
            move.capturedPiece->col = capturedPawnCol;
            //this->board->renderCell(this->board->cells[capturedPawnRow][capturedPawnCol]);
            
            // Restore weight
            if (move.capturedPiece->id[0] == 'B') {
                this->board->remBlackPieceWeight += move.capturedPiece->weight;
            } else {
                this->board->remWhitePieceWeight += move.capturedPiece->weight;
            }
        } else {
            // Normal capture: restore to destination square
            this->board->cells[move.toRow][move.toCol].piece = move.capturedPiece;
            move.capturedPiece->row = move.toRow;
            move.capturedPiece->col = move.toCol;
            //this->board->renderCell(this->board->cells[move.toRow][move.toCol]);
            
            // Restore weight
            if (move.capturedPiece->id[0] == 'B') {
                this->board->remBlackPieceWeight += move.capturedPiece->weight;
            } else {
                this->board->remWhitePieceWeight += move.capturedPiece->weight;
            }
        }
    }
    
    // REGENERATE VALID MOVES
    this->board->generateValidMovesForAll();
    this->board->generateValidMovesForAll();
  }


  int AIGame::minimax(int depth, int alpha, int beta, bool isMaximizing){
    if(depth == 0 || this -> board -> blackPieces["BKc"] -> row < 0 || 
       this -> board -> whitePieces["WKc"] -> row < 0 || 
       this -> board -> isDrawByInsufficientMaterial() || this -> board -> isNoValidMoveForBlack() || this -> board -> isNoValidMoveForWhite()){
        return this -> board -> remBlackPieceWeight - this -> board -> remWhitePieceWeight;
    }

    if(isMaximizing){
        int maxEval = -5000;
        bool pruned = false;
        
        for(int i = 0; i < 16 && !pruned; i++){
            for(int roww = 0; roww <= 7 && !pruned; roww++){
                for(int coll = 0; coll <= 7 && !pruned; coll++){
                    if(!this -> board -> blackPiecesArray[i] -> validMoveCells[roww][coll]) continue;
                    Piece* piece = this -> board -> blackPiecesArray[i];
                    Cell toMoveTo;
                    toMoveTo.row = roww;
                    toMoveTo.col = coll;
                    myutils::MoveInfo move = this -> recordMove(piece, toMoveTo);
                    this -> board -> movePieceNoRender(piece, toMoveTo);
                    int eval = minimax(depth - 1, alpha, beta, false);
                    this -> undoMove(move);
                    maxEval = max(maxEval, eval);
                    alpha = max(alpha, maxEval);
                    if(beta <= alpha) pruned = true;
                }
            }
        }
        return maxEval;
    }
    else{
        int minEval = 5000;
        bool pruned = false;
        
        for(int i = 0; i < 16 && !pruned; i++){
            for(int roww = 0; roww <= 7 && !pruned; roww++){
                for(int coll = 0; coll <= 7 && !pruned; coll++){
                    if(!this -> board -> whitePiecesArray[i] -> validMoveCells[roww][coll]) continue;
                    Piece* piece = this -> board -> whitePiecesArray[i];
                    Cell toMoveTo;
                    toMoveTo.row = roww;
                    toMoveTo.col = coll;
                    myutils::MoveInfo move = this -> recordMove(piece, toMoveTo);
                    this -> board -> movePieceNoRender(piece, toMoveTo);
                    int eval = minimax(depth - 1, alpha, beta, true);
                    this -> undoMove(move);
                    minEval = min(eval, minEval);
                    beta = min(beta, minEval);
                    if(beta <= alpha) pruned = true;
                }
            }
        }
        return minEval;
    }
  }

  string AIGame::AIMove(){
    string aiMove = "";
    int maxEval = -5000;
    int alpha = -5000;
    int beta = 5000;
    
    int bestFromRow = -1, bestFromCol = -1, bestToRow = -1, bestToCol = -1;
    
    for(int i = 0; i < 16; i++){
        for(int roww = 0; roww <= 7; roww++){
            for(int coll = 0; coll <= 7; coll++){
                if(!this -> board -> blackPiecesArray[i] -> validMoveCells[roww][coll]) continue;
                Piece* piece = this -> board -> blackPiecesArray[i];
                Cell toMoveTo;
                toMoveTo.row = roww;
                toMoveTo.col = coll;
                
                // STORE COORDINATES BEFORE MOVING
                int fromRow = piece -> row;
                int fromCol = piece -> col;
                
                myutils::MoveInfo move = this -> recordMove(piece, toMoveTo);
                this -> board -> movePieceNoRender(piece, toMoveTo);
                int eval = minimax(this -> AIDepth - 1, -5000, 5000, false);
                this -> undoMove(move);

                if(eval > maxEval){
                    maxEval = eval;
                    // STORE THE BEST MOVE COORDINATES
                    bestFromRow = fromRow;
                    bestFromCol = fromCol;
                    bestToRow = roww;
                    bestToCol = coll;
                }
                else if(eval == maxEval){
                  int ogBestFromRow = bestFromRow;
                  int ogBestFromCol = bestFromCol;
                  int k = (rand() % 2 == 0) ? 1 : 2;

                  if(k == 1){
                    bestFromRow = (rand() % 2 == 0) ? bestFromRow : fromRow;
                    if(bestFromRow != ogBestFromRow){
                      bestFromCol = fromCol;
                      bestToRow = roww;
                      bestToCol = coll;
                    }
                  } 
                  else{
                    bestFromCol = (rand() % 2 == 0) ? bestFromCol : fromCol;
                    if(bestFromCol != ogBestFromCol){
                      bestFromRow = fromRow;
                      bestToRow = roww;
                      bestToCol = coll;
                    }
                  }
                
                }

                alpha = max(alpha, eval);
                if(beta <= alpha) break;
            }
        }
    }
    
    // BUILD STRING FROM STORED COORDINATES
    if(bestFromRow != -1){  // Make sure a valid move was found
        aiMove += to_string(bestFromRow);
        aiMove += to_string(bestFromCol);
        aiMove += to_string(bestToRow);
        aiMove += to_string(bestToCol);
    }
    
    return aiMove;
  }
  
  void AIGame::run(){
    this -> running = true;
    system("cls");
    this -> board -> renderInitial();
    this -> board -> generateValidMovesForAll();
    board -> renderDifficultySettings();
    char difficulty = this -> selectDifficulty('e');
    switch(difficulty){
      case 'e':
        this -> AIDepth = 4;
        break;
      case 'm':
        this -> AIDepth = 6;
        break;
      case 'h':
        this -> AIDepth = 8;
        break;
    }
    system("cls");
    board -> renderInitial();


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

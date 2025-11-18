#include <MultGame.h>
#include <Board.h>
#include <Piece.h>
#include <Cell.h>
#include <utils.h>
#include <SFML/Network.hpp>
#include <thread>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
#include <conio.h>
#include <iostream>
using namespace std;
    
    
    MultGame::MultGame()
      : board(new Board()), joiningAs('0'), color('0'),
        isMyTurn(false), running(false), port(0)
    {
        currCell.col = 0;
        currCell.row = 7;
    }
    MultGame::~MultGame(){ delete board; }

    //Functions Copied From Prac Game
      
    Piece* MultGame::whiteMove(){
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
        int rowToSend = piece -> row;
        int colToSend = piece -> col;
        board -> movePiece(piece, selectedMoveCell);

        //Send this data to the other player
        if (!sendMoveInts(rowToSend, colToSend, selectedMoveCell.row, selectedMoveCell.col)) {
            system("cls");
            cerr << "Network Error. Press any key to go back to main menu...\n";
            _getch();
            piece = nullptr;
            this -> running = true;
            break;
        }
        this -> currCell.row = selectedMoveCell.row;
        this -> currCell.col = selectedMoveCell.col;
        //board -> ifCastlingInvalid(piece);
      }
      myutils::setCursorPosition(currPos.X, currPos.Y);
      return piece;
    }

    Piece* MultGame::blackMove(){
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
        int rowToSend = piece -> row;
        int colToSend = piece -> col;
        board -> movePiece(piece, selectedMoveCell);



        //Send this data to the otehr player
        if (!sendMoveInts(rowToSend, colToSend, selectedMoveCell.row, selectedMoveCell.col)) {
            system("cls");
            cerr << "Network Error. Press any key to go back to main menu...\n";
            _getch();
            piece = nullptr;
            this -> running = true;
            break;
        }

        this -> currCell.row = selectedMoveCell.row;
        this -> currCell.col = selectedMoveCell.col;
        //board -> ifCastlingInvalid(piece);
      }
      myutils::setCursorPosition(currPos.X, currPos.Y);
      return piece;
    }

    
    char MultGame::selectJoiningAs(char c){
      char selected = c;
      int inp = -1;
      COORD currPos= myutils::getCursorPosition();


      while(inp != 13){
        inp = _getch();
        if (inp == 224 || inp == 0) {
          inp = _getch();
          
          switch(inp) {
              case 72: // Up arrow
                  if (selected == 'H'){
                    myutils::setCursorPosition(16, 2);
                    cout << "    ";
                    myutils::setCursorPosition(16, 3);
                    cout << "<<--";
                    selected = 'J';
                  }
                  else if(selected == 'J'){
                    myutils::setCursorPosition(16, 3);
                    cout << "    ";
                    myutils::setCursorPosition(16, 2);
                    cout << "<<--";
                    selected = 'H';
                  }
                  
                  break;
              case 80: // Down arrow
                  if (selected == 'H'){
                    myutils::setCursorPosition(16, 2);
                    cout << "    ";
                    myutils::setCursorPosition(16, 3);
                    cout << "<<--";
                    selected = 'J';

                  }
                  else if(selected == 'J'){
                    myutils::setCursorPosition(16, 3);
                    cout << "    ";
                    myutils::setCursorPosition(16, 2);
                    cout << "<<--";
                    selected = 'H';
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
        else if(inp == 27){
          this -> running = false;
          myutils::setCursorPosition(currPos.X, currPos.Y);
          return selected;
        }
      
      }
      myutils::setCursorPosition(currPos.X, currPos.Y);
      return selected;

    }

    // Find a free port in a range; returns 0 if none found
    unsigned short MultGame::findFreePort(unsigned short start, unsigned short max) {
        sf::TcpListener tmp;
        for (unsigned short p = start; p <= max; ++p) {
            if (tmp.listen(p) == sf::Socket::Done) {
                tmp.close();
                return p;
            }
        }
        return 0;
    }

    
    bool MultGame::initializeHost() {
      this->port = findFreePort(5050, 5200);
      if (this->port == 0) {
          cerr << "No free port available!\n";
          return false;
      }

      sf::TcpListener listener;
      if (listener.listen(this->port) != sf::Socket::Done) {
          cerr << "Error: could not listen on port " << this->port << "\n";
          return false;
      }

      cout << "Waiting for connection on port : " << this->port << ".....(Timeout in 2 minutes)\n";

      // ---- ADD SELECTOR FOR TIMEOUT ----
      sf::SocketSelector selector;
      selector.add(listener);

      // Wait for up to 2 minutes (120000 ms)
      if (!selector.wait(sf::milliseconds(120000))) {
          cout << "No player connected within 2 minutes.\n";
          listener.close();
          return false;    // return from function
      }

      // If we reach here, SOMETHING is ready → attempt accept
      if (listener.accept(this->socket) != sf::Socket::Done) {
          cerr << "Error: failed to accept connection\n";
          return false;
      }

      cout << "Connected to a player!\n";
      return true;
    }


    // Client initialization: connect to a host ip and port
    bool MultGame::initializeClient(const string& ip, unsigned short hostPort) {
        if (this->socket.connect(ip, hostPort) != sf::Socket::Done) {
            cerr << "Could not connect to " << ip << ":" << hostPort << "\n";
            return false;
        }
        this->port = hostPort;
        cout << "Connected to host " << ip << ":" << hostPort << "\n";
        return true;
    }


    bool MultGame::sendColor(char color) {
      sf::Packet p;
      p << string("COLOR") << string(1, color);  // Convert char to string
      if(socket.send(p) != sf::Socket::Done){
          cerr << "Failed to send COLOR packet\n";
          return false;
      }
      cout << "COLOR packet sent successfully\n";
      return true;
    }

    // And sendReady
    bool MultGame::sendReady() {
      sf::Packet p;
      p << string("READY");
      if(socket.send(p) != sf::Socket::Done){
          cerr << "Failed to send READY packet\n";
          return false;
      }
      cout << "READY packet sent successfully\n";
      return true;
    }


    //Quitting Midway
    bool MultGame::sendQuit() {
      sf::Packet p;
      p << string("QUIT");
      socket.send(p);
      return true;
    }

    // Send 4 ints representing a move. Returns true on success.
    bool MultGame::sendMoveInts(int a, int b, int c, int d) {
        sf::Packet packet;
        packet << string("MOVE") << a << b << c << d;
        if (this->socket.send(packet) != sf::Socket::Done) {
            cerr << "Failed to send move (connection problem)\n";
            return false;
        }
        return true;
    }

    

    bool MultGame::receiveMoveInts(string& type, int &a, int &b, int &c, int &d, char &colorOut, bool &readyOut) {
      sf::Packet packet;
      if (this->socket.receive(packet) != sf::Socket::Done) {
          cerr << "Failed to receive packet (connection closed or error)\n";
          return false;
      }
      
      type = "";
      a = b = c = d = -1;
      
      if (!(packet >> type)) {
          cerr << "Failed to read type from packet\n";
          return false;
      }

      if (type == "QUIT") {
          return true;
      }

      if (type == "MOVE") {
          if (!(packet >> a >> b >> c >> d)) {
              cerr << "Failed to read move coordinates from packet\n";
              return false;
          }
          return true;
      }

      if (type == "COLOR") {
          string colorStr;
          if (!(packet >> colorStr)) {
              cerr << "Failed to read color from packet\n";
              return false;
          }
          if(colorStr.length() > 0) {
              colorOut = colorStr[0];
              cout << "DEBUG: Received color: " << colorOut << "\n";
          }
          return true;
      }

      if (type == "READY") {
          readyOut = true;
          return true;
      }
      
      cerr << "Unknown packet type: " << type << "\n";
      return false;
    }

    

    // Apply opponent move to board (replace with your board logic)
    void MultGame::applyRemoteMove(int a, int b, int c, int d) {
        //cout << "DEBUG: Applying move (" << a << "," << b << ") -> (" << c << "," << d << ")\n";
        Piece* piece = board -> cells[a][b].piece;
        if(piece == nullptr){
          cout << "ERROR: No piece at source (" << a << "," << b << ")\n";
          return;
        }
        //cout << "DEBUG: Moving piece " << piece->id << "\n";
        //_getch();
        board->movePiece(piece, board -> cells[c][d]);
    }

    // Main turn-based loop: send OR receive alternately
    void MultGame::connectedNowPlay() {
        cout << "Game started. Press ESC at any time to quit.\n";
        running = true;


        //TO Refer From
        // while(running){
        //   Piece* piece = nullptr;
        //   piece = this -> whiteMove();
        //   if(!piece){
        //     running = false;
        //     return;
        //   }
        //   if(this -> board -> isBlackKingInTrouble(piece)  || this -> board -> isDrawByInsufficientMaterial()){
        //     running = false;
        //   }
        //   if(!running) return;
        //   piece = this -> blackMove();
        //   if(!piece){
        //     running = false;
        //     return;
        //   }
        //   if(this -> board -> isWhiteKingInTrouble(piece)  || this -> board -> isDrawByInsufficientMaterial()){
        //     running = false;
        //   }
        // }


        // Decide who starts: convention - host starts (isMyTurn set by caller)
        while (running) {
            // --- CHECK FOR ESC ---
            if (_kbhit()) {
                int key = _getch();
                if (key == 27) { // ESC
                    cout << "You quit the game.\n";
                    sendQuit();
                    running = false;
                    break;
                }
            }


            if (isMyTurn) {
                // Player's turn to make move and send it
                //int a,b,c,d;
                // You might want to integrate this with your board's input method instead of getLocalMove()
                //getLocalMove(a,b,c,d);
                if(this -> color == 'W'){
                  Piece* piece = this -> whiteMove();
                  if(!piece && !running){
                    system("cls");
                    cout << "You quit the game. Press any key to go back to main menu...\n";
                    _getch();
                    sendQuit();
                    this -> running = false;
                    break;
                  }
                  else if(!piece && running){
                    this -> running = false;
                    break;
                  }
                  this -> isMyTurn = false;
                  if(this -> board -> isBlackKingInTrouble(piece)  || this -> board -> isDrawByInsufficientMaterial()){
                    system("cls");
                    cout << "Press any key to go back to main menu...";
                    _getch();
                    running = false;
                    break;
                  }
                }

                else if(this -> color == 'B'){
                  Piece* piece = this -> blackMove();
                  if(!piece && !running){
                    system("cls");
                    cout << "You quit the game. Press any key to go back to main menu...\n";
                    sendQuit();
                    this -> running = false;
                    break;
                  }
                  else if(!piece && running){
                    this -> running = false;
                    break;
                  }
                  this -> isMyTurn = false;
                  if(this -> board -> isWhiteKingInTrouble(piece)  || this -> board -> isDrawByInsufficientMaterial()){
                    system("cls");
                    cout << "Press any key to go back to main menu...";
                    _getch();
                    running = false;
                    break;
                  }
                }
                // Optional: allow quitting by special values (not implemented here), or string-based protocol
                

                // Apply locally as well
                //board->applyMove(a,b,c,d);

                // After sending, wait for opponent next
                //isMyTurn = false;
            }
            else {
                // Waiting for opponent move (blocking receive)
                COORD currPos = myutils::getCursorPosition();
                cout << "\nWaiting for opponent's move...\n";
                
                string type;
                bool temp = true;
                int a,b,c,d;
                if (!receiveMoveInts(type,a,b,c,d, this -> color, temp)) {
                    system("cls");
                    cerr << "Network Error. Press any key to go back to main menu...\n";
                    _getch();
                    //piece = nullptr;
                    this -> running = false;
                    break;
                }
                myutils::setCursorPosition(currPos.X, currPos.Y);
                cout << "\n                                    \n";
                myutils::setCursorPosition(currPos.X, currPos.Y);
                if (type == "QUIT") {
                  cout << "\nOpponent quit the game. Press any key to go back to main menu...\n";
                  _getch();
                  this -> running = false;
                  break;
                }

                if(type == "MOVE"){
                  //cout << "Opponent move received: " << a << " " << b << " -> " << c << " " << d << "\n";
                  applyRemoteMove(a,b,c,d);
                  Piece* piece= this -> board->cells[c][d].piece;
                  if(this -> color == 'W'){
                    if(this -> board -> isWhiteKingInTrouble(piece) || this -> board -> isDrawByInsufficientMaterial()){
                      system("cls");
                      cout << "Press any key to go back to main menu...";
                      _getch();
                      running = false;
                      break;
                    }
                  }
                  else if(this -> color == 'B'){
                    if(this -> board -> isBlackKingInTrouble(piece)  || this -> board -> isDrawByInsufficientMaterial()){
                      system("cls");
                      cout << "Press any key to go back to main menu...";
                      _getch();
                      running = false;
                      break;
                    }
                    
                  }

                  isMyTurn = true;
                }
            }

            // small sleep prevents 100% CPU usage
            this_thread::sleep_for(chrono::milliseconds(50));
        } // while running
        
        cout << "Exiting game loop.\n";
        this->socket.disconnect();
    }

    
    void MultGame::hostHandshake(){
        // HOST HANDSHAKE
        cout << "Select your color (W/B): ";
        cin >> this->color;
        
        // Validate input
        if(this->color != 'W' && this->color != 'B'){
            this->color = 'W';  // Default to white if invalid
        }
        
        cout << "You chose: " << this->color << "\n";
        cout << "Sending color to client...\n";

        // SEND my color to client IMMEDIATELY
        if(!sendColor(this->color)){
            cerr << "Failed to send color to client\n";
            return;
        }

        cout << "Color sent. Waiting for client to be ready...\n";

        // wait for client to ACK with READY
        bool clientReady = false;
        string type;
        int aa, bb, cc, dd;
        char colorGot = '0';
        bool readyGot = false;

        while (!clientReady) {
            if(!receiveMoveInts(type, aa, bb, cc, dd, colorGot, readyGot)){
                cerr << "Failed to receive from client\n";
                return;
            }
            
            if (type == "READY") {
                clientReady = true;
                cout << "Client is ready.\n";
            }
        }

        // host also sends READY to confirm
        if(!sendReady()){
            cerr << "Failed to send READY to client\n";
            return;
        }

        cout << "Handshake complete. Starting game...\n";
        this_thread::sleep_for(chrono::milliseconds(500));  // Small delay before game starts
    }

    void MultGame::clientHandshake(){
        // CLIENT HANDSHAKE
        cout << "Waiting for host to choose color...\n";

        string type;
        int a1, b1, c1, d1;
        char hostColor = '0';
        bool readyFlag = false;

        // wait for COLOR message from host
        while (true) {
            if(!receiveMoveInts(type, a1, b1, c1, d1, hostColor, readyFlag)){
                cerr << "Failed to receive from host\n";
                return;
            }
            
            cout << "DEBUG: Received type: " << type << "\n";  // Debug line
            
            if (type == "COLOR") {
                cout << "Host chose color: " << hostColor << "\n";
                break;
            }
        }

        // assign opposite color to client
        this->color = (hostColor == 'W' ? 'B' : 'W');
        cout << "You are color: " << this->color << "\n";

        // client sends READY to acknowledge
        if(!sendReady()){
            cerr << "Failed to send READY to host\n";
            return;
        }

        cout << "Sent READY. Waiting for host confirmation...\n";

        // wait for host READY confirmation
        readyFlag = false;
        while (!readyFlag) {
            if(!receiveMoveInts(type, a1, b1, c1, d1, hostColor, readyFlag)){
                cerr << "Failed to receive READY from host\n";
                return;
            }
            
            if (type == "READY") {
                cout << "Host confirmed ready.\n";
                break;
            }
        }

        cout << "Handshake complete. Starting game...\n";
        this_thread::sleep_for(chrono::milliseconds(500));  // Small delay before game starts
    }


    void MultGame::resetBoard(){
      Board* temp = board;
      board = new Board();
      delete temp;
      running = false;
      this -> currCell.col = 0;
      this -> currCell.row = 7;
    }

    void MultGame::run(){
      this -> running = true;
      system("cls");
      //this -> board -> renderInitial();
      //this -> renderJoiningInfo();
      COORD currPos = myutils::getCursorPosition();
      cout << "\n";
      cout << "Choose What To Do :\n1. Host A Game  <<--\n2. Join A Game  ";
      char c = this -> selectJoiningAs('H');
      // myutils::setCursorPosition(currPos.X, currPos.Y);
      // cout << "                   \n                   \n                ";
      // myutils::setCursorPosition(currPos.X, currPos.Y);
      system("cls");
      if(!this -> running) return;
      this -> joiningAs = c;
      if (this -> joiningAs == 'H') {
        // Host: auto-pick port and wait for connection
        if (!this -> initializeHost()) {
            cerr << "Failed to initialize host.\nPress any key to go back to main menu...";
            _getch();
            this -> running = false;
            return;
        }
        system("cls");
        this -> hostHandshake();
        this -> isMyTurn = true; // convention: host moves first
      } 
      else {
        // Joiner: prompt IP and port
        string ip;
        unsigned short port;
        cout << "Enter host IP: ";
        cin >> ip;
        cout << "Enter host port: ";
        cin >> port;
        if (!this -> initializeClient(ip, port)) {
            cerr << "Failed to connect to host.\nPress any key to go back to main menu...";
            _getch();
            this -> running = false;
            return;
        }
        system("cls");
        this -> clientHandshake();
        this -> isMyTurn = false; // client waits first
      }

      // Now start the turn-based exchange
      system("cls");
      myutils::setCursorPosition(currPos.X, currPos.Y);
      this -> board -> renderInitial();
      this -> board -> generateValidMovesForAll();
      this -> connectedNowPlay();
    }

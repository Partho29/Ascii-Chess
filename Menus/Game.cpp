#include <Game.h>
#include <utils.h>
#include <iostream>
using namespace std;


Game::Game() : menu(new MainMenu()) {}

Game::~Game(){
  delete menu;
}

void Game::run(){
  cout << "\033[0m";
  system("cls");
  cout << myutils::BG_COLOR;
  cout << myutils::TXT_COLOR;
  this -> menu -> run();
}

#include <iostream>
#include <string>
#include <map>

#include "ChessBoard.h"

using namespace std;

ChessBoard::ChessBoard() {
  currentPlayer = WHITE_PLAYER;
  gameEnd = false;
  inCheck = false;
  insertPieces();
}

ChessBoard::~ChessBoard() {
  deletePieces();
}

void ChessBoard::switchPlayers() {
  currentPlayer = currentPlayer == WHITE_PLAYER ? BLACK_PLAYER : WHITE_PLAYER;
}

string ChessBoard::printPlayerColour() {
  return (currentPlayer == WHITE_PLAYER) ? "White" : "Black";
}

Player ChessBoard::getCurrentPlayer() {
  return currentPlayer;
}

void ChessBoard::insertPieces() {

  currentBoard["A1"] = new Rook(WHITE);
  currentBoard["B1"] = new Knight(WHITE);
  currentBoard["C1"] = new Bishop(WHITE);
  currentBoard["D1"] = new Queen(WHITE);
  currentBoard["E1"] = new King(WHITE);
  currentBoard["F1"] = new Bishop(WHITE);
  currentBoard["G1"] = new Knight(WHITE);
  currentBoard["H1"] = new Rook(WHITE);
  currentBoard["A2"] = new Pawn(WHITE);
  currentBoard["B2"] = new Pawn(WHITE);
  currentBoard["C2"] = new Pawn(WHITE);
  currentBoard["D2"] = new Pawn(WHITE);
  currentBoard["E2"] = new Pawn(WHITE);
  currentBoard["F2"] = new Pawn(WHITE);
  currentBoard["G2"] = new Pawn(WHITE);
  currentBoard["H2"] = new Pawn(WHITE);

  currentBoard["A8"] = new Rook(BLACK);
  currentBoard["B8"] = new Knight(BLACK);
  currentBoard["C8"] = new Bishop(BLACK);
  currentBoard["D8"] = new Queen(BLACK);
  currentBoard["E8"] = new King(BLACK);
  currentBoard["F8"] = new Bishop(BLACK);
  currentBoard["G8"] = new Knight(BLACK);
  currentBoard["H8"] = new Rook(BLACK);
  currentBoard["A7"] = new Pawn(BLACK);
  currentBoard["B7"] = new Pawn(BLACK);
  currentBoard["C7"] = new Pawn(BLACK);
  currentBoard["D7"] = new Pawn(BLACK);
  currentBoard["E7"] = new Pawn(BLACK);
  currentBoard["F7"] = new Pawn(BLACK);
  currentBoard["G7"] = new Pawn(BLACK);
  currentBoard["H7"] = new Pawn(BLACK);

  cout << "A new chess game is started!" << endl;

  printBoard();

}

void ChessBoard::deletePieces() {

  map <string, Piece*> ::iterator it;
  for (it = currentBoard.begin(); it != currentBoard.end(); it++){
    delete it->second;
  }

}

void ChessBoard::resetBoard() {

  currentPlayer = WHITE_PLAYER;
  deletePieces();
  currentBoard.clear();
  insertPieces();

}

void ChessBoard::printBoard() {

  cout << endl << "  +---+---+---+---+---+---+---+---+" << endl;
  for (char i = '8'; i >= '1'; i--) {
    cout << i << " ";
    for (char j = 'A'; j <= 'H'; j++) {
      cout << "|";
      string coordinate = "";
      coordinate += j;
      coordinate += i;
      if (currentBoard.count(coordinate)){
        cout << " " << currentBoard[coordinate]->printSymbol() << " ";
      } else{
        cout << "   ";
      }
    }
    cout << "|" << endl << "  +---+---+---+---+---+---+---+---+" << endl;
  }
  cout << "    A   B   C   D   E   F   G   H" << endl << endl;

}

void ChessBoard::submitMove(const char* from, const char* to){

  string fromCoordinate (from);
  string toCoordinate (to);

  cout << printPlayerColour() << "'s "
       << currentBoard[fromCoordinate]->printPieceName() << " moves from "
       << fromCoordinate << " to " << toCoordinate << endl;

  currentBoard[toCoordinate] = currentBoard[fromCoordinate];
  currentBoard.erase(fromCoordinate);

  printBoard();
  switchPlayers();
}

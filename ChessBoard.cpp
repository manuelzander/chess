#include <iostream>
#include <string>
#include <map>

#include "ChessBoard.h"

using namespace std;

ChessBoard::ChessBoard() {
  currentPlayer = WHITE;
  gameEnd = false;
  inCheck = false;
  insertPieces();
}

ChessBoard::~ChessBoard() {
  deletePieces();
}

void ChessBoard::switchPlayers() {
  currentPlayer = currentPlayer == WHITE ? BLACK : WHITE;
}


Colour ChessBoard::getCurrentPlayer() {
  return currentPlayer;
}

void ChessBoard::insertPieces() {

  currentBoard["A1"] = new Rook(WHITE, this);
  currentBoard["B1"] = new Knight(WHITE, this);
  currentBoard["C1"] = new Bishop(WHITE, this);
  currentBoard["D1"] = new Queen(WHITE, this);
  currentBoard["E1"] = new King(WHITE, this);
  currentBoard["F1"] = new Bishop(WHITE, this);
  currentBoard["G1"] = new Knight(WHITE, this);
  currentBoard["H1"] = new Rook(WHITE, this);
  currentBoard["A2"] = new Pawn(WHITE, this);
  currentBoard["B2"] = new Pawn(WHITE, this);
  currentBoard["C2"] = new Pawn(WHITE, this);
  currentBoard["D2"] = new Pawn(WHITE, this);
  currentBoard["E2"] = new Pawn(WHITE, this);
  currentBoard["F2"] = new Pawn(WHITE, this);
  currentBoard["G2"] = new Pawn(WHITE, this);
  currentBoard["H2"] = new Pawn(WHITE, this);

  currentBoard["A8"] = new Rook(BLACK, this);
  currentBoard["B8"] = new Knight(BLACK, this);
  currentBoard["C8"] = new Bishop(BLACK, this);
  currentBoard["D8"] = new Queen(BLACK, this);
  currentBoard["E8"] = new King(BLACK, this);
  currentBoard["F8"] = new Bishop(BLACK, this);
  currentBoard["G8"] = new Knight(BLACK, this);
  currentBoard["H8"] = new Rook(BLACK, this);
  currentBoard["A7"] = new Pawn(BLACK, this);
  currentBoard["B7"] = new Pawn(BLACK, this);
  currentBoard["C7"] = new Pawn(BLACK, this);
  currentBoard["D7"] = new Pawn(BLACK, this);
  currentBoard["E7"] = new Pawn(BLACK, this);
  currentBoard["F7"] = new Pawn(BLACK, this);
  currentBoard["G7"] = new Pawn(BLACK, this);
  currentBoard["H7"] = new Pawn(BLACK, this);

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

  currentPlayer = WHITE;
  deletePieces();
  currentBoard.clear();
  insertPieces();

}

void ChessBoard::submitMove(const char* from, const char* to){

  string fromCoordinate (from);
  string toCoordinate (to);

  if(gameEnd){
    cout << "The game is already over!" << endl;
    return;
  }

  if(!checkCoordinateValidity(fromCoordinate)
      || !checkCoordinateValidity(toCoordinate) ){
    cout << "A given coordinate is invalid!" << endl;
    return;
  }

  if(!currentBoard.count(fromCoordinate)){
    cout << "There is no piece at position " << fromCoordinate << endl;
    return;
  }

  if(currentBoard[fromCoordinate]->getPieceColour() != getCurrentPlayer()){
    cout << "It is not " << currentBoard[fromCoordinate]->printPieceColour()
         << "'s turn to move!" << endl;
    return;
  }

  if(fromCoordinate == toCoordinate){
    cout << "The positions are identical!" << endl;
    return;
  }


  // Move after checks done

  cout << currentBoard[fromCoordinate]->printPieceColour() << "'s "
       << currentBoard[fromCoordinate]->printPieceType() << " moves from "
       << fromCoordinate << " to " << toCoordinate << endl;

  currentBoard[toCoordinate] = currentBoard[fromCoordinate];
  currentBoard.erase(fromCoordinate);
  // Should I delete the pointer to the piece as well?

  printBoard();
  switchPlayers();
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

bool ChessBoard::checkCoordinateValidity(const string coordinate) {

  if(coordinate[0] < 'A' || coordinate[0] > 'H'){
    return false;
  }
  if(coordinate[1] < '1' || coordinate[1] > '8'){
    return false;
  }
  if(coordinate.length() != 2){
    return false;
  }
  return true;
}

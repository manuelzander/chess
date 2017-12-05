#include <iostream>
#include <string>

#include "King.h"

using namespace std;

King::King(Colour _colour, ChessBoard *_board) : Piece(_colour, _board){
  pieceType = KING;
  cout << "King created with colour " << pieceColour << endl;
}

King::~King () {
}

bool King::checkMoveValidity(const string from, const string to){

  // TODO
  return true;
}

string King::printSymbol (){
  if (pieceColour == 0) {
    return "♔";
  }
  return "♚";
}

#include <iostream>
#include <string>

#include "Bishop.h"

using namespace std;

Bishop::Bishop(Colour _colour, ChessBoard *_board) : Piece(_colour, _board){
  pieceType = BISHOP;
}

Bishop::~Bishop () {
}

bool Bishop::checkMoveValidity(const string from, const string to){

  // TODO
  return true;
}

string Bishop::printSymbol(){
  if (pieceColour == 0) {
    return "♗";
  }
  return "♝";
}

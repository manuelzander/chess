#include <iostream>
#include <string>

#include "Queen.h"

using namespace std;

Queen::Queen(Colour _colour, ChessBoard *_board) : Piece(_colour, _board){
  pieceType = QUEEN;
}

Queen::~Queen () {
}

bool Queen::checkMoveValidity(const string from, const string to){

  // TODO
  return true;
}

string Queen::printSymbol(){
  if (pieceColour == 0) {
    return "♕";
  }
  return "♛";
}

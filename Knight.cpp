#include <iostream>
#include <string>

#include "Knight.h"

using namespace std;

Knight::Knight(Colour _colour, ChessBoard *_board) : Piece(_colour, _board){
  pieceType = KNIGHT;
}

Knight::~Knight () {
}

bool Knight::checkMoveValidity(const string from, const string to){

  bool validMove =
      ((abs(from[Ra] - to[Ra]) == 2) && //Two vertival and one horizontal
      (abs(from[Fi] - to[Fi]) == 1)) ||
      ((abs(from[Fi] - to[Fi]) == 2) && //Two horizontal and one vertival
      (abs(from[Ra] - to[Ra]) == 1));

  return validMove;
}

string Knight::printSymbol(){
  if (pieceColour == 0) {
    return "♘";
  }
  return "♞";
}

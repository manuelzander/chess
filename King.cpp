#include <iostream>
#include <string>

#include "King.h"

using namespace std;

King::King(Colour _colour, ChessBoard *_board) : Piece(_colour, _board){
  pieceType = KING;
}

King::~King () {
}

bool King::checkMoveValidity(const string from, const string to){

  bool validHorizontalMove, validVerticalMove, validDiagonalMove;

  validHorizontalMove =
    (abs(from[Fi] - to[Fi]) == 1 &&
    from[Ra] - to[Ra] == 0);

  validVerticalMove =
    (abs(from[Ra] - to[Ra]) == 1 &&
    from[Fi] - to[Fi] == 0);

  validDiagonalMove =
    (abs(from[Fi] - to[Fi]) == 1 &&
    abs(from[Ra] - to[Ra]) == 1);

  return (validHorizontalMove || validVerticalMove || validDiagonalMove);
}

string King::printSymbol(){
  if (pieceColour == 0) {
    return "♔";
  }
  return "♚";
}

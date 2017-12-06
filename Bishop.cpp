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

  bool validDiagonalMove, validDiagonalWay;

  validDiagonalWay = freeDiagonalWay(from, to);

  validDiagonalMove = (abs(from[Fi] - to[Fi]) ==
    abs(from[Ra] - to[Ra]) &&
    validDiagonalWay);

  /*if(validDiagonalMove && !board->checkCoordinateEmpty(to))
      board->setPieceCaptured();*/

  return validDiagonalMove;
}

string Bishop::printSymbol(){
  if (pieceColour == 0) {
    return "♗";
  }
  return "♝";
}

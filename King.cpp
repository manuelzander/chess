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



  validHorizontalMove = (abs(from[0] - to[0]) == 1);
  validVerticalMove = (abs(from[1] - to[1]) == 1);
  validDiagonalMove = (abs(from[0] - to[0]) == 1 &&
    abs(from[1] - to[1]) == 1);

  if((validHorizontalMove || validVerticalMove || validDiagonalMove) &&
    !board->checkCoordinateEmpty(to)) board->setPieceCaptured();

  return (validHorizontalMove || validVerticalMove || validDiagonalMove);
}

string King::printSymbol(){
  if (pieceColour == 0) {
    return "♔";
  }
  return "♚";
}

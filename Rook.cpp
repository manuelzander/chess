#include <iostream>
#include <string>

#include "Rook.h"

using namespace std;

Rook::Rook(Colour _colour, ChessBoard *_board) : Piece(_colour, _board){
  pieceType = ROOK;
}

Rook::~Rook () {
}

bool Rook::checkMoveValidity(const string from, const string to){

  bool validHorizontalMove, validVerticalMove,
    validHorizontalWay, validVerticalWay;

  if (from[Ra] == to[Ra]){ //Check for freeHorizontalWay
    validHorizontalWay = freeHorizontalWay(from, to);
    } else{ //Check for freeVerticalWay
    validVerticalWay = freeVerticalWay(from, to);
  }

  validHorizontalMove = (abs(from[Fi] - to[Fi]) > 0 &&
    from[Ra] - to[Ra] == 0 &&
    validHorizontalWay);

  validVerticalMove = (abs(from[Ra] - to[Ra]) > 0 &&
    from[Fi] - to[Fi] == 0 &&
    validVerticalWay);

  /*if((validHorizontalMove || validVerticalMove) &&
    !board->checkCoordinateEmpty(to))
      board->setPieceCaptured();*/

  return (validHorizontalMove || validVerticalMove);
}

string Rook::printSymbol(){
  if (pieceColour == 0) {
    return "♖";
  }
  return "♜";
}

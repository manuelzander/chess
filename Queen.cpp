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

  bool validHorizontalMove, validVerticalMove, validDiagonalMove,
    validHorizontalWay, validVerticalWay, validDiagonalWay;

  if (from[Ra] == to[Ra]){ //Check for freeHorizontalWay
    validHorizontalWay = freeHorizontalWay(from, to);
  }else if(from[Fi] == to[Fi]){ //Check for freeVerticalWay
    validVerticalWay = freeVerticalWay(from, to);
  }else{ //Check for freeDiagonalWay
    validDiagonalWay = freeDiagonalWay(from, to);
  }

  validHorizontalMove = (abs(from[Fi] - to[Fi]) > 0 &&
    from[Ra] - to[Ra] == 0 &&
    validHorizontalWay);

  //cout << validHorizontalMove << endl;

  validVerticalMove = (abs(from[Ra] - to[Ra]) > 0 &&
    from[Fi] - to[Fi] == 0 &&
    validVerticalWay);

  //cout << validVerticalMove << endl;

  validDiagonalMove = (abs(from[Fi] - to[Fi]) ==
    abs(from[Ra] - to[Ra]) &&
    validDiagonalWay);

  //cout << validDiagonalMove << endl;

  /*if((validHorizontalMove || validVerticalMove || validDiagonalMove) &&
    !board->checkCoordinateEmpty(to))
      board->setPieceCaptured();*/

    return (validHorizontalMove || validVerticalMove || validDiagonalMove);
}

string Queen::printSymbol(){
  if (pieceColour == 0) {
    return "♕";
  }
  return "♛";
}

#include <iostream>
#include <string>

#include "Pawn.h"

using namespace std;

Pawn::Pawn(Colour _colour, ChessBoard *_board) : Piece(_colour, _board){
  pieceType = PAWN;
}

Pawn::~Pawn () {
}

bool Pawn::checkMoveValidity(const string from, const string to){

  bool validMove, validSpecialMove, validDiagonalMove;

  if(pieceColour == WHITE){

    validMove =
      (from[Fi] == to[Fi] &&
      from[Ra] + 1 == to[Ra] &&
      board->checkCoordinateEmpty(to));

    string middleCoordinate = "";
    middleCoordinate += from[Fi];
    middleCoordinate += (from[Ra] + 1);

    validSpecialMove =
      (from[Ra] == '2' &&
      from[Fi] == to[Fi] &&
      from[Ra] + 2 == to[Ra] &&
      board->checkCoordinateEmpty(middleCoordinate) &&
      board->checkCoordinateEmpty(to));

    validDiagonalMove =
      (from[Ra] + 1 == to[Ra] &&
      abs(from[Fi] - to[Fi]) == 1 &&
      !board->checkCoordinateEmpty(to));
  }

  if (pieceColour == BLACK) {

    validMove =
      (from[Fi] == to[Fi] &&
      from[Ra] - 1 == to[Ra] &&
      board->checkCoordinateEmpty(to));

    string middleCoordinate = "";
    middleCoordinate += from[Fi];
    middleCoordinate += (from[Ra] - 1);

    validSpecialMove =
      (from[Ra] == '7' &&
      from[Fi] == to[Fi] &&
      from[Ra] - 2 == to[Ra] &&
      board->checkCoordinateEmpty(middleCoordinate) &&
      board->checkCoordinateEmpty(to));

    validDiagonalMove =
      (from[Ra] - 1 == to[Ra] &&
      abs(from[Fi] - to[Fi]) == 1 &&
      !board->checkCoordinateEmpty(to));
  }

  /*if(validDiagonalMove)
    board->setPieceCaptured();*/

  return (validMove || validSpecialMove || validDiagonalMove);
}

string Pawn::printSymbol(){
  if (pieceColour == 0) {
    return "♙";
  }
  return "♟";
}

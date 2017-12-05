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

    validMove = (from[0] == to[0] &&
      from[1] + 1 == to[1] &&
      board->checkCoordinateEmpty(to));

    string middleCoordinate = "";
    middleCoordinate += from[0];
    middleCoordinate += (from[1] + 1);
    cout << middleCoordinate << endl;

    validSpecialMove = (from[1] == '2' &&
      from[0] == to[0] &&
      from[1] + 2 == to[1] &&
      board->checkCoordinateEmpty(middleCoordinate) &&
      board->checkCoordinateEmpty(to));

    validDiagonalMove = (from[1] + 1 == to[1] &&
      abs(from[0] - to[0]) == 1 &&
      !board->checkCoordinateEmpty(to));
      //board->getPieceColour(to) == BLACK);

  }
  if (pieceColour == BLACK) {

    validMove = (from[0] == to[0] &&
      from[1] - 1 == to[1] &&
      board->checkCoordinateEmpty(to));

    string middleCoordinate = "";
    middleCoordinate += from[0];
    middleCoordinate += (from[1] - 1);
    cout << middleCoordinate << endl;

    validSpecialMove = (from[1] == '7' &&
      from[0] == to[0] &&
      from[1] - 2 == to[1] &&
      board->checkCoordinateEmpty(middleCoordinate) &&
      board->checkCoordinateEmpty(to));

    validDiagonalMove = (from[1] - 1 == to[1] &&
      abs(from[0] - to[0]) == 1 &&
      !board->checkCoordinateEmpty(to));
      //board->getPieceColour(to) == WHITE);
  }

  if(validDiagonalMove == true)
    board->setPieceCaptured();
  return (validMove || validSpecialMove || validDiagonalMove);
}

string Pawn::printSymbol(){
  if (pieceColour == 0) {
    return "♙";
  }
  return "♟";
}

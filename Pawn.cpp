#include <iostream>
#include <string>

#include "Pawn.h"

using namespace std;

Pawn::Pawn(Colour _colour, ChessBoard *_board) : Piece(_colour, _board){
  pieceType = PAWN;
  cout << "Pawn created with colour " << pieceColour << endl;
}

Pawn::~Pawn () {
}

bool Pawn::checkMoveValidity(const string from, const string to){

  // How to check for an empty field
  // How to capture an opponent piece?

  if(pieceColour == WHITE){

    // Special case for first move
    if(from[1] == '2' && to[1] == from[1] + 2)
      return true;

    if(to[1] == from[1] + 1)
      return true;

  }
  if (pieceColour == BLACK) {

    // Special case for first move
    if(from[1] == '7' && to[1] == from[1] - 2)
      return true;

    if(to[1] == from[1] - 1)
      return true;

  }

  return false;
}

string Pawn::printSymbol (){
  if (pieceColour == 0) {
    return "♙";
  }
  return "♟";
}

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

string Pawn::printSymbol (){
  if (pieceColour == 0) {
    return "♙";
  }
  return "♟";
}

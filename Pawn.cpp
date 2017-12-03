#include <iostream>
#include <string>

#include "Pawn.h"

using namespace std;

Pawn::Pawn(Colour colour) : Piece(colour) {
  name = "Pawn";
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

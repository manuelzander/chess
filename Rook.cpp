#include <iostream>
#include <string>

#include "Rook.h"

using namespace std;

Rook::Rook(Colour colour) : Piece(colour) {
  name = "Rook";
  cout << "Rook created with colour " << pieceColour << endl;
}

Rook::~Rook () {
}

string Rook::printSymbol (){
  if (pieceColour == 0) {
    return "♖";
  }
  return "♜";
}

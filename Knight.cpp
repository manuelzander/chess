#include <iostream>
#include <string>

#include "Knight.h"

using namespace std;

Knight::Knight(Colour colour) : Piece(colour) {
  name = "Knight";
  cout << "Knight created with colour " << pieceColour << endl;
}

Knight::~Knight () {
}

string Knight::printSymbol (){
  if (pieceColour == 0) {
    return "♘";
  }
  return "♞";
}

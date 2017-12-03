#include <iostream>
#include <string>

#include "Queen.h"

using namespace std;

Queen::Queen(Colour colour) : Piece(colour) {
  name = "Queen";
  cout << "Queen created with colour " << pieceColour << endl;
}

Queen::~Queen () {
}

string Queen::printSymbol (){
  if (pieceColour == 0) {
    return "♕";
  }
  return "♛";
}

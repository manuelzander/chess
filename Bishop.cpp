#include <iostream>
#include <string>

#include "Bishop.h"

using namespace std;

Bishop::Bishop(Colour colour) : Piece(colour) {
  name = "Bishop";
  cout << "Bishop created with colour " << pieceColour << endl;
}

Bishop::~Bishop () {
}

string Bishop::printSymbol (){
  if (pieceColour == 0) {
    return "♗";
  }
  return "♝";
}

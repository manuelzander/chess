#include <iostream>
#include <string>

#include "King.h"

using namespace std;

King::King(Colour colour) : Piece(colour){
  name = "King";
  cout << "King created with colour " << pieceColour << endl;
}

King::~King () {
}

string King::printSymbol (){
  if (pieceColour == 0) {
    return "♔";
  }
  return "♚";
}

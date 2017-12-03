#include <iostream>
#include <string>

#include "Piece.h"

using namespace std;

Piece::Piece (Colour colour) : pieceColour(colour){
}

Piece::~Piece (){
}

string Piece::printPieceName(){
  return name;
}

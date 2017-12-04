#include <iostream>
#include <string>

#include "Bishop.h"

using namespace std;

Bishop::Bishop(Colour _colour, ChessBoard *_board) : Piece(_colour, _board){
  pieceType = BISHOP;
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

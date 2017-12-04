#include <iostream>
#include <string>

#include "Queen.h"

using namespace std;

Queen::Queen(Colour _colour, ChessBoard *_board) : Piece(_colour, _board){
  pieceType = QUEEN;
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

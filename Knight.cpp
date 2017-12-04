#include <iostream>
#include <string>

#include "Knight.h"

using namespace std;

Knight::Knight(Colour _colour, ChessBoard *_board) : Piece(_colour, _board){
  pieceType = KNIGHT;
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

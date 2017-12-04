#include <iostream>
#include <string>

#include "Rook.h"

using namespace std;

Rook::Rook(Colour _colour, ChessBoard *_board) : Piece(_colour, _board){
  pieceType = ROOK;
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

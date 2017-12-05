#include <iostream>
#include <string>

#include "Rook.h"

using namespace std;

Rook::Rook(Colour _colour, ChessBoard *_board) : Piece(_colour, _board){
  pieceType = ROOK;
}

Rook::~Rook () {
}

bool Rook::checkMoveValidity(const string from, const string to){

  // TODO
  return true;
}

string Rook::printSymbol(){
  if (pieceColour == 0) {
    return "♖";
  }
  return "♜";
}

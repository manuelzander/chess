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

bool Knight::checkMoveValidity(const string from, const string to){

  // TODO
  return true;
}

string Knight::printSymbol (){
  if (pieceColour == 0) {
    return "♘";
  }
  return "♞";
}

#include <iostream>
#include <string>

#include "Piece.h"
#include "ChessBoard.h"

using namespace std;

class ChessBoard;

Piece::Piece(Colour _colour, ChessBoard *_board) : pieceColour(_colour), board(_board){
}

Piece::~Piece(){
}

Type Piece::getPieceType(){
  return pieceType;
}

Colour Piece::getPieceColour(){
  return pieceColour;
}

string Piece::printPieceType(){
  switch(pieceType){
    case KING:
      return "King";
    case QUEEN:
      return "Queen";
    case PAWN:
      return "Pawn";
    case ROOK:
      return "Rook";
    case KNIGHT:
      return "Knight";
    case BISHOP:
      return "Bishop";
    default:
      return "Error";
  }
}

string Piece::printPieceColour(){
  switch(pieceColour){
    case WHITE:
      return "White";
    case BLACK:
      return "Black";
    default:
      return "Error";
  }
}

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

bool Piece::freeHorizontalWay(const string from, const string to){

  bool freeHorizontalWay = true;

  string start = from;
  if(from[Fi] > to[Fi]){
    start[Fi] = from[Fi] - 1;
    start[Ra] = from[Ra];

    for(string coordinate = start; coordinate[Fi] > to[Fi]; coordinate[Fi]--){
      if(!board->checkCoordinateEmpty(coordinate)){
        freeHorizontalWay = false;
        break;
      }
    }
  } else{
    start[Fi] = from[Fi] + 1;
    start[Ra] = from[Ra];

    for(string coordinate = start; coordinate[Fi] < to[Fi]; coordinate[Fi]++){
      if(!board->checkCoordinateEmpty(coordinate)){
        freeHorizontalWay = false;
        break;
      }
    }
  }
  return freeHorizontalWay;
}

bool Piece::freeVerticalWay(const string from, const string to){

  bool freeVerticalWay = true;

  string start = from;
  if(from[Ra] > to[Ra]){
    start[Ra] = from[Ra] - 1;
    start[Fi] = from[Fi];

    for(string coordinate = start; coordinate[Ra] > to[Ra]; coordinate[Ra]--){
      if(!board->checkCoordinateEmpty(coordinate)){
        freeVerticalWay = false;
        break;
      }
    }
  } else{
    start[Ra] = from[Ra] + 1;
    start[Fi] = from[Fi];

    for(string coordinate = start; coordinate[Ra] < to[Ra]; coordinate[Ra]++){
      if(!board->checkCoordinateEmpty(coordinate)){
        freeVerticalWay = false;
        break;
      }
    }
  }
  return freeVerticalWay;
}

bool Piece::freeDiagonalWay(const string from, const string to){

  bool freeDiagonalWay = true;

  string start = from;
  if(to[Ra] > from[Ra] && to[Fi] > from[Fi]){ //Right and up

    start[Ra] = from[Ra] + 1;
    start[Fi] = from[Fi] + 1;

    for(string coordinate = start; coordinate[Ra] < to[Ra] && coordinate[Fi] < to[Fi]; coordinate[Ra]++, coordinate[Fi]++){
      cout << coordinate << endl;
      if(!board->checkCoordinateEmpty(coordinate)){
        freeDiagonalWay = false;
        break;
      }
    }

    cout << "RU" << endl;

  }
  if(to[Ra] < from[Ra] && to[Fi] > from[Fi]){ //Right and down





    cout << "RD" << endl;

  }
  if(to[Ra] > from[Ra] && to[Fi] < from[Fi]){ //Left and up





    cout << "LU" << endl;

  }
  if(to[Ra] < from[Ra] && to[Fi] < from[Fi]){ //Left and down





    cout << "LD" << endl;

  }



  /*{
    start[Ra] = from[Ra] - 1;
    start[Fi] = from[Fi];

    for(string coordinate = start; coordinate[Ra] > to[Ra]; coordinate[Ra]--){
      if(!board->checkCoordinateEmpty(coordinate)){
        freeDiagonalWay = false;
        break;
      }
    }
  } else{
    start[Ra] = from[Ra] + 1;
    start[Fi] = from[Fi];

    for(string coordinate = start; coordinate[Ra] < to[Ra]; coordinate[Ra]++){
      if(!board->checkCoordinateEmpty(coordinate)){
        freeDiagonalWay = false;
        break;
      }
    }
  }*/
  return freeDiagonalWay;
}

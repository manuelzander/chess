#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>
using namespace std;

enum Colour { WHITE, BLACK };
enum Type { KING, QUEEN, PAWN, ROOK, KNIGHT, BISHOP };
enum FileRank { Fi, Ra };

class ChessBoard;

class Piece {
protected:

  Colour pieceColour;
  Type pieceType;
  ChessBoard *board;

public:
  Piece(Colour _colour, ChessBoard *_board);
  virtual ~Piece();
  //Helper function to print out unicode chess symbol
  virtual string printSymbol() = 0;
  //Getter functions
  Colour getPieceColour();
  Type getPieceType();
  string printPieceColour();
  string printPieceType();
  /*Function to check the general move validity (is the destination square of
  a move theorethically reachable and is the way to that square free*/
  virtual bool checkMoveValidity(const string from, const string to) = 0;
  /*Helper functions for the previous function to check if
  the way to reach the destination square is free*/
  bool freeHorizontalWay(const string from, const string to);
  bool freeVerticalWay(const string from, const string to);
  bool freeDiagonalWay(const string from, const string to);
};

#endif

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
  virtual string printSymbol() = 0;
  virtual bool checkMoveValidity(const string from, const string to) = 0;
  Colour getPieceColour();
  Type getPieceType();
  string printPieceColour();
  string printPieceType();
  bool freeHorizontalWay(const string from, const string to);
  bool freeVerticalWay(const string from, const string to);
  bool freeDiagonalWay(const string from, const string to);
};

#endif

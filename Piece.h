#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>
using namespace std;

enum Colour { WHITE, BLACK };
enum Type { KING, QUEEN, PAWN, ROOK, KNIGHT, BISHOP };
class ChessBoard;

class Piece {
protected:

  Colour pieceColour;
  Type pieceType;
  ChessBoard *board;

public:
  Piece(Colour _colour, ChessBoard *_board);
  virtual ~Piece() = 0;
  virtual string printSymbol() = 0;
  virtual bool checkMoveValidity(const string from, const string to) = 0;
  Colour getPieceColour();
  Type getPieceType();
  string printPieceColour();
  string printPieceType();
};

#endif

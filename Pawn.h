#ifndef PAWN_H
#define PAWN_H

#include <string>
#include <cmath>

#include "ChessBoard.h"
#include "Piece.h"

class Pawn : public Piece {
private:

public:
  Pawn (Colour _colour, ChessBoard *_board);
  ~Pawn ();
  virtual string printSymbol();
  virtual bool checkMoveValidity(const string from, const string to);
};

#endif

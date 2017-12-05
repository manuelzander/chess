#ifndef KNIGHT_H
#define KNIGHT_H

#include <string>
#include <cmath>

#include "ChessBoard.h"
#include "Piece.h"

class Knight : public Piece {
private:

public:
  Knight (Colour _colour, ChessBoard *_board);
  ~Knight ();
  virtual string printSymbol();
  virtual bool checkMoveValidity(const string from, const string to);
};

#endif

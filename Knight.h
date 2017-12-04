#ifndef KNIGHT_H
#define KNIGHT_H

#include <string>

#include "Piece.h"

class Knight : public Piece {
private:

public:
  Knight (Colour _colour, ChessBoard *_board);
  ~Knight ();
  virtual string printSymbol();
};

#endif

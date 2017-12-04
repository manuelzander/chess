#ifndef ROOK_H
#define ROOK_H

#include <string>

#include "Piece.h"

class Rook : public Piece {
private:

public:
  Rook (Colour _colour, ChessBoard *_board);
  ~Rook ();
  virtual string printSymbol();
};

#endif

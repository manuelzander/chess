#ifndef PAWN_H
#define PAWN_H

#include <string>

#include "Piece.h"

class Pawn : public Piece {
private:

public:
  Pawn (Colour colour);
  ~Pawn ();
  virtual string printSymbol();
};

#endif

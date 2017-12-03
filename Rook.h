#ifndef ROOK_H
#define ROOK_H

#include <string>

#include "Piece.h"

class Rook : public Piece {
private:

public:
  Rook (Colour colour);
  ~Rook ();
  virtual string printSymbol();
};

#endif

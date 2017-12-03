#ifndef KNIGHT_H
#define KNIGHT_H

#include <string>

#include "Piece.h"

class Knight : public Piece {
private:

public:
  Knight (Colour colour);
  ~Knight ();
  virtual string printSymbol();
};

#endif

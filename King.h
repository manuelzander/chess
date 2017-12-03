#ifndef KING_H
#define KING_H

#include <string>

#include "Piece.h"

class King : public Piece {
private:

public:
  King (Colour colour);
  ~King ();
  virtual string printSymbol();
};

#endif

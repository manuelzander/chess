#ifndef QUEEN_H
#define QUEEN_H

#include <string>

#include "Piece.h"

class Queen : public Piece {
private:

public:
  Queen (Colour colour);
  ~Queen ();
  virtual string printSymbol();
};

#endif

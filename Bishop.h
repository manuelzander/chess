#ifndef BISHOP_H
#define BISHOP_H

#include <string>

#include "Piece.h"

class Bishop : public Piece {
private:

public:
  Bishop (Colour colour);
  ~Bishop ();
  virtual string printSymbol();
};

#endif

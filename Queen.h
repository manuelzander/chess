#ifndef QUEEN_H
#define QUEEN_H

#include <string>

#include "Piece.h"

class Queen : public Piece {
private:

public:
  Queen (Colour _colour, ChessBoard *_board);
  ~Queen ();
  virtual string printSymbol();
  virtual bool checkMoveValidity(const string from, const string to);
};

#endif

#ifndef KING_H
#define KING_H

#include <string>

#include "Piece.h"

class King : public Piece {
private:

public:
  King (Colour _colour, ChessBoard *_board);
  ~King ();
  virtual string printSymbol();
  virtual bool checkMoveValidity(const string from, const string to);
};

#endif

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
  virtual bool checkMoveValidity(const string from, const string to);
};

#endif

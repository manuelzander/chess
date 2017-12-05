#ifndef BISHOP_H
#define BISHOP_H

#include <string>

#include "Piece.h"

class Bishop : public Piece {
private:

public:
  Bishop (Colour _colour, ChessBoard *_board);
  ~Bishop ();
  virtual string printSymbol();
  virtual bool checkMoveValidity(const string from, const string to);
};

#endif

#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>
using namespace std;

enum Colour { WHITE, BLACK };

class Piece {
protected:

  Colour pieceColour;
  string name;
  //Position *position;
  //ChessBoard *board;

public:
  Piece(Colour colour);
  virtual ~Piece() = 0;
  virtual string printSymbol() = 0;
  string printPieceName();
};

#endif

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <string>
#include <map>

#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Pawn.h"

using namespace std;

class ChessBoard {
private:

  map <string, Piece*> currentBoard;
  Colour currentPlayer;
  bool gameEnd;
  bool inCheck;

public:
  ChessBoard();
  ~ChessBoard();

  void insertPieces(); //Insert all pieces on board
  void deletePieces(); //Delete all pieces from board

  Colour getCurrentPlayer();

  bool checkCoordinateValidity(const string coordinate);

  void switchPlayers();
  void submitMove(const char* from, const char* to);
  void resetBoard();

  void printBoard();
};

#endif

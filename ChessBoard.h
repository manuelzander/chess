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

enum Player { WHITE_PLAYER, BLACK_PLAYER };

class ChessBoard {
private:

  map <string, Piece*> currentBoard;
  Player currentPlayer;
  bool gameEnd;
  bool inCheck;


public:
  ChessBoard();
  ~ChessBoard();

  void insertPieces(); //Insert all pieces on board
  void deletePieces(); //Delete all pieces from board

  Player getCurrentPlayer();
  void switchPlayers();
  string printPlayerColour();

  void submitMove(const char* from, const char* to);
  void resetBoard();
  
  void printBoard();
};

#endif

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
  bool pieceCaptured;
  string checking_piece;
  //string king_position;
  //string whiteKing;
  //string blackKing;

public:
  ChessBoard();
  ~ChessBoard();

  void insertPieces(); //Insert all pieces on board
  void deletePieces(); //Delete all pieces from board

  Colour getCurrentPlayer();
  Colour getOpponent();
  Colour getPieceColour(const string coordinate);
  string printColour(Colour colour);

  bool checkCoordinateValid(const string coordinate);
  bool checkCoordinateEmpty(const string coordinate);
  bool isKingInCheck(Colour colour);
  bool isKingInCheckmate(Colour colour);

  string getKingsPosition(Colour colour);
  void switchPlayers();
  void setPieceCaptured();
  void submitMove(const char* from, const char* to);
  void resetBoard();

  void printBoard();
};

#endif

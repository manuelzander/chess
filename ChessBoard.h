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
  string checking_piece;

public:
  ChessBoard();
  ~ChessBoard();
  //Function to get and/or print specific piece attributes
  Colour getCurrentPlayer();
  Colour getOpponent();
  Colour getPieceColour(const string coordinate);
  string getKingsPosition(Colour colour);
  string printColour(Colour colour);
  ///Function to check if a given square coordinate is valid (spelling etc.)
  bool checkCoordinateValid(const string coordinate);
  ///Function to check if a given square coordinate is free
  bool checkCoordinateEmpty(const string coordinate);
  //Function to check for given king in check
  bool isKingInCheck(Colour colour);
  //Function to check for given king in checkmate
  bool isKingInCheckmate(Colour colour);
  //Function to check if a given move puts a given king into check
  bool simulateMoveTocheckCheck(const string from, const string to, Colour colour);
  //Functions for general game/board operations (self-explanatory)
  void switchPlayers();
  void submitMove(const char* from, const char* to);
  void resetBoard();
  void printBoard();
  //Function to insert all pieces (pointers) on board
  void insertPieces();
  //Function to delete all pieces (pointers) from board
  void deletePieces();
};

#endif

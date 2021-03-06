#include <iostream>
#include <string>
#include <map>
#include <vector>


#include "ChessBoard.h"

using namespace std;

ChessBoard::ChessBoard(){
  currentPlayer = WHITE;
  gameEnd = false;
  checking_piece = "";
  insertPieces();
}

ChessBoard::~ChessBoard(){
  deletePieces();
}

void ChessBoard::switchPlayers(){
  currentPlayer = currentPlayer == WHITE ? BLACK : WHITE;
}

Colour ChessBoard::getCurrentPlayer(){
  return currentPlayer;
}

Colour ChessBoard::getOpponent(){
  return currentPlayer == WHITE ? BLACK : WHITE;
}

string ChessBoard::printColour(Colour colour){
  return colour == WHITE ? "White" : "Black";
}

Colour ChessBoard::getPieceColour(const string coordinate){
  return currentBoard[coordinate]->getPieceColour();
}

void ChessBoard::insertPieces(){

  currentBoard["A1"] = new Rook(WHITE, this);
  currentBoard["B1"] = new Knight(WHITE, this);
  currentBoard["C1"] = new Bishop(WHITE, this);
  currentBoard["D1"] = new Queen(WHITE, this);
  currentBoard["E1"] = new King(WHITE, this);
  currentBoard["F1"] = new Bishop(WHITE, this);
  currentBoard["G1"] = new Knight(WHITE, this);
  currentBoard["H1"] = new Rook(WHITE, this);
  for(string coordinate = "A2"; coordinate[Fi] <= 'H'; coordinate[Fi]++)
    currentBoard[coordinate] = new Pawn(WHITE, this);

  currentBoard["A8"] = new Rook(BLACK, this);
  currentBoard["B8"] = new Knight(BLACK, this);
  currentBoard["C8"] = new Bishop(BLACK, this);
  currentBoard["D8"] = new Queen(BLACK, this);
  currentBoard["E8"] = new King(BLACK, this);
  currentBoard["F8"] = new Bishop(BLACK, this);
  currentBoard["G8"] = new Knight(BLACK, this);
  currentBoard["H8"] = new Rook(BLACK, this);
  for(string coordinate = "A7"; coordinate[Fi] <= 'H'; coordinate[Fi]++)
    currentBoard[coordinate] = new Pawn(BLACK, this);

  cout << "A new chess game is started!" << endl;
}

void ChessBoard::deletePieces(){

  map <string, Piece*> ::iterator it;
  for (it = currentBoard.begin(); it != currentBoard.end(); it++){
    delete it->second;
  }
}

void ChessBoard::resetBoard(){
  currentPlayer = WHITE;
  gameEnd = false;
  deletePieces(); //Delete pointers
  currentBoard.clear(); //Delete map keys
  insertPieces();
}

void ChessBoard::submitMove(const char* from, const char* to){

  string fromCoordinate (from);
  string toCoordinate (to);

  if(gameEnd){
    cout << "The game is already over!" << endl;
    return;
  }

  if(!checkCoordinateValid(fromCoordinate) ||
     !checkCoordinateValid(toCoordinate)){
    cout << "A given coordinate is invalid!" << endl;
    return;
  }

  if(checkCoordinateEmpty(fromCoordinate)){
    cout << "There is no piece at position " << fromCoordinate << "!" << endl;
    return;
  }

  if(currentBoard[fromCoordinate]->getPieceColour() != getCurrentPlayer()){
    cout << "It is not " << currentBoard[fromCoordinate]->printPieceColour()
         << "'s turn to move!" << endl;
    return;
  }

  if (!checkCoordinateEmpty(toCoordinate)){
    if(currentBoard[fromCoordinate]->getPieceColour() ==
       currentBoard[toCoordinate]->getPieceColour()){
         cout << "One of "
              << currentBoard[fromCoordinate]->printPieceColour()
              << "'s pieces is already at position " << toCoordinate << endl;
         return;
    }
  }

  if(fromCoordinate == toCoordinate){
    cout << "The coordinates are identical!" << endl;
    return;
  }

  // Check general move validity for piece, if yes proceed, if not more is invalid
  if(!currentBoard[fromCoordinate]->checkMoveValidity(fromCoordinate, toCoordinate)){

    cout << currentBoard[fromCoordinate]->printPieceColour() << "'s "
         << currentBoard[fromCoordinate]->printPieceType() << " cannot move to "
         << toCoordinate << "!";

  // Check if move would put own king in check, if yes move is invalid...
  } else if (simulateMoveTocheckCheck(fromCoordinate, toCoordinate, getCurrentPlayer())){

    cout << currentBoard[fromCoordinate]->printPieceColour() << "'s "
         << currentBoard[fromCoordinate]->printPieceType() << " cannot move to "
         << toCoordinate << "! (Puts own king into check)" << endl;

  // ...otherwise, the move is valid!
  } else{

    cout << currentBoard[fromCoordinate]->printPieceColour() << "'s "
         << currentBoard[fromCoordinate]->printPieceType() << " moves from "
         << fromCoordinate << " to " << toCoordinate;

    // If a piece is captured, add to print out and delete the pointer to it
    if(!checkCoordinateEmpty(toCoordinate)){
      cout << " taking " << currentBoard[toCoordinate]->printPieceColour() << "'s "
           << currentBoard[toCoordinate]->printPieceType();

      delete currentBoard[toCoordinate];
    }

    // Move pieces on map and delete map key
    currentBoard[toCoordinate] = currentBoard[fromCoordinate];
    currentBoard.erase(fromCoordinate);
  }

  //Check for check, checkmate and stalemate
  if (isKingInCheck(getOpponent())) {
    if (isKingInCheckmate(getOpponent())){
      cout << endl << printColour(getOpponent())
           << " is in checkmate";
      gameEnd = true;
    } else {
      cout << endl << printColour(getOpponent())
           << " is in check";
    }
  } else if (isKingInCheckmate(getOpponent())){
      cout << endl << "Game ends in stalemate!";
      gameEnd = true;
  }

  //printBoard();
  cout << endl;
  switchPlayers();
}

bool ChessBoard::checkCoordinateEmpty(const string coordinate) {

  if(currentBoard.count(coordinate)){
    return false; //Count = 1, not empty
  }
  return true;
}

string ChessBoard::getKingsPosition(Colour colour){

  map <string, Piece*> ::iterator it;
  for (it = currentBoard.begin(); it != currentBoard.end(); it++){
    if(it->second->getPieceColour() == colour &&
    it->second->getPieceType() == KING){
      return it->first;
    }
  }
  return "Error"; // Should not happen
}

bool ChessBoard::isKingInCheck(Colour colour){

  string kings_position = getKingsPosition(colour);

  // If king is WHITE, checking_piece should be BLACK and vice-versa
  colour = colour == WHITE ? BLACK : WHITE;

  map <string, Piece*> ::iterator it;
  for (it = currentBoard.begin(); it != currentBoard.end(); it++){
    if(it->second->getPieceColour() == colour &&
      it->second->checkMoveValidity(it->first, kings_position)){
      checking_piece = it->first;
      return true;
    }
  }
  return false;
}

bool ChessBoard::isKingInCheckmate(Colour colour){

  string kings_position = getKingsPosition(colour);
  vector<string> squares;

  //Generate every board location and save in vector
  for(char file = 'A'; file <= 'H'; file++){
    for(char rank = '1'; rank <= '8'; rank++){
      string coordinate = "";
      coordinate += file;
      coordinate += rank;
      squares.push_back(coordinate);
    }
  }

  //Loop through all board locations
  for (vector<string>::iterator it = squares.begin(); it != squares.end(); it++) {
    string& coordinate = *it;
    for (vector<string>::iterator it2 = squares.begin(); it2 != squares.end(); it2++) {
      /*If a board location does not contain piece, skip it,
      otherwise --> Test for every valid move*/
      if (checkCoordinateEmpty(*it2))
        continue;

      if(currentBoard[*it2]->getPieceColour() == getOpponent() &&
         currentBoard[*it2]->checkMoveValidity(*it2, coordinate) &&
         (checkCoordinateEmpty(coordinate) || (!checkCoordinateEmpty(coordinate) &&
         currentBoard[kings_position]->getPieceColour()!=
         currentBoard[coordinate]->getPieceColour()))){

         /*For every possible valid move test if king NOT in check anymore,
         if this happens king NOT in checkmate, so return false*/
         if (simulateMoveTocheckCheck(*it2, coordinate, getOpponent()) == false)
           return false;

        }
      }
    }

  return true;
}

bool ChessBoard::simulateMoveTocheckCheck(const string from, const string to, Colour colour){

  bool KingInCheck = false, pieceCaptured = false;
  Piece* backup = NULL;

  if(!checkCoordinateEmpty(to))
    pieceCaptured = true;

  //Backup of captured piece
  if(pieceCaptured)
    backup = currentBoard[to];

  currentBoard[to] = currentBoard[from];
  currentBoard.erase(from);

  KingInCheck = isKingInCheck(colour);

  currentBoard[from] = currentBoard[to];

  //Restore captured piece
  if(pieceCaptured){
    currentBoard[to] = backup;
  } else {
    currentBoard.erase(to);
  }

  return KingInCheck;
}

void ChessBoard::printBoard() {

  cout << endl << "  +---+---+---+---+---+---+---+---+" << endl;
  for (char i = '8'; i >= '1'; i--) {
    cout << i << " ";
    for (char j = 'A'; j <= 'H'; j++) {
      cout << "|";
      string coordinate = "";
      coordinate += j;
      coordinate += i;
      if (!checkCoordinateEmpty(coordinate)){
        cout << " " << currentBoard[coordinate]->printSymbol() << " ";
      } else{
        cout << "   ";
      }
    }
    cout << "|" << endl << "  +---+---+---+---+---+---+---+---+" << endl;
  }
  cout << "    A   B   C   D   E   F   G   H" << endl << endl;

}

bool ChessBoard::checkCoordinateValid(const string coordinate) {

  if(coordinate[0] < 'A' || coordinate[0] > 'H'){
    return false;
  }
  if(coordinate[1] < '1' || coordinate[1] > '8'){
    return false;
  }
  if(coordinate.length() != 2){
    return false;
  }
  return true;
}

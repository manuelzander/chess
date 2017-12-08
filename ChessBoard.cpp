#include <iostream>
#include <string>
#include <map>

#include "ChessBoard.h"

using namespace std;

ChessBoard::ChessBoard(){
  currentPlayer = WHITE;
  gameEnd = false;
  inCheck = false;
  pieceCaptured = false;
  checking_piece = "";
  insertPieces();
}

ChessBoard::~ChessBoard(){
  deletePieces();
}

void ChessBoard::switchPlayers(){
  currentPlayer = currentPlayer == WHITE ? BLACK : WHITE;
}

void ChessBoard::setPieceCaptured(){
  pieceCaptured = pieceCaptured == false ? true : false;
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

  printBoard();
}

void ChessBoard::deletePieces(){

  map <string, Piece*> ::iterator it;
  for (it = currentBoard.begin(); it != currentBoard.end(); it++){
    delete it->second;
  }
}

void ChessBoard::resetBoard(){

  currentPlayer = WHITE;
  deletePieces();
  currentBoard.clear();
  insertPieces();
}

void ChessBoard::submitMove(const char* from, const char* to){

  string fromCoordinate (from);
  string toCoordinate (to);
  pieceCaptured = false;

  // Consider moving these checks into a seperate function
  if(gameEnd){
    cout << "The game is already over!" << endl;
    return;
  }

  if(!checkCoordinateValid(fromCoordinate)
      || !checkCoordinateValid(toCoordinate) ){
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
    cout << "The positions are identical!" << endl;
    return;
  }

  // Check move validity for that piece, if yes proceed, if not more is invalid

  // Check if move would put king in check, if yes move is invalid
  // Otherwise perform move

  if(!currentBoard[fromCoordinate]->checkMoveValidity(fromCoordinate, toCoordinate)){

    cout << currentBoard[fromCoordinate]->printPieceColour() << "'s "
         << currentBoard[fromCoordinate]->printPieceType() << " cannot move to "
         << toCoordinate << "!" << endl;

  } else{ //...a move is valid

    cout << currentBoard[fromCoordinate]->printPieceColour() << "'s "
         << currentBoard[fromCoordinate]->printPieceType() << " moves from "
         << fromCoordinate << " to " << toCoordinate;

    if(!checkCoordinateEmpty(toCoordinate))
      setPieceCaptured();

    if(pieceCaptured){
      cout << " taking " << currentBoard[toCoordinate]->printPieceColour() << "'s "
           << currentBoard[toCoordinate]->printPieceType();

      delete currentBoard[toCoordinate];
    }

    currentBoard[toCoordinate] = currentBoard[fromCoordinate];
    currentBoard.erase(fromCoordinate);
  }

  if (isKingInCheck(getOpponent())) {
    if (isKingInCheckmate(getOpponent())){
      cout << endl << printColour(getOpponent())
           << " is in checkmate";
      gameEnd = true;
    } else {
      cout << endl << printColour(getOpponent())
           << " is in check";
    }
  }

  // Check if other player is in checkmate, end game if true
  // Check for stale?

  // If checks not succeed, switch player

  printBoard();
  cout << endl;
  switchPlayers();
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

bool ChessBoard::checkCoordinateEmpty(const string coordinate) {

  if(currentBoard.count(coordinate)){
    return false; //Count = 1, not empty
  }
  return true;
}

Colour ChessBoard::getPieceColour(const string coordinate){

  return currentBoard[coordinate]->getPieceColour();

}

string ChessBoard::getKingsPosition(Colour colour){

  //Always returns the position of the opponents's king
  map <string, Piece*> ::iterator it;
  for (it = currentBoard.begin(); it != currentBoard.end(); it++){
    if(it->second->getPieceColour() == colour &&
    it->second->getPieceType() == KING){
      return it->first;
    }
  }
  return "Error"; // Will not happen
}

bool ChessBoard::isKingInCheck(Colour colour){

  string kings_position = getKingsPosition(colour);

  map <string, Piece*> ::iterator it;
  for (it = currentBoard.begin(); it != currentBoard.end(); it++){
    if(it->second->getPieceColour() == getCurrentPlayer() &&
      it->second->checkMoveValidity(it->first, kings_position)){
      checking_piece = it->first;
      return true;
    }
  }
  return false;
}

bool ChessBoard::isKingInCheckmate(Colour colour){

  cout << endl << "Test " << getOpponent() << "'s King for checkmate" << endl;

  // Possible to capture the checking piece?!
  cout << endl << "Checking piece:" << checking_piece;

  map <string, Piece*> ::iterator it;
  for (it = currentBoard.begin(); it != currentBoard.end(); it++){
    if(it->second->getPieceColour() == getOpponent() &&
      it->second->checkMoveValidity(it->first, checking_piece)){
      cout << endl << it->first << " can capture the checking piece" << endl;
      return false;
    }
  }

  // Can king move out of check?!
  string kings_position = getKingsPosition(colour);

  for(char file = 'A'; file <= 'H'; file++){
    for(char rank = '1'; rank <= '8'; rank++){
    string coordinate = "";
    coordinate += file;
    coordinate += rank;

    bool capture_king = false;

      if(currentBoard[kings_position]->checkMoveValidity(kings_position, coordinate) &&
        (checkCoordinateEmpty(coordinate) || (!checkCoordinateEmpty(coordinate) &&
          currentBoard[kings_position]->getPieceColour()!=
            currentBoard[coordinate]->getPieceColour()))){

        cout << endl << "King can move to " << coordinate;

        for (it = currentBoard.begin(); it != currentBoard.end(); it++){

          if(it->second->getPieceColour() == getCurrentPlayer() &&
            it->second->checkMoveValidity(it->first, coordinate)){
              cout << endl << it->first << " could capture the King there" << endl;
              capture_king = true;
          }

        }

        if (capture_king == false)
          return capture_king;
      }
    }
  }

  // Possible to move an opponents piece in betwee?

  /*
  For each of the oppontents pieces
   -->> Generate every possible location
   (Test validity of ever board location)

   For every such location test if king not in check
  */

  for(char file = 'A'; file <= 'H'; file++){
    for(char rank = '1'; rank <= '8'; rank++){
    string coordinate = "";
    coordinate += file;
    coordinate += rank;

    for (it = currentBoard.begin(); it != currentBoard.end(); it++){
      if(it->second->getPieceColour() == getOpponent() &&
        it->second->getPieceType() != KING &&
        it->second->checkMoveValidity(it->first, coordinate) &&
          (checkCoordinateEmpty(coordinate) || (!checkCoordinateEmpty(coordinate) &&
            currentBoard[kings_position]->getPieceColour()!=
              currentBoard[coordinate]->getPieceColour()))){

                //cout << endl << it->first << " can move to " << coordinate << endl;

                if(currentBoard[checking_piece]->checkMoveValidity(checking_piece, coordinate)){
                  cout << endl << checking_piece << " can hit " << coordinate << endl;

                  //return false;
                }

              }
      }
    }
  }




  return true;
}

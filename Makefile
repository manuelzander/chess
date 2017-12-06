chess: ChessMain.o ChessBoard.o Piece.o King.o Queen.o Knight.o Bishop.o Rook.o Pawn.o
	g++ -g ChessMain.o ChessBoard.o Piece.o King.o Queen.o Knight.o Bishop.o Rook.o Pawn.o -o chess

ChessBoard.o: ChessBoard.cpp ChessBoard.h
	g++ -Wall -g -c ChessBoard.cpp

Piece.o: Piece.cpp Piece.h ChessBoard.h
	g++ -Wall -g -c Piece.cpp

King.o: King.cpp King.h
	g++ -Wall -g -c King.cpp

Queen.o: Queen.cpp Queen.h
	g++ -Wall -g -c Queen.cpp

Knight.o: Knight.cpp Knight.h
	g++ -Wall -g -c Knight.cpp

Bishop.o: Bishop.cpp Bishop.h
	g++ -Wall -g -c Bishop.cpp

Rook.o: Rook.cpp Rook.h
	g++ -Wall -g -c Rook.cpp

Pawn.o: Pawn.cpp Pawn.h
	g++ -Wall -g -c Pawn.cpp

ChessMain.o: ChessMain.cpp ChessBoard.h
	g++ -Wall -g -c ChessMain.cpp

clean:
	rm *.o chess

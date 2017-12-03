chess: ChessMain.o ChessBoard.o
	g++ -g ChessMain.o ChessBoard.o -o chess

ChessBoard.o: ChessBoard.cpp ChessBoard.h
	g++ -Wall -g -c ChessBoard.cpp

ChessMain.o: ChessMain.cpp ChessBoard.h
	g++ -Wall -g -c ChessMain.cpp

clean:
	rm *.o chess

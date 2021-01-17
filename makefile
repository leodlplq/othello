#makefile of the othello game.

game: main.o grille.o jeton.o player.o game.o
	g++ -o game main.o grille.o jeton.o player.o game.o -Wall

main.o: main.cpp
	g++ -o main.o -c main.cpp -Wall 

grille.o: grille.cpp
	g++ -o grille.o -c grille.cpp -Wall

jeton.o : jeton.cpp
	g++ -o jeton.o -c jeton.cpp -Wall

player.o : player.cpp
	g++ -o player.o -c player.cpp -Wall 

game.o : game.cpp
	g++ -o game.o -c game.cpp -Wall
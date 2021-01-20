#makefile of the othello game.

game: main.o grille.o jeton.o player.o game.o
	g++ -o game main.o grille.o jeton.o player.o game.o -Wall -g

main.o: main.cpp
	g++ -o main.o -c main.cpp -Wall -g

grille.o: grille.cpp
	g++ -o grille.o -c grille.cpp -Wall -g

jeton.o : jeton.cpp
	g++ -o jeton.o -c jeton.cpp -Wall -g

player.o : player.cpp
	g++ -o player.o -c player.cpp -Wall -g

game.o : game.cpp
	g++ -o game.o -c game.cpp -Wall -g

all: TpMonop

TpMonop: main.o
	g++ -o TpMonop main.o joueur.o case.o plateau.o constructible.o achetable.o
	rm *.o

main.o: main.cpp joueur.o case.o plateau.o constructible.o achetable.o
	g++ -c main.cpp

joueur.o: joueur.cpp
	g++ -c joueur.cpp

case.o: case.cpp
	g++ -c case.cpp

plateau.o: plateau.cpp case.o joueur.o
	g++ -c plateau.cpp

constructible.o: constructible.cpp case.o joueur.o
	g++ -c constructible.cpp

achetable.o: achetable.cpp case.o joueur.o
	g++ -c achetable.cpp

clean:
	rm *.o
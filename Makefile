all: TpMonop

TpMonop: joueur.o case.o achetable.o gare.o constructible.o service.o plateau.o
	g++ -o TpMonop joueur.o case.o achetable.o gare.o constructible.o service.o plateau.o
	rm *.o

joueur.o: joueur.cpp
	g++ -c joueur.cpp

case.o: case.cpp
	g++ -c case.cpp

achetable.o: achetable.cpp
	g++ -c achetable.cpp 

gare.o: gare.cpp
	g++ -c gare.cpp

constructible.o: constructible.cpp
	g++ -c constructible.cpp

service.o: service.cpp
	g++ -c service.cpp

plateau.o: plateau.cpp
	g++ -c plateau.cpp

clean:
	rm *.o
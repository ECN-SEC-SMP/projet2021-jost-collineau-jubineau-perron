
all: TpMonop

TpMonop: main.o
	g++ -o TpMonop main.o joueur.o case.o plateau.o constructible.o achetable.o gare.o service.o non_achetable.o depart.o 
	rm *.o

main.o: main.cpp joueur.o case.o plateau.o achetable.o constructible.o gare.o service.o non_achetable.o depart.o 
	g++ -c main.cpp

joueur.o: joueur.cpp
	g++ -c joueur.cpp

case.o: case.cpp
	g++ -c case.cpp

plateau.o: plateau.cpp gare.o service.o constructible.o non_achetable.o case.o joueur.o depart.o
	g++ -c plateau.cpp

constructible.o: constructible.cpp case.o joueur.o
	g++ -c constructible.cpp

achetable.o: achetable.cpp case.o joueur.o
	g++ -c achetable.cpp

gare.o: gare.cpp case.o
	g++ -c gare.cpp

service.o: service.cpp case.o
	g++ -c service.cpp	

non_achetable.o: non_achetable.cpp case.o
	g++ -c non_achetable.cpp

depart.o: depart.cpp non_achetable.o
	g++ -c depart.cpp

clean:
	rm *.o
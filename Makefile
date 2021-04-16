all: main

main: main.o
	g++ -o main main.o
	rm *.o

main.o: main.cpp
	g++ -c main.cpp
	
clean:
	rm *.o
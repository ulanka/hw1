all: hw1

hw1: main.o hexdump.o encbase64.o decbase64.o
	g++ main.o hexdump.o encbase64.o decbase64.o -o hw1 -Wall

main.o: main.cpp
	g++ -c main.cpp

hexdump.o: hexdump.cpp
	g++ -c hexdump.cpp

encbase64.o: encbase64.cpp
	g++ -c encbase64.cpp

decbase64.o: decbase64.cpp
	g++ -c decbase64.cpp

clean:
	rm *o hw1

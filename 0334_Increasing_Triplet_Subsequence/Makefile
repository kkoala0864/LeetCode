CC=clang++

.PHONY:
all: exe Solution.o

exe : main.cpp Solution.o
	$(CC) -o exe main.cpp Solution.o -I.

Solution.o : Solution.cpp Solution.h
	$(CC) -o Solution.o -c Solution.cpp -I.

clean : 
	rm *.o exe

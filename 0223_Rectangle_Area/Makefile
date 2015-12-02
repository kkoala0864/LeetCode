CC=g++

.PHONY : all
all : exe

exe : main.cpp Solution.o
	$(CC) -o exe main.cpp Solution.o -I.

Solution.o : Solution.cpp Solution.h
	$(CC) -c Solution.cpp -o Solution.o -I.

clean :
	rm *.o exe

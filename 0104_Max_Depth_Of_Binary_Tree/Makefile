CC=g++

.PHONY : all
all : exe

exe : main.cpp Solution.o
	$(CC) -o exe main.cpp Solution.o -I.

Solution.o : Solution.h Solution.cpp
	$(CC) -c Solution.cpp -o Solution.o -I.

clean :
	rm *.o exe

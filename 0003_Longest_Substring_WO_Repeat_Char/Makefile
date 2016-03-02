CC=g++

CFLAGS= -std=c++11
all : exe
.PHONY: all

exe : main.cpp Solution.o
	$(CC) -o exe main.cpp Solution.o -I. -g ${CFLAGS}

Solution.o : Solution.cpp Solution.h
	$(CC) -c Solution.cpp -o Solution.o -I. -g ${CFLAGS}

.PHONY: clean
clean :
	rm Solution.o exe

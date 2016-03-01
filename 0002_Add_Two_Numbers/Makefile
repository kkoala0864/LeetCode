CC=g++


all : exe
.PHONY: all

exe : main.cpp Solution.o
	$(CC) -o exe main.cpp Solution.o -I. -g

Solution.o : Solution.cpp Solution.h
	$(CC) -c Solution.cpp -o Solution.o -I. -g

.PHONY: clean
clean :
	rm Solution.o exe

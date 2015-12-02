CC=g++
INC_DIR=../include/
LIB_DIR=../ChaosLib/
.PHONY:
all: exe Solution.o

exe : main.cpp Solution.o
	$(CC) -o exe main.cpp Solution.o -I. -I${INC_DIR} -L${LIB_DIR}

Solution.o : Solution.cpp Solution.h
	$(CC) -o Solution.o -c Solution.cpp -I. -I${INC_DIR} -L${LIB_DIR}

clean : 
	rm *.o exe

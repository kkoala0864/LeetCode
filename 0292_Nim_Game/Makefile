CC=gcc
CXX=g++

SRC=$(filter-out main.cpp,$(wildcard *.cpp))
STATIC_OBJ=$(SRC:%.cpp=%.o)
CFLAGS+=-O3
CXXFLAGS+=-O3
INC_PATH=-I. -I../include/
LIB_DIR=-L../ChaosLib/


.PHONY:
all: exe

exe : main.cpp $(STATIC_OBJ)
	$(CXX) $(CXXFLAGS) -o exe $< $(STATIC_OBJ) $(INC_PATH) $(LIB_DIR)

$(STATIC_OBJ) : $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(INC_PATH) $(LIB_DIR)

clean : 
	rm *.o exe

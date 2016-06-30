CC=gcc
CXX=g++

SRC=$(filter-out main.cpp,$(wildcard *.cpp))
STATIC_OBJ=$(SRC:%.cpp=%.o)
CFLAGS+=-O3
CXXFLAGS+=-O3
INC_PATH=-I.


.PHONY:
all: exe

exe : main.cpp $(STATIC_OBJ)
	$(CXX) $(CXXFLAGS) -o exe $< $(STATIC_OBJ) $(INC_PATH)

$(STATIC_OBJ) : $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(INC_PATH)

clean : 
	rm *.o exe

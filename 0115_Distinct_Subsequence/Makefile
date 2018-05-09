CXX=g++

SRC=$(filter-out main.cpp,$(wildcard *.cpp))
STATIC_OBJ=$(SRC:%.cpp=%.o)
CXXFLAGS+=-O3 -std=c++11
INC_PATH=.
deps := $(SRC:%.cpp=.%.o.d)

.PHONY:
all: exe

exe : main.cpp $(STATIC_OBJ)
	$(CXX) $(CXXFLAGS) -o exe $< $(STATIC_OBJ) -I$(INC_PATH)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< -I$(INC_PATH) -MMD -MF .$@.d

clean :
	rm $(STATIC_OBJ) exe $(deps)

-include $(deps)

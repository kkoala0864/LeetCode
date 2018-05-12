CXX=clang++

SRC=$(filter-out main.cpp,$(wildcard *.cpp))
STATIC_OBJ=$(SRC:%.cpp=%.o)
CFLAGS+=-O3
CXXFLAGS+=-O0 -std=c++14 -g
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

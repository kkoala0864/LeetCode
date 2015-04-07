CC=g++
ChaosLibPath=../ChaosLib
VPATH=$(ChaosLibPath)

all: libchaos exe

exe: main.h main.cpp
	$(CC) main.h main.cpp -I$(ChaosLibPath) -L$(ChaosLibPath) -lchaos -Wl,-rpath=$(ChaosLibPath) -o exe -std=c++11 

.PHONY: libchaos
libchaos:
	@make -C $(ChaosLibPath) -f ChaosLib.mk

clean:
	cd $(ChaosLibPath); make -f ChaosLib.mk clean
	rm exe

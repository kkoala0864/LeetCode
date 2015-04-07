CC=g++

libchaos.so: libchaos.so.1.0.1
	ln -sf libchaos.so.1.0.1 libchaos.so.1
	ln -sf libchaos.so.1.0.1 libchaos.so

libchaos.so.1.0.1: qsort.o
	$(CC) -shared -Wl,-soname,libchaos.so.1 -o libchaos.so.1.0.1 qsort.o -lc

qsort.o: ChaosLib.h qsort.cpp
	$(CC) -fPIC -c qsort.cpp

clean:
	rm *.so.* *.so *.o

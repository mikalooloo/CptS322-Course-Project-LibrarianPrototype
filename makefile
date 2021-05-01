CC=g++
CFLAGS=-g -Wall -std=c++11
DEPS = classes.hpp
OBJ = main.cpp functions.cpp

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
library: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
clean:
	-rm *.o

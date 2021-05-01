CC=g++
CFLAGS=-g -Wall -std=c++11
DEPS = 
OBJ = main.cpp classes.cpp functions.cpp

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
pa3: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
clean:
	-rm *.o

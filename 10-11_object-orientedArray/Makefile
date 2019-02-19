CC = clang++
CFLAGS = -Wall -Wextra -c -std=c++11
DEPS = array.h
 
%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

array: array.o test_array.o
	$(CC) -o array array.o test_array.o

clean:
	rm -f *.o core* *~ array
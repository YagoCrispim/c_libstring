CFLAGS = -Wall -Wextra -I.
CC = gcc

test: test.o lib_string.o
	$(CC) $(CFLAGS) $? -o $@

test.o: test.c
	$(CC) $(CFLAGS) -c $? -o $@

lib_string.o: lib_string.c
	$(CC) $(CFLAGS) -c $? -o $@

clean:
	rm ./*.o

cleanall:
	rm -f ./test
	rm -f ./debug
	rm -f ./*.o


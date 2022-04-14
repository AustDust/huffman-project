CFLAGS = -O
CC = g++

main: main.o
	$(CC) $(CFLAGS) -o main main.O

clean:
	rm -f core *.o main
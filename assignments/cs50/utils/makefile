CC=gcc
CFLAGS=-g -std=c11 -Wall -pedantic
OBJECTS= hashtable.o file.o web.o indexer.o

file: ./file.c $(HEADERS)
	$(CC) $(CFLAGS) -o file.o -c file.c 

web: ./web.c $(HEADERS)
	$(CC) $(CFLAGS) -o web.o -c web.c 

hashtable: ./hashtable.c $(HEADERS)
	$(CC) $(CFLAGS) -o hashtable.o -c hashtable.c 

indexer.o: ./indexer.c $(HEADERS)
	$(CC) $(CFLAGS) -o indexer.o -c indexer.c


libtseutil:
	make clean
	make file
	make web
	make hashtable
	make indexer.o
	ar -cvq libtseutil.a *.o

clean:
	rm -f *.o
	rm -f *.a
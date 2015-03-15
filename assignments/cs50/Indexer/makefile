CC=gcc
CFLAGS=-g -std=c11 -Wall -pedantic
OBJECTS= obj/hashtable.o obj/file.o obj/web.o
TARGET=src/indexer.c
HEADERS=./src/indexer.h ./src/file.h ./src/web.h ./src/hashtable.h

index: ./src/indexer.c $(HEADERS)
	make clean
	make hashtable
	make file
	make web 
	$(CC) $(CFLAGS) -o indexer $(TARGET) -L. -lutils

file: ./src/file.c $(HEADERS)
	$(CC) $(CFLAGS) -o obj/file.o -c ./src/file.c 

web: ./src/web.c $(HEADERS)
	$(CC) $(CFLAGS) -o obj/web.o -c ./src/web.c 

hashtable: ./src/hashtable.c $(HEADERS)
	$(CC) $(CFLAGS) -o obj/hashtable.o -c ./src/hashtable.c 

indexer.o: ./src/indexer.c $(HEADERS)
	$(CC) $(CFLAGS) -o obj/indexer.o -c ./src/indexer.c

clean:
	rm -f *~
	rm -f *#
	rm -rf *.dSYM
	rm -f ./indexer
	rm -f ./obj/*.o

clean_0:
	rm -f ./data/*
	rm -f *.dat
	cp -f ../crawler/data/1 ./data/1
clean_1:
	rm -f *.dat
	rm -f ./data/*
	cp -f ../crawler/data/1 ./data/1
	cp -f ../crawler/data/2 ./data/2
	cp -f ../crawler/data/3 ./data/3
	cp -f ../crawler/data/4 ./data/4
	cp -f ../crawler/data/5 ./data/5
	cp -f ../crawler/data/6 ./data/6
	cp -f ../crawler/data/7 ./data/7
clean_2:
	rm -f *.dat
	rm -f ./data/*
	cp -rf ../crawler/data/ ./data/

clean_3:
	rm -f *~
	rm -f *#
	rm -rf *.dSYM
	rm -f ./indexer
	rm -f ./obj/*.o
	rm -f *.dat
	rm -f ./data/*



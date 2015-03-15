CC=gcc
CFLAGS=-g -std=c11 -Wall -pedantic
OBJECTS=obj/web.o obj/list.o obj/hashtable.o 
TARGET=src/crawler.c
SOURCES=./src/crawler.c ./src/list.c ./src/web.c
HEADERS=./src/crawler.h ./src/list.h ./src/web.h

crawl:  $(OBJECTS)
	make clean
	make list.o
	make web.o
	make hashtable.o
	$(CC) $(CFLAGS) -o crawler $(TARGET) -lcurl $(OBJECTS) 

obj/%.o: src/%.c
	$(CC) -c $< -o $@
crawler.o: ./src/crawler.c $(HEADERS)
	$(CC) $(CFLAGS) -o obj/crawler.o -c src/crawler.c 
list.o: ./src/list.c $(HEADERS)
	$(CC) $(CFLAGS) -o obj/list.o -c ./src/list.c 
web.o: ./src/web.c $(HEADERS)
	$(CC) $(CFLAGS) -o obj/web.o -c ./src/web.c 
hashtable.o: ./src/hashtable.c $(HEADERS)
	$(CC) $(CFLAGS) -o obj/hashtable.o -c ./src/hashtable.c 
clean:
	rm -f *~
	rm -f *#
	rm -rf *.dSYM
	rm -f ./crawler
	rm -f ./obj/*.o
	rm -f ./data/*

CC=gcc
CFLAGS=-g -std=c11 -Wall -pedantic
TARGET=query.c query_functions.c
HEADERS=query.h query_functions.h

querier: ./query.c $(HEADERS)
	make clean
	$(CC) $(CFLAGS) -o querier $(TARGET) -L../../utils  -ltseutil

test: ./test/units.c $(HEADERS) ./test/units.h
	$(CC) $(CFLAGS) -o ./test/units ./test/units.c query_functions.c -L../../utils -ltseutil

clean:
	rm -f *~
	rm -f *#
	rm -rf *.dSYM
	rm -f ./querier
	rm -f ./obj/*.o
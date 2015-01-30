CC=gcc
CFLAGS=-g -std=c11 -Wall -pedantic
TARGET=weather

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c -lcurl mycurl.c
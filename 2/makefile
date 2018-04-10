CC=g++
CFLAGS=-c -Wall

all: FileDB

FileDB: main.o func.o files.o
		$(CC) main.o func.o files.o -o FileDB

main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp

func.o: func.cpp
		$(CC) $(CFLAGS) func.cpp

files.o: files.cpp
		$(CC) $(CFLAGS) files.cpp
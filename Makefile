all: main

CC = gcc

main: main.o
	$(CC) main.c -o main

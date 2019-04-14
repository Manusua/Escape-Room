########################################################
CC = gcc
FLAGS= -g -Wall -pedantic -ansi
########################################################


all: set clean 

set: set.o set_test.o
	$(CC) $(FLAGS) -o set $^

set.o: set.c set.h types.h
	$(CC) $(FLAGS) -c set.c

set_test.o: set_test.c
	$(CC) $(FLAGS) -c set_test.c


clean:
	rm -rf *.o 


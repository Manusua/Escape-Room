########################################################
CC = gcc
FLAGS= -g -Wall -pedantic -ansi
########################################################


all: die clean

die: die.o die_test.o
	$(CC) $(FLAGS) -o die $^

die.o: die.c die.h types.h
	$(CC) $(FLAGS) -c die.c

die_test.o: die_test.c
	$(CC) $(FLAGS) -c die_test.c


clean:
	rm -rf *.o

########################################################
CC = gcc
FLAGS= -g -Wall -pedantic -ansi
########################################################


all: ocabas clean dist

ocabas: space.o game.o command.o game_loop.o graphic_engine.o screen.o GameReader.o player.o object.o set.o die.o
	$(CC) $(FLAGS) -o ocabas $^

game_loop.o: game_loop.c graphic_engine.h
	$(CC) $(FLAGS) -c game_loop.c

set.o: set.c set.h
		$(CC) $(FLAGS) -c set.c

space.o: space.c space.h  set.h
	$(CC) $(FLAGS) -c space.c

game.o: game.c game.h command.h space.h GameReader.h
	$(CC) $(FLAGS) -c game.c

command.o: command.c command.h
	$(CC) $(FLAGS) -c command.c

graphic_engine.o : graphic_engine.c graphic_engine.h screen.h game.h
	$(CC) $(FLAGS) -c graphic_engine.c

screen.o: screen.c screen.h
	$(CC) $(FLAGS) -c screen.c

GameReader.o: GameReader.c GameReader.h space.h
	$(CC) $(FLAGS) -c GameReader.c

player.o: player.c player.h
	$(CC) $(FLAGS) -c player.c


object.o: object.c object.h
	$(CC) $(FLAGS) -c object.c

die.o: die.c die.h
		$(CC) $(FLAGS) -c die.c

clean:
	rm -rf *.o

dist:
	tar -cvzf dist.tgz *c *h *dat makefile

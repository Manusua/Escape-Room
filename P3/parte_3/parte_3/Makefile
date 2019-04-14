########################################################
CC = gcc
CFLAGS = -Wall -ansi -pedantic
EJS = game_loop.o game.o screen.o space.o graphic_engine.o command.o player.o object.o game_reader.o set.o die.o
########################################################

all: ocabas set_test die_test link_test dist.tgz clean

ocabas: $(EJS)
	$(CC) $(CFLAGS) -o ocabas $(EJS)

game_loop.o:graphic_engine.h game_reader.h
	$(CC) $(CFLAGS) -c game_loop.c

game.o: game.c game.h command.h space.h
	$(CC) $(CFLAGS) -c game.c

command.o: command.c command.h
	$(CC) $(CFLAGS) -c command.c

space.o: space.c space.h
	$(CC) $(CFLAGS) -c space.c

graphic_engine.o: graphic_engine.c graphic_engine.h game.h screen.h
		$(CC) $(CFLAGS) -c 	graphic_engine.c

screen.o: screen.c screen.h
	$(CC) $(CFLAGS) -c screen.c

player.o: player.c player.h
	$(CC) $(CFLAGS) -c player.c

object.o: object.c object.h
	$(CC) $(CFLAGS) -c object.c

game_reader.o: game_reader.c game_reader.h game.h
	$(CC) $(CFLAGS) -c game_reader.c

set_test:set_test.o set.o
	$(CC) $(CFLAGS) -o set_test set_test.o set.o

set_test.o: set_test.c set.h
		$(CC) $(CFLAGS) -c set_test.c

set.o: set.c set.h
		$(CC) $(CFLAGS) -c set.c

die_test: die_test.o die.o
		$(CC) $(CFLAGS) -o die_test die_test.o die.o

die_test.o: die_test.c die.h
		$(CC) $(CFLAGS) -c die_test.c

die.o: die.c die.h
		$(CC) $(CFLAGS) -c die.c

inventory.o: inventory.c inventory.h
		$(CC) $(CFLAGS) -c inventory.c

inventory_test: inventory_test.o inventory.o
		$(CC) $(CFLAGS) -o inventory_test inventory_test.o inventory.o

inventory_test.o: inventory_test.c inventory.h
		$(CC) $(CFLAGS) -c inventory_test.c

link.o: link.c link.h
		$(CC) $(CFLAGS) -c link.c

link_test: link_test.o link.o
		$(CC) $(CFLAGS) -o link_test link_test.o link.o

link_test.o: link_test.c link.h
		$(CC) $(CFLAGS) -c link_test.c


dist.tgz:
	tar -cvzf ocabas.tgz *.c *.h Makefile

clean:
	rm -rf *.o

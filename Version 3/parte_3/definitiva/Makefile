########################################################
CC = gcc
CFLAGS = -Wall -ansi -pedantic -I include
EJS = game_loop.o game.o screen.o space.o graphic_engine.o command.o player.o object.o game_reader.o set.o die.o inventory.o link.o
########################################################

all: ocabas set_test die_test link_test dist.tgz clean doc

ocabas: $(EJS)
	$(CC) $(CFLAGS) -o ocabas $(EJS)

game_loop.o: include/graphic_engine.h include/game_reader.h
	$(CC) $(CFLAGS) -c src/game_loop.c

game.o: src/game.c include/game.h include/command.h include/space.h include/link.h include/die.h include/player.h include/object.h
	$(CC) $(CFLAGS) -c src/game.c

command.o: src/command.c include/command.h
	$(CC) $(CFLAGS) -c src/command.c

space.o: src/space.c include/space.h
	$(CC) $(CFLAGS) -c src/space.c

graphic_engine.o: src/graphic_engine.c include/graphic_engine.h include/game.h include/screen.h
		$(CC) $(CFLAGS) -c 	src/graphic_engine.c

screen.o: src/screen.c include/screen.h
	$(CC) $(CFLAGS) -c src/screen.c

player.o: src/player.c include/player.h include/inventory.h
	$(CC) $(CFLAGS) -c src/player.c

object.o: src/object.c include/object.h
	$(CC) $(CFLAGS) -c src/object.c

game_reader.o: src/game_reader.c include/game_reader.h include/game.h
	$(CC) $(CFLAGS) -c src/game_reader.c

set_test:set_test.o set.o
	$(CC) $(CFLAGS) -o set_test set_test.o set.o

set_test.o: src/set_test.c include/set.h
		$(CC) $(CFLAGS) -c src/set_test.c

set.o: src/set.c include/set.h
		$(CC) $(CFLAGS) -c src/set.c

die_test: die_test.o die.o
		$(CC) $(CFLAGS) -o die_test die_test.o die.o

die_test.o: src/die_test.c include/die.h
		$(CC) $(CFLAGS) -c src/die_test.c

die.o: src/die.c include/die.h
		$(CC) $(CFLAGS) -c src/die.c

inventory.o: src/inventory.c include/inventory.h
		$(CC) $(CFLAGS) -c src/inventory.c

inventory_test: inventory_test.o inventory.o
		$(CC) $(CFLAGS) -o inventory_test inventory_test.o inventory.o

inventory_test.o: src/inventory_test.c include/inventory.h
		$(CC) $(CFLAGS) -c src/inventory_test.c

link.o: src/link.c include/link.h
		$(CC) $(CFLAGS) -c src/link.c

link_test: link_test.o link.o
		$(CC) $(CFLAGS) -o link_test link_test.o link.o

link_test.o: src/link_test.c include/link.h
		$(CC) $(CFLAGS) -c src/link_test.c
doc:
	doxygen

dist.tgz:
	tar -cvzf ocabas.tgz src/*.c include/*.h Makefile

clean:
	rm -rf *.o
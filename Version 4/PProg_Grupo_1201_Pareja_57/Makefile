########################################################
CC = gcc
CFLAGS = -Wall -ansi -pedantic -I include
EJS = game_loop.o game.o screen.o space.o graphic_engine.o command.o player.o object.o game_management.o set.o die.o inventory.o link.o dialogue.o game_rules.o
########################################################

all: ocabas set_test die_test link_test inventory_test command_test player_test space_test dist.tgz mov docu

ocabas: $(EJS)
	$(CC) $(CFLAGS) -o ocabas $(EJS)

game_loop.o: include/graphic_engine.h include/game_management.h
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

game_management.o: src/game_management.c include/game_management.h include/game.h
	$(CC) $(CFLAGS) -c src/game_management.c

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
		$(CC) $(CFLAGS) -o inventory_test inventory_test.o inventory.o set.o

inventory_test.o: src/inventory_test.c include/inventory.h
		$(CC) $(CFLAGS) -c src/inventory_test.c

link.o: src/link.c include/link.h
		$(CC) $(CFLAGS) -c src/link.c

link_test: link_test.o link.o
		$(CC) $(CFLAGS) -o link_test link_test.o link.o

link_test.o: src/link_test.c include/link.h
		$(CC) $(CFLAGS) -c src/link_test.c
player_test: player_test.o player.o
		$(CC) $(CFLAGS) -o player_test player_test.o player.o inventory.o set.o

player_test.o: src/player_test.c include/player.h
		$(CC) $(CFLAGS) -c src/player_test.c
command_test: command_test.o command.o
		$(CC) $(CFLAGS) -o command_test command_test.o command.o

command_test.o: src/command_test.c include/command.h
		$(CC) $(CFLAGS) -c src/command_test.c
space_test: space_test.o space.o
		$(CC) $(CFLAGS) -o space_test space_test.o space.o set.o

space_test.o: src/space_test.c include/space.h
		$(CC) $(CFLAGS) -c src/space_test.c

dialogue.o: src/dialogue.c include/command.h include/dialogue.h
		$(CC) $(CFLAGS) -c src/dialogue.c
game_rules.o: src/game_rules.c include/game.h include/game_rules.h
		$(CC) $(CFLAGS) -c src/game_rules.c
docu:	src/*.c include/*.h
	doxygen doc/Doxyfile

dist.tgz:
	tar -cvzf ocabas.tgz src/*.c include/*.h Makefile

mov:
	mv *.o obj/
clean:
	rm -rf obj/*.o

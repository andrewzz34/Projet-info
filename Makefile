CFLAGS=-W -Wall -ggdb
EXE=cyfish

all: cyfish

cyfish: main.o player.o affichage.o
	gcc -o $@ $^

main.o: main.c player.c affichage.c
	gcc -o $@ -c $< $(CFLAGS)
	
player.o: player.c
	gcc -o $@ -c $< $(CFLAGS)

affichage.o: affichage.c
	gcc -o $@ -c $< $(CFLAGS)
	
clean:
	rm -rf *.o
	rm -rf $(EXE)
	

	

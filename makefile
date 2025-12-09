CC=gcc 
CFLAGS=-Wall -g 

all: lab3 

lab3: main.o fil.o 
	$(CC) $(CFLAGS) main.o fil.o -o lab3 

main.o: main.c fil.h 
	$(CC) $(CFLAGS) -c main.c 

fil.o: fil.c fil.h 
	$(CC) $(CFLAGS) -c fil.c 

clean: 
	rm -f * .o lab3

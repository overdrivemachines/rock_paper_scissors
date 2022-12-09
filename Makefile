
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

rock_paper_scissors: rock_paper_scissors.o
	$(CC) $(CFLAGS) -o rock_paper_scissors rock_paper_scissors.o

rock_paper_scissors.o: rock_paper_scissors.cpp
	$(CC) $(CFLAGS) -c rock_paper_scissors.cpp

clean:
	rm -rf rock_paper_scissors rock_paper_scissors.o

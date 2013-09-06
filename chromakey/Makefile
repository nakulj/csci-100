# July 23, 2008
# Name: Mark Redekopp
# email: redekopp@usc.edu

CC = g++
CFLAGS = -g -Wall
LDFLAGS =
SRCS = 	chromakey.cpp


all: $(SRCS) chromakey

.cpp.o:
	$(CC) $(CFLAGS) -c $<

chromakey : chromakey.o bmplib.h
	@echo "chromakey"
	@echo "Compiling and linking"
	$(CC) $(CFLAGS) chromakey.o bmplib.o -o chromakey

clean:
	rm -f chromakey chromakey.o  *~
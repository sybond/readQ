# Makefile good
CCFLAGS = -Wno-write-strings
CC = g++
readQ: readq_main.c 
	$(CC) $(CCFLAGS) readq_main.c bnd_util.c bnd_util.h -o readQ

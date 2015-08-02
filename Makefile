# Makefile for dtoa-test

CC = gcc
CFLAGS = -Wall -gdwarf-2 -g3 -O0
RM = rm -f

obj = dtoa-test.o 

%.o : %.c
	$(CC) -c $(CFLAGS) $<


.PHONY: all
all: dtoa-test

dtoa-test: $(obj)
	$(CC) -o $@ $(obj)

dtoa-test.o: dtoa-test.c

.PHONY: clean
clean:
	$(RM) *.o
	$(RM) dtoa-test

# end of Makefile


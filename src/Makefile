IDIR=../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=../obj
LDIR=../lib

#LIBS=-lm

_DEPS=blackjack.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=blackjack.o blackjackfunc.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

blackjack: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

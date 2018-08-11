IDIR=../include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=../obj
LDIR=../lib

#LIBS=-lm

_DEPS=blackjack.hpp
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=blackjack.o blackjackfunc.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -std=c++11 -c -o $@ $< $(CFLAGS)

blackjack: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

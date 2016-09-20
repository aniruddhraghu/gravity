# Define project name here
PROJECT = gravity

IDIR = ./
CC=g++

CFLAGS=-I$(IDIR) -Wall
ODIR=./

LIBS=-lm

_DEPS = %.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o body.o gravity.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ)) 

ibtasks: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(ODIR)/%.o: %.cpp $(DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ ./ibtasks

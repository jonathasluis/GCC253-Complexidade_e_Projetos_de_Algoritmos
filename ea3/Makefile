# teste
CC = gcc
BINS = bin 

# Criar executaveis a partir de objetos usando compilador de C++
%: %.o
	$(CC) $@.o  -o $@

all: $(BINS)

clean:
	rm -f *.o $(BINS)

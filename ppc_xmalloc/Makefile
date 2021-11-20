all: ppc_xmalloc_test1.txt ppc_xmalloc_test2.txt

CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -O2

ppc_xmalloc_test1: ppc_xmalloc.o ppc_xmalloc_test1.o
	$(CC) ppc_xmalloc.o ppc_xmalloc_test1.o -o $@
ppc_xmalloc_test2: ppc_xmalloc.o ppc_xmalloc_test2.o
	$(CC) ppc_xmalloc.o ppc_xmalloc_test2.o -o $@
	
ppc_xmalloc_test1.txt: ppc_xmalloc_test1
	./ppc_xmalloc_test1 > ppc_xmalloc_test1.txt
ppc_xmalloc_test2.txt: xmalloc_test2
	./ppc_xmalloc_test2 > ppc_xmalloc_test2.txt
	
clean:
	rm -f ppc_xmalloc.o ppc_xmalloc_test1.o ppc_xmalloc_test2.o ppc_xmalloc_test1 ppc_xmalloc_test2 ppc_xmalloc_test1.txt ppc_xmalloc_test2.txt

CC = gcc
OPTC = -O3 -ffast-math -funroll-loops -ftree-vectorize -march=native -fopenmp

######################################################################################
# This uses regular BLAS (assuming you have everything included in $PATH
######################################################################################
IBLAS = 
LBLAS = 
BLASLIBS = -lblas
######################################################################################


######################################################################################
# This uses ACML
######################################################################################
#IBLAS = -L/opt/acml4.4.0/gfortran64/lib/
#LBLAS = -I/opt/acml4.4.0/gfortran64/include/
#BLASLIBS = -lacml -lacml_mv
######################################################################################

HEADERS = pdblas.h

all: peri1d

peri1d: peri1d.o pdblas.o
	$(CC) $(OPTC) $(LBLAS) peri1d.o pdblas.o -o peri1d -lm $(BLASLIBS)

peri1d.o: peri1d.c $(HEADERS)
	$(CC) -c $(IACML) $(OPTC) peri1d.c -o peri1d.o

pdblas.o: pdblas.c $(HEADERS)
	$(CC) -c $(IBLAS) pdblas.c -o pdblas.o

clean:
	rm -fr peri1d.o
	rm -fr peri1d

#! /bin/bash
#
gcc -c -Wall -I$HOME/include umfpack_simple.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#gcc umfpack_simple.o -L/usr/local/lib -L/$HOME/lib -lumfpack -lamd -lcholmod -lcolamd -lm \
#  -lsuitesparseconfig -lblas
gfortran umfpack_simple.o -L/usr/local/lib -L/$HOME/lib -lumfpack -lamd -lcholmod -lcolamd -lm \
  -lsuitesparseconfig -lblas
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm umfpack_simple.o
mv a.out umfpack_simple
#
./umfpack_simple > umfpack_simple.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm umfpack_simple
#
#  Terminate.
#
echo "Normal end of execution."

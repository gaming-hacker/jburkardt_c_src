#! /bin/bash
#
gcc -c -Wall -I/usr/local/include umfpack_west.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gfortran umfpack_west.o -L/usr/local/lib -L/$HOME/lib -lumfpack -lamd -lcholmod -lcolamd -lm \
  -lsuitesparseconfig -lblas
#gcc umfpack_west.o -L/usr/local/lib -L/$HOME/lib -lumfpack -lamd -lcholmod -lcolamd -lm \
#  -lsuitesparseconfig -lblas
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm umfpack_west.o
mv a.out umfpack_west
#
./umfpack_west > umfpack_west.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm umfpack_west
#
echo "Normal end of execution."

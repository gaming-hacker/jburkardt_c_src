#! /bin/bash
#
gcc -c -Wall -I/usr/local/include umfpack_wathen.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gfortran umfpack_wathen.o -L/usr/local/lib -L/$HOME/lib -lumfpack -lamd -lcholmod -lcolamd -lm \
  -lsuitesparseconfig -lblas
#gcc umfpack_wathen.o -L/usr/local/lib -L/$HOME/lib -lumfpack -lamd -lcholmod -lcolamd -lm \
#  -lsuitesparseconfig -lblas
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm umfpack_wathen.o
mv a.out umfpack_wathen
#
./umfpack_wathen > umfpack_wathen.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm umfpack_wathen
#
#  Terminate.
#
echo "Normal end of execution."

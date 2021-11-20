#! /bin/bash
#
gcc -c -Wall -I/$HOME/include quadrature_golub_welsch_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc quadrature_golub_welsch_test.o /$HOME/libc/quadrature_golub_welsch.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm quadrature_golub_welsch_test.o
#
mv a.out quadrature_golub_welsch_test
./quadrature_golub_welsch_test > quadrature_golub_welsch_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quadrature_golub_welsch_test
#
echo "Normal end of execution."

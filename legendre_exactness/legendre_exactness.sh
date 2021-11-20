#! /bin/bash
#
gcc -c -Wall legendre_exactness.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc legendre_exactness.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm legendre_exactness.o
#
chmod ugo+x a.out
mv a.out ~/binc/legendre_exactness
#
echo "Normal end of execution."

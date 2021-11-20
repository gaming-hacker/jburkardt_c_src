#! /bin/bash
#
gcc -c -Wall hermite_exactness.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc hermite_exactness.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm hermite_exactness.o
#
chmod ugo+x a.out
mv a.out ~/binc/hermite_exactness
#
echo "Normal end of execution."

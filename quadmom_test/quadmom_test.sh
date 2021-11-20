#! /bin/bash
#
gcc -c -Wall -I/$HOME/include quadmom_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc quadmom_test.o /$HOME/libc/quadmom.o  /$HOME/libc/toms655.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm quadmom_test.o
#
mv a.out quadmom_test
./quadmom_test > quadmom_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quadmom_test
#
echo "Normal end of execution."

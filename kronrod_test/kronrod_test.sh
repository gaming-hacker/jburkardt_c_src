#! /bin/bash
#
gcc -c -Wall -I/$HOME/include kronrod_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc kronrod_test.o /$HOME/libc/kronrod.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm kronrod_test.o
#
mv a.out kronrod_test
./kronrod_test > kronrod_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm kronrod_test
#
echo "Normal end of execution."

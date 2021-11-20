#! /bin/bash
#
gcc -c -Wall -I/$HOME/include bellman_ford_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc bellman_ford_test.o /$HOME/libc/bellman_ford.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm bellman_ford_test.o
#
mv a.out bellman_ford_test
./bellman_ford_test > bellman_ford_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm bellman_ford_test
#
echo "Normal end of execution."

#! /bin/bash
#
gcc -c -Wall -I/$HOME/include edge_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc edge_test.o /$HOME/libc/edge.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm edge_test.o
#
mv a.out edge_test
./edge_test > edge_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm edge_test
#
echo "Normal end of execution."

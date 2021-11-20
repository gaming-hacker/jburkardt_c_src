#! /bin/bash
#
gcc -c -Wall -I/$HOME/include polyominoes_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o polyominoes_test polyominoes_test.o /$HOME/libc/polyominoes.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm polyominoes_test.o
#
./polyominoes_test > polyominoes_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm polyominoes_test
#
echo "Normal end of execution."

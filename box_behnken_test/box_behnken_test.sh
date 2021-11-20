#! /bin/bash
#
gcc -c -Wall -I/$HOME/include box_behnken_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc box_behnken_test.o /$HOME/libc/box_behnken.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm box_behnken_test.o
#
mv a.out box_behnken_test
./box_behnken_test > box_behnken_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm box_behnken_test
#
echo "Normal end of execution."

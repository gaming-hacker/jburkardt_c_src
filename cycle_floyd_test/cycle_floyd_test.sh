#! /bin/bash
#
gcc -c -Wall -I/$HOME/include cycle_floyd_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc cycle_floyd_test.o /$HOME/libc/cycle_floyd.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cycle_floyd_test.o
#
mv a.out cycle_floyd_test
./cycle_floyd_test > cycle_floyd_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cycle_floyd_test
#
echo "Normal end of execution."

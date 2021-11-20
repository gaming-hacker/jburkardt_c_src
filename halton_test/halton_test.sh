#! /bin/bash
#
gcc -c -Wall -I/$HOME/include halton_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o halton_test halton_test.o /$HOME/libc/halton.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm halton_test.o
#
./halton_test > halton_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm halton_test
#
echo "Normal end of execution."

#! /bin/bash
#
gcc -c -Wall -I/$HOME/include praxis_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o praxis_test praxis_test.o /$HOME/libc/praxis.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm praxis_test.o
#
./praxis_test > praxis_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm praxis_test
#
echo "Normal end of execution."

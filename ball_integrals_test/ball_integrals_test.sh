#! /bin/bash
#
gcc -c -Wall -I/$HOME/include ball_integrals_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc ball_integrals_test.o /$HOME/libc/ball_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ball_integrals_test.o
#
mv a.out ball_integrals_test
./ball_integrals_test > ball_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ball_integrals_test
#
echo "Normal end of execution."

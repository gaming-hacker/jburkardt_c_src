#! /bin/bash
#
gcc -c -Wall -I/$HOME/include euler_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o euler_test euler_test.o /$HOME/libc/euler.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm euler_test.o
#
./euler_test > euler_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm euler_test
#
gnuplot < euler_humps_commands.txt
#
echo "Normal end of execution."

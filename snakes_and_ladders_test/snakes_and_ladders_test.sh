#! /bin/bash
#
gcc -c -Wall -I/$HOME/include snakes_and_ladders_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o snakes_and_ladders_test snakes_and_ladders_test.o /$HOME/libc/snakes_and_ladders.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm snakes_and_ladders_test.o
#
./snakes_and_ladders_test > snakes_and_ladders_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm snakes_and_ladders_test
#
echo "Normal end of execution."

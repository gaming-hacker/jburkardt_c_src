#! /bin/bash
#
gcc -c -Wall -I/$HOME/include toms322_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc toms322_test.o /$HOME/libc/toms322.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm toms322_test.o
#
mv a.out toms322_test
./toms322_test < input.txt > toms322_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm toms322_test
#
echo "Normal end of execution."

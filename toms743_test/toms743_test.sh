#! /bin/bash
#
gcc -c -Wall -I/$HOME/include toms743_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc toms743_test.o /$HOME/libc/toms743.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm toms743_test.o
#
mv a.out toms743_test
./toms743_test > toms743_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm toms743_test
#
echo "Normal end of execution."

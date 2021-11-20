#! /bin/bash
#
gcc -c -Wall -I/$HOME/include drand48_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc drand48_test.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm drand48_test.o
#
mv a.out drand48_test
./drand48_test > drand48_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm drand48_test
#
echo "Normal end of execution."

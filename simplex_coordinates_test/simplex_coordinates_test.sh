#! /bin/bash
#
gcc -c -Wall -I/$HOME/include simplex_coordinates_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc simplex_coordinates_test.o /$HOME/libc/simplex_coordinates.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm simplex_coordinates_test.o
#
mv a.out simplex_coordinates_test
./simplex_coordinates_test > simplex_coordinates_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm simplex_coordinates_test
#
echo "Normal end of execution."

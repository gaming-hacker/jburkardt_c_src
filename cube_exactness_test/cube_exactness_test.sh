#! /bin/bash
#
gcc -c -Wall -I/$HOME/include cube_exactness_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o cube_exactness_test cube_exactness_test.o /$HOME/libc/cube_exactness.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cube_exactness_test.o
#
./cube_exactness_test > cube_exactness_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cube_exactness_test
#
echo "Normal end of execution."

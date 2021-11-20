#! /bin/bash
#
gcc -c -Wall -I/$HOME/include fd2d_heat_steady_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fd2d_heat_steady_test.o /$HOME/libc/fd2d_heat_steady.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fd2d_heat_steady_test.o
#
mv a.out fd2d_heat_steady_test
./fd2d_heat_steady_test > fd2d_heat_steady_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm fd2d_heat_steady_test
#
echo "Normal end of execution."

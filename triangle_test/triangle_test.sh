#! /bin/bash
#
gcc -c -Wall -I $HOME/include triangle_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc triangle_test.o /$HOME/libc//triangle.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_test.o
#
mv a.out triangle_test
./triangle_test > triangle_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle_test
#
echo "Normal end of execution."

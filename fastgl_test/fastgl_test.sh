#! /bin/bash
#
gcc -c -Wall -I/$HOME/include fastgl_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fastgl_test.o /$HOME/libc/fastgl.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fastgl_test.o
#
mv a.out fastgl_test
./fastgl_test > fastgl_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm fastgl_test
#
echo "Normal end of execution."

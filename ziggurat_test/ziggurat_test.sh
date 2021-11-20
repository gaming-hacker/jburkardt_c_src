#! /bin/bash
#
gcc -c -Wall -I/$HOME/include ziggurat_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc ziggurat_test.o /$HOME/libc/ziggurat.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ziggurat_test.o
#
mv a.out ziggurat_test
./ziggurat_test > ziggurat_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ziggurat_test
#
echo "Normal end of execution."

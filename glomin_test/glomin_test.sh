#! /bin/bash
#
gcc -c -Wall -I/$HOME/include glomin_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc glomin_test.o /$HOME/libc/glomin.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm glomin_test.o
#
mv a.out glomin_test
./glomin_test > glomin_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm glomin_test
#
echo "Normal end of execution."

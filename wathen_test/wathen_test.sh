#! /bin/bash
#
gcc -c -Wall -I/$HOME/include wathen_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc wathen_test.o /$HOME/libc/wathen.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm wathen_test.o
#
mv a.out wathen_test
./wathen_test > wathen_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm wathen_test
#
echo "Normal end of execution."

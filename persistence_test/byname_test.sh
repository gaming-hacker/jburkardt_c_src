#! /bin/bash
#
gcc -c -Wall -I/$HOME/include byname_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc byname_test.o /$HOME/libc/byname.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm byname_test.o
#
mv a.out byname_test
./byname_test > byname_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm byname_test
#
echo "Normal end of execution."

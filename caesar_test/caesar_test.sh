#! /bin/bash
#
gcc -c -Wall -I/$HOME/include caesar_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o caesar_test caesar_test.o /$HOME/libc/caesar.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm caesar_test.o
#
./caesar_test > caesar_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm caesar_test
#
echo "Normal end of execution."

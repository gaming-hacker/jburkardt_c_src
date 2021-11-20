#! /bin/bash
#
gcc -c -Wall -I/$HOME/include haar_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc haar_test.o /$HOME/libc/haar.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm haar_test.o
#
mv a.out haar_test
./haar_test > haar_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm haar_test
#
echo "Normal end of execution."

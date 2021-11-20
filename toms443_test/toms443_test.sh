#! /bin/bash
#
gcc -c -Wall -I/$HOME/include toms443_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o toms443_test toms443_test.o /$HOME/libc/toms443.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm toms443_test.o
#
./toms443_test > toms443_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm toms443_test
#
echo "Normal end of execution."

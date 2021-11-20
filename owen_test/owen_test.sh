#! /bin/bash
#
gcc -c -Wall -I/$HOME/include owen_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc owen_test.o /$HOME/libc/owen.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm owen_test.o
#
mv a.out owen_test
./owen_test > owen_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm owen_test
#
echo "Normal end of execution."

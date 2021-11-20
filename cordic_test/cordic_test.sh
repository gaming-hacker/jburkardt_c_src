#! /bin/bash
#
gcc -c -Wall -I/$HOME/include cordic_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc cordic_test.o /$HOME/libc/cordic.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cordic_test.o
#
mv a.out cordic_test
./cordic_test > cordic_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cordic_test
#
echo "Normal end of execution."

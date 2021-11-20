#! /bin/bash
#
gcc -c -Wall -I/$HOME/include lebesgue_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc lebesgue_test.o /$HOME/libc/lebesgue.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm lebesgue_test.o
#
mv a.out lebesgue_test
./lebesgue_test > lebesgue_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm lebesgue_test
#
echo "Normal end of execution."

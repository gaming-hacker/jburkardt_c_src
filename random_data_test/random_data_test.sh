#! /bin/bash
#
gcc -c -Wall -I/$HOME/include random_data_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc random_data_test.o /$HOME/libc/random_data.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm random_data_test.o
#
mv a.out random_data_test
./random_data_test > random_data_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm random_data_test
#
echo "Normal end of execution."

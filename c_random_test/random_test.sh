#! /bin/bash
#
gcc -c -Wall -I/$HOME/include random_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc random_test.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm random_test.o
#
mv a.out random_test
./random_test > random_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm random_test
#
echo "Normal end of execution."

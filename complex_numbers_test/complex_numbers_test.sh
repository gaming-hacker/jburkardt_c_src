#! /bin/bash
#
gcc -c -Wall -I/$HOME/include complex_numbers_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o complex_numbers_test complex_numbers_test.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm complex_numbers_test.o
#
./complex_numbers_test > complex_numbers_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm complex_numbers_test
#
echo "Normal end of execution."

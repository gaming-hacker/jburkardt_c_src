#! /bin/bash
#
gcc -c -Wall -I/$HOME/include latin_random_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc latin_random_test.o /$HOME/libc/latin_random.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm latin_random_test.o
#
mv a.out latin_random_test
./latin_random_test > latin_random_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm latin_random_test
#
echo "Normal end of execution."

#! /bin/bash
#
gcc -c -Wall -I/$HOME/include ornstein_uhlenbeck_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc ornstein_uhlenbeck_test.o /$HOME/libc/ornstein_uhlenbeck.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm ornstein_uhlenbeck_test.o
#
mv a.out ornstein_uhlenbeck_test
./ornstein_uhlenbeck_test > ornstein_uhlenbeck_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ornstein_uhlenbeck_test
#
echo "Normal end of execution."

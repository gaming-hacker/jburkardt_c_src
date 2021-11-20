#! /bin/bash
#
gcc -c -Wall -I/$HOME/include weekday_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc weekday_test.o /$HOME/libc/weekday.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm weekday_test.o
#
mv a.out weekday_test
./weekday_test > weekday_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm weekday_test
#
echo "Normal end of execution."

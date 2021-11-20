#! /bin/bash
#
gcc -c -Wall -I/$HOME/include humps_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o humps_test humps_test.o /$HOME/libc/humps.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm humps_test.o
#
./humps_test > humps_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm humps_test
#
echo "Normal end of execution."

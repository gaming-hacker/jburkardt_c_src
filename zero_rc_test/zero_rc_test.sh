#! /bin/bash
#
gcc -c -Wall -I/$HOME/include zero_rc_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc zero_rc_test.o /$HOME/libc/zero_rc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm zero_rc_test.o
#
mv a.out zero_rc_test
./zero_rc_test > zero_rc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm zero_rc_test
#
echo "Normal end of execution."

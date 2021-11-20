#! /bin/bash
#
gcc -c -Wall -I/$HOME/include roots_rc_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc roots_rc_test.o /$HOME/libc/roots_rc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm roots_rc_test.o
#
mv a.out roots_rc_test
./roots_rc_test > roots_rc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm roots_rc_test
#
echo "Normal end of execution."

#! /bin/bash
#
gcc -c -Wall -I/$HOME/include sort_rc_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o sort_rc_test sort_rc_test.o /$HOME/libc/sort_rc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sort_rc_test.o
#
./sort_rc_test > sort_rc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sort_rc_test
#
echo "Normal end of execution."

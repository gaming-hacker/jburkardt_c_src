#! /bin/bash
#
gcc -c -Wall -I/$HOME/include root_rc_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc root_rc_test.o /$HOME/libc/root_rc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm root_rc_test.o
#
mv a.out root_rc_test
./root_rc_test > root_rc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm root_rc_test
#
echo "Normal end of execution."

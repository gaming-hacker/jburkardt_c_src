#! /bin/bash
#
gcc -c -Wall -I/$HOME/include fn_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fn_test.o /$HOME/libc/fn.o /$HOME/libc/test_values.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fn_test.o
#
mv a.out fn_test
./fn_test > fn_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm fn_test
#
echo "Normal end of execution."

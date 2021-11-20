#! /bin/bash
#
gcc -c -Wall -I/$HOME/include test_lls_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc test_lls_test.o /$HOME/libc/test_lls.o \
                   /$HOME/libc/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_lls_test.o
#
mv a.out test_lls_test
./test_lls_test > test_lls_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_lls_test
#
echo "Normal end of execution."

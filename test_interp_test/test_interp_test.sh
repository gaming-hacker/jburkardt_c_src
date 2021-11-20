#! /bin/bash
#
gcc -c -Wall -I/$HOME/include test_interp_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc test_interp_test.o /$HOME/libc/test_interp.o \
                      /$HOME/libc/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_interp_test.o
#
mv a.out test_interp_test
./test_interp_test > test_interp_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_interp_test
#
echo "Normal end of execution."

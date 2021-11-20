#! /bin/bash
#
gcc -c -Wall -I/$HOME/include test_interp_nd_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc test_interp_nd_test.o /$HOME/libc/test_interp_nd.o  \
                         /$HOME/libc/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_interp_nd_test.o
#
mv a.out test_interp_nd_test
./test_interp_nd_test > test_interp_nd_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_interp_nd_test
#
echo "Normal end of execution."

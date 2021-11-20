#! /bin/bash
#
gcc -c -Wall -I/$HOME/include shepard_interp_nd_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc shepard_interp_nd_test.o /$HOME/libc/shepard_interp_nd.o \
                            /$HOME/libc/test_interp_nd.o \
                            /$HOME/libc/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm shepard_interp_nd_test.o
#
mv a.out shepard_interp_nd_test
./shepard_interp_nd_test > shepard_interp_nd_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm shepard_interp_nd_test
#
echo "Normal end of execution."

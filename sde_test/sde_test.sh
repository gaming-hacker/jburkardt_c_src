#! /bin/bash
#
gcc -c -Wall  -I/$HOME/include sde_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sde_test.o /$HOME/libc/sde.o \
              /$HOME/libc/qr_solve.o \
              /$HOME/libc/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sde_test.o
#
mv a.out sde_test
./sde_test > sde_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sde_test
#
echo "Normal end of execution."

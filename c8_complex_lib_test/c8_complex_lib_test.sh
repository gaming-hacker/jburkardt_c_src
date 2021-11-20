#! /bin/bash
#
gcc -c -Wall -I/$HOME/include c8_complex_lib_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc c8_complex_lib_test.o /$HOME/libc/c8_complex_lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm c8_complex_lib_test.o
#
mv a.out c8_complex_lib_test
./c8_complex_lib_test > c8_complex_lib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm c8_complex_lib_test
#
echo "Normal end of execution."

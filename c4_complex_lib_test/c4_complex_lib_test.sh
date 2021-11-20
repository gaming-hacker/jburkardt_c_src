#! /bin/bash
#
gcc -c -Wall -I/$HOME/include c4_complex_lib_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc c4_complex_lib_test.o /$HOME/libc/c4_complex_lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm c4_complex_lib_test.o
#
mv a.out c4_complex_lib_test
./c4_complex_lib_test > c4_complex_lib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm c4_complex_lib_test
#
echo "Normal end of execution."

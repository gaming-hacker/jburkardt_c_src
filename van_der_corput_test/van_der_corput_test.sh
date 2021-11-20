#! /bin/bash
#
gcc -c -Wall -I/$HOME/include van_der_corput_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o van_der_corput_test van_der_corput_test.o /$HOME/libc/van_der_corput.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm van_der_corput_test.o
#
./van_der_corput_test > van_der_corput_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm van_der_corput_test
#
echo "Normal end of execution."

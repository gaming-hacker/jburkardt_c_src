#! /bin/bash
#
gcc -c -Wall -I/$HOME/include fftpack4_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fftpack4_test.o /$HOME/libc/fftpack4.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fftpack4_test.o
#
mv a.out fftpack4_test
./fftpack4_test > fftpack4_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm fftpack4_test
#
echo "Normal end of execution."

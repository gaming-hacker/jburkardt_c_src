#! /bin/bash
#
gcc -c -Wall -I/usr/local/include fftw_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fftw_test.o -L/usr/local/lib -lfftw3 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fftw_test.o
#
mv a.out fftw_test
./fftw_test > fftw_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm fftw_test
#
echo "Normal end of execution."

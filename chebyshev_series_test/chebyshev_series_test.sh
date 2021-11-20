#! /bin/bash
#
gcc -c -Wall -I/$HOME/include chebyshev_series_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc chebyshev_series_test.o /$HOME/libc/chebyshev_series.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm chebyshev_series_test.o
#
mv a.out chebyshev_series_test
./chebyshev_series_test > chebyshev_series_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm chebyshev_series_test
#
echo "Normal end of execution."

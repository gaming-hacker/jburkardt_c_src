#! /bin/bash
#
cp chebyshev_series.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include chebyshev_series.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv chebyshev_series.o ~/libc/chebyshev_series.o
#
echo "Normal end of execution."

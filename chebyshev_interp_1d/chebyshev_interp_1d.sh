#! /bin/bash
#
cp chebyshev_interp_1d.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include chebyshev_interp_1d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv chebyshev_interp_1d.o ~/libc/chebyshev_interp_1d.o
#
echo "Normal end of execution."

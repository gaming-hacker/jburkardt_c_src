#! /bin/bash
#
cp chebyshev.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include chebyshev.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv chebyshev.o ~/libc/chebyshev.o
#
echo "Normal end of execution."

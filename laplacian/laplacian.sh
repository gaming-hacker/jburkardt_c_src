#! /bin/bash
#
cp laplacian.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include laplacian.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv laplacian.o ~/libc/laplacian.o
#
echo "Normal end of execution."

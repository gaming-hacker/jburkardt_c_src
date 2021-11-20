#! /bin/bash
#
cp pwl_approx_1d.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include pwl_approx_1d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pwl_approx_1d.o ~/libc/pwl_approx_1d.o
#
echo "Normal end of execution."

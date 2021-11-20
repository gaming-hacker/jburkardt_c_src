#! /bin/bash
#
cp svd_snowfall.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include svd_snowfall.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv svd_snowfall.o ~/libc/svd_snowfall.o
#
echo "Normal end of execution."

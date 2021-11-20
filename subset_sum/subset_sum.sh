#! /bin/bash
#
cp subset_sum.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include subset_sum.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv subset_sum.o ~/libc/subset_sum.o
#
echo "Normal end of execution."

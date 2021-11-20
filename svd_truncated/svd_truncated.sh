#!/bin/bash
#
gcc -c -Wall -I$HOME/include svd_truncated.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o svd_truncated svd_truncated.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm svd_truncated.o
#
mv svd_truncated $HOME/binc
#
echo "Normal end of execution."

#! /bin/bash
#
gcc -c -Wall -I/$HOME/include stats_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc stats_test.o /$HOME/libc/stats.o  /$HOME/libc/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm stats_test.o
#
mv a.out stats_test
./stats_test > stats_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm stats_test
#
echo "Normal end of execution."

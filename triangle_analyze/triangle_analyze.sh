#!/bin/bash
#
gcc -c -Wall triangle_analyze.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc triangle_analyze.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm triangle_analyze.o
#
chmod ugo+x a.out
mv a.out ~/binc/triangle_analyze
#
echo "Normal end of execution."

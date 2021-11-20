#! /bin/bash
#
gcc -c -Wall tsp_brute.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc tsp_brute.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm tsp_brute.o
#
mv a.out ~/binc/tsp_brute
#
echo "Normal end of execution."

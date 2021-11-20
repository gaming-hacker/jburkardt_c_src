#! /bin/bash
#
gcc -c -Wall fem1d_adaptive.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fem1d_adaptive.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fem1d_adaptive.o
#
chmod ugo+x a.out
mv a.out ~/binc/fem1d_adaptive
#
echo "Normal end of execution."

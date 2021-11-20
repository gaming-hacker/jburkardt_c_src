#! /bin/bash
#
gcc -c -Wall -I$HOME/include triangle_exactness.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc triangle_exactness.o -lm 
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_exactness.o
#
chmod ugo+x a.out
mv a.out ~/binc/triangle_exactness
#
echo "Normal end of execution."

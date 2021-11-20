#! /bin/bash
#
gcc -c -Wall testpack.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc testpack.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm testpack.o
#
chmod ugo+x a.out
mv a.out ~/binc/testpack
#
echo "Normal end of execution."

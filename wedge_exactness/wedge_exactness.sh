#! /bin/bash
#
gcc -c -Wall wedge_exactness.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc wedge_exactness.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm wedge_exactness.o
#
chmod ugo+x a.out
mv a.out ~/binc/wedge_exactness
#
echo "Normal end of execution."

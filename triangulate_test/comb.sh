#! /bin/bash
#
gcc -c -Wall comb.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc comb.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm comb.o
#
chmod ugo+x a.out
mv a.out ~/binc/comb
#
echo "Normal end of execution."

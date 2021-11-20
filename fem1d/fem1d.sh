#! /bin/bash
#
gcc -c -Wall fem1d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fem1d.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fem1d.o
#
chmod ugo+x a.out
mv a.out ~/binc/fem1d
#
echo "Normal end of execution."

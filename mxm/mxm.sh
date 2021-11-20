#! /bin/bash
#
gcc -c -Wall mxm.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc mxm.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm mxm.o
#
chmod ugo+x a.out
mv a.out ~/binc/mxm
#
echo "Normal end of execution."

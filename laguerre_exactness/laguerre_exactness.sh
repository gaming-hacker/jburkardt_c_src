#! /bin/bash
#
gcc -c -Wall laguerre_exactness.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc laguerre_exactness.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm laguerre_exactness.o
#
chmod ugo+x a.out
mv a.out ~/binc/laguerre_exactness
#
echo "Normal end of execution."

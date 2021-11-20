#! /bin/bash
#
gcc -c -Wall showme.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc showme.o -L/usr/X11R6/lib -lX11
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm showme.o
#
chmod ugo+x a.out
mv a.out ~/binc/showme
#
echo "Normal end of execution."

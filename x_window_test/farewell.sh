#! /bin/bash
#
gcc -c -Wall -I /usr/lib/X11 farewell.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc farewell.o -L/usr/X11R6/lib -lXt -lXaw
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm farewell.o
mv a.out ~/binc/farewell
#
echo "Normal end of execution."

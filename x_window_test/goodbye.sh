#! /bin/bash
#
gcc -c -Wall -I /usr/lib/X11 goodbye.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc goodbye.o -L/usr/X11R6/lib -lXt -lXaw
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm goodbye.o
mv a.out ~/binc/goodbye
#
echo "Normal end of execution."

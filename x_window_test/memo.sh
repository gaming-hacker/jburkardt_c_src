#! /bin/bash
#
gcc -c -Wall -I /usr/lib/X11 memo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc memo.o -L/usr/X11R6/lib -lXt -lXaw
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm memo.o
mv a.out ~/binc/memo
#
echo "Normal end of execution."

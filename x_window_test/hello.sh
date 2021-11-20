#! /bin/bash
#
gcc -c -Wall -I /usr/lib/X11 hello.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc hello.o -L/usr/X11R6/lib -lX11 -lXt -lXaw
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hello.o
mv a.out ~/binc/hello
#
echo "Normal end of execution."

#! /bin/bash
#
cp dijkstra.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include dijkstra.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv dijkstra.o ~/libc/dijkstra.o
#
echo "Normal end of execution."

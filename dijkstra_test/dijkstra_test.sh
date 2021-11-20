#! /bin/bash
#
gcc -c -Wall -I/$HOME/include dijkstra_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc dijkstra_test.o /$HOME/libc/dijkstra.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm dijkstra_test.o
#
mv a.out dijkstra_test
./dijkstra_test > dijkstra_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm dijkstra_test
#
echo "Normal end of execution."

#! /bin/bash
#
gcc -c -Wall -I/$HOME/include image_edge_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc image_edge_test.o /$HOME/libc/image_edge.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm image_edge_test.o
#
mv a.out image_edge_test
./image_edge_test > image_edge_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm image_edge_test
#
echo "Normal end of execution."

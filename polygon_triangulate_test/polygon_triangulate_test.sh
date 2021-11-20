#! /bin/bash
#
gcc -c -Wall -I/$HOME/include polygon_triangulate_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc polygon_triangulate_test.o /$HOME/libc/polygon_triangulate.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm polygon_triangulate_test.o
#
mv a.out polygon_triangulate_test
./polygon_triangulate_test > polygon_triangulate_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm polygon_triangulate_test
#
echo "Normal end of execution."

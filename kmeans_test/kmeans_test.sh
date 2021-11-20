#! /bin/bash
#
gcc -c -Wall -I/$HOME/include kmeans_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc kmeans_test.o /$HOME/libc/kmeans.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm kmeans_test.o
#
mv a.out kmeans_test
./kmeans_test > kmeans_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm kmeans_test
#
echo "Normal end of execution."

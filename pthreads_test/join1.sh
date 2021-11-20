#! /bin/bash
#
gcc -c -Wall join1.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc join1.o -pthread
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm join1.o
mv a.out join1
./join1 > join1.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm join1
#
echo "Normal end of execution."

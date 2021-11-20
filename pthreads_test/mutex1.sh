#! /bin/bash
#
gcc -c -Wall mutex1.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc mutex1.o -pthread
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm mutex1.o
mv a.out mutex1
./mutex1 > mutex1.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm mutex1
#
echo "Normal end of execution."

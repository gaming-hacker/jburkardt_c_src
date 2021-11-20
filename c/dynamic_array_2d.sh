#! /bin/bash
#
gcc -c -Wall dynamic_array_2d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc dynamic_array_2d.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm dynamic_array_2d.o
#
mv a.out dynamic_array_2d
./dynamic_array_2d > dynamic_array_2d.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm dynamic_array_2d
#
echo "Normal end of execution."

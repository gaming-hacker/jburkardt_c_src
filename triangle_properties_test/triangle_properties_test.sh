#! /bin/bash
#
gcc -c -Wall -I/$HOME/include triangle_properties_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o triangle_properties_test triangle_properties_test.o /$HOME/libc/triangle_properties.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_properties_test.o
#
./triangle_properties_test > triangle_properties_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle_properties_test
#
echo "Normal end of execution."

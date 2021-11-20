#! /bin/bash
#
gcc -c -Wall -I/$HOME/include tga_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o tga_test tga_test.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm tga_test.o
#
./tga_test fern.tga &> tga_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm tga_test
#
echo "Normal end of execution."

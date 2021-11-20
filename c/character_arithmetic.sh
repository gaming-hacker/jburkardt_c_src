#! /bin/bash
#
gcc -c -Wall character_arithmetic.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc character_arithmetic.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm character_arithmetic.o
#
mv a.out character_arithmetic
./character_arithmetic > character_arithmetic.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm character_arithmetic
#
echo "Normal end of execution."

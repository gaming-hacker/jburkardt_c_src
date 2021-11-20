#! /bin/bash
#
gcc -c -Wall c_mistake.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc c_mistake.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm c_mistake.o
#
mv a.out c_mistake
./c_mistake > c_mistake.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm c_mistake
#
echo "Normal end of execution."

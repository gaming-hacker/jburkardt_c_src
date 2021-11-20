#! /bin/bash
#
gcc -c -Wall pthread1.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc pthread1.o -pthread
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pthread1.o
mv a.out pthread1
./pthread1 > pthread1.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pthread1
#
echo "Normal end of execution."

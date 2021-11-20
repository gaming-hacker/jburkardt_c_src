#! /bin/bash
#
gcc -c -Wall cond1.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc cond1.o -pthread
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cond1.o
mv a.out cond1
./cond1 > cond1.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cond1
#
echo "Normal end of execution."

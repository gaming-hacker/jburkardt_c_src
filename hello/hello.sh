#! /bin/bash
#
gcc -c -Wall hello.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc hello.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hello.o
#
mv a.out ~/binc/hello
#
echo "Normal end of execution."

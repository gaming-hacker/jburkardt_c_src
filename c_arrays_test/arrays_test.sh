#! /bin/bash
#
gcc -c -Wall arrays_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o arrays_test arrays_test.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm arrays_test.o
#
./arrays_test > arrays_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm arrays_test
#
echo "Normal end of execution."

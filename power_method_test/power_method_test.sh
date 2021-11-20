#! /bin/bash
#
gcc -c -Wall -I/$HOME/include power_method_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc power_method_test.o /$HOME/libc/power_method.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm power_method_test.o
#
mv a.out power_method_test
./power_method_test > power_method_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm power_method_test
#
echo "Normal end of execution."

#! /bin/bash
#
gcc -c -Wall -I/$HOME/include machine_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc machine_test.o /$HOME/libc/machine.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm machine_test.o
#
mv a.out machine_test
./machine_test > machine_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm machine_test
#
echo "Normal end of execution."

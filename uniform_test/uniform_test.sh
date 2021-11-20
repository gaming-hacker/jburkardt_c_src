#! /bin/bash
#
gcc -c -Wall -I/$HOME/include uniform_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc uniform_test.o /$HOME/libc/uniform.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm uniform_test.o
#
mv a.out uniform_test
./uniform_test > uniform_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm uniform_test
#
echo "Normal end of execution."

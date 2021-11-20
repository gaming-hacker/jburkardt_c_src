#! /bin/bash
#
gcc -c -Wall -I/$HOME/include machar_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc machar_test.o /$HOME/libc/machar.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm machar_test.o
#
mv a.out machar_test
./machar_test > machar_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm machar_test
#
echo "Normal end of execution."

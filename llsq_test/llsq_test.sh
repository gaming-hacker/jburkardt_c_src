#! /bin/bash
#
gcc -c -Wall -I$HOME/include llsq_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc llsq_test.o $HOME/libc/llsq.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm llsq_test.o
#
mv a.out llsq_test
./llsq_test > llsq_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm llsq_test
#
echo "Normal end of execution."

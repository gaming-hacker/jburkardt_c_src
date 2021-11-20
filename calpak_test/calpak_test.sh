#! /bin/bash
#
gcc -c -Wall -I $HOME/include calpak_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o calpak_test calpak_test.o /$HOME/libc/calpak.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
./calpak_test > calpak_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm calpak_test
#
echo "Normal end of execution."

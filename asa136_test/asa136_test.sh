#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa136_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa136_test.o /$HOME/libc/asa136.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa136_test.o
#
mv a.out asa136_test
./asa136_test > asa136_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa136_test
#
echo "Normal end of execution."

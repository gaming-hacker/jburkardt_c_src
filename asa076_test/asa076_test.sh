#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa076_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa076_test.o -L $HOME/libc -lasa076 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm asa076_test.o
#
mv a.out asa076_test
./asa076_test > asa076_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa076_test
#
echo "Normal end of execution."

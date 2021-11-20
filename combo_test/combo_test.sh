#! /bin/bash
#
gcc -c -Wall -I/$HOME/include combo_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc combo_test.o /$HOME/libc/combo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm combo_test.o
#
mv a.out combo_test
./combo_test > combo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm combo_test
#
echo "Normal end of execution."

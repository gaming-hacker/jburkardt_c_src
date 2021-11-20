#! /bin/bash
#
gcc -c -Wall -I/$HOME/include quadrule_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc quadrule_test.o /$HOME/libc/quadrule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm quadrule_test.o
#
mv a.out quadrule_test
./quadrule_test > quadrule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quadrule_test
#
echo "Normal end of execution."

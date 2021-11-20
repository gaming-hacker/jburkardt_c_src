#! /bin/bash
#
gcc -c -Wall -I/$HOME/include pyramid_integrals_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc pyramid_integrals_test.o /$HOME/libc/pyramid_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pyramid_integrals_test.o
#
mv a.out pyramid_integrals_test
./pyramid_integrals_test > pyramid_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pyramid_integrals_test
#
echo "Normal end of execution."

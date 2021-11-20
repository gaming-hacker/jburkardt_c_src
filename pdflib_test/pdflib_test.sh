#! /bin/bash
#
gcc -c -Wall -I/$HOME/include pdflib_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc pdflib_test.o /$HOME/libc/pdflib.o  /$HOME/libc/rnglib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pdflib_test.o
#
mv a.out pdflib_test
./pdflib_test > pdflib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pdflib_test
#
echo "Normal end of execution."

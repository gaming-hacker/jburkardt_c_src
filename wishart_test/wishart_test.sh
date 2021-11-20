#! /bin/bash
#
gcc -c -Wall -I/$HOME/include wishart_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc wishart_test.o \
  /$HOME/libc/wishart.o \
  /$HOME/libc/pdflib.o \
  /$HOME/libc/rnglib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm wishart_test.o
#
mv a.out wishart_test
./wishart_test > wishart_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm wishart_test
#
echo "Normal end of execution."

#! /bin/bash
#
gcc -c -Wall -I/$HOME/include problem2.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc /$HOME/libc/dream.o \
  problem2.o \
  /$HOME/libc/pdflib.o \
  /$HOME/libc/rnglib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm problem2.o
#
mv a.out problem2
./problem2 > problem2.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm problem2
#
echo "Normal end of execution."

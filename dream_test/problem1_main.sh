#! /bin/bash
#
gcc -c -Wall -I/$HOME/include problem1.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -c -Wall -I/$HOME/include problem1_main.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc problem1_main.o \
  problem1.o \
  /$HOME/libc/pdflib.o \
  /$HOME/libc/rnglib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm problem1_main.o
rm problem1.o
#
mv a.out problem1_main
./problem1_main > problem1_main.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm problem1_main
#
echo "Normal end of execution."

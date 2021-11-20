#! /bin/bash
#
cp pdflib.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include pdflib.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pdflib.o ~/libc/pdflib.o
#
echo "Normal end of execution."

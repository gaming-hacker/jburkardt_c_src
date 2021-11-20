#! /bin/bash
#
cp monomial.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include monomial.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv monomial.o ~/libc/monomial.o
#
echo "Normal end of execution."

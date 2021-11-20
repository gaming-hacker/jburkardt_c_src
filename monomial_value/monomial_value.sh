#! /bin/bash
#
cp monomial_value.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include monomial_value.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv monomial_value.o ~/libc/monomial_value.o
#
echo "Normal end of execution."

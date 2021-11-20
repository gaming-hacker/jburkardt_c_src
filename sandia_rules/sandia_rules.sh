#! /bin/bash
#
cp sandia_rules.h /$HOME/include
#
gcc -c -Wall sandia_rules.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sandia_rules.o ~/libc/sandia_rules.o
#
echo "Normal end of execution."

#! /bin/bash
#
cp square_arbq_rule.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include square_arbq_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv square_arbq_rule.o ~/libc/square_arbq_rule.o
#
echo "Normal end of execution."

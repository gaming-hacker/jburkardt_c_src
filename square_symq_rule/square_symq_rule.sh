#! /bin/bash
#
cp square_symq_rule.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include square_symq_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv square_symq_rule.o ~/libc/square_symq_rule.o
#
echo "Normal end of execution."

#! /bin/bash
#
cp square_minimal_rule.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include square_minimal_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv square_minimal_rule.o ~/libc/square_minimal_rule.o
#
echo "Normal end of execution."

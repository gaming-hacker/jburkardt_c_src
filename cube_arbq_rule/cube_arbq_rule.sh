#! /bin/bash
#
cp cube_arbq_rule.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include cube_arbq_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cube_arbq_rule.o ~/libc/cube_arbq_rule.o
#
echo "Normal end of execution."

#! /bin/bash
#
cp simplex_gm_rule.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include simplex_gm_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv simplex_gm_rule.o ~/libc/simplex_gm_rule.o
#
echo "Normal end of execution."

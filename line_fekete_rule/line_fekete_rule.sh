#! /bin/bash
#
cp line_fekete_rule.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include line_fekete_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv line_fekete_rule.o ~/libc/line_fekete_rule.o
#
echo "Normal end of execution."

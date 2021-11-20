#! /bin/bash
#
cp line_ncc_rule.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include line_ncc_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv line_ncc_rule.o ~/libc/line_ncc_rule.o
#
echo "Normal end of execution."

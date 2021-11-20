#! /bin/bash
#
cp line_nco_rule.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include line_nco_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv line_nco_rule.o ~/libc/line_nco_rule.o
#
echo "Normal end of execution."

#! /bin/bash
#
cp line_felippa_rule.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include line_felippa_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv line_felippa_rule.o ~/libc/line_felippa_rule.o
#
echo "Normal end of execution."

#! /bin/bash
#
cp square_felippa_rule.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include square_felippa_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv square_felippa_rule.o ~/libc/square_felippa_rule.o
#
echo "Normal end of execution."

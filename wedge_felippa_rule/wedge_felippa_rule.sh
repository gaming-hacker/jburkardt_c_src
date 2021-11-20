#! /bin/bash
#
cp wedge_felippa_rule.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include wedge_felippa_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv wedge_felippa_rule.o ~/libc/wedge_felippa_rule.o
#
echo "Normal end of execution."

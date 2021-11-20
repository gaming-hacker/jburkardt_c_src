#! /bin/bash
#
cp cube_felippa_rule.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include cube_felippa_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cube_felippa_rule.o ~/libc/cube_felippa_rule.o
#
echo "Normal end of execution."

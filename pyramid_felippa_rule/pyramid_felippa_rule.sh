#! /bin/bash
#
cp pyramid_felippa_rule.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include pyramid_felippa_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pyramid_felippa_rule.o ~/libc/pyramid_felippa_rule.o
#
echo "Normal end of execution."

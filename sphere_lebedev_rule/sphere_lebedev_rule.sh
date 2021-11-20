#! /bin/bash
#
cp sphere_lebedev_rule.h /$HOME/include
#
gcc -c -Wall sphere_lebedev_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sphere_lebedev_rule.o ~/libc/sphere_lebedev_rule.o
#
echo "Normal end of execution."

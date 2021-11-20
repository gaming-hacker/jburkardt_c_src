#! /bin/bash
#
gcc -c -Wall triangle_to_fem.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc triangle_to_fem.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_to_fem.o
#
chmod ugo+x a.out
mv a.out ~/binc/triangle_to_fem
#
echo "Normal end of execution."

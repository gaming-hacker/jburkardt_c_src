#! /bin/bash
#
gcc -c -Wall triangulation_svg.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc triangulation_svg.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulation_svg.o
#
chmod ugo+x a.out
mv a.out ~/binc/triangulation_svg
#
echo "Normal end of execution."

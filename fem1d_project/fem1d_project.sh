#! /bin/bash
#
gcc -c -Wall fem1d_project.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fem1d_project.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fem1d_project.o
#
chmod ugo+x a.out
mv a.out ~/binc/fem1d_project
#
echo "Normal end of execution."

#! /bin/bash
#
gcc -c -Wall tetrahedron_exactness.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc tetrahedron_exactness.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm tetrahedron_exactness.o
#
chmod ugo+x a.out
mv a.out ~/binc/tetrahedron_exactness
#
echo "Normal end of execution."

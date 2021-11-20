#! /bin/bash
#
gcc -c -Wall pyramid_exactness.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc pyramid_exactness.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm pyramid_exactness.o
#
chmod ugo+x a.out
mv a.out ~/binc/pyramid_exactness
#
echo "Normal end of execution."

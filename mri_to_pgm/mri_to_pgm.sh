#! /bin/bash
#
gcc -c -Wall mri_to_pgm.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc mri_to_pgm.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm mri_to_pgm.o
mv a.out ~/binc/mri_to_pgm
#
echo "Normal end of execution."

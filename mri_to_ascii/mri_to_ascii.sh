#! /bin/bash
#
gcc -c -Wall mri_to_ascii.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc mri_to_ascii.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm mri_to_ascii.o
mv a.out ~/binc/mri_to_ascii
#
echo "Normal end of execution."

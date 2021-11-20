#! /bin/bash
#
gcc -c -Wall discrete_pdf_sample_2d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc discrete_pdf_sample_2d.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm discrete_pdf_sample_2d.o
#
mv a.out ~/binc/discrete_pdf_sample_2d
#
echo "Normal end of execution."

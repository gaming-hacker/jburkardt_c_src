#! /bin/bash
#
$HOME/binc/discrete_pdf_sample_2d test01.txt > discrete_pdf_sample_2d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
$HOME/binc/discrete_pdf_sample_2d test02.txt >> discrete_pdf_sample_2d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

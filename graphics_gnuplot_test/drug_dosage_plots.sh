#! /bin/bash
#
gcc -c -Wall drug_dosage_plots.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc drug_dosage_plots.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm drug_dosage_plots.o
#
mv a.out drug_dosage_plots
./drug_dosage_plots > drug_dosage_plots.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm drug_dosage_plots
#
#  Generate graphics.
#
gnuplot < drug_dosage_commands.txt
#
echo "Normal end of execution."

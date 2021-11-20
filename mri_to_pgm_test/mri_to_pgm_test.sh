#! /bin/bash
#
$HOME/binc/mri_to_pgm roi > mri_to_pgm_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."


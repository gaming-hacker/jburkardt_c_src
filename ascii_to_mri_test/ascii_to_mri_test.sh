#! /bin/bash
#
$HOME/binc/ascii_to_mri roi > ascii_to_mri_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."


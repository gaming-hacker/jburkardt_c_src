#! /bin/bash
#
$HOME/binc/mri_to_ascii roi > mri_to_ascii_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."


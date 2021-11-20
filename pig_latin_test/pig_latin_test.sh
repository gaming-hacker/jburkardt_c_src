#! /bin/bash
#
$HOME/binc/pig_latin < gettysburg.txt > piggysburg.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."


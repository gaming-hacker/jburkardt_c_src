#! /bin/bash
#
#  This script is designed to compile and run C DISLIN examples on my OSX system.
#
export DISLIN=/usr/local/dislin
export DYLD_LIBRARY_PATH=$DISLIN:$DYLD_LIBRARY_PATH
#
$DISLIN/bin/clink -c -r8 ex06
if [ $? -ne 0 ]; then
  echo "Errors linking and loading ex06.o"
  exit
fi
#
./ex06 > ex06_osx_output.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ex06
#
echo "Normal end of execution."

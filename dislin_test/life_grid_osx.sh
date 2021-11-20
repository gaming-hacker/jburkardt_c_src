#! /bin/bash
#
#  This script is designed to compile and run C DISLIN examples on my OSX system.
#
export DISLIN=/usr/local/dislin
export DYLD_LIBRARY_PATH=$DISLIN:$DYLD_LIBRARY_PATH
#
$DISLIN/bin/clink -c -r8 life_grid
if [ $? -ne 0 ]; then
  echo "Errors linking and loading life_grid.o"
  exit
fi
#
./life_grid > life_grid_osx_output.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm life_grid
#
echo "Normal end of execution."

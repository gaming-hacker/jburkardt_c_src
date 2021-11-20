#! /bin/bash
#
#  This script is designed to compile and run C DISLIN examples on my OSX system.
#
export DISLIN=/usr/local/dislin
export DYLD_LIBRARY_PATH=$DISLIN:$DYLD_LIBRARY_PATH
#
$DISLIN/bin/clink -c -r8 quickplot_color
if [ $? -ne 0 ]; then
  echo "Errors linking and loading quickplot_color.o"
  exit
fi
#
./quickplot_color > quickplot_color_osx_output.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quickplot_color
#
echo "Normal end of execution."

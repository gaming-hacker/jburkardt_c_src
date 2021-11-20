#! /bin/bash
#
#  This script is designed to compile and run C DISLIN examples on my OSX system.
#
export DISLIN=/usr/local/dislin
export DYLD_LIBRARY_PATH=$DISLIN:$DYLD_LIBRARY_PATH
#
$DISLIN/bin/clink -c -r8 quickplot_pie
if [ $? -ne 0 ]; then
  echo "Errors linking and loading quickplot_pie.o"
  exit
fi
#
./quickplot_pie > quickplot_pie_osx_output.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quickplot_pie
#
echo "Normal end of execution."

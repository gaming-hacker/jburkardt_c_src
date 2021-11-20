#! /bin/bash
#
cp args.h $HOME/include
#
gcc -c -Wall -I $HOME/include *.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o args *.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm *.o
#
chmod ugo+x args
mv args ~/binc/args
#
echo "Normal end of execution."

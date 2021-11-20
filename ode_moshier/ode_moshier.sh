#! /bin/bash
#
cp ode_moshier.h /$HOME/include
#
gcc -c -Wall adams3.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -c rungek.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
ar qc libode_moshier.a *.o
rm *.o
mv libode_moshier.a ~/libc/libode_moshier.a
#
echo "Normal end of execution."

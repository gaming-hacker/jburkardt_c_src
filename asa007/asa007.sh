#! /bin/bash
#
cp asa007.h /$HOME/include
#
for FILE in `ls -1 *.c`;
do
  gcc -c -Wall $FILE
  if [ $? -ne 0 ]; then
    echo "Compile error: " $FILE
    exit
  fi
done
#
ar qc libasa007.a *.o
if [ $? -ne 0 ]; then
  echo "Archive error."
  exit
fi
rm *.o
mv libasa007.a ~/libc
#
echo "Normal end of execution."

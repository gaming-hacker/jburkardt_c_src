#! /bin/bash
#
cp asa063.h /$HOME/include
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
ar qc libasa063.a *.o
if [ $? -ne 0 ]; then
  echo "Archive error."
  exit
fi
rm *.o
mv libasa063.a ~/libc
#
echo "Normal end of execution."

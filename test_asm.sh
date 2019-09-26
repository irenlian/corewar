#!/bin/bash -e
while getopts "r:" opt
do
   case "$opt" in
      r ) rivalName="$OPTARG" ;;
      ? ) helpFunction ;; # Print helpFunction in case parameter is non-existent
   esac
done
./asm $rivalName.s &&
if ! [ -s $rivalName.cor ] ; then
    echo   DAAAAMN! &&
    exit
fi &&
xxd $rivalName.cor > t2 &&
rm -rf $rivalName.cor &&
./vm_champs/asm $rivalName.s &&
xxd $rivalName.cor > t1 &&
rm -rf $rivalName.cor &&
vimdiff t1 t2
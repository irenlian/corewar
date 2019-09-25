while getopts "r:" opt
do
   case "$opt" in
      r ) rivalName="$OPTARG" ;;
      ? ) helpFunction ;; # Print helpFunction in case parameter is non-existent
   esac
done
./asm $rivalName.s &&
xxd $rivalName.cor > t2 &&
./vm_champs/asm $rivalName.s &&
xxd $rivalName.cor > t1 &&
vimdiff t1 t2
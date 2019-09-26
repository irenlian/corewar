path=vm_champs/champs/championships/2017
path2=vm_champs/champs
end=s

s_array=("$path/adenis/*$end" "$path/agregoir/*$end" "$path/gnebie/*$end"
 "$path/iburel/*$end" "$path/jaustry/*$end" "$path/nolivier/*$end" "$path/pzarmehr/*$end" "$path/tbillard/*$end"
  "$path2/barriere.$end" "$path2/Gagnant.$end" "$path2/slider2.$end" "$path2/jumper.$end" "$path2/Car.$end")

end=cor
cor_array=("$path/adenis/*$end" "$path/agregoir/*$end" "$path/gnebie/*$end"
 "$path/iburel/*$end" "$path/jaustry/*$end" "$path/nolivier/*$end" "$path/pzarmehr/*$end" "$path/tbillard/*$end"
  "$path2/barriere.$end" "$path2/Gagnant.$end" "$path2/slider2.$end" "$path2/jumper.$end" "$path2/Car.$end")

for i in ${!s_array[@]}; do
    ./asm ${s_array[$i]} && xxd ${cor_array[$i]} > t1
	./vm_champs/asm ${s_array[$i]} && xxd ${cor_array[$i]} > t2
	if diff t1 t2 > 0.txt; then
		echo GOOD, MAN!!!
	else
		echo Damn
		echo Damn
		echo Damn
		echo Damn
		echo Damn
		echo Damn
		echo Damn
		echo Damn
	fi
done
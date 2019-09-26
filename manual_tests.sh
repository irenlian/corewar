# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    manual_tests.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdemian <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 20:31:22 by pdemian           #+#    #+#              #
#    Updated: 2019/09/26 20:31:25 by pdemian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

path=vm_champs/champs/championships/2017
path2=vm_champs/champs
path3=vm_champs/champs/examples
path4=vm_champs/champs/championships/2014
end=s

s_array=("$path/adenis/*$end" "$path/agregoir/*$end" "$path/gnebie/*$end"
 "$path/iburel/*$end" "$path/jaustry/*$end" "$path/nolivier/*$end" "$path/pzarmehr/*$end" "$path/tbillard/*$end"
  "$path2/barriere.$end" "$path2/Gagnant.$end" "$path2/slider2.$end" "$path2/jumper.$end" "$path2/Car.$end"
   "$path3/bee_gees.$end" "$path3/bigzork.$end" "$path3/fluttershy.$end" "$path3/helltrain.$end" "$path3/turtle.$end"
    "$path3/zork.$end"
	 "$path4/bguy/*$end" "$path4/bjacob/*$end" "$path4/brandazz/*$end" "$path4/cdivry/*$end" "$path4/clafleur/*$end"
	  "$path4/dcohen/*$end" "$path4/ekocevar/*$end" "$path4/esusseli/*$end" "$path4/evlasova/*$end"
	   "$path4/fcorre/*$end" "$path4/gbir/*$end" "$path4/gjestin/*$end" "$path4/gleger/*$end" "$path4/gmange/*$end"
	    "$path4/gpetrov/*$end" "$path4/gudepard/*$end" "$path4/hmichals/*$end" "$path4/hmoutaou/*$end"
		 "$path4/kelickel/*$end" "$path4/kmonrose/*$end" "$path4/ldesgoui/*$end" "$path4/lseguin/*$end"
		  "$path4/lsirigna/*$end" "$path4/mbacoux/*$end" "$path4/mconraux/*$end" "$path4/rabid-on/*$end"
		   "$path4/rmasse/*$end")

end=cor
cor_array=("$path/adenis/*$end" "$path/agregoir/*$end" "$path/gnebie/*$end"
 "$path/iburel/*$end" "$path/jaustry/*$end" "$path/nolivier/*$end" "$path/pzarmehr/*$end" "$path/tbillard/*$end"
  "$path2/barriere.$end" "$path2/Gagnant.$end" "$path2/slider2.$end" "$path2/jumper.$end" "$path2/Car.$end"
   "$path3/bee_gees.$end" "$path3/bigzork.$end" "$path3/fluttershy.$end" "$path3/helltrain.$end" "$path3/turtle.$end"
    "$path3/zork.$end"
	 "$path4/bguy/*$end" "$path4/bjacob/*$end" "$path4/brandazz/*$end" "$path4/cdivry/*$end" "$path4/clafleur/*$end"
	  "$path4/dcohen/*$end" "$path4/ekocevar/*$end" "$path4/esusseli/*$end" "$path4/evlasova/*$end"
	   "$path4/fcorre/*$end" "$path4/gbir/*$end" "$path4/gjestin/*$end" "$path4/gleger/*$end" "$path4/gmange/*$end"
	    "$path4/gpetrov/*$end" "$path4/gudepard/*$end" "$path4/hmichals/*$end" "$path4/hmoutaou/*$end"
		 "$path4/kelickel/*$end" "$path4/kmonrose/*$end" "$path4/ldesgoui/*$end" "$path4/lseguin/*$end"
		  "$path4/lsirigna/*$end" "$path4/mbacoux/*$end" "$path4/mconraux/*$end" "$path4/rabid-on/*$end"
		   "$path4/rmasse/*$end")

for i in ${!s_array[@]}; do
    ./asm ${s_array[$i]} && xxd ${cor_array[$i]} > t1
	./vm_champs/asm ${s_array[$i]} && xxd ${cor_array[$i]} > t2
	if diff t1 t2 ; then
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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_asm.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdemian <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 20:31:58 by pdemian           #+#    #+#              #
#    Updated: 2019/09/26 20:31:59 by pdemian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash -e
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

while getopts "r:" opt
do
   case "$opt" in
      r ) rivalName="$OPTARG" ;;
      ? ) helpFunction ;; # Print helpFunction in case parameter is non-existent
   esac
done
$DIR/../asm $rivalName.s &&
if ! [ -s $rivalName.cor ] ; then
    echo   DAAAAMN! &&
    exit
fi &&
xxd $rivalName.cor > t2 &&
rm -rf $rivalName.cor &&
$DIR/../vm_champs/asm $rivalName.s &&
xxd $rivalName.cor > t1 &&
rm -rf $rivalName.cor &&
diff t1 t2 > res
if ! [ -s res ] ; then
	echo "GOOD, MAN!!!";
	fi
rm -rf t1
rm -rf t2
rm -rf res
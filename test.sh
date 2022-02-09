#!/bin/sh
read -p "Total de pruebas a realizar: " TOTAL
read -p "Cantidad de números por prueba: " lenlist

var=0;
echo "realizando pruebas..."

for i in $(seq $TOTAL)
do
	ARG=$(ruby -e "puts (1..$lenlist).to_a.shuffle.join(' ')")
	ret=$(./push_swap $ARG | wc -l)
	var=$(($ret + $var))
	echo $ret
#	echo $ARG
	if [[ $(($i % 10)) == 0 ]]
	then
		echo "..."
	fi

done

echo Media de pasos necesarios: $(($var / $TOTAL))

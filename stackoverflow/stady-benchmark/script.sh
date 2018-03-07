#!/bin/sh

# Define the script function
Script(){
        s="$1"
	s=${s##*/}
	s=${s%.*}
	echo "Remove old $s/$2 folder"
	rm -r "$s/$2"
	echo "Make new $s/$2 folder"
	mkdir "$s"
	mkdir "$s/$2"
	echo "Call  frama-c rpp on $1"
	frama-c -rpp -rpp-pro $1 -then-last -print -ocode "$s/$2/test.c"

	cd "$s/$2/"
	echo "Call  frama-c stady on $1 for $s"
	frama-c test.c -main $2 -stady -stady-stop-when-assert-violated > "$1_$2.log"
	cat "$1_$2.log"

	if [ $3 -eq 1 ] 
	then
	    cd "testcases___sd_instru_test_$2/$2/testdrivers/"
	    altDir=$(find -name "*.c")
	    for VARIABLE in ${altDir};   
	    do
		su="${VARIABLE}"
		su=${su##*/}
		su=${su%.*}
		mkdir "${su}_test"
		cp "$VARIABLE" "${su}_test"
		cp "../../../test.c" "${su}_test"
		cp "../../../pathcrawler___sd_instru_test_$2/lanceur_$2_params.h" "${su}_test"
		sed -i '5d' "${su}_test/${VARIABLE}"
		sed -i '5d' "${su}_test/${VARIABLE}"
		sed -i '5d' "${su}_test/${VARIABLE}"
		sed -i '5i#include "test.c"' "${su}_test/${VARIABLE}"
		sed -i "5i#include \"lanceur_$2_params.h\"" "${su}_test/${VARIABLE}"
		echo "Call E-ACSL on $VARIABLE"
		cd "${su}_test"
		e-acsl-gcc.sh -c "${VARIABLE}"
		echo "Run test case for  $VARIABLE"  
		./a.out.e-acsl
		echo "Done"
		cd ../
	    done
	    cd ../../../
	fi
	cd ../../
}

# Invoking the script function
Script $1 $2 $3

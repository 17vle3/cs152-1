#!/bin/bash

files=$(ls in)
inFolder="in"
outFolder="out"


cat in/mytest.min | parser

test(){
    local input=$1
        mil_run mil_code.mil <<< $input > out/mytest.out
        mil_run submission/mytest.mil <<< $input > out/mytest.real
        diff -u out/mytest.out out/mytest.real

}
test "1 2"
test "1 2"
test "1 3"
test "1 4"
test "1 5"

#test "1 1"
test "2 1"
#test "3 1"
#test "4 1"
#test "5 1"

#test "1 2"
#test "2 2"
#test "3 3"
#test "4 4"
#test "5 5"


#ERROR=0
#
#while read -r file; do
#    fileName=${file%.min}
#    isError=${fileName#error}
#
#    echo "test: $fileName"
#    if [ "$isError" != "$fileName" ];then
#        #echo "ERROR File"
#        cat "$inFolder/$file" | parser > "$outFolder/$fileName".output 2>&1
#    else
#        cat "$inFolder/$file" | parser > "$outFolder/$fileName".output
#    fi
#    #diff -u "$outFolder/$fileName".output "$outFolder/$fileName".tokens > "$outFolder/$fileName".diff
#    #DIFF=$(cat "$outFolder/$fileName".diff)
#    #if [ "$DIFF" != "" ];then
#    #    echo "---------FAILED----------"
#    #    ERROR=1
#    #fi
#
#    #diff -u "$outFolder/$fileName".output "$outFolder/$fileName".tokens 
#done <<< "$files"
#
##if [ $ERROR -eq 0 ]; then
##    rm $outfolder/*.diff
##    rm $outfolder/*.output
##fi
##

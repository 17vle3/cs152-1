#!/bin/bash

files=$(ls in)
inFolder="in"
outFolder="out"

ERROR=0

while read -r file; do
    fileName=${file%.min}
    isError=${fileName#error}

    echo "test: $fileName"
    if [ "$isError" != "$fileName" ];then
        #echo "ERROR File"
        cat "$inFolder/$file" | parser > "$outFolder/$fileName".output 2>&1
    else
        cat "$inFolder/$file" | parser > "$outFolder/$fileName".output
    fi
    #diff -u "$outFolder/$fileName".output "$outFolder/$fileName".tokens > "$outFolder/$fileName".diff
    #DIFF=$(cat "$outFolder/$fileName".diff)
    #if [ "$DIFF" != "" ];then
    #    echo "---------FAILED----------"
    #    ERROR=1
    #fi

    #diff -u "$outFolder/$fileName".output "$outFolder/$fileName".tokens 
done <<< "$files"

#if [ $ERROR -eq 0 ]; then
#    rm $outfolder/*.diff
#    rm $outfolder/*.output
#fi
#

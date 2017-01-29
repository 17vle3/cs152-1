#!/bin/bash

files=$(ls tests/in)

ERROR=0

while read -r file; do
    fileName=${file%.min}
    isError=${fileName#error}

    echo "test: $fileName"
    if [ "$isError" != "$fileName" ];then
        #echo "ERROR File"
        cat tests/in/"$file" | lexer 2> tests/out/"$fileName".output >/dev/null
    else
        cat tests/in/"$file" | lexer > tests/out/"$fileName".output
    fi
    diff -u tests/out/"$fileName".output tests/out/"$fileName".tokens > tests/out/"$fileName".diff
    DIFF=$(cat tests/out/"$fileName".diff)
    if [ "$DIFF" != "" ];then
        echo "---------FAILED----------"
        ERROR=1
    fi

    #diff -u tests/out/"$fileName".output tests/out/"$fileName".tokens 
done <<< "$files"

if [ $ERROR -eq 0 ]; then
    rm tests/out/*.diff
    rm tests/out/*.output
fi


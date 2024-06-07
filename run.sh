#!/bin/bash

OPTION=$1

if [ "$OPTION" == "t" ]; then
    make -s
    make -s clean
    
    echo ""
    echo "---------------------"
    ./test
    echo "---------------------"
    echo ""
fi

if [ "$OPTION" == "d" ]; then
    gcc -o debug \
        ./test.c \
        ./lib_string.c \
        -lm \
        --debug
    # make -s clean
    exit
fi


#!/bin/sh

module load GCC/8.3.0 OpenMPI/3.1.4 ROOT/6.20.04-Python-3.7.4

function printHelp {
    echo " --> ERROR in input arguments "
    echo " [0] -d    : default"
    echo " [0] -h    : print help"
}

make mergeDATfiles

if [ $# -eq 0 ] 
then    
    printHelp
else
    if [ "$1" = "-d" ]; then
	./mergeDATfiles 0 ./mergeDATfiles.root
    elif [ "$1" = "-h" ]; then
        printHelp
    else
        printHelp
    fi
fi

#espeak "I have done"

#!/bin/bash

########################################################################
#                                                                      #
# Copyright(C) 2018 - LBS - (Single person developer.)                 #
# Tue Mar  6 20:15:29 JST 2018                                         #
# Autor: Leonid Burmistrov                                             #
#                                                                      #
# File description:                                                    #
#                 This script run the analysis class.                  #
#                                                                      #
# Input paramete:                                                      #
#                                                                      #
# This software is provided "as is" without any warranty.              #
#                                                                      #
########################################################################

module load GCC/8.3.0 OpenMPI/3.1.4 ROOT/6.20.04-Python-3.7.4

#useroot53434
#useroot60806

#Analyse list of root files 
rootFilesList="./rootFileList.dat"
outHistF="./histMerge.root"

#Or analyse single root file 
inRootFiles="./root_data_merg/mergeDATfiles.root"
outHistSingleF="./histMerge.root"

make -f Makefilemerg clean; make -f Makefilemerg runmerg;

function printHelp {
    echo " --> ERROR in input arguments "
    echo " [0] -d  : single root file"
    echo " [0] -l  : list of root files"
    echo " [0] -h  : print help"
}

if [ $# -eq 0 ] 
then    
    printHelp
else
    if [ "$1" = "-d" ]; then
	./runmerg 1 $inRootFiles $outHistSingleF
    elif [ "$1" = "-l" ]; then
	./runmerg 0 $rootFilesList $outHistF
        #printHelp
    elif [ "$1" = "-h" ]; then
        printHelp
    else
        printHelp
    fi
fi

#espeak "I have done"
